<?php

//$conf['theme_debug'] = TRUE;

/* Stage File Proxy Settings */
$conf['stage_file_proxy_origin'] = "http://live-center-professional-education.pantheonsite.io";
$conf['stage_file_proxy_hotlink'] = "1";

// Shopping cart checkout url
#$conf['cpe_cart_checkout_url'] = 'https://utdirect.utexas.edu/nlogon/cee/uex/reg1.WBX';
$conf['cpe_cart_cookie_domain'] = 'cpe.local';

$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'cpe',
  'username' => 'root',
  'password' => 'root',
  'host' => '127.0.0.1',
  'port' => '8889',
  'collation' => 'utf8_general_ci',
);
