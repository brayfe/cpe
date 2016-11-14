/**
 * @file
 * Attaches the behaviors for the CPE cart checkout.
 */

 (function ($) {
  Drupal.behaviors.modulename = {
    attach: function (context, settings) {

      // Attach a click behavior to the "add to cart" button.
      $('input#add-to-cart').on('click', function () {
        var mishellId = $(this).data('mishell-id');
        setCookie('class', mishellId);
        $('form#section-form').submit();
      });

      // Hide the "Add to Cart" button if MISHELL returns a response for
      // the seat check that isn't a number greater than zero. If the response
      // is between 1-4, show the number of seats remaining as a sepaarate
      // field on the section.
      $('#block-views-cpe-sections-block div.node-cpe-section').each(function () {
        if ($('input#add-to-cart', this).length) {
          var $addToCartButton = $('input#add-to-cart', this);
          var courseId = $addToCartButton.data('course-id');
          var $emailCoordinatorButton = $('button#email-coord', this);
          $('div.field_section_course_id', this).before('<div class="field field_seats_remaining"><div class="field-label">Seats Remaining: </div><div class="field-items"></div></div></div>');
          var $seatsRemainingField = $('div.field_seats_remaining', this);
          $seatsRemainingField.hide();
          $.get(Drupal.settings.cpe_cart.cpeCartSeatCheckUrl + courseId, function (data) {
            var seatsAvailable = parseInt(data);
            $seatsRemainingField.children('.field-items').text(seatsAvailable);
            if (seatsAvailable > 0) {
              // Hide the "Contact Coodinator" button if there are seats available.
              $emailCoordinatorButton.hide();
              if (seatsAvailable < 5) {
                // Show the "Seats Remaining" field if there are 1-4 seats available.
                $seatsRemainingField.show();
              }
            }
            else {
              // Hide the "Add to Cart" button if there are no seats available.
              $addToCartButton.hide();
            }
          });
        }
      });

      // Parse the "class" cookie and divide the contents by the length of the
      // classId as determined by the cpe_cart_class_id_length $conf variable.
      var cookieVal = getCookie('class');
      var numOfClasses = 0;
      if (cookieVal != null) {
        var numOfClasses = cookieVal.length / Drupal.settings.cpe_cart.cpeCartClassIdLength;
      }

      // Change the text of the number of classes in the cart based on singular or plural.
      if (numOfClasses == 1) {
        $('#classes_cart').append(" " + numOfClasses + " Item");
      }
      else {
        $('#classes_cart').append(" " + numOfClasses + " Items");
      }

      // If there are classes in the cart, change the available actions.
      if (numOfClasses > 0) {
        $('#classes_cart').append('<br /><form action="' + Drupal.settings.cpe_cart.cpeCartCheckoutUrl + '" method="get"><input type="submit" value="Check Out >" /></form>');

        $('#classes_cart').append('<input id="empty_cart" type="button" value="Empty Cart"  />');

        // Add the click behavior for the "empty cart" button to reset the
        // "class" cookie and reload the page.
        $('#empty_cart').on('click', function () {
          setCookie('class', '');
          location.reload();
        });
      }
    }
  }
}(jQuery));
