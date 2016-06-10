# features/video_filter.feature

@api

Feature: Video Filter
  In order to use the contrib Video Filter and its button
  As a site-builder
  I need to be able to supply populated quick link fields to a page

@javascript
Scenario: User can add a Qualtrics form and fulfill it.
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click on the link "WYSIWYG A" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "cke_edit-field-wysiwyg-a-und-0-value" to "wysiwyg_a"
  And I fill in "This is a perfect example of a video embed. [video:https://www.youtube.com/watch?v=cyohHyQl-kc]" in WYSIWYG editor "wysiwyg_a"
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been created."
  Then I should see the text "test form" in the "page_title" region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "main_content" region
  And I should see the text "Content" in the "main_content" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-fda604d130a57f15015895c8268f20d2"
  And I wait for css element ".field.field_wysiwyg_a" to "appear"
  And I click "Done" in the "context_editor" region
  And I press "Save" in the "ui_dialog_buttonset" region
  And I wait for 2 seconds
  Then I should see an "iframe" element
  And I the set the iframe located in element with an id of "block-fieldblock-node-standard-page-default-field-wysiwyg-a" to "video_filter"
  And I switch to the iframe "video_filter"

