<?php
/**
 * @file
 * cpe_content_type_mcc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cpe_content_type_mcc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cpe_content_type_mcc_node_info() {
  $items = array(
    'cpe_multi_course_cert' => array(
      'name' => t('Multi Course Certificate'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
