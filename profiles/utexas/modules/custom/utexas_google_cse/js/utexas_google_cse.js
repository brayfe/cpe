/**
 * @file
 * Here we have the default Google CSE snippet and we will pass our google CSE ID here as a setting.
 */

(function ($) {

  Drupal.behaviors.googleCSE = {
    attach: function (context, settings) {
      // Getting setting variable.
      var cseID = settings.cseId;
      // cseID has the google cse id needed for the site search to work.
      var cx = cseID;
      var gcse = document.createElement('script');
      gcse.type = 'text/javascript';
      gcse.async = true;
      gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
          '//cse.google.com/cse.js?cx=' + cx;
      var s = document.getElementsByTagName('script')[0];
      s.parentNode.insertBefore(gcse, s);

    }
  };

})(jQuery);
