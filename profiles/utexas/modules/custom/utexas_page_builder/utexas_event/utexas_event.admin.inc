<?php

/**
 * @file
 * Admin include file for admin settings form.
 */

/**
 * Basic configuration form.
 *
 * Shows the first page of UTexas Events configuration.
 *
 * @return array
 *   All form elements.
 */
function utexas_event_configuration() {
  $events_url = variable_get('utexas_events_url', 'events');
  if ($events_url != '') {
    $events_url = drupal_get_path_alias($events_url);
  }
  $form['utexas_events_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Path to Events listing',
    '#description' => 'Defines what page the breadcrumb "Events" link should point to. If the URL of this page is "yoursite.utexas.edu/events," simply type "events" here. ',
    '#maxlength' => 255,
    '#default_value' => $events_url,
    '#element_validate' => array('utexas_event_configuration_valid_url'),
  );
  $elements = array(
    'upcoming' => "Upcoming Events",
    'featured' => "Featured Events",
  );
  // Generate integer options for Number of Events.
  $options = array();
  $inc = 1;
  while ($inc <= 10) {
    $options[$inc] = $inc;
    $inc++;
  }
  // Generate form options from $elements array.
  foreach ($elements as $key => $value) {
    $title = 'utexas_events_' . $key . '_block_title';
    $count = 'utexas_events_' . $key . '_block_count';
    $form[$key] = array(
      '#type' => 'fieldset',
      '#title' => $value,
      '#collapsible' => FALSE,
    );
    $form[$key][$title] = array(
      '#type' => 'textfield',
      '#title' => t('Block title'),
      '#default_value' => variable_get($title, $value),
      '#description' => t('The text that will be displayed above the') . ' ' .  $value . ' ' .  t('listings.'),
      '#element_validate' => array('utexas_event_configuration_valid_text'),
    );
    $form[$key][$count] = array(
      '#type' => 'select',
      '#title' => t('Number of Events'),
      '#default_value' => variable_get($count, 5),
      '#options' => $options,
      '#description' => t('The number of events displayed in the') . ' ' .  $value . ' ' .  t('listings.'),
    );
  }
  $form['#submit'][] = 'utexas_event_configuration_submit';
  return system_settings_form($form);
}

/**
 * Custom text validation.
 */
function utexas_event_configuration_valid_text($element, &$form_state, $form) {
  $input = $element['#value'];
  if ($input && (strcmp($input, strip_tags($input)))) {
    form_error($element, t('The title may only use plain text.'));
  }
}

/**
 * Custom text validation.
 */
function utexas_event_configuration_valid_url($element, &$form_state, $form) {
  $input = $element['#value'];
  $target = drupal_get_normal_path($input);
  if (($input != '') and !drupal_valid_path($target)) {
    form_error($element, t('The path to the Events listing is not valid. Does the path provided exist in the system?'));
  }
}

/**
 * Additional handler for utexas_event_configuration submission.
 */
function utexas_event_configuration_submit($form, &$form_state) {
  // Save the URL as a Drupal internal path, in case users update the alias.
  if ($form['utexas_events_url']['#value'] != '') {
    form_set_value($form['utexas_events_url'], drupal_get_normal_path($form['utexas_events_url']['#value']), $form_state);
  }
}
