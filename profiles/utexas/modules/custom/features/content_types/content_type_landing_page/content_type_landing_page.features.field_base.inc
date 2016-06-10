<?php
/**
 * @file
 * content_type_landing_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_type_landing_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_landing_page_tags'.
  $field_bases['field_landing_page_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_landing_page_tags',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'tags',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_utexas_background_accent'.
  $field_bases['field_utexas_background_accent'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_background_accent',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_background_accent',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_background_accent',
  );

  return $field_bases;
}
