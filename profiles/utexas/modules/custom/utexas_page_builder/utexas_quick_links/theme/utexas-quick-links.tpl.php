<?php
/**
 * @file
 * Compound field template for Social Links.
 *
 * Available variables:
 *  - $classes: A string of classes to add to the field collection item.
 *  - $attributes: A string representing attributes to add to this item.
 *  - $content_attributes: Content attributes for the item.
 *  - $headline: The defined headline
 *  - $links: an array of user-defined links, with social media name
 *  - $page_template: the human readable name of the page template of the node.
 *  - $quick_links_region: machine name of the region of the Quick Links block.
 *
 * @ingroup themeable.
 */

if ($headline != FALSE) :
echo '<h3 class="sidebar-headline">' . $headline . '</h3>';
endif;
if ($copy != FALSE) :
  echo '<div class="body-copy">' . $copy . '</div>';
endif;
if ($links != FALSE) :
  if ($page_template == 'Landing Page Template 2') :
    echo '<div class="row">';
    print render($links);
    echo '</div>';
  else :
    print render($links);
  endif;
endif;
