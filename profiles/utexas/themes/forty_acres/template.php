<?php
/**
 * @file
 * Main template file for forty_acres theme.
 */

/**
 * Implements hook_html_head_alter().
 *
 * Remove some HTML head elements.
 */
function forty_acres_html_head_alter(&$head_elements) {
  // Strip the generator link.
  unset($head_elements['system_meta_generator']);

  // Unset the dafault favicon.
  foreach ($head_elements as $key => $element) {
    if (!empty($element['#attributes'])) {
      if (array_key_exists('href', $element['#attributes'])) {
        if (strpos($element['#attributes']['href'], 'misc/favicon.ico') > 0) {
          unset($head_elements[$key]);
        }
      }
    }
  }
}

/**
 * Theme override for theme_menu_link().
 */
function forty_acres_menu_link__menu_footer(array $variables) {
  // Grab the element (represents the <a> element) from the variables array.
  $element = $variables['element'];

  // Add classes attribute for the element.
  $element['#localized_options']['attributes']['class'] = array('helpful-link');

  // Create the menu link using the Drupal l function.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Return the link embedded in a list element.
  return '<li class="helpful-link-item" role="menuitem">' . $output . "</li>\n";
}

/**
 * Theme override for theme_menu_tree().
 */
function forty_acres_menu_tree__menu_footer($variables) {
  // Create variable for two-column layout on footer menu.
  $two_column_class = '';
  if (theme_get_setting('footer_menu_grid') == TRUE) {
    $two_column_class = 'large-block-grid-2';
  }
  // Add classes to the wrapper and return with the menu tree.
  return '<ul class="helpful-links ' . $two_column_class . '" role="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme override for theme_menu_link().
 */
function forty_acres_menu_link__menu_header(array $variables) {
  // Grab the element (represents the <a> element) from the variables array.
  $element = $variables['element'];

  // Add a class attribute for the element.
  $element['#localized_options']['attributes']['class'] = array('nav-link');

  // Create a list of classes to add to the link.
  $classes = array('nav-item');

  // Create the menu link using the Drupal l function.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Return the link embedded in a list element.
  return '<li class="' . implode(' ', $classes) . '" role="menuitem">' . $output . "</li>\n";
}

/**
 * Theme override for theme_menu_tree().
 */
function forty_acres_menu_tree__menu_header($variables) {
  // Add a class to the wrapper.
  return '<ul class="topnav-constituents" role="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Theme override for theme_breadcrumb().
 *
 * Insert themed breadcrumb page
 * navigation at top of the node content.
 *
 * Breadcrumb array looks like this:
 * Array ( [0] => Home [1] => Campus Life [2] => Living & Eating )
 *
 * $breadcrumb[1] should not have a link, since it is a landing page that does
 * not exist.
 */
function forty_acres_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $output = '';

    // Grab the count of the breadcrumb items.
    $total = count($breadcrumb);

    switch ($total) {
      case ($total > 2):
        // Build a new array and add the first breadcrumb.
        $trail = array();
        $trail[] = $breadcrumb[0];

        // Grab the position of the closing element.
        $pos = strpos($breadcrumb[2], '>');

        // Create a new link by combining the 1st and second breadcrumbs.
        if ($breadcrumb[2] != '') {
          $new_link = substr_replace($breadcrumb[2], strip_tags($breadcrumb[1]) . ' : ', $pos + 1, 0);
        }
        else {
          $new_link = $breadcrumb[1];
        }

        // Add the new link to the array.
        $trail[] = $new_link;

        // Add the remaining breadcrumbs.
        for ($i = 3; $i < $total; $i++) {
          $trail[] = $breadcrumb[$i];
        }

        // Append the current page title.
        $trail[] = drupal_get_title();
        $breadcrumb = $trail;

        break;

      case ($total == 2):
        // Remove any tags from the last breadcrumb.
        $last_element = strip_tags(array_pop($breadcrumb));

        // Combine the text of the last breadcrumb and the current page title.
        $breadcrumb[] = $last_element . ' : ' . drupal_get_title();

        break;

      default:
        // Combine the text of the last breadcrumb and the current page title.
        $breadcrumb[] = drupal_get_title();

        break;
    }

    // Make the list attribute-able.
    foreach ($breadcrumb as $key => &$crumb) {
      $crumb = array('data' => $crumb);
      if ($key == count($breadcrumb) - 1) {
        $crumb['class'] = array('current');
      }
    }

    return $output . theme('item_list', array(
      'items' => $breadcrumb,
      'type' => 'ul',
      'title' => NULL,
      'attributes' => array(
        'class' => array('breadcrumbs'),
      ),
    ));
  }
}

