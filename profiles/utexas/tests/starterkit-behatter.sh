#!/bin/bash

# This script serves as a wrapper for running our behat test suite.
# It takes screenshots prior to running the suite and does an imagemagick compare of them and baseline images for CSS regression testing.
# The script accepts two arguments: screen or noscreen.
# Running the script with the screen argument will only execute the screenshot comparison.
# Running the script with the noscreen argument will only execute the behat test suite.
# Running the script with the all argument will only execute both.
#
# SETUP:
#
# First you'll need to make the script executable:
# chmod u+x starterkit-behatter.sh
# Create a Bash alias for easier execution by adding the following to your .bash_profile:
# alias starterkit-diff='/full/path/to/starterkit-behatter.sh'
# You can then run the script with the commands 'starterkit-diff all','starterkit-diff screens', or 'starterkit-diff noscreens'.


# Get the full path to this script
script_path="`dirname \"$0\"`"

# Source the config file
source $script_path/config.sh

# Get a timestamp for log naming
now="$(date +%s)"

if [ "$1" == "all" ] || [ "$1" == "noscreens" ] || [ "$1" == "screens" ]; then

  # If noscreens argument was passed or no argument (all steps) given run the behat suite.
  if [ "$1" == "all" ] || [ "$1" == "noscreens" ]; then
    # Run the full behat suite - outputting to screen and logs
    echo "Running behat test suite..."
    echo ===========================================================================
    behat --config="$script_path/behat.yml" --tags ~screenshots | tee "$script_path/logs/behat-$now.log"
    echo ===========================================================================
  fi
  
  # If screens argument was passed or no argument (all steps) given run the screen tests with phantom.js.
  if [ "$1" == "all" ] || [ "$1" == "screens" ]; then

    behat --config="$script_path/behat.yml" features/starterkit_screenshot_regression.feature -p phantomjs | tee "$script_path/logs/screens-$now.log"

    # Find the newest screenshots of the front page with starterkit enabled...
    newest_front_1200_screen_starterkit="$(ls -t $script_path/regressions/behat-regression-starterkit-front-1200* | head -1)"
    newest_front_850_screen_starterkit="$(ls -t $script_path/regressions/behat-regression-starterkit-front-850* | head -1)"
    newest_front_350_screen_starterkit="$(ls -t $script_path/regressions/behat-regression-starterkit-front-350* | head -1)"

    # Compare the front screenshots to the screenshots taken with the starterkit enabled
    front_1200_compare_output_starterkit="$(compare -metric AE $script_path/regressions/baselines/front-1200-width-baseline.png $newest_front_1200_screen_starterkit null: 2>&1)"
    front_850_compare_output_starterkit="$(compare -metric AE $script_path/regressions/baselines/front-850-width-baseline.png $newest_front_850_screen_starterkit null: 2>&1)"
    front_350_compare_output_starterkit="$(compare -metric AE $script_path/regressions/baselines/front-350-width-baseline.png $newest_front_350_screen_starterkit null: 2>&1)"


    # If the 1200 width front screenshots are the same we're okay.
    if [[ $front_1200_compare_output_starterkit == "0" ]]; then
      echo "CSS regression for STARTERKIT front 1200 width front test passed. There are no differences between the screenshots."

    # If the 1200 width front screenshots are a different height, a diff image can't be created.
    elif [[ $front_1200_compare_output_starterkit == *"compare: image widths or heights differ"*  ]]; then
      echo ===========================================================================
      echo "The baseline and most recent STARTERKIT front 1200 width screenshot differ in size and can't be compared. Opening both for comparison..."
      open $newest_front_1200_screen_starterkit -a preview.app
      open $script_path/regressions/baselines/front-1200-width-baseline.png -a preview.app

    # If the 1200 width front screenshots are the same size but different, create a diff image and open it for the tester.
    else
      echo ===========================================================================
      echo "There are differences between the front 1200 width baseline and the most recent STARTERKIT screenshot..."
      echo "Creating a diff image for comparison..."
      compare $script_path/regressions/baselines/front-1200-width-baseline.png $newest_front_1200_screen_starterkit \
      -compose Src -highlight-color SeaGreen $script_path/regressions/front-1200-diff-$now.png
      newest_front_1200_diff="$(ls -t $script_path/regressions/front-1200-diff* | head -1)"
      #this step will need to be removed/conditionally executed for anything other than a Mac
      open $newest_front_1200_diff -a preview.app
    fi

    # If the 850 width front screenshots are the same we're okay.
    if [[ $front_850_compare_output_starterkit == "0" ]]; then
      echo "CSS regression for STARTERKIT front 850 width front test passed. There are no differences between the screenshots."

    # If the 850 width front screenshots are a different height, a diff image can't be created.
    elif [[ $front_850_compare_output_starterkit == *"compare: image widths or heights differ"*  ]]; then
      echo ===========================================================================
      echo "The baseline and most recent STARTERKIT front 850 width screenshot differ in size and can't be compared. Opening both for comparison..."
      open $newest_front_850_screen_starterkit -a preview.app
      open $script_path/regressions/baselines/front-850-width-baseline.png -a preview.app

    # If the 850 width screenshots are the same size but different, create a diff image and open it for the tester.
    else
      echo ===========================================================================
      echo "There are differences between the front 850 width baseline and the most recent STARTERKIT screenshot..."
      echo "Creating a diff image for comparison..."
      compare $script_path/regressions/baselines/front-850-width-baseline.png $newest_front_850_screen_starterkit \
      -compose Src -highlight-color SeaGreen $script_path/regressions/front-850-diff-$now.png
      newest_front_850_diff="$(ls -t $script_path/regressions/front-850-diff* | head -1)"
      #this step will need to be removed/conditionally executed for anything other than a Mac
      open $newest_front_850_diff -a preview.app
    fi

    # If the 350 width front screenshots are the same we're okay.
    if [[ $front_350_compare_output_starterkit == "0" ]]; then
      echo "CSS regression for STARTERKIT front 350 width front test passed. There are no differences between the screenshots."

    # If the 350 width front screenshots are a different height, a diff image can't be created.
    elif [[ $front_350_compare_output_starterkit == *"compare: image widths or heights differ"*  ]]; then
      echo ===========================================================================
      echo "The baseline and most recent STARTERKIT front 350 width screenshot differ in size and can't be compared. Opening both for comparison..."
      open $newest_front_350_screen_starterkit -a preview.app
      open $script_path/regressions/baselines/front-350-width-baseline.png -a preview.app

    # If the 350 width screenshots are the same size but different, create a diff image and open it for the tester.
    else
      echo ===========================================================================
      echo "There are differences between the front 350 width baseline and the most recent STARTERKIT screenshot..."
      echo "Creating a diff image for comparison..."
      compare $script_path/regressions/baselines/front-350-width-baseline.png $newest_front_350_screen_starterkit \
      -compose Src -highlight-color SeaGreen $script_path/regressions/front-350-diff-$now.png
      newest_front_350_diff="$(ls -t $script_path/regressions/front-350-diff* | head -1)"
      #this step will need to be removed/conditionally executed for anything other than a Mac
      open $newest_front_350_diff -a preview.app
    fi

  fi


else
  # Only run when appropriate argument is passed.
  script=$(basename $0)
  echo "That $script option does not exist."
  echo "Options:  $script screens"
  echo "          $script noscreens"
  echo "          $script all"
fi