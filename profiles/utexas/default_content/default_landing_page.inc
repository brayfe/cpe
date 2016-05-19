<?php

/**
 * @file
 * Default landing page content.
 */
$profile_dir = drupal_get_path('profile', 'utexas');
if ($handle = fopen($profile_dir . '/default_content/assets/' . 'background-accent.jpg', 'r')) {
  $file = file_save_data($handle, 'public://background-accent.jpg');
  fclose($handle);
  $file->field_file_image_alt_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
  $file->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
  file_save($file);
}

$landing_pages = array();

// Context for Landing Template 1.
$context = new stdClass();
$context->disabled = FALSE;
$context->api_version = 3;
$context->name = 'context_field-node-';
$context->description = 'custom';
$context->tag = 'Context Field Custom';
$context->conditions = array(
  'context_field' => array(
    'values' => array(
      1 => 1,
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'fieldblock-6f3b85225f51542463a88e53104f8753' => array(
        'module' => 'fieldblock',
        'delta' => '6f3b85225f51542463a88e53104f8753',
        'region' => 'content_top_left',
        'weight' => 0,
      ),
      'fieldblock-9bcf52bbed6b2a3ea84b55a58fdd9c55' => array(
        'module' => 'fieldblock',
        'delta' => '9bcf52bbed6b2a3ea84b55a58fdd9c55',
        'region' => 'content_top_left',
        'weight' => 1,
      ),
      'fieldblock-eab8c417f7d28e9571473905cfebbd5b' => array(
        'module' => 'fieldblock',
        'delta' => 'eab8c417f7d28e9571473905cfebbd5b',
        'region' => 'content_top_right',
        'weight' => 0,
      ),
    ),
  ),
  'theme' => array(
    'title' => '',
    'subtitle' => '',
  ),
  'theme_html' => array(
    'class' => '',
  ),
);
$context->condition_mode = 0;

$export['Landing Page Template 1'] = $context;


// Context for Landing Template 2.
$context = new stdClass();
$context->disabled = FALSE;
$context->api_version = 3;
$context->name = 'context_field-node-';
$context->description = 'custom';
$context->tag = 'Context Field Custom';
$context->conditions = array(
  'context_field' => array(
    'values' => array(
      1 => 1,
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'fieldblock-d83c2a95384186e375ab37cbf1430bf5' => array(
        'module' => 'fieldblock',
        'delta' => 'd83c2a95384186e375ab37cbf1430bf5',
        'region' => 'content_top_right',
        'weight' => 0,
      ),
      'fieldblock-1a9dd8685785a44b58d5e24ed3f8996d' => array(
        'module' => 'fieldblock',
        'delta' => '1a9dd8685785a44b58d5e24ed3f8996d',
        'region' => 'content_top_three_pillars',
        'weight' => 0,
      ),
      'fieldblock-9bcf52bbed6b2a3ea84b55a58fdd9c55' => array(
        'module' => 'fieldblock',
        'delta' => '9bcf52bbed6b2a3ea84b55a58fdd9c55',
        'region' => 'content_bottom',
        'weight' => 0,
      ),
      'fieldblock-6f3b85225f51542463a88e53104f8753' => array(
        'module' => 'fieldblock',
        'delta' => '6f3b85225f51542463a88e53104f8753',
        'region' => 'content_bottom',
        'weight' => 1,
      ),
    ),
  ),
  'theme' => array(
    'title' => '',
    'subtitle' => '',
  ),
  'theme_html' => array(
    'class' => '',
  ),
);
$context->condition_mode = 0;

$export['Landing Page Template 2'] = $context;

