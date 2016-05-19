<?php
/**
 * @file
 * Returns Twitter object.
 */

require_once 'TwitterAPIExchange.php';

/**
 * Set access tokens here - see: https://dev.twitter.com/apps/.
 */
$settings = array(
  'oauth_access_token' => "",
  'oauth_access_token_secret' => "",
  'consumer_key' => "",
  'consumer_secret' => "",
);

/**
 * URL for REST request, see: https://dev.twitter.com/docs/api/1.1/.
 */
$url = 'https://api.twitter.com/1.1/blocks/create.json';
$request_method = 'POST';

/**
 * POST fields required by the URL above. See relevant docs as above.
 */
$postfields = array(
  'screen_name' => 'usernameToBlock',
  'skip_status' => '1',
);

/**
 * Perform a POST request and echo the response.
 */
$twitter = new TwitterAPIExchange($settings);
echo $twitter->buildOauth($url, $request_method)
  ->setPostfields($postfields)
  ->performRequest();

/**
 * Perform a GET request and echo the response.
 *
 * Note: Set the GET field BEFORE calling buildOauth();
 */
$url = 'https://api.twitter.com/1.1/followers/ids.json';
$getfield = '?screen_name=J7mbo';
$request_method = 'GET';
$twitter = new TwitterAPIExchange($settings);
echo $twitter->setGetfield($getfield)
  ->buildOauth($url, $request_method)
  ->performRequest();
