<?php
/**
 * @file
 * UTexas Event entity definitions.
 *
 * Provides the "Event" entity, which stores date, location, and detail about
 * given events.
 */

/**
 * Implements hook_entity_property_info().
 */
function utexas_event_entity_property_info() {

  $info = array();

  $info['utexas_event']['properties']['id'] = array(
    'label' => t('Event ID'),
    'description' => t('The system ID of the event.'),
    'type' => 'integer',
    'schema field' => 'id',
  );
  $info['utexas_event']['properties']['title'] = array(
    'label' => t('Event Title'),
    'description' => t('The display title of the event.'),
    'type' => 'text',
    'schema field' => 'title',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['start'] = array(
    'label' => t('Start Date'),
    'description' => t('The date the event starts.'),
    'type' => 'date',
    'schema field' => 'start',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['featured'] = array(
    'label' => t('Featured Event'),
    'description' => t('Is this a Featured Event?'),
    'type' => 'boolean',
    'schema field' => 'featured',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['end'] = array(
    'label' => t('End Date'),
    'description' => t('The date the event ends.'),
    'type' => 'date',
    'schema field' => 'end',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['image_fid'] = array(
    'label' => t('Event image FID'),
    'description' => t('The image associated with an event.'),
    'type' => 'integer',
    'schema field' => 'image_fid',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['summary_text'] = array(
    'label' => t('Summary Text'),
    'description' => t('The short description of the event.'),
    'type' => 'text',
    'schema field' => 'summary_text',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['detail_text'] = array(
    'label' => t('Detail Text'),
    'description' => t('The long description of the event.'),
    'type' => 'text',
    'schema field' => 'detail_text',
    'setter callback' => 'entity_property_verbatim_set',
  );
  $info['utexas_event']['properties']['detail_format'] = array(
    'label' => t('Detail Format (Event)'),
    'description' => t('The text format of the long description.'),
    'type' => 'text',
    'schema field' => 'detail_format',
    'setter callback' => 'entity_property_verbatim_set',
  );

  return $info;
}

/**
 * UTexas Event UI class extending the EntityDefaultUIController class.
 */
class UtexasEventUIController extends EntityDefaultUIController {
  /**
   * Provides definitions for implementing hook_menu().
   */
  public function hook_menu() {
    $items = array();
    // Set this on the object so classes that extend hook_menu() can use it.
    $this->id_count = count(explode('/', $this->path));
    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';
    $plural_label = isset($this->entityInfo['plural label']) ? $this->entityInfo['plural label'] : $this->entityInfo['label'] . 's';

    $items[$this->path . '/add'] = array(
      'title callback' => 'entity_ui_get_action_title',
      'title arguments' => array('add', $this->entityType),
      'page callback' => 'entity_ui_get_form',
      'page arguments' => array($this->entityType, NULL, 'add'),
      'access callback' => 'entity_access',
      'access arguments' => array('create', $this->entityType),
      'type' => MENU_LOCAL_ACTION,
    );
    $items[$this->path . '/manage/' . $wildcard] = array(
      'title' => 'Edit',
      'title callback' => 'entity_label',
      'title arguments' => array($this->entityType, $this->id_count + 1),
      'page callback' => 'entity_ui_get_form',
      'page arguments' => array($this->entityType, $this->id_count + 1),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array(
        'update',
        $this->entityType,
        $this->id_count + 1,
      ),
    );
    $items[$this->path . '/manage/' . $wildcard . '/edit'] = array(
      'title' => 'Edit',
      'load arguments' => array($this->entityType),
      'type' => MENU_DEFAULT_LOCAL_TASK,
    );

    // Clone form, a special case for the edit form.
    $items[$this->path . '/manage/' . $wildcard . '/clone'] = array(
      'title' => 'Clone',
      'page callback' => '_utexas_event_clone_entity',
      'access arguments' => array(UTEXAS_EVENT_EDIT_PERMISSION),
    );
    // Menu item for operations like revert and delete.
    $items[$this->path . '/manage/' . $wildcard . '/%'] = array(
      'page callback' => 'drupal_get_form',
      'page arguments' => array(
        $this->entityType . '_operation_form',
        $this->entityType,
        $this->id_count + 1,
        $this->id_count + 2,
      ),
      'load arguments' => array($this->entityType),
      'access callback' => 'entity_access',
      'access arguments' => array(
        'delete',
        $this->entityType,
        $this->id_count + 1,
      ),
      'file' => 'includes/entity.ui.inc',
    );
    return $items;
  }
}

/**
 * UTexas Event entity class extending the Entity class.
 */
class UtexasEventEntity extends Entity {
  /**
   * Change the default URI from default/id to events/id.
   */
  protected function defaultUri() {
    return array('path' => 'events/' . $this->identifier());
  }
}

/**
 * Extends the EntityDefaultViewsController class.
 */
class EntityEventViewsController extends EntityDefaultViewsController {
  /**
   * Edit or add extra fields to views_data().
   */
  public function views_data() {
    $data = parent::views_data();

    // Define custom views handlers for various entity fields.
    $data['utexas_event']['operations'] = array(
      'title' => 'Events Operations',
      'help' => 'Edit, clone, and delete links.',
      'field' => array(
        'real field' => 'id',
        'handler' => 'utexas_events_handler_operations',
        'click sortable' => 1,
        'float' => '',
      ),
    );
    $data['utexas_event']['date_range'] = array(
      'title' => 'Event Date Range',
      'help' => 'Show span of date/time on an event.',
      'field' => array(
        'real field' => 'id',
        'handler' => 'utexas_events_handler_date_range',
        'click sortable' => 1,
        'float' => '',
      ),
    );
    return $data;
  }
}

/**
 * Extends the EntityAPIController for the Event entity.
 */
class UTexasEventEntityController extends EntityAPIController {
  /**
   * Extends buildContent().
   */
  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    $build = parent::buildContent($entity, $view_mode, $langcode, $content);

    global $base_url;
    // Set defaults.
    $title = FALSE;
    $location = FALSE;
    $image = FALSE;
    $thumbnail = FALSE;
    $detail_text = FALSE;
    $dates = FALSE;
    $times = FALSE;
    $ical = FALSE;
    $google_calendar = FALSE;
    $tag_list = FALSE;

    $lang = field_language('utexas_event', $entity, 'field_event_tags');
    if (isset($entity->field_event_tags[$lang])) {
      $items = $entity->field_event_tags[$lang];
      $tags = array();
      foreach ($items as $key => $term) {
        $term = taxonomy_term_load($term['tid']);
        $url = preg_replace('/\W+/', '-', strtolower($term->name));
        $tags[] = l($term->name, '/events/tag/' . $url, array('attributes' => array('class' => array('export'))));
      }
      $tag_list = theme_item_list(array(
        'items' => $tags,
        'type' => 'ul',
        'title' => 'Event Category',
        'attributes' => array('class' => array('tags')),
      ));
    }

    // Ensure title is sanitized.
    $title = $entity->title;
    $link = $base_url . '/events/' . $entity->id;
    $linked_title = l($title, $link, array(
      'attributes' => array('class' => array('headline-link')),
    ));

    // Get the location.
    $location = _utexas_event_get_location($entity, TRUE);

    // Load & style the image, if present.
    if (!empty($entity->image_fid)) {
      if ($file = file_load($entity->image_fid)) {
        $alt = (isset($file->field_file_image_alt_text['und'][0]['safe_value'])) ? $file->field_file_image_alt_text['und'][0]['safe_value'] : $title;
        $img_title = isset($file->field_file_image_title_text['und'][0]['safe_value']) ? $file->field_file_image_title_text['und'][0]['safe_value'] : $title;
        $info = image_get_info($file->uri);
        $base_promo_unit_style = array(
          'style_name' => 'utexas_promo_unit_square_image',
          'path' => $file->uri,
          'width' => $info['width'],
          'height' => $info['height'],
          'alt' => $alt,
          'title' => $img_title,
        );
        $image = theme('image_style', $base_promo_unit_style);
        $thumbnail_style = $base_promo_unit_style;
        $thumbnail_style['attributes'] = array('class' => array('post-image'));
        $thumbnail = theme('image_style', $thumbnail_style);
      }
    }
    // Format date & time using utexas_brand_guidelines_date_format().
    $times = 'All-day event';
    if ($entity->all_day !== '1') {
      $time_array = utexas_brand_guidelines_date_format(array('start' => $entity->start, 'end' => $entity->end), 'utexas_times');
      $times = $time_array['start'] . $time_array['end'];
    }
    $dates_array = utexas_brand_guidelines_date_format(array('start' => $entity->start, 'end' => $entity->end), 'utexas_days');
    $dates = $dates_array['start'];
    if (isset($dates_array['end'])) {
      $dates .= ' - ' . $dates_array['end'];
    }

    $google_calendar = _utexas_event_get_google_calendar_link($entity);

    // Add event-specific CSS.
    $build['#attached']['css'][] = drupal_get_path('module', 'utexas_event') . '/theme/utexas_event.css';

    $build += array(
      'title' => check_plain($title),
      'link' => $link,
      'linked_title' => $linked_title,
      'location' => $location,
      'image' => $image,
      'thumbnail' => $thumbnail,
      'detail_text' => check_markup($entity->detail_text, 'filtered_html'),
      'summary_text' => check_plain($entity->summary_text),
      'dates' => $dates,
      'times' => $times,
      'tags' => $tag_list,
      'ical' => l(t('Export to iCal'), $link . '/ical', array(
        'attributes' => array(
          'class' => array('export'),
        ),
      )),
      'google_calendar' => $google_calendar,
    );

    return $build;
  }
}
