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
<?php $forty_acres_path = drupal_get_path('theme', 'forty_acres'); ?>
<?php drupal_add_js($forty_acres_path . '/js/highlight.pack.js', array(
  'scope' => 'head_scripts',
  'weight' => -1,
)); ?>
<?php drupal_add_css($forty_acres_path . '/css/solarized-dark.css'); ?>
<?php if (file_exists($partial_header)): require_once $partial_header; endif;  ?>
<style>
pre {
  white-space: pre-wrap;
  white-space: -moz-pre-wrap;
  white-space: -pre-wrap;
  white-space: -o-pre-wrap;
  word-wrap: break-word; }
 .tabs .tab-title a {
     padding: 20px 30px!important;
     font-size: 1rem; }
}
</style>
<div class="UT-page default-page" id="ut-page-content" role="main">
  <div class="container container-top">
    <?php if (file_exists($partial_breadcrumbs)) : require_once $partial_breadcrumbs; endif; ?>
    <?php if (file_exists($partial_page_top)) : require_once $partial_page_top; endif; ?>
    <div class="row">
      <div class="column small-12">
        <h1 class="page-title"><?php print $title; ?></h1>
      </div>
    </div>
  </div>
  <div class="container">
    <div class="row">
      <div class="small-12 columns">
        <ul style="text-align:center;" class="small-block-grid-2 medium-block-grid-3">
          <li><a href="#accordion">Accordions</a></li>
          <li><a href="#alert-boxes">Alert Boxes</a></li>
          <li><a href="#dropdown-buttons">Dropdown Buttons</a></li>
          <li><a href="#reveal">Reveal Modals</a></li>
          <li><a href="#tabs">Tabs</a></li>
          <li><a href="#tooltips">Tooltips</a></li>
        </ul>
        <hr>
        <div style="height:30px;"></div>

        <!-- accordions -->
        <h4 id="accordion">Accordion</h4>
        <div style="height:10px;"></div>
        <dl class="accordion" data-accordion>
          <dd class="accordion-navigation">
            <a href="#panel1b">Accordion 1</a>
            <div id="panel1b" class="content active">
              Panel 1. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
            </div>
          </dd>
          <dd class="accordion-navigation">
            <a href="#panel2b">Accordion 2</a>
            <div id="panel2b" class="content">
              Panel 2. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
            </div>
          </dd>
          <dd class="accordion-navigation">
            <a href="#panel3b">Accordion 3</a>
            <div id="panel3b" class="content">
              Panel 3. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
            </div>
          </dd>
        </dl>
        <div style="height:30px;"></div>
        <p><a class="radius button" data-reveal-id="accordion-modal" href="#">accordion code</a>
        <div data-reveal="" class="reveal-modal" id="accordion-modal">
          <h2>Accordion example code</h2>
          <pre><code class='html'>
&ltdl class="accordion" data-accordion>
  &ltdd class="accordion-navigation">
    &lta href="#panel1b">Accordion 1&lt/a>
    &ltdiv id="panel1b" class="content active">
      Panel 1. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
    &lt/div>
  &lt/dd>
  &ltdd class="accordion-navigation">
    &lta href="#panel2b">Accordion 2&lt/a>
    &ltdiv id="panel2b" class="content">
      Panel 2. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
    &lt/div>
  &lt/dd>
&ltdd class="accordion-navigation">
  &lta href="#panel3b">Accordion 3&lt/a>
    &ltdiv id="panel3b" class="content">
      Panel 3. Lorem ipsum dolor sit amet, consectetur adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
    &lt/div>
  &lt/dd>
&lt/dl>
          </code></pre>
          <a class="close-reveal-modal">×</a>
        </div>
        <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/accordion.html">Foundation Docs for Accordions</a></h5>
      <hr>

      <!-- alert boxes -->
      <h4 id="alert-boxes">Alert Boxes</h4>
      <div style="height:30px;"></div>
      <div class="alert-box radius" data-alert="">
        This is a standard alert (div.alert-box.radius).
        <a class="close" href="">×</a>
      </div>
      <div class="alert-box success" data-alert="">
        This is a success alert (div.alert-box.success).
        <a class="close" href="">×</a>
      </div>
      <div class="alert-box alert round" data-alert="">
        This is an alert (div.alert-box.alert.round).
        <a class="close" href="">×</a>
      </div>
      <div class="alert-box secondary" data-alert="">
        This is a secondary alert (div.alert-box.secondary).
        <a class="close" href="">×</a>
      </div>
      <div style="height:30px;"></div>
      <p><a class="radius button" data-reveal-id="alert-boxes-modal" href="#">alert boxes code</a>
      <div data-reveal="" class="reveal-modal" id="alert-boxes-modal">
        <h2>Alert Boxes example code</h2>
        <pre><code class='html'>
