# features/team_member.feature

# You need default content to run this test

@api @javascript @mcms_only @media_upload

Feature: Team Member Content Type
  In order to feature team members
  As a site-builder
  I need an interface to add pre-themed profile content

@drush
Scenario: Site builder can enable team members
  Given I run drush "en content_type_team_member -y"
  Then drush output should contain "team_member"
  Given I run drush "cache-clear all"
  Then drush output should contain "'all' cache was cleared"

@javascript
Scenario: Validating empty fields
  Given I am logged in as a user with the "administrator" role
  And I set browser window size to "1200" x "900"
  And I click "Add content"
  And I click "Team Member"
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "Related Links" for "edit-field-utexas-quick-links-und-0-headline"
  And I press the "Save" button
  Then I should see the error message "Given Name field is required."
  And I should see the error message "Surname field is required."
  And I should see the error message "Organizational Group field is required."
  And I should see the error message "Related Links: There is a Link Title but no corresponding Link URL"
  And I click on the link "Basic Info" in the ".vertical-tabs-list" region
  And I fill in "Jon Snow" for "edit-custom-vertical-tabs-field-utexas-member-given-name-und-0-value"
  And I fill in "Crow" for "edit-custom-vertical-tabs-field-utexas-member-surname-und-0-value"
  And I select the radio button "Leadership"
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "Current Courses" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I press the "Save" button
  Then I should see the error message "Related Links: There is a title but no corresponding link."
  And I should see the error message "Related Links: There is a Link Title but no corresponding Link URL"
  And I fill in "invalid/path" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I press the "Save" button
  Then I should see the error message "Related Links: The path provided is not a valid URL alias or external link."

@javascript
Scenario: User can add available content to a team member, and display them in the Team Member view block
  Given I am logged in as a user with the "administrator" role
  When I click "Add content"
  And I click "Team Member"
  # Add Basic Info #
  And I fill in "Jon Snow" for "edit-custom-vertical-tabs-field-utexas-member-given-name-und-0-value"
  And I fill in "Crow" for "edit-custom-vertical-tabs-field-utexas-member-surname-und-0-value"
  And I fill in "Lord Commander from the Nightswatch" for "edit-custom-vertical-tabs-field-utexas-member-designation-und-0-value"
  And I select the radio button "Leadership"
  # Add Headshot #
  And I click on the link "Headshot" in the ".vertical-tabs-list" region
  And I click on the element "#edit-field-utexas-member-headshot-und-0-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "super_kitty_do.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  # Add Bio #
  And I click on the Link "Bio" in the ".vertical-tabs-list" region
  And I the set the iframe located in element with an id of "edit-field-utexas-member-bio" to "utexas_member_bio_summary"
  And I fill in "Cat ipsum dolor sit amet, give attitude for spread kitty litter all over house." in WYSIWYG editor "utexas_member_bio_summary"
  And I the set the iframe located in element with an id of "cke_edit-field-utexas-member-bio-und-0-value" to "utexas_member_bio_copy"
  And I fill in "Cat ipsum dolor sit amet, give attitude for spread kitty litter all over house. Hack up furballs stare at the wall, play with food and get confused by dust and mew attack feet run in circles. Caticus cuteicus paw at your fat belly yet missing until dinner time, or sit by the fire." in WYSIWYG editor "utexas_member_bio_copy"
  # Add Contact Info #
  And I click on the link "Contact Info" in the ".vertical-tabs-list" region
  And I select the radio button "Example Contact Form"
  # Add Related Links #
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "Related Links" for "edit-field-utexas-quick-links-und-0-headline"
  And I fill in "Current Courses" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-0-link-url"
  And I fill in "Curriculum Vitae" for "edit-field-utexas-quick-links-und-0-links-1-link-title"
  And I fill in "<front>" for "edit-field-utexas-quick-links-und-0-links-1-link-url"
  And I fill in "Publications" for "edit-field-utexas-quick-links-und-0-links-2-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-2-link-url"
  And I fill in "Activities" for "edit-field-utexas-quick-links-und-0-links-3-link-title"
  And I fill in "http://google.com" for "edit-field-utexas-quick-links-und-0-links-3-link-url"
  And I press the "Save" button
  # Display data #
  Then I should see the heading "Jon Snow Crow"
  And I should see "Lord Commander from the Nightswatch" in the "field_utexas_member_designation" region
  And I should see the link "Current Courses" in the "quick_links_block" region
  And I should see "Example Contact Form" in the "field_contact_info" region
  And I should see "Cat ipsum dolor sit amet" in the "utexas_member_bio" region
  And I should see the css element ".bio-top img" with the attribute "src" with the value containing "/team_members/super_kitty_do"
  And I should see the css element ".bio-top img" with the attribute "alt" with the value containing "Placeholder Image"
  And I should see the css element ".bio-top img" with the attribute "title" with the value containing "Placeholder Title"
  # Edit Related Links to display links only #
  And I click "Edit" in the "primary_tabs" region
  And I click on the link "Related Links" in the ".vertical-tabs-list" region
  And I fill in "" for "edit-field-utexas-quick-links-und-0-links-0-link-title"
  And I press the "Save" button
  And I should see the link "http://google.com" in the "quick_links_block" region
  # Going into the Entity Team Member page
  When I go to "admin/content/team-members"
  And I should see the link "Jon Snow Crow" in the "leadership_entity_table" region
  # Creating a Standard Page to set the View Block #
  When I go to "node/add/standard-page"
  And I fill in "Team Member View Page" for "edit-title" in the "form_item_title" region
  And I press the "Save" button
  # Displaying view page content
  Then I should see the message "Standard Page Team Member View Page has been created."
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  And I click on the element ".context-ui-add-link.context-ui-processed" in the "#context-block-region-content" region
  And I click on the element "#context-block-addable-views-team_members-block_1"
  And I wait for 2 seconds
  And I click "Done" in the "context_editor" region
  And I press the "Save" button
  Then I should see "Leadership" in the "field_utexas_promo_units" region
  And I should see the link "Cornelia Africana" in the "promo_headline" region
  # Changing Cornelia organizational group, to move it to the bottom of the page
  And I click on the link "Cornelia Africana" in the ".utexas-promo-unit" region
  And I click "Edit" in the "primary_tabs" region
  And I select the radio button "Faculty"
  And I press the "Save" button
  # Going back to the view page
  When I go to "team-member-view-page"
  And I should see "Marcus Tullius Cicero" in the "promo_headline" region
  # Returning Cornelia to her original position, and with a [none] link
  When I go to "cornelia-africana"
  And I click "Edit" in the "primary_tabs" region
  And I select the radio button "Leadership"
  And I fill in "abc12345" for "edit-overview-fieldset-field-utexas-eid-und-0-value"
  And I press the "Save" button
  # Going back to the view page
  When I go to "team-member-view-page"
  And I should see "Cornelia Africana" in the "promo_headline" region
  When I go to "about-us"
  And I should see "View in Directory" in the "field_utexas_promo_list" region
  # Returning Cornelia to her original state, to avoid errors if this test is re-ran
  When I go to "cornelia-africana"
  And I click "Edit" in the "primary_tabs" region
  And I fill in "" for "edit-overview-fieldset-field-utexas-eid-und-0-value"
  And I press the "Save" button
