<?php
/**
 * @file
 * Partial file to display misc. information, like site messages or tabs.
 */

if ($messages) :
  ?>
  <div class="row">
    <div class="column small-12">
      <div id="console" class="clearfix"><?php print $messages; ?></div>
    </div>
  </div>
  <?php endif; ?>
  <?php if ($tabs) : ?>
  <div class="row">
    <div class="column small-12">
      <?php print render($tabs); ?>
    </div>
  </div>
  <?php endif; ?>