&ltdiv class="alert-box radius" data-alert="">
  This is a standard alert (div.alert-box.radius).
  &lta class="close" href="">×&lt/a>
&lt/div>
&ltdiv class="alert-box success" data-alert="">
  This is a success alert (div.alert-box.success).
  &lta class="close" href="">×&lt/a>
&lt/div>
&ltdiv class="alert-box alert round" data-alert="">
  This is an alert (div.alert-box.alert.round).
  &lta class="close" href="">×&lt/a>
&lt/div>
&ltdiv class="alert-box secondary" data-alert="">
  This is a secondary alert (div.alert-box.secondary).
  &lta class="close" href="">×&lt/a>
&lt/div>
        </code></pre>
        <a class="close-reveal-modal">×</a>
      </div>
      <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/alert_boxes.html">Foundation Docs for Alert Boxes</a></h5>
      <hr>

      <!-- dropdown buttons -->
      <h4 id="dropdown-buttons">Dropdown Buttons</h4>
      <div style="height:30px;"></div>
      <ul data-dropdown-content="" class="f-dropdown" id="drop">
        <li><a href="#">This is a link</a></li>
        <li><a href="#">This is another</a></li>
        <li><a href="#">Yet another link</a></li>
      </ul>
      <p><a class="tiny button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Tiny Dropdown Button</a><br>
      <a class="small secondary radius button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Small Secondary Radius Dropdown Button</a><br>
      <a class="button alert round dropdown" data-dropdown="drop" href="#" aria-expanded="false">Button Alert Round Dropdown Button</a><br>
      <a class="large success button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Large Success Dropdown Button</a><br>
      <a class="large button dropdown expand" data-dropdown="drop" href="#" aria-expanded="false">Large Expanded Dropdown Button</a></p>
      <div style="height:30px;"></div>
      <p><a class="radius button" data-reveal-id="dropdown-buttons-modal" href="#">dropdown buttons code</a>
      <div data-reveal="" class="reveal-modal" id="dropdown-buttons-modal">
        <h2>Dropdown Buttons example code</h2>
        <pre><code class='html'>
&ltul data-dropdown-content="" class="f-dropdown" id="drop">
  &ltli>&lta href="#">This is a link&lt/a>&lt/li>
  &ltli>&lta href="#">This is another&lt/a>&lt/li>
  &ltli>&lta href="#">Yet another link&lt/a>&lt/li>
&lt/ul>
&ltp>
  &lta class="tiny button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Tiny Dropdown Button&lt/a>&ltbr>
  &lta class="small secondary radius button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Small Secondary Radius Dropdown Button&lt/a>&ltbr>
  &lta class="button alert round dropdown" data-dropdown="drop" href="#" aria-expanded="false">Button Alert Round Dropdown Button&lt/a>&ltbr>
  &lta class="large success button dropdown" data-dropdown="drop" href="#" aria-expanded="false">Large Success Dropdown Button&lt/a>&ltbr>
  &lta class="large button dropdown expand" data-dropdown="drop" href="#" aria-expanded="false">Large Expanded Dropdown Button&lt/a>
