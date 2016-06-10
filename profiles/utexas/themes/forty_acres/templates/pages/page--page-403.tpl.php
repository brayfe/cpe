<?php
/**
 * @file
 * Template for the site's 403 page.
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
<?php global $base_root; ?>
<?php if (file_exists($partial_header)): require_once $partial_header; endif;  ?>

<div class="UT-page page-404" id="ut-page-content" role="main">
  <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>

  <div class="container container-top">
    <div class="row">
      <div class="column medium-10 large-9 medium-centered">
        <h1 class="page-title">Access Denied</h1>
        <div class="not-found">
        <p>We're sorry, you are not authorized to access this page.</p>
        </div>
      </div>
    </div>
  </div>

  <div class="container container-bottom">
    <div class="row">
      <div class="column medium-10 large-9 medium-centered">
        <section class="main-content">
          <div class="field_wysiwyg_a">
            <p>Have an ID? Please <?php print l(t('Log in'), 'user/login', array('query' => array('destination' => request_path()))); ?>.</p>
            <?php if (empty($page['menus']['core_helpful_links'])): ?>
              <p>If you feel you have reached this page in error, please <?php print l(t('contact us'), '<front>'); ?>. You may also search in the site header.</p>
            <?php else: ?>
              <p>If you feel you have reached this page in error, please <?php print l(t('contact us'), '<front>'); ?>. You may also search in the site header or view the helpful links below.</p>
              <h3>Helpful Links</h3>
              <?php print render($page['menus']['core_helpful_links']); ?>
            <?php endif; ?>
          </div>
        </section>
      </div>
    </div>
  </div>
  <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
</div>