/**
 * Theme override for theme_item_list().
 */
function forty_acres_item_list($variables) {
  $items = $variables['items'];
  $title = $variables['title'];
  $type = $variables['type'];
  $attributes = $variables['attributes'];

  // Only output the list container and title, if there are any list items.
  // Check to see whether the block title exists before adding a header.
  // Empty headers are not semantic and present accessibility challenges.
  $output = '';
  if (isset($title) && $title !== '') {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    // Open the list.
    $output .= "<$type" . drupal_attributes($attributes) . '>';

    // Figure out how many items we have.
    $num_items = count($items);
    $i = 0;

    // Loop through passed items.
    foreach ($items as $item) {
      $attributes = array();
      $children = array();
      $data = '';
      $i++;

      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }

      // We have children, so render the nested list.
      if (count($children) > 0) {
        $data .= theme_item_list(array(
          'items' => $children,
          'title' => NULL,
          'type' => $type,
          'attributes' => $attributes,
        ));
      }

      // Add some classes to the element, as necessary.
      if ($i == 1) {
        $attributes['class'][] = 'first';
      }
      if ($i == $num_items) {
        $attributes['class'][] = 'last';
      }

      // Attach the output to the list item.
      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>\n";
    }

    // Close the list.
    $output .= "</$type>";
  }

  return $output;
}

/**
 * Implements template_preprocess_field_collection_view().
 *
 * Used to add a theme hook suggestion for further templating.
 *
 * @see template_preprocess_field_collection_view()
 */
function forty_acres_preprocess_field_collection_view(&$variables) {
  // Remove the links on the individual field collection.
  unset($variables['element']['links']);

  // Add a custom template file for field collection views.
  $variables['theme_hook_suggestions'][] = 'field_collection_view';
}

/**
 * Template preprocessor for theme('html').
 *
 * Attaches new metatags for the different favicons and touch icons.
 *
 * @see drupal_add_html_head()
 */
function forty_acres_preprocess_html(&$variables) {
  // Attach favicons to the page.
  $path = base_path() . drupal_get_path('theme', 'forty_acres') . '/img/favicon/';
  $active_theme_path = base_path() . drupal_get_path('theme', $GLOBALS['theme']);
  $apple_icons = array(
    '',
    '57x57',
    '60x60',
    '72x72',
    '76x76',
    '114x114',
    '120x120',
    '144x144',
    '152x152',
    '180x180',
  );
  foreach ($apple_icons as $size) {
    if ($size) {
      // There's a size, so attach that as an extension.
      drupal_add_html_head(array(
        '#tag' => 'link',
        '#attributes' => array(
          'rel' => 'apple-touch-icon',
          'sizes' => $size,
          'href' => $path . 'apple-touch-icon-' . $size . '.png',
        ),
      ), 'apple-touch-' . $size);
    }
    else {
      // This is the default icon, so attach that.
      drupal_add_html_head(array(
        '#tag' => 'link',
        '#attributes' => array(
          'rel' => 'apple-touch-icon',
          'href' => $path . 'apple-touch-icon.png',
        ),
      ), 'apple-touch');
    }
  }

  // Set the IE 6-9 favicon. IE10 defaults to /favicon.ico.
  drupal_add_html_head(array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'shortcut icon',
      'href' => $active_theme_path . 'favicon.ico',
    ),
    '#prefix' => '<!--[if IE]>',
    '#suffix' => '<![endif]-->',
  ), 'ie-favicon');

  // Set application tiles.
  drupal_add_html_head(array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileColor',
      'content' => '#bf5700',
    ),
  ), 'msapplication-TileColor');
  drupal_add_html_head(array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'msapplication-TileImage',
      'content' => $path . 'apple-touch-icon-144x144.png',
    ),
  ), 'msapplication-TileImage');

  // Add viewport.
  drupal_add_html_head(array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no',
    ),
  ), 'meta-viewport');

  // Add a custom title for Apple homescreen users.
  drupal_add_html_head(array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'apple-mobile-web-app-title',
      'content' => t('UT Austin'),
    ),
  ), 'apple-mobile-web-app-title');

  // Append | to $head title if not on the front page.
  if (!drupal_is_front_page()) {
    $variables['head_title'] = $variables['head_title'] . ' |';
  }
}

