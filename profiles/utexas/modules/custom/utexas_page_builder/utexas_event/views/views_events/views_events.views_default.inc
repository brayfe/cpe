<?php
/**
 * @file
 * views_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'utexas_event';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'start' => 'start',
    'end' => 'end',
    'title' => 'title',
    'date_range' => 'date_range',
    'field_event_location' => 'field_event_location',
    'field_event_tags' => 'field_event_tags',
    'operations' => 'operations',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'start' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'end' => array(
      'sortable' => 0,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'date_range' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_location' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_event_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'operations' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: Event */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Event: Event ID */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = '';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  $handler->display->display_options['fields']['id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Event: Start Date */
  $handler->display->display_options['fields']['start']['id'] = 'start';
  $handler->display->display_options['fields']['start']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['start']['field'] = 'start';
  $handler->display->display_options['fields']['start']['exclude'] = TRUE;
  $handler->display->display_options['fields']['start']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['start']['date_format'] = 'long';
  $handler->display->display_options['fields']['start']['custom_date_format'] = 'l, F j, Y g:i a';
  $handler->display->display_options['fields']['start']['second_date_format'] = 'long';
  /* Field: Event: End Date */
  $handler->display->display_options['fields']['end']['id'] = 'end';
  $handler->display->display_options['fields']['end']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['end']['field'] = 'end';
  $handler->display->display_options['fields']['end']['exclude'] = TRUE;
  $handler->display->display_options['fields']['end']['date_format'] = 'long';
  $handler->display->display_options['fields']['end']['second_date_format'] = 'long';
  /* Field: Event: Event Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Title';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'events/[id]';
  /* Field: Event: Event Date Range */
  $handler->display->display_options['fields']['date_range']['id'] = 'date_range';
  $handler->display->display_options['fields']['date_range']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['date_range']['field'] = 'date_range';
  $handler->display->display_options['fields']['date_range']['label'] = 'Occurs';
  /* Field: Event: Event Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = 'Location';
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Event: Event Tags */
  $handler->display->display_options['fields']['field_event_tags']['id'] = 'field_event_tags';
  $handler->display->display_options['fields']['field_event_tags']['table'] = 'field_data_field_event_tags';
  $handler->display->display_options['fields']['field_event_tags']['field'] = 'field_event_tags';
  $handler->display->display_options['fields']['field_event_tags']['label'] = 'Tags';
  $handler->display->display_options['fields']['field_event_tags']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_event_tags']['delta_offset'] = '0';
  /* Field: Event: Events Operations */
  $handler->display->display_options['fields']['operations']['id'] = 'operations';
  $handler->display->display_options['fields']['operations']['table'] = 'utexas_event';
  $handler->display->display_options['fields']['operations']['field'] = 'operations';
  $handler->display->display_options['fields']['operations']['label'] = 'Operations';
  /* Sort criterion: Event: Event Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Event Title';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'word';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search by title';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
  );
  /* Filter criterion: Date: Date (utexas_event) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'Date is on or after';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'utexas_event.start' => 'utexas_event.start',
  );
  /* Filter criterion: Event: Event Tags (field_event_tags) */
  $handler->display->display_options['filters']['field_event_tags_tid']['id'] = 'field_event_tags_tid';
  $handler->display->display_options['filters']['field_event_tags_tid']['table'] = 'field_data_field_event_tags';
  $handler->display->display_options['filters']['field_event_tags_tid']['field'] = 'field_event_tags_tid';
  $handler->display->display_options['filters']['field_event_tags_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_tags_tid']['expose']['operator_id'] = 'field_event_tags_tid_op';
  $handler->display->display_options['filters']['field_event_tags_tid']['expose']['label'] = 'Tagged with';
  $handler->display->display_options['filters']['field_event_tags_tid']['expose']['operator'] = 'field_event_tags_tid_op';
  $handler->display->display_options['filters']['field_event_tags_tid']['expose']['identifier'] = 'field_event_tags_tid';
  $handler->display->display_options['filters']['field_event_tags_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_tags_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_tags_tid']['vocabulary'] = 'event_tags';
  /* Filter criterion: Event: Event Location (field_event_location) */
  $handler->display->display_options['filters']['field_event_location_tid']['id'] = 'field_event_location_tid';
  $handler->display->display_options['filters']['field_event_location_tid']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['filters']['field_event_location_tid']['field'] = 'field_event_location_tid';
  $handler->display->display_options['filters']['field_event_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_location_tid']['expose']['operator_id'] = 'field_event_location_tid_op';
  $handler->display->display_options['filters']['field_event_location_tid']['expose']['label'] = 'Event Location';
  $handler->display->display_options['filters']['field_event_location_tid']['expose']['operator'] = 'field_event_location_tid_op';
  $handler->display->display_options['filters']['field_event_location_tid']['expose']['identifier'] = 'field_event_location_tid';
  $handler->display->display_options['filters']['field_event_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_event_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_event_location_tid']['vocabulary'] = 'event_location';

  /* Display: Admin Page */
  $handler = $view->new_display('page', 'Admin Page', 'page');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['path'] = 'admin/content/events';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Upcoming Events (teasers) */
  $handler = $view->new_display('block', 'Upcoming Events (teasers)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['filters']['end']['value']['type'] = 'offset';
  $handler->display->display_options['block_description'] = 'Upcoming Events (teasers)';

  /* Display: Upcoming Events (titles) */
  $handler = $view->new_display('block', 'Upcoming Events (titles)', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_title';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['filters']['end']['value']['type'] = 'offset';
  $handler->display->display_options['block_description'] = 'Upcoming Events (titles)';

  /* Display: Featured Events (titles) */
  $handler = $view->new_display('block', 'Featured Events (titles)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Events';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_title';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['filters']['end']['value']['type'] = 'offset';
  /* Filter criterion: Event: Featured Event */
  $handler->display->display_options['filters']['featured']['id'] = 'featured';
  $handler->display->display_options['filters']['featured']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['featured']['field'] = 'featured';
  $handler->display->display_options['filters']['featured']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Featured Events (titles)';

  /* Display: Featured Events (teasers) */
  $handler = $view->new_display('block', 'Featured Events (teasers)', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Events';
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['filters']['end']['value']['type'] = 'offset';
  /* Filter criterion: Event: Featured Event */
  $handler->display->display_options['filters']['featured']['id'] = 'featured';
  $handler->display->display_options['filters']['featured']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['featured']['field'] = 'featured';
  $handler->display->display_options['filters']['featured']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Featured Events (teasers)';
  $handler->display->display_options['block_caching'] = '-1';

  /* Display: Events Tags Listing */
  $handler = $view->new_display('page', 'Events Tags Listing', 'page_1');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['sorts']['start']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Event: Event Tags (field_event_tags) */
  $handler->display->display_options['arguments']['field_event_tags_tid']['id'] = 'field_event_tags_tid';
  $handler->display->display_options['arguments']['field_event_tags_tid']['table'] = 'field_data_field_event_tags';
  $handler->display->display_options['arguments']['field_event_tags_tid']['field'] = 'field_event_tags_tid';
  $handler->display->display_options['arguments']['field_event_tags_tid']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_event_tags_tid']['exception']['title'] = 'Events';
  $handler->display->display_options['arguments']['field_event_tags_tid']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['field_event_tags_tid']['title'] = '%1';
  $handler->display->display_options['arguments']['field_event_tags_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_event_tags_tid']['default_argument_options']['argument'] = 'all';
  $handler->display->display_options['arguments']['field_event_tags_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_tags_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_tags_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_tags_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_event_tags_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_event_tags_tid']['validate_options']['vocabularies'] = array(
    'event_tags' => 'event_tags',
  );
  $handler->display->display_options['arguments']['field_event_tags_tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['field_event_tags_tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['path'] = 'events/tag/%';

  /* Display: All Events */
  $handler = $view->new_display('page', 'All Events', 'page_2');
  $handler->display->display_options['defaults']['cache'] = FALSE;
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '1800';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '1800';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'event_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event: Start Date */
  $handler->display->display_options['sorts']['start']['id'] = 'start';
  $handler->display->display_options['sorts']['start']['table'] = 'utexas_event';
  $handler->display->display_options['sorts']['start']['field'] = 'start';
  $handler->display->display_options['sorts']['start']['granularity'] = 'minute';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event: End Date */
  $handler->display->display_options['filters']['end']['id'] = 'end';
  $handler->display->display_options['filters']['end']['table'] = 'utexas_event';
  $handler->display->display_options['filters']['end']['field'] = 'end';
  $handler->display->display_options['filters']['end']['operator'] = '>=';
  $handler->display->display_options['filters']['end']['value']['value'] = '+30 minutes';
  $handler->display->display_options['path'] = 'events';
  $export['events'] = $view;

  return $export;
}
