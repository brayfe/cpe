<?php
/**
 * @file
 * Field collection template for Timely Announcements.
 *
 * Available variables:
 *  - $classes: A string of classes to add to the field collection item.
 *  - $attributes: A string representing attributes to add to this item.
 *  - $content_attributes: Content attributes for the item.
 *  - $content: The content itself.
 *  - $values: Rendered values of the fields.
 *
 * @see template_preprocess_field_collection_item().
 *
 * @todo As ITS revises how the Timely Announcements module works, this file
 *   may become obsolete or need to be re-worked.
 *
 * @ingroup themeable.
 */

// Get the link in an easier to use value.
$link = (isset($values['field_highlight_link'][0]))
 ? $values['field_highlight_link'][0]
 : FALSE;
?>
<div class="row">
  <div class="column medium-12">
    <div class="<?php print $classes; ?>">
      <div class="notice-wrapper">
        <h4><span class="icon-annoucement"></span> <?php print render($values['field_headline']); ?></h4>
        <div class="alert-text"><?php print render($values['field_copy']); ?></div>
        <?php if ($link): ?>
          <?php print l($link['#element']['title'], $link['#element']['url'], array('html' => TRUE, 'attributes' => array('class' => array('cta')))); ?>
        <?php endif; ?>
      </div>
    </div>
  </div>
</div>
