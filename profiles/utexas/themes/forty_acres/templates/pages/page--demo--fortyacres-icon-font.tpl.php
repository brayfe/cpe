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
<style>
body {padding: 0; margin: 0; font-size: 1em; line-height: 1.5; color: #555; background: #fff;}
.glyph {font-size: 16px; padding-bottom: 1em; margin-bottom: 1em;}
.mls {margin-left: .25em; font-family: open_sans, serif; }
.unicode {margin-top: 10px; font-family: open_sans, serif;}
.pbs {padding-bottom: .25em; text-align:center;}
.fs2 {font-size: 24px;}
.container-main{padding-top: 40px; padding-bottom:40px;}
ul.icon-demo li {min-height: 100px;}
ul.icon-demo {padding-top: 40px;}
</style>
<div class="UT-page default-page" id="ut-page-content" role="main">
  <div class="container container-top">
    <?php if (file_exists($partial_breadcrumbs)) : require_once $partial_breadcrumbs; endif; ?>
    <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>
    <?php if (!isset($no_title)): ?>
      <div class="row">
        <div class="column small-12">
          <h1 class="page-title"><?php print $title; ?></h1>
        </div>
      </div>
    <?php endif; ?>
  </div>
  <div class="container container-main">
    <div class="row">
      <div class="columns small-12">
        <p>The icon set is provided by the UTexas Fonts custom module.  This module contains the font files and the CSS defining specific icon classes.  There are two ways to use these icons.  The first is by adding a class to an HTML element. For example, <pre><code>&lti class="icon-flickr">&lt/i></code></pre> <p>will render the flickr icon.</p>
        <p>The second way involves calling the icons on an ::after pseudo-class. The following CSS would append an arrow icon to all elements with the "headline-link" class:
<pre>.headline-link::after {
    content: "\f101";
    font-family: "forty_acres_icons";
}</pre>
        <p>For more advanced users, there is a SASS mixin available for the more commonly used icons.  The mixin is located at ../forty_acres/src/scss/mixins/_icons.scss.  The following grid shows all of the currently available icons.  If you choose to use &lti> tags you will need to use the class names.  If you choose to use ::after pseudo-classes you will need to use the unique alphanumeric identifiers in the "content" attribute.</p>
      </div>
      <ul class="columns small-block-grid-1 medium-block-grid-2 large-block-grid-3 icon-demo">
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-controller-play"></span>
                  <span class="mls"> icon-controller-play</span>
                  <div class="unicode">\e900</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-facebook2"></span>
                  <span class="mls"> icon-facebook2</span>
                  <div class="unicode">\ea90</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-instagram2"></span>
                  <span class="mls"> icon-instagram2</span>
                  <div class="unicode">\ea92</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-clock"></span>
                  <span class="mls"> icon-clock</span>
                  <div class="unicode">\e94e</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-link"></span>
                  <span class="mls"> icon-link</span>
                  <div class="unicode">\e9cb</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-location"></span>
                  <span class="mls"> icon-location</span>
                  <div class="unicode">\f060</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-vimeo2"></span>
                  <span class="mls"> icon-vimeo2</span>
                  <div class="unicode">\eaa1</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-vimeo-square"></span>
                  <span class="mls"> icon-vimeo-square</span>
                  <div class="unicode">\f194</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-envelope"></span>
                  <span class="mls"> icon-envelope</span>
                  <div class="unicode">\f003</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-heart"></span>
                  <span class="mls"> icon-heart</span>
                  <div class="unicode">\f004</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-star"></span>
                  <span class="mls"> icon-star</span>
                  <div class="unicode">\f005</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-check"></span>
                  <span class="mls"> icon-check</span>
                  <div class="unicode">\f00c</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-remove"></span>
                  <span class="mls"> icon-remove</span>
                  <div class="unicode">\f00d</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-file"></span>
                  <span class="mls"> icon-file</span>
                  <div class="unicode">\f016</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-lock"></span>
                  <span class="mls"> icon-lock</span>
                  <div class="unicode">\f023</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-warning"></span>
                  <span class="mls"> icon-warning</span>
                  <div class="unicode">\f071</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-comment"></span>
                  <span class="mls"> icon-comment</span>
                  <div class="unicode">\f075</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-retweet"></span>
                  <span class="mls"> icon-retweet</span>
                  <div class="unicode">\f079</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-phone"></span>
                  <span class="mls"> icon-phone</span>
                  <div class="unicode">\f095</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-twitter-bird"></span>
                  <span class="mls"> icon-twitter-bird</span>
                  <div class="unicode">\f099</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-caret-down"></span>
                  <span class="mls"> icon-caret-down</span>
                  <div class="unicode">\f0d7</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-file-text"></span>
                  <span class="mls"> icon-file-text</span>
                  <div class="unicode">\f0f6</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-mail-reply"></span>
                  <span class="mls"> icon-mail-reply</span>
                  <div class="unicode">\f11a</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-calendar"></span>
                  <span class="mls"> icon-calendar</span>
                  <div class="unicode">\f133</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-reply"></span>
                  <span class="mls"> icon-reply</span>
                  <div class="unicode">\e600</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-links"></span>
                  <span class="mls"> icon-links</span>
                  <div class="unicode">\f100</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-buttons"></span>
                  <span class="mls"> icon-buttons</span>
                  <div class="unicode">\f101</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-search"></span>
                  <span class="mls"> icon-search</span>
                  <div class="unicode">\f102</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-menu"></span>
                  <span class="mls"> icon-menu</span>
                  <div class="unicode">\f103</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-facebook"></span>
                  <span class="mls"> icon-facebook</span>
                  <div class="unicode">\f104</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-twitter"></span>
                  <span class="mls"> icon-twitter</span>
                  <div class="unicode">\f105</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-youtube"></span>
                  <span class="mls"> icon-youtube</span>
                  <div class="unicode">\f106</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-flickr"></span>
                  <span class="mls"> icon-flickr</span>
                  <div class="unicode">\f107</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-chevron-down"></span>
                  <span class="mls"> icon-chevron-down</span>
                  <div class="unicode">\f108</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-chevron-up"></span>
                  <span class="mls"> icon-chevron-up</span>
                  <div class="unicode">\f109</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-linkedin"></span>
                  <span class="mls"> icon-linkedin</span>
                  <div class="unicode">\f110</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-mail"></span>
                  <span class="mls"> icon-mail</span>
                  <div class="unicode">\f111</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-alert"></span>
                  <span class="mls"> icon-alert</span>
                  <div class="unicode">\f112</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-external-link"></span>
                  <span class="mls"> icon-external-link</span>
                  <div class="unicode">\f113</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-announcement"></span>
                  <span class="mls"> icon-announcement</span>
                  <div class="unicode">\f114</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-twitterInverse"></span>
                  <span class="mls"> icon-twitterInverse</span>
                  <div class="unicode">\f115</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-beacon"></span>
                  <span class="mls"> icon-beacon</span>
                  <div class="unicode">\f116</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-reddit"></span>
                  <span class="mls"> icon-reddit</span>
                  <div class="unicode">\f117</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-googleplus"></span>
                  <span class="mls"> icon-googleplus</span>
                  <div class="unicode">\f118</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-tumblr"></span>
                  <span class="mls"> icon-tumblr</span>
                  <div class="unicode">\f119</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-instagram"></span>
                  <span class="mls"> icon-instagram</span>
                  <div class="unicode">\f120</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-pinterest"></span>
                  <span class="mls"> icon-pinterest</span>
                  <div class="unicode">\f121</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-more"></span>
                  <span class="mls"> icon-more</span>
                  <div class="unicode">\f122</div>
              </div>
          </li>
          <li class="glyph fs2">
              <div class="pbs">
                  <span class="icon-close"></span>
                  <span class="mls"> icon-close</span>
                  <div class="unicode">\f123</div>
              </div>
          </li>
      </ul>
    </div>
  </div>
  <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
</div>
