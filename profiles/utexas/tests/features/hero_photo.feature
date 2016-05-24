# features/hero_photo.feature

@api @media_upload
Feature: UTexas Hero Photo
  In order use the Hero Photo field
  As a site builder
  I need to be able to create, review, update and delete existing hero photos standard pages and landing pages

@javascript
Scenario: Verify themed output for standard hero photo
  Given I am logged in as a user with the "administrator" role
  When I visit "node/add/standard-page"
  And I fill in "Rawrrr!" for "edit-title" in the "form_item_title" region
  And I click "Hero Photo"
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "super_kitty_do.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Image of Super Kitty" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I fill in "YAWWWWN" for "edit-field-utexas-hero-photo-und-0-caption"
  And I fill in "Photo by Associated Kitty Press." for "edit-field-utexas-hero-photo-und-0-credit"
  And I press the "Save" button
  Then I should see the text "Rawrrr!" in the "page_title" region
  And I should see the image path "utexas_hero_photo_image/public/hero-photos/super_kitty_do" in the css element ".utexas-hero-photo"
  And I should see the css selector ".field_utexas_hero_photo img" with the attribute "class" with the exact value "utexas-hero-photo"
  And I should see the css selector ".field_utexas_hero_photo img" with the attribute "alt" with the exact value "Image of Super Kitty"
  And I should see the css selector ".field_utexas_hero_photo img" with the attribute "title" with the exact value "Placeholder Title"
  And I should see the text "YAWWWWN" in the "hero_caption" region
  And I should see the text "Photo by Associated Kitty Press." in the "caption_copy" region
@javascript
Scenario: Verify user can save all fields on hero photo *full* display, hero style 1
  Given I am logged in as a user with the "view the administration theme,create landing_page content,access media browser,administer files,create files" permission
  When I visit "node/add/landing-page"
  And I fill in "Test full-width Hero Photo" for "edit-title" in the "form_item_title" region
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Heading text" for "edit-field-utexas-hero-photo-und-0-caption"
  And I fill in "Subheading" for "edit-field-utexas-hero-photo-und-0-subhead"
  And I fill in "invalidlink" for "edit-field-utexas-hero-photo-und-0-link-link-href"
  And I fill in "Call to Action" for "edit-field-utexas-hero-photo-und-0-link-link-title"
  And I press the "Save" button
  Then I should see the error message "Hero Photo: A valid URL is required for a link."
  When I fill in "<front>" for "edit-field-utexas-hero-photo-und-0-link-link-href"
  And I press the "Save" button
  Then I should see the text "Test full-width Hero Photo" in the "page_title" region
  And I should see the ".container.container-hero" css selector with css property "background-image" containing "/utexas_hero_photo_image_full/public/hero-photos-full/"
  And I should see "Heading text" in the "hero_callout" region
  And I should not see "Subheading" in the "hero_callout" region
  And I should see the link "Call to Action" in the "hero_callout" region
@javascript
Scenario: Verify user can save all fields on hero photo *full* display, hero style 2
  Given I am logged in as a user with the "view the administration theme,create landing_page content,access media browser,administer files,create files" permission
  When I visit "node/add/landing-page"
  And I fill in "Test full-width Hero Photo" for "edit-title" in the "form_item_title" region
  And I select the radio button "2: Headline on light background, floated right"
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Heading text" for "edit-field-utexas-hero-photo-und-0-caption"
  And I fill in "Subheading" for "edit-field-utexas-hero-photo-und-0-subhead"
  And I fill in "Call to Action" for "edit-field-utexas-hero-photo-und-0-link-link-title"
  When I fill in "<front>" for "edit-field-utexas-hero-photo-und-0-link-link-href"
  And I press the "Save" button
  Then I should see the text "Test full-width Hero Photo" in the "page_title" region
  And I should see the ".container.container-hero" css selector with css property "background-image" containing "/utexas_hero_photo_image_full/public/hero-photos-full/"
  And I should see "Heading text" in the "hero_callout" region
  And I should not see "Subheading" in the "hero_callout" region
  And I should see the link "Call to Action" in the "hero_callout" region

@javascript
Scenario: Verify user can save all fields on hero photo *full* display, hero style 3
  Given I am logged in as a user with the "view the administration theme,create landing_page content,edit any landing_page content,access media browser,administer files,create files" permission
  When I visit "node/add/landing-page"
  And I fill in "Test full-width Hero Photo" for "edit-title" in the "form_item_title" region
  And I select the radio button "3: Opaque bottom pane with heading, subheading and burnt orange call-to-action"
  And I click "Browse"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Heading text" for "edit-field-utexas-hero-photo-und-0-caption"
  And I fill in "Subheading" for "edit-field-utexas-hero-photo-und-0-subhead"
  And I fill in "Call to Action" for "edit-field-utexas-hero-photo-und-0-link-link-title"
  When I fill in "<front>" for "edit-field-utexas-hero-photo-und-0-link-link-href"
  And I press the "Save" button
  Then I should see the text "Test full-width Hero Photo" in the "page_title" region
  And I should see the ".container.container-hero" css selector with css property "background-image" containing "/utexas_hero_photo_image_full/public/hero-photos-full/"
  And I should see "Heading text" in the "hero_callout" region
  And I should see "Subheading" in the "hero_callout" region
  And I should see the link "Call to Action" in the "hero_callout" region
  # Verify user entered data persists after saving without an image
  And I click "Edit" in the "primary_tabs" region
  Then I should see the css element "#edit-field-utexas-hero-photo-und-0-link-link-title" with the attribute "value" with the value containing "Call to Action"
  And I press "edit-field-utexas-hero-photo-und-0-utexas-hero-photo-image-remove-button"
  And I wait for css element "#edit-field-utexas-hero-photo-und-0-utexas-hero-photo-image-browse-button" to appear
  And I press "edit-submit"
  # Verify that neither image or other hero photo elements are displaying
  Then I should see the text "Test full-width Hero Photo" in the "page_title" region
  And I should not see the css element ".container.container-hero"
  And I should not see the css element ".hero-callout"




