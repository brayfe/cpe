(function($){

	//kick off foundation except in < IE8
	try {
		 $(document).foundation({
		 	equalizer: {
		 		equalize_on_stack: true
		 	}
		 });
	} catch (e) {
	}


	window.UT = window.UT || {};

	//add main navigation controls
	var navigation = new UT.Navigation();

	// check if the columns have been set in the markup
	var layoutCols = window.UT && window.UT.layoutCols ? window.UT.layoutCols : 4;

	//layout subnavigation
	var layout = new UT.Layout({cols:layoutCols});

	//Placeholders for IE
	$('input').placeholder();

}(jQuery));
