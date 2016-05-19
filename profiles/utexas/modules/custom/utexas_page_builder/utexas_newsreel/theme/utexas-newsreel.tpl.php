<?php
/**
 * @file
 * Compound field template for Hero Photos.
 *
 * Available variables:
 *  - $headline: header text for block
 *  - $items: array of news feed items
 *  - $more link: a link to the originating source.
 *
 * @ingroup themeable.
 */

if (!empty($items)) :
 echo '<div>
  <div class="sidebar-headline">
    <h3 class="post-headline">' . $headline . '</h3>
  </div>
  <div class="module-content">';
  foreach ($items as $key => $item) :
    echo '<div class="news-item item-' . $key . '">
      <span class="news-date">' . $item['date'] . '</span>
      <h4 class="news-headline">
        <a class="headline-link" href="' . $item['link'] . '">' . $item['headline'] . '</a>
      </h4>';
      if ($include_description) :
        echo '<p class="news-description">' . $item['description'] . '</p>';
      endif;
      echo '<a class="cta-link" href="' . $item['link'] . '"><span>Read more</span></a>
    </div>';
  endforeach;
  if ($view_all) : print $view_all; endif;
  echo '</div>
</div>';
endif;
