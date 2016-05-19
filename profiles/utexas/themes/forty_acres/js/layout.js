(function($){

	'use strict';

	window.UT = window.UT || {};

	UT.Layout = function(userSettings){
		
		$('#main-nav .sub-nav').each(function(i, el){

			var $el = $(el),
				$main = $('#main-nav'),
				children = $el.find('.sub-nav-item'),
				containerWidth,
				navWidth,
				columnWidth,
				maxColumns,
				numRows,
				numColumns,
				defaults = {
					cols: 4
				};

			var settings = $.extend({}, defaults, userSettings);


			var update = function(){

				//remove the old classes
				$el.removeClass('item-c-' + numColumns + ' item-r-' + numRows);

				//get the max row width
				containerWidth = $el.parent().width();

				//Still in Mobile View
				if(!containerWidth) { return; }

				//get the width of the nav
				navWidth = $el.width();

				//get the minimum possible width of a column
				columnWidth = Math.floor(containerWidth/settings.cols);

				//calculate how many columns fit in the nav width or use the # of children if less than that
				maxColumns = Math.min(Math.floor(navWidth/columnWidth), children.length);

				//divide the children into the columns evenly
				numRows = Math.ceil(children.length/maxColumns);

				//remove any empty columns
				numColumns = Math.ceil(children.length/numRows);

				//add the new container classes
				$el.addClass('item-c-' + numColumns + ' item-r-' + numRows);

				//layout the children
				for (var i = 0; i < numColumns; i++) {
					for (var j = 0; j < numRows; j++) {
						if(children.eq(i+j)){
							children.eq((i*numRows)+j).addClass('item-c-' + (i+1) + ' item-r-'+ (j+1));

							//add a special class to the bottom row children
							if(j+1==numRows){
								children.eq((i*numRows)+j).addClass('item-last');
							}
						}
					}
				}

				//flag the nav if its overflowing offthe screen
				if(navWidth + $el.offset().left >  $main.width() +  $main.offset().left){
					$el.closest('.sub-nav-wrapper').addClass('overflowing');
				}

				//Detech the resize event if layout has completed
				$(window).off('resize', update);

			};

			//Update on window resize
			$(window).resize(update);

			//Update on Page Load
			update();

		});

	};


}(jQuery));