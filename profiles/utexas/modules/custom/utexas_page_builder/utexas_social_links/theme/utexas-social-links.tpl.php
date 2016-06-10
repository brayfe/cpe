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
 *  - $links: an array of user-defined links, with social media name.
 *
 * @ingroup themeable.
 */
?>
<h4><?php echo $headline; ?></h4>
<ul class="connect-links">
<?php
  foreach ($links as $name => $link) :
    echo '<li><a href="' . $link . '" class="connect-link" title="' . $name . '"><span class="icon-' .
    strtolower($name) . '"><span class="hiddenText">' . $name .
    '</span></span></a></li>';
  endforeach;
?>
</ul>
