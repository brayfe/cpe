# features/templates.feature

@api
Feature: Node Revisioning
  In order use the Page Builder module with existing Drupal functionality
  As a site builder
  I need to be able to make revisions of Page Builder-enabled nodes.

@javascript
Scenario: Verify
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I click "Add content"
  And I click "Landing Page"
  And I fill in "Revisions Test" for "edit-title" in the "form_item_title" region
  # Add WYSIWYG A #
  And I click on the link "WYSIWYG A" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "cke_edit-field-wysiwyg-a-und-0-value" to "wysiwyg_a"
  And I fill in "Revision 1" in WYSIWYG editor "wysiwyg_a"
  # Add UT Newsreel #
  And I click on the link "UT Newsreel" in the ".vertical-tabs-list" region
  And I fill in "Headline Text" for "edit-field-utexas-newsreel-und-0-headline"
  And I check the box "edit-field-utexas-newsreel-und-0-category-science-and-technology"
  And I fill in "View all Test" for "edit-field-utexas-newsreel-und-0-view-all"
  And I press the "Save" button
  # Assign fields to regions #
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  # WYSIWYG A #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_left" region
  And I click on the element "#context-block-addable-fieldblock-6f3b85225f51542463a88e53104f8753"
  # UT Newsreel #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_right" region
  And I click on the element "#context-block-addable-fieldblock-d41b4a03ee9d7b1084986f74b617921c"
  And I wait for css element ".field.field_utexas_newsreel" to "appear"
  # Save #
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  # Verify themed output #
  And I should see "Revision 1" in the "wysiwyg_a_block" region
  And I click "Edit" in the "primary_tabs" region
  # Revise WYSIWYG A #
  And I click on the link "WYSIWYG A" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "cke_edit-field-wysiwyg-a-und-0-value" to "wysiwyg_a"
  And I fill in "Revision 2" in WYSIWYG editor "wysiwyg_a"
  And I click on the element "a" in the ".vertical-tabs-list" region containing the text "Revision information"
  And I fill in "This is a new revision" for "edit-log"
  And I check the box "edit-revision"
  And I press the "Save" button
  Then I should see "Revision 2" in the "wysiwyg_a_block" region
  # Revert a revision #
  And I click "Revisions" in the "primary_tabs" region
  And I click "revert"
  And I wait for css element "#edit-submit" to "appear"
  And I press the "Revert" button
  And I click "View" in the "primary_tabs" region
  Then I should see "Revision 1" in the "wysiwyg_a_block" region



