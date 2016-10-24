<?php
/**
 * @file
 * cpe_content_type_instructor.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cpe_content_type_instructor_taxonomy_default_vocabularies() {
  return array(
    'cpe_prof_unit_types' => array(
      'name' => 'Professional Unit Types',
      'machine_name' => 'cpe_prof_unit_types',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -6,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
