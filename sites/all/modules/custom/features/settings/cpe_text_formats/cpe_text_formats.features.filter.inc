<?php
/**
 * @file
 * cpe_text_formats.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function cpe_text_formats_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_html' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '<a> <abbr> <address> <article> <aside> <blockquote> <br> <button> <caption> <cite> <code> <del> <details> <dl> <dt> <dd> <div> <em> <figure> <figcaption> <img> <i> <input> <hr> <h1> <h2> <h3> <h4> <h5> <h6> <ul> <ol> <li> <mark> <nav> <p> <pre> <script> <sub> <sup> <table> <th> <tr> <td> <thead> <tbody> <tfoot> <section> <span> <source> <strong> <time> <track> <video>',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'ckeditor_link_filter' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
      'qualtrics_filter' => array(
        'weight' => 3,
        'status' => 1,
        'settings' => array(
          'qualtrics_filter_height' => 500,
          'qualtrics_filter_title' => 'Qualtrics form',
        ),
      ),
      'video_filter' => array(
        'weight' => 4,
        'status' => 1,
        'settings' => array(
          'video_filter_width' => 400,
          'video_filter_height' => 400,
          'video_filter_autoplay' => 0,
          'video_filter_related' => 0,
          'video_filter_html5' => 1,
          'video_filter_codecs' => array(
            'whatchado' => 'whatchado',
            'archive' => 0,
            'bliptv' => 0,
            'candidcareer' => 0,
            'capped' => 0,
            'collegehumor' => 0,
            'coub' => 0,
            'dailymotion' => 0,
            'democracynow_fullshow' => 0,
            'democracynow_story' => 0,
            'flickr_slideshows' => 0,
            'flickr_video' => 0,
            'foxnews' => 0,
            'gametrailers' => 0,
            'gamevideos' => 0,
            'giphy' => 0,
            'godtube' => 0,
            'google' => 0,
            'instagram' => 0,
            'metacafe' => 0,
            'mailru' => 0,
            'myspace' => 0,
            'myvideo' => 0,
            'picasa_slideshows' => 0,
            'rutube' => 0,
            'slideshare' => 0,
            'streamhoster' => 0,
            'teachertube' => 0,
            'ted' => 0,
            'twitch' => 0,
            'ustream' => 0,
            'vbox' => 0,
            'vimeo' => 0,
            'vine' => 0,
            'wistia' => 0,
            'youku' => 0,
            'youtube' => 0,
            'youtube_playlist' => 0,
          ),
          'video_filter_multiple_sources' => 1,
        ),
      ),
      'filter_url' => array(
        'weight' => 5,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'tablesaw' => array(
        'weight' => 6,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 7,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => 9,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
