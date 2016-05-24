<?php

/**
 * @file
 * Placeholder menu content.
 */

$placeholders = array(
  array(
    'link_title' => st('Lorem Ipsum'),
    'link_path' => 'node/1',
  ),
  array(
    'link_title' => st('Lorem Ipsum'),
    'link_path' => 'node/1',
  ),
  array(
    'link_title' => st('Lorem Ipsum'),
    'link_path' => 'node/1',
  ),
  array(
    'link_title' => st('Lorem Ipsum'),
    'link_path' => 'node/1',
  ),
);

$menu = array(
  array(
    'link_title' => st('Undergraduate Program'),
    'link_path' => 'node/1',
    '#children' => $placeholders,
  ),
  array(
    'link_title' => st('Graduate Program'),
    'link_path' => '<nolink>',
    '#children' => $placeholders,
  ),
  array(
    'link_title' => st('Course Directory'),
    'link_path' => 'node/1',
    '#children' => array(),
  ),
  array(
    'link_title' => st('News'),
    'link_path' => 'node/1',
    '#children' => $placeholders,
  ),
  array(
    'link_title' => st('Events'),
    'link_path' => 'node/1',
    '#children' => $placeholders,
  ),
  array(
    'link_title' => st('About'),
    'link_path' => 'http://example.com',
    '#children' => array(
      array(
        'link_title' => st('L2 item 1'),
        'link_path' => 'http://example.com',
      ),
      array(
        'link_title' => st('L2 item 2'),
        'link_path' => 'http://example.com',
        '#children' => array(
          array(
            'link_title' => st('L3 item 1'),
            'link_path' => 'http://example.com',
          ),
          array(
            'link_title' => st('L3 item 2'),
            'link_path' => 'node/1',
          ),
          array(
            'link_title' => st('L3 item 3'),
            'link_path' => 'http://example.com',
          ),
          array(
            'link_title' => st('L4 item 4'),
            'link_path' => 'http://example.com',
          ),
        ),
      ),
      array(
        'link_title' => st('L2 item 3'),
        'link_path' => 'node/1',
      ),
      array(
        'link_title' => st('L2 item 4'),
        'link_path' => 'node/1',

      ),
    ),
  ),
);

menu_delete_links('main-menu');
utexas_menu_builder($menu, 'main-menu');
