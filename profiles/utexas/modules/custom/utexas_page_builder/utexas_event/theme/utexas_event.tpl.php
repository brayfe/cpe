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
<div class="field_event_details event-page">
  <div class="event-block">
    <div class="event-details-top">
      <?php if ($content['image']): ?>
      <div class="post-image">
        <?php print $content['image']; ?>
      </div>
      <?php endif; ?>
      <div class="event-details">
        <div class="event-date"><?php print $content['dates']; ?></div>
        <div class="event-headline"><?php print $content['title']; ?></div>
        <div class="event-time-and-location">
          <div class="event-time"><?php print $content['times']; ?></div>
          <?php if($content['location']): ?>
            <div class="event-location"><?php print $content['location']; ?></div>
          <?php endif; ?>
        </div>
        <div class="export-links">
          <?php print $content['google_calendar']; ?>
          <?php print $content['ical']; ?>
        </div>
      </div>
    </div>
    <div class="field_wysiwyg_a">
    <?php print $content['detail_text']; ?>
    <?php print $content['tags']; ?>
    </div>
  </div>
</div>
