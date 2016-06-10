<?php
/**
 * @file
 * Partial file to display breadcrumbs.
 *
 * Available variables:
 *  - $breadcrumb: The rendered breadcrumb for the page.
 */

if ($breadcrumb) :
  ?>
  <div class="row">
    <div class="column small-12 show-for-medium-up">
      <?php print render($breadcrumb); ?>
    </div>
  </div>
  <?php
endif;
