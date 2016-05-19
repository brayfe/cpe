# features/photo_content_area.feature

@api @media_upload
Feature: Photo Content Area
  In order use the Photo Content Area widget
  As a site builder
  I need to be able to add the photo content area field to a page

@javascript
Scenario: Validate CTA Title
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "Test PCA" for "edit-title" in the "form_item_title" region
  And I click on the element "#featured_highlight"
  And I wait for css element "#edit-field-utexas-featured-highlight-und-0-headline" to "appear"
  And I click "Photo Content Area" in the "vertical_tabs" region
  And I wait for css element "#edit-field-utexas-photo-content-area" to "appear"
  And I fill in "CTA Title" for "edit-field-utexas-photo-content-area-und-0-links-0-link-title" in the "photo_content_area" region
  And I press the "Save" button
  Then I should see the error message "Photo Content Area: There is a title but no corresponding link."

  # Now we will create a valid PCA
  And I click "Photo Content Area" in the "vertical_tabs" region
  And I wait for css element "#edit-field-utexas-photo-content-area" to "appear"
  And I fill in "Headline" for "edit-field-utexas-photo-content-area-und-0-headline" in the "photo_content_area" region
  And I fill in "Photo by Associated Press." for "edit-field-utexas-photo-content-area-und-0-credit"
  And I click "edit-field-utexas-photo-content-area-und-0-utexas-photo-content-area-image-browse-button" in the "photo_content_area" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I fill in "Copy text field example" for "edit-field-utexas-photo-content-area-und-0-copy-value" in the "photo_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-photo-content-area-und-0-links-0-link-url" in the "photo_content_area" region
  And I press the "Save" button
  Then I should see the message "Standard Page Test PCA has been created."

  # Assigning field to region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "main_content_top_right" region
  And I should see the text "Content" in the "main_content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-29dbb1cb2c1033fdddae49c21ad4a9f5"
  And I wait for css element ".field.field_utexas_photo_content_area" to "appear"
  And I click "Done" in the "context_editor" region
  And I wait for css element ".field_utexas_photo_content_area" to "appear"
  And I press the "Save" button

  # Making sure that the fields are present
  Then I should see "Headline" in the "field_utexas_photo_content_area" region
  And I should see the image path "photo-content-area/placeholder" in the css element ".utexas-photo-content-area"
  And I should see the css selector ".utexas-photo-content-area" with the attribute "alt" with the exact value "Placeholder Image"
  And I should see the css selector ".utexas-photo-content-area" with the attribute "title" with the exact value "Placeholder Title"
  And I should see "Copy text field example" in the "field_utexas_photo_content_area" region
  And I should see the link "CTA Title" in the "field_utexas_photo_content_area" region
  And I should see the text "Photo by Associated Press." in the "caption_copy" region
