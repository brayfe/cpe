<?php
/**
 * @file
 * cpe_taxonomy_categories.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cpe_taxonomy_categories_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'taxonomy_term-cpe_prof_unit_types-field_accrediting_body'.
  $field_instances['taxonomy_term-cpe_prof_unit_types-field_accrediting_body'] = array(
    'bundle' => 'cpe_prof_unit_types',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_accrediting_body',
    'label' => 'Accrediting Body',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Accrediting Body');

  return $field_instances;
}
