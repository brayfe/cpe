# features/social_links.feature

@api

Feature: Social Links
  In order to use the Social Links widget
  As a site-builder
  I need to be able to create, update, and delete social links

@javascript
Scenario: User with correct permissions can add fields
  Given I am logged in as a user with the "administrator" role on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click "Social Links" in the "vertical_tabs" region
  # make sure link validation works
  And I fill in "facebook.com" for "edit-field-utexas-social-links-und-0-links-facebook"
  And I press the "Save" button
  Then I should see the error message "Social Links: A valid URL is required for social links."
  # now check with valid links
  And I fill in "http://facebook.com" for "edit-field-utexas-social-links-und-0-links-facebook"
  And I fill in "http://twitter.com" for "edit-field-utexas-social-links-und-0-links-twitter"
  And I fill in "http://instagram.com" for "edit-field-utexas-social-links-und-0-links-instagram"
  And I fill in "http://linkedin.com" for "edit-field-utexas-social-links-und-0-links-linkedin"
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been created."
  And I should see the link "Facebook" in the "social_links_block" region
  And I should see the link "Twitter" in the "social_links_block" region
  And I should see the link "Instagram" in the "social_links_block" region
  And I should see the link "LinkedIn" in the "social_links_block" region







