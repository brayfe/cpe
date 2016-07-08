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
<div class="field_event_details event_teaser">
  <div class="event-block">
    <div class="event-date"><?php print $content['dates']; ?></div>
    <div class="event-headline"><?php print $content['linked_title']; ?></div>
    <?php if ($content['thumbnail']): ?>
      <?php print $content['thumbnail']; ?>
    <?php endif; ?>
    <div class="event-time"><?php print $content['times']; ?></div>
    <?php if($content['location']): ?>
      <div class="event-location"><?php print $content['location']; ?></div>
    <?php endif; ?>
    <p class="event-text"><?php print $content['summary_text']; ?> <a class="cta-link post-cta-link" href="<?php print $content['link']; ?>"><span>Event Details</span></a></p>
  </div>
</div>
