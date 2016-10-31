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
}


