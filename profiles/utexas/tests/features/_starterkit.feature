# features/starterkit.feature

@api @javascript @screenshots

Feature: Forty Acres subtheme starter kit
  In order to make subtheming Forty Acres easier
  As a site-builder, themer or developer
  I need a starterkit with the necessary files to properly build a subtheme

@javascript  @drush @screenshots
Scenario: Enable the starterkit to make some theme-settings changes
  Given I run drush "en STARTERKIT -y"
  Then drush output should contain "STARTERKIT"
  Given I run drush "vset theme_default STARTERKIT -y"
  Then drush output should contain 'theme_default was set to "STARTERKIT".'

@javascript @drush
Scenario: Test theme-settings and verify starterkit is default theme
  Given I am logged in as a user with the "administrator" role
  Then I go to "admin/appearance"
  And I should see "STARTERKIT" in the "theme_default" region
  Then I go to "admin/appearance/settings/STARTERKIT"
  And I select the radio button "Header menu: Configure header menu here."
  And I enter "this is a behat test of the STARTERKIT subtheme" for "OPTIONAL - Enter text to be displayed in a block in the left-most region of the footer."
  And I enter "School of Law" for "Parent Entity Name"
  And I press the "edit-submit" button
  Then I should see the message "Please enter a link for the Parent Entity Website. A link is required if you have entered a Parent Entity Name."
  And I enter "hello world" for "Parent Entity Website"
  And I press the "edit-submit" button
  Then I should see the message "Please enter a valid link for the Parent Entity Website."
  Then I enter "http://www.google.com" for "Parent Entity Website"
  And I press the "edit-submit" button
  Then I should see the message "The configuration options have been saved"
  And I click "Home"
  Then I should not see the error message "Warning"
  Then I should not see the error message "Notice"
  Then I run drush "cache-clear all"
  Then I should see "this is a behat test of the STARTERKIT subtheme" in the "full_page_content" region
  And I should see "Header Link 1" in the "header" region
  And I should see "School of Law" in the "header" region
  Given I run drush "en forty_acres -y"
  Then drush output should contain "forty_acres"
  Given I run drush "vset theme_default forty_acres -y"
  Then drush output should contain 'theme_default was set to "forty_acres".'
  Given I run drush "cache-clear all"
  Then drush output should contain "cleared"





