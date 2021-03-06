Description of existing patch files for this distribution
*********************************************************

1. media_ckeditor_file_insert.patch
Slightly modifies how file metadata is inserted when using Media's WYSIWYG file
inserter so that it never uses the mediawrapper tag which is stripped out by
CKEditor. See https://www.drupal.org/files/issues/media-ckeditor-remove-mediawrapper-2177893-2.patch
and https://www.drupal.org/node/2542566#comment-10407747

2. media_ckeditor_multiple_insert.patch
Due to the unresolved problem reported here, https://www.drupal.org/node/2591069
which likely has to do with a greedy regex, we prevent the replacement of the
HTML with a placeholder tag. The downside is that the link to a file becomes
hardcoded into the HTML (legacy style), but all data displays correctly. Once
the issue is resolved, this patch can be undone.

3. node_clone_context.patch
Calls a function defined in utexas_admin to clone the context on a page-builder
enabled node.

4. context_reaction_block_permission.patch
Context Reaction Block requires the "administer contexts" permission to use the
layout editor. Since we don't want generic Site Builder roles to have access to
Context UI, we redefine the permission requirement relative to page builder.
https://utexas-digx.atlassian.net/browse/MC-192

5. workbench_contextual_link_notice.patch
When views_ui is not enabled, as it will not be in QuickSites instances, a
notice is produced due to an assumption, as reported at
https://www.drupal.org/node/1727284. The provided patch fixes this problem.

7. ckeditor_xss_caching_2069871.patch
If/when CKEditor's XSS logic receives no header response, caching is improperly
triggered, which results in the CKEditor toolbar not rendering. This workaround
simply disables CKEditor caching; this is only meant as a temporary fix until
CKEditor module maintainers provide a better solution. The problem is difficult
to reproduce, but both Henry Tijerina and John Kotarski reported it on UT Web
installs of UT Drupal Kit. See tickets 490232 and 488316.
See https://www.drupal.org/node/2069871

8. media_replicate-patches-in-media-ckeditor_MC-497.patch
The 2.0-beta1 version of Media, added in April 2016[1], included its own version of
the "media" CKEditor plugin, which was already present in the Media CKEditor
module, and to which we had applied two patches (#1 & #2, above). When the
CKEditor configuration is saved via the UI, it looks through the codebase for
the "media" plugin and finds the "first available" one. The most transparent
solution for existing sites is simply to replicate the patches in this second
version of the plugin. As of Sept 2016, the bug for which the patches are made
is still present[2], so we do need to keep this patch in place.
[1] https://bitbucket.org/utexas-its-drupal/managed-cms/commits/f67cd0f696d9d0722eac8998027fb461d16b21e2
[2] https://www.drupal.org/node/2591069
