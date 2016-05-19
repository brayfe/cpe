# features/subnav.feature

@api @javascript

Feature: Sub-navigation menu block
  In order to clarify site page hierarchy
  As a site-builder
  I need to be able to place a sub navigation menu block on a page

Scenario: User adds subnav to standard page
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I click "Structure"
  And I click "Blocks"
  And I click "Add menu block"
  And I press "Advanced options"
  And I fill in "<none>" for "Block title"
  And I select "-- About" from "Fixed parent item"
  And I press "Save block"
  And I click "Find content"
  And I click "Welcome to Your New Site"
  # Assign fields to regions #
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  # Add Sub Nav #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-main_content_top_left" region
  And I click on the element "#context-block-addable-menu_block-1"
  And I wait for css element ".subnav" to "appear"
  # Save #
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  And I wait for css element ".subnav" to "appear"
  # Verify themed output #
  Then I should see the link "L3 item 1" in the "subnav" region
  And I should not see "Test Subnav" in the "block_menu_block_1" region
  # Add a block title #
  When I click "Structure"
  And I click "Blocks"
  And I click "configure" in the "About (levels 1+)" row
  And I fill in "Test Subnav" for "Block title"
  And I press "Save block"
  And I run drush "cache-clear all"
  And I click "Find content"
  And I click "Welcome to Your New Site"
  Then I should see the link "L3 item 1" in the "subnav" region
  And I should see "Test" in the "block_menu_block_1" region
