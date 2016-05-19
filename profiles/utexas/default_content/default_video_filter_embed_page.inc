<?php

/**
 * @file
 * Default Embed standard page.
 */

/**
 * Helper function to install a default page.
 */

  $pages[] = array(
    'uid' => 1,
    'title' => 'Video Filter Embedding Demo',
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
          'value' => '<p>"This page demonstrates how to embed videos within WYSIWYG fields. This first example is a form with the video filter default options, accomplished with the following shortcode:</p>
          <p>&nbsp;</p>
          <p>&#91;video:&#91;https&#93;&#47;&#47;youtube&#91;dot&#93;com/watch?v=UMQTQhdizxI &#93;</p>

<p">[video:https://www.youtube.com/watch?v=UMQTQhdizxI]</p>
  ',
          'format' => 'filtered_html',
          'safe_value' => '<p>"This page demonstrates how to embed videos within WYSIWYG fields. This first example is a form with the video filter default options, accomplished with the following shortcode:</p>
          <p>&nbsp;</p>
          <p>&#91;video:&#91;https&#93;&#47;&#47;youtube&#91;dot&#93;com/watch?v=UMQTQhdizxI &#93;</p>

<p>[video:https://www.youtube.com/watch?v=UMQTQhdizxI]</p>
  ',
        ),
      ),
    ),
    'field_wysiwyg_b' => array(
      'und' => array(
        0 => array(
          'value' => '<p>The below shortcode sets the width, height, align and autoplay attributes. It is also wrapped in a div with the "flex-video" class , that makes videos responsive:</p>
          <p>&nbsp;</p>
          <p>&lt;div class="flex-video"&gt;&#91;video:&#91;https&#93;&#47;&#47;vimeo&#91;dot&#93;com/65142723 width:300 height:300 align:center autoplay:0&#93;&lt;/div&gt;</p>

<div class="flex-video">[video:https://vimeo.com/65142723 width:300 height:300 align:center autoplay:0]</div>

<p>Videos can be embedded from the following services:</p>
<table>
	<tbody>
		<tr>
			<td><a rel="nofollow">Archive.org</a></td>
			<td><a href="http://www.flickr.com/" rel="nofollow" target="_blank">Flickr Slideshows</a></td>
			<td><a href="http://video.google.com/" rel="nofollow" target="_blank">Google Video</a></td>
			<td><a href="http://www.streamhoster.com/" rel="nofollow" target="_blank">Streamhoster</a></td>
		</tr>
		<tr>
			<td><a href="http://blip.tv/" rel="nofollow" target="_blank">Blip.tv</a></td>
			<td><a href="http://www.flickr.com/" rel="nofollow" target="_blank">Flickr Video</a></td>
			<td><a href="http://metacafe.com/" rel="nofollow" target="_blank">Metacafe</a></td>
			<td><a href="http://www.teachertube.com/" rel="nofollow" target="_blank">Teachertube</a></td>
		</tr>
		<tr>
			<td><a href="http://capped.tv/" rel="nofollow" target="_blank">Capped.tv</a></td>
			<td><a href="http://www.gametrailers.com/" rel="nofollow" target="_blank">Gametrailers</a></td>
			<td><a href="http://www.myspace.com/" rel="nofollow" target="_blank">Myspace</a></td>
			<td><a href="http://www.vimeo.com/" rel="nofollow" target="_blank">Vimeo</a></td>
		</tr>
		<tr>
			<td><a href="http://www.collegehumor.com/" rel="nofollow" target="_blank">College Humor</a></td>
			<td><a href="http://gamevideos.1up.com/" rel="nofollow" target="_blank">Gamevideos</a></td>
			<td><a href="http://picasaweb.google.com/" rel="nofollow" target="_blank">Picasa</a></td>
			<td><a href="http://www.wistia.com/" rel="nofollow" target="_blank">Wistia</a></td>
		</tr>
		<tr>
			<td><a href="http://www.dailymotion.com/" rel="nofollow" target="_blank">DailyMotion</a></td>
			<td><a href="http://www.godtube.com/" rel="nofollow" target="_blank">Godtube</a></td>
			<td><a href="http://www.slideshare.net/" rel="nofollow" target="_blank">Slideshare</a></td>
			<td><a href="http://www.youtube.com/" rel="nofollow" target="_blank">YouTube</a></td>
		</tr>
	</tbody>
</table>
  ',
          'format' => 'filtered_html',
          'safe_value' => '<p>The below shortcode sets the width, height, align and autoplay attributes. It is also wrapped in a div with the "flex-video" class , that makes videos responsive:</p>
          <p>&nbsp;</p>
          <p>&lt;div class="flex-video"&gt;&#91;video:&#91;https&#93;&#47;&#47;vimeo&#91;dot&#93;com/65142723 width:300 height:300 align:center autoplay:0&#93;&lt;/div&gt;</p>

<div class="flex-video">[video:https://vimeo.com/65142723 width:300 height:300 align:center autoplay:0]</div>

<p>Videos can be embedded from the following services:</p>
<table>
	<tbody>
		<tr>
			<td><a rel="nofollow">Archive.org</a></td>
			<td><a href="http://www.flickr.com/" rel="nofollow" target="_blank">Flickr Slideshows</a></td>
			<td><a href="http://video.google.com/" rel="nofollow" target="_blank">Google Video</a></td>
			<td><a href="http://www.streamhoster.com/" rel="nofollow" target="_blank">Streamhoster</a></td>
		</tr>
		<tr>
			<td><a href="http://blip.tv/" rel="nofollow" target="_blank">Blip.tv</a></td>
			<td><a href="http://www.flickr.com/" rel="nofollow" target="_blank">Flickr Video</a></td>
			<td><a href="http://metacafe.com/" rel="nofollow" target="_blank">Metacafe</a></td>
			<td><a href="http://www.teachertube.com/" rel="nofollow" target="_blank">Teachertube</a></td>
		</tr>
		<tr>
			<td><a href="http://capped.tv/" rel="nofollow" target="_blank">Capped.tv</a></td>
			<td><a href="http://www.gametrailers.com/" rel="nofollow" target="_blank">Gametrailers</a></td>
			<td><a href="http://www.myspace.com/" rel="nofollow" target="_blank">Myspace</a></td>
			<td><a href="http://www.vimeo.com/" rel="nofollow" target="_blank">Vimeo</a></td>
		</tr>
		<tr>
			<td><a href="http://www.collegehumor.com/" rel="nofollow" target="_blank">College Humor</a></td>
			<td><a href="http://gamevideos.1up.com/" rel="nofollow" target="_blank">Gamevideos</a></td>
			<td><a href="http://picasaweb.google.com/" rel="nofollow" target="_blank">Picasa</a></td>
			<td><a href="http://www.wistia.com/" rel="nofollow" target="_blank">Wistia</a></td>
		</tr>
		<tr>
			<td><a href="http://www.dailymotion.com/" rel="nofollow" target="_blank">DailyMotion</a></td>
			<td><a href="http://www.godtube.com/" rel="nofollow" target="_blank">Godtube</a></td>
			<td><a href="http://www.slideshare.net/" rel="nofollow" target="_blank">Slideshare</a></td>
			<td><a href="http://www.youtube.com/" rel="nofollow" target="_blank">YouTube</a></td>
		</tr>
	</tbody>
</table>
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

    $context = new stdClass();
    $context->disabled = FALSE;
    $context->api_version = 3;
    $context->name = 'context_field-node-' . $node->nid;
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
    $context->condition_mode = 0;

    context_save($context);
  }

