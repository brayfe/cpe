# features/image_links.feature

@api @media_upload

Feature: Image Links
  In order to use the Image Links widget
  As a site-builder
  I need to be able to create, update, and delete image links

  @javascript
  Scenario: User with correct permissions can add fields
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/standard-page"
    And I fill in "test form" for "edit-title" in the "form_item_title" region
    And I click "Image Link A" in the "vertical_tabs" region
    And I wait for css element ".form-item-field-utexas-image-link-a-und-0-image" to "appear"
    And I click "edit-field-utexas-image-link-a-und-0-image-browse-button"
    And I switch to the iframe "mediaBrowser"
    And I attach the file "placeholder.jpg" to "files[upload]"
    And I press the "Next" button
    And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
    And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
    And I press the "Save" button
    And I fill in "http://www.google.com" for "edit-field-utexas-image-link-a-und-0-link-link-href" in the "image_links_edit" region
    And I fill in "image link test title" for "edit-field-utexas-image-link-a-und-0-link-link-title" in the "image_links_edit" region
    And I press the "Save" button
    Then I should see the message "Standard Page test form has been created."
    And I click "Layout Editor" in the "primary_tabs" region
    And I click "Edit" in the "context_editor" region
    And I wait for css element ".main-content" to "appear"
    Then I should see the text "Add a block here." in the "context_layout" region
    And I should see the text "Content" in the "context_layout" region
    And I click on the element "#context-block-region-content .context-ui-add-link.context-ui-processed"
    And I click on the element "#context-block-addable-fieldblock-6986914623a8e5646904aca42f9f452e"
    And I click "Done" in the "context_editor" region
    And I wait for css element ".utexas-image-link" to "appear"
    And I should see the image path "image-link/placeholder" in the css element ".utexas-image-link a img"
    Then I should see the css selector ".utexas-image-link a img" with the attribute "width" with the exact value "1280"
    And I should see the css selector ".utexas-image-link a img" with the attribute "alt" with the exact value "Placeholder Image"
    And I should see the css selector ".utexas-image-link a img" with the attribute "title" with the exact value "Placeholder Title"

