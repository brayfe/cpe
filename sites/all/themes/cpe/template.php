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
    
   // Area of Study content type field variables
    if ($node->type == 'cpe_area_of_study') {
        $variables['field_aos_headline'] = render($view['field_aos_headline']);
        $variables['field_aos_description'] = render($view['field_aos_description']);
        $variables['field_aos_cert_options'] = render($view['field_aos_cert_options']);
        $variables['field_aos_certify_body'] = render($view['field_aos_certify_body']);
        $variables['field_aos_accred_body'] = render($view['field_aos_accred_body']);
        $variables['field_aos_featured'] = render($view['field_aos_featured']);
        $variables['field_aos_contact_name'] = render($view['field_aos_contact_name']);
        $variables['field_aos_rfi'] = render($view['field_aos_rfi']);
        $variables['field_aos_contact_phone'] = render($view['field_aos_contact_phone']);
        $variables['field_aos_contact_email'] = render($view['field_aos_contact_email']);
    }

}


