<?php
/**
 * @file
 * Displays the homepage alert.
 *
 * Available variables:
 *  - $is_admin: Boolean to see if the user has administrative privileges.
 *  - $logged_in: Boolean to see if the user is logged in or not.
 *  - $is_front: Boolean to see if the page is the front page or not.
 *  - $announcement_title: Title of the homepage alert.
 *  - $announcement_background_color: Background color for the
 *    announcement container.
 *  - $announcement_call_to_action: Formatted link for the call to action.
 *  - $announcement_body: Body copy for announcement.
 *  - $title_icon: Icon to display next to the announcement title.
 *
 * @see template_preprocess_utexas_announcement()
 *
 * @ingroup themeable
 */
?>
<div class="container container-announcement <?php print $announcement_background_color; ?>">
  <div class="row">
    <div class="column medium-8 medium-centered">
      <div class="announcement"><span class="<?php print $title_icon; ?>"></span><?php print $announcement_title;?></div>
      <div class="announcement-text"><?php print $announcement_body;?></div>
       <?php if (!empty($announcement_call_to_action)) : print $announcement_call_to_action; ?><?php endif; ?>
    </div>
  </div>
</div>
