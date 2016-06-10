<?php
/**
 * @file
 * Template for the Context UI block browser.
 *
 * Available variables:
 *  - $blocks: An array of blocks to use in the Context UI editor.
 *  - $categories: Categories of blocks that can be used in the Context UI.
 *  - $filter_label: The label to use for filters.
 *  - $help_text: A helper text to describe how to use this functionality.
 *
 * @see utexas_preprocess_content_block_browser().
 * @see theme_context_block_browser_item().
 *
 * @ingroup themeable.
 */
?>
<div class="context-block-browser clearfix">
  <div class="blocks">
    <?php foreach ($blocks as $module => $module_blocks): ?>
      <?php if (!empty($module_blocks)): ?>
        <div class="category category-<?php print $module ?> clearfix">
        <div class="category-label"><?php print $available_modules[$module]; ?></div>
        <?php foreach ($module_blocks as $block): ?>
          <?php print theme('context_block_browser_item', array('block' => $block)); ?>
        <?php endforeach; ?>
        </div>
      <?php endif; ?>
    <?php endforeach; ?>
  </div>
  <div class="block-browser-sidebar">
    <div class="categories"><?php print render($categories); ?></div>
    <div class="filter"><?php print render($filter_label); ?></div>
    <?php print render($help_text); ?>
  </div>
</div>
