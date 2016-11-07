<?php
/**
 * @file
 * Main template file for subtheme of forty_acres theme.
 */

/**
 * Setup custom page templates based on suggestions.
 */
function cpe_preprocess_page(&$variables) {
  // check for node type set then use theme hook suggestions for page templates to work
  if (isset($variables['node']->type)) {
    $nodetype = $variables['node']->type;
    $variables['theme_hook_suggestions'][] = 'page__' . $nodetype;
  }

  $node = $variables['node'];
  $view = node_view($node);

  // Instructor content type field variables
  if ($node->type == 'cpe_instructor') {
    $variables['field_instructor_bio'] = render($view['field_instructor_bio']);
    $variables['field_instructor_creds'] = render($view['field_instructor_creds']);
    $variables['field_instructor_pic'] = render($view['field_instructor_pic']);
  }

  // Course content type field variables
  if ($node->type == 'cpe_course') {
    $variables['field_course_type'] = render($view['field_course_type']);
    $variables['field_course_aos'] = render($view['field_course_aos']);
    $variables['field_course_description'] = render($view['field_course_description']);
    $variables['field_course_who_enroll'] = render($view['field_course_who_enroll']);
    $variables['field_course_outcomes'] = render($view['field_course_outcomes']);
    $variables['field_course_discounts'] = render($view['field_course_discounts']);
    $variables['field_course_cont_ed_hrs'] = render($view['field_course_cont_ed_hrs']);
    $variables['field_course_prereqs'] = render($view['field_course_prereqs']);
    $variables['field_course_textbook_info'] = render($view['field_course_textbook_info']);
    $variables['field_course_notes'] = render($view['field_course_notes']);
    $variables['field_course_contact_name'] = render($view['field_course_contact_name']);
    $variables['field_course_contact_phone'] = render($view['field_course_contact_phone']);
    $variables['field_course_contact_email'] = render($view['field_course_contact_email']);
  }

  // Area of Study content type field variables
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
  }

  // SCC content type field variables
  if ($node->type == 'cpe_single_course_cert') {
    $variables['field_scc_aos'] = render($view['field_scc_aos']);
    $variables['field_scc_headline'] = render($view['field_scc_headline']);
    $variables['field_scc_description'] = render($view['field_scc_description']);
    $variables['field_scc_who_enroll'] = render($view['field_scc_who_enroll']);
    $variables['field_scc_outcomes'] = render($view['field_scc_outcomes']);
    $variables['field_scc_prereqs'] = render($view['field_scc_prereqs']);
    $variables['field_scc_notes'] = render($view['field_scc_notes']);
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

  // MCC content type field variables
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
    $variables['field_mcc_mishell_id'] = render($view['field_mcc_mishell_id']);
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
  }

}

/**
 * Implements hook_preprocess_node().
 */
function cpe_preprocess_node(&$variables) {
    $node = $variables['node'];

  if($node->type == 'cpe_section') {
    $variables['field_section_cost'] = $node->field_section_cost['und'][0]['safe_value'];
    $datestamp1 = strtotime($node->field_section_dates['und'][0]['value']);
    $datestamp2 = strtotime($node->field_section_dates['und'][0]['value2']);
    $variables['field_section_dates'] = format_date(intval($datestamp1), 'custom', 'M j, Y') . ' - ' . format_date(intval($datestamp2), 'custom', 'M j, Y');
    $variables['field_section_days'] = $node->field_section_days['und'][0]['value'];
    $variables['field_section_times'] = $node->field_section_times['und'][0]['value'] . ' - ' . $node->field_section_times['und'][0]['value2'];
    $variables['field_section_location'] = $node->field_section_location['und'][0]['safe_value'];
    $tid  = $node->field_section_modality['und'][0]['tid'];
    $term = taxonomy_term_load($tid);
    $name = $term->name;
    $variables['field_section_modality'] = $name;
    $nodeid = $node->field_section_instructor['und'][0]['target_id'];
    $instructor_name = node_load($nodeid)->title;
    $variables['field_section_instructor'] = l($instructor_name,'node/' . $nodeid);
    $variables['field_section_course'] = $node->field_section_course['und'][0]['target_id'];
    $variables['field_section_course_id'] = $node->field_section_course_id['und'][0]['safe_value'];
    $variables['field_section_mishell_id'] = $node->field_section_mishell_id['und'][0]['safe_value'];
    $variables['field_section_notes'] = $node->field_section_notes['und'][0]['safe_value'];
    }

}