&lt/p>
        </code></pre>
        <a class="close-reveal-modal">×</a>
      </div>
      <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/dropdown_buttons.html">Foundation Docs for Dropdown Buttons</a></h5>
      <hr>

      <!-- reveal modals -->
      <h4 id="reveal">Reveal</h4>
      <div style="height:30px;"></div>
      <p><a class="radius button" data-reveal-id="firstModal" href="#">Example Modal…</a>
      <a class="radius button" data-reveal-id="videoModal" href="#">Example Video Modal…</a></p>
      <div data-reveal="" class="reveal-modal" id="firstModal">
        <h2>This is a modal.</h2>
        <p>Reveal makes these very easy to summon and dismiss. The close button is simply an anchor with a unicode character icon and a class of <code>close-reveal-modal</code>. Clicking anywhere outside the modal will also dismiss it.</p>
        <p>Finally, if your modal summons another Reveal modal, the plugin will handle that for you gracefully.</p>
        <p><a class="secondary button" data-reveal-id="secondModal" href="#">Second Modal…</a></p>
        <a class="close-reveal-modal">×</a>
      </div>
      <div data-reveal="" class="reveal-modal" id="secondModal">
        <h2>This is a second modal.</h2>
        <p>See? It just slides into place after the first modal. Very handy when you need subsequent dialogs, or when a modal option impacts or requires another decision.</p>
        <a class="close-reveal-modal">×</a>
      </div>
      <div data-reveal="" class="reveal-modal large" id="videoModal">
        <h2>This modal has video</h2>
        <div class="flex-video">
                <iframe height="315" frameborder="0" width="420" allowfullscreen="" src="https://www.youtube.com/embed/UMQTQhdizxI"></iframe>
        </div>
        <a class="close-reveal-modal">×</a>
      </div>
      <div style="height:30px;"></div>
      <p><a class="radius button" data-reveal-id="reveal-modal" href="#">reveal code</a>
      <div data-reveal="" class="reveal-modal" id="reveal-modal">
        <h2>Reveal example code</h2>
        <pre><code class='html'>
&ltp>&lta class="radius button" data-reveal-id="firstModal" href="#">Example Modal…&lt/a>
&lta class="radius button" data-reveal-id="videoModal" href="#">Example Video Modal…&lt/a>&lt/p>
&ltdiv data-reveal="" class="reveal-modal" id="firstModal">
  &lth2>This is a modal.&lt/h2>
  &ltp>Reveal makes these very easy to summon and dismiss. The close button is simply an anchor with a unicode character icon and a class of &ltcode>close-reveal-modal&lt/code>. Clicking anywhere outside the modal will also dismiss it.&lt/p>
  &ltp>Finally, if your modal summons another Reveal modal, the plugin will handle that for you gracefully.&lt/p>
  &ltp>&lta class="secondary button" data-reveal-id="secondModal" href="#">Second Modal…&lt/a>&lt/p>
  &lta class="close-reveal-modal">×&lt/a>
&lt/div>
&ltdiv data-reveal="" class="reveal-modal" id="secondModal">
  &lth2>This is a second modal.&lt/h2>
  &ltp>See? It just slides into place after the first modal. Very handy when you need subsequent dialogs, or when a modal option impacts or requires another decision.&lt/p>
  &lta class="close-reveal-modal">×&lt/a>
&lt/div>
&ltdiv data-reveal="" class="reveal-modal large" id="videoModal">
  &lth2>This modal has video&lt/h2>
  &ltdiv class="flex-video">
    &ltiframe height="315" frameborder="0" width="420" allowfullscreen="" src="//www.youtube.com/embed/aiBt44rrslw">&lt/iframe>
  &lt/div>
  &lta class="close-reveal-modal">×&lt/a>
&lt/div>
        </code></pre>
        <a class="close-reveal-modal">×</a>
      </div>
      <h4>Note: This component is not yet fully accessible. While it is usable via the keyboard, it has to be checked if additional ARIA attributes can enhance the component's accessibility.</h4>
      <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/reveal.html">Foundation Docs for Reveal Modals</a></h5>
      <hr>

      <!-- tabs -->
      <h4 id="tabs">Tabs</h4>
      <div style="height:30px;"></div>
      <ul class="tabs" data-tab>
        <li class="tab-title active"><a href="#panel1">Tab 1</a></li>
        <li class="tab-title"><a href="#panel2">Tab 2</a></li>
        <li class="tab-title"><a href="#panel3">Tab 3</a></li>
        <li class="tab-title"><a href="#panel4">Tab 4</a></li>
      </ul>
      <div class="tabs-content">
        <div class="content active" id="panel1">
          <p>This is the first panel of the basic tab example. You can place all sorts of content here including a grid.</p>
        </div>
        <div class="content" id="panel2">
          <p>This is the second panel of the basic tab example. This is the second panel of the basic tab example.</p>
        </div>
        <div class="content" id="panel3">
          <p>This is the third panel of the basic tab example. This is the third panel of the basic tab example.</p>
        </div>
        <div class="content" id="panel4">
          <p>This is the fourth panel of the basic tab example. This is the fourth panel of the basic tab example.</p>
        </div>
      </div>
        <p><a class="radius button" data-reveal-id="tabs-modal" href="#">tabs code</a>
        <div data-reveal="" class="reveal-modal" id="tabs-modal">
          <h2>Tabs example code</h2>
        <pre><code class='html'>
