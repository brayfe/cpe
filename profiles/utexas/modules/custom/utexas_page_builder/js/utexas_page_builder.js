/**
 * @file
 * Utexas_page_builder.js file.
 */

(function ($) {
  // Context editor tab handling.
  Drupal.behaviors.utexasPageBuilderContextEditor = {
    attach: function() {
      // Bind a click event for the context view, if we're not on an admin page.
      $('.tabs a[href$="/layout-editor"]').bind('click', function(e) {
        e.preventDefault();

        // Pop open the context editor.
        $('#context-inline-editor').removeClass('element-invisible').dialog({
          title: Drupal.t('Layout Editor'),
          position: ['left','top'],
          buttons: {
            'Save': function() {
              $('#context-inline-editor a.done:visible').click();
              $('.context-inline-editor-save').click();
            },
            'Cancel': function() {
              $('.context-inline-editor-cancel').click();
            }
          }
        }).parent().css({position:'fixed'});
      });
    }
  };

  // Admin selector.
  Drupal.behaviors.utexasPageBuilderAdminTemplate = {
    attach: function() {
      // Get the current value.
      var defaultTID = $('input[name="field_template"]').val();

      // Select the current one, if nothing's been selected.
      if ($('.template-option.selected').length == 0) {
        $('.template-option[data-tid="' + defaultTID + '"]').addClass('selected');
      }

      // Bind a click event to the template options.
      $('.template-option').bind('click', function(e) {
        e.preventDefault();

        if (!($(this).hasClass('selected'))) {
          // Figure out which one was selected.
          var newTID = $(this).data('tid');
          $('input[name="field_template"]').val(newTID).change();

          // Swap the selected classes.
          $('.template-option').removeClass('selected');
          $(this).addClass('selected');
        }
      });

      // Prevent access to helper text links.
      $('a.field-description-help-text').bind('click', function(e) {
        e.preventDefault();
      });

      // Handle the slide down of the field expander.
      $('.field-expander').bind('click', function(e) {
        e.preventDefault();
        e.stopImmediatePropagation();

        // Figure out which one this was.
        var $this = $(this);
        var $parent = $this.parents('.template-option');

        // Perform the animation.
        if ($this.hasClass('expanded')) {
          // Collapse the field list.
          $this.removeClass('expanded');
          $parent.find('.template-field-list').slideUp(400, function() {
            $(this).addClass('collapsed');
          });
        }
        else {
          // Expand the field list.
          $this.addClass('expanded');
          $parent.find('.template-field-list').slideDown(400, function() {
            $(this).removeClass('collapsed');
          });
        }
      });

      // Handle additional settings click.
      $('.template-option .none a').bind('click', function(e) {
        // Stop propagating to the template option.
        e.stopImmediatePropagation();
      });
    }
  };

  /**
   * Theme function for a vertical tab.
   *
   * Overriding the default to append an attribute for the tabs used elsewhere.
   *
   * @param settings
   *   An object with the following keys:
   *   - title: The name of the tab.
   *
   * @return
   *   This function has to return an object with at least these keys:
   *   - item: The root tab jQuery element
   *   - link: The anchor tag that acts as the clickable area of the tab
   *       (jQuery version)
   *   - summary: The jQuery element that contains the tab summary
   */
  Drupal.theme.prototype.utexasPageBuilderVerticalTab = function (settings) {
    var id = settings.fieldset.attr('id').replace('edit-', '').replace('sub-', '');
    var tab = {};
    tab.item = $('<li class="vertical-tab-button" tabindex="-1"></li>')
      .append(tab.link = $('<a href="#" data-tab="' + id + '"></a>')
        .append(tab.title = $('<strong></strong>').text(settings.title))
        .append(tab.summary = $('<span class="summary"></span>')
      )
    );
    return tab;
  };

})(jQuery);
