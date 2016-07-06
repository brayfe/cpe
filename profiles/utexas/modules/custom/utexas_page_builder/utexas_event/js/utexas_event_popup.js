(function ($) {
  Drupal.behaviors.utexasEventDatePopup = {
    attach: function (context, settings) {
      $('#edit-start-date-datepicker-popup-0').one('focus', function() {
        $('#edit-start-date-datepicker-popup-0').datepicker('option', {
          onClose: function(selected) {
            // Gray out items in the end date that are before the start date.
            $('#edit-end-date-datepicker-popup-0').one('focus', function() {
              $('#edit-end-date-datepicker-popup-0').datepicker('option', 'minDate', selected);
            });
            $('#edit-end-date-datepicker-popup-0').datepicker('option', 'minDate', selected);
          }
        });
      });
    }
  };
}(jQuery));
