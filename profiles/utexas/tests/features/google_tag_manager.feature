# features/google_tag_manager.feature

@api @javascript

Feature: Google Tag Manager functionality
  In order to ensure Google Tag Manager can be added and targeted
  As a site-builder
  I need to be able to define a GTM code and set which types of pages it should display on

@api @drush
Scenario: Default Google Tag Manager settings for anonymous user.

  # Create an unpublished page
  Given I am logged in as a user with the "Site Builder" role
  When I go to "node/add/page"
  And I fill in "GTM Test" for "edit-title"
  And I click "Publishing options" in the "vertical_tabs" region
  And I uncheck "Published"
  And I press the "Save" button

  # Ensure default Tag Manager settings.
  Given I run drush "vset 'utexas_google_tag_manager_gtm_code' GTM-123456"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_403' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_admin' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_unpublished' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_authenticated' 0"
  And I run drush "cache-clear all"
  And I wait for 5 seconds

  # Tag Manager is included on published pages.
  When I am an anonymous user
  And I go to the homepage
  Then I should see HTML 'GTM-123456' in the '.region-page-bottom' region

  # Tag Manager is included on 404s.
  When I go to "/nonexistentpage"
  Then I should see HTML 'GTM-123456' in the '.region-page-bottom' region

  # Tag Manager is not included on 403s by default.
  When I go to "/gtm-test"
  Then I should not see HTML 'GTM-123456' in the '.html' region
  Given I run drush "vset 'utexas_google_tag_manager_gtm_include_403' 1"
  And I run drush "cache-clear all"
  And I wait for 5 seconds
  # Tag Manager is now included on 403s.
  When I go to "/gtm-test"
  Then I should see HTML 'GTM-123456' in the '.html' region

  # Now test authenticated, unpublished, admin pages, & excluded paths.
  Given I am logged in as a user with the "Site Builder" role
  When I go to "node/add/page"
  And I fill in "GTM Test 2" for "edit-title"
  And I click "Publishing options" in the "vertical_tabs" region
  And I uncheck "Published"
  And I press the "Save" button

  # Tag Manager is not included for authenticated traffic by default.
  When I go to "/node/1"
  Then I should not see HTML 'GTM-123456' in the '.html' region
  Given I run drush "vset 'utexas_google_tag_manager_gtm_include_authenticated' 1"
  # Tag Manager is now included for authenticated traffic
  When I go to "/node/1"
  Then I should see HTML 'GTM-123456' in the '.html' region

  # Tag Manager is not included for unpublished nodes by default.
  When I go to "/gtm-test-2"
  Then I should not see HTML 'GTM-123456' in the '.html' region
  Given I run drush "vset 'utexas_google_tag_manager_gtm_include_unpublished' 1"
  # Tag Manager is now included on unpublished nodes
  When I go to "/gtm-test-2"
  Then I should see HTML 'GTM-123456' in the '.html' region

  # Tag Manager is now included on administrative pages
  When I go to "/admin/content"
  Then I should not see HTML 'GTM-123456' in the '.html' region
  Given I run drush "vset 'utexas_google_tag_manager_gtm_include_admin' 1"
  # Tag Manager is now included on administrative pages
  When I go to "/admin/content"
  Then I should see HTML 'GTM-123456' in the '.html' region

  # Tag Manager can be excluded by specifying the path
  Given I run drush "vset 'utexas_google_tag_manager_gtm_exclude_paths' gtm-test-2"
  When I go to "/gtm-test-2"
  Then I should not see HTML 'GTM-123456' in the '.html' region

  # Cleanup
  Then I run drush "vset 'utexas_google_tag_manager_gtm_code' ''"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_403' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_admin' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_unpublished' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_include_authenticated' 0"
  And I run drush "vset 'utexas_google_tag_manager_gtm_exclude_paths' ''"
  And I run drush "cache-clear all"