// Context for Landing Template 3.
$context = new stdClass();
$context->disabled = FALSE;
$context->api_version = 3;
$context->name = 'context_field-node-';
$context->description = 'custom';
$context->tag = 'Context Field Custom';
$context->conditions = array(
  'context_field' => array(
    'values' => array(
      1 => 1,
    ),
  ),
);
$context->reactions = array(
  'block' => array(
    'blocks' => array(
      'fieldblock-9bcf52bbed6b2a3ea84b55a58fdd9c55' => array(
        'module' => 'fieldblock',
        'delta' => '9bcf52bbed6b2a3ea84b55a58fdd9c55',
        'region' => 'content_top_left',
        'weight' => 0,
      ),
      'fieldblock-6f3b85225f51542463a88e53104f8753' => array(
        'module' => 'fieldblock',
        'delta' => '6f3b85225f51542463a88e53104f8753',
        'region' => 'content_bottom',
        'weight' => 0,
      ),
      'fieldblock-d83c2a95384186e375ab37cbf1430bf5' => array(
        'module' => 'fieldblock',
        'delta' => 'd83c2a95384186e375ab37cbf1430bf5',
        'region' => 'content_top_right',
        'weight' => 0,
      ),
      'fieldblock-1a9dd8685785a44b58d5e24ed3f8996d' => array(
        'module' => 'fieldblock',
        'delta' => '1a9dd8685785a44b58d5e24ed3f8996d',
        'region' => 'content_top_four_pillars',
        'weight' => 0,
      ),
      'fieldblock-eab8c417f7d28e9571473905cfebbd5b' => array(
        'module' => 'fieldblock',
        'delta' => 'eab8c417f7d28e9571473905cfebbd5b',
        'region' => 'sidebar_second',
        'weight' => 0,
      ),
    ),
  ),
  'theme' => array(
    'title' => '',
    'subtitle' => '',
  ),
  'theme_html' => array(
    'class' => '',
  ),
);
$context->condition_mode = 0;

$export['Landing Page Template 3'] = $context;

