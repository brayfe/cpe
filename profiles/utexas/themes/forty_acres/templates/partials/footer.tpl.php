<?php
/**
 * @file
 * Partial file to display the footer.
 *
 * @todo ITS to update this file when Subscribe to our Newsletter module has
 *   been completed.
 */

?>
    <div class="container container-footer footer-theme2">
      <div class="row">
        <div class="column small-12 medium-4">
          <div class="footer-primary">
            <?php if ($logo) : ?>
              <div class="footer-logo">
                <a href="<?php print $base_path; ?>" class="main-logo"><span class="hiddenText"><?php print $site_name; ?></span><img src="<?php print $logo; ?>" alt="main_logo"></a>
              </div>
            <?php endif; ?>
            <?php if ($footer_text) : ?>
              <div class="footer-contact">
                <?php print $footer_text; ?>
              </div>
            <?php endif; ?>
              <div class="connect">
                <?php if ($display_social == '1' && module_exists('utexas_social_accounts')) :
                  $block = block_load('utexas_social_accounts', 'social_accounts_block');
                  $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
                  $output = render($render_array);
                  print $output;
                endif; ?>
              </div>
            </div>
        </div>
        <?php if ($page['menus']['footer']) : ?>
          <div class="column small-12 medium-4">
            <div class="footer-secondary">
                <?php print render($page['menus']['footer']); ?>
             </div>
          </div>
        <?php endif; ?>
        <div class="column small-12 <?php print $related_links_class; ?>">
          <div class="footer-tertiary">
            <?php if (($newsletter_exists == 1) && ($newsletter_url)) : ?>
              <div class="newsletter">
                 <a href="<?php print render($newsletter_url); ?>" target="_blank" class="cta sidebar-cta"><span>Subscribe to our newsletter</span></a>
              </div>
            <?php endif; ?>
            <ul class="helpful-links <?php print $related_links_block_grid_class; ?>">
              <li class="helpful-link-item"><a href="http://www.utexas.edu" class="helpful-link">UT Austin Home</a></li>
              <li class="helpful-link-item"><a href="http://www.utexas.edu/emergency" class="helpful-link">Emergency Information</a></li>
              <li class="helpful-link-item"><a href="http://www.utexas.edu/site-policies" class="helpful-link">Site Policies</a></li>
              <li class="helpful-link-item"><a href="http://www.utexas.edu/web-accessibility-policy" class="helpful-link">Web Accessibility Policy</a></li>
              <li class="helpful-link-item"><a href="http://www.utexas.edu/web-privacy-policy" class="helpful-link">Web Privacy Policy</a></li>
              <li class="helpful-link-item"><a href="https://get.adobe.com/reader/" class="helpful-link">Adobe Reader</a></li>
            </ul>
          </div>
        </div>

      </div>

        <div class="row">
          <br/>
          <div class="copyright">&copy; The University of Texas at Austin <?php echo date("Y"); ?></div>
        </div>
    </div><!--container-footer-->
