# features/custom_block.feature

@api @javascript

Feature: Custom block integration with layout editor
  In order to display custom blocks with the layout editor
  As a site-builder
  I need to be able to place a custom block on a page built with page-builder

Scenario: User adds custom blaock to standard page
  Given I am logged in as a user with the "administrator" role on this site
  # create custom block
  And I click "toolbar-link-admin-structure"
  And I click "Blocks"
  And I click "Add block"
  And I fill in "test block" for "Block title"
  And I fill in "test block" for "Block description"
  And I select "Plain text" from "Text format"
  And I fill in "Cat ipsum dolor sit amet, give attitude for spread kitty litter all over house. Hack up furballs stare at the wall, play with food and get confused by dust and mew attack feet run in circles. Caticus cuteicus paw at your fat belly yet missing until dinner time, or sit by the fire." for "Block body"
  And I click on the element "#edit-submit"
  And I click "Home"
  # assign custom block with layout editor
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-main_content_top_left" region
  And I click on the element "#context-block-addable-block-1"
  And I wait for css element "#block-block-1" to "appear"
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  # test for custom block prescence on page
  Then I should see the text "Cat ipsum dolor sit amet, give attitude for spread kitty litter all over house. Hack up furballs stare at the wall, play with food and get confused by dust and mew attack feet run in circles. Caticus cuteicus paw at your fat belly yet missing until dinner time, or sit by the fire." in the "top_left_region" region



