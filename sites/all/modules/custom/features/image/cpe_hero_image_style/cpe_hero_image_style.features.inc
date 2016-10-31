<?php
/**
 * @file
 * cpe_hero_image_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cpe_hero_image_style_image_default_styles() {
  $styles = array();

  // Exported image style: cpe_hero_bg_image.
  $styles['cpe_hero_bg_image'] = array(
    'label' => 'CPE Hero BG IMage',
    'effects' => array(
      4 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 400,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
