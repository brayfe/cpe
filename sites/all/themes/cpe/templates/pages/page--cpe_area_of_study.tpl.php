<?php

/**
 * @file
 * Template for a Area of study page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup themeable.
 */
?>

<?php if (file_exists($partial_header)): require_once $partial_header; endif;  ?>

  <div class="UT-page default-page" id="ut-page-content" role="main">
    <div class="container container-top">
      <?php if (file_exists($partial_breadcrumbs)) : require_once $partial_breadcrumbs; endif; ?>
      <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>
      <?php if (!isset($no_title)): ?>

        <div class="top-banner">
          <!-- the div below prints the hero background image-->
          <div class="container container-hero hero-style-1">

            <div class="row">
            <!--set placement of content that appears on top of hero image-->
              <div class="column small-12 medium-6 large-6 relative-pos">
                <h1 class="page-title"><?php print $title; ?></h1>
              </div>
              <div class="column small-12 medium-5 large-5 rfi-block">
                <div class="rfi-code"><?php print render($field_aos_rfi); ?></div>
              </div>

            </div>
          </div>

        </div>


      <?php endif; ?>
    </div>
    <div class="container">
      <?php if($page['header']):?>
        <div class="row">
          <div class="columns small-12">
            <?php print render($page['header']); ?>
          </div>
        </div>
      <?php endif; ?>

      <div class="middle_content row">

        <?php if($page['content']):?>
          <div class="column small-12 medium-8 large-9">
            <?php
              // Print fields in the main area.
              print render($field_aos_headline);
              print render($field_aos_description);
              print render($field_aos_cert_options);
              print render($field_aos_certify_body);
              // Display field if it isn't "Continuing Education Units".
              if ($display_link) {
                print render($field_aos_accred_body);
              }
              print render($field_aos_featured);
              print render($field_aos_related_arts);
              if ($display_link) {
                print render($link_to_course_listing);
              }
            ?>

          </div>
        <?php endif; ?>

          <div class="column small-12 medium-4 large-3">
            <!--contact info-->
            <div class="contact-wrapper">
              <h2 class="contact-title">Contact</h2>
              <div class="coordinator-name"><?php print render($field_aos_contact_name); ?></div>
              <?php
                print render($field_aos_contact_phone);
                print render($field_aos_contact_email);
              ?>
            </div>
            <?php if($page['sidebar_second']):?>
              <?php print render($page['sidebar_second']); ?>
            <?php endif; ?>
          </div>

      </div>

      <?php if ($page['footer']): ?>
        <div class="row">
          <div class="column small-12">
            <?php print render($page['footer']); ?>
          </div>
        </div>
      <?php endif; ?>
    </div>
    <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
  </div>
