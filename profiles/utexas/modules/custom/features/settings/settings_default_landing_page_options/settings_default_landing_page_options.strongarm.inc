<?php
/**
 * @file
 * settings_default_landing_page_options.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function settings_default_landing_page_options_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_landing_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'revision',
  );
  $export['node_options_landing_page'] = $strongarm;

  return $export;
}
