<?php
/**
 * @file
 * Main template file for subtheme of forty_acres theme.
 */


function social_links_custom_field_widget_utexas_social_links_form_alter(&$element, &$form_state, $context) {
  $links = unserialize($element['#entity']->field_utexas_social_links['und'][0]['links']);
  // The "pinterest-square" element is used to refer to the UTexas font class "icon-pinterest-square".
  $element['links']['vimeo-square'] = array(
    '#type' => 'textfield',
    '#title' => t('Pinterest'),
    '#size' => 60,
    '#maxlength' => 255,
    '#default_value' => (isset($links['pinterest-square'])) ? $links['pinterest-square'] : '',
    '#attributes' => array(
      'placeholder' => 'http://pinterest.com/[account_handle]',
    ),
  );
}