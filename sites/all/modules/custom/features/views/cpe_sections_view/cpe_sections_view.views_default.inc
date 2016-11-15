<?php
/**
 * @file
 * cpe_sections_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cpe_sections_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'cpe_sections';
  $view->description = 'List Sections related to a particular Course/SCC.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'reverse_field_section_course_node';
  $handler->display->display_options['row_options']['view_mode'] = 'full';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_section_course_node']['id'] = 'reverse_field_section_course_node';
  $handler->display->display_options['relationships']['reverse_field_section_course_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_section_course_node']['field'] = 'reverse_field_section_course_node';
  $handler->display->display_options['relationships']['reverse_field_section_course_node']['label'] = 'Section_Course';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_section_course_node';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Dates -  start date (field_section_dates) */
  $handler->display->display_options['sorts']['field_section_dates_value']['id'] = 'field_section_dates_value';
  $handler->display->display_options['sorts']['field_section_dates_value']['table'] = 'field_data_field_section_dates';
  $handler->display->display_options['sorts']['field_section_dates_value']['field'] = 'field_section_dates_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Dates -  start date (field_section_dates) */
  $handler->display->display_options['filters']['field_section_dates_value']['id'] = 'field_section_dates_value';
  $handler->display->display_options['filters']['field_section_dates_value']['table'] = 'field_data_field_section_dates';
  $handler->display->display_options['filters']['field_section_dates_value']['field'] = 'field_section_dates_value';
  $handler->display->display_options['filters']['field_section_dates_value']['relationship'] = 'reverse_field_section_course_node';
  $handler->display->display_options['filters']['field_section_dates_value']['operator'] = '>';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Course (field_section_course) */
  $handler->display->display_options['arguments']['field_section_course_target_id']['id'] = 'field_section_course_target_id';
  $handler->display->display_options['arguments']['field_section_course_target_id']['table'] = 'field_data_field_section_course';
  $handler->display->display_options['arguments']['field_section_course_target_id']['field'] = 'field_section_course_target_id';
  $handler->display->display_options['arguments']['field_section_course_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_section_course_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_section_course_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_section_course_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_section_course_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'cpe_section' => 'cpe_section',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Dates -  start date (field_section_dates) */
  $handler->display->display_options['filters']['field_section_dates_value']['id'] = 'field_section_dates_value';
  $handler->display->display_options['filters']['field_section_dates_value']['table'] = 'field_data_field_section_dates';
  $handler->display->display_options['filters']['field_section_dates_value']['field'] = 'field_section_dates_value';
  $handler->display->display_options['filters']['field_section_dates_value']['operator'] = '>';
  $handler->display->display_options['filters']['field_section_dates_value']['group'] = 1;
  $handler->display->display_options['filters']['field_section_dates_value']['default_date'] = 'now';
  $export['cpe_sections'] = $view;

  return $export;
}
