module.exports = {
  dist: {
        files: [
            {
                expand: true,
                cwd: '<%= path.dist %>/js',
                src: ['*.js', '!*.min.js'],
                dest: '<%= path.dist %>/js',
                extDot: 'last',
                ext: '.min.js'
            }
        ]
    }
}