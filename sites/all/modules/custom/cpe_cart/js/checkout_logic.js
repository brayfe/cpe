(function($){
  Drupal.behaviors.modulename = {
    attach: function (context, settings) {
              /*Code goes here, this is going to be like 
              $(document).ready() but will not be lost if
              Drupal reloads the page or something */

     //<![CDATA[
      var mycookie = document.cookie;

      function getCookie(name) {
        var index = mycookie.indexOf(name + '=');
        if (index == -1)
          return null;
          index = mycookie.indexOf("=", index) + 1;
          var endstr = mycookie.indexOf(';', index);
        if (endstr == -1)
          endstr = mycookie.length;
          return unescape(mycookie.substring(index, endstr));
      }

      var cookievalue = getCookie('class');
      var numofcookies = 0;
      if (cookievalue != null) {
        var numofcookies = cookievalue.length / 22;
      }

      if (numofcookies == 1) {
        $('#classes_cart').append(" " + numofcookies + " Item");
      }
      else
      {
        $('#classes_cart').append(" " + numofcookies + " Items");
      }

      if (numofcookies != 0) {

        $('#classes_cart').append('<br /><form action="' + Drupal.settings.cpe_cart.cpeCartCheckoutUrl + '" method="get"><input type="hidden" /><input type="submit" value="Check Out >" /></form>');

        $('#classes_cart').append('<input id="empty_cart" type="button" value="Empty Cart"  />');
        
        $('#empty_cart').on('click',function() {
          setCookie('class', '');
          location.reload();
        });

      }

      //]]>

    }
  }
}(jQuery));

