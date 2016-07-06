<?php

/**
 * @file
 * Displays the Event detail entity.
 *
 * @see utexas_event_theme()
 *
 * @ingroup themeable
 */
?>
<div class="field_event_details">
  <div class="event-block">
    <a class="cta-link sans" href="<?php print $content['link']; ?>"><span><?php print $content['title']; ?></span></a>
    <div class="post-cta-link">
      <?php print $content['dates'] . ', ' . $content['times']; ?>
    </div>
  </div>
</div>
