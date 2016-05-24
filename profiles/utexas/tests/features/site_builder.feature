# features/site_builder.feature

@api
Feature: Site Builder
  In order to build sites
  As a site builder
  I need to be able to perform the tasks associated with site-building

@javascript
Scenario: Perform actions with site-builder permissions

  # Validate login
  Given I am logged in as a user with the "site builder, standard page editor" role
  And I set browser window size to "1200" x "900"
  When I go to "node/add/standard-page"
  Then I should see the css element ".toolbar-menu"
  And I set browser window size to "1200" x "900"

  # Create page
  And I go to "/admin/content"
  And I click "Add content"
  And I click "Standard Page"
  Then I should see the text "Create Standard Page" in the "branding" region
  And I fill in "Standard Page Test" for "edit-title" in the "form_item_title" region
  # Add hero image
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  # Add WYSIWYG A #
  And I click on the link "WYSIWYG A" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "cke_edit-field-wysiwyg-a-und-0-value" to "wysiwyg_a"
  And I fill in "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." in WYSIWYG editor "wysiwyg_a"
  # Save #
  And I press the "Save" button
  Then I should see the message "Standard Page Standard Page Test has been created."

  # Use the layout editor to place a block
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_right" region
  And I click on the element "#context-block-addable-fieldblock-fda604d130a57f15015895c8268f20d2"
  # Save #
  And I wait for css element ".field.field_wysiwyg_a" to "appear"
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  # Verify themed output #
  Then I should see the heading "Standard Page Test"
  And I should see "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." in the "wysiwyg_a_block" region

  # Verify Site Builder cannot access designated configuration pages
  When I go to "/admin/config/utexas/google_cse"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/config/utexas/twitter"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/config/system/utexas_google_tag_manager"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/config/system/cron"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/structure"
  Then I should see "Add new menus" in the "page" region
  And I should not see "Views" in the "page" region
  And I should not see "Context" in the "page" region
  When I go to "/admin/people"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/modules"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/templates/manage/1"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/appearance/settings/bartik"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/admin/appearance/settings/forty_acres"
  Then I should see "You are not authorized to access this page." in the "page" region
  When I go to "/node/add"
  Then I should not see "Landing Page" in the "page" region
  And I should not see "Team Member" in the "page" region
  And I should not see "Faculty Profile" in the "page" region
  And I should see "Standard Page" in the "page" region
  And I should see "Basic page" in the "page" region
