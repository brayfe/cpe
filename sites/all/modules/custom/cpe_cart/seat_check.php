<?php

/**
 * @file
 * Wrapper script for querying MISHELL.
 *
 * This is a "wrapper" script for querying MISHELL on UT Direct
 * to check for seat availability on course sections in the Center
 * for Professional Education. The only reason it has to be done
 * this way is to avoid a CORS violation when making an AJAX request
 * to check seat availability.
 */

if (preg_match('/^[a-zA-Z0-9_]+$/', $_GET['s_pgm_id'])) {
  $s_pgm_id = $_GET['s_pgm_id'];
}
else {
  print 'INVALID INPUT';
  exit();
}

$ch = curl_init();
curl_setopt($ch, CURLOPT_URL, "https://utdirect.utexas.edu/nlogon/cee/seats_remaining.WBX?s_pgm_id=$_pgm_id");
curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
$output = curl_exec($ch);
curl_close($ch);

print $output;

exit();
