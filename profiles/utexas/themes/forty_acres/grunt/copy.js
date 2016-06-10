module.exports = {
      fonts: {
        files: [{
          expand: true,
          cwd: '<%= path.src %>/fonts/',
          src: ['**'],
          dest: '<%= path.dist %>/fonts'
        }]
      },
      js: {
      	files: [{
      		expand: true,
      		flatten: true,
      		src: [
      			'<%= path.src %>/bower_components/modernizr/modernizr.js',
      			'<%= path.src %>/bower_components/jquery/dist/jquery.js'
      		],
      		dest: '<%= path.dist %>/js'
      	}]
      },
      forty_acres: {
        files: [
          // Fonts
          {
            expand: true,
            cwd: '<%= path.dist %>/fonts/',
            src: ['**'],
            dest: 'fonts'
          },
          /* Stylesheets -- only foundation CSS files copied, site CSS files are copied using CMQ package. */
          {
            expand: true,
            cwd: '<%= path.dist %>/css/',
            src: ['overrides.css', 'foundation.accordion.css', 'foundation.alert.css',
            'foundation.dropdown.css', 'foundation.reveal.css', 'foundation.tab.css', 'foundation.tooltip.css'],
            dest: 'css'
          },
          // Scripts
          {
            expand: true,
            cwd: '<%= path.dist %>/js/',
            src: ['application.min.js', 'foundation.min.js', 'jquery.min.js', 'jquery.plugins.min.js', 'modernizr.min.js', 'polyfill.min.js',
            'foundation.accordion.js', 'foundation.alert.js', 'foundation.dropdown.js', 'foundation.abide.js', 'foundation.reveal.js', 'foundation.tab.js', 'foundation.tooltip.js'],
            dest: 'js'
          }
        ]
      },
    }
