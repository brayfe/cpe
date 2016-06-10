<?php
/**
 * @file
 * Template file for main menu items.
 *
 * Available variables:
 *   - $menu: Menu object.
 *
 * @see template_preprocess_utexas_menu().
 *
 * @ingroup themeable
 */
?>
<ul class="nav" id="main-nav" role="menu">
  <?php foreach ($menu as $key => $item): ?>
    <?php if (is_numeric($key)): ?>
      <li class="nav-item" role="menuitem">
        <?php
          print l($item['#title'], $item['#href'], array(
            'attributes' => array(
              'class' => array(
                'nav-link',
                (count($item['#below'])) ? 'has-children' : '',
              ),
            ),
          ));
        ?>
        <?php
          print l('<span class="icon-chevron-down"><span class="hiddenText">' . t('Expand') . '</span></span>', $item['#href'], array(
            'html' => TRUE,
            'attributes' => array(
              'class' => array(
                'caret',
                'nav-link',
                (count($item['#below'])) ? 'has-child' : '',
              ),
            ),
          ));
        ?>
        <?php if (count($item['#below'])): ?>
          <div class="sub-nav-wrapper">
            <div class="sub-nav-row">
              <ul class="sub-nav">
                <?php foreach ($item['#below'] as $subkey => $subitem): ?>
                  <?php if (isset($subitem['#title']) and isset($subitem['#href'])): ?>
                    <li class="sub-nav-item">
                      <?php print l('<span>' . check_plain($subitem['#title']) . '</span>', $subitem['#href'], array('html' => TRUE, 'attributes' => array('class' => array('sub-nav-link')))); ?>
                    </li>
                  <?php endif; ?>
                <?php endforeach; ?>
              </ul>
            </div>
          </div>
        <?php endif; ?>
      </li>
    <?php endif; ?>
  <?php endforeach ?>
</ul>
