# features/templates.feature

@api
Feature: UTexas Templates Behavior
  In order use the Page Builder module
  As a site builder
  I need to be able to create, review, update and delete existing templates

@javascript
Scenario: View Templates provided by module installation
  Given I am logged in as a user with the "administer templates,view templates" permission on this site
  And I set browser window size to "1200" x "900"
  When I click "Templates in the "toolbar"
  Then I should see the link "Hero Image & Sidebars" in the "content" region
  And I should see the link "Header with Content & Sidebars" in the "content" region
  And I should see the link "Hero Image & Sidebars" in the "content" region
  And I should see the link "Promotional Page & Sidebar" in the "content" region
  And I should see the link "Full Content Page & Sidebar" in the "content" region
  And I should see the link "Featured Highlight" in the "content" region
  And I should see the link "Full Width Content Page & Title" in the "content" region
  And I should see the link "Full Width Content Page" in the "content" region
  And I should see the link "Open Text Page" in the "content" region

Scenario: Anonymous user restricted from viewing
  Given I am on "admin/templates/"
  Then the response status code should be 403

@javascript
Scenario: Authenticated user restricted from viewing
  Given I am logged in as a user with the "authenticated user" role on this site
  When I visit "admin/templates/manage/1"
  Then I should see the text "Access Denied" in the "page_title" region

@javascript
Scenario: Add new template
  Given I am logged in as a user with the "administer templates,view templates" permission on this site
  When I visit "admin/templates/add"
  And I fill in "Behat Test" for "edit-name" in the "form_item_name" region
  And I fill in "Behat Test description" for "edit-description" in the "form_item_description" region
  And I check the box "edit-field-utexas-social-links-enabled"
  And I press the "Save template" button
  And I click "Behat Test"
  Then I should see the text "Behat Test" in the "content" region
  And I should see the text "page_builder_layouts/behat-test/behat-test.svg" in the "content" region
  And I should see the warning message "Missing"
  And I should see the text "page_builder_layouts/behat-test/page--behat-test.tpl.php" in the "content" region

@javascript
Scenario: Avoid duplicate templates
  Given I am logged in as a user with the "administer templates,view templates" permission on this site
  When I visit "admin/templates/add"
  And I fill in "Behat Test" for "edit-name" in the "form_item_name" region
  And I fill in "Behat Test description" for "edit-description" in the "form_item_description" region
  And I check the box "edit-field-utexas-social-links-enabled"
  And I press the "Save template" button
  Then I should see the error message "The title Behat Test conflicts with an existing template."

@javascript
Scenario: Edit existing template
  Given I am logged in as a user with the "administer templates,view templates" permission on this site
  When I visit "admin/templates"
  And I click "Behat Test"
  And I click "Edit"
  And I fill in "Name Change" for "edit-name" in the "form_item_name" region
  And I press the "Update template" button
  Then I should see the message "The template: Name Change has been saved."
  And I should see the message "Note: the name Behat Test was changed to Name Change. Make sure that your template file is page--name-change.tpl.php and your image file is name-change.svg. You will also need to reassign this template to the existing content types."

Scenario: Delete a template
  Given I am logged in as a user with the "administer templates,view templates" permission on this site
  When I visit "admin/templates"
  And I click "Name Change"
  And I click "Delete"
  And I press the "Confirm" button
  Then I should see the message "Deleted Template Name Change."
  And I should not see the text "Name Change" in the "content" region