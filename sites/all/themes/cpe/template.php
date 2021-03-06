<?php

/**
 * @file
 * Main template file for subtheme of forty_acres theme.
 */

/**
 * Setup custom page templates based on suggestions.
 */
function cpe_preprocess_page(&$variables) {
  // Add theme hook suggestions based on node type.
  if (isset($variables['node']->type)) {
    $nodetype = $variables['node']->type;
    $variables['theme_hook_suggestions'][] = 'page__' . $nodetype;
  }

  if (isset($variables['node'])) {
    $node = $variables['node'];
    $view = node_view($node);

    // Instructor content type field variables.
    if ($node->type == 'cpe_instructor') {
      $variables['field_instructor_bio'] = render($view['field_instructor_bio']);
      $variables['field_instructor_creds'] = render($view['field_instructor_creds']);
      $variables['field_instructor_pic'] = render($view['field_instructor_pic']);
    }

    // Course content type field variables.
    if ($node->type == 'cpe_course') {
      $variables['field_course_type'] = render($view['field_course_type']);
      $variables['field_course_aos'] = render($view['field_course_aos']);

      // Custom label display logic based on course type.
      $course_type_term = taxonomy_term_load($node->field_course_type['und'][0]['tid']);
      $course_description_display = 'above';
      switch ($course_type_term->name) {
        case 'Course':
          $course_description_display = 'above';
          break;

        case 'Webinar':
          $course_description_display = 'hidden';
          break;

        case 'Information Session':
          $course_description_display = 'hidden';
          break;

        case 'Specialist Program':
          $course_description_display = 'above';
          break;

        default:
          $course_description_display = 'above';
      }
      $view['field_course_description']['#label_display'] = $course_description_display;

      $variables['field_course_description'] = render($view['field_course_description']);
      $variables['field_course_who_enroll'] = render($view['field_course_who_enroll']);
      $variables['field_course_outcomes'] = render($view['field_course_outcomes']);
      $variables['field_course_discounts'] = render($view['field_course_discounts']);
      $variables['field_course_cont_ed_hrs'] = render($view['field_course_cont_ed_hrs']);
      // Load block view of certificates.
      $block = module_invoke('views', 'block_view', 'cpe_certs_by_course-block');
      $variables['field_course_certificates'] = $block['subject'] . render($block['content']);
      $variables['field_course_prereqs'] = render($view['field_course_prereqs']);
      $variables['field_course_textbook_info'] = render($view['field_course_textbook_info']);
      $variables['field_course_notes'] = render($view['field_course_notes']);
      $variables['field_course_contact_name'] = render($view['field_course_contact_name']);
      $variables['field_course_contact_phone'] = render($view['field_course_contact_phone']);
      $variables['field_course_contact_email'] = render($view['field_course_contact_email']);
    }

    // Area of Study content type field variables.
    if ($node->type == 'cpe_area_of_study') {
      $variables['field_aos_headline'] = render($view['field_aos_headline']);
      $variables['field_aos_description'] = render($view['field_aos_description']);
      $variables['field_aos_cert_options'] = render($view['field_aos_cert_options']);
      $variables['field_aos_certify_body'] = render($view['field_aos_certify_body']);
      $variables['field_aos_accred_body'] = render($view['field_aos_accred_body']);
      $variables['field_aos_featured'] = render($view['field_aos_featured']);
      $variables['field_aos_related_arts'] = render($view['field_aos_related_arts']);
      $variables['field_aos_contact_name'] = render($view['field_aos_contact_name']);
      $variables['field_aos_rfi'] = render($view['field_aos_rfi']);
      $variables['field_aos_contact_phone'] = render($view['field_aos_contact_phone']);
      $variables['field_aos_contact_email'] = render($view['field_aos_contact_email']);
      $link_text = '<div class="course-listing-link">' . t("PDUs/CEUs") . '</div>';
      $variables['link_to_course_listing'] = l($link_text, "/course-by-aos/" . drupal_get_path_alias(), array('attributes' => array('title' => "PDUs/CEUs"), 'html' => TRUE));

      $node_wrapper = entity_metadata_wrapper('node', $node);
      // Only show link to PDU if Accred Body is NOT tid 16 (CEUs).
      $variables['display_link'] = $node_wrapper->field_aos_accred_body->value()->tid == 16 ? FALSE : TRUE;
    }

    // SCC content type field variables.
    if ($node->type == 'cpe_single_course_cert') {
      $variables['field_scc_aos'] = render($view['field_scc_aos']);
      $variables['field_scc_headline'] = render($view['field_scc_headline']);
      $variables['field_scc_description'] = render($view['field_scc_description']);
      $variables['field_scc_who_enroll'] = render($view['field_scc_who_enroll']);
      $variables['field_scc_outcomes'] = render($view['field_scc_outcomes']);
      $variables['field_scc_prereqs'] = render($view['field_scc_prereqs']);
      $variables['field_scc_notes'] = render($view['field_scc_notes']);
      $variables['field_scc_discounts'] = render($view['field_scc_discounts']);
      $variables['field_scc_program_id'] = render($view['field_scc_program_id']);
      $variables['field_scc_featured_related'] = render($view['field_scc_featured_related']);
      $variables['field_scc_duration'] = render($view['field_scc_duration']);
      $variables['field_scc_modality'] = render($view['field_scc_modality']);
      $variables['field_scc_tuition'] = render($view['field_scc_tuition']);
      $variables['field_scc_pay_options'] = render($view['field_scc_pay_options']);
      $variables['field_scc_cont_ed_hrs'] = render($view['field_scc_cont_ed_hrs']);
      $variables['field_scc_related_arts'] = render($view['field_scc_related_arts']);
      $variables['field_scc_contact_name'] = render($view['field_scc_contact_name']);
      $variables['field_scc_contact_phone'] = render($view['field_scc_contact_phone']);
      $variables['field_scc_contact_email'] = render($view['field_scc_contact_email']);
      $variables['field_scc_info_sessions'] = render($view['field_scc_info_sessions']);
      $variables['field_scc_rfi'] = render($view['field_scc_rfi']);
    }

    // MCC content type field variables.
    if ($node->type == 'cpe_multi_course_cert') {
      $variables['field_mcc_aos'] = render($view['field_mcc_aos']);
      $variables['field_mcc_headline'] = render($view['field_mcc_headline']);
      $variables['field_mcc_description'] = render($view['field_mcc_description']);
      $variables['field_mcc_who_enroll'] = render($view['field_mcc_who_enroll']);
      $variables['field_mcc_description'] = render($view['field_mcc_description']);
      $variables['field_mcc_outcomes'] = render($view['field_mcc_outcomes']);
      $variables['field_mcc_prereqs'] = render($view['field_mcc_prereqs']);
      $variables['field_mcc_certify_body'] = render($view['field_mcc_certify_body']);
      $variables['field_mcc_notes'] = render($view['field_mcc_notes']);
      $variables['field_mcc_program_id'] = render($view['field_mcc_program_id']);
      $variables['field_mcc_courses'] = render($view['field_mcc_courses']);
      $variables['field_mcc_duration'] = render($view['field_mcc_duration']);
      $variables['field_mcc_modality'] = render($view['field_mcc_modality']);
      $variables['field_mcc_featured_related'] = render($view['field_mcc_featured_related']);
      $variables['field_mcc_tuition'] = render($view['field_mcc_tuition']);
      $variables['field_mcc_pay_options'] = render($view['field_mcc_pay_options']);
      $variables['field_mcc_related_arts'] = render($view['field_mcc_related_arts']);
      $variables['field_mcc_rfi'] = render($view['field_mcc_rfi']);
      $variables['field_mcc_contact_name'] = render($view['field_mcc_contact_name']);
      $variables['field_mcc_contact_phone'] = render($view['field_mcc_contact_phone']);
      $variables['field_mcc_contact_email'] = render($view['field_mcc_contact_email']);
      $variables['field_mcc_info_sessions'] = render($view['field_mcc_info_sessions']);

      // Get safe value of MISHELL ID field and course coodinator email fields,
      // rather than fully rendered fields.
      $node_wrapper = entity_metadata_wrapper('node', $node);
      $variables['field_mcc_mishell_id'] = $node_wrapper->field_mcc_mishell_id->value();
      $variables['field_coordinator_email'] = $node_wrapper->field_mcc_contact_email->value();
    }
  }
}

