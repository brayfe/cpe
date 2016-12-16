# features/social_sharing.features

@api

Feature: Social Sharing
  In order to use the Social Sharing widget
  As a site-builder
  I need to be able to configure social accounts and display them on a Page

@javascript @api
Scenario: User with correct permissions can configure social sharing accounts
  Given I am logged in as a user with the "complete" permissions on this site
  And I set browser window size to "1200" x "900"
  When I go to "admin/config/utexas/utexas_social_sharing"
  Then I should see the text "Social Sharing Configuration" in the "branding" region
  Given I fill in "Social sharing behat test" for "edit-utexas-social-sharing-title"
  Given I check the box "utexas_social_sharing_em"
  Given I check the box "utexas_social_sharing_go"
  Given I check the box "utexas_social_sharing_li"
  Given I check the box "utexas_social_sharing_tu"
  And I click on the element "#edit-submit"
  Then I should see the message "The configuration options have been saved."

@javascript @api
Scenario: User with correct permissions can position the social sharing widget on standard Page
  Given I am logged in as a user with the "complete" permissions on this site
  And I set browser window size to "1200" x "900"
  When I go to "node/1"
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "main_content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-utexas_social_sharing-utexas_social_sharing_block"
  And I wait for css element "#block-utexas-social-sharing-utexas-social-sharing-block" to "appear"
  And I click "Done" in the "context_editor" region
  And I press "Save" in the "ui_dialog_buttonset" region
  And I go to "node/1"
  Then I should see the text "Social sharing behat test" in the "field_utexas_social_share" region
  Then I should see the text "Email" in the "field_utexas_social_share" region
  Then I should see the text "Google+" in the "field_utexas_social_share" region
  Then I should see the text "LinkedIn" in the "field_utexas_social_share" region
  Then I should see the text "Tumblr" in the "field_utexas_social_share" region
