<?php 
/**
 *  field tpl based on Forty Acres theme but showing labels
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
	<?php if (!$label_hidden): ?>
	<div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
	<?php endif; ?>

	<div class="<?php print $classes; ?>">
	  <?php foreach ($items as $delta => $item): ?>
	    <?php print render($item); ?>
	  <?php endforeach; ?>
	</div>
</div>

