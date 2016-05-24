# features/faculty_profile.feature

@api @javascript @mcms_only @media_upload

Feature: Faculty Profile Content Type
  In order to feature faculty and staff
  As a site-builder
  I need an interface to add pre-themed profile content

@drush
Scenario: Site builder can enable faculty profiles
  Given I run drush "en faculty_profile -y"
  Then drush output should contain "faculty_profile"
  Given I run drush "cache-clear all"
  Then drush output should contain "'all' cache was cleared"

@javascript
Scenario: User cannot add invalid content to form
  Given I am logged in as a user with the "administrator" role
  And I click "Add content"
  And I click "Faculty Profile"
  And I click on the link "Education" in the ".vertical-tabs-list" region
  And I fill in "http://cat.invalid" for "edit-field-faculty-education-und-0-url"
  And I click on the link "Areas of Specialty" in the ".vertical-tabs-list" region
  And I fill in "https://cat.invalid" for "edit-field-faculty-areas-of-specialty-und-0-url"
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "Related Links" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "Current Courses" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I fill in "Curriculum Vitae" for "edit-field-utexas-quick-links-und-0-links-1-link-title"
  And I fill in "invalidlink" for "edit-field-utexas-quick-links-und-0-links-1-link-url"
  And I press the "Save" button
  Then I should see the error message "Name field is required."
  And I should see the error message "The value https://cat.invalid provided for Areas of Specialty is not a valid URL."
  And I should see the error message "The value http://cat.invalid provided for Education is not a valid URL."
  And I should see the error message "Related Links: There is a title but no corresponding link."
  And I should see the error message "Related Links: The path provided is not a valid URL alias or external link."

@javascript
Scenario: Related Links block with no links does not display
  Given I am logged in as a user with the "administrator" role
  When I click "Add content"
  And I click "Faculty Profile"
  And I fill in "Super Kitty Do" for "edit-title" in the "form_item_title" region
  And I press the "Save" button
  Then I should not see "Other Resources" in the "sidebar_content" region

@javascript
Scenario: User can adds available content to landing page
  Given I am logged in as a user with the "administrator" role
  When I click "Add content"
  And I click "Faculty Profile"
  And I fill in "Super Kitty Do" for "edit-title" in the "form_item_title" region
  And I click on the element "#edit-field-faculty-headshot-und-0-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "super_kitty_do.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I click on the link "Faculty Title" in the ".vertical-tabs-list" region
  And I fill in "Peer out window, chatter at birds, lure them to mouth paw at your fat belly attack feet, and mark territory, yet chase dog then run away." for "edit-field-faculty-title-und-0-value"
  And I click on the link "Education" in the ".vertical-tabs-list" region
  And I fill in "MA Boston College" for "edit-field-faculty-education-und-0-title"
  And I fill in "http://bc.edu" for "edit-field-faculty-education-und-0-url"
  And I click on the element "#edit-field-faculty-education-und-add-more"
  And I wait for css element "#edit-field-faculty-education-und-1-title" to appear
  And I fill in "BA USC" for "edit-field-faculty-education-und-1-title"
  And I click on the link "Areas of Specialty" in the ".vertical-tabs-list" region
  And I fill in "Postcolonialism" for "edit-field-faculty-areas-of-specialty-und-0-title"
  And I fill in "https://en.wikipedia.org/wiki/Postcolonial_literature" for "edit-field-faculty-areas-of-specialty-und-0-url"
  And I click on the element "#edit-field-faculty-areas-of-specialty-und-add-more"
  And I wait for css element "#edit-field-faculty-areas-of-specialty-und-1-title" to appear
  And I fill in "Rhizomatic Theory" for "edit-field-faculty-areas-of-specialty-und-1-title"
  And I click on the Link "Bio" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "edit-field-wysiwyg-a" to "wysiwyg_a"
  And I fill in "Cat ipsum dolor sit amet, give attitude for spread kitty litter all over house. Hack up furballs stare at the wall, play with food and get confused by dust and mew attack feet run in circles. Caticus cuteicus paw at your fat belly yet missing until dinner time, or sit by the fire." in WYSIWYG editor "wysiwyg_a"
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "Related Links" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "Current Courses" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I fill in "<front>" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I fill in "Curriculum Vitae" for "edit-field-utexas-quick-links-und-0-links-1-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-1-link-url"
  And I fill in "Publications" for "edit-field-utexas-quick-links-und-0-links-2-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-2-link-url"
  And I fill in "Activities" for "edit-field-utexas-quick-links-und-0-links-3-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-3-link-url"
  And I click on the link "Contact Info" in the ".vertical-tabs-list" region
  And I select the radio button "Example Contact Form"
  And I press the "Save" button
  Then I should see the heading "Super Kitty Do"
  And I should see "Peer out window, chatter at birds, lure them to mouth paw at your fat belly attack feet, and mark territory, yet chase dog then run away." in the "field_faculty_title" region
  And I should see the link "Current Courses" in the "quick_links_block" region
  And I should see "Example Contact Form" in the "field_contact_info" region
  And I should see "Cat ipsum dolor sit amet" in the "wysiwyg_a_block" region
  And I should see the link "MA Boston College" in the "additional_info" region
  And I should see "BA USC" in the "additional_info" region
  And I should see the link "Postcolonialism" in the "additional_info" region
  And I should see "Rhizomatic Theory" in the "additional_info" region
  And I should see the css element ".bio-top img" with the attribute "src" with the value containing "/faculty_headshots/super_kitty_do"
  And I should see the css element ".bio-top img" with the attribute "alt" with the value containing "Placeholder Image"
  And I should see the css element ".bio-top img" with the attribute "title" with the value containing "Placeholder Title"