&ltul class="tabs" data-tab>
  &ltli class="tab-title active">&lta href="#panel1">Tab 1&lt/a>&lt/li>
  &ltli class="tab-title">&lta href="#panel2">Tab 2&lt/a>&lt/li>
  &ltli class="tab-title">&lta href="#panel3">Tab 3&lt/a>&lt/li>
  &ltli class="tab-title">&lta href="#panel4">Tab 4&lt/a>&lt/li>
&lt/ul>
&ltdiv class="tabs-content">
  &ltdiv class="content active" id="panel1">
    &ltp>This is the first panel of the basic tab example. You can place all sorts of content here including a grid.&lt/p>
  &lt/div>
  &ltdiv class="content" id="panel2">
    &ltp>This is the second panel of the basic tab example. This is the second panel of the basic tab example.&lt/p>
  &lt/div>
  &ltdiv class="content" id="panel3">
    &ltp>This is the third panel of the basic tab example. This is the third panel of the basic tab example.&lt/p>
  &lt/div>
  &ltdiv class="content" id="panel4">
    &ltp>This is the fourth panel of the basic tab example. This is the fourth panel of the basic tab example.&lt/p>
  &lt/div>
&lt/div>
        </code></pre>
        <a class="close-reveal-modal">×</a>
      </div>
      <h4>See <a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tabs.html#accessibility">documentation</a> for more information regarding accessibility.</h4>
      <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tabs.html">Foundation Docs for Tabs</a></h5>
      <hr>

      <!-- tooltips -->
      <h4 id="tooltips">Tooltips</h4>
      <div style="height:30px;"></div>
      <p>The tooltips can be positioned on the <span data-width="210" class="has-tip" data-tooltip="" data-selector="tooltip-iksllr5u0" aria-describedby="tooltip-iksllr5u0" title="bottom aligned">"tip-bottom"</span>, which is the default position, <span data-width="210" class="has-tip tip-top noradius" data-tooltip="" data-selector="tooltip-iksllr5u1" aria-describedby="tooltip-iksllr5u1" title="top aligned">"tip-top" (hehe)</span>, <span data-width="90" class="has-tip tip-left" data-tooltip="left" title="left aligned">"tip-left"</span>, or <span data-width="120" class="has-tip tip-right" data-tooltip="right" title="right aligned">"tip-right"</span> of the target element by adding the appropriate class to them. You can even add your own custom class to style each tip differently. On a small device, the tooltips are full width and bottom aligned.</p>
      <div style="height:30px;"></div>
      <p><a class="radius button" data-reveal-id="tooltip-modal" href="#">tooltip code</a>
      <div data-reveal="" class="reveal-modal" id="tooltip-modal">
        <h2>Tooltip example code</h2>
        <pre><code class='html'>
&ltp>The tooltips can be positioned on the &ltspan data-width="210" class="has-tip" data-tooltip="" data-selector="tooltip-iksllr5u0" aria-describedby="tooltip-iksllr5u0" title="bottom aligned">"tip-bottom"&lt/span>, which is the default position, &ltspan data-width="210" class="has-tip tip-top noradius" data-tooltip="" data-selector="tooltip-iksllr5u1" aria-describedby="tooltip-iksllr5u1" title="top aligned">"tip-top" (hehe)&lt/span>, &ltspan data-width="90" class="has-tip tip-left" data-tooltip="left" title="left aligned">"tip-left"&lt/span>, or &ltspan data-width="120" class="has-tip tip-right" data-tooltip="right" title="right aligned">"tip-right"&lt/span> of the target element by adding the appropriate class to them. You can even add your own custom class to style each tip differently. On a small device, the tooltips are full width and bottom aligned.&lt/p>
          </code></pre>
          <a class="close-reveal-modal">×</a>
        </div>
        <h4>See <a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tooltips.html#accessibility">documentation</a> for more information regarding accessibility.</h4>
        <h5><a target="_blank" href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tooltips.html">Foundation Docs for Tooltips</a></h5>
      </div>
    </div>
  </div>
</div>
  <?php if (file_exists($partial_footer)): require_once $partial_footer; endif;  ?>
</div>
<script>hljs.initHighlightingOnLoad();</script>
