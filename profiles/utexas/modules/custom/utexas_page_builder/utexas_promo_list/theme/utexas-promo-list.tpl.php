<?php
/**
 * @file
 * Default theme implementation to display a promo unit.
 *
 * Available variables:
 * - $headline: Either a text or linked text for the promo's headline
 * - $headline_text: The raw text value for the promo's headline
 * - $image_fid: The raw file ID for the image
 * - $link: The link for the promo
 * - $copy: The formatted copy for the promo
 * - $read_more: If not false, a link with the CTA. Defaults to "Read story"
 * - $image: An <img> tag (optionally with an image link) with the promo image.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs 'odd' and 'even' on the field order.
 * - $id: Promo unit ID
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * @see template_preprocess()
 * @see template_preprocess_utexas_promo_list)
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="utexas-promo-field utexas-promo-list">
  <?php if ($image): ?>
    <?php print $image; ?>
  <?php endif; ?>
  <?php $image_status_class = (!$image) ? "no_image" : ""; ?>
    <div class="content <?php print $image_status_class; ?>">
      <?php if ($headline != FALSE): ?>
        <h3 class="promo-headline"><?php print $headline; ?></h3>
      <?php endif; ?>
      <div class="promo-copy">
      <?php if ($copy != FALSE): ?>
       <?php print $copy; ?>
      <?php endif; ?>
      </div>
    </div>
</div>
