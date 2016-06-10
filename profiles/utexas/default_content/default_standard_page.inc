<?php

/**
 * @file
 * Default Standard Page content.
 */

$profile_dir = drupal_get_path('profile', 'utexas');
if ($handle = fopen($profile_dir . '/default_content/assets/' . 'dummy-560x315.png', 'r')) {
  $file = file_save_data($handle, 'public://dummy-560x315.png');
  fclose($handle);
  $file->field_file_image_alt_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
  $file->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
  file_save($file);
}

// Add a default youtube video for testing purposes ($file->fid = 2).
$video['filename'] = 'What is the UT Drupal Kit?';
$video['uri'] = 'youtube://v/49uRQ38EpD4';
$video['filemime'] = 'video/youtube';
$video['status'] = 1;
$youtube_video = db_merge('file_managed')
  ->key(array('filename' => $video['filename']))
  ->fields(array(
    'filename' => $video['filename'],
    'uri' => $video['uri'],
    'filemime' => $video['filemime'],
    'filesize' => 0,
    'timestamp' => time(),
    'status' => $video['status'],
    'type' => 'video',
  ))
  ->execute();

$images = array(
  '1960s.jpg',
  'fishing.jpg',
  'museo-columns.jpg',
  'retro-computer.jpg',
);
foreach ($images as $image_filename) {
  if ($handle = fopen($profile_dir . '/default_content/assets/' . $image_filename, 'r')) {
    $file = file_save_data($handle, 'public://' . $image_filename);
    fclose($handle);
    $file->field_file_image_alt_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
    $file->field_file_image_title_text[LANGUAGE_NONE][0]['value'] = 'placeholder image';
    file_save($file);
  }
}

// Add samples of each available page template.
// Default default promo list item (used below).
$promo_list_item = array(
  'headline' => 'List item',
  'image_fid' => 1,
  'link' => '<front>',
  'copy_value' => 'Cras porta cursus fermentum. Integer orci nunc, lobortis non sem sit amet, lobortis blandit turpis.',
  'copy_format' => 'filtered_html',
);
$promo_list_headline = array(
  'value' => 'Promo List',
  'format' => NULL,
  'safe_value' => 'Promo List',
);
$promo_list_style_2 = array(
  'value' => 'Two lists, side-by-side',
);

// Creating contact info form.
$entity_type = 'contact_info';
$entity = entity_create($entity_type, array(
  'name' => 'Example Contact Form',
  'field_location_1' => '795 E Dragon',
  'field_location_2' => 'Trlr. 123',
  'field_location_3' => '',
  'field_location_city' => 'Austin',
  'field_location_state' => 'Texas',
  'field_location_zip' => '78501',
  'field_address_1' => '1000 N Subway Ave.',
  'field_address_2' => '#777',
  'field_address_3' => '',
  'field_address_city' => 'Austin',
  'field_address_state' => 'Texas',
  'field_address_zip' => '78500-0000',
  'field_url' => 'http://utexas.edu',
  'field_phone' => '512-123-4567',
  'field_fax' => '',
  'field_email' => 'email@domain.com',
  ));
$wrapper = entity_metadata_wrapper($entity_type, $entity);
$wrapper->save();

