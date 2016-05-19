<?php
/**
 * @file
 * content_type_standard_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_standard_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_standard_page_node_info() {
  $items = array(
    'standard_page' => array(
      'name' => t('Standard Page'),
      'base' => 'node_content',
      'description' => t('Use the Standard Page for content-focused pages using the themed widget page builder tool.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
