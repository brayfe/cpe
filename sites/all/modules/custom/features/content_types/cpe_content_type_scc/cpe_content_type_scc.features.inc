<?php
/**
 * @file
 * cpe_content_type_scc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cpe_content_type_scc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cpe_content_type_scc_node_info() {
  $items = array(
    'cpe_single_course_cert' => array(
      'name' => t('Single Course Certificate'),
      'base' => 'node_content',
      'description' => t('A certificate program consisting of a single Course.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
