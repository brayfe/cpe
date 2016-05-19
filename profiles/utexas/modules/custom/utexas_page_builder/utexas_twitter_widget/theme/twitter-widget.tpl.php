<?php

/**
 * @file
 * Displays the Twitter box.
 *
 * Available variables:
 *  - $link: The link to the Twitter feed.
 *  - $tweets: Array of tweets.
 *  - $headline: the user-defined headline text
 *  - $view_all: linked, user-defined view all text.
 *
 * @see template_preprocess_utexas_home_tweets()
 * @see template_preprocess_utexas_home_tweet()
 *
 * @ingroup themeable
 */

?>
<div class="sidebar-module sidebar-default-style">

<?php
if ($content['tweets'] !== FALSE) :
  echo '<h3 class="sidebar-headline">' . $content['headline'] . '</h3>';
  echo '<div class="module-content">';
  foreach ($content['tweets'] as $count => $tweet) :
    echo '<div class="tweet" id="tweet-' . $count . '">';
      echo '<div class="tweet-image">' . $tweet['image'] . '</div>';
      echo '<div class="tweet-author">' . $tweet['author'] . '</div>';
      echo '<div class="tweet-username">' . $tweet['username'] . '</div>';
      echo '<div class="tweet-text">' . $tweet['text'] . '</div>';
      echo '<div class="tweet-time">' . $tweet['timestamp'] . '</div>';
      echo '<ul class="tweet-actions">';
      echo $tweet['tweet_actions'];
      echo '</ul>';
    echo '</div>';
  endforeach;
  if ($content['view_all']) : echo $content['view_all']; endif;
endif;
?>
</div>
</div>
