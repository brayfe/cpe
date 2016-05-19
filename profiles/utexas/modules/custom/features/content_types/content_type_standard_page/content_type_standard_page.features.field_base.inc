<?php
/**
 * @file
 * content_type_standard_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_type_standard_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_page_layout'.
  $field_bases['field_page_layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_page_layout',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'context_field',
    'settings' => array(
      'global_setting' => 255,
    ),
    'translatable' => 0,
    'type' => 'context_field',
  );

  // Exported field_base: 'field_standard_page_tags'.
  $field_bases['field_standard_page_tags'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_standard_page_tags',
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

  // Exported field_base: 'field_template'.
  $field_bases['field_template'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_template',
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
        'target_bundles' => array(),
      ),
      'target_type' => 'template',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_utexas_contact_info'.
  $field_bases['field_utexas_contact_info'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_contact_info',
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
        'target_bundles' => array(),
      ),
      'target_type' => 'contact_info',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_utexas_featured_highlight'.
  $field_bases['field_utexas_featured_highlight'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_featured_highlight',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_featured_highlight',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_featured_highlight',
  );

  // Exported field_base: 'field_utexas_flex_content_area_a'.
  $field_bases['field_utexas_flex_content_area_a'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_flex_content_area_a',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_flex_content_areas',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_flex_content_area',
  );

  // Exported field_base: 'field_utexas_flex_content_area_b'.
  $field_bases['field_utexas_flex_content_area_b'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_flex_content_area_b',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_flex_content_areas',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_flex_content_area',
  );

  // Exported field_base: 'field_utexas_hero_photo'.
  $field_bases['field_utexas_hero_photo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_hero_photo',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_hero_photo',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_hero_photo',
  );

  // Exported field_base: 'field_utexas_image_link_a'.
  $field_bases['field_utexas_image_link_a'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_image_link_a',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_image_links',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_image_link',
  );

  // Exported field_base: 'field_utexas_image_link_b'.
  $field_bases['field_utexas_image_link_b'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_image_link_b',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_image_links',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_image_link',
  );

  // Exported field_base: 'field_utexas_newsreel'.
  $field_bases['field_utexas_newsreel'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_newsreel',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_newsreel',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_newsreel',
  );

  // Exported field_base: 'field_utexas_photo_content_area'.
  $field_bases['field_utexas_photo_content_area'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_photo_content_area',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_photo_content_area',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_photo_content_area',
  );

  // Exported field_base: 'field_utexas_promo_list'.
  $field_bases['field_utexas_promo_list'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_promo_list',
    'indexes' => array(
      'revision_id' => array(
        0 => 'revision_id',
      ),
    ),
    'locked' => 0,
    'module' => 'field_collection',
    'settings' => array(
      'hide_blank_items' => 1,
      'path' => '',
    ),
    'translatable' => 0,
    'type' => 'field_collection',
  );

  // Exported field_base: 'field_utexas_promo_list_headline'.
  $field_bases['field_utexas_promo_list_headline'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_promo_list_headline',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_utexas_promo_list_item'.
  $field_bases['field_utexas_promo_list_item'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_promo_list_item',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_promo_list',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_promo_list',
  );

  // Exported field_base: 'field_utexas_promo_list_style'.
  $field_bases['field_utexas_promo_list_style'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_promo_list_style',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'Single list full (1 item per row)' => 'Single list full (1 item per row)',
        'Single list responsive (2 items per row)' => 'Single list responsive (2 items per row)',
        'Two lists, side-by-side' => 'Two lists, side-by-side',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_utexas_promo_units'.
  $field_bases['field_utexas_promo_units'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_promo_units',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_promo_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_promo_field',
  );

  // Exported field_base: 'field_utexas_quick_links'.
  $field_bases['field_utexas_quick_links'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_quick_links',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_quick_links',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_quick_links',
  );

  // Exported field_base: 'field_utexas_resource'.
  $field_bases['field_utexas_resource'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_resource',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_resource',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_resource',
  );

  // Exported field_base: 'field_utexas_social_links'.
  $field_bases['field_utexas_social_links'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_social_links',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'utexas_social_links',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'utexas_social_links',
  );

  // Exported field_base: 'field_utexas_twitter_widget'.
  $field_bases['field_utexas_twitter_widget'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_utexas_twitter_widget',
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
        'target_bundles' => array(),
      ),
      'target_type' => 'twitter_widget',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_wysiwyg_a'.
  $field_bases['field_wysiwyg_a'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wysiwyg_a',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_wysiwyg_b'.
  $field_bases['field_wysiwyg_b'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_wysiwyg_b',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
