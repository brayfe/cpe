<?php
/**
 * @file
 * Default template implementation to display a field collection view.
 *
 * Available variables:
 * - $element: the element to render.
 *
 * @see template_preprocess_field_collection_view()
 *
 * @ingroup themeable
 */

print render($element['entity']);
