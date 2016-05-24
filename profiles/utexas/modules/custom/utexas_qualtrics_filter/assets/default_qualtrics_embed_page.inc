<?php

/**
 * @file
 * Default Embed standard page.
 */

/**
 * Helper function to install a default page.
 */
function _utexas_qualtrics_filter_default_page() {
  $pages[] = array(
    'uid' => 1,
    'title' => 'Qualtrics Demo',
    'log' => '',
    'status' => 1,
    'comment' => 0,
    'promote' => 0,
    'sticky' => 0,
    'type' => 'standard_page',
    'language' => 'und',
    'created' => 1449267569,
    'tnid' => 0,
    'translate' => 0,
    'revision_uid' => 1,
    'field_standard_page_tags' => array(),
    'field_template' => array(
      'und' => array(
        0 => array(
          'target_id' => 2,
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
    'field_utexas_featured_highlight' => array(),
    'field_utexas_flex_content_area_a' => array(),
    'field_utexas_flex_content_area_b' => array(),
    'field_utexas_hero_photo' => array(),
    'field_utexas_image_link_a' => array(),
    'field_utexas_image_link_b' => array(),
    'field_utexas_newsreel' => array(
      'und' => array(
        0 => array(
          'headline' => 'Latest from UTNews',
          'type' => 'a:3:{s:4:"news";s:4:"news";s:14:"press-releases";s:14:"press-releases";s:18:"texas-perspectives";s:18:"texas-perspectives";}',
          'category' => 'a:7:{s:19:"arts-and-humanities";s:19:"arts-and-humanities";s:20:"business-and-economy";s:20:"business-and-economy";s:20:"campus-and-community";s:20:"campus-and-community";s:24:"education-and-leadership";s:24:"education-and-leadership";s:19:"health-and-wellness";s:19:"health-and-wellness";s:14:"policy-and-law";s:14:"policy-and-law";s:22:"science-and-technology";s:22:"science-and-technology";}',
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
    'field_utexas_promo_units' => array(),
    'field_utexas_quick_links' => array(),
    'field_utexas_resource' => array(),
    'field_utexas_social_links' => array(),
    'field_utexas_twitter_widget' => array(),
    'field_wysiwyg_a' => array(
      'und' => array(
        0 => array(
          'value' => '<p>This page demonstrates adding Qualtrics forms to the site. This first example is a form with the Qualtrics default height and HTML title, accomplished with the following shortcode:</p>
          <p>&nbsp;</p>
          <p>&#91;embed&#93;&#91;https&#93;:&#47;&#47;utexas.qualtrics&#91;dot&#93;com/SE/?SID=SV_af1Gk9JWK2khAEJ&#91;/embed&#93;</p>

<p>[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ[/embed]</p>
  ',
          'format' => 'filtered_html',
          'safe_value' => '<p>This page demonstrates adding Qualtrics forms to the site. This first example is a form with the Qualtrics default height and HTML title, accomplished with the following shortcode:</p>
          <p>&nbsp;</p>
          <p>&#91;embed&#93;&#91;https&#93;:&#47;&#47;utexas.qualtrics&#91;dot&#93;com/SE/?SID=SV_af1Gk9JWK2khAEJ&#91;/embed&#93;</p>

<p>[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ[/embed]</p>
  ',
        ),
      ),
    ),
    'field_wysiwyg_b' => array(
      'und' => array(
        0 => array(
          'value' => '<p>The below shortcode sets the height and HTML title:</p>
          <p>&nbsp;</p>
          <p>&#91;embed&#93;&#91;https&#93;:&#47;&#47;utexas.qualtrics&#91;dot&#93;com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:My new Qualtrics Form Title | height:800 [/embed&#93;</p>

<p>[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:My new Qualtrics Form Title | height:800 [/embed]</p>

<p>Qualtrics shortcodes can be embedded alongside other content, in any region on the page.</p>
  ',
          'format' => 'filtered_html',
          'safe_value' => '<p>The below shortcode sets the height and HTML title:</p>
          <p>&nbsp;</p>
          <p>&#91;embed&#93;&#91;https&#93;:&#47;&#47;utexas.qualtrics&#91;dot&#93;com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:My new Qualtrics Form Title | height:800 [/embed&#93;</p>

<p>[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:My new Qualtrics Form Title | height:800 [/embed]</p>

<p>Qualtrics shortcodes can be embedded alongside other content, in any region on the page.</p>
  ',
        ),
      ),
    ),
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
    'path' => array(
      'pathauto' => 1,
    ),
    'name' => 'admin',
    'picture' => 0,
    'data' => 'b:0;',
    'pathauto_perform_alias' => FALSE,
    'date' => '2015-12-04 22:19:29 +0000',
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
    $node->uid = 1;

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

    node_save($node);

    // Re-save the node to get the correct context page layout nid;

    $node->field_page_layout = array(
      'und' => array(
        0 => array(
          'context' => 'context_field-node-' . $node->nid,
        ),
      ),
    );
  }

  $context['name'] = 'context_field-node-' . $node->nid;
  $context['description'] = 'custom';
  $context['tag'] = 'Context Field Custom';
  $context['conditions'] = array(
    'context_field' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context['reactions'] = array(
    'block' => array(
      'blocks' => array(
        'fieldblock-bf40687156268eaa30437ed84189f13e' => array(
          'module' => 'fieldblock',
          'delta' => 'bf40687156268eaa30437ed84189f13e',
          'region' => 'content_top_left',
          'weight' => 0,
        ),
        'fieldblock-fda604d130a57f15015895c8268f20d2' => array(
          'module' => 'fieldblock',
          'delta' => 'fda604d130a57f15015895c8268f20d2',
          'region' => 'content_top_left',
          'weight' => 0,
        ),
        'fieldblock-38205d43426b33bd0fe595ff8ca61ffd' => array(
          'module' => 'fieldblock',
          'delta' => '38205d43426b33bd0fe595ff8ca61ffd',
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
}
