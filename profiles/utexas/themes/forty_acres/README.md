# UT Homepage

This is the homepage for the Univeristy of Texas

## Requirements

You'll need to have the following items installed before continuing.

  * [Node.js](http://nodejs.org): Use the installer provided on the NodeJS website or Homebrew.
  * [Grunt](http://gruntjs.com/): Run `[sudo] npm install -g grunt-cli`
  * [Bower](http://bower.io): Run `[sudo] npm install -g bower`

Check to see if everything is installed correctly by running:

grunt --version
node --version
npm --version
bower --version

## Quickstart to install node modules and bower components

```bash
npm install && bower install
```

While you're working on your project, run:

`grunt`

And you're set!

## Building for Drupal
Once you're ready to make a full build to convert to Drupal, run

`grunt build`


## Directory Structure

  * `scss/_settings.scss`: Foundation configuration settings go in here
  * `scss/app.scss`: Application styles go here

** if you encounter errors related to the .info files produced in node_modules conflicting with drupal's 
theme settings run the npm_post.sh script
```bash
sh npm_post.sh
```
