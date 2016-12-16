<?php

/**
 * @file
 * Admin include file for admin settings form.
 */

/**
 * Implements drupal_get_form().
 *
 * Menu callback for the Social Sharing module administration.
 */
function utexas_social_sharing_admin_form($form, &$form_state) {

  $form['description']['#markup'] = '<img id="social-sharing-screenshot" src="/' . drupal_get_path('module', 'utexas_social_sharing') . '/theme/screenshot.png' . '" alt ="Screenshot of social sharing icons" align="right" />The "Social Share" block of icons, shown at right, can be placed on any page using the Layout Editor. Clicking on the links initiate a form on the destination site, prepopulated with a link back to the given page, as well as any other metadata you define below. <p><strong>Note:</strong> when developing with a local (non-publicly accessible) site, some of these share links will not work. Similarly, a Facebook App must be configured to share via Facebook.</p>';

  $form['container1']['#type'] = 'fieldset';
  $form['container1']['#title'] = t('Social sharing settings');
  $form['container1']['utexas_social_sharing_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Social sharing widget title'),
    '#description' => t('Enter a title to display above the icons'),
    '#default_value' => variable_get('utexas_social_sharing_title', 'Share this'),
  );
  $form['container1']['utexas_social_sharing_text'] = array(
    '#type' => 'checkbox',
    '#title' => t('Display social share titles'),
    '#description' => t('Note: titles are automatically hidden on mobile displays.'),
    '#default_value' => variable_get('utexas_social_sharing_text', 1),
  );
  $form['container1']['utexas_social_sharing_campaign'] = array(
    '#type' => 'textfield',
    '#title' => t('Campaign tag'),
    '#description' => t('Optionally, enter a string to identify in Analytics when sharing links are clicked.'),
    '#default_value' => variable_get('utexas_social_sharing_campaign', ''),
  );

  $form['container2']['#type'] = 'fieldset';
  $form['container2']['#title'] = t('Select which share links should display');
  $form['container2']['email']['utexas_social_sharing_em'] = array(
    '#type' => 'checkbox',
    '#title' => t('Email link'),
    '#default_value' => variable_get('utexas_social_sharing_em', 1),
  );
  $form['container2']['email']['utexas_social_sharing_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email subject line'),
    '#description' => t('Optionally, prepopulate the email with a custom subject line. If left blank, this will default to [site name] : [page title]'),
    '#default_value' => variable_get('utexas_social_sharing_email_subject', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_em"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['container2']['email']['utexas_social_sharing_email_body'] = array(
    '#type' => 'textarea',
    '#title' => t('Email body'),
    '#description' => t('Optionally, prepopulate the email with a custom body. If left blank, this will default to [site name] : [page title]'),
    '#default_value' => variable_get('utexas_social_sharing_email_body', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_em"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['container2']['facebook']['utexas_social_sharing_fb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Facebook'),
    '#default_value' => variable_get('utexas_social_sharing_fb', 0),
  );
  $form['container2']['facebook']['utexas_social_sharing_facebook_app_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Facebook App ID'),
    '#description' => t('Enter your !dev_url number. This must be a valid Facebook App to ensure that sharing works properly.',
      array(
        '!dev_url' => l(t('Facebook App ID'), 'https://developers.facebook.com/apps', array(
          'attributes' => array('target' => '_blank'),
        )),
      )),
    '#default_value' => variable_get('utexas_social_sharing_facebook_app_id', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_fb"]' => array('checked' => FALSE),
      ),
    ),
  );
  // Set the facebook default image.
  $form['container2']['facebook']['utexas_social_sharing_og_default'] = array(
    '#type' => 'managed_file',
    '#title' => t('Default og:image'),
    '#description' => t('This is used by Facebook sharing if a hero image is not set on the page.'),
    '#default_value' => variable_get('utexas_social_sharing_og_default', 0),
    '#upload_location' => 'public://og_images',
    '#upload_validators' => array(
      'file_validate_extensions' => array('png jpg jpeg gif'),
    ),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_fb"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['container2']['twitter']['utexas_social_sharing_tw'] = array(
    '#type' => 'checkbox',
    '#title' => t('Twitter'),
    '#default_value' => variable_get('utexas_social_sharing_tw', 1),
  );
  // Set the twitter handle.
  $form['container2']['twitter']['utexas_social_sharing_twitter_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter Handle'),
    '#description' => t('Optionally, append a Twiter handle in the form of "via @[handle]" to the end of the tweet. Do not include the @ in the textarea above.'),
    '#default_value' => variable_get('utexas_social_sharing_twitter_name', ''),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_tw"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['container2']['google']['utexas_social_sharing_go'] = array(
    '#type' => 'checkbox',
    '#title' => t('Google+'),
    '#default_value' => variable_get('utexas_social_sharing_go', 1),
  );
  $form['container2']['linkedin']['utexas_social_sharing_li'] = array(
    '#type' => 'checkbox',
    '#title' => t('LinkedIn'),
    '#default_value' => variable_get('utexas_social_sharing_li', 1),
  );
  $form['container2']['pinterest']['utexas_social_sharing_pi'] = array(
    '#type' => 'checkbox',
    '#title' => t('Pinterest'),
    '#default_value' => variable_get('utexas_social_sharing_pi', 1),
  );
  $form['container2']['pinterest']['utexas_social_sharing_pi_fields'] = array(
    '#type' => 'textfield',
    '#title' => t('Image fields'),
    '#size' => 200,
    '#description' => t('A comma-separated list of field machine names on the page that should be searched for images, ordered in priority. The first positive hit will be used in the Pinterest pin.'),
    '#default_value' => variable_get('utexas_social_sharing_pi_fields', 'field_utexas_hero_image, field_utexas_member_headshot'),
    '#states' => array(
      'invisible' => array(
        'input[name="utexas_social_sharing_pi"]' => array('checked' => FALSE),
      ),
    ),
  );
  $form['container2']['tumblr']['utexas_social_sharing_tu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Tumblr'),
    '#default_value' => variable_get('utexas_social_sharing_tu', 1),
  );
  $form['container2']['reddit']['utexas_social_sharing_re'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reddit'),
    '#default_value' => variable_get('utexas_social_sharing_re', 1),
  );

  // Make into a system settings form.
  $form = system_settings_form($form);

  $form['#validate'][] = 'utexas_social_sharing_admin_form_validate';

  $form['#submit'] = array_merge(array('utexas_social_sharing_admin_form_submit'), $form['#submit']);
  return $form;
}

