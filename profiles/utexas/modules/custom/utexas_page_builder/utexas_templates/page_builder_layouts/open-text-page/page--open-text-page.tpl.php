<?php
/**
 * @file
 * Template for Open Text page (a basic WYSWIYG).
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
 * - $locked_fields: Any fields locked to this page template.
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
<div class="UT-page" id="ut-page-content" role="main">
  <div class="container bottom-search">
    <?php if (file_exists($partial_breadcrumbs)) : require_once $partial_breadcrumbs; endif; ?>
    <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>
    <div class="row">
      <div class="column medium-10 large-9 medium-centered">
        <h1 class="page-title"><?php print $title; ?></h1>
      </div>
    </div>

    <div class="row">
      <div class="column medium-10 large-9 medium-centered">
        <section class="main-content">
          <?php if (isset($locked_fields['field_wysiwyg_a'])): ?>
            <div class="block-fieldblock">
              <?php print render($locked_fields['field_wysiwyg_a']); ?>
            </div>
          <?php endif; ?>
        </section>
      </div>
    </div>
  </div>
  <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
</div>
<?php render($page['content']); ?>
