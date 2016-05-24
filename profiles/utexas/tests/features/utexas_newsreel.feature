# features/utexas_newsreel.feature

@api

Feature: UT News
  In order to featured related UT News
  As a site-builder
  I need to be able to add a categorized feed of UT News items to a page

@javascript
Scenario: User adds a Newsreel with defaults
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/add/standard-page"
  And I fill in "UT Newsreel Test" for "edit-title" in the "form_item_title" region
  And I press the "Save" button
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  And I click on the element ".main-content .context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-8e85c2c89f0ccf26e9e4d0378250bf17"
  And I wait for css element ".field.field_utexas_newsreel" to "appear"
  And I click "Done" in the "context_editor" region
  Then I should see the message "Standard Page UT Newsreel Test has been created."
  And I should see the css element ".news-item.item-3"
  And I should not see the css element ".news-item.item-4"
  And I should see the css element ".news-description"
  And I should see "Latest from UTNews" in the "utexas_newsreel_block" region
  And I should see "View all news" in the "utexas_newsreel_block" region

@javascript
Scenario: User can customize and place a UT Newsreel
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/standard-page"
  And I fill in "UT Newsreel Test" for "edit-title" in the "form_item_title" region
  And I click "UT Newsreel" in the "vertical_tabs" region
  And I fill in "Headline Text" for "edit-field-utexas-newsreel-und-0-headline"
  And I select "7" from "edit-field-utexas-newsreel-und-0-count"
  And I check the box "edit-field-utexas-newsreel-und-0-category-science-and-technology"
  And I uncheck the box "Include article teaser text?"
  And I fill in "View all Test" for "edit-field-utexas-newsreel-und-0-view-all"
  And I press the "Save" button
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  And I click on the element ".main-content .context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-8e85c2c89f0ccf26e9e4d0378250bf17"
  And I wait for css element ".field.field_utexas_newsreel" to "appear"
  And I click "Done" in the "context_editor" region
  Then I should see the message "Standard Page UT Newsreel Test has been created."
  And I should see the css element ".news-item.item-6"
  And I should not see the css element ".news-item.item-7"
  And I should not see the css element ".news-description"
  And I should see "Headline Text" in the "utexas_newsreel_block" region
  And I should see "View all Test" in the "utexas_newsreel_block" region









