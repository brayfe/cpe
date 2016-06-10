# features/quick_links.feature

@api

Feature: Quick Links
  In order to use the Quick Links widget
  As a site-builder
  I need to be able to supply populated quick link fields to a page

@javascript
Scenario: User with correct permissions can add fields
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click "Quick Links" in the "vertical_tabs" region
  And I fill in "behat quick_link test" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "behat test link title" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I fill in "google.com" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I press the "Save" button
  Then I should see the error message "Quick Links: The path provided is not a valid URL alias or external link."
  And I fill in "http://www.google.com" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been created."
  Then I should see the text "test form" in the "page_title" region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-669a6a1f32566fa73ea7974696027184"
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  And I click "Done" in the "context_editor" region
  Then I should see "behat quick_link test" in the "quick_links_block" region

@javascript
Scenario: User can enter more than 5 quick links
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click "Quick Links" in the "vertical_tabs" region
  And I fill in "behat quick_link test" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "behat test link title1" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I fill in "behat test link title2" for "edit-field-utexas-quick-links-und-0-links-1-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-1-link-url"
  And I fill in "behat test link title3" for "edit-field-utexas-quick-links-und-0-links-2-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-2-link-url"
  And I fill in "behat test link title4" for "edit-field-utexas-quick-links-und-0-links-3-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-3-link-url"
  And I fill in "behat test link title5" for "edit-field-utexas-quick-links-und-0-links-4-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-4-link-url"
  And I click on the element "#edit-submit"
  Then I should see the message "Standard Page test form has been created."
  And I wait for css element ".tabs.primary" to "appear"
  And I click "Edit" in the "primary_tabs" region
  And I click "Quick Links" in the "vertical_tabs" region
  And I fill in "behat test link title6" for "edit-field-utexas-quick-links-und-0-links-5-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-5-link-url"
  And I click on the element "#edit-submit"
  Then I should see the message "Standard Page test form has been updated."
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "context_layout" region
  And I should see the text "Content" in the "context_layout" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-669a6a1f32566fa73ea7974696027184"
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  And I click "Done" in the "context_editor" region
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  Then I should see the link "behat test link title6" in the "quick_links_block" region

@javascript
Scenario: When a link is entered without a title, an absolute URL displays
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/standard-page"
  And I fill in "Quick Links Test" for "edit-title" in the "form_item_title" region
  And I click "Quick Links" in the "vertical_tabs" region
  And I fill in "Quick Link Test" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I fill in "<front>" for "edit-field-utexas-quick-links-und-0-links-1-link-url"
  And I fill in "node/1" for "edit-field-utexas-quick-links-und-0-links-2-link-url"
  And I click on the element "#edit-submit"
  Then I should see the message "Standard Page Quick Links Test has been created."
  And I wait for css element ".tabs.primary" to "appear"
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "context_layout" region
  And I should see the text "Content" in the "context_layout" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-669a6a1f32566fa73ea7974696027184"
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  And I click "Done" in the "context_editor" region
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  Then I should see the link "http://google.com" in the "quick_links_block" region

