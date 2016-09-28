# features/events.feature

# You need default content to run this test

@api @javascript @media_upload @drush

Feature: Team Member Content Type
  In order to add and managed events
  As a site-builder
  I need an interface to add pre-themed events content


@javascript @api
Scenario: Validating empty fields
  Given I am logged in as a user with the "complete" permissions on this site
  And I set browser window size to "1200" x "900"
  And I click "Find content"
  And I click "Events"
  And I click "Add event"
  # Add an event with no optional fields
  And I fill in "Woodstock" for "edit-title"
  And I press the "Save" button
  And I click "Woodstock"
  Then I should see HTML '\<div class="event-headline"\>Woodstock\<\/div\>' in the '.event-details' region

  # Edit event and add all additional non-date fields
  And I click "Find content"
  And I click "Events"
  And I click "Edit"
  And I fill in "Max Yasgur Dairy Farm" for "edit-field-event-location-und"
  And I fill in "Music" for "edit-field-event-tags-und"
  # Image
  And I click on the element "#edit-image-fid-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "560x315.png" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  # Summary & Detail
  And I fill in "An Aquarian Exposition in White Lake, NY. 3 Days of Peace & Music." for "edit-summary-text"
  And I the set the iframe located in element with an id of "cke_edit-detail-text-value" to "utexas_event_detail"
  And I fill in "What would you do if I sang out of tune?" in WYSIWYG editor "utexas_event_detail"
  And I check the box 'Display this in the "Featured Events" block.'
  And I press the "Update" button
  And I click "Woodstock"
  # Verify display
  Then I should see HTML '\<div class=\"event-location\">Max Yasgur Dairy Farm\<\/div\>' in the '.event-details' region
  And I should see the css element ".post-image img" with the attribute "src" with the value containing "/event-image/560x315"
  Then I should see HTML '\<p\>What would you do if I sang out of tune?\<\/p\>' in the '.field_wysiwyg_a' region

  # Manipulate date fields
  And I click "Find content"
  And I click "Events"
  And I click "Edit"
  And I fill in "Monday 15 Aug 2017" for "edit-start-date-datepicker-popup-0"
  And I fill in "11:45 pm" for "start_time[time]"
  And I press the "Update" button
  Then I should see the error message "The end time must be the same as or later than the start time."
  And I check the box "The end date is different than the start date."
  Then I wait for 3 seconds
  And I fill in "Sunday 14 Aug 2017" for "edit-end-date-datepicker-popup-0"
  And I press the "Update" button
  Then I should see the error message "The end date must the same as or later than the start date."
  And I fill in "Wednesday 17 Aug 2017" for "edit-end-date-datepicker-popup-0"
  Then I check the box "This is an all-day event"
  Then I wait for 3 seconds
  And I press the "Update" button
  And I click "Woodstock"
  Then I should see HTML '\<div class=\"event-date\">Aug. 15  - 17\<\/div\>' in the '.event-details' region
  Then I should see HTML 'All-day event' in the '.event-time' region

  # Clone an event
  When I click "Find content"
  And I click "Events"
  And I click "Clone"
  And I press the "Update" button
  Then I should see the link "Clone of Woodstock"

  # Add Events blocks to page
  When I run drush 'php-eval "_utexas_event_add_demo_content(15);"'
  And I click "Add content"
  And I click "Standard Page"
  And I fill in "Events Test" for "edit-title" in the "form_item_title" region
  And I press the "Save" button
  # Assign fields to regions #
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  # Upcoming Events, titles #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_right" region
  And I click on the element "#context-block-addable-views-events-block_2"
  And I wait for css element "#block-views-events-block-2" to "appear"
  # Featured Events, titles #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_right" region
  And I click on the element "#context-block-addable-views-events-block_3"
  And I wait for css element "#block-views-events-block-3" to "appear"
  # Upcoming Events, teasers #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content" region
  And I click on the element "#context-block-addable-views-events-block_1"
  And I wait for css element "#block-views-events-block-1" to "appear"
  # Featured Events, teasers #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content" region
  And I click on the element "#context-block-addable-views-events-block_4"
  And I wait for css element "#block-views-events-block-4" to "appear"
  # Save #
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  # Verify themed output #
  Then I should see HTML '\<h3 class="sidebar-headline"\>Featured Events\</h3\>' in the '#block-views-events-block-3' region
  And I should see HTML '\<h3 class="sidebar-headline"\>Upcoming Events\</h3\>' in the '#block-views-events-block-2' region
  And I should see HTML '\<h2\>Upcoming Events\</h2\>' in the '#block-views-events-block-1' region
  And I should see HTML '\<h2\>Featured Events\</h2\>' in the '#block-views-events-block-4' region

  # Configure Events
  When I click "Find content"
  And I click "Events"
  And I click "Configure events"
  And I fill in "Upcoming Foo" for "edit-utexas-events-upcoming-block-title"
  And I select "1" from "edit-utexas-events-upcoming-block-count"
  And I fill in "Featured Bar" for "edit-utexas-events-featured-block-title"
  And I select "1" from "edit-utexas-events-featured-block-count"
  Then I press the "Save configuration" button

  # Verify modified configuration
  When I visit "events-test"
  Then I should see HTML '\<h3 class="sidebar-headline"\>Featured Bar\</h3\>' in the '#block-views-events-block-3' region
  And I should see HTML '\<h3 class="sidebar-headline"\>Upcoming Foo\</h3\>' in the '#block-views-events-block-2' region
  And I should see HTML '\<h2>Upcoming Foo</h2>' in the '#block-views-events-block-1' region
  And I should see HTML '\<h2\>Featured Bar\</h2\>' in the '#block-views-events-block-4' region

  # Bulk delete events
  And I click "Find content"
  And I click "Events"
  And I select the checkbox with class "vbo-table-select-all"
  And I select "Delete item" from "operation"
  And I press the "Execute" button
  And I press the "Confirm" button
