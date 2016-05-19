<?php
/**
 * @file
 * Template option template.
 *
 * Available variables:
 *  - $selected: a class representing if this template option has been selected.
 *  - $term: the taxonomy term of the template.
 *    - $term['tid']: TID of the taxonomy term.
 *  - $name: the name of the template option.
 *  - $image: the template icon image.
 *  - $description: a description of the template.
 *  - $fields: an array of fields available on the template.
 *    - $field['enabled']: a boolean indicating if the field is enabled
 *    - $field['label']: the name of the field.
 *    - $field['description']: the description of the field.
 *
 * @see template_preprocess_utexas_page_builder_template_option
 *
 * @ingroup themeable
 */
?>
<div id="<?php print $machine_name; ?>" class="template-option<?php print $selected; ?>" data-tid="<?php print $term; ?>">
  <h2 class="template-name"><?php print $name; ?></h2>
  <div class="meta-top">
    <div class="image">
      <?php print $image; ?>
    </div>
    <div class="template-description">
      <?php print $description; ?>
    </div>
  </div>
  <div class="meta-bottom">
      <div class="template-fields">
        <?php if (!empty($fields)): ?>
          <h3><a href="#" class="field-expander">Available Fields</a></h3>
          <ul class="template-field-list collapsed">
            <?php foreach ($fields as $field_name => $field): ?>
              <?php if ($field['enabled']): ?>
                <li>
                  <span class="field-label"><?php print $field['label']; ?></span>
                  <?php if (!empty($field['description'])): ?>
                    <span class="field-help">[<a href="#" class="field-description-help-text" title="<?php print $field['description']; ?>">?</a>]</span>
                  <?php endif; ?>
                </li>
              <?php endif; ?>
            <?php endforeach; ?>
          </ul>
      <?php else: ?>
         <p class="none">
          No available fields for this template.
          <?php if (user_access('manage template additional settings')): ?>
            <?php print l(t('Manage available fields.'), 'taxonomy/term/' . $term['tid'] . '/additional-settings', array('attributes' => array('target' => '_blank'))); ?>
          <?php endif; ?>
        </p>
      <?php endif; ?>
    </div>
  </div>
</div>
