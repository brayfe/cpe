<?php
/**
 * @file
 * Field collection template for Contact Info.
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
 * @ingroup themeable.
 */
?>
<div class="address">
  <?php if (isset($values['field_location_name']) and !empty($values['field_location_name'])): ?>
    <div class="label"><?php print render($values['field_location_name']); ?></div>
  <?php endif; ?>
  <?php if (isset($values['field_address_content']) and !empty($values['field_address_content'])): ?>
    <?php print render($values['field_address_content']); ?>
  <?php endif; ?>
</div>
