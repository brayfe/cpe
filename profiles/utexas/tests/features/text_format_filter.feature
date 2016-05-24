# features/text_format_filter.feature

@api

Feature: Text Format Filter
  In order to display rich text correctly via WYSIWYG field
  As a site-builder
  I need to see that the output provides expected HTML

@javascript
Scenario: User can add text to a WYSIWYG field an see no empty <p> tags
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/add/page"
  And I fill in "Test Content" for "edit-title" in the "form_item_title" region
  And I the set the iframe located in element with an id of "cke_edit-body-und-0-value" to "body"
  And I fill in "Lorem ipsum dolor sit amet." in WYSIWYG editor "body"
  And I press the "Save" button
  Then I should see the message "Basic page Test Content has been created."
  Then I should see the text "Test Content" in the "page_title" region
  And I should not see HTML "\<p\>\<br\>\<\/p\>" in the ".field.body" region

