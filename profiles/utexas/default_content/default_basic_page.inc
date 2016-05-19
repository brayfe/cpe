<?php

/**
 * @file
 * Default basic page content.
 *
 * Used if Page Builder is not enabled.
 */

$pages = array();

$pages[] = array(
  'uid' => 1,
  'title' => 'Welcome to Your New Site!',
  'log' => '',
  'status' => 1,
  'comment' => 0,
  'promote' => 0,
  'sticky' => 0,
  'vuuid' => '3acbfec1-fbd3-4556-9ae5-f70f4f2ea9ab',
  'type' => 'page',
  'language' => 'und',
  'created' => 1438963631,
  'tnid' => 0,
  'translate' => 0,
  'uuid' => 'ced7d381-be2b-448d-bceb-e8cf6dfbd7f7',
  'revision_uid' => 1,
  'body' => array(
    'und' => array(
      0 => array(
        'value' => '<p>Phasellus scelerisque gravida leo, vel blandit lacus rutrum in. Donec nisi orci, semper in nulla et, rutrum consequat ante. Maecenas efficitur neque ut lectus maximus, nec luctus nunc venenatis. Donec sit amet maximus mauris. Vivamus tempor ligula odio, eget auctor mauris facilisis consectetur. Pellentesque vestibulum ornare cursus. Donec sit amet efficitur libero, volutpat semper metus. Aenean varius tortor vitae tempus scelerisque. In pulvinar mi vel pulvinar ornare. Nam mollis, mi in ornare dapibus, nulla ligula laoreet nisl, quis malesuada nibh nibh quis est. Quisque lobortis elit id rutrum commodo.</p><p>Nulla et mollis dolor, sed dapibus diam. Pellentesque vel purus lorem. Integer malesuada pretium euismod. Ut orci purus, scelerisque ut nisi ut, egestas facilisis eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Quisque ex nisi, imperdiet a pretium ut, ullamcorper in risus. Quisque dictum, est eget ullamcorper sodales, libero nulla pellentesque justo, ac mollis sem tellus ac ante. Integer aliquet, urna eu tincidunt dignissim, mi purus lacinia eros, sed suscipit purus ipsum et felis. Phasellus sagittis posuere massa vel condimentum. Suspendisse nibh ipsum, suscipit a pellentesque ut, mattis sed lacus. Pellentesque interdum porttitor tellus at lacinia. Integer elementum orci eget ante maximus eleifend. Nulla facilisi. Quisque at pellentesque orci.</p>',
        'summary' => '',
        'format' => 'filtered_html',
        'safe_value' => '<p>Phasellus scelerisque gravida leo, vel blandit lacus rutrum in. Donec nisi orci, semper in nulla et, rutrum consequat ante. Maecenas efficitur neque ut lectus maximus, nec luctus nunc venenatis. Donec sit amet maximus mauris. Vivamus tempor ligula odio, eget auctor mauris facilisis consectetur. Pellentesque vestibulum ornare cursus. Donec sit amet efficitur libero, volutpat semper metus. Aenean varius tortor vitae tempus scelerisque. In pulvinar mi vel pulvinar ornare. Nam mollis, mi in ornare dapibus, nulla ligula laoreet nisl, quis malesuada nibh nibh quis est. Quisque lobortis elit id rutrum commodo.</p><p>Nulla et mollis dolor, sed dapibus diam. Pellentesque vel purus lorem. Integer malesuada pretium euismod. Ut orci purus, scelerisque ut nisi ut, egestas facilisis eros. Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas. Quisque ex nisi, imperdiet a pretium ut, ullamcorper in risus. Quisque dictum, est eget ullamcorper sodales, libero nulla pellentesque justo, ac mollis sem tellus ac ante. Integer aliquet, urna eu tincidunt dignissim, mi purus lacinia eros, sed suscipit purus ipsum et felis. Phasellus sagittis posuere massa vel condimentum. Suspendisse nibh ipsum, suscipit a pellentesque ut, mattis sed lacus. Pellentesque interdum porttitor tellus at lacinia. Integer elementum orci eget ante maximus eleifend. Nulla facilisi. Quisque at pellentesque orci.</p>',
        'safe_summary' => '',
      ),
    ),
  ),
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
  'date' => '2015-08-07 18:07:11 +0200',
);

foreach ($pages as $page) {
  $node = new stdClass();
  $node->title = $page['title'];
  $node->type = $page['type'];
  node_object_prepare($node);
  $node->language = LANGUAGE_NONE;
  $node->status = 1;
  $node->promote = 0;
  $node->comment = 0;
  $node->body = $page['body'];
  // Add default user and creation date.
  $node = node_submit($node);
  node_save($node);
}
