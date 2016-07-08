<?php
/**
 * @file
 * Definition of utexas_events_handler_operations.
 */

/**
 * Provides a custom views field.
 */
class utexas_events_handler_operations extends views_handler_field {
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
    $edit = l(t('Edit'), UTEXAS_EVENT_CALLBACK . '/manage/' . $values->id);
    $clone = l(t('Clone'), UTEXAS_EVENT_CALLBACK . '/manage/' . $values->id . '/clone');
    $delete = l(t('Delete'), UTEXAS_EVENT_CALLBACK . '/manage/' . $values->id . '/delete');

    $output = $edit . ' | ' . $clone . ' | ' . $delete;
    return $output;
  }
}
