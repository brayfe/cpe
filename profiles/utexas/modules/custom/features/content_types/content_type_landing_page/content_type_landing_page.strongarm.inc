<?php
/**
 * @file
 * content_type_landing_page.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function content_type_landing_page_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'fieldblock-node-landing_page-default';
  $strongarm->value = array(
    'field_utexas_contact_info' => 'Contact Info',
    'field_utexas_featured_highlight' => 'Featured Highlight',
    'field_utexas_flex_content_area_a' => 'Flex Content Area A',
    'field_utexas_flex_content_area_b' => 'Flex Content Area B',
    'field_utexas_hero_photo' => 'Hero Photo',
    'field_utexas_image_link_a' => 'Image Link A',
    'field_utexas_image_link_b' => 'Image Link B',
    'field_utexas_newsreel' => 'UT Newsreel',
    'field_utexas_photo_content_area' => 'Photo Content Area',
    'field_utexas_promo_list' => 'Promo List',
    'field_utexas_promo_units' => 'Promo Units',
    'field_utexas_quick_links' => 'Quick Links',
    'field_utexas_social_links' => 'Social Links',
    'field_utexas_twitter_widget' => 'Twitter Widget',
    'field_wysiwyg_a' => 'WYSIWYG A',
    'field_wysiwyg_b' => 'WYSIWYG B',
    'field_utexas_resource' => 'Resources',
  );
  $export['fieldblock-node-landing_page-default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__landing_page';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '19',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_landing_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_landing_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_landing_page';
  $strongarm->value = array(
    0 => 'status',
    1 => 'promote',
  );
  $export['node_options_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_landing_page';
  $strongarm->value = '1';
  $export['node_preview_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_landing_page';
  $strongarm->value = 0;
  $export['node_submitted_landing_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_builder_template_landing_page';
  $strongarm->value = array(
    0 => 'Full-width Featured Highlight',
    1 => 'Landing Page Template 1',
    2 => 'Landing Page Template 2',
    3 => 'Landing Page Template 3',
  );
  $export['page_builder_template_landing_page'] = $strongarm;

  return $export;
}
