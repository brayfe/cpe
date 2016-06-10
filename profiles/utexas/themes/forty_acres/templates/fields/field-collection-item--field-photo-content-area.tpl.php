<?php
/**
 * @file
 * Field collection template for Photo Content Areas.
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
?>
<div class="row">
  <div class="column small-12 medium-6 force-width">
    <?php if (isset($values['field_photo']) and !empty($values['field_photo'])): ?>
      <div class="photo-wrap">
        <?php print render($values['field_photo'][0]['image']); ?>
        <div class="hero-caption">
          <span class="caption-copy"><?php print render($values['field_photo'][0]['credit']); ?></span>
        </div>
      </div>
    <?php endif; ?>
  </div>
  <div class="column small-12 medium-6 force-width">
    <div class="links">
      <?php if (isset($values['field_headline'])): ?>
        <h3 class="post-headline"><?php print render($values['field_headline']); ?></h3>
      <?php endif; ?>
      <?php if (isset($values['field_copy'])): ?>
        <p><?php print render($values['field_copy']); ?></p>
      <?php endif; ?>
      <?php if (isset($values['field_links'])): ?>
         <ul>
          <?php foreach ($values['field_links'] as $link): ?>
            <li><?php print l($link['#element']['title'], $link['#element']['url'], array(
              'html' => TRUE,
              'attributes' => array(
                'class' => array(
                  'cta-link',
                  'sans',
                ),
              ),
            )); ?></li>
          <?php endforeach; ?>
        </ul>
      <?php endif; ?>
    </div>
  </div>
</div>
