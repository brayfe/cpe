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

  // Strip the default favicon.
  unset($head_elements['drupal_add_html_head_link:shortcut icon:http://forty_acres.dev/misc/favicon.ico']);

  // Strip the RSS link.
  unset($head_elements['drupal_add_html_head_link:alternate:http://forty_acres.dev/rss.xml']);

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
 * Theme override for menu links for the core helpful links menu.
 */
function forty_acres_menu_link__menu_core_helpful_links(array $variables) {
  // Grab the element (represents the <a> element) from the variables array.
  $element = $variables['element'];

  // Add classes attribute for the element.
  $element['#localized_options']['attributes']['class'] = array('cta-link', 'sans');

  // Create the menu link using the Drupal l function.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Return the link embedded in a list element.
  return '<li>' . $output . "</li>\n";
}

/**
 * Theme override for the menu tree for the core helpful links menu.
 */
function forty_acres_menu_tree__menu_core_helpful_links($variables) {
  // We don't want a wrapper for this menu, so just return the tree.
  return '<ul>' . $variables['tree'] . '</ul>';
}

/**
 * Theme override for theme_menu_link().
 */
function forty_acres_menu_link__menu_directory(array $variables) {
  // Grab the element (represents the <a> element) from the variables array.
  $element = $variables['element'];

  // Add a class attribute for the element.
  $element['#localized_options']['attributes']['class'] = array('nav-link');

  // Grab the position.
  $position = $element['#attributes']['class'][0];

  // Set class based on the position.
  switch ($position) {
    case 'first':
      $link_class = 'first';
      break;

    case 'last':
      $link_class = 'last';
      break;

    case 'leaf':
      $link_class = 'mid';
      break;

    default:
      $link_class = '';
      break;
  }

  // Create the menu link using the Drupal l function.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Return the link embedded in a list element with the the set list item
  // class.
  return '<li class="nav-item nav-item-info ' . $link_class . '" role="menuitem">' . $output . "</li>\n";
}

/**
 * Theme override for theme_menu_tree().
 */
