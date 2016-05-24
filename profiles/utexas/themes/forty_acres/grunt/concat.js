module.exports = {

    jquery_plugins: {
        files: {
            '<%= path.dist %>/js/jquery.plugins.js': [
                '<%= path.src %>/bower_components/jquery-placeholder/jquery.placeholder.js',
                '<%= path.src %>/bower_components/jquery.browser/dist/jquery.browser.min.js'
            ]
        }
    },

    foundation: {
        files : {
          '<%= path.dist %>/js/foundation.js': [
            '<%= path.src %>/bower_components/fastclick/lib/fastclick.js',
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.js',
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.equalizer.js',
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.magellan.js',
          ]
        }
    },

    application: {
        files : {
          '<%= path.dist %>/js/application.js': [
            '<%= path.src %>/bower_components/Accessible-Mega-Menu/js/jquery-accessibleMegaMenu.js',
            '<%= path.src %>/js/navigation.js',
            '<%= path.src %>/js/layout.js',
            '<%= path.src %>/js/app.js'
          ]
        }
    },

    news: {
        files : {
          '<%= path.dist %>/js/news.js': [
            '<%= path.src %>/js/navigation.js',
            '<%= path.src %>/js/layout.js',
            '<%= path.src %>/js/news.js'
          ]
        }
    },

    polyfill: {
        files : {
          '<%= path.dist %>/js/polyfill.js': [
            '<%= path.src %>/bower_components/jquery-1.9.1/index.js',
            '<%= path.src %>/bower_components/html5shiv/dist/html5shiv.js',
            '<%= path.src %>/bower_components/nwmatcher/src/nwmatcher.js',
            '<%= path.src %>/bower_components/selectivizr/selectivizr.js',
            '<%= path.src %>/bower_components/respond/dest/respond.src.js',
            '<%= path.src %>/bower_components/REM-unit-polyfill/js/rem.js'
          ]
        }
    },
    foundation_options: {
        files : {
          '<%= path.dist %>/js/foundation.accordion.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.accordion.js'
          ],
          '<%= path.dist %>/js/foundation.alert.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.alert.js'
          ],
          '<%= path.dist %>/js/foundation.dropdown.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.dropdown.js'
          ],
          '<%= path.dist %>/js/foundation.abide.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.abide.js'
          ],
          '<%= path.dist %>/js/foundation.reveal.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.reveal.js'
          ],
          '<%= path.dist %>/js/foundation.tab.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.tab.js'
          ],
          '<%= path.dist %>/js/foundation.tooltip.js': [
            '<%= path.src %>/bower_components/foundation/js/foundation/foundation.tooltip.js'
          ]
        }
    }

};
