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


