<?php
/**
 * @file
 * content_type_landing_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_landing_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-landing_page-field_landing_page_tags'.
  $field_instances['node-landing_page-field_landing_page_tags'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A comma-separated list of terms from site <a href="/admin/structure/taxonomy/tags">Tags</a>. Existing tags will autocomplete as you type.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_landing_page_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_page_layout'.
  $field_instances['node-landing_page-field_page_layout'] = array(
    'bundle' => 'landing_page',
    'default_value' => array(
      0 => array(
        'context' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'context_field',
        'settings' => array(),
        'type' => 'context_field_context',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_layout',
    'label' => 'Page Layout',
    'required' => 0,
    'settings' => array(
      'allowed_blocks' => array(
        'context_ui' => 0,
        'fieldblock' => 'fieldblock',
        'node' => 0,
        'search' => 0,
        'shortcut' => 0,
        'system' => 0,
        'user' => 0,
        'utexas_menu' => 0,
      ),
      'default_context' => 'context_field_default_context',
      'use_default' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'context_field',
      'settings' => array(
        'form_element' => array(
          'user_toggle' => 0,
        ),
      ),
      'type' => 'context_field',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_template'.
  $field_instances['node-landing_page-field_template'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_template',
    'label' => 'Template',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-landing_page-field_utexas_background_accent'.
  $field_instances['node-landing_page-field_utexas_background_accent'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'utexas_background_accent',
        'settings' => array(),
        'type' => 'utexas_background_accent',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_background_accent',
    'label' => 'Background Accent',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_background_accent',
      'settings' => array(),
      'type' => 'utexas_background_accent',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_contact_info'.
  $field_instances['node-landing_page-field_utexas_contact_info'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select an existing Contact Info block to be available on this page. <a href="/admin/content/contact_info">Review or add Contact Info blocks</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => 0,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_contact_info',
    'label' => 'Contact Info',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-landing_page-field_utexas_featured_highlight'.
  $field_instances['node-landing_page-field_utexas_featured_highlight'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_featured_highlight',
        'settings' => array(),
        'type' => 'utexas_featured_highlight',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_featured_highlight',
    'label' => 'Featured Highlight',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_featured_highlight',
      'settings' => array(),
      'type' => 'utexas_featured_highlight',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-landing_page-field_utexas_flex_content_area_a'.
  $field_instances['node-landing_page-field_utexas_flex_content_area_a'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_flex_content_areas',
        'settings' => array(),
        'type' => 'utexas_flex_content_area',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_flex_content_area_a',
    'label' => 'Flex Content Area A',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'utexas_flex_content_areas',
      'settings' => array(
        'max_links' => 5,
      ),
      'type' => 'utexas_flex_content_area',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'node-landing_page-field_utexas_flex_content_area_b'.
  $field_instances['node-landing_page-field_utexas_flex_content_area_b'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_flex_content_areas',
        'settings' => array(),
        'type' => 'utexas_flex_content_area',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_flex_content_area_b',
    'label' => 'Flex Content Area B',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'utexas_flex_content_areas',
      'settings' => array(
        'max_links' => 5,
      ),
      'type' => 'utexas_flex_content_area',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_hero_photo'.
  $field_instances['node-landing_page-field_utexas_hero_photo'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_hero_photo',
        'settings' => array(),
        'type' => 'utexas_hero_photo_full',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_hero_photo',
    'label' => 'Hero Photo',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_hero_photo',
      'settings' => array(),
      'type' => 'utexas_hero_photo_full',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_image_link_a'.
  $field_instances['node-landing_page-field_utexas_image_link_a'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_image_links',
        'settings' => array(),
        'type' => 'utexas_image_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_image_link_a',
    'label' => 'Image Link A',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_image_links',
      'settings' => array(),
      'type' => 'utexas_image_link',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_image_link_b'.
  $field_instances['node-landing_page-field_utexas_image_link_b'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_image_links',
        'settings' => array(),
        'type' => 'utexas_image_link',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_image_link_b',
    'label' => 'Image Link B',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_image_links',
      'settings' => array(),
      'type' => 'utexas_image_link',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_newsreel'.
  $field_instances['node-landing_page-field_utexas_newsreel'] = array(
    'bundle' => 'landing_page',
    'default_value' => array(
      0 => array(
        'headline' => 'Latest from UTNews',
        'type' => array(
          'news' => 'news',
          'press-releases' => 'press-releases',
          'texas-perspectives' => 'texas-perspectives',
        ),
        'category' => array(
          'arts-and-humanities' => 'arts-and-humanities',
          'business-and-economy' => 'business-and-economy',
          'campus-and-community' => 'campus-and-community',
          'education-and-leadership' => 'education-and-leadership',
          'health-and-wellness' => 'health-and-wellness',
          'policy-and-law' => 'policy-and-law',
          'science-and-technology' => 'science-and-technology',
        ),
        'tag' => '',
        'count' => 4,
        'include_description' => 1,
        'refresh_rate' => 1,
        'view_all' => 'View all news',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_newsreel',
        'settings' => array(),
        'type' => 'utexas_newsreel',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_newsreel',
    'label' => 'UT Newsreel',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_newsreel',
      'settings' => array(),
      'type' => 'utexas_newsreel',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-landing_page-field_utexas_photo_content_area'.
  $field_instances['node-landing_page-field_utexas_photo_content_area'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_photo_content_area',
        'settings' => array(),
        'type' => 'utexas_photo_content_area',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_photo_content_area',
    'label' => 'Photo Content Area',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'utexas_photo_content_area',
      'settings' => array(
        'max_links' => 1,
      ),
      'type' => 'utexas_photo_content_area',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_promo_list'.
  $field_instances['node-landing_page-field_utexas_promo_list'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_promo_list',
    'label' => 'Promo List',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_promo_units'.
  $field_instances['node-landing_page-field_utexas_promo_units'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_promo_field',
        'settings' => array(),
        'type' => 'utexas_promo_unit',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_promo_units',
    'label' => 'Promo Units',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_promo_field',
      'settings' => array(),
      'type' => 'utexas_promo_unit',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_quick_links'.
  $field_instances['node-landing_page-field_utexas_quick_links'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_quick_links',
        'settings' => array(),
        'type' => 'utexas_quick_links',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_quick_links',
    'label' => 'Quick Links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'utexas_quick_links',
      'settings' => array(
        'max_links' => 20,
      ),
      'type' => 'utexas_quick_links',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_resource'.
  $field_instances['node-landing_page-field_utexas_resource'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_resource',
        'settings' => array(),
        'type' => 'utexas_resource',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_resource',
    'label' => 'Resources',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'utexas_resource',
      'settings' => array(
        'max_links' => 5,
      ),
      'type' => 'utexas_resource',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_social_links'.
  $field_instances['node-landing_page-field_utexas_social_links'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_social_links',
        'settings' => array(),
        'type' => 'utexas_social_links',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_social_links',
    'label' => 'Social Links',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_social_links',
      'settings' => array(),
      'type' => 'utexas_social_links',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_utexas_twitter_widget'.
  $field_instances['node-landing_page-field_utexas_twitter_widget'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select an existing Twitter Widget to be available on this page. <a href="/admin/content/twitter">Review or add Twitter widgets</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_utexas_twitter_widget',
    'label' => 'Twitter Widget',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_wysiwyg_a'.
  $field_instances['node-landing_page-field_wysiwyg_a'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wysiwyg_a',
    'label' => 'WYSIWYG A',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-landing_page-field_wysiwyg_b'.
  $field_instances['node-landing_page-field_wysiwyg_b'] = array(
    'bundle' => 'landing_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_wysiwyg_b',
    'label' => 'WYSIWYG B',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A comma-separated list of terms from site <a href="/admin/structure/taxonomy/tags">Tags</a>. Existing tags will autocomplete as you type.');
  t('Background Accent');
  t('Contact Info');
  t('Featured Highlight');
  t('Flex Content Area A');
  t('Flex Content Area B');
  t('Hero Photo');
  t('Image Link A');
  t('Image Link B');
  t('Page Layout');
  t('Photo Content Area');
  t('Promo List');
  t('Promo Units');
  t('Quick Links');
  t('Resources');
  t('Select an existing Contact Info block to be available on this page. <a href="/admin/content/contact_info">Review or add Contact Info blocks</a>.');
  t('Select an existing Twitter Widget to be available on this page. <a href="/admin/content/twitter">Review or add Twitter widgets</a>.');
  t('Social Links');
  t('Tags');
  t('Template');
  t('Twitter Widget');
  t('UT Newsreel');
  t('WYSIWYG A');
  t('WYSIWYG B');

  return $field_instances;
}
