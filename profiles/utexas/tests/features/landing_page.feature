# features/landing_page.feature

@api @javascript @media_upload

Feature: Landing Page Content Type
  In order to add overview/feature pages
  As a site-builder
  I need to be able to place content on a landing page

Scenario: User adds available content to landing page
  Given I am logged in as a user with the "administrator" role
  When I click "Add content"
  And I click "Landing Page"
  # Quick Links #
  And I click on the link "Quick Links" in the ".vertical-tabs-list" region
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
  And I fill in "Landing Page Test" for "edit-title" in the "form_item_title" region
  # Add WYSIWYG A #
  And I click on the link "WYSIWYG A" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "cke_edit-field-wysiwyg-a-und-0-value" to "wysiwyg_a"
  And I fill in "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." in WYSIWYG editor "wysiwyg_a"
  # Add UT Newsreel #
  And I click on the link "UT Newsreel" in the ".vertical-tabs-list" region
  And I fill in "Headline Text" for "edit-field-utexas-newsreel-und-0-headline"
  And I check the box "edit-field-utexas-newsreel-und-0-category-science-and-technology"
  And I fill in "View all Test" for "edit-field-utexas-newsreel-und-0-view-all"
  And I fill in "Landing Page Test" for "edit-title" in the "form_item_title" region
  # Add Featured Highlight #
  And I click on the link "Featured Highlight" in the ".vertical-tabs-list" region
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
  And I fill in "Lorem Ipsum" for "edit-field-utexas-featured-highlight-und-0-headline" in the "featured_highlight_widget" region
  And I click on the element "#edit-field-utexas-featured-highlight-und-0-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "560x315.png" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur." for "edit-field-utexas-featured-highlight-und-0-copy-value" in the "featured_highlight_widget" region
  And I fill in "Dolor sit amet" for "edit-field-utexas-featured-highlight-und-0-call-title" in the "featured_highlight_widget" region
  And I fill in "<front>" for "edit-field-utexas-featured-highlight-und-0-call-link" in the "featured_highlight_widget" region
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
  # Quick Links #
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content_top_left" region
  And I click on the element "#context-block-addable-fieldblock-eab8c417f7d28e9571473905cfebbd5b"
  And I wait for css element ".field.field_utexas_quick_links" to "appear"
  # Save #
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  # Verify themed output #
  Then I should see the heading "Landing Page Test"
  And I should see "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum." in the "wysiwyg_a_block" region
  And I should see the css element ".news-item.item-3"
  And I should not see the css element ".news-item.item-4"
  And I should see the css element ".news-description"
  And I should see "Headline Text" in the "utexas_newsreel_block" region
  And I should see "View all Test" in the "utexas_newsreel_block" region
  And I should see the link "behat test link title5" in the "quick_links_block" region
  And I should see the link "Lorem Ipsum" in the "highlight_headline" region
  And I should see the link "Dolor sit amet" in the "highlight_text" region
  And I should see the text "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur." in the "highlight_text" region
  And I should see today's AP style date in the css element ".highlight-date"
  And I should see the image path "featured-highlights/560x315" in the css element ".featured-highlight"







