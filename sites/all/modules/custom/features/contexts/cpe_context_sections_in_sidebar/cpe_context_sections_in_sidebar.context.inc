<?php
/**
 * @file
 * cpe_context_sections_in_sidebar.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function cpe_context_sections_in_sidebar_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'cpe_sections_in_sidebar';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'cpe_course' => 'cpe_course',
        'cpe_single_course_cert' => 'cpe_single_course_cert',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-cpe_sections-block' => array(
          'module' => 'views',
          'delta' => 'cpe_sections-block',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['cpe_sections_in_sidebar'] = $context;

  return $export;
}
