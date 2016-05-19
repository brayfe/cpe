# features/utexas_admin.feature

@api @javascript @media_upload
Feature: UTexas Admin
  In order to leverage the full functionality of the UTexas distribution
  As a site builder
  I need certain global actions to work properly.


Scenario: Verify jQuery version is correct on node forms and allows add/remove.
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "Test Page" for "edit-title" in the "form_item_title" region
  And I click on the link "Flex Content Area A" in the ".vertical-tabs-list" region
  And I click on the element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I click "Library"
  And I click on the element ".media-item"
  And I click "Submit"
  And I wait for css element "#edit-field-utexas-flex-content-area-a-und-0-image-remove-button" to appear
  And I click on the element "#edit-field-utexas-flex-content-area-a-und-0-image-remove-button"
  And I wait for css element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button" to appear
  And I click on the element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  # If jQuery library is not correct, the test should fail here.
  And I click "Library"
  And I click on the element ".media-item"
  And I click "Submit"
  And I press the "Save" button
  Then I should see the text "Test Page" in the "page_title" region