/**
 * Implements hook_preprocess_node().
 */
function cpe_preprocess_node(&$variables) {
  $node = $variables['node'];
  if ($node->type == 'cpe_section') {

    // Add the "Course coordinator" email, based on whether the parent of the
    // section is a course or a single_course_cert.
    $node_wrapper = entity_metadata_wrapper('node', $node);
    $variables['field_section_mishell_id'] = $node_wrapper->field_section_mishell_id->value();
    $variables['field_section_course_id'] = $node_wrapper->field_section_course_id->value();
    switch ($node_wrapper->field_section_course->getBundle()) {
      case 'cpe_course':
        $variables['field_coordinator_email'] = $node_wrapper->field_section_course->field_course_contact_email->value();
        break;

      case 'cpe_single_course_cert':
        $variables['field_coordinator_email'] = $node_wrapper->field_section_course->field_scc_contact_email->value();
        break;
    }
  }
}

/**
 * Implements template_preprocess_field().
 *
 * Used to trim teaser Headlines for Certificate Options field.
 */
function cpe_preprocess_field(&$variables, $hook) {
  // Headlines used for Certificate Options Entity Reference field.
  $cts = array('field_mcc_headline', 'field_scc_headline', 'field_aos_headline');
  // If this is a teaser view Headline from allowed Entity References.
  if (in_array($variables['element']['#field_name'], $cts) && $variables['element']['#view_mode'] == 'teaser') {
    // Truncate to 100 characters (+3 for ellipsis), and return to markup.
    $variables['items'][0]['#markup'] = truncate_utf8(strip_tags($variables['items'][0]['#markup']), 103, TRUE, TRUE);
  }
}

/**
 * Implements hook_preprocess_links().
 */
function cpe_preprocess_links(&$variables) {
  if (isset($variables['links']['node-readmore'])) {
    $variables['links']['node-readmore']['title'] = t('Learn more');
  }
}
