(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.utexasCustomBehavior = {
  attach: function(context, settings) {

  	//  enter custom javascript here
    function repositionTranslateWidget(){
      if ($( window ).width() > desktop_screen_size){
        translateWidget.appendTo(desktopTranslateWidgetContainer);
      }
      if ($( window ).width() < desktop_screen_size){
        translateWidget.appendTo(mobileTranslateWidgetContainer);
      }
    }
      //  enter custom javascript here
      var desktop_screen_size = 1025;
      var translateWidget = $("#classes_cart");
      var desktopTranslateWidgetContainer = $(".cart-toggle-large");
      var mobileTranslateWidgetContainer = $(".cart-toggle-small");
      $(document).ready(function(){
      repositionTranslateWidget();

      })
    var margin;
    var currentWidth;
      $( window ).resize(function() {
      repositionTranslateWidget();
        // console.log($(window).width());
      });






  }
};

})(jQuery, Drupal, this, this.document);