$landing_pages[] = array(
  'uid' => 1,
  'title' => 'Landing Page Template 1',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '6b2015b1-222c-4163-93db-10b426fd18f3',
  'type' => 'landing_page',
  'language' => 'und',
  'created' => 1440428993,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ea19f67d-ff6b-4627-9465-1fd2abdf5bad',
  'revision_uid' => 1,
  'field_page_layout' => array(
    'und' => array(
      0 => array(
        'context' => 'context_field-node-2',
      ),
    ),
  ),
  'field_template' => array(
    'und' => array(
      0 => array(
        'target_id' => 9,
      ),
    ),
  ),
  'field_utexas_background_accent' => array(
    'und' => array(
      0 => array(
        'image_fid' => 7,
      ),
    ),
  ),
  'field_utexas_contact_info' => array(
    'und' => array(
      0 => array(
        'target_id' => 1,
      ),
    ),
  ),
  'field_utexas_featured_highlight' => array(
    'und' => array(
      0 => array(
        'image_fid' => 6,
        'date' => 0,
        'headline' => 'Pellentesque habitant morbi tristique senectus',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'link' => 'http://utexas.edu',
        'cta' => 'Cras euismod',
        'highlight_style' => 'navy',
      ),
    ),
  ),
  'field_utexas_flex_content_area_a' => array(
    'und' => array(
      0 => array(
        'image_fid' => 3,
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Proin in arcu neque.',
        'cta_link' => 'http://utexas.edu',
      ),
      1 => array(
        'image_fid' => 5,
        'headline' => 'Quisque massa mauris',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Morbi laoreet molestie',
        'cta_link' => 'http://google.com',
      ),
      2 => array(
        'image_fid' => 4,
        'headline' => 'Aliquam erat volutpat.',
        'copy_value' => 'Ut id ullamcorper ipsum, et porttitor neque. Donec sodales bibendum enim ac interdum.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Morbi laoreet molestie.',
        'cta_link' => 'http://utexas.edu',
      ),
    ),
  ),
  'field_utexas_flex_content_area_b' => array(),
  'field_utexas_hero_photo' => array(
    'und' => array(
      0 => array(
        'image_fid' => 5,
        'caption' => 'Lorem Ipsum Dolor Sit Amet',
        'credit' => NULL,
        'subhead' => 'Integer nisl turpis, ornare sed porta nec',
        'link_href' => 'http://utexas.edu',
        'link_text' => 'Learn More',
        'hero_image_style' => 'hero-style-3',
        'hero_image_position' => 'center',
      ),
    ),
  ),
  'field_utexas_image_link_a' => array(),
  'field_utexas_image_link_b' => array(),
  'field_utexas_newsreel' => array(
    'und' => array(
      0 => array(
        'headline' => 'Latest Sci & Tech News',
        'type' => array(
          'news' => 'news',
          'press-releases' => 'press-releases',
          'texas-perspectives' => 'texas-perspectives',
        ),
        'category' => array('science-and-technology' => 'science-and-technology'),
        'tag' => '',
        'count' => 4,
        'include_description' => 1,
        'refresh_rate' => 1,
        'view_all' => 'View all news',
      ),
    ),
  ),
  'field_utexas_photo_content_area' => array(),
  'field_utexas_promo_list' => array(),
  'field_utexas_promo_units' => array(
    'und' => array(
      0 => array(
        'title' => '',
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In ultrices facilisis venenatis. Vestibulum molestie ornare ullamcorper. Mauris facilisis est id quam tristique elementum.',
        'copy_format' => 'filtered_html',
        'image_fid' => 5,
        'link' => 'http://utexas.edu',
        'cta' => 'Lorem Ipsum',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
      1 => array(
        'title' => NULL,
        'headline' => 'Dolor sit amet',
        'copy_value' => 'Proin tincidunt elementum lorem, dictum semper mi dignissim et. Nunc a ante ultrices urna pellentesque luctus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. ',
        'copy_format' => 'filtered_html',
        'image_fid' => 4,
        'link' => 'http://utexas.edu',
        'cta' => 'Dolor sit amet',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
    ),
  ),
  'field_utexas_quick_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Departments',
        'copy_value' => '',
        'copy_format' => 'filtered_html',
        'links' => 'a:15:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}i:4;a:3:{s:10:"link_title";s:19:"Proin in arcu neque";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-6;}i:5;a:3:{s:10:"link_title";s:25:"Nam sit amet semper ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-5;}i:6;a:3:{s:10:"link_title";s:33:"Nulla interdum, neque ac molestie";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-4;}i:7;a:3:{s:10:"link_title";s:22:"Duis at fermentum nunc";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-3;}i:8;a:3:{s:10:"link_title";s:20:"Quisque massa mauris";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-2;}i:9;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-1;}i:10;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:0;}i:11;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:1;}i:12;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:2;}i:13;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:3;}i:14;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:4;}}',
      ),
    ),
  ),
  'field_utexas_social_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Connect',
        'links' => 'a:9:{s:8:"Facebook";s:18:"http://twitter.com";s:7:"Twitter";s:19:"http://facebook.com";s:9:"Instagram";s:20:"http://instagram.com";s:8:"LinkedIn";s:0:"";s:7:"YouTube";s:0:"";s:10:"GooglePlus";s:0:"";s:6:"Flickr";s:0:"";s:9:"Pinterest";s:0:"";s:6:"Tumblr";s:0:"";}',
      ),
    ),
  ),
  'field_utexas_twitter_widget' => array(),
  'field_wysiwyg_a' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>

<ul>
  <li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
  <li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
  <li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>
',
        'format' => 'filtered_html',
        'safe_value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>
<ul><li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
<li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
<li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>',
      ),
    ),
  ),
  'field_wysiwyg_b' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2015-08-24 15:09:53 +0000',
);

