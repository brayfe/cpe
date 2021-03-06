<?php
/**
 * @file
 * cpe_taxonomy_categories.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cpe_taxonomy_categories_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_accrediting_body'.
  $field_bases['field_accrediting_body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_accrediting_body',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'cpe_accred_bodies' => 'cpe_accred_bodies',
        ),
      ),
      'target_type' => 'taxonomy_term',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
