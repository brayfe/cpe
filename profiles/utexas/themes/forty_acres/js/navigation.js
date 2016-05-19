(function($){

	'use strict';

	window.UT = window.UT || {};

	UT.Navigation = function(){
		
		/* Mobile Hamburger Menu */
		$('#menu-icon').on('click', this.toggleMobileNavigation);

		/* Mobile Navigation Content Overlay */
		$('#nav-overlay').on((Modernizr.touch ? 'touchstart' : 'click'), this.toggleMobileNavigation);

		/* Mobile Sub Navigation */
		$('.nav .nav-link.has-child').on('click', this.showMobileSubNavigation);

		/* Desktop Sub Navigation */
		if ($('.container-nav nav:first').length > 0) {
			// Only launch container nav if we're on utexas theme
			$('.container-nav nav:first').accessibleMegaMenu();
		}

	};

	UT.Navigation.prototype = {

		toggleMobileNavigation: function (e){
			e.preventDefault();
			$('body').toggleClass('show-nav');
		},

		showMobileSubNavigation: function (e){
			e.preventDefault();
			var currElem = $(this);
			currElem.parent().siblings().removeClass('nav-active');
			currElem.parent().toggleClass('nav-active');
		}

	};

	/* Phase 2 Parent Link Hide/Show */
	$('#show-parents').click(function(e){
		e.preventDefault();
		$('#parents').toggle();
		$('.toggle').toggleClass('active');
		$(this).toggleClass('active');
	});


}(jQuery));