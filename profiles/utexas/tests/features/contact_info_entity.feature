# features/contact_info_entity.feature

@api @javascript
Feature: UTexas Contact Info
  In order add contact info forms to the site pages
  As a site builder
  I need to be able to add customizable contact info forms


Scenario: Validate Required Title field. Validate Location and Address Zip Codes only to allow "11111" or "11111-1111" format. Validate Website, Phone, Fax and Email fields and Creating a valid Contact Info Form
  Given I am logged in as a user with the "view the administration theme,access content overview,access content,administer nodes,view contact info forms,administer contact info forms" permission on this site
  And I set browser window size to "1200" x "900"
  When I go to "admin/content"
  And I click "Contact Info"

  # Validating Required Title
  And I click "Add contact info"
  And I press the "Save" button
  Then I should see the error message "Title field is required."

  # Validating Location and Address Zip Codes
  And I fill in "Contact Info" for "edit-name"
  And I fill in "781234" for "edit-field-location-zip"
  And I fill in "7812" for "edit-field-address-zip"
  And I press the "Save" button
  Then I should see the message "Not a valid Location Zip Code (e.g, 78123 or 78123-5678)"
  And I should see the message "Not a valid Address Zip Code (e.g, 78123 or 78123-5678)"

  # Validating Website, Phone, Fax and Email
  And I fill in "Contact Info" for "edit-name"
  And I fill in "google.com" for "edit-field-url"
  And I fill in "1111111111" for "edit-field-phone"
  And I fill in "111-111-11111" for "edit-field-fax"
  And I fill in "bademail@email" for "edit-field-email"
  And I press the "Save" button
  Then I should see the error message "Not a valid Phone Number (e.g, 123-456-7890)"
  And I should see the error message "Not a valid Fax Number (e.g, 123-456-7890)"
  And I should see the error message "Not a valid Email format (e.g, email@domain.com)"
  And I should see the error message "Not a valid URL (e.g, http://validurl.com)"

  # Adding valid form after validating all the fields
  And I fill in "795 E Dragon" for "edit-field-location-1"
  And I fill in "#123" for "edit-field-location-2"
  And I fill in "SUITE 5A-1204" for "edit-field-location-3"
  And I fill in "Austin" for "edit-field-location-city"
  And I fill in "Texas" for "edit-field-location-state"
  And I fill in "78711" for "edit-field-location-zip"
  And I fill in "795 N Polo" for "edit-field-address-1"
  And I fill in "#123" for "edit-field-address-2"
  And I fill in "SUITE 5A-1204" for "edit-field-address-3"
  And I fill in "Austin" for "edit-field-address-city"
  And I fill in "Texas" for "edit-field-address-state"
  And I fill in "78711-0000" for "edit-field-address-zip"
  And I fill in "http://google.com" for "edit-field-url"
  And I fill in "512-111-1111" for "edit-field-phone"
  And I fill in "111-111-1111" for "edit-field-fax"
  And I fill in "goodemail@email.com" for "edit-field-email"
  And I press the "Save" button
  Then I should see the message "The contact info form: Contact Info has been saved."

Scenario: Prevent duplicate Contact Info names
  Given I am logged in as a user with the "view the administration theme,access content overview,access content,administer nodes,view contact info forms,administer contact info forms" permission on this site
  When I go to "admin/content"
  And I click "Contact Info"
  And I click "Add contact info"
  And I fill in "Contact Info" for "edit-name"
  And I press the "Save" button
  Then I should see the error message "The title Contact Info is already being used. Choose something else so that each form can be easily identified."

Scenario: Assign contact info to a page
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/standard-page"
  And I fill in "Test Page" for "edit-title" in the "form_item_title" region
  And I click "Contact Info" in the "vertical_tabs" region
  When I select the radio button "Contact Info"
  And I press the "Save" button
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-38205d43426b33bd0fe595ff8ca61ffd"
  And I wait for css element ".field.field_utexas_contact_info" to "appear"
  And I click "Done" in the "context_editor" region
  And I press "Save" in the "ui_dialog_buttonset" region
  Then I should see "Contact Info" in the "field_contact_info" region
  # Verify anonymous user access level
  Given I am an anonymous user
  When I visit "admin/content/contact_info"
  Then I should see the text "Access Denied" in the "page_title" region
  When I visit "test-page"
  Then I should see "Contact Info" in the "field_contact_info" region

Scenario: Delete a Contact Info Form
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "admin/content/contact_info"
  Given I click "delete" in the "Contact Info" row
  And I press the "Confirm" button
  Then I should see the message "Deleted Contact Info Contact Info."
