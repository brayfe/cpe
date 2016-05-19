<?php
/**
 * @file
 * Updates the context reaction block.
 *
 * Hides 'locked to region' fields in the context module.
 */

/**
 * Context reaction handler that removes fieldblocks 'locked to region'.
 *
 * This is to prevent double-adding of fieldblocks.
 */
class utexas_page_builder_context_reaction_block extends context_reaction_block {
  /**
   * {@inheritdoc}
   */
  public function options_form($context) {
    // Figure out if we're on a context field node.
    $this->is_context_field = (strpos($context->name, 'context_field') !== FALSE);
    // Get the node if we're on a context field context.
    if ($this->is_context_field) {
      $nid = str_replace('context_field-node-', '', $context->name);
      $node = node_load($nid);

      // Get the template.
      if ($template = field_get_items('node', $node, 'field_template')) {
        $template = entity_load('template', $template[0]['target_id']);

        // Get the loaded fields.
        $fields = array();
        if (isset($template->fields)) {
          $defined_fields = unserialize($template->fields);
          foreach ($fields as $field) {
            if ($field['enabled'] and !$field['locked']) {
              $field_label = field_info_instance('node', $field['machine_name'], $node->type);
              $fields[$field_label['label']] = array(
                'label' => $field_label['label'],
                'weight' => $field['_weight'],
              );
            }
          }
        }
      }
    }

    // Set the local node.
    $this->node = (isset($node)) ? $node : FALSE;

    // Rebuild the block info cache if necessary.
    $this->get_blocks(NULL, NULL, $this->rebuild_needed());
    $this->rebuild_needed(FALSE);

    $weight_delta = $this->max_block_weight();

    $form = array(
      '#tree' => TRUE,
      '#theme' => 'context_block_form',
      'max_block_weight' => array(
        '#value' => $weight_delta,
        '#type' => 'value',
      ),
      'state' => array(
        '#type' => 'hidden',
        '#attributes' => array('class' => 'context-blockform-state'),
      ),

    );

    /* Selector. */
    $modules = module_list();
    $options = array();
    $form['selector'] = array(
      '#type' => 'item',
      '#tree' => TRUE,
      '#prefix' => '<div class="context-blockform-selector">',
      '#suffix' => '</div>',
    );
    foreach ($this->get_blocks() as $block) {
      $group = isset($block->context_group) ? $block->context_group : $block->module;
      if (!isset($form['selector'][$group])) {
        $form['selector'][$group] = array(
          '#type' => 'checkboxes',
          '#title' => isset($block->context_group) ? check_plain($block->context_group) : check_plain($modules[$block->module]),
          '#options' => array(),
        );
      }

      // Do a check for the fieldblock module.
      switch ($block->module) {
        case 'fieldblock':
          if (isset($fields[$block->info])) {
            $options[$block->bid] = array(
              'weight' => $fields[$block->info]['weight'],
              'label' => $fields[$block->info]['label'],
            );
          }
          break;

        case 'views':
          if ($this->is_context_field and $display = _utexas_pagz_get_view_display_from_block_delta($block->delta)) {
            // Make sure this view can be exposed to the block editor.
            if (isset($display->display_options['block_exposed_to_editor']) and $display->display_options['block_exposed_to_editor']) {
              // Since this block can be exposed, add it to the block editor.
              $form['selector'][$group]['#options'][$block->bid] = check_plain($block->info);
            }
          }
          else {
            // Attach all views blocks if not on a context field or can't get a
            // display.
            $form['selector'][$group]['#options'][$block->bid] = check_plain($block->info);
          }
          break;

        default:
          $form['selector'][$group]['#options'][$block->bid] = check_plain($block->info);
          break;
      }
    }

    // If options isn't empty, sort and apply the options.
    if (!empty($options)) {
      // Sort by weight.
      uasort($options, function($a, $b) {
        $a_weight = (is_array($a) && isset($a['weight'])) ? $a['weight'] : 0;
        $b_weight = (is_array($b) && isset($b['weight'])) ? $b['weight'] : 0;
                         if ($a_weight == $b_weight) {
                           return 0;
                         }
        return ($a_weight < $b_weight) ? -1 : 1;
      });

      // Reassign the label.
      foreach ($options as $key => &$option) {
        $option = $option['label'];
      }

      // Assign to the form.
      $form['selector']['fieldblock']['#options'] = $options;
    }

    ksort($form['selector']);

    // If options is empty, remove fieldblock as a valid block.
    if (empty($options)) {
      unset($form['selector']['fieldblock']);
    }

    /* Show all theme choice */
    $themes = list_themes();
    $options = array(
      '_none' => t('All themes'),
    );
    foreach ($themes as $theme) {
      $options[$theme->name] = $theme->info['name'];
    }
    $form['themes'] = array(
      '#type' => 'select',
      '#title' => t('Filter regions by theme'),
      '#description' => t('Show regions from all theme or for only theme'),
      '#options' => $options,
    );

    /* Regions. */
    $form['blocks'] = array(
      '#tree' => TRUE,
      '#theme' => 'context_block_regions_form',
    );
    $regions = array();
    foreach ($themes as $theme_key) {
      foreach (system_region_list($theme_key->name, REGIONS_VISIBLE) as $region => $label) {
        $regions[$region][] = $theme_key->info['name'];
        $form['blocks'][$region] = array(
          '#type' => 'item',
          '#title' => check_plain($label),
          '#tree' => TRUE,
        );
        foreach ($this->get_blocks($region, $context) as $block) {
          if (!empty($block->context)) {
            $form['blocks'][$region][$block->bid] = array(
              '#value' => check_plain($block->info),
              '#weight' => $block->weight,
              '#type' => 'markup',
              '#tree' => TRUE,
              'weight' => array(
                '#type' => 'weight',
                '#delta' => $weight_delta,
                '#default_value' => $block->weight,
              ),
            );
          }
        }
      }
    }

    return $form;
  }

  /**
   * {@inheritdoc}
   *
   * Overridden to prevent weird issues with $_GET.
   */
  public function execute(&$page) {
    global $theme;

    // The theme system might not yet be initialized. We need $theme.
    drupal_theme_initialize();

    // If the context_block querystring param is set, switch to AJAX rendering.
    // Note that we check the output buffer for any content to ensure that we
    // are not in the middle of a PHP template render.
    if (isset($_GET['context_block'])) {
      return $this->render_ajax($_GET['context_block']);
    }

    // Populate all block regions.
    $all_regions = $this->system_region_list($theme);

    // Load all region content assigned via blocks.
    foreach (array_keys($all_regions) as $region) {
      if ($this->is_enabled_region($region)) {
        if ($blocks = $this->block_get_blocks_by_region($region)) {

          // Are the blocks already sorted.
          $blocks_sorted = TRUE;

          // If blocks have already been placed in this region (most likely by
          // Block module), then merge in blocks from Context.
          if (isset($page[$region])) {
            $page[$region] = array_merge($page[$region], $blocks);

            // Restore the weights that Block module manufactured.
            // @see _block_get_renderable_array().
            foreach ($page[$region] as &$block) {
              if (isset($block['#block']->weight)) {
                $block['#weight'] = $block['#block']->weight;
                $blocks_sorted = FALSE;
              }
            }
          }
          else {
            $page[$region] = $blocks;
          }

          $page[$region]['#sorted'] = $blocks_sorted;
        }
      }
    }
  }

}
