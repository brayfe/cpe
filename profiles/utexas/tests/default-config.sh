# SETTING UP BEHAT WITH AN SPECIFIC GOOGLE CHROME VERSION
#
# 1. Download the Google Chrome .dmg file with your favorite downgraded version
# you rather use (in my case Chrome 43).
# You can get it at: http://google-chrome.en.uptodown.com/mac/old
#
# 2. Open the dmg file and drag and drop the file into any directory that is
# NOT Applications. Rename the file from "Google Chrome" to something
# like "Google Chrome [version number]".
#
# 3. Move the file you just renamed to the Applications directory,
# so now you will have your updated Chrome version and your custom Chrome
# downgraded version living together.
#
# 4. Create a bash script like this
# https://bitbucket.org/snippets/utexas-its-drupal/5E7po
# (also available at the "Installation" tab at
# https://wikis.utexas.edu/display/UTDK/Running+Automated+Tests) and paste it
#  in your /usr/local/bin directory.
#
# 5. Update the content of this file to match your site alias, base_url,
# drupal_root and the Chrome file name in the "capabilities" section matching
# the file name from your downgraded .app Chrome filename.
#
# 6. Rename this file to "config.sh" and save it in this
# same directory (profiles/[installation_profile]/tests).

export BEHAT_PARAMS='{"extensions":{"Behat\\MinkExtension":{"selenium2":{"wd_host":"http://localhost:4444/wd/hub/", "capabilities": {"chrome":{"binary": "/Applications/Google Chrome 42.app/Contents/MacOS/Google Chrome", "switches":["--user-data-dir= /Users/lar3597/tmp/Google Chrome/42/"]}}},"base_url":"http://mc.local"},"Drupal\\DrupalExtension":{"drush":{"alias":"mc-local"},"drupal":{"drupal_root":"/Applications/MAMP/htdocs/mc"}}}}'
