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
 * @see template_preprocess_utexas_promo_unit()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="utexas-promo-field ut-promo-list">
  <?php if ($image): ?>
    <?php print $image; ?>
  <?php endif; ?>
  <?php if (!empty($headline) or !empty($copy)): ?>
    <div class="content">
      <?php if (!empty($headline)): ?>
        <h3 class="promo-headline"><?php print $headline; ?></h3>
      <?php endif; ?>
      <?php if (!empty($copy)): ?>
        <div class="promo-copy"><p><?php print $copy; ?></p></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
</div>
