<?php
/**
 * @file
 * content_type_standard_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function content_type_standard_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_utexas_promo_list-field_utexas_promo_list_headline'.
  $field_instances['field_collection_item-field_utexas_promo_list-field_utexas_promo_list_headline'] = array(
    'bundle' => 'field_utexas_promo_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_utexas_promo_list_headline',
    'label' => 'Promo List Headline',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_utexas_promo_list-field_utexas_promo_list_item'.
  $field_instances['field_collection_item-field_utexas_promo_list-field_utexas_promo_list_item'] = array(
    'bundle' => 'field_utexas_promo_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_promo_list',
        'settings' => array(),
        'type' => 'utexas_promo_list',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_utexas_promo_list_item',
    'label' => 'Promo List Item',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'utexas_promo_list',
      'settings' => array(),
      'type' => 'utexas_promo_list',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_utexas_promo_list-field_utexas_promo_list_style'.
  $field_instances['field_collection_item-field_utexas_promo_list-field_utexas_promo_list_style'] = array(
    'bundle' => 'field_utexas_promo_list',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<p>Choose \'Single list full\' for a one-column list of items that spans the width of its container.<br>Choose \'Single list responsive\' to produce a two-column list that spans the width of its container.<br>Choose \'Two lists, side-by-side\' to produce a one-column list that spans half the width of its container.<br>*note: two lists need to be entered with \'Two lists, side-by-side\' style selected to fill a container<br>Choose "N/A" (along with removing all other field data) to completely remove the Promo List from the page.</p>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_utexas_promo_list_style',
    'label' => 'Promo List Style',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_page_layout'.
  $field_instances['node-standard_page-field_page_layout'] = array(
    'bundle' => 'standard_page',
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
    'field_name' => 'field_page_layout',
    'label' => 'Page Layout',
    'required' => 0,
    'settings' => array(
      'allowed_blocks' => array(
        'block' => 0,
        'context_ui' => 0,
        'fieldblock' => 'fieldblock',
        'node' => 0,
        'search' => 0,
        'shortcut' => 0,
        'system' => 0,
        'user' => 0,
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
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_standard_page_tags'.
  $field_instances['node-standard_page-field_standard_page_tags'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A comma-separated list of terms from site <a href="/admin/structure/taxonomy/tags">Tags</a>. Existing tags will autocomplete as you type.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_standard_page_tags',
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
      'weight' => 32,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_template'.
  $field_instances['node-standard_page-field_template'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_template',
    'label' => 'Template',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'taxonomy-index' => array(
          'status' => TRUE,
        ),
      ),
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

  // Exported field_instance: 'node-standard_page-field_utexas_contact_info'.
  $field_instances['node-standard_page-field_utexas_contact_info'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This widget provides an easy way to display contact information on one or more pages. Since you may need the same contact information to appear on multiple pages, Contact Info data is added on a <a href="/admin/content/contact_info">separate form</a>, then assigned by reference on pages. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-ContactInfo">Go to documentation</a>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-standard_page-field_utexas_featured_highlight'.
  $field_instances['node-standard_page-field_utexas_featured_highlight'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The featured highlight is a special field, available on the "Featured Highlight" template, which appears automatically when data has been entered for it (in other words, it is not a positionable field). <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-FeaturedHighlight">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_featured_highlight',
        'settings' => array(),
        'type' => 'utexas_featured_highlight',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-standard_page-field_utexas_flex_content_area_a'.
  $field_instances['node-standard_page-field_utexas_flex_content_area_a'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Flex Content Area field, as its name implies, is a highly flexible block that can yield a variety of looks. It comes with an image, linkable title, copy text area, and call to action link or list of links. In addition, you can add multiple flex content area fields on a single page. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-FlexContentArea">Go to documentation</a>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_flex_content_areas',
        'settings' => array(),
        'type' => 'utexas_flex_content_area',
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
  // 'node-standard_page-field_utexas_flex_content_area_b'.
  $field_instances['node-standard_page-field_utexas_flex_content_area_b'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Flex Content Area field, as its name implies, is a highly flexible block that can yield a variety of looks. It comes with an image, linkable title, copy text area, and call to action link or list of links. In addition, you can add multiple flex content area fields on a single page. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-FlexContentArea">Go to documentation</a>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_flex_content_areas',
        'settings' => array(),
        'type' => 'utexas_flex_content_area',
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

  // Exported field_instance: 'node-standard_page-field_utexas_hero_photo'.
  $field_instances['node-standard_page-field_utexas_hero_photo'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The hero photo is a large image region, typically displayed at the top of content, to provide identity to the content on the page. On Standard Pages, the hero image fills 66% width in the upper left, and includes an optional caption. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-HeroPhoto">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_hero_photo',
        'settings' => array(),
        'type' => 'utexas_hero_photo',
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
      'type' => 'utexas_hero_photo',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_image_link_a'.
  $field_instances['node-standard_page-field_utexas_image_link_a'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Image Link is a simple field which allows uploading an image of any size and optionally linking it to another webpage (internal or external). <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-ImageLink">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_image_links',
        'settings' => array(),
        'type' => 'utexas_image_link',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_image_link_b'.
  $field_instances['node-standard_page-field_utexas_image_link_b'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Image Link is a simple field which allows uploading an image of any size and optionally linking it to another webpage (internal or external). <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-ImageLink">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_image_links',
        'settings' => array(),
        'type' => 'utexas_image_link',
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
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_newsreel'.
  $field_instances['node-standard_page-field_utexas_newsreel'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The UT Newsreel widget adds an unlimited number of feeds from news.utexas.edu. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-UTNewsreel">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_newsreel',
        'settings' => array(),
        'type' => 'utexas_newsreel',
        'weight' => 21,
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
      'weight' => 18,
    ),
  );

  // Exported field_instance:
  // 'node-standard_page-field_utexas_photo_content_area'.
  $field_instances['node-standard_page-field_utexas_photo_content_area'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Photo Content Areas are similar to Flex Content Areas (see above), and come with an image, linkable title, copy text, and link(s). <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-PhotoContentArea">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_photo_content_area',
        'settings' => array(),
        'type' => 'utexas_photo_content_area',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_promo_list'.
  $field_instances['node-standard_page-field_utexas_promo_list'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Promo Lists provide the ability to add many content-rich featured items on a page, without taking up much space. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-PromoList">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
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

  // Exported field_instance: 'node-standard_page-field_utexas_promo_units'.
  $field_instances['node-standard_page-field_utexas_promo_units'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Promo Unit, similar in content to the Promo List, adds an unlimited number of preformatted content, each with image, headline, copy text, and call to action link. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-PromoUnit">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_promo_field',
        'settings' => array(),
        'type' => 'utexas_promo_unit',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_quick_links'.
  $field_instances['node-standard_page-field_utexas_quick_links'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Quick Links widget provides the ability to display a list of links with a title and optional copy. On landing page template 2 the "Quick Links" are a locked region that will produce an interesting full-width layout to highlight a number of links. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-QuickLinks">Go to documentation</a>.',
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
        'max_links' => 5,
      ),
      'type' => 'utexas_quick_links',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_resource'.
  $field_instances['node-standard_page-field_utexas_resource'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Resources widget provides a responsive display consisting of a title, image, headline and list of links. There is no copy field available for this widget. <a href="https://wikis.utexas.edu/display/quicksites/List+of+available+fields+and+widgets#Listofavailablefieldsandwidgets-Resources">Go to documentation</a>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_resource',
        'settings' => array(),
        'type' => 'utexas_resource',
        'weight' => 22,
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
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_social_links'.
  $field_instances['node-standard_page-field_utexas_social_links'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Social Links widget provides an easy way to link to your organization\'s social media accounts. On most layouts, the social link block will automatically appear within the page\'s regions as social media icons. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-SocialLinks">Go to documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'utexas_social_links',
        'settings' => array(),
        'type' => 'utexas_social_links',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_utexas_twitter_widget'.
  $field_instances['node-standard_page-field_utexas_twitter_widget'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Twitter widget allows you to add an unlimited number of configurable Twitter feeds that pull from an account or user timeline. Add and configure Twitter widgets <a href="/admin/content/twitter">here</a>. Also see <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-TwitterWidget">the documentation</a>.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_wysiwyg_a'.
  $field_instances['node-standard_page-field_wysiwyg_a'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The WYSIWYG ("What you see is what you get") field is the all-purpose text field, which allows you to add formatted text, including bold and italicized text, links, ordered and unordered lists, and tables. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-WYSIWYGfield">Go to documentation</a>.',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-standard_page-field_wysiwyg_b'.
  $field_instances['node-standard_page-field_wysiwyg_b'] = array(
    'bundle' => 'standard_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The WYSIWYG ("What you see is what you get") field is the all-purpose text field, which allows you to add formatted text, including bold and italicized text, links, ordered and unordered lists, and tables. <a href="https://wikis.utexas.edu/display/UTDK/Fields+and+Widgets#FieldsandWidgets-WYSIWYGfield">Go to documentation</a>.',
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p>Choose \'Single list full\' for a one-column list of items that spans the width of its container.<br>Choose \'Single list responsive\' to produce a two-column list that spans the width of its container.<br>Choose \'Two lists, side-by-side\' to produce a one-column list that spans half the width of its container.<br>*note: two lists need to be entered with \'Two lists, side-by-side\' style selected to fill a container<br>Choose "N/A" (along with removing all other field data) to completely remove the Promo List from the page.</p>');
  t('A comma-separated list of terms from site <a href="/admin/structure/taxonomy/tags">Tags</a>. Existing tags will autocomplete as you type.');
  t('Add an image that is clickable to a URL. This is ideal for small ad units that do not need captions or additional calls to action.');
  t('Add your hero photo and give it a caption. It will appear at the top of your page. Please upload the high resolution version of the image for best results.');
  t('Contact Info');
  t('Featured Highlight');
  t('Flex Content Area A');
  t('Flex Content Area B');
  t('Flexible area to share an image, title, copy and some links. This can appear in the body of the page or the sidebar.');
  t('Hero Photo');
  t('Image Link A');
  t('Image Link B');
  t('Page Layout');
  t('Photo Content Area');
  t('Promo List');
  t('Promo List Headline');
  t('Promo List Item');
  t('Promo List Style');
  t('Promo Units');
  t('Promo Units provide a two-thirds width area to promote an item, with an image, title, copy, and call to action.');
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
  t('WYSIWYG A is the primary body copy entry field.');
  t('WYSIWYG B');
  t('WYSIWYG B is a secondary body copy entry field.');
  t('boooty call');
  t('some quick links');

  return $field_instances;
}
