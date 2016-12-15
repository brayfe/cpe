<?php

/**
 * @file
 * Theme implementation for the social share block.
 *
 * Available variables.
 *  - $current_url: URL of the current page path.
 *  - $current_url_urlencoded: Encoded URL of the current page path.
 *  - $mailto_subject: The subject line for the mailto link.
 *  - $body: The body of the email.
 *  - $title_encoded: The encoded URL title for the page.
 *
 * @see template_preprocess_utexas_news_share().
 *
 * @ingroup themeable
 */
?>
<?php print $social_sharing_details; ?>
<div class="social-share social-share-bottom">
  <h3 class="post-headline"><?php print $utexas_social_sharing_title; ?></h3>
  <ul class="social-links <?php print $grid_class; ?>">
  <?php
    foreach ($variables['enabled'] as $key => $values) {
      echo '<li class="social-share-li"><a href="' . $values['link'] . '" class="connect-link ' . $values['class'] . '" data-href="' . $values['data'] . '">';
      echo '<span class="' . $values['icon'] . '"></span>';
      echo '<span class="social-name ' . $hidden . '">' . $values['text'] . '</span></li>';
    }
  ?>
  </ul>
</div>
