# features/flex_content_area.feature

@api @media_upload
Feature: Flex Content Area
  In order use the Flex Content Area widget
  As a site builder
  I need to be able to add the flex content area field to a page

@javascript
Scenario: Validating and creating a node with Flex Content Area.

  # Validate CTA or Links.
  Given I am logged in as a user with the "administrator" role
  When I go to "node/add/standard-page"
  And I fill in "Test FCA" for "edit-title" in the "form_item_title" region
  And I click "Flex Content Area A" in the "vertical_tabs" region
  And I wait for css element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button" to "appear"
  And I fill in "Link Title" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-title" in the "field_flex_content_area" region
  And I fill in "http://google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-url" in the "field_flex_content_area" region
  And I fill in "CTA Title" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-title" in the "field_flex_content_area" region
  And I fill in "http://google.com" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-link" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the error message "Flex Content Area A: You cannot have both links and a call to action."

  # Validating Link when Title filled
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-url" in the "field_flex_content_area" region
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-title" in the "field_flex_content_area" region
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-link" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the error message "Flex Content Area A: There is a title but no corresponding link."

  # Validating Title when Link filled
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-title" in the "field_flex_content_area" region
  And I fill in "http://google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-url" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the error message "Flex Content Area A: There is a link but no corresponding title."

  # Validating CTA Link when Title filled
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-url" in the "field_flex_content_area" region
  And I fill in "CTA Title" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-title" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the error message "Flex Content Area A: A link is required for a call to action."

  # Validating CTA Title when Link filled
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-title" in the "field_flex_content_area" region
  And I fill in "http://google.com" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-link" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the error message "Flex Content Area A: A title is required for a call to action."

  # Now we will create a valid FCA with Links
  And I wait for css element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button" to "appear"
  And I click on the element "#edit-field-utexas-flex-content-area-a-und-0-image-browse-button"
  And I switch to the iframe "mediaBrowser"
  And I attach the file "placeholder.jpg" to "files[upload]"
  And I press the "Next" button
  And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
  And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
  And I press the "Save" button
  And I fill in "" for "edit-field-utexas-flex-content-area-a-und-0-cta-cta-link" in the "field_flex_content_area" region
  And I fill in "Headline" for "edit-field-utexas-flex-content-area-a-und-0-headline" in the "field_flex_content_area" region
  And I fill in "Copy text field example" for "edit-field-utexas-flex-content-area-a-und-0-copy-value" in the "field_flex_content_area" region
  And I fill in "Link 1" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-0-link-url" in the "field_flex_content_area" region
  And I fill in "Link 2" for "edit-field-utexas-flex-content-area-a-und-0-links-1-link-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-1-link-url" in the "field_flex_content_area" region
  And I fill in "Link 3" for "edit-field-utexas-flex-content-area-a-und-0-links-2-link-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-2-link-url" in the "field_flex_content_area" region
  And I fill in "Link 4" for "edit-field-utexas-flex-content-area-a-und-0-links-3-link-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-3-link-url" in the "field_flex_content_area" region
  And I fill in "Link 5" for "edit-field-utexas-flex-content-area-a-und-0-links-4-link-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-0-links-4-link-url" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the message "Standard Page Test FCA has been created."

  # Assigning field to region
  And I click "Layout Editor" in the "primary_tabs" region
  And I click "Edit" in the "context_editor" region
  And I wait for css element ".main-content" to "appear"
  Then I should see the text "Add a block here." in the "content_top_right" region
  And I should see the text "Content" in the "content_top_right" region
  And I click on the element ".context-ui-add-link.context-ui-processed"
  And I click on the element "#context-block-addable-fieldblock-9c079efa827f76dea650869c5d2631e6"
  And I wait for css element ".field_utexas_flex_content_area_a" to "appear"
  And I click "Done" in the "context_editor" region
  And I press the "Save" button

  # Making sure that the fields are present
  Then I should see "Headline" in the "field_utexas_flex_content_area" region
  And I should see the image path "flex-content-areas/placeholder" in the css element ".utexas-flex-content-area-image"
  And I should see the css selector ".utexas-flex-content-area-image" with the attribute "alt" with the exact value "Placeholder Image"
  And I should see the css selector ".utexas-flex-content-area-image" with the attribute "title" with the exact value "Placeholder Title"
  Then I should see "Copy text field example" in the "field_utexas_flex_content_area" region
  Then I should see the link "Link 1" in the "field_utexas_flex_content_area" region
  Then I should see the link "Link 2" in the "field_utexas_flex_content_area" region
  Then I should see the link "Link 3" in the "field_utexas_flex_content_area" region
  Then I should see the link "Link 4" in the "field_utexas_flex_content_area" region
  Then I should see the link "Link 5" in the "field_utexas_flex_content_area" region

  # Adding another item with CTA
  And I click "Edit" in the "primary_tabs" region
  And I click "Flex Content Area A" in the "vertical_tabs" region
  And I click "edit-field-utexas-flex-content-area-a-und-1-image-browse-button" in the "field_flex_content_area" region
  And I switch to the iframe "mediaBrowser"
  And I attach the file "background-accent.jpg" to "files[upload]"
  And I press the "Next" button
  And I press the "Save" button
  And I fill in "Headline 2" for "edit-field-utexas-flex-content-area-a-und-1-headline" in the "field_flex_content_area" region
  And I fill in "Copy text field example second object" for "edit-field-utexas-flex-content-area-a-und-1-copy-value" in the "field_flex_content_area" region
  And I fill in "CTA Title" for "edit-field-utexas-flex-content-area-a-und-1-cta-cta-title" in the "field_flex_content_area" region
  And I fill in "https://www.google.com" for "edit-field-utexas-flex-content-area-a-und-1-cta-cta-link" in the "field_flex_content_area" region
  And I press the "Save" button
  Then I should see the message "Standard Page Test FCA has been updated."

  # Making sure that the Second FCA object fields are present
  Then I should see "Headline 2" in the "field_utexas_flex_content_area" region
  And I should see the image path "flex-content-areas/background-accent" in the css element ".utexas-flex-content:nth-child(2) .utexas-flex-content-area-image-wrapper .utexas-flex-content-area-image"
  Then I should see "Copy text field example second object" in the "field_utexas_flex_content_area" region
  Then I should see the link "CTA Title" in the "field_utexas_flex_content_area" region