/**
 * Preprocessor for page.tpl.php.
 *
 * Adds in new stylesheets for base, core home,
 * core pages. Also handles adding new javascript, and setting page theme
 * suggestions based on the field_template value. It also throws the menus into
 * a variable on the $page array, and defines the partials directory.
 *
 * Finally, it associates the 404 and 403 pages with their theme suggestions.
 */
function forty_acres_preprocess_page(&$variables, $hook) {

  $path = drupal_get_path('theme', 'forty_acres');

  // Add forty_acres_pages.css if Page Builder is enabled.
  if (module_exists('utexas_page_builder')) {
    drupal_add_css($path . '/css/forty_acres_pages.css');
  };

  // Modernizr is important to prevent flash of unstyled content, so put that
  // in the header.
  drupal_add_js($path . '/js/modernizr.min.js', array(
    'scope' => 'head_scripts',
    'weight' => -1,
  ));

  // Add all secondary scripts to the footer for faster page loading.
  drupal_add_js($path . '/js/jquery.plugins.min.js', array(
    'scope' => 'foot_scripts',
    'weight' => 0,
  ));
  drupal_add_js($path . '/js/foundation.min.js', array(
    'scope' => 'foot_scripts',
    'weight' => 0,
  ));
  drupal_add_js($path . '/js/application.min.js', array(
    'scope' => 'foot_scripts',
    'weight' => 5,
  ));

  // Add CSS for search pages.
  if ((arg(0) == 'search') || (arg(0) == 'search-results')) {
    drupal_add_css($path . '/css/search_page.css', array(
      'group' => CSS_DEFAULT,
      'every_page' => FALSE,
      'media' => 'all',
    ));
  }

  // Get easily accessible menus into the page variable.
  $utexas_main_menu = module_invoke('utexas_menu', 'block_view', 'utexas_main_menu');
  $variables['page']['menus'] = array(
    'footer' => menu_tree('menu-footer'),
    'header' => menu_tree('menu-header'),
    'core_main' => $utexas_main_menu['content'],
  );

  // Sets partial variables for use on the template.tpl.php pages.
  $partials_list = array(
    'breadcrumbs' => 'breadcrumbs.tpl.php',
    'footer' => 'footer.tpl.php',
    'header' => 'header.tpl.php',
    'page_top' => 'page-top.tpl.php',
    'search_result' => 'search-result.tpl.php',
    'search_results' => 'search-results.tpl.php',
  );
  $current_theme_path = drupal_get_path('theme', $GLOBALS['theme']);
  $current_templates = array();
  if ($GLOBALS['theme'] != 'forty_acres') {
    // Returns array of the tpl.php files in the subtheme's templates directory.
    $current_templates = file_scan_directory($current_theme_path . '/templates', '/\.tpl.php/', $options = array('key' => 'filename'));
  }
  foreach ($partials_list as $name => $file_name) {
    // If we are using a subtheme and a partial is defined anywhere in the
    // templates directory, set the partial variable to that template.
    $variables['partial_' . $name] = (($GLOBALS['theme'] != 'forty_acres') && (isset($current_templates[$file_name]))) ? $current_templates[$file_name]->uri : drupal_get_path('theme', 'forty_acres') . '/templates/partials/' . $file_name;
  }

  // Load foundation js files selected in theme settings.
  $forty_acres_path = drupal_get_path('theme', 'forty_acres');
  $extra_libraries = theme_get_setting('foundation_files') ? theme_get_setting('foundation_files') : array();
  foreach ($extra_libraries as $library => $value) {
    if ($library === $value) {
      if (file_exists($forty_acres_path . '/js/foundation.' . $library . '.js')) {
        drupal_add_js($forty_acres_path . '/js/foundation.' . $library . '.js', array(
          'scope' => 'foot_scripts',
          'weight' => 4,
        ));
      }
      if (file_exists($forty_acres_path . '/css/foundation.' . $library . '.css')) {
        drupal_add_css($forty_acres_path . '/css/foundation.' . $library . '.css');
      }
    }
  }
  $foundation_libraries = array(
    'abide',
    'accordion',
    'alert',
    'dropdown',
    'reveal',
    'tab',
    'tooltip',
  );
  if (arg(0) == 'demo' && arg(1) == 'foundation-extra-libraries' && drupal_valid_path('demo/foundation-extra-libraries')) {
    foreach ($foundation_libraries as $library) {
      if (file_exists($forty_acres_path . '/js/foundation.' . $library . '.js')) {
        drupal_add_js($forty_acres_path . '/js/foundation.' . $library . '.js', array(
          'scope' => 'foot_scripts',
          'weight' => 4,
        ));
      }
      if (file_exists($forty_acres_path . '/css/foundation.' . $library . '.css')) {
        drupal_add_css($forty_acres_path . '/css/foundation.' . $library . '.css');
      }
    }
  }

  // Figure out if we're on a 403 or 404 page.
  if ($header = drupal_get_http_header('status')) {
    switch ($header) {
      case '403 Forbidden':
        // Set the page template for 403 page.
        $variables['theme_hook_suggestions'][] = 'page__page_403';
        $variables['contact_403_checkbox'] = theme_get_setting('contact_403_checkbox');
        $variables['contact_403'] = check_markup(theme_get_setting('contact_403'), 'filtered_html');
        break;

      case '404 Not Found':
      default:
        // Set the page template for 404 page.
        $variables['theme_hook_suggestions'][] = 'page__page_404';
        $variables['contact_404_checkbox'] = theme_get_setting('contact_404_checkbox');
        $variables['contact_404'] = check_markup(theme_get_setting('contact_404'), 'filtered_html');
        break;
    }
  }

  // Random off-chance that the user reaches page/404 or page/403, return
  // content for those as well.
  if (arg(0) == 'page') {
    if (arg(1) == '404') {
      $variables['theme_hook_suggestions'][] = 'page__page_404';
    }
    if (arg(1) == '403') {
      $variables['theme_hook_suggestions'][] = 'page__page_403';
    }
  }
  if (arg(0) == 'search-results') {
    $variables['theme_hook_suggestions'][] = 'page__search';
  }

  $variables['newsletter_display'] = theme_get_setting('newsletter_url');
  $variables['footer_text'] = check_markup(theme_get_setting('footer_text_area'), 'filtered_html');
  $variables['display_social'] = theme_get_setting('display_social_icons');
  $variables['display_header_menu'] = theme_get_setting('secondary_menu');
  $variables['newsletter_exists'] = theme_get_setting('newsletter_exists');
  $variables['newsletter_url'] = check_url(theme_get_setting('newsletter_url'));
  $variables['parent_link_title'] = check_plain(theme_get_setting('parent_link_title'));
  $variables['parent_link'] = theme_get_setting('parent_link');
  $variables['parent_entity'] = FALSE;
  if ($variables['parent_link_title'] != '' && $variables['parent_link'] != '') {
    $variables['parent_entity'] = l($variables['parent_link_title'], $variables['parent_link'], array(
      'html' => TRUE,
      'external' => TRUE,
      'attributes' => array('class' => 'parent_link')));
  }

  if (variable_get('utexas_google_tag_manager_gtm_verification', '') != '') {
    // Add Google verification metatag to all pages.
    $element = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'google-site-verification',
        'content' => variable_get('utexas_google_tag_manager_gtm_verification', ''),
      ),
    );
    drupal_add_html_head($element, 'google-site-verification');
  }

  // Pass variable for page.tpl.php to size the content region.
  $variables['size_content_region'] = 'medium-12';
  if ($variables['page']['sidebar_second']) {
    $variables['size_content_region'] = 'medium-8 large-9';
  }

  // Add css if user selects Tall logo option in theme settings.
  $variables['logo_height'] = theme_get_setting('logo_height');

  // Variable to control size of related links in footer.
  $variables['related_links_class'] = 'medium-4';
  $variables['related_links_block_grid_class'] = 'small-block-grid-2';
  if (empty($variables['page']['menus']['footer'])) {
    $variables['related_links_class'] = 'medium-8';
    $variables['related_links_block_grid_class'] = 'small-block-grid-3';
    drupal_add_css('.footer-theme2 .footer-primary {border-right: 1px solid #cbcbcb!important;}', 'inline');
  }
  $variables['display_search'] = TRUE;
  if (theme_get_setting('utexas_searchbar_theme_settings') == 'no') {
    $variables['display_search'] = FALSE;
    drupal_add_css('#main-nav {margin: 0;}.container-nav-phase2 .nav-item:first-child{border-top: none!important;}', 'inline');
  }

  $variables['display_breadcrumb'] = 1;
  if (isset($variables['node'])) {
    if ($variables['node']->show_breadcrumb !== NULL) {
      $variables['display_breadcrumb'] = $variables['node']->show_breadcrumb;
    }
    else {
      $default_breadcrumb = theme_get_setting('utexas_' . $variables['node']->type . '_breadcrumb');
      if ($default_breadcrumb !== NULL) {
        $variables['display_breadcrumb'] = $default_breadcrumb;
      }
    }
  }

  // Decrease padding if user selects two-column footer menu.
  if (theme_get_setting('footer_menu_grid') == TRUE) {
    drupal_add_css('@media only screen and (min-width:64.063em) {.footer-theme2 .footer-secondary{padding-left:5%!important;padding-right:5%!important;}}', 'inline');
  }
}

