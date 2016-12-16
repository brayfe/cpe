/**
 * @file
 * Handles clicking of social share icon
 */

(function ($) {
  Drupal.behaviors.utexasNewsShareSocialShare = {
    attach: function (context, settings) {
      // Handle the clicking of a social share icon
      $('.fbShare').on('click', function(e) {
        e.preventDefault();
        var url = $(this).data("href");

        // Perform the share
        FB.ui({
          method: 'share',
          href: url
        }, function(response){
        });
      });
    }
  };
})(jQuery);
