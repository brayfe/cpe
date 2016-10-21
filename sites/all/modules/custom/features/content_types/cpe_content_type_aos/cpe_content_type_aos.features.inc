<?php
/**
 * @file
 * cpe_content_type_aos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cpe_content_type_aos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cpe_content_type_aos_node_info() {
  $items = array(
    'cpe_area_of_study' => array(
      'name' => t('Area of Study'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
