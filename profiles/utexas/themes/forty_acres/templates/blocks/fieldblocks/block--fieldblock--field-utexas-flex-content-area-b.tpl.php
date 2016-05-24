<?php
/**
 * @file
 * Flex Content Area B fieldblock.
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

// Do a grouping of field items to create two-up rows.
$groups = array();
for ($i = 0; $i < count($field_items); $i += 2) :
  $tmp = array();
  if (isset($field_items[$i])) :
    $tmp[] = $field_items[$i];
  endif;
  if (isset($field_items[$i + 1])) :
    $tmp[] = $field_items[$i + 1];
  endif;
  $groups[] = $tmp;
endfor;

if (isset($block->edit_links)) : ?>
  <div class="edit-links">
    <?php print $block->edit_links; ?>
  </div>
<?php endif; ?>
<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> <?php print 'fieldblock_' . $elements['#field_name']; ?>"<?php print $attributes; ?>>
  <div class="field_utexas_flex_content_area_b">
    <div class="content row"<?php print $content_attributes; ?>>
      <?php foreach ($groups as $group): ?>
        <hr class="utexas_flex_content_hr">
        <div class="two-up clearfix">
          <?php foreach ($group as $item): ?>
            <div class="column medium-6">
              <?php print render($item); ?>
            </div>
          <?php endforeach; ?>
        </div>
      <?php endforeach; ?>
    </div>
  </div>
  <?php if ($editable): ?>
    <?php print $editable; ?>
  <?php endif; ?>
</div>
