#!/bin/bash

## Run CodeSniffer on selected files/directories. Commented out items
# include style "violations" that are needed but are erroneously flagged by
# phpcs version 1.5.x.
#
# You can either enter an argument, or sniff all the files if you do not specify one.

# LIST OF FILES/MODULES WE ARE IGNORING FOR NOW AND REASON WHY:
#
# themes/forty_acres/templates/views/views-view-table.tpl.php -- Core content we will not change.
# modules/custom/utexas_google_tag_manager/utexas_google_tag_manager.install -- l() function not recommended on .install file.
# modules/custom/utexas_google_tag_manager/utexas_google_tag_manager.module -- Constants name convention.
# modules/custom/utexas_page_builder/plugins/utexas_page_builder_context_reaction_block.inc -- Class name convention.
# modules/custom/utexas_page_builder/plugins/utexas_page_builder_views_plugin_display_block.inc -- Class name convention.
# modules/custom/utexas_page_builder/utexas_contact_info/utexas_contact_info.module -- Class name convention.
# modules/custom/utexas_page_builder/utexas_twitter_widget/utexas_twitter_widget.module -- Class name convention.
# modules/custom/utexas_devel/utexas_devel.install - Default content identation not possible.
#
##

echo "Starting CodeSniffer!"
echo "(Dont forget to enable coder first 'drush en coder -y')"

valid=n

if [ -z "$1" -o "$1" == "ip" ] ; then
  # Installation profile
  drush drupalcs ../utexas.profile
  drush drupalcs ../utexas.install
  drush drupalcs ../utexas.css
  drush drupalcs ../default_content/default_basic_page.inc
  # drush drupalcs ../default_content/default_page.inc
  # drush drupalcs ../default_content/landing_page.inc

  valid=y
fi

if [ -z "$1" -o "$1" == "themes" ] ; then
  # Themes
  drush drupalcs ../themes/forty_acres/template.php
  drush drupalcs ../themes/forty_acres/theme-settings.php
  drush drupalcs ../themes/forty_acres/templates
  drush drupalcs ../themes/STARTERKIT/template.php
  drush drupalcs ../themes/STARTERKIT/theme-settings.php
  drush drupalcs ../themes/STARTERKIT/templates

  valid=y
fi

if [ -z "$1" -o "$1" == "modules" ] ; then
  # Modules
  drush drupalcs ../modules/custom/utexas_devel/utexas_devel.module
  # drush drupalcs ../modules/custom/utexas_devel/utexas_devel.install
  drush drupalcs ../modules/custom/utexas_google_cse
  # drush drupalcs ../modules/custom/utexas_google_tag_manager
  drush drupalcs ../modules/custom/utexas_menu
  # drush drupalcs ../modules/custom/utexas_page_builder
  drush drupalcs ../modules/custom/utexas_social_accounts
  drush drupalcs ../modules/custom/utexas_tablesaw_filter
  drush drupalcs ../modules/custom/utexas_admin
  drush drupalcs ../modules/custom/utexas_beacon
  drush drupalcs ../modules/custom/utexas_fonts
  # drush drupalcs ../modules/custom/features/content_types/faculty_profile/faculty_profile.module
  drush drupalcs ../modules/custom/features/content_types/faculty_profile/faculty_profile.install
  drush drupalcs ../modules/custom/features/content_types/faculty_profile/page_layout/page--faculty-profile.tpl.php

  valid=y
fi

if [ "$valid" == "n" ]; then
  script=$(basename $0)
  echo "That CodeSniffer option does not exist."
  echo "Options:  $script ip (installation profile)"
  echo "          $script themes"
  echo "          $script modules"
fi
