module.exports = {
  options: {
    livereload: true
  },

  grunt: { files: ['Gruntfile.js'] },

  sass: {
    files: '<%= path.src %>/scss/**/*.scss',
    tasks: ['sass:dev', 'autoprefixer:dev'],
    options: {
      livereload: false
    }
  },
  css: {
    files: '<%= path.dist %>/css/**/*.css',
    tasks: ['copy:forty_acres','cmq','csslint']
  },

  js: {
    files: '<%= path.src %>/js/**/*.js',
    tasks: ['concat','newer:uglify']
  }
};