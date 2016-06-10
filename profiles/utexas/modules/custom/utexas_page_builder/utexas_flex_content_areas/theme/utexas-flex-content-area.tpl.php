<?php
/**
 * @file
 * Displays a Flex Content Area.
 *
 * Available variables:
 *  - $is_admin: Boolean to see if the user has administrative privileges.
 *  - $logged_in: Boolean to see if the user is logged in or not.
 *  - $is_front: Boolean to see if the page is the front page or not.
 *  - $image: If true, image representing the uploaded Flex Content Area image.
 *  - $headline: If true, headline for the Flex Content Area.
 *  - $copy: If true, copy for the Flex Content Area.
 *  - $call_to_action: If true, formatted call-to-action for the Flex Content
 *  - $page_template: the human readable name of the page template of the node.
 *  - $flex_content_area_a_region: the region of the flex content area A block.
 *  - $flex_content_area_b_region: the region of the flex content area B block.
 *  - $links: If true, formatted list of links for the Flex Content Area.
 *
 * @see template_preprocess_utexas_flex_content_area()
 *
 * @ingroup themeable
 */
?>
<div class="utexas-flex-content">
  <?php if ($image): ?>
    <div class="utexas-flex-content-area-image-wrapper">
      <?php print $image; ?>
    </div>
  <?php endif; ?>
  <?php if ($headline): ?>
    <h3 class="utexas-flex-content-area-headline"><?php print $headline; ?></h3>
  <?php endif; ?>
  <?php if ($copy): ?>
    <div class="utexas-flex-content-area-copy">
      <?php print $copy; ?>
    </div>
  <?php endif; ?>
  <?php if ($links): ?>
    <div class="utexas-flex-content-area-links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>
  <?php if ($call_to_action): ?>
    <div class="utexas-flex-content-area-call-to-action">
      <?php print $call_to_action; ?>
    </div>
  <?php endif; ?>
</div>
