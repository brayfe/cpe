/**
 * @file
 * Plugin for Facebook Connect API
 */

(function ($) {
  Drupal.behaviors.utexasSocialShareFacebookInit = {
    attach: function (context, settings) {
      window.fbAsyncInit = function () {
        FB.init({
          // Pass in App ID from value set via utexas_news_share config form.
          appId: Drupal.settings.utexas_social_sharing.facebook_app_id,
          xfbml: true,
          version: 'v2.0'
        });
      };

      (function (d, s, id) {
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) {
          return;
        }
        js = d.createElement(s);
        js.id = id;
        js.src = "//connect.facebook.net/en_US/sdk.js";
        fjs.parentNode.insertBefore(js, fjs);
      }(document, 'script', 'facebook-jssdk'));
    }
  };
})(jQuery, document, 'script', 'facebook-jssdk');
