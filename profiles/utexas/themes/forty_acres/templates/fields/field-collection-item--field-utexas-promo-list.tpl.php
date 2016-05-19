<?php
/**
 * @file
 * Field collection template for Promo List Collections.
 *
 * Available variables:
 *  - $classes: A string of classes to add to the field collection item.
 *  - $attributes: A string representing attributes to add to this item.
 *  - $content_attributes: Content attributes for the item.
 *  - $content: The content itself.
 *  - $values: Rendered values of the fields.
 *
 * @see template_preprocess_field_collection_item().
 *
 * @ingroup themeable.
 */

if ($values['field_utexas_promo_list_style'][0]['#markup'] == 'Single list responsive (2 items per row)') :
  $promo_list_style = 'two-column';
  $promo_list_class = 'columns small-12 large-6 end';
elseif ($values['field_utexas_promo_list_style'][0]['#markup'] == 'Single list full (1 item per row)') :
  $promo_list_style = 'one-column-full-width small-12 end ';
  $promo_list_class = '';
else :
  $promo_list_style = 'one-column small-12 large-6 end';
  $promo_list_class = '';
endif;
?>
<div class="column <?php echo $promo_list_style; ?>">
  <div class="utexas-promo-list-wrapper">
    <?php if (!empty($values['field_utexas_promo_list_headline'])): ?>
      <h3 class="post-headline"><?php print render($values['field_utexas_promo_list_headline']); ?></h3>
    <?php endif; ?>
    <div class="promo-list-item-wrapper">
      <?php if (!empty($values['field_utexas_promo_list_item'])): ?>
        <?php foreach ($values['field_utexas_promo_list_item'] as $promo_list_item): ?>
          <div class="promo-list-li <?php print $promo_list_class; ?>"><?php print render($promo_list_item); ?></div>
        <?php endforeach; ?>
      <?php endif; ?>
    </div>
  </div>
</div>
