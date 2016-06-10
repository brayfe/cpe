# features/background_accent.feature

@api @javascript @media_upload
Feature: Background Accent
  In order brand individual landing pages
  As a site builder
  I need to be able to add a background image to the related content region

Scenario: Demonstrate adding an image and its presence on a page
  Given I am logged in as a user with the "administrator" role on this site
  When I go to "node/add/landing-page"
  And I fill in "Test Background Image" for "edit-title" in the "form_item_title" region
  And I click on the link "Background Accent" in the ".vertical-tabs-list" region
  And I click "edit-field-utexas-background-accent-und-0-utexas-background-accent-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "background-accent.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I click "Social Links" in the "vertical_tabs" region
  And I wait for css element "#edit-field-utexas-social-links-und-0-links-facebook" to "appear"
  And I fill in "http://facebook.com" for "edit-field-utexas-social-links-und-0-links-facebook"
  And I press the "Save" button
  Then I should see the text "Test Background Image" in the "page_title" region
  And I should see the ".container.container-bottom.accent" css selector with css property "position" containing "relative"
  And I should see the ".container.container-bottom.accent .field_utexas_social_links" css selector with css property "background-color" containing "rgb(255, 255, 255)"
  And I should see the ".container.container-bottom.accent .field_utexas_social_links " css selector with css property "border" containing "1px solid rgb(51, 63, 72)"
  And I should see the ".container.container-bottom.accent" css selector with pseudo element ":before" with css property "background-image" containing "files/styles/utexas_background_accent/public/background-accents/background-accent"
  And I should see the ".container.container-bottom.accent" css selector with pseudo element ":before" with css property "background-size" containing "cover"
  And I should see the ".container.container-bottom.accent" css selector with pseudo element ":before" with css property "background-repeat" containing "no-repeat"
  And I should see the ".container.container-bottom.accent" css selector with pseudo element ":before" with css property "background-position" containing "50% 50%"


