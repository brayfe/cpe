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
 * - $cta: A string represting the text for the call to action
 * - $copy: The formatted copy for the promo
 * - $read_more: If not false, a text link with the CTA.
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
<div class="field_utexas_resource">
  <?php if ($title): ?>
    <?php print '<div class="utexas-resource-wrapper"><h3 class="post-headline">' . $title . '</h3></div>'; ?>
  <?php endif; ?>
  <div class="flex-content horizontal">
    <div class="row">
      <?php if ($image): ?>
        <div class="column large-6">
          <div class="img-wrap">
            <?php print $image; ?>
          </div>
        </div>
        <div class="column large-6 content-box">
          <?php if (!empty($headline)): ?>
            <h3 class="resource-headline"><?php print $headline; ?></h3>
          <?php endif; ?>
          <div class="resource-links">
            <?php print $links; ?>
          </div>
        </div>
      <?php else: ?>
        <div class="column small-12 full-width-content-box">
          <?php if (!empty($headline)): ?>
            <h3 class="resource-headline"><?php print $headline; ?></h3>
          <?php endif; ?>
          <div class="resource-links">
            <?php print $links; ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
  </div>
</div>
