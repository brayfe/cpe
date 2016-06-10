<?php
/**
 * @file
 * Compound field template for Social Links.
 *
 * Available variables:
 *  - $classes: A string of classes to add to the field collection item.
 *  - $attributes: A string representing attributes to add to this item.
 *  - $content_attributes: Content attributes for the item.
 *  - $headline: The defined headline
 *  - $links: an array of user-defined links, with social media name.
 *
 * @ingroup themeable.
 */
?>

<div class="row">
  <div class="column small-12 force-width <?php print $grid_class; ?>">
    <?php if (isset($photo)): ?>
      <div class="photo-wrap">
        <?php print render($photo); ?>
          <div class="hero-caption">
            <span class="caption-copy"><?php print $credit; ?></span>
          </div>
      </div>
    <?php endif; ?>
  </div>
  <div class="column small-12 force-width <?php print $grid_class; ?>">
    <div class="links">
      <?php if (isset($headline)): ?>
        <h3 class="post-headline"><?php print $headline; ?></h3>
      <?php endif; ?>
      <?php if (isset($copy)): ?>
        <p><?php print $copy; ?></p>
      <?php endif; ?>
      <?php if (isset($links)): ?>
         <?php print render($links); ?>
      <?php endif; ?>
    </div>
  </div>
</div>
