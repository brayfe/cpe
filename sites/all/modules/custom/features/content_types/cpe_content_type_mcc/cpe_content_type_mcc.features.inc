<?php
/**
 * @file
 * cpe_content_type_mcc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cpe_content_type_mcc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
