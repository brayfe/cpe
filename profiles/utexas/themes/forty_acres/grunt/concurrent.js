module.exports = {
	'copy-dist': [
		'copy:fonts',
		'copy:js'
	],
	'copy-build': [
		'copy:forty_acres'
	],
	'minify': [
		'uglify:dist'
	]
}