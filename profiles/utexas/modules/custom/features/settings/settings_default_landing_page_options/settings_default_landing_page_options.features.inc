<?php
/**
 * @file
 * settings_default_landing_page_options.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function settings_default_landing_page_options_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