/**
 * Process variables for html.tpl.php. Adds header and footer scripts.
 */
function forty_acres_process_html(&$variables) {
  // Separate scripts into head_scripts and foot_scripts.
  $variables['head_scripts'] = drupal_get_js('head_scripts');
  $variables['foot_scripts'] = drupal_get_js('foot_scripts');
}

/**
 * Theme override for theme_pager().
 */
function forty_acres_pager(&$variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  $quantity = $variables['quantity'];
  global $pager_page_array, $pager_total;

  // Calculate various markers within this pager piece:
  // Middle is used to "center" pages around the current page.
  $pager_middle = ceil($quantity / 2);
  $pager_current = $pager_page_array[$element] + 1;
  $pager_first = $pager_current - $pager_middle + 1;
  $pager_last = $pager_current + $quantity - $pager_middle;
  $pager_max = $pager_total[$element];
  // End of marker calculations.

  // Prepare for generation loop.
  $i = $pager_first;
  if ($pager_last > $pager_max) {
    // Adjust "center" if at end of query.
    $i = $i + ($pager_max - $pager_last);
    $pager_last = $pager_max;
  }
  if ($i <= 0) {
    // Adjust "center" if at start of query.
    $pager_last = $pager_last + (1 - $i);
    $i = 1;
  }
  // End of generation loop preparation.

  $li_first = theme(
    'pager_first', array(
      'text' => (isset($tags[0]) ? $tags[0] : t('« first')
      ),
      'element' => $element,
      'parameters' => $parameters)
  );
  $li_previous = theme(
    'pager_previous', array(
      'text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')
      ),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters)
  );
  $li_next = theme(
    'pager_next', array(
      'text' => (isset($tags[3]) ? $tags[3] : t('next ›')
      ),
      'element' => $element,
      'interval' => 1,
      'parameters' => $parameters)
  );
  $li_last = theme(
    'pager_last', array(
      'text' => (isset($tags[4]) ? $tags[4] : t('last »')
      ),
      'element' => $element,
      'parameters' => $parameters)
  );

  if ($pager_total[$element] > 1) {
    if ($li_first) {
      $items[] = array(
        'class' => array(),
        'data' => $li_first,
      );
    }
    if ($li_previous) {
      $items[] = array(
        'class' => array(),
        'data' => $li_previous,
      );
    }

    // When there is more than one page, create the pager list.
    if ($i != $pager_max) {
      if ($i > 1) {
        $items[] = array(
          'class' => array('unavailable'),
          'data' => '&hellip;',
        );
      }
      // Now generate the actual pager piece.
      for (; $i <= $pager_last && $i <= $pager_max; $i++) {
        if ($i < $pager_current) {
          $items[] = array(
            'class' => array(),
            'data' => theme(
              'pager_previous', array(
                'text' => $i,
                'element' => $element,
                'interval' => ($pager_current - $i),
                'parameters' => $parameters,
              )
            ),
          );
        }
        if ($i == $pager_current) {
          $items[] = array(
            'class' => array('current'),
            'data' => '<a href="#">' . $i . '</a>',
          );
        }
        if ($i > $pager_current) {
          $items[] = array(
            'class' => array(),
            'data' => theme(
              'pager_next', array(
                'text' => $i,
                'element' => $element,
                'interval' => ($i - $pager_current),
                'parameters' => $parameters,
              )
            ),
          );
        }
      }
      if ($i < $pager_max) {
        $items[] = array(
          'class' => array('unavailable'),
          'data' => '&hellip;',
        );
      }
    }
    // End generation.
    if ($li_next) {
      $items[] = array(
        'class' => array(),
        'data' => $li_next,
      );
    }
    if ($li_last) {
      $items[] = array(
        'class' => array(),
        'data' => $li_last,
      );
    }

    // Return the generated list.
    $item_list = theme('item_list', array(
      'items' => $items,
      'type' => 'ul',
      'title' => NULL,
      'attributes' => array('class' => array('pagination')),
    ));
    return '<div class="pagination-centered">' . $item_list . '</div>';
  }
}
