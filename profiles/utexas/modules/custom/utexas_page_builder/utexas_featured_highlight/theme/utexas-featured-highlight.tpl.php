<?php
/**
 * @file
 * Compound field template for Featured Highlights.
 *
 * Available variables:
 *  - $variables['headline']:
 *  - $variables['image']:
 *  - $variables['copy']:
 *  - $variables['cta']:
 *  - $variables['link']:
 *  - $variables['highlight_style']:
 *  - $page_template: the human readable name of the page template of the node.
 *  - $featured_highlight_region: the region of the featured highlight block.
 *  Typically $featured_highlight_region will be FALSE because it is not placed
 *  in a region on any of the existing templates.
 *
 * @see template_preprocess_utexas_featured_highlight();
 *
 * @ingroup themeable.
 */
?>

<div class="container container-highlight field_utexas_featured_highlight <?php print $highlight_style; ?> <?php print $has_image; ?>">
  <div class="container-highlight-table-row">
    <div class="row">
      <div class="column small-12">
        <?php
          if ($image != '') :
            echo '<div class="highlight-image template-highlight">';
            print render($image);
            echo '</div>';
          endif;
        ?>
        <div class="featured-highlight-content">
          <?php
            if ($date) :
              echo '<div class="highlight-date">' . $date . '</div>';
            endif;
          ?>
          <h2 class="highlight-headline"><?php print $headline; ?></h2>
          <div class="highlight-text">           
            <?php print $copy; ?>
            <?php print $read_more; ?>           
          </div>
        </div>
      </div>
    </div>
  </div>
</div>
