<?php
/**
 * @file
 * cpe_rel_art_img.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function cpe_rel_art_img_image_default_styles() {
  $styles = array();

  // Exported image style: rel_art_img.
  $styles['rel_art_img'] = array(
    'label' => 'Related Artifacts Image',
    'effects' => array(
      1 => array(
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => 480,
          'height' => 480,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