$landing_pages[] = array(
  'uid' => 1,
  'title' => 'Landing Page Template 2',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '3496d02f-24c6-4c16-a024-3e34f1ca9b4f',
  'type' => 'landing_page',
  'language' => 'und',
  'created' => 1440427028,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'f3d47a02-82e8-4e1e-8eeb-335e44d9f0ed',
  'revision_uid' => 1,
  'field_page_layout' => array(
    'und' => array(
      0 => array(
        'context' => 'context_field-node-3',
      ),
    ),
  ),
  'field_template' => array(
    'und' => array(
      0 => array(
        'target_id' => 10,
      ),
    ),
  ),
  'field_utexas_background_accent' => array(
    'und' => array(
      0 => array(
        'image_fid' => 7,
      ),
    ),
  ),
  'field_utexas_contact_info' => array(
    'und' => array(
      0 => array(
        'target_id' => 1,
      ),
    ),
  ),
  'field_utexas_featured_highlight' => array(
    'und' => array(
      0 => array(
        'image_fid' => 6,
        'date' => '2015-08-24',
        'headline' => 'Pellentesque habitant morbi tristique senectus',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'link' => 'http://utexas.edu',
        'cta' => 'Cras euismod',
        'highlight_style' => 'navy',
      ),
    ),
  ),
  'field_utexas_flex_content_area_a' => array(
    'und' => array(
      0 => array(
        'image_fid' => 3,
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Proin in arcu neque.',
        'cta_link' => 'http://utexas.edu',
      ),
      1 => array(
        'image_fid' => 5,
        'headline' => 'Quisque massa mauris',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Morbi laoreet molestie',
        'cta_link' => 'http://google.com',
      ),
      2 => array(
        'image_fid' => 4,
        'headline' => 'Aliquam erat volutpat.',
        'copy_value' => 'Ut id ullamcorper ipsum, et porttitor neque. Donec sodales bibendum enim ac interdum.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Morbi laoreet molestie.',
        'cta_link' => 'http://utexas.edu',
      ),
    ),
  ),
  'field_utexas_flex_content_area_b' => array(),
  'field_utexas_hero_photo' => array(
    'und' => array(
      0 => array(
        'image_fid' => 5,
        'caption' => 'Lorem Ipsum Dolor Sit Amet',
        'credit' => NULL,
        'subhead' => 'Integer nisl turpis, ornare sed porta nec',
        'link_href' => 'http://utexas.edu',
        'link_text' => 'Learn More',
        'hero_image_style' => 'hero-style-5',
        'hero_image_position' => 'center',
      ),
    ),
  ),
  'field_utexas_image_link_a' => array(),
  'field_utexas_image_link_b' => array(),
  'field_utexas_newsreel' => array(
    'und' => array(
      0 => array(
        'headline' => 'Latest Sci & Tech News',
        'type' => array(
          'news' => 'news',
          'press-releases' => 'press-releases',
          'texas-perspectives' => 'texas-perspectives',
        ),
        'category' => array('science-and-technology' => 'science-and-technology'),
        'tag' => '',
        'count' => 4,
        'include_description' => 1,
        'refresh_rate' => 1,
        'view_all' => 'View all news',
      ),
    ),
  ),
  'field_utexas_photo_content_area' => array(),
  'field_utexas_promo_list' => array(),
  'field_utexas_promo_units' => array(
    'und' => array(
      0 => array(
        'title' => '',
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In ultrices facilisis venenatis. Vestibulum molestie ornare ullamcorper. Mauris facilisis est id quam tristique elementum.',
        'copy_format' => 'filtered_html',
        'image_fid' => 5,
        'link' => 'http://utexas.edu',
        'cta' => 'Lorem Ipsum',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
      1 => array(
        'title' => NULL,
        'headline' => 'Dolor sit amet',
        'copy_value' => 'Proin tincidunt elementum lorem, dictum semper mi dignissim et. Nunc a ante ultrices urna pellentesque luctus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. ',
        'copy_format' => 'filtered_html',
        'image_fid' => 4,
        'link' => 'http://utexas.edu',
        'cta' => 'Dolor sit amet',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
    ),
  ),
  'field_utexas_quick_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Departments',
        'copy_value' => '',
        'copy_format' => 'filtered_html',
        'links' => 'a:15:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}i:4;a:3:{s:10:"link_title";s:19:"Proin in arcu neque";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-6;}i:5;a:3:{s:10:"link_title";s:25:"Nam sit amet semper ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-5;}i:6;a:3:{s:10:"link_title";s:33:"Nulla interdum, neque ac molestie";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-4;}i:7;a:3:{s:10:"link_title";s:22:"Duis at fermentum nunc";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-3;}i:8;a:3:{s:10:"link_title";s:20:"Quisque massa mauris";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-2;}i:9;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-1;}i:10;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:0;}i:11;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:1;}i:12;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:2;}i:13;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:3;}i:14;a:3:{s:10:"link_title";s:20:"Cras euismod viverra";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:4;}}',
      ),
    ),
  ),
  'field_utexas_social_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Connect',
        'links' => 'a:9:{s:8:"Facebook";s:18:"http://twitter.com";s:7:"Twitter";s:19:"http://facebook.com";s:9:"Instagram";s:20:"http://instagram.com";s:8:"LinkedIn";s:0:"";s:7:"YouTube";s:0:"";s:10:"GooglePlus";s:0:"";s:6:"Flickr";s:0:"";s:9:"Pinterest";s:0:"";s:6:"Tumblr";s:0:"";}',
      ),
    ),
  ),
  'field_utexas_twitter_widget' => array(),
  'field_wysiwyg_a' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>

