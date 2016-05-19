<?php
/**
 * @file
 * Flex Content Area A fieldblock for the sidebar.
 *
 * Available variables:
 *  - $block: The block object itself.
 *  - $block_html_id: ID of this block.
 *  - $classes: Classes for this block.
 *  - $attributes: Extra attributes for this block.
 *  - $content_attributes: Extra attributes for the content of this block.
 *  - $content: Content of this block.
 *  - $field_items: The field values of the field.
 *  - $editable: Whether or not the block is editable by the Layout Editor.
 *
 * @see template_preprocess_block().
 *
 * @ingroup themeable.
 */
?>
<?php if (isset($block->edit_links)): ?>
  <div class="edit-links">
    <?php print $block->edit_links; ?>
  </div>
<?php endif; ?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> <?php print 'fieldblock_' . $elements['#field_name']; ?>"<?php print $attributes; ?>>
  <div class="field_utexas_flex_content_area_a">
    <?php foreach ($field_items as $item): ?>
      <?php print render($item); ?>
    <?php endforeach; ?>
  </div>
  <?php if ($editable): ?>
    <?php print $editable; ?>
  <?php endif; ?>
</div>
