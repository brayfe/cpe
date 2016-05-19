# features/twitter_widget.feature

@api @javascript
Feature: UTexas Twitter Widget
  In order add up-to-date social media to my site
  As a site builder
  I need to be able to add customizable twitter feeds

Scenario: Validate required fields
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Add twitter widget"
  And I press the "Save" button
  Then I should see the error message "Widget Label field is required."
  And I should see the error message "Twitter Account field is required."

Scenario: Add Twitter configuration
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Twitter Configuration"
  And I fill in "utaustin" for "edit-utexas-twitter-widget-owner"
  And I fill in "test" for "edit-utexas-twitter-widget-key"
  And I fill in "test" for "edit-utexas-twitter-widget-secret"
  And I press the "Save configuration" button
  Then I should see the error message "Could not authenticate you. The form has not been updated; any previously valid data you entered will remain active."

Scenario: Add Twitter configuration
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Twitter Configuration"
  And I fill in "utaustin" for "edit-utexas-twitter-widget-owner"
  And I add the credential "twitter_key" for "#edit-utexas-twitter-widget-key"
  And I add the credential "twitter_secret" for "#edit-utexas-twitter-widget-secret"
  And I fill in "200" for "edit-utexas-twitter-widget-cache-time"
  And I press the "Save configuration" button
  Then I should see the message "The configuration options have been saved."

Scenario: Validate account name
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Add twitter widget"
  And I fill in "Test Twitter Widget" for "edit-name"
  And I fill in "Test Headline" for "edit-headline"
  And I fill in "invalid_twitter_handle" for "edit-account"
  And I press the "Save" button
  Then I should see the error message "The Twitter username invalid_twitter_handle does not appear to be valid."

Scenario: Validate timeline list
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Add twitter widget"
  And I fill in "Test Twitter Widget" for "edit-name"
  And I fill in "Test Headline" for "edit-headline"
  And I fill in "utaustin" for "edit-account"
  And I fill in "invalid_timeline_list" for "edit-timeline-list"
  And I press the "Save" button
  Then I should see the error message "The Twitter timeline list invalid_timeline_list does not appear to be valid."

Scenario: Add Twitter widget data
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Add twitter widget"
  And I fill in "Test Twitter Widget" for "edit-name"
  And I fill in "Test Headline" for "edit-headline"
  And I fill in "utaustin" for "edit-account"
  And I fill in "ut-web-home" for "edit-timeline-list"
  And I select "6" from "count"
  And I fill in "View all test" for "edit-view-all"
  And I press the "Save" button
  Then I should see the message "The widget: Test Twitter Widget has been saved."

Scenario: Prevent duplicate Twitter widget names
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content"
  And I click "Twitter Widgets"
  And I click "Add twitter widget"
  And I fill in "Test Twitter Widget" for "edit-name"
  And I fill in "Test Headline" for "edit-headline"
  And I fill in "utaustin" for "edit-account"
  And I fill in "ut-web-home" for "edit-timeline-list"
  And I fill in "View all test" for "edit-view-all"
  And I press the "Save" button
  Then I should see the error message "The title Test Twitter Widget is already being used. Choose something else so that each widget can be easily identified."

Scenario: Assign widget to page
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/standard-page"
  And I fill in "Test Page" for "edit-title" in the "form_item_title" region
  And I click "Twitter Widget" in the "vertical_tabs" region
  When I select the radio button "Test Twitter Widget"
  And I press the "Save" button
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-5e45b57e2023b0d28f5a9dc785ea12fa"
  And I wait for css element ".field.field_utexas_twitter_widget" to "appear"
  And I click "Done" in the "context_editor" region
  And I press "Save" in the "ui_dialog_buttonset" region
  Then I should see "Test Headline" in the "twitter_widget_block" region
  And I should see the css element "#tweet-5"
  # Verify anonymous user access level
  Given I am an anonymous user
  When I visit "admin/content/twitter"
  Then I should see the text "Access Denied" in the "page_title" region
  When I visit "test-page"
  Then I should see "Test Headline" in the "twitter_widget_block" region

Scenario: Delete a twitter widget
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content/twitter"
  And I click "delete"
  And I press the "Confirm" button
  Then I should see the message "Deleted Twitter Widget Test Twitter Widget."
