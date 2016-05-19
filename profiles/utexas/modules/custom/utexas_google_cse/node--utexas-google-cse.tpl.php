<?php
/**
 * @file
 * Default theme implementation to display google cse search results.
 *
 * @see template_preprocess()
 *
 * @ingroup themeable
 */

global $base_root;

?>
<div class="UT-page page-cse" id="ut-page-content" role="main">
  <div class="not-found search">
    <?php   $placeholder = get_current_search_terms(); ?>
    <div class="div-google-results">
      <label for="search-desktop" class="hiddenText">Search UT Austin</label>
      <form action = "/search-results" method = "get" id = "cse_searchbox">
        <input type = "text" name="query" id = "search-desktop" placeholder = <?php print $placeholder; ?> class="search-page-input" title="Search the University of Texas site" aria-labelledby="desktopSearchLabel">
        <button class = "nav-search-button"><span class = "hiddenText">Search</span><span class="icon-search"></span></button>
      </form>
      <?php $google_logo = $base_root . '/profiles/utexas/themes/forty_acres/src/img/general/google-logo.png';?>
      <p class="custom-search">
        <?php print '<img src="' . $google_logo . '">'; ?>
      Custom Search</p>
    </div>
  </div>
</div>
<gcse:searchresults-only resultsUrl = "/search-results"  queryParameterName="query"></gcse:searchresults-only>
