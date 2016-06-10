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

  //layout subnavigation
  var layout = new UT.Layout();

  // News social sharing options
  $('.social-share .connect-link.toggle-link').on('click', function(e) {
    // Prevent the default from firing & get a local context
    e.preventDefault();
    var $social = $(this).parents('.social-share');

    // Define an isMore variable for checking
    var isMore = $('.social-name.toggle-name', $social).hasClass('more');

    // Load the other links and swap text
    if (isMore) {
      $('.additional-links', $social).show();
      $('.social-name.toggle-name', $social).addClass('less').removeClass('more').text('Less');
    } else {
      $('.additional-links', $social).hide();
      $('.social-name.toggle-name', $social).addClass('more').removeClass('less').text('More');
    }
  });

  //Placeholders for IE
  $('input').placeholder();

}(jQuery));
