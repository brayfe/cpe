<?php

/**
 * @file
 * Twitter-API-PHP : Simple PHP wrapper for the v1.1 API.
 *
 * PHP version 5.3.10.
 *
 * @category Awesomeness
 *
 * @package Twitter-API-PHP
 *
 * @author James Mallison <me@j7mbo.co.uk>
 *
 * @license MIT License
 *
 * @link http://github.com/j7mbo/twitter-api-php
 */

/**
 * Twitter API Exchange class.
 */
class TwitterAPIExchange {
  private $oauthAccessToken;
  private $oauthAccessTokenSecret;
  private $consumerKey;
  private $consumerSecret;
  private $postfields;
  private $getfield;
  protected $oauth;
  public $url;

  /**
   * Create the API access object. Requires an array of settings.
   *
   * Oauth access token, oauth access token secret, consumer key, secret
   * These are all available by creating your own application on dev.twitter.com
   * Requires the cURL library.
   *
   * @param array $settings
   *   Twitter settings.
   */
  public function __construct(array $settings) {
    if (!in_array('curl', get_loaded_extensions())) {
      throw new Exception('You need to install cURL, see: http://curl.haxx.se/docs/install.html');
    }

    if (!isset($settings['oauth_access_token'])
      || !isset($settings['oauth_access_token_secret'])
      || !isset($settings['consumer_key'])
      || !isset($settings['consumer_secret'])) {
      throw new Exception('Make sure you are passing in the correct parameters');
    }
    $this->oauthAccessToken = $settings['oauth_access_token'];
    $this->oauthAccessTokenSecret = $settings['oauth_access_token_secret'];
    $this->consumerKey = $settings['consumer_key'];
    $this->consumerSecret = $settings['consumer_secret'];
  }

  /**
   * Set postfields array, example: array('screen_name' => 'J7mbo').
   *
   * @param array $array
   *   Array of parameters to send to API.
   *
   * @return object
   *   TwitterAPIExchange Instance of self for method chaining.
   */
  public function setPostfields(array $array) {
    if (!is_null($this->getGetfield())) {
      throw new Exception('You can only choose get OR post fields.');
    }
    if (isset($array['status']) && substr($array['status'], 0, 1) === '@') {
      $array['status'] = sprintf("\0%s", $array['status']);
    }
    $this->postfields = $array;

    return $this;
  }

  /**
   * Set getfield string, example: '?screen_name=J7mbo'.
   *
   * @param string $string
   *   Get key and value pairs as string.
   *
   * @return Object
   *   \TwitterAPIExchange Instance of self for method chaining.
   */
  public function setGetfield($string) {
    if (!is_null($this->getPostfields())) {
      throw new Exception('You can only choose get OR post fields.');
    }

    $search = array('#', ',', '+', ':');
    $replace = array('%23', '%2C', '%2B', '%3A');
    $string = str_replace($search, $replace, $string);

    $this->getfield = $string;

    return $this;
  }

  /**
   * Get getfield string (simple getter).
   *
   * @return string
   *   $this->getfields.
   */
  public function getGetfield() {
    return $this->getfield;
  }

  /**
   * Get postfields array (simple getter).
   *
   * @return array
   *   $this->postfields.
   */
  public function getPostfields() {
    return $this->postfields;
  }

  /**
   * Build the Oauth object.
   *
   * Using params set in construct and additionals passed to this method.
   * For v1.1, see: https://dev.twitter.com/docs/api/1.1.
   *
   * @param string $url
   *   The API url to use.
   *   Example: https://api.twitter.com/1.1/search/tweets.json.
   * @param string $request_method
   *   Either POST or GET.
   *
   * @return object
   *   \TwitterAPIExchange Instance of self for method chaining.
   */
  public function buildOauth($url, $request_method) {
    if (!in_array(strtolower($request_method), array('post', 'get'))) {
      throw new Exception('Request method must be either POST or GET');
    }

    $consumer_key = $this->consumerKey;
    $consumer_secret = $this->consumerSecret;
    $oauth_access_token = $this->oauthAccessToken;
    $oauth_access_token_secret = $this->oauthAccessTokenSecret;

    $oauth = array(
      'oauth_consumer_key' => $consumer_key,
      'oauth_nonce' => time(),
      'oauth_signature_method' => 'HMAC-SHA1',
      'oauth_token' => $oauth_access_token,
      'oauth_timestamp' => time(),
      'oauth_version' => '1.0',
    );

    $getfield = $this->getGetfield();

    if (!is_null($getfield)) {
      $getfields = str_replace('?', '', explode('&', $getfield));
      foreach ($getfields as $g) {
        $split = explode('=', $g);
        $oauth[$split[0]] = $split[1];
      }
    }

    $base_info = $this->buildBaseString($url, $request_method, $oauth);
    $composite_key = rawurlencode($consumer_secret) . '&' . rawurlencode($oauth_access_token_secret);
    $oauth_signature = base64_encode(hash_hmac('sha1', $base_info, $composite_key, TRUE));
    $oauth['oauth_signature'] = $oauth_signature;

    $this->url = $url;
    $this->oauth = $oauth;

    return $this;
  }

  /**
   * Perform the actual data retrieval from the API.
   *
   * @param bool $return
   *   If true, returns data.
   *
   * @return string
   *   If $return param is true, returns json data.
   */
  public function performRequest($return = TRUE) {
    if (!is_bool($return)) {
      throw new Exception('performRequest parameter must be true or false');
    }

    $header = array($this->buildAuthorizationHeader($this->oauth), 'Expect:');

    $getfield = $this->getGetfield();
    $postfields = $this->getPostfields();

    $options = array(
      CURLOPT_HTTPHEADER => $header,
      CURLOPT_HEADER => FALSE,
      CURLOPT_URL => $this->url,
      CURLOPT_RETURNTRANSFER => TRUE,
      CURLOPT_TIMEOUT => 10,
    );

    if (!is_null($postfields)) {
      $options[CURLOPT_POSTFIELDS] = $postfields;
    }
    else {
      if ($getfield !== '') {
        $options[CURLOPT_URL] .= $getfield;
      }
    }

    $feed = curl_init();
    curl_setopt_array($feed, $options);
    $json = curl_exec($feed);
    curl_close($feed);

    if ($return) {
      return $json;
    }
  }

  /**
   * Private method to generate the base string used by cURL.
   *
   * @param string $base_uri
   *   The base URI.
   * @param string $method
   *   Unused.
   * @param array $params
   *   Twitter params.
   *
   * @return string
   *   Built base string.
   */
  private function buildBaseString($base_uri, $method, array $params) {
    $return = array();
    ksort($params);

    foreach ($params as $key => $value) {
      $return[] = "$key=" . $value;
    }

    return $method . "&" . rawurlencode($base_uri) . '&' . rawurlencode(implode('&', $return));
  }

  /**
   * Private method to generate authorization header used by cURL.
   *
   * @param array $oauth
   *   Array of oauth data generated by buildOauth().
   *
   * @return string
   *   Header used by cURL for request.
   */
  private function buildAuthorizationHeader(array $oauth) {
    $return = 'Authorization: OAuth ';
    $values = array();

    foreach ($oauth as $key => $value) {
      $values[] = "$key=\"" . rawurlencode($value) . "\"";
    }
    $return .= implode(', ', $values);
    return $return;
  }

}
