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
        $variables['field_course_prereqs'] = render($view['field_course_prereqs']);
        $variables['field_course_textbook_info'] = render($view['field_course_textbook_info']);
        $variables['field_course_notes'] = render($view['field_course_notes']);
        $variables['field_course_contact_name'] = render($view['field_course_contact_name']);
        $variables['field_course_contact_phone'] = render($view['field_course_contact_phone']);
        $variables['field_course_contact_email'] = render($view['field_course_contact_email']);
    }

}