$pages[] = array(
  'uid' => 1,
  'title' => 'Welcome to Your New Site',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '42a14cde-cb63-460c-ac31-6d0ef6e3fee4',
  'type' => 'standard_page',
  'language' => 'und',
  'created' => 1434640350,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => '80dbdaac-58a4-46dd-9e6f-90e76c50f56f',
  'revision_uid' => 1,
  'field_page_layout' => array(
    'und' => array(
      0 => array(
        'context' => 'context_field-node-1',
      ),
    ),
  ),
  'field_template' => array(
    'und' => array(
      0 => array(
        'target_id' => 5,
      ),
    ),
  ),
  'field_utexas_featured_highlight' => array(
    'und' => array(
      0 => array(
        'image_fid' => 2,
        'date' => '2015-06-17',
        'headline' => 'Featured Highlight',
        'copy_value' => 'Emphasize date-driven content with this edge-to-edge pane. Easily embed images or youtube videos.',
        'copy_format' => 'filtered_html',
        'link' => '<front>',
        'cta' => 'Visit content',
        'highlight_style' => 'navy',
      ),
    ),
  ),
  'field_utexas_flex_content_area_a' => array(
    'und' => array(
      0 => array(
        'image_fid' => 1,
        'headline' => 'Flex Content (Call to Action)',
        'copy_value' => 'Flex Content Areas fit responsively into many page regions. They can include a single "Call to Action" link, or a set of standard links.',
        'copy_format' => 'filtered_html',
        'links' => 'a:0:{}',
        'cta_title' => 'Call to Action',
        'cta_link' => 'http://www.utexas.edu',
      ),
      1 => array(
        'image_fid' => 1,
        'headline' => 'Flex Content (with links)',
        'copy_value' => 'Images scale to 280 x 160px on desktop view.',
        'copy_format' => 'filtered_html',
        'links' => 'a:3:{i:0;a:3:{s:10:"link_title";s:13:"External Link";s:8:"link_url";s:21:"http://www.utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:13:"Internal Link";s:8:"link_url";s:7:"<front>";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:6:"Link 3";s:8:"link_url";s:21:"http://www.utexas.edu";s:7:"_weight";i:-8;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
    ),
  ),
  'field_utexas_flex_content_area_b' => array(
    'und' => array(
      0 => array(
        'image_fid' => 0,
        'headline' => '',
        'copy_value' => '',
        'copy_format' => 'filtered_html',
        'links' => 'a:5:{i:0;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}i:4;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-6;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
      1 => array(
        'image_fid' => 0,
        'headline' => '',
        'copy_value' => '',
        'copy_format' => 'filtered_html',
        'links' => 'a:5:{i:0;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-8;}i:3;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-7;}i:4;a:3:{s:10:"link_title";s:26:"Lorem ipsum dolor sit amet";s:8:"link_url";s:17:"http://utexas.edu";s:7:"_weight";i:-6;}}',
        'cta_title' => '',
        'cta_link' => '',
      ),
    ),
  ),
  'field_utexas_hero_photo' => array(
    'und' => array(
      0 => array(
        'image_fid' => 1,
        'caption' => 'This is a "Hero Image"',
        'credit' => 'Photo from Associated Press archive.',
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
  'field_utexas_photo_content_area' => array(
    'und' => array(
      0 => array(
        'image_fid' => 1,
        'headline' => 'Photo Content Area',
        'copy_value' => 'Feature content with an accent image.',
        'credit' => 'Enter an optional photo credit',
        'copy_format' => 'filtered_html',
        'links' => 'a:1:{i:0;a:3:{s:10:"link_title";s:21:"Reference a link here";s:8:"link_url";s:21:"http://www.utexas.edu";s:7:"_weight";i:-10;}}',
      ),
    ),
  ),
  'field_utexas_promo_list' => array(),
  'field_utexas_promo_units' => array(
    'und' => array(
      0 => array(
        'title' => 'Promo Unit',
        'headline' => 'This is a "Promo Unit"',
        'copy_value' => 'Use this to feature items with an image, copy text, and optional "Call to Action" link',
        'copy_format' => 'filtered_html',
        'image_fid' => 1,
        'link' => 'http://www.utexas.edu',
        'cta' => 'Visit this featured content',
      ),
      1 => array(
        'headline' => 'Promo Unit 2',
        'copy_value' => 'Images scale at 220 x 140px on desktop view.',
        'copy_format' => 'filtered_html',
        'image_fid' => 1,
        'link' => 'http://www.utexas.edu',
        'cta' => 'Visit some different content',
      ),
    ),
  ),
  'field_utexas_quick_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Quick Links',
        'copy_value' => 'Add internal/external links to this "Quick Links" section (customizable headline).',
        'copy_format' => 'filtered_html',
        'links' => 'a:3:{i:0;a:3:{s:10:"link_title";s:13:"Site Homepage";s:8:"link_url";s:7:"<front>";s:7:"_weight";i:-10;}i:1;a:3:{s:10:"link_title";s:9:"UT Direct";s:8:"link_url";s:26:"http://utdirect.utexas.edu";s:7:"_weight";i:-9;}i:2;a:3:{s:10:"link_title";s:19:"Academic Experience";s:8:"link_url";s:47:"http://www.utexas.edu/about/academic-experience";s:7:"_weight";i:-8;}}',
      ),
    ),
  ),
  'field_utexas_social_links' => array(
    'und' => array(
      0 => array(
        'headline' => 'Social Links Block',
        'links' => 'a:9:{s:8:"Facebook";s:29:"http://facebook.com/myaccount";s:7:"Twitter";s:28:"http://twitter.com/myaccount";s:9:"Instagram";s:0:"";s:8:"LinkedIn";s:0:"";s:7:"YouTube";s:28:"http://youtube.com/myaccount";s:10:"GooglePlus";s:32:"http://plus.google.com/myaccount";s:6:"Flickr";s:0:"";s:9:"Pinterest";s:0:"";s:6:"Tumblr";s:0:"";}',
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
  'field_wysiwyg_a' => array(
    'und' => array(
      0 => array(
        'value' => '<strong>WYSIWYG fields</strong> allow you to add any amount of formatted text. Use this for brief descriptions, or for detailed content. Below, the "Flex Content" field is being used to show a series of pertinent links.',
        'format' => 'filtered_html',
        'safe_value' => '<p><strong>WYSIWYG fields</strong> allow you to add any amount of formatted text. Use this for brief descriptions, or for detailed content.</p><p>Below, the "Flex Content" field is being used to show a series of pertinent links.</p>',
      ),
    ),
  ),
  'field_wysiwyg_b' => array(
    'und' => array(
      0 => array(
        'value' => 'Content is king. Use the "WYSIWYG" fields to add formatted text. Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt.<table>
    <thead>
    <tr>
      <th>Header One</th>
      <th>Header Two</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Easily add tables with the WYSIWYG toolbar</td>
      <td>Styled to match the brand</td>
    </tr>
    <tr>
      <td>Tables respond to display on smaller screens</td>
      <td>Fully accessible to screen readers</td>
    </tr>
  </tbody>
</table>',
        'format' => 'filtered_html',
        'safe_value' => '<p>Content is king. Use the "WYSIWYG" fields to add formatted text.</p>
<p>Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi.</p><table>
  <thead>
    <tr>
      <th>Header One</th>
      <th>Header Two</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Easily add tables with the WYSIWYG toolbar</td>
      <td>Styled to match the brand</td>
    </tr>
    <tr>
      <td>Tables respond to display on smaller screens</td>
      <td>Fully accessible to screen readers</td>
    </tr>
  </tbody>
</table>
        ',
      ),
    ),
  ),
  'body' => array(),
  'rdf_mapping' => array(
    'rdftype' => array(
      0 => 'foaf:Document',
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
  'date' => '2015-06-18 17:12:30 +0200',
);

foreach ($pages as $page) {
  $node = new stdClass();
  $node->title = $page['title'];
  $node->type = 'standard_page';
  // Add some node defaults (log, revision, date).
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;
  $node->status = 1;
  $node->promote = 0;
  $node->comment = 0;

  $node->field_page_layout = $page['field_page_layout'];
  $node->field_template = $page['field_template'];
  $node->field_utexas_featured_highlight = $page['field_utexas_featured_highlight'];
  $node->field_utexas_hero_photo = $page['field_utexas_hero_photo'];
  $node->field_utexas_promo_units = $page['field_utexas_promo_units'];
  $node->field_utexas_quick_links = $page['field_utexas_quick_links'];
  $node->field_wysiwyg_a = $page['field_wysiwyg_a'];
  $node->field_wysiwyg_b = $page['field_wysiwyg_b'];
  $node->field_utexas_image_link_a = $page['field_utexas_image_link_a'];
  $node->field_utexas_image_link_b = $page['field_utexas_image_link_b'];
  $node->field_utexas_newsreel = $page['field_utexas_newsreel'];
  $node->field_utexas_social_links = $page['field_utexas_social_links'];
  $node->field_utexas_photo_content_area = $page['field_utexas_photo_content_area'];
  $node->field_utexas_flex_content_area_a = $page['field_utexas_flex_content_area_a'];
  $node->field_utexas_flex_content_area_b = $page['field_utexas_flex_content_area_b'];
  $node->field_utexas_contact_info = $page['field_utexas_contact_info'];

  // Add default user and creation date.
  $node = node_submit($node);

  $count = 0;
  while ($count < 1) {
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_utexas_promo_list'));
    $field_collection_item->setHostEntity('node', $node);
    $field_collection_item->field_utexas_promo_list_headline[LANGUAGE_NONE][] = $promo_list_headline;
    // Add three promo list items.
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_style[LANGUAGE_NONE][] = $promo_list_style_2;
    $field_collection_item->save();

    // Add Promo List field collection.
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_utexas_promo_list'));
    $field_collection_item->setHostEntity('node', $node);
    $field_collection_item->field_utexas_promo_list_headline[LANGUAGE_NONE][] = array(
      'value' => 'Promo List',
      'format' => NULL,
      'safe_value' => 'Promo List',
    );
    // Add three promo list items.
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_item[LANGUAGE_NONE][] = $promo_list_item;
    $field_collection_item->field_utexas_promo_list_style[LANGUAGE_NONE][] = array(
      'value' => 'Two lists, side-by-side',
    );
    $field_collection_item->save();
    $count++;
  }

  // Re-save newsreel to ensure correct serialization.
  $node->field_utexas_newsreel = $page['field_utexas_newsreel'];

  node_save($node);
}

$context['name'] = 'context_field-node-1';
$context['description'] = 'custom';
$context['tag'] = 'Context Field Custom';
$context['conditions'] = array(
  'context_field' => array(
    'values' => array(
      1 => 1,
    ),
  ),
);
$context['reactions'] = unserialize('a:3:{s:5:"block";a:1:{s:6:"blocks";a:7:{s:43:"fieldblock-208a521aa519bc1ed37d8992aeffae83";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"208a521aa519bc1ed37d8992aeffae83";s:6:"region";s:21:"main_content_top_left";s:6:"weight";i:0;}s:43:"fieldblock-fda604d130a57f15015895c8268f20d2";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"fda604d130a57f15015895c8268f20d2";s:6:"region";s:21:"main_content_top_left";s:6:"weight";i:1;}s:43:"fieldblock-c4c10ae36665adf0e722e7e3f4be74d4";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"c4c10ae36665adf0e722e7e3f4be74d4";s:6:"region";s:22:"main_content_top_right";s:6:"weight";i:0;}s:43:"fieldblock-9c079efa827f76dea650869c5d2631e6";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"9c079efa827f76dea650869c5d2631e6";s:6:"region";s:14:"content_bottom";s:6:"weight";i:0;}s:43:"fieldblock-bf40687156268eaa30437ed84189f13e";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"bf40687156268eaa30437ed84189f13e";s:6:"region";s:14:"content_bottom";s:6:"weight";i:1;}s:43:"fieldblock-669a6a1f32566fa73ea7974696027184";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"669a6a1f32566fa73ea7974696027184";s:6:"region";s:14:"sidebar_second";s:6:"weight";i:0;}s:43:"fieldblock-38205d43426b33bd0fe595ff8ca61ffd";a:4:{s:6:"module";s:10:"fieldblock";s:5:"delta";s:32:"38205d43426b33bd0fe595ff8ca61ffd";s:6:"region";s:14:"sidebar_second";s:6:"weight";i:1;}}}s:5:"theme";a:2:{s:5:"title";s:0:"";s:8:"subtitle";s:0:"";}s:10:"theme_html";a:1:{s:5:"class";s:0:"";}}');
$context['condition_mode'] = 0;

db_merge('context')
  ->key(array('name' => $context['name']))
  ->fields(array(
    'name' => $context['name'],
    'description' => $context['description'],
    'tag' => $context['tag'],
    'conditions' => serialize($context['conditions']),
    'reactions' => serialize($context['reactions']),
    'condition_mode' => $context['condition_mode'],
  ))
  ->execute();
