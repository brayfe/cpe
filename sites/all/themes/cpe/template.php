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
    // instructor content type field variables
    if ($node->type == 'cpe_instructor') {
            $variables['field_instructor_bio'] = field_view_field('node', $node, 'field_instructor_bio', array('label' => 'above'));

            $variables['field_instructor_creds'] = field_view_field('node', $node, 'field_instructor_creds');

            $variables['field_instructor_pic'] = field_view_field('node', $node, 'field_instructor_pic', array('settings' => array('image_style' => 'large')));
    }


    // Course content type field variables
    if ($node->type == 'cpe_course') {

            $variables['field_course_type'] = field_view_field('node', $node, 'field_course_type');

            $variables['field_course_aos'] = field_view_field('node', $node, 'field_course_aos');

            $variables['field_course_description'] = field_view_field('node', $node, 'field_course_description');

            $variables['field_course_who_enroll'] = field_view_field('node', $node, 'field_course_who_enroll');

            $variables['field_course_outcomes'] = field_view_field('node', $node, 'field_course_outcomes');

            $variables['field_course_discounts'] = field_view_field('node', $node, 'field_course_discounts');

            $variables['field_course_prereqs'] = field_view_field('node', $node, 'field_course_prereqs');

            $variables['field_course_textbook_info'] = field_view_field('node', $node, 'field_course_textbook_info');

            $variables['field_course_notes'] = field_view_field('node', $node, 'field_course_notes');

            $variables['field_course_contact_name'] = field_view_field('node', $node, 'field_course_contact_name');

            $variables['field_course_contact_phone'] = field_view_field('node', $node, 'field_course_contact_phone');

            $variables['field_course_contact_email'] = field_view_field('node', $node, 'field_course_contact_email');

    }

}
