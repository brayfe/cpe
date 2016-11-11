(function ($) {
  Drupal.behaviors.modulename = {
    attach: function (context, settings) {

      $('input#add-to-cart').on('click', function () {
        var classId = $(this).data('class-id');
        setCookie('class', classId);
        $('form#section-form').submit();
      });

      // Hide the "Add to Cart" button if MISHELL returns a response for
      // the seat check that isn't a number greater than zero.
      $('div.node-cpe-section').each(function() {
        if ($('input#add-to-cart', this).length) {
          var $addToCartButton = $('input#add-to-cart', this);
          var $emailCoordinatorButton = $('input#email-coord', this);
          var classId = $addToCartButton.data('class-id');
          $.get(Drupal.settings.cpe_cart.cpeCartSeatCheckUrl + classId, function(data) {
            if (data > 0) {
              // Hide the "Contact Coodinator" button if there are seats available
              $emailCoordinatorButton.hide();
              if (data < 5) {
                // Add a pseudo "Seats Remaining" field if there are 1-4 seats available
                $('div.field_section_course_id').before('<div class="field field_seats_remaining"><div class="field-label">Seats Remaining: </div><div class="field-items">' + data + '</div></div></div>');
              }
            } else {
              // Hide the "Add to Cart" button if there are no seats available
              $addToCartButton.hide()
            }
          });
        }
      });

      var cookieVal = getCookie('class');
      var numOfClasses = 0;
      if (cookieVal != null) {
        var numOfClasses = cookieVal.length / Drupal.settings.cpe_cart.cpeCartClassIdLength;
      }

      if (numOfClasses == 1) {
        $('#classes_cart').append(" " + numOfClasses + " Item");
      }
      else {
        $('#classes_cart').append(" " + numOfClasses + " Items");
      }

      if (numOfClasses > 0) {
        $('#classes_cart').append('<br /><form action="' + Drupal.settings.cpe_cart.cpeCartCheckoutUrl + '" method="get"><input type="submit" value="Check Out >" /></form>');

        $('#classes_cart').append('<input id="empty_cart" type="button" value="Empty Cart"  />');

        $('#empty_cart').on('click', function () {
          setCookie('class', '');
          location.reload();
        });
      }
    }
  }
}(jQuery));