<ul>
  <li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
  <li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
  <li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>
',
        'format' => 'filtered_html',
        'safe_value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>
<ul><li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
<li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
<li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>',
      ),
    ),
  ),
  'field_wysiwyg_b' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2015-08-24 14:37:08 +0000',
);

$landing_pages[] = array(
  'uid' => 1,
  'title' => 'Landing Page Template 3',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 1,
  'sticky' => 0,
  'vuuid' => '9c705991-3751-4433-b497-3d1dfba515cc',
  'type' => 'landing_page',
  'language' => 'und',
  'created' => 1440429114,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '2622c6e9-b713-46dc-a069-031d288c71f3',
  'revision_uid' => 1,
  'field_page_layout' => array(
    'und' => array(
      0 => array(
        'context' => 'context_field-node-4',
      ),
    ),
  ),
  'field_template' => array(
    'und' => array(
      0 => array(
        'target_id' => 11,
      ),
    ),
  ),
  'field_utexas_background_accent' => array(
    'und' => array(
      0 => array(
        'image_fid' => 7,
      ),
    ),
  ),
  'field_utexas_contact_info' => array(
    'und' => array(
      0 => array(
        'target_id' => 1,
      ),
    ),
  ),
  'field_utexas_featured_highlight' => array(
    'und' => array(
      0 => array(
        'image_fid' => 6,
        'date' => 0,
        'headline' => 'Pellentesque habitant morbi tristique senectus',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'link' => 'http://utexas.edu',
        'cta' => 'Cras euismod',
        'highlight_style' => 'navy',
      ),
    ),
  ),
  'field_utexas_flex_content_area_a' => array(
    'und' => array(
      0 => array(
        'image_fid' => 3,
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.',
        'copy_format' => 'filtered_html',
        'links' => 'a:4:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
      1 => array(
        'image_fid' => 5,
        'headline' => 'Quisque massa mauris',
        'copy_value' => 'Mauris arcu purus, blandit id dictum at, tristique a metus. Proin in arcu neque.',
        'copy_format' => 'filtered_html',
        'links' => 'a:4:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
      2 => array(
        'image_fid' => 4,
        'headline' => 'Aliquam erat volutpat.',
        'copy_value' => 'Ut id ullamcorper ipsum, et porttitor neque. Donec sodales bibendum enim ac interdum.',
        'copy_format' => 'filtered_html',
        'links' => 'a:4:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
      3 => array(
        'image_fid' => 6,
        'headline' => 'Quisque massa mauris',
        'copy_value' => 'In est lorem, ultrices eu tincidunt non, mattis a turpis. Nulla laoreet nunc eu nisi malesuada.',
        'copy_format' => 'filtered_html',
        'links' => 'a:4:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
    ),
  ),
  'field_utexas_flex_content_area_b' => array(),
  'field_utexas_hero_photo' => array(
    'und' => array(
      0 => array(
        'image_fid' => 5,
        'caption' => 'Lorem Ipsum Dolor Sit Amet',
        'credit' => NULL,
        'subhead' => 'Integer nisl turpis, ornare sed porta nec',
        'link_href' => 'http://utexas.edu',
        'link_text' => 'Learn More',
        'hero_image_style' => 'hero-style-4',
        'hero_image_position' => 'center',
      ),
    ),
  ),
  'field_utexas_image_link_a' => array(),
  'field_utexas_image_link_b' => array(),
  'field_utexas_newsreel' => array(
    'und' => array(
      0 => array(
        'headline' => 'Latest Sci & Tech News',
        'type' => array(
          'news' => 'news',
          'press-releases' => 'press-releases',
          'texas-perspectives' => 'texas-perspectives',
        ),
        'category' => array('science-and-technology' => 'science-and-technology'),
        'tag' => '',
        'count' => 4,
        'include_description' => 1,
        'refresh_rate' => 1,
        'view_all' => 'View all news',
      ),
    ),
  ),
  'field_utexas_photo_content_area' => array(),
  'field_utexas_promo_list' => array(),
  'field_utexas_promo_units' => array(
    'und' => array(
      0 => array(
        'title' => '',
        'headline' => 'Lorem Ipsum',
        'copy_value' => 'Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. In ultrices facilisis venenatis. Vestibulum molestie ornare ullamcorper. Mauris facilisis est id quam tristique elementum.',
        'copy_format' => 'filtered_html',
        'image_fid' => 5,
        'link' => 'http://utexas.edu',
        'cta' => 'Lorem Ipsum',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
      1 => array(
        'title' => NULL,
        'headline' => 'Dolor sit amet',
        'copy_value' => 'Proin tincidunt elementum lorem, dictum semper mi dignissim et. Nunc a ante ultrices urna pellentesque luctus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. ',
        'copy_format' => 'filtered_html',
        'image_fid' => 4,
        'link' => 'http://utexas.edu',
        'cta' => 'Dolor sit amet',
        'size_option' => 'utexas_promo_unit_landscape_image',
      ),
    ),
  ),
  'field_utexas_quick_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Departments',
        'copy_value' => '',
        'copy_format' => 'filtered_html',
        'links' => 'a:7:{i:0;a:3:{s:10:"link_title";s:11:"Lorem Ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:14:"Dolor Sit Amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:22:"Caecilius est in Horto";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:17:"Mauris arcu purus";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}i:4;a:3:{s:10:"link_title";s:19:"Proin in arcu neque";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-6;}i:5;a:3:{s:10:"link_title";s:25:"Nam sit amet semper ipsum";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-5;}i:6;a:3:{s:10:"link_title";s:33:"Nulla interdum, neque ac molestie";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-4;}}',
      ),
    ),
  ),
  'field_utexas_social_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Connect',
        'links' => 'a:9:{s:8:"Facebook";s:18:"http://twitter.com";s:7:"Twitter";s:19:"http://facebook.com";s:9:"Instagram";s:20:"http://instagram.com";s:8:"LinkedIn";s:0:"";s:7:"YouTube";s:0:"";s:10:"GooglePlus";s:0:"";s:6:"Flickr";s:0:"";s:9:"Pinterest";s:0:"";s:6:"Tumblr";s:0:"";}',
      ),
    ),
  ),
  'field_utexas_twitter_widget' => array(),
  'field_wysiwyg_a' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>

