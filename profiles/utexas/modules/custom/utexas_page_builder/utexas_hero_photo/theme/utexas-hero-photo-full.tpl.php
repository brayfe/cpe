<?php
/**
 * @file
 * Compound field template for Hero Photos, Full Width.
 *
 * Available variables:
 *  - $photo: User uploaded hero photo image.
 *  - $headline: Headline.
 *  - $subhead: Subheading.
 *  - $link: Link.
 *
 * @ingroup themeable.
 */
?>
<?php if ($photo) : ?>
<?php $templates = array('hero-style-1', 'hero-style-2', 'hero-style-3'); ?>
<?php if (in_array($hero_image_style, $templates)): ?>
  <div class="container container-hero <?php print $hero_image_style; ?>">
    <div class="background-box">
      <p class="hiddenText"><?php if ($hero_alt) : print $hero_alt; endif; ?></p>
    </div>
    <div class="row">
      <div class="small-12 column">
        <?php if ($headline or $link) : ?>
          <div class="hero-callout">
            <div class="callout-text">
              <?php if ($headline) : ?>
                <div class="headline"><?php print $headline; ?></div>
              <?php endif; ?>
              <?php if ($subhead) : ?>
                <div class="subhead"><?php print $subhead; ?>
                  <?php if ($link) : ?>
                    <?php print $post_link; ?>
                  <?php endif; ?>
                </div>
              <?php endif; ?>
            </div>
            <?php if ($link) : ?>
              <div class="callout-cta">
                <?php print $link; ?>
              </div>
            <?php endif; ?>
          </div>
        <?php endif; ?>
      </div>
    </div>
  </div>
  <?php endif; ?>
  <?php if ($hero_image_style == "hero-style-4"): ?>
    <div class="container container-hero <?php print $hero_image_style; ?>">
      <?php if (isset($photo)): ?>
        <div class="row">
          <div class="medium-12 column">
            <div class="hero-img">
              <img src="<?php print $image_url; ?>" alt="<?php if ($hero_alt) : print $hero_alt; endif; ?>" title="<?php if ($hero_title) : print $hero_title; endif; ?>">
            </div>
          </div>
        </div>
      <?php endif; ?>
      <div class="row">
        <div class="medium-12 column">
          <div class="herocallout">
            <div class="row">
              <div class="medium-12 large-9 column">
                <?php if ($headline) : ?>
                  <div class="headline"><?php print $headline; ?></div>
                <?php endif; ?>
                <?php if ($subhead) : ?>
                  <div class="subhead"><?php print $subhead; ?></div>
                <?php endif; ?>
              </div>
              <div class="medium-12 large-3 column">
                <?php if ($link) : ?>
                  <?php print $link; ?>
                <?php endif; ?>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($hero_image_style == "hero-style-5"): ?>
  <div class="container container-hero <?php print $hero_image_style; ?>">
    <div class="row" data-equalizer>
      <div class="medium-5 column force-width">
        <div class="hero-thumbnail" data-equalizer-watch>
          <p class="hiddenText"><?php if ($hero_alt) : print $hero_alt; endif; ?></p>
        </div>
      </div>
        <div class="medium-7 column force-width">
          <div class="content-wrap" data-equalizer-watch>
            <?php if ($headline): ?>
              <div class="hero-headline"><?php print $headline; ?></div>
            <?php endif; ?>
            <?php if ($subhead): ?>
              <div class="hero-subhead"><?php print $subhead; ?></div>
            <?php endif; ?>
            <?php if ($link): ?>
                <?php print $link; ?>
            <?php endif; ?>
          </div>
        </div>
      </div>
    </div>
  <?php endif; ?>
<?php endif; ?>
