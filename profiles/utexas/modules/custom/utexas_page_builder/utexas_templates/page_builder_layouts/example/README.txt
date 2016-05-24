Example Template
****************

This directory includes an example template that you can copy and rename to
create your own templates.

Create a new template
*********************
1. Go to admin/templates and add a new template. Only the fields that you check
will be available to be placed on this template using the drag-and-drop editor.
2. After saving, click this template’s name in the “Label” column at
admin/templates. For the custom template location, you will see something like
sites/all/themes/<yourtheme>/page_builder_layouts/<templatename>/page—<templatename>.tpl.php
For the custom thumbnail location, you will see something like
sites/all/themes/<yourtheme>/page_builder_layouts/<templatename>/<templatename>.svg
You will also see a warning that these are currently missing.
3. Copy this directory ("example") into the location indicated, e.g.,
sites/all/themes/<yourtheme>/page_builder_layouts/<templatename>
4. Rename the tpl.php and .svg files as indicated above.
5. Clear the cache.
6. If you have named the files correctly, you will no longer see a "Missing"
warning on the template page.
7. To make this new template available on any content types you have defined, go
to admin/structure/types and click "Edit" for the corresponding content type.
Under the "Available Templates" vertical tab, check this new template.

Lock fields to a region
***********************
1. To make a field always show in a certain location on the layout, find your
template at admin/templates and check the corresponding "Locked to region"
checkbox on the template. Note the machine name of the field(s) you checked.
2. Next, you need to make this template aware of where these locked fields
should appear. Open the tpl.php file you created above.
3. The example template comes with x predefined regions: content_top_left,
content_top_right, content_bottom, sidebar_content, and sidebar_second. It shows
one locked field, "field_social_links" defined within the content_top_right
region:

<section class="header_content_sidebars_top_right_region">
  <?php if (isset($locked_fields['field_utexas_social_links'])): ?>
    <div class="sidebar-default-style">
      <?php print render($locked_fields['field_utexas_social_links']); ?>
    </div>
  <?php endif; ?>
  <?php print render($page['content_top_right']); ?>
</section>

To add your own locked regions, follow the above logic, replacing
"field_utexas_social_links" with the machine name of the desired field.

Troubleshooting
***************
If you're seeing problems with fields not showing up, check the following:
- Does the template have the fields enabled? (admin/templates)
- Does the content type you are using have the template enabled? (admin/structure/types)
- Does the content type have the "Page Layout" and "Template" fields included? (admin/structure/types)
- Does the content type's display have the field set to "Display as block"?
- If you are trying to lock a field to a region, have you defined it in the
tpl.php file? (see "Lock fields to a region," above)

