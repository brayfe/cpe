/**
 * @file
 * Utexas_templates.js file.
 */

(function ($) {
  // Generate machine names for templates.
  Drupal.behaviors.utexasTemplatesMachineNames = {
    attach: function() {
      var machineNameSettings = '[^a-z0-9]';
      var rx = new RegExp(machineNameSettings, 'g');
      $('#edit-name').bind('change keyup paste', (function () {
        var value = $(this).val();
        var templateName = value.toLowerCase().replace(rx, '-');
        templateName = templateName.replace('---', '-');
        templateName = templateName.replace('--', '-');
        $("#edit-template-filename").val('page--' + templateName + '.tpl.php');
        $("#edit-image-filename").val(templateName + '.svg');
      }));
    }
  };

})(jQuery);
