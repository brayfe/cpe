<?php
/**
 * @file
 * cpe_content_type_multicourse_certificate.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function cpe_content_type_multicourse_certificate_taxonomy_default_vocabularies() {
  return array(
    'cpe_modality' => array(
      'name' => 'Modality',
      'machine_name' => 'cpe_modality',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => -8,
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
