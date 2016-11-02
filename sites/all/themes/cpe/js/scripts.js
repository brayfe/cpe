(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.utexasCustomBehavior = {
  attach: function(context, settings) {

  	//  enter custom javascript here
  	var myVal = $(".field-mishell").val();
  	alert(myVal);
  	//alert(myVal);
  	//$('input.cookie-value').setAttribute('data-value','myVal');

  }
};

})(jQuery, Drupal, this, this.document);