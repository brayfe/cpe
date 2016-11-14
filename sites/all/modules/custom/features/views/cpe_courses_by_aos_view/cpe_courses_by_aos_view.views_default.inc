<?php
/**
 * @file
 * cpe_courses_by_aos_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cpe_courses_by_aos_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cpe_course_by_aos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course by Area of Study';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course by Area of Study';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h4>Found the following courses with [field_aos_accred_body] PDUs:</h4>
';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no courses available for this Area of Study.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_course_aos_target_id']['id'] = 'field_course_aos_target_id';
  $handler->display->display_options['relationships']['field_course_aos_target_id']['table'] = 'field_data_field_course_aos';
  $handler->display->display_options['relationships']['field_course_aos_target_id']['field'] = 'field_course_aos_target_id';
  $handler->display->display_options['relationships']['field_course_aos_target_id']['label'] = 'ER to AoS';
  /* Field: Content: Area of Study */
  $handler->display->display_options['fields']['field_course_aos']['id'] = 'field_course_aos';
  $handler->display->display_options['fields']['field_course_aos']['table'] = 'field_data_field_course_aos';
  $handler->display->display_options['fields']['field_course_aos']['field'] = 'field_course_aos';
  $handler->display->display_options['fields']['field_course_aos']['label'] = '';
  $handler->display->display_options['fields']['field_course_aos']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_aos']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_aos']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Continuing Education Hours */
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['id'] = 'field_course_cont_ed_hrs';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['table'] = 'field_data_field_course_cont_ed_hrs';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['field'] = 'field_course_cont_ed_hrs';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['label'] = '';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['click_sort_column'] = 'accrediting_body_tid';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_course_cont_ed_hrs']['multi_type'] = 'ul';
  /* Field: Content: Accrediting Body */
  $handler->display->display_options['fields']['field_aos_accred_body']['id'] = 'field_aos_accred_body';
  $handler->display->display_options['fields']['field_aos_accred_body']['table'] = 'field_data_field_aos_accred_body';
  $handler->display->display_options['fields']['field_aos_accred_body']['field'] = 'field_aos_accred_body';
  $handler->display->display_options['fields']['field_aos_accred_body']['relationship'] = 'field_course_aos_target_id';
  $handler->display->display_options['fields']['field_aos_accred_body']['label'] = '';
  $handler->display->display_options['fields']['field_aos_accred_body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_aos_accred_body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_aos_accred_body']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Area of Study (field_course_aos) */
  $handler->display->display_options['arguments']['field_course_aos_target_id']['id'] = 'field_course_aos_target_id';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['table'] = 'field_data_field_course_aos';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['field'] = 'field_course_aos_target_id';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_course_aos_target_id']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_course_aos_target_id']['title'] = '%1';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_course_aos_target_id']['validate_options']['types'] = array(
    'cpe_area_of_study' => 'cpe_area_of_study',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpe_course' => 'cpe_course',
  );
  /* Filter criterion: Content: Course Type (field_course_type) */
  $handler->display->display_options['filters']['field_course_type_tid']['id'] = 'field_course_type_tid';
  $handler->display->display_options['filters']['field_course_type_tid']['table'] = 'field_data_field_course_type';
  $handler->display->display_options['filters']['field_course_type_tid']['field'] = 'field_course_type_tid';
  $handler->display->display_options['filters']['field_course_type_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_course_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_course_type_tid']['vocabulary'] = 'cpe_course_types';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'course-by-aos';
  $handler->display->display_options['menu']['title'] = 'Course by Area of Study';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['cpe_course_by_aos'] = $view;

  return $export;
}
