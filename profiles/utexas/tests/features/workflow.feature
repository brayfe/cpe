# features/workflow.feature

@api
Feature: Workflow
  In order to build sites
  As various user roles
  I need to be able to manipulate content with the expected level of permission

@javascript
Scenario: Try to view an unpublished page and publish it: various roles

  # Standard Page Editor
  Given I am logged in as a user with the "Site Builder, Standard Page Editor" role
  And I set browser window size to "1200" x "900"
  When I go to "node/add/page"
  And I fill in "Test Unpublished Standard Page" for "edit-title"
  And I click "Publishing options" in the "vertical_tabs" region
  And I uncheck "Published"
  And I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Unpublished Standard Page"
  When I click "Test Unpublished Standard Page"
  And I click "Edit"
  And I fill in "Test Published Standard Page" for "edit-title"
  And I click "Publishing options" in the "vertical_tabs" region
  And I check "Published"
  Then I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Published Standard Page"

  # Landing Page Editor
  Given I am logged in as a user with the "Site Builder, Landing Page Editor" role
  And I set browser window size to "1200" x "900"
  When I go to "node/add/landing-page"
  And I click "Publishing options" in the "vertical_tabs" region
  And I fill in "Test Unpublished Landing Page" for "edit-title"
  And I uncheck "Published"
  And I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Unpublished Landing Page"
  When I click "Test Unpublished Landing Page"
  And I click "Edit"
  And I click "Publishing options" in the "vertical_tabs" region
  And I fill in "Test Published Landing Page" for "edit-title"
  And I check "Published"
  Then I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Published Landing Page"

  # Team Member Editor
  Given I am logged in as a user with the "Site Builder, Team Member Editor" role
  And I set browser window size to "1200" x "900"
  When I go to "node/add/team-member"
  And I fill in "Test" for "edit-custom-vertical-tabs-field-utexas-member-given-name-und-0-value"
  And I fill in "Unpublished" for "edit-custom-vertical-tabs-field-utexas-member-surname-und-0-value"
  And I select the radio button "Leadership"
  And I click "Publishing options" in the "vertical_tabs" region
  And I uncheck "Published"
  And I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Unpublished"
  When I click "Test Unpublished"
  And I click "Edit"
  And I fill in "Published" for "edit-custom-vertical-tabs-field-utexas-member-surname-und-0-value"
  And I click "Publishing options" in the "vertical_tabs" region
  And I check "Published"
  Then I press the "Save" button
  When I go to "admin/content"
  Then I should see the text "Test Published"
