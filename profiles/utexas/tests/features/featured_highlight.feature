# features/featured_highlight.feature

@api @media_upload
Feature: Featured Highlight
#  In order use the Featured Highlight widget
#  As a site builder
#  I need to be able to add fully formatted highlights to a page

@javascript
Scenario: Validate copy field and URL field
#  Given I am logged in as a user with the "view the administration theme,create standard_page content" permission
#  When I go to "node/add/standard-page"
#  And I fill in "Test Featured Highlight" for "edit-title" in the "form_item_title" region
#  And I click on the element "#featured_highlight"
#  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
#  And I fill in "Test Featured Highlight" for "edit-field-utexas-featured-highlight-und-0-headline" in the "featured_highlight_widget" region
#  And I fill in "nonexistent-link" for "edit-field-utexas-featured-highlight-und-0-call-link" in the "featured_highlight_widget" region
#  And I press the "Save" button
#  Then I should see the error message "Featured Highlight: Copy field is required."
#  And I should see the error message "Featured Highlight: The path provided is not a valid URL alias or external link."

@javascript
Scenario: Verify themed output
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "Test Featured Highlight" for "edit-title" in the "form_item_title" region
  And I click on the element "#featured_highlight"
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
  And I fill in "Lorem Ipsum" for "edit-field-utexas-featured-highlight-und-0-headline" in the "featured_highlight_widget" region
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "560x315.png" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I fill in "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur." for "edit-field-utexas-featured-highlight-und-0-copy-value" in the "featured_highlight_widget" region
  And I fill in "Dolor sit amet" for "edit-field-utexas-featured-highlight-und-0-call-title" in the "featured_highlight_widget" region
  And I fill in "<front>" for "edit-field-utexas-featured-highlight-und-0-call-link" in the "featured_highlight_widget" region
  And I press the "Save" button
  Then I should see the text "Test Featured Highlight" in the "page_title" region
  And I should see the link "Lorem Ipsum" in the "highlight_headline" region
  And I should see the link "Dolor sit amet" in the "highlight_text" region
  And I should see the text "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur." in the "highlight_text" region
  And I should see today's AP style date in the css element ".highlight-date"
  And I should see the image path "featured-highlights/560x315" in the css element ".featured-highlight"
  And I should see the css selector ".featured-highlight" with the attribute "alt" with the exact value "Placeholder Image"
  And I should see the css selector ".featured-highlight" with the attribute "title" with the exact value "Placeholder Title"

  # User adds a youtube video
  Then I click "Edit" in the "primary_tabs" region
  And I click on the element "#edit-field-utexas-featured-highlight-und-0-image-remove-button"
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-image-browse-button" to appear
  And I click on the element "#edit-field-utexas-featured-highlight-und-0-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I click "Library"
  And I click on the element "#media-item-2"
  And I click "Submit"
  And I press the "Save" button
  And I wait for css element "iframe.media-youtube-player" to appear
  Then I should see the css element "iframe.media-youtube-player" with the attribute "title" with the value containing "What is the UT Drupal Kit?"

  # Testing Light Highlight Style
  And I click "Edit" in the "primary_tabs" region
  And I click on the element "#featured_highlight"
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
  When I select the radio button "Light" with the id "edit-field-utexas-featured-highlight-und-0-highlight-style-light"
  And I press the "Save" button
  Then I should see the css element ".field_utexas_featured_highlight .light"
  And I should see the ".field_utexas_featured_highlight.light" css selector with css property "background-color" containing "rgb(214, 210, 196)"

  # Testing Dark Highlight Style
  And I click "Edit" in the "primary_tabs" region
  And I click on the element "#featured_highlight"
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
  When I select the radio button "Dark" with the id "edit-field-utexas-featured-highlight-und-0-highlight-style-dark"
  And I press the "Save" button
  Then I should see the css element ".field_utexas_featured_highlight .dark"
  And I should see the ".field_utexas_featured_highlight.dark" css selector with css property "background-color" containing "rgb(106, 99, 97)"
