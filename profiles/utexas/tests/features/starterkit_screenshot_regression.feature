# features/screenshot_regression.feature

@api @screenshots
Feature: Starterkit Screenshot Regression Testing
  In order to test css regression
  As a developer
  I need to be capture screenshots to diff them against baseline screenshots

@javascript @screenshots @drush
Scenario: Capture screenshots for non-changing pages
  Given I run drush "en STARTERKIT -y"
  Then drush output should contain "STARTERKIT"
  Given I run drush "vset theme_default STARTERKIT -y"
  Then drush output should contain 'theme_default was set to "STARTERKIT".'
  Given I run drush "cache-clear all"
  Then drush output should contain "cleared"
  When I visit "/"
  And I set browser window size to "1200" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "starterkit-front-1200"
  And I set browser window size to "850" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "starterkit-front-850"
  And I set browser window size to "350" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "starterkit-front-350"
  Given I run drush "en forty_acres -y"
  Then drush output should contain "forty_acres"
  Given I run drush "vset theme_default forty_acres -y"
  Then drush output should contain 'theme_default was set to "forty_acres".'
  Given I run drush "cache-clear all"
  Then drush output should contain "cleared"