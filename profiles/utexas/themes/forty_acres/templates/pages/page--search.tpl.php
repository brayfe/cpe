<?php
/**
 * @file
 * Template for a basic page.
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

<div class="UT-page" id="ut-page-content" role="main">
  <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>

   <div class="container container-top">
    <div class="row">
      <div class="column medium-10 large-9 medium-centered">
        <h1 class="page-title">Search</h1>
        <div class="search">
          <div class="div-search-404">
          <?php
            if (isset($search_cse)) :
             print $search_cse;
            else :
              print $drupal_search;
            endif;
            print render($page['content']);
          ?>
          </div>
        </div>
      </div>
    </div>
  </div>
  <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
</div>
