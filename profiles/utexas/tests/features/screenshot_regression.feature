# features/screenshot_regression.feature

@api @screenshots
Feature: Screenshot Regression Testing
  In order to test css regression
  As a developer
  I need to be capture screenshots to diff them against baseline screenshots

@javascript @screenshots
Scenario: Capture screenshots for non-changing pages
  When I visit "/"
  And I set browser window size to "1200" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "front-1200-width"
  And I set browser window size to "850" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "front-850-width"
  And I set browser window size to "350" x "900"
  And I wait for 2 seconds
  And I take a screenshot for regression testing of page "front-350-width"
