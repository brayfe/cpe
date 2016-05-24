<?php
/**
 * @file
 * Contains the block display plugin for views.
 */

/**
 * The plugin that handles a block.
 *
 * Attaches a new definition to show a view in the layout editor or not.
 *
 * @ingroup views_display_plugins
 */
class utexas_page_builder_views_plugin_display_block extends views_plugin_display_block {
  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();

    $options['block_exposed_to_editor'] = array('default' => FALSE);

    return $options;
  }

  /**
   * Provide the summary for page options in the views UI.
   *
   * This output is returned as an array.
   */
  public function options_summary(&$categories, &$options) {
    // It is very important to call the parent function here:
    parent::options_summary($categories, $options);

    $options['block_exposed_to_editor'] = array(
      'category' => 'block',
      'title' => t('Block exposed to page layout editor'),
      'value' => ($this->get_option('block_exposed_to_editor')) ? 'Yes' : 'No',
    );
  }

  /**
   * {@inheritdoc}
   */
  public function options_form(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_form($form, $form_state);

    switch ($form_state['section']) {
      case 'block_exposed_to_editor':
        $form['#title'] .= t('Block exposed to editor');
        $form['block_exposed_to_editor'] = array(
          '#type' => 'checkbox',
          '#title' => t('Checking this box will allow this block to be used on the page layout editor.'),
          '#default_value' => $this->get_option('block_exposed_to_editor'),
        );
        break;
    }
  }

  /**
   * Perform any necessary changes to the form values prior to storage.
   *
   * There is no need for this function to actually store the data.
   */
  public function options_submit(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_submit($form, $form_state);

    switch ($form_state['section']) {
      case 'block_exposed_to_editor':
        $this->set_option('block_exposed_to_editor', $form_state['values']['block_exposed_to_editor']);
        break;
    }
  }

}
