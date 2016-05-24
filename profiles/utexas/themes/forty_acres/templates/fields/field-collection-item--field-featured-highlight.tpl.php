<?php
/**
 * @file
 * Field collection template for Featured Highlights.
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

// Figure out which version of the highlight to display -- light or dark.
$style = (isset($values['field_highlight_style'][0]) and !empty($values['field_highlight_style'][0]))
 ? render($values['field_highlight_style'][0])
 : 'dark';
$style = strtolower($style);

// Get a re-styled CTA link.
$link = (isset($values['field_call_to_action'][0]['#element']))
 ? l(
    $values['field_call_to_action'][0]['#element']['title'],
    $values['field_call_to_action'][0]['#element']['url'],
    array('html' => TRUE, 'attributes' => array('class' => array('cta-link')))
  )
 : FALSE;

// Get a linkified image.
$image = (isset($values['field_call_to_action'][0]['#element']['url']))
 ? l(
    render($values['field_image']),
    $values['field_call_to_action'][0]['#element']['url'],
    array(
      'html' => TRUE,
      'absolute' => TRUE,
    )
  )
 : render($values['field_image']);
?>
<div class="container container-highlight <?php print $style; ?>">
  <div class="row">
    <div class="column small-12">
      <div class="highlight-image template-highlight"><?php print $image; ?></div>
      <div class="highlight-date"><?php print render($values['field_date']); ?></div>
      <h2 class="highlight-headline"><?php print render($values['field_headline']); ?></h2>
      <div class="highlight-text">
        <p><?php print render($values['field_copy']); ?>
        <?php if ($link): ?>
          <?php print $link; ?>
        <?php endif; ?></p>
      </div>
    </div>
  </div>
</div>
