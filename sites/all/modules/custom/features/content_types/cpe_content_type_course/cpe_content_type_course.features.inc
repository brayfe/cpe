<?php
/**
 * @file
 * cpe_content_type_course.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cpe_content_type_course_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cpe_content_type_course_node_info() {
  $items = array(
    'cpe_course' => array(
      'name' => t('Course'),
      'base' => 'node_content',
      'description' => t('Use Course when adding details for a new course or information session.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
