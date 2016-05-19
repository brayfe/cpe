<?php
/**
 * @file
 * Theme settings which allow for configuration settings through the theme UI.
 */

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function forty_acres_form_system_theme_settings_alter(&$form, &$form_state) {

  // Disable the Toggle Display section.
  unset($form['theme_settings']);

  // Main navigation settings.
  $form['utexas_main_nav_theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Header settings'),
  );
  $form['utexas_main_nav_theme_settings']['logo_height'] = array(
    '#type' => 'radios',
    '#title' => 'Logo Height',
    '#description' => "Most UT Austin logos will work with the 'short' option, but logos that are taller or wider than normal may need to use the 'tall' setting in order to not appear too small.",
    '#options' => array(
      'short_logo' => t('Short'),
      'tall_logo' => t('Tall'),
    ),
    '#default_value' => theme_get_setting('logo_height'),
  );
  $form['utexas_main_nav_theme_settings']['parent_link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent Entity Name'),
    '#description' => t("OPTIONAL - Enter the name of the site's parent college or office, if providing a link to the parent unit in the orange University Brand Bar. This will appear as a link at the left of the Brand Bar."),
    '#default_value' => theme_get_setting('parent_link_title'),
  );
  $form['utexas_main_nav_theme_settings']['parent_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Parent Entity Website'),
    '#description' => t("If providing a parent entity link in the brand bar above, enter the URL of the site's parent college or office. This is required if you have entered a Parent Entity Name."),
    '#default_value' => theme_get_setting('parent_link'),
    '#maxlength' => 256,
    '#attributes'    => array(
      'placeholder' => t('http://'),
    ),
    '#element_validate' => array('_forty_acres_parent_link_validate'),
  );

  /**
   * Helper function to provide validation on Parent Entity Website.
   */
  function _forty_acres_parent_link_validate($element, &$form_state) {
    if ($form_state['values']['parent_link_title'] != '' && empty($element['#value'])) {
      form_error($element, t('Please enter a link for the Parent Entity Website.  A link is required if you have entered a Parent Entity Name.'));
    }
    if ($element['#value'] != '' && filter_var($element['#value'], FILTER_VALIDATE_URL) === FALSE) {
      form_error($element, t('Please enter a valid link for the Parent Entity Website.'));
    }
  }
  $form['utexas_main_nav_theme_settings']['secondary_menu'] = array(
    '#type' => 'radios',
    '#title' => t('Which option should be displayed in the secondary menu region (directly to the left of the search form)?'),
    '#options' => array(
      'no_menu' => t('No menu or links'),
      'header_menu' => t('Header menu: <a href="/admin/structure/menu/manage/menu-header">Configure header menu here.</a>'),
    ),
  );
  if (module_exists('utexas_social_accounts')) {
    $form['utexas_main_nav_theme_settings']['secondary_menu']['#options']['social_accounts'] = t('Social accounts: <a href="/admin/config/utexas/utexas-social-accounts">Configure social accounts here.</a>');
    $form['utexas_main_nav_theme_settings']['secondary_menu']['#default_value'] = theme_get_setting('secondary_menu');
  }
  else {
    $form['utexas_main_nav_theme_settings']['secondary_menu']['#default_value'] = (theme_get_setting('secondary_menu') == 'social_accounts') ? 'header_menu' : theme_get_setting('secondary_menu');
  }

  $form['utexas_main_nav_theme_settings']['utexas_searchbar_theme_settings'] = array(
    '#type' => 'radios',
    '#title' => t('Search bar display options'),
    '#options' => array(
      'yes' => t('Display search bar'),
      'no' => t('Hide search bar'),
    ),
    '#default_value' => theme_get_setting('utexas_searchbar_theme_settings') ? theme_get_setting('utexas_searchbar_theme_settings') : 'yes',
  );
  if (!module_exists('utexas_google_cse')) {
    $form['utexas_main_nav_theme_settings']['utexas_searchbar_theme_settings']['display_search'] = array(
      '#markup' => t("<div class='messages warning'>The UTexas Google CSE module is currently disabled which prevents the search bar from being displayed on your site.  Please contact a site administrator to resolve this.</div>"),
    );
  }

  // Footer settings.
  $form['utexas_footer_theme_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Footer settings'),
  );
  $form['utexas_footer_theme_settings']['footer_text_area'] = array(
    '#type' => 'textarea',
    '#title' => t('OPTIONAL - Enter text to be displayed in a block in the left-most region of the footer.'),
    '#description' => t("For example, this block can be used for contact information for the site's office/department."),
    '#default_value' => theme_get_setting('footer_text_area'),
  );
  if (module_exists('utexas_social_accounts')) {
    $form['utexas_footer_theme_settings']['display_social_icons'] = array(
      '#type' => 'checkbox',
      '#title' => t('Would you like to display social accounts in the footer?'),
      '#description' => t('<a href="/admin/config/utexas/utexas-social-accounts">Configure social accounts here.</a>'),
      '#default_value' => theme_get_setting('display_social_icons'),
    );
  }
  $form['utexas_footer_theme_settings']['newsletter_exists'] = array(
    '#type' => 'checkbox',
    '#title' => t('Would you like to provide a link to a newsletter subscription form in the footer?'),
    '#default_value' => theme_get_setting('newsletter_exists'),
  );
  $form['utexas_footer_theme_settings']['newsletter_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'invisible' => array(
        'input[name="newsletter_exists"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['utexas_footer_theme_settings']['newsletter_container']['newsletter_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the URL of your newsletter subscription form.'),
    '#description' => t("The label for this link will be 'Subscribe to our newsletter'"),
    '#default_value' => theme_get_setting('newsletter_url'),
    '#maxlength' => 256,
  );
  // Option to load supplemental foundation javascript files.
  $form['utexas_extra_foundation_js'] = array(
    '#type' => 'fieldset',
    '#title' => t('Supplemental Foundation Elements'),
  );
  $base_url = $GLOBALS['base_url'];
  $form['utexas_extra_foundation_js']['display_demo_page'] = array(
    '#type' => 'item',
    '#title' => t('Visit a <a href="/demo/foundation-extra-libraries">demonstration page</a> to see the foundation extra libraries in action.'),
    '#description' => t('Note: this page is only visible to authenticated users.'),
  );
  $form['utexas_extra_foundation_js']['foundation_files'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Select additional Foundation elements to load their CSS and JavaScript files.'),
    '#description' => t('Note: this is an experimental feature.  We do not guarantee these elements will work correctly with Drupal.'),
    '#options' => array(
      'abide' => 'Abide Form Validation (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/abide.html" target="_blank">see here for more information</a>)',
      'accordion' => 'Accordions (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/accordion.html" target="_blank">see here for more information</a>)',
      'alert' => 'Alert Boxes (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/alert_boxes.html" target="_blank">see here for more information</a>)',
      'dropdown' => 'Dropdown Buttons (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/dropdown_buttons.html" target="_blank">see here for more information</a>)',
      'reveal' => 'Reveal Modals (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/reveal.html" target="_blank">see here for more information</a>)',
      'tab' => 'Horizontal and Vertical Tabs (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tabs.html" target="_blank">see here for more information</a>)',
      'tooltip' => 'Tooltips (<a href="http://foundation.zurb.com/sites/docs/v/5.5.3/components/tooltips.html" target="_blank">see here for more information</a>)',
    ),
    '#default_value' => theme_get_setting('foundation_files') ? theme_get_setting('foundation_files') : array(),
  );
}
