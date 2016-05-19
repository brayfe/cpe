(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.utexasGeneralBehavior = {
  attach: function(context, settings) {

    // Add flex-video class to youtube iframes
    $('iframe.media-youtube-player').wrap('<div class="flex-video"></div>');

    // Add class to fix header on scroll event on screens < 627px
    var window_width;
    $(window).on('resize load', function(e){
      window_width = $(window).width();
    });
    var header_region = $('.container-logo-p2');
    function headerScroll() {
      var scroll = $(window).scrollTop();
        if ((window_width < 627) && (scroll > 32)) {
          header_region.css('transform','translate3d(0px,0px,0px)');
          header_region.addClass('fix-header');
        } else {
          header_region.css('transform','translate3d(0px,0px,0px)');
          header_region.removeClass('fix-header');
        }
    }
    $(window).scroll(headerScroll);
  }
};

})(jQuery, Drupal, this, this.document);
