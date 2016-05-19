<?php

include_once '../utexas_qualtrics_filter.module';

$tests = array(
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ[/embed]' => 'none',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello[/embed]'  => 'title',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello [/embed]'  => 'title',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | height:10[/embed]'  => 'height',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | height:10 [/embed]' => 'height',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello | height:10[/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello | height:10 [/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello |height:10 [/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ | title:hello|height:10 [/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ |title:hello|height:10[/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ |title: hello|height:10[/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ |height:10|title:hello[/embed]'  => 'both',
  '[embed]https://utexas.qualtrics.com/SE/?SID=SV_af1Gk9JWK2khAEJ |height:10|malicious:hello[/embed]'  => 'malicious',
);

echo '<table border="1">';
foreach ($tests as $data => $type) {
  $score = 'FAIL';
  $result = _qualtrics_filter_process($data, NULL);
  $title = strpos($result, 'title="hello"');
  $height = strpos($result, 'height="10"');
  $malicious = strpos($result, 'malicious');

  if ($type == 'none') {
    if ($title === FALSE && $height === FALSE) {
      $score = 'PASS';
    }
  }
  if ($type == 'title') {
    if ($title !== FALSE && $height === FALSE) {
      $score = 'PASS';
    }
  }
  if ($type == 'height') {
     if ($title === FALSE && $height !== FALSE) {
      $score = 'PASS';
    }
  }
  if ($type == 'both') {
    if ($title !== FALSE && $height !== FALSE) {
      $score = 'PASS';
    }
  }
  if ($type == 'malicious') {
    if ($malicious === FALSE) {
      $score = 'PASS';
    }
  }

  echo '<tr><td>' . $data . '</td>';
  echo '<td>' . htmlentities($result) . '</td>';
  echo '<td>' . $score . '</td></tr>';
}
echo '</table>';
