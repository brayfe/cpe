<?php

/**
 * @file
 * Displays the Contact Info form.
 *
 * @see utexas_contact_info_theme()
 *
 * @ingroup themeable
 */
?>
<?php
echo '<div class="field_contact_info">';
echo '<h4>' . $content['title'] . '</h4>';
echo '<div class="address">';

if ($content['has_location']) :
  echo '<div class="label">Location:</div>';
  echo '<div class="contact-info-location">';
  echo $content['location_1'] ? '<div class="field field_location_1">' . $content['location_1'] . '</div>' : '';
  echo $content['location_2'] ? '<div class="field field_location_2">' . $content['location_2'] . '</div>' : '';
  echo $content['location_3'] ? '<div class="field field_location_3">' . $content['location_3'] . '</div>' : '';
  echo '<div class="field field_location_location">';
  echo '<div class="field field_location_location">' . $content['location_city'] . $content['location_state'] . $content['location_zip'] . '</div>';
  echo '</div>';
  echo '</div>';
endif;
if ($content['has_address']) :
  echo '<div class="label">Mailing Address:</div>';
  echo '<div class="contact-info-address">';
  echo '<div class="field field_address_1">' . $content['address_1'] . '</div>';
  echo '<div class="field field_address_2">' . $content['address_2'] . '</div>';
  echo '<div class="field field_address_3">' . $content['address_3'] . '</div>';
  echo '<div class="field field_address_location">';
  echo '<div class="field field_address_location">' . $content['address_city'] . $content['address_state'] . $content['address_zip'] . '</div>';
  echo '</div>';
  echo '</div>';
endif;
echo $content['phone'] ? '<div class="field field_phone"> <p class="label">Phone:</p> <a href="tel:' . $content['phone'] . '">' . $content['phone'] . '</a> </div>' : '';
echo $content['email'] ? '<div class="field field_email"> <p class="label">Email:</p> <a href="mailto:' . $content['email'] . '">' . $content['email'] . '</a> </div>' : '';
echo $content['fax'] ? '<div class="field field_fax"> <p class="label">Fax:</p> <div class="field field_fax">' . $content['fax'] . '</div> </div>' : '';
echo $content['website'] ? '<div class="field field_website"> <p class="label">Website:</p> <a href="' . $content['website'] . '">' . $content['website'] . '</a> </div>' : '';
echo '</div>';
echo '</div>';
?>
