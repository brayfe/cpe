# features/promo_units.feature

@api @javascript @media_upload
Feature: UTexas Promo Units
  In order add promo units to a page
  As a site builder
  I need to be able to create, update, and delete promo units


Scenario: 1. Validating Copy needed when Headline filled 2. Creating a valid Promo Unit.
  # Validating Copy needed when Headline filled
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click "Promo Units" in the "vertical_tabs" region
  And I wait for css element ".form-item-field-utexas-promo-units-und-0-image" to "appear"
  And I fill in "Headline" for "edit-field-utexas-promo-units-und-0-headline" in the "field_utexas_promo_units_values" region
  And I press the "Save" button
  Then I should see the error message "Promo Units: Copy field is required."

  # Now filling the Promo Unit normally
  And I fill in "Promo Unit Title" for "edit-field-utexas-promo-units-und-0-title" in the "field_utexas_promo_units_values" region
  And I click "edit-field-utexas-promo-units-und-0-image-browse-button" in the "field_utexas_promo_units_values" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I wait for css element "#edit-field-utexas-promo-units-und-0-image-remove-button" to appear
  And I select the radio button "Square (140x140)"
  And I fill in "Copy field" for "edit-field-utexas-promo-units-und-0-copy-value" in the "field_utexas_promo_units_values" region

  And I fill in "http://www.google.com" for "edit-field-utexas-promo-units-und-0-link" in the "field_utexas_promo_units_values" region
  And I fill in "Read more" for "edit-field-utexas-promo-units-und-0-cta" in the "field_utexas_promo_units_values" region
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been created."

  # Assigning Promo Unit to a region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-208a521aa519bc1ed37d8992aeffae83"
  And I wait for css element ".field.field_utexas_promo_units" to "appear"
  And I click "Done" in the "context_editor" region

  # Making sure that the fields are present
  Then I should see "Promo Unit Title" in the "field_utexas_promo_units" region
  And I wait for css element ".utexas-promo-unit" to "appear"
  And I should see the image path "styles/utexas_promo_unit_square_image" in the css element ".utexas-promo-unit a img"
  Then I should see the link "Headline" in the "field_utexas_promo_units" region
  And I should see "Copy field" in the "field_utexas_promo_units" region
  And I should see "Read more" in the "field_utexas_promo_units" region

  And I click "Edit Promo Units"
  And I select the radio button "Portrait (150x188)"
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been updated."
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-208a521aa519bc1ed37d8992aeffae83"
  And I wait for css element ".field.field_utexas_promo_units" to "appear"
  And I click "Done" in the "context_editor" region
  And I should see the image path "styles/utexas_promo_unit_portrait_image" in the css element ".utexas-promo-unit a img"
  And I should see the css selector ".utexas-promo-unit a img" with the attribute "alt" with the exact value "Placeholder Image"
  And I should see the css selector ".utexas-promo-unit a img" with the attribute "title" with the exact value "Placeholder Title"