/**
 * Check if a Facebook App ID has been entered.
 */
function utexas_social_sharing_admin_form_validate(&$form, &$form_state) {
  if ($form_state['values']['utexas_social_sharing_fb'] == 1 && $form_state['values']['utexas_social_sharing_facebook_app_id'] == '') {
    form_error($form['container2']['facebook']['utexas_social_sharing_facebook_app_id'], t('A Facebook App ID must be added (and configured) for Facebook shares to work.'));
  }
}

/**
 * Custom form submitter to permanently save the file upload.
 */
function utexas_social_sharing_admin_form_submit(&$form, &$form_state) {
  $new_file_id = $form_state['values']['utexas_social_sharing_og_default'];
  $old_file_id = variable_get('utexas_social_sharing_og_default', 0);

  // There's a new file so process it.
  if ($new_file_id and $new_file_id != $old_file_id) {
    if ($file = file_load($new_file_id)) {
      // Make the new file permanent.
      $file->status = FILE_STATUS_PERMANENT;
      file_save($file);
      file_usage_add($file, 'utexas_social_sharing', 'utexas_social_sharing', 1);

      // Delete the old file.
      if ($old_file = file_load($old_file_id)) {
        file_delete($old_file, TRUE);
      }

      // Set notifications.
      drupal_set_message(t('Successfully saved new og:image image.'), 'status', FALSE);
    }
    else {
      // Alert to the error.
      drupal_set_message(t('There was a problem saving your og:image image.'), 'error', FALSE);
    }
  }

  // There's an old file that needs to be deleted and no new one.
  if (!$new_file_id and $old_file_id) {
    if ($file = file_load($old_file_id)) {
      file_delete($file, TRUE);
      drupal_set_message(t('Successfully removed old og:image image.'), 'status', FALSE);
    }
    else {
      // Alert to the error.
      drupal_set_message(t('There was a problem deleting your og:image image.'), 'error', FALSE);
    }
  }
}
