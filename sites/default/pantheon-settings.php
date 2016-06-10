<?php

// Provide a Pantheon environment identifier as a $conf variable.
$conf['pantheon_environment'] = $_ENV['PANTHEON_ENVIRONMENT'];

// Decode Pantheon Settings
$ps = json_decode($_SERVER['PRESSFLOW_SETTINGS'], TRUE);

// Provide universal absolute path to the SimpleSAMLphp installation.
$conf['simplesamlphp_auth_installdir'] = '/srv/bindings/'. $ps['conf']['pantheon_binding'] .'/code/private/simplesamlphp-1.11.0';

// By default we don't want to automatically create a Drupal account when a
// user authenticates via UTLogin.  Change this to 1 or TRUE if you have a
// site that _does_ need autoprovisioning of Drupal accounts for users
// authenticating via SAML.
$conf['simplesamlphp_auth_registerusers'] = 0;

// Which attributes from UTLogin should we use for various user fields
$conf['simplesamlphp_auth_unique_id'] = "uid";
$conf['simplesamlphp_auth_user_name'] = "displayName";
$conf['simplesamlphp_auth_mailattr'] = "mail";

// We want to make sure User 1 can always log in using local authentication
// (even if SAML auth is enabled).  There are two settings required for this:
// * simplesamlphp_auth_allowdefaultlogin
// * simplesamlphp_auth_allowdefaultloginusers
//
// "Allow authentication with local Drupal accounts"
$conf['simplesamlphp_auth_allowdefaultlogin'] = 1;

// "Which users should be allowed to login with local accounts?
// A comma-separated list of user IDs that should be allowed to login without
// simpleSAMLphp. If left blank, all local accounts can login."
$conf['simplesamlphp_auth_allowdefaultloginusers'] = "1";
// (NOTE: "all accounts can login" if this setting is blank *only* if the
// roles also allow it -- you either need to include "1" here, or make sure
// administrators are allowed via the
// simplesamlphp_auth_allowdefaultloginroles setting).

// Change the text for the SAML link on the login page
$conf['simplesamlphp_auth_login_link_display_name'] = "Log in with UT EID";

// After logging out of Drupal, send the user to the UTLogin logout page, so
// their session is ended there as well.
// NOTE: By default they'll be redirected to www.utexas.edu once they're
// logged out of UTLogin.  See this page for more on the UTLogin logout URL:
// https://www.utexas.edu/its/help/utlogin/2377
$conf['simplesamlphp_auth_logoutgotourl'] = "https://login.utexas.edu/login/UI/Logout";

if (php_sapi_name() != "cli") {
  // Logic to redirect traffic to HTTPS.
  $url = $_SERVER['HTTP_HOST'];
  $redirect = FALSE;
  $www = strpos($url, 'www.');
  if ($www === 0) {
    // The request begins with "www." . Rewrite the URL only to include
    // everything after "www." and trigger the redirect.
    $url = substr($url, 4);
    $redirect = TRUE;
  }
  if ($_SERVER['HTTP_X_FORWARDED_PROTO'] != 'https') {
    // The request is to HTTP. Trigger the redirect.
    $redirect = TRUE;
  }
  if ($redirect) {
    // Send all traffic to HTTPS.
    header('HTTP/1.0 301 Moved Permanently');
    header('Location: ' . 'https://' . $url . $_SERVER['REQUEST_URI']);
    header('Cache-Control: public, max-age=3600');
    exit();
  }
}
