# features/resource.feature

@api
Feature: Resource
  In order use the Resource widget
  As a site builder
  I need to be able to add the resource field to a page

  @javascript
  Scenario: Validating and creating a node with Resource.

    # Validate Links.
    Given I am logged in as a user with the "administrator" role
    When I go to "node/add/standard-page"
    And I fill in "test resource" for "edit-title" in the "form_item_title" region
    And I click "Resource" in the "vertical_tabs" region
    And I wait for css element "#edit-field-utexas-resource-und-0-image-upload" to "appear"
    And I fill in "Resource Title" for "edit-field-utexas-resource-und-0-title"
    And I fill in "Resource Headline" for "edit-field-utexas-resource-und-0-headline"

    # validate link with no title
    And I fill in "" for "edit-field-utexas-resource-und-0-links-0-link-title"
    And I fill in "http://google.com" for "edit-field-utexas-resource-und-0-links-0-link-url"
    And I press the "Save" button
    Then I should see the error message "Resources: There is a link but no corresponding title."

    # validate title with no link
    And I fill in "" for "edit-field-utexas-resource-und-0-links-0-link-url" in the "field_resource" region
    And I fill in "title" for "edit-field-utexas-resource-und-0-links-0-link-title"
    And I press the "Save" button
    Then I should see the error message "Resources: There is a title but no corresponding link."

    # validate invalid link
    And I fill in "title" for "edit-field-utexas-resource-und-0-links-0-link-title" in the "field_resource" region
    And I fill in "blah blah blah" for "edit-field-utexas-resource-und-0-links-0-link-url" in the "field_resource" region
    And I press the "Save" button
    Then I should see the error message "Resources: The path provided is not a valid URL alias or external link."

    # Now we will create a valid resource with links
    And I wait for css element "#edit-field-utexas-resource-und-0-image-browse-button" to "appear"
    And I click on the element "#edit-field-utexas-resource-und-0-image-browse-button"
    And I switch to the iframe "mediaBrowser"
    And I attach the file "placeholder.jpg" to "files[upload]"
    And I press the "Next" button
    And I fill in "Placeholder Image" for "edit-field-file-image-alt-text-und-0-value"
    And I fill in "Placeholder Title" for "edit-field-file-image-title-text-und-0-value"
    And I press the "Save" button
    And I fill in "Headline" for "edit-field-utexas-resource-und-0-headline" in the "field_resource" region
    And I fill in "Link 1" for "edit-field-utexas-resource-und-0-links-0-link-title" in the "field_resource" region
    And I fill in "https://www.google.com" for "edit-field-utexas-resource-und-0-links-0-link-url" in the "field_resource" region
    And I fill in "Link 2" for "edit-field-utexas-resource-und-0-links-1-link-title" in the "field_resource" region
    And I fill in "https://www.google.com" for "edit-field-utexas-resource-und-0-links-1-link-url" in the "field_resource" region
    And I fill in "Link 3" for "edit-field-utexas-resource-und-0-links-2-link-title" in the "field_resource" region
    And I fill in "https://www.google.com" for "edit-field-utexas-resource-und-0-links-2-link-url" in the "field_resource" region
    And I fill in "Link 4" for "edit-field-utexas-resource-und-0-links-3-link-title" in the "field_resource" region
    And I fill in "https://www.google.com" for "edit-field-utexas-resource-und-0-links-3-link-url" in the "field_resource" region
    And I fill in "Link 5" for "edit-field-utexas-resource-und-0-links-4-link-title" in the "field_resource" region
    And I fill in "https://www.google.com" for "edit-field-utexas-resource-und-0-links-4-link-url" in the "field_resource" region
    And I press the "Save" button
    Then I should see the message "Standard Page test resource has been created."

    # Assigning field to region
    And I click "Layout Editor" in the "primary_tabs" region
    And I click "Edit" in the "context_editor" region
    And I wait for css element ".main-content" to "appear"
    Then I should see the text "Add a block here." in the "content_top_right" region
    And I should see the text "Content" in the "content_top_right" region
    And I click on the element ".context-ui-add-link.context-ui-processed"
    And I click on the element "#context-block-addable-fieldblock-e01ea87c2dadf3edda4cc61011b33637"
    And I wait for css element ".field_utexas_resource" to "appear"
    And I click "Done" in the "context_editor" region
    And I press the "Save" button

    # Making sure that the fields are present
    Then I should see "Resource Title" in the "field_utexas_resource" region
    And I should see the image path "placeholder" in the css element ".resource-image"
    And I should see the css selector ".resource-image" with the attribute "alt" with the exact value "Placeholder Image"
    And I should see the css selector ".resource-image" with the attribute "title" with the exact value "Placeholder Title"
    Then I should see the link "Link 1" in the "field_utexas_resource" region
    Then I should see the link "Link 2" in the "field_utexas_resource" region
    Then I should see the link "Link 3" in the "field_utexas_resource" region
    Then I should see the link "Link 4" in the "field_utexas_resource" region
    Then I should see the link "Link 5" in the "field_utexas_resource" region

