<?php
/**
 * @file
 * Theme implementation for the image link.
 *
 * Available variables:
 *  - $link: The linked image.
 *
 * @see template_preprocess_utexas_image_link()
 *
 * @ingroup themeable.
 */
?>
<?php if ($link): ?>
  <div class="utexas-image-link">
    <?php print $link; ?>
  </div>
<?php endif; ?>
