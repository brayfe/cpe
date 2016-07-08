<?php
/**
 * @file
 * Definition of utexas_events_handler_date_range.
 */

/**
 * Provides a custom views field.
 */
class utexas_events_handler_date_range extends views_handler_field {
  /**
   * Render a numeric value as a size.
   *
   * @ingroup views_field_handlers
   */
  public function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Default options form that provides label widget all fields should have.
   */
  public function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  /**
   * Called to add the field to a query.
   */
  public function query() {
    // Nothing needed here, just override default query.
  }

  /**
   * Render the field.
   *
   * @param object $values
   *   The values retrieved from the database.
   */
  public function render($values) {
    // Format date & time using utexas_brand_guidelines_date_format().

    $time_array = utexas_brand_guidelines_date_format(array('start' => $values->utexas_event_start, 'end' => $values->utexas_event_end), 'utexas_times');
    $times = $time_array['start'] . $time_array['end'];
    $dates_array = utexas_brand_guidelines_date_format(array('start' => $values->utexas_event_start, 'end' => $values->utexas_event_end), 'utexas_days');
    $dates = $dates_array['start'];
    if (isset($dates_array['end'])) {
      $dates .= ' - ' . $dates_array['end'];
    }
    $output = $dates . ', ' . $times;
    return $output;
  }
}
