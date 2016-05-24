module.exports = {
  options: {
    includePaths: ['<%= path.src %>/bower_components/foundation/scss']
  },
  dev: {
    options: {
      outputStyle: 'nested'
    },
    files: {
      '<%= path.dist %>/css/base.css': '<%= path.src %>/scss/build/base.scss',
      '<%= path.dist %>/css/forty_acres_pages.css': '<%= path.src %>/scss/build/forty_acres_pages.scss',
      '<%= path.dist %>/css/forty_acres.css': '<%= path.src %>/scss/build/forty_acres.scss',
      '<%= path.dist %>/css/foundation.accordion.css': '<%= path.src %>/scss/build/accordion.scss',
      '<%= path.dist %>/css/foundation.alert.css': '<%= path.src %>/scss/build/alert.scss',
      '<%= path.dist %>/css/foundation.dropdown.css': '<%= path.src %>/scss/build/dropdown.scss',
      '<%= path.dist %>/css/foundation.reveal.css': '<%= path.src %>/scss/build/reveal.scss',
      '<%= path.dist %>/css/foundation.tab.css': '<%= path.src %>/scss/build/tab.scss',
      '<%= path.dist %>/css/foundation.tooltip.css': '<%= path.src %>/scss/build/tooltip.scss'
    }
  },
  dist: {
    files: {
      '<%= path.dist %>/css/base.css': '<%= path.src %>/scss/build/base.scss',
      '<%= path.dist %>/css/forty_acres_pages.css': '<%= path.src %>/scss/build/forty_acres_pages.scss',
      '<%= path.dist %>/css/forty_acres.css': '<%= path.src %>/scss/build/forty_acres.scss',
      '<%= path.dist %>/css/foundation.accordion.css': '<%= path.src %>/scss/build/accordion.scss',
      '<%= path.dist %>/css/foundation.alert.css': '<%= path.src %>/scss/build/alert.scss',
      '<%= path.dist %>/css/foundation.dropdown.css': '<%= path.src %>/scss/build/dropdown.scss',
      '<%= path.dist %>/css/foundation.reveal.css': '<%= path.src %>/scss/build/reveal.scss',
      '<%= path.dist %>/css/foundation.tab.css': '<%= path.src %>/scss/build/tab.scss',
      '<%= path.dist %>/css/foundation.tooltip.css': '<%= path.src %>/scss/build/tooltip.scss'
    }
  }
}
