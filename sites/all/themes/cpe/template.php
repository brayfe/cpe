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
}

// node tpl for sections
function cpe_preprocess_node(&$variables) {

	
	$node = $variables['node'];
	dpm($node);
	if($node->type == 'cpe_section') {

	$variables['field_section_cost'] = $node->field_section_cost['und'][0]['safe_value'];
	
	$datestamp1 = strtotime($node->field_section_dates['und'][0]['value']);
	$datestamp2 = strtotime($node->field_section_dates['und'][0]['value2']);
	$variables['field_section_dates'] = format_date(intval($datestamp1), 'custom', 'M j, Y') . ' - ' . format_date(intval($datestamp2), 'custom', 'M j, Y');

	$variables['field_section_days'] = $node->field_section_days['und'][0]['value'];

	$timestamp1 = strtotime($node->field_section_times['und'][0]['value']);
	$timestamp2 = strtotime($node->field_section_times['und'][0]['value2']);
	$variables['field_section_times'] =  format_date(intval($timestamp1), 'custom', 'g:i A T') . ' - ' . format_date(intval($timestamp2), 'custom', 'g:i A T');

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

