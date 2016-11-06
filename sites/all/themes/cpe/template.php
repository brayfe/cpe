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
        $variables['field_mcc_rfi'] = render($view['field_mcc_rfi']);
        $variables['field_mcc_contact_name'] = render($view['field_mcc_contact_name']);
        $variables['field_mcc_contact_phone'] = render($view['field_mcc_contact_phone']);
        $variables['field_mcc_contact_email'] = render($view['field_mcc_contact_email']);
        $variables['field_mcc_info_sessions'] = render($view['field_mcc_info_sessions']);
    }

}


