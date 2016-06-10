<?php
/**
 * @file
 * Compound field template for Hero Photos.
 *
 * Available variables:
 *  - $photo: User uploaded hero photo image.
 *  - $caption: Photo caption.
 *  - $credit: Photo credit.
 *
 * @ingroup themeable.
 */
?>

<?php if ($photo): ?>
  <?php print render($photo); ?>
  <?php if (isset($caption) or isset($credit)): ?>
    <div class="hero-caption">
      <p>
        <?php if (isset($caption)): ?>
          <?php print $caption; ?>
        <?php endif; ?>
        <?php if (isset($credit)): ?>
          <span class="caption-copy<?php print (!isset($caption)) ? ' full' : ''; ?>">
            <?php print render($credit); ?>
          </span>
        <?php endif; ?>
      </p>
    </div>
  <?php endif; ?>
<?php endif; ?>