<ul>
  <li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
  <li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
  <li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>
',
        'format' => 'filtered_html',
        'safe_value' => '<p>Morbi laoreet molestie arcu id lacinia. Nam sit amet semper ipsum. Nulla interdum, neque ac molestie egestas, ligula justo feugiat tortor, nec ultricies nulla justo a orci. Donec pulvinar ipsum elit, a congue sapien semper id. In finibus turpis eget suscipit sollicitudin. Morbi pulvinar nisi consequat metus porttitor lacinia. Etiam turpis magna, mattis sit amet turpis nec, varius ullamcorper tellus. Phasellus id cursus nibh. Ut non enim sed lorem convallis vehicula id at mauris. Quisque lobortis massa id lorem ultrices, at lobortis odio sodales.</p>
<ul><li>Cras venenatis vel mi ac volutpat. Fusce at facilisis dui.</li>
<li>Phasellus consectetur, nibh a finibus auctor, massa tortor placerat tortor, eu cursus arcu nulla sit amet nisl.</li>
<li>Etiam vitae est condimentum, elementum lacus nec, molestie urna. Duis at fermentum nunc.</li>
</ul>',
      ),
    ),
  ),
  'field_wysiwyg_b' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'sioc:Item',
      1 => 'foaf:Document',
    ),
    'title' => array(
      'predicates' => array(
        0 => 'dc:title',
      ),
    ),
    'created' => array(
      'predicates' => array(
        0 => 'dc:date',
        1 => 'dc:created',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'changed' => array(
      'predicates' => array(
        0 => 'dc:modified',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
    'body' => array(
      'predicates' => array(
        0 => 'content:encoded',
      ),
    ),
    'uid' => array(
      'predicates' => array(
        0 => 'sioc:has_creator',
      ),
      'type' => 'rel',
    ),
    'name' => array(
      'predicates' => array(
        0 => 'foaf:name',
      ),
    ),
    'comment_count' => array(
      'predicates' => array(
        0 => 'sioc:num_replies',
      ),
      'datatype' => 'xsd:integer',
    ),
    'last_activity' => array(
      'predicates' => array(
        0 => 'sioc:last_activity_date',
      ),
      'datatype' => 'xsd:dateTime',
      'callback' => 'date_iso8601',
    ),
  ),
  'name' => 'admin',
  'picture' => 0,
  'data' => 'b:0;',
  'date' => '2015-08-24 15:11:54 +0000',
);

foreach ($landing_pages as $page) {
  $node = new stdClass();
  $node->title = $page['title'];
  $node->type = 'landing_page';
  // Add some node defaults (log, revision, date).
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;
  $node->status = 1;
  $node->promote = 0;
  $node->comment = 0;
  $node->field_page_layout = $page['field_page_layout'];
  $node->field_template = $page['field_template'];
  $node->field_utexas_background_accent = $page['field_utexas_background_accent'];
  $node->field_utexas_featured_highlight = $page['field_utexas_featured_highlight'];
  $node->field_utexas_hero_photo = $page['field_utexas_hero_photo'];
  $node->field_utexas_promo_units = $page['field_utexas_promo_units'];
  $node->field_utexas_newsreel = $page['field_utexas_newsreel'];
  $node->field_utexas_quick_links = $page['field_utexas_quick_links'];
  $node->field_wysiwyg_a = $page['field_wysiwyg_a'];
  $node->field_utexas_photo_content_area = $page['field_utexas_photo_content_area'];
  $node->field_utexas_flex_content_area_a = $page['field_utexas_flex_content_area_a'];
  $node->field_utexas_contact_info = $page['field_utexas_contact_info'];
  // Add default user and creation date.
  $node = node_submit($node);
  node_save($node);

  // Assign the correct context to this node.
  $export[$node->title]->name = 'context_field-node-' . $node->nid;
  // Save the context.
  context_save($export[$node->title]);
}
