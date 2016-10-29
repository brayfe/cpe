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
	// if node type is for instructor content type, then create field variables to print in the page tpl
	if ($node->type == 'cpe_instructor') {
    		$variables['field_instructor_bio'] = field_view_field('node', $node, 'field_instructor_bio', array('label' => 'above'));

    		$variables['field_instructor_creds'] = field_view_field('node', $node, 'field_instructor_creds');

    		$variables['field_instructor_pic'] = field_view_field('node', $node, 'field_instructor_pic', array('settings' => array('image_style' => 'large')));
	}

    // SCC content type field variables
    if ($node->type == 'cpe_single_course_cert') {

            $variables['field_scc_aos'] = field_view_field('node', $node, 'field_scc_aos');

            $variables['field_scc_headline'] = field_view_field('node', $node, 'field_scc_headline');

            $variables['field_scc_description'] = field_view_field('node', $node, 'field_scc_description');

            $variables['field_scc_who_enroll'] = field_view_field('node', $node, 'field_scc_who_enroll');

            $variables['field_scc_outcomes'] = field_view_field('node', $node, 'field_scc_outcomes');

            $variables['field_scc_prereqs'] = field_view_field('node', $node, 'field_scc_prereqs');

            $variables['field_scc_notes'] = field_view_field('node', $node, 'field_scc_notes');

            $variables['field_scc_program_id'] = field_view_field('node', $node, 'field_scc_program_id');

            $variables['field_scc_featured_related'] = field_view_field('node', $node, 'field_scc_featured_related');

            $variables['field_scc_modality'] = field_view_field('node', $node, 'field_scc_modality');

            $variables['field_scc_tuition'] = field_view_field('node', $node, 'field_scc_tuition');

            $variables['field_scc_pay_options'] = field_view_field('node', $node, 'field_scc_pay_options');

            $variables['field_scc_contact_name'] = field_view_field('node', $node, 'field_scc_contact_name');

            $variables['field_scc_contact_phone'] = field_view_field('node', $node, 'field_scc_contact_phone');

            $variables['field_scc_contact_email'] = field_view_field('node', $node, 'field_scc_contact_email');

            $variables['field_scc_info_sessions'] = field_view_field('node', $node, 'field_scc_info_sessions');

            $variables['field_scc_rfi'] = field_view_field('node', $node, 'field_scc_rfi');

    }

}