function forty_acres_menu_tree__menu_directory($variables) {
  // We don't need a wrapper for this menu, so just return the tree.
  return $variables['tree'];
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
  // Add classes to the wrapper and return with the menu tree.
  return '<ul class="helpful-links" role="menu">' . $variables['tree'] . '</ul>';
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
 * Theme override for theme_menu_link().
 */
function forty_acres_menu_link__menu_secondary_navigation(array $variables) {
  // Grab the element (represents the <a> element) from the variables array.
  $element = $variables['element'];

  // Add classes attribute for the element.
  $element['#localized_options']['attributes']['class'] = array(
    'nav-link',
    'nav-link-button',
  );

  // Create the menu link using the Drupal l function.
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  // Return the link embedded in a list element.
  return '<li class="nav-item nav-item-button show-for-large-up" role="menuitem">' . $output . "</li>\n";
}

/**
 * Theme override for theme_menu_tree().
 */
function forty_acres_menu_tree__menu_secondary_navigation($variables) {
  // We don't want a wrapper for this menu so just return the tree.
  return $variables['tree'];
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
        $new_link = substr_replace($breadcrumb[2], strip_tags($breadcrumb[1]) . ' : ', $pos + 1, 0);

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
 * Implements template_preprocess_block().
 *
 * @todo ITS to override twitter component on this page after writing the new
 *   Twitter feed module.
 */
function forty_acres_preprocess_block(&$variables) {
  // Custom override for twitter block.
  // @todo ITS to revise this section, as needed.
  if ($variables['block']->module == 'forty_acres_home_twitter') {
    $classes = array_diff($variables['classes_array'], array('sidebar-default-style'));
    $classes[] = 'sidebar-twitter-style';
    $variables['classes_array'] = array_values($classes);
  }
}

/**
 * The name of the field collection item entity.
 */
define('FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE', 'field_collection_item');

/**
 * Implements template_preprocess_entity().
 *
 * We're wanting to grab all of the
 * fields per entity to expose as a simple value in a
 * field-collection-item.tpl.php template.
 *
 * @see template_preprocess_entity()
 * @see field-collection-item.tpl.php
 */
function forty_acres_preprocess_entity(&$variables) {
  // Add in variables for the defined field collections.
  if ($variables['entity_type'] == FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE) {
    $collection = $variables[FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE];

    // Get the field names.
    $field_info = field_info_instances(FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE, $collection->field_name);
    $fields = array_keys($field_info);
    $temp = array();

    // Iterate over the fields.
    foreach ($fields as $field) {
      // Grab the items of the field.
      $items = field_get_items(FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE, $collection, $field);
      $value = array();
      $view  = $field_info[$field]['display']['default'];

      // Only continue if there are items stored in the field.
      if ($items) {
        // Throw the items into a sub array.
        foreach ($items as $item) {
          // Custom validation.
          switch ($field) {
            // Display the markup for embed codes.
            case 'field_embed_code':
              $value[] = check_markup($item['value'], 'embeds');
              break;

            // Pass in the markup for the photo.
            case 'field_photo':
              // Grab the alt tag.
              $entity = file_load($item['fid']);
              $alt_tag = field_get_items('file', $entity, 'field_alt_tag');
              if ($alt_tag) {
                $alt_tag = field_view_value('file', $entity, 'field_alt_tag', $alt_tag[0]);
                $alt_tag = drupal_render($alt_tag);
              }

              // Grab the photo credit.
              $credit = field_get_items('file', $entity, 'field_photo_credit');
              if ($credit) {
                $credit = field_view_value('file', $entity, 'field_photo_credit', $credit[0]);
                $credit = drupal_render($credit);
              }

              // Check the uri.
              if ($field_info[$field]['settings']['file_directory'] == 'photo-content-area') {
                $info = image_get_info($entity->uri);
                $image = theme('image_style', array(
                  'style_name' => 'photo_content_area_image',
                  'path' => $entity->uri,
                  'width' => $info['width'],
                  'height' => $info['height'],
                  'alt' => $alt_tag,
                ));
              }
              elseif ($field_info[$field]['settings']['file_directory'] == 'hero-photos') {
                $info = image_get_info($entity->uri);
                $image = theme('image_style', array(
                  'style_name' => 'hero_photo_image',
                  'path' => $entity->uri,
                  'width' => $info['width'],
                  'height' => $info['height'],
                  'alt' => $alt_tag,
                ));
              }
              else {
                $image = theme('image', array(
                  'path' => $entity->uri,
                  'alt' => $alt_tag ? $alt_tag : NULL,
                ));
              }

              // Build the image.
              $value[] = array(
                'image' => array(
                  '#markup' => $image,
                  '#access' => TRUE,
                ),
                'credit' => array(
                  '#markup' => $credit,
                  '#access' => TRUE,
                ),
              );

              break;

            case 'field_date':
              // If we're setting a format type, reformat to strip out invalid
              // RDF tags.
              if (isset($view['settings']['format_type'])) {
                $format = $view['settings']['format_type'];

                // Attach the value.
                $value[] = array(
                  '#markup' => '<time datetime="' . $item['value'] . '">' . format_date(strtotime($item['value']), $format) . '</time>',
                  '#access' => field_access('view', $field_info[$field], 'node'),
                );
              }
              else {
                // Use a default viewer.
                $value[] = field_view_value(FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE, $collection, $field, $item, $view);
              }
              break;

            // Display the default view for the field type.
            default:
              $value[] = field_view_value(FORTY_ACRES_FIELD_COLLECTION_ITEM_ENTITY_TYPE, $collection, $field, $item, $view);
              break;
          }
        }
      }

      // Associate for the field.
      $temp[$field] = $value;
    }

    // Assign back to the array.
    $variables['values'] = $temp;
  }
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

  // Attach favicon.
  drupal_add_html_head(array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'icon',
      'href' => $path . 'favicon.ico',
    ),
  ), 'favicon-png');

  // Set the IE 6-9 favicon. IE10 defaults to /favicon.ico.
  drupal_add_html_head(array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'shortcut icon',
      'href' => $path . 'favicon.ico',
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

  // Get easily accessible menus into the page variable.
  $utexas_main_menu = module_invoke('utexas_menu', 'block_view', 'utexas_main_menu');
  $variables['page']['menus'] = array(
    'core_directory' => menu_tree('menu-directory'),
    'footer' => menu_tree('menu-footer'),
    'header' => menu_tree('menu-header'),
    'core_secondary' => menu_tree('menu-secondary-navigation'),
    'core_main' => $utexas_main_menu['content'],
    'core_helpful_links' => menu_tree('menu-core-helpful-links'),
  );

  // Sets partial variables for use on the template.tpl.php pages.
  $partials_list = array(
    'breadcrumbs' => 'breadcrumbs.tpl.php',
    'footer' => 'footer.tpl.php',
    'header' => 'header.tpl.php',
    'page_top' => 'page-top.tpl.php',
    'search_result'=> 'search-result.tpl.php',
    'search_results' => 'search-results.tpl.php',
  );
  $current_theme_path = drupal_get_path('theme', $GLOBALS['theme']);
  $current_templates = array();
  if ($GLOBALS['theme'] != 'forty_acres') {
    // Returns array of the tpl.php files in the subtheme's templates directory.
    $current_templates = file_scan_directory($current_theme_path . '/templates', '/\.tpl.php/', $options = array('key' => 'filename'));
  }
  foreach ($partials_list as $name => $file_name) {
    // If we are using a subtheme and a partial is defined anywhere in the templates directory, set the partial variable to that template.
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
  $foundation_libraries = array('abide', 'accordion', 'alert', 'dropdown', 'reveal', 'tab', 'tooltip');
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
        break;

      case '404 Not Found':
      default:
        // Set the page template for 404 page.
        $variables['theme_hook_suggestions'][] = 'page__page_404';
        break;
    }
  }
  // Building the 404 drupal search form.
  $search_form = drupal_get_form('search_block_form');
  $form_build_id = '';
  $form_token = '';
  if (!empty($search_form['form_build_id']['#value'])) {
    $form_build_id = $search_form['form_build_id']['#value'];
  }
  if (!empty($search_form['form_token']['#default_value'])) {
    $form_token = $search_form['form_token']['#default_value'];
  }
  $variables['drupal_search'] = "
  <label for='search-desktop' class='hiddenText'>Search UT Austin News</label>
  <form action='' method='post' id='search-block-form--2' accept-charset='UTF-8'>
    <input title='Enter the terms you wish to search for.'' type='text' name='search_block_form' placeholder='Search' value='' size='15' maxlength='128' id='search-desktop' class='search-page-input'>
    <button class='nav-search-button'><span class='hiddenText'>Search</span><span class='icon-search'></span></button>
    <input type='hidden' name='form_build_id' value=" . $form_build_id . ">
    <input type='hidden' name='form_token' value=" . $form_token . ">
    <input type='hidden' name='form_id' value='search_block_form'>
  </form>";

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

  $variables['newsletter_display'] = theme_get_setting('newsletter_url');
  $variables['footer_text'] = check_markup(theme_get_setting('footer_text_area'), 'filtered_html');
  $variables['display_social'] = theme_get_setting('display_social_icons');
  $variables['display_header_menu'] = theme_get_setting('secondary_menu');
  $variables['newsletter_exists'] = theme_get_setting('newsletter_exists');
  $variables['newsletter_url'] = check_url(theme_get_setting('newsletter_url'));
  $variables['parent_link_title'] = theme_get_setting('parent_link_title');
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
 * Implements hook_form_alter().
 */
function forty_acres_form_alter(&$form, &$form_state, $form_id) {
  if ($form_id == 'search_form') {
    // Hide the default search form in favor of our custom one; see $search_form
    $form['#access'] = FALSE;
  }
}

/**
 * @file
 * Style overrides for pagers.
 */

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
