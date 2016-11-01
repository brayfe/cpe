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
        $variables['field_scc_contact_name'] = render($view['field_scc_contact_name']);
        $variables['field_scc_contact_phone'] = render($view['field_scc_contact_phone']);
        $variables['field_scc_contact_email'] = render($view['field_scc_contact_email']);
        $variables['field_scc_info_sessions'] = render($view['field_scc_info_sessions']);
        $variables['field_scc_rfi'] = render($view['field_scc_rfi']);
    }

}


