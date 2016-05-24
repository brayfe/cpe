<?php
/**
 * @file
 * Field collection template for Contact Info.
 *
 * Available variables:
 *  - $classes: A string of classes to add to the field collection item.
 *  - $attributes: A string representing attributes to add to this item.
 *  - $content_attributes: Content attributes for the item.
 *  - $content: The content itself.
 *  - $values: Rendered values of the fields.
 *
 * @see template_preprocess_node().
 *
 * @ingroup themeable.
 */

// Validates if there are no location fields.
$field_location_exists = FALSE;
$field_location_array = array(
  "field_location_1",
  "field_location_2",
  "field_location_city",
  "field_location_state",
  "field_location_zip",
);
foreach ($field_location_array as $location_element) :
  if (array_key_exists($location_element, $content)) :
    $field_location_exists = TRUE;
    break;
  endif;
endforeach;
// Validates if there are no address fields.
$field_address_exists = FALSE;
$field_address_array = array(
  "field_address_1",
  "field_address_2",
  "field_address_city",
  "field_address_state",
  "field_address_zip",
);
foreach ($field_address_array as $address_element) :
  if (array_key_exists($address_element, $content)) :
    $field_address_exists = TRUE;
    break;
  endif;
endforeach;

?>
<div class="field_contact_info">
  <h4><?php print (!empty($title)) ? render($title) : t('Contact') ?></h4>
  <div class="address">
    <?php if ($field_location_exists) : print ('<div class="label">Location:</div>'); ?><?php endif; ?>
    <div class="contact-info-location">
      <?php if (!empty($content['field_location_1'])) : print render($content['field_location_1']); ?><?php endif; ?>
      <?php if (!empty($content['field_location_2'])) : print render($content['field_location_2']); ?><?php endif; ?>
      <div class='field field_location_location'>
        <?php if (!empty($content['field_location_city'])) :  print ($content['field_location_city']['#items']['0']['value'] . ", "); ?><?php endif; ?> <?php if (!empty($content['field_location_state'])) :  print ($content['field_location_state']['#items']['0']['value']); ?><?php endif; ?> <?php if (!empty($content['field_location_zip'])) :  print ($content['field_location_zip']['#items']['0']['value']); ?><?php endif; ?>
      </div>
    </div>
    <?php if ($field_address_exists) : print ('<div class="label">Mailing Address:</div>'); ?><?php endif; ?>
    <div class="contact-info-address">
      <?php if (!empty($content['field_address_1'])) : print render($content['field_address_1']); ?><?php endif; ?>
      <?php if (!empty($content['field_address_2'])) :  print render($content['field_address_2']); ?><?php endif; ?>
      <div class='field field_address_location'>
        <?php if (!empty($content['field_address_city'])) :  print ($content['field_address_city']['#items']['0']['value'] . ", "); ?><?php endif; ?> <?php if (!empty($content['field_address_state'])) :  print ($content['field_address_state']['#items']['0']['value']); ?><?php endif; ?> <?php if (!empty($content['field_address_zip'])) :  print ($content['field_address_zip']['#items']['0']['value']); ?><?php endif; ?>
      </div>
    </div>
    <!-- Render the <a> element for phone -->
    <?php if (!empty($content['field_phone'])) : print ("<p class='label'>"); print render($content['field_phone']['#title']) . ":</p>";
    print ("<a href='tel:" . $content['field_phone']['#items']['0']['value'] . "'><p>" . $content['field_phone']['#items']['0']['value'] . "</p></a>"); ?><?php endif; ?>
    <!-- /Render the <a> element for phone -->

    <!-- Render the <a> element for email -->
    <?php if (!empty($content['field_email'])) : print ("<p class='label'>"); print render($content['field_email']['#title']) . ":</p>";
    print ("<a href='mailto:" . $content['field_email']['#items']['0']['value'] . "'><p>" . $content['field_email']['#items']['0']['value'] . "</p></a>"); ?><?php endif; ?>
    <!-- /Render the <a> element for email -->
    <?php if (!empty($content['field_fax'])) : print ("<p class='label'>"); print render($content['field_fax']['#title']) . ":"; print render($content['field_fax']); ?><?php endif; ?>
    <!-- Render the <a> element for Website -->
    <?php if (!empty($content['field_url'])) : print ("<p class='label'>"); print render($content['field_url']['#title']) . ":</p>";
    print ("<a href='" . $content['field_url']['#items']['0']['value'] . "'><p>" . $content['field_url']['#items']['0']['value'] . "</p></a>"); ?><?php endif; ?>
    <!-- Render the <a> element for phone -->
  </div>
</div>
