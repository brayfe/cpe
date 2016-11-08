(function($){
  Drupal.behaviors.modulename = {
    attach: function (context, settings) {

      $('input#add-to-cart').on('click', function() {
        var classId = $(this).data('class-id');
        setCookie('class', classId);
        $('form#section-form').submit();
      });

      var cookieVal = getCookie('class');
      var numOfClasses = 0;
      if (cookieVal != null) {
        var numOfClasses = cookieVal.length / Drupal.settings.cpe_cart.cpeCartClassIdLength;
      }

      if (numOfClasses == 1) {
        $('#classes_cart').append(" " + numOfClasses + " Item");
      }
      else
      {
        $('#classes_cart').append(" " + numOfClasses + " Items");
      }

      if (numOfClasses > 0) {

        $('#classes_cart').append('<br /><form action="' + Drupal.settings.cpe_cart.cpeCartCheckoutUrl + '" method="get"><input type="submit" value="Check Out >" /></form>');

        $('#classes_cart').append('<input id="empty_cart" type="button" value="Empty Cart"  />');
          
          $('#empty_cart').on('click',function() {
            setCookie('class', '');
            location.reload();
          });
      }
    }
  }
}(jQuery));

