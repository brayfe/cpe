# features/promo_lists.feature

@api @javascript @media_upload
Feature: UTexas Promo List
  In order to add promo lists to a page
  As a site builder
  I need to be able to create, update, and delete promo lists


Scenario: 1. Validating Promo List Style. Creating a valid Promo List.
  # Validating Copy needed when Headline filled
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "test form" for "edit-title" in the "form_item_title" region
  And I click "Promo List" in the "vertical_tabs" region
  And I wait for css element "#edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-0-image-browse-button" to "appear"
  And I fill in "Headline PL 1" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-headline-und-0-value" in the "field_utexas_promo_list_values" region
  And I press the "Save" button
  Then I should see the error message "Promo List Style field is required."

  # Now filling the Promo List normally. Creating PL 1 Item 1
  And I fill in "Headline Item 1" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-0-headline" in the "field_utexas_promo_list_values" region
  When I select the radio button "Single list full (1 item per row)" with the id "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-style-und-single-list-full-1-item-per-row"
  And I click "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-0-image-browse-button" in the "field_utexas_promo_list_values" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I fill in "Copy Field for Promo List Item 1" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-0-copy-value" in the "field_utexas_promo_list_values" region
  And I fill in "http://www.google.com" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-0-link" in the "field_utexas_promo_list_values" region

  # Creating PL 1 Item 2
  When I click on the element "#edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-add-more"
  And I wait for css element ".form-item-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-1-headline" to "appear"
  And I fill in "Headline Item 2" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-1-headline" in the "field_utexas_promo_list_values" region
  And I click "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-1-image-browse-button" in the "field_utexas_promo_list_values" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Copy Field for Promo List Item 2" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-1-copy-value" in the "field_utexas_promo_list_values" region
  And I fill in "http://www.google.com" for "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-item-und-1-link" in the "field_utexas_promo_list_values" region

  # Creating PL 2 Item 1
  When I click on the element "#edit-field-utexas-promo-list-und-add-more"
  And I wait for css element "#edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-0-image-browse-button" to "appear"
  And I fill in "Headline PL 2" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-headline-und-0-value" in the "field_utexas_promo_list_values" region
  When I select the radio button "Single list full (1 item per row)" with the id "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-style-und-single-list-full-1-item-per-row"
  And I fill in "PL2 Headline Item 1" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-0-headline" in the "field_utexas_promo_list_values" region
  And I click "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-0-image-browse-button" in the "field_utexas_promo_list_values" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Copy Field for Promo List 2 Item 1" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-0-copy-value" in the "field_utexas_promo_list_values" region
  And I fill in "http://www.google.com" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-0-link" in the "field_utexas_promo_list_values" region

  # Creating PL 2 Item 2
  When I click on the element "#edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-add-more"
  And I wait for css element ".form-item-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-1-headline" to "appear"
  And I fill in "Headline PL 2 Item 2" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-1-headline" in the "field_utexas_promo_list_values" region
  And I click "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-1-image-browse-button" in the "field_utexas_promo_list_values" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Copy Field for Promo List 2 Item 2" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-1-copy-value" in the "field_utexas_promo_list_values" region
  And I fill in "http://www.google.com" for "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-item-und-1-link" in the "field_utexas_promo_list_values" region

  And I wait for css element "#edit-submit" to "appear"
  And I wait for 2 seconds

  # Saving the PL
  And I click on the element "#edit-submit"
  And I wait for 4 seconds
  #Then I should see the message "Standard Page test form has been created."

  # Assigning Promo List to a region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-c4c10ae36665adf0e722e7e3f4be74d4"
  And I wait for css element ".field.field_utexas_promo_list" to "appear"
  And I click "Done" in the "context_editor" region

  # Making sure that the fields are present
  Then I should see "Headline" in the "field_utexas_promo_list" region
  And I wait for css element ".utexas-promo-list" to "appear"
  And I press the "Save" button
  Then I should see "Headline PL 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  And I should see the css selector ".utexas-promo-list a img" with the attribute "alt" with the exact value "Placeholder Image"
  And I should see the css selector ".utexas-promo-list a img" with the attribute "title" with the exact value "Placeholder Title"
  Then I should see the link "Headline Item 1" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List Item 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "Headline Item 2" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List Item 2" in the "field_utexas_promo_list" region
  Then I should see "Headline PL 2" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "PL2 Headline Item 1" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List 2 Item 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "Headline PL 2 Item 2" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List 2 Item 2" in the "field_utexas_promo_list" region

  # Validating 1st Promo List Style CSS is present
  Then I should see the css element ".one-column-full-width"

  # Changing the Promo List Style to 2nd option to the 1st PL
  And I click "Edit" in the "primary_tabs" region
  And I click "Promo List" in the "vertical_tabs" region
  When I select the radio button "Single list responsive (2 items per row)" with the id "edit-field-utexas-promo-list-und-0-field-utexas-promo-list-style-und-single-list-responsive-2-items-per-row"

  # Changing the Promo List Style to 3rd option to 2nd PL
  When I select the radio button "Two lists, side-by-side" with the id "edit-field-utexas-promo-list-und-1-field-utexas-promo-list-style-und-two-lists-side-by-side"
  And I press the "Save" button
  Then I should see the message "Standard Page test form has been updated."

  # Making sure that the fields are still present
  Then I should see "Headline" in the "field_utexas_promo_list" region
  And I wait for css element ".utexas-promo-list" to "appear"
  Then I should see "Headline PL 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "Headline Item 1" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List Item 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "Headline Item 2" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List Item 2" in the "field_utexas_promo_list" region
  Then I should see "Headline PL 2" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "PL2 Headline Item 1" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List 2 Item 1" in the "field_utexas_promo_list" region
  And I should see the image path "promo-lists/placeholder" in the css element ".utexas-promo-list a img"
  Then I should see the link "Headline PL 2 Item 2" in the "field_utexas_promo_list" region
  And I should see "Copy Field for Promo List 2 Item 2" in the "field_utexas_promo_list" region

  # Validating 2nd and 3rd Promo Lists Style CSS is present
  Then I should see the css element ".two-column"
  Then I should see the css element ".one-column"
