/**
 * @file
 * Attaches the behaviors for the CPE cart checkout.
 */

 (function ($) {
  Drupal.behaviors.modulename = {
    attach: function (context, settings) {

      // Attach a click behavior to the "add to cart" button.
      $('input#add-to-cart').on('click', function () {
        var mishellIdRaw = $(this).data('mishell-id');
        // If the MISHELL ID field is only 7 bytes, it should be padded to 8 bytes
        // with an underscore.
        if (mishellIdRaw.length == '7') {
          var mishellIdEightByte = mishellIdRaw + '_';
        }
        else if (mishellIdRaw.length == '8') {
          var mishellIdEightByte = mishellIdRaw;
        }
        else {
          console.error('MISHELL ID is not a valid 7 or 8 byte value');
          alert('An unknown error has occurred. Please contact the website administrators.');
          return false;
        }
        // Pad the 8-byte string with an additional 12 zeros, to match what
        // MISHELL expects to see in the "class" cookie for cart checkout.
        var mishellIdForCart = mishellIdEightByte + '000000000000';
        setCookie('class', mishellIdForCart);
        $('form#section-form').submit();
      });

      // "Seat availability check" functionality
      // This does an AJAX call to a wrapper script that connects to MISHELL
      // and queries the course_id for a section to see how many seats are
      // available.
      //
      // It also adds a "Seats remaining" pseudo-field to the section display
      // and hides it by default.
      //
      // If a section has 0 zero seats available or is not found, the "Add to Cart"
      // button is hidden in favor of the "Contact Coordinator" button.
      //
      // If a section has 1-4 available seats, the "Seats remaining" pseudo-field
      // is populated with the number of available seats, and the "Contact
      // Coordinator" button remains hidden.
      //
      // If a section has 5+ available seats, the "Seats remaining" pseudo-field
      // and the "Contact Coordinator" button both stay hiddden.
      $('#block-views-cpe-sections-block div.node-cpe-section').each(function () {
        if ($('input#add-to-cart', this).length) {
          var $addToCartButton = $('input#add-to-cart', this);
          var mishellId = $addToCartButton.data('mishell-id');
          var $emailCoordinatorButton = $('button.email-coord', this);
          $('div.field_section_course_id', this).before('<div class="field field_seats_remaining"><div class="field-label">Seats Remaining: </div><div class="field-items"></div></div></div>');
          var $seatsRemainingField = $('div.field_seats_remaining', this);
          $seatsRemainingField.hide();
          $.get(Drupal.settings.cpe_cart.cpeCartSeatCheckUrl + mishellId, function (data) {
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
        $('#classes_cart').append('<form action="' + Drupal.settings.cpe_cart.cpeCartCheckoutUrl + '" method="get"><input type="submit" value="Check Out" /></form>');

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
