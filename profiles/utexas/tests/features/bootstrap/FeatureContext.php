<?php
/**
 * @file
 * Feature Context.
 */

use Drupal\DrupalExtension\Context\RawDrupalContext;
use Drupal\DrupalExtension\Context\DrupalContext;
use Behat\Behat\Context\SnippetAcceptingContext;
use Behat\Gherkin\Node\PyStringNode;
use Behat\Gherkin\Node\TableNode;
use Behat\Behat\Tester\Exception\PendingException;

/**
 * Defines application features from the specific context.
 */
class FeatureContext extends RawDrupalContext implements SnippetAcceptingContext {

  /**
   * Initializes context.
   *
   * Every scenario gets its own context instance.
   * You can also pass arbitrary arguments to the
   * context constructor through behat.yml.
   */
  public function __construct() {
  }

  /**
   * Check logged in status.
   *
   * Overrides RawDrupalContext::loggedIn().
   * @see https://github.com/jhedstrom/drupalextension/pull/131
   */
  public function loggedIn() {
    $session = $this->getSession();
    $page = $session->getPage();
    // Look for the logged-in class on the body tag. This should work with
    // almost any theme.
    $body = $page->find('css', 'body');
    if ($body->hasClass('logged-in')) {
      return TRUE;
    }
    // Some themes do not add that class to the body, so lets check if the
    // login form is displayed on /user/login.
    $session->visit($this->locatePath('/user/login'));
    if (!$page->has('css', 'form#user-login')) {
      return TRUE;
    }
    $session->visit($this->locatePath('/'));
    // As a last resort, if a logout link is found, we are logged in. While not
    // perfect, this is how Drupal SimpleTests currently work as well.
    $element = $session->getPage();
    return $element->findLink($this->getDrupalText('log_out'));
  }

  /**
   * RawDrupalContext::assertAnonymousUser() with better logged in check.
   *
   * @Given I am an anonymous user on this site
   * @Given I am not logged in on this site
   */
  public function assertAnonymousUserOnThisSite() {
    // Verify the user is logged out.
    if ($this->loggedIn()) {
      $this->logout();
    }
  }


  /**
   * Create user with list of permissions & log in.
   *
   * @Given I am logged in as a user with the :permissions permission(s) on this site
   */
  public function assertLoggedInWithPermissionsOnThisSite($permissions) {
    // Create user.
    $user = (object) array(
      'name' => $this->getRandom()->name(8),
      'pass' => $this->getRandom()->name(16),
    );
    $user->mail = "{$user->name}@example.com";
    $this->userCreate($user);
    // Create and assign a temporary role with given permissions.
    $permissions = explode(',', $permissions);
    $rid = $this->getDriver()->roleCreate($permissions);
    $this->getDriver()->userAddRole($user, $rid);
    $this->roles[] = $rid;
    // Login.
    $this->login();
  }

  /**
   * Creates and authenticates a user with the given role(s).
   *
   * RawDrupalContext::assertAuthenticatedByRole() with better logged in check.
   *
   * @Given I am logged in as a user with the :role role(s) on this site
   */
  public function assertAuthenticatedByRoleOnThisSite($role) {
    // Check if a user with this role is already logged in.
    if (!$this->loggedInWithRole($role)) {
      // Create user (and project)
      $user = (object) array(
        'name' => $this->getRandom()->name(8),
        'pass' => $this->getRandom()->name(16),
        'role' => $role,
      );
      $user->mail = "{$user->name}@example.com";

      $this->userCreate($user);

      $roles = explode(',', $role);
      $roles = array_map('trim', $roles);
      foreach ($roles as $role) {
        if (!in_array(strtolower($role), array('authenticated', 'authenticated user'))) {
          // Only add roles other than 'authenticated user'.
          $this->getDriver()->userAddRole($user, $role);
        }
      }

      // Login.
      $this->login();
    }
  }

  /**
   * @When I add the credential :arg1 for :arg2
   */
  public function iAddTheCredentialFor($credential_name, $region) {
    $file_name = DRUPAL_ROOT . '/profiles/utexas/tests/credentials.php';
    if (file_exists($file_name)) {
      include $file_name;
    }
    else {
      throw new \Exception(sprintf("The file '%s' was not found in the filesystem", $file_name));
    }
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    // Verify presence of CSS element
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $region));
    }
    // Set the credential field to the user-provided values.
    $element->setValue($credentials[$credential_name]);
  }

  /**
   * @When /^(?:|I )click on the element "([^"]*)"$/
   *
   * Click on the element with the provided xpath query.
   */
  public function iClickOnTheElement($locator) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $locator);

    // Errors must not pass silently.
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $locator));
    }

    $element->click();
  }

  /**
   * @When I click on the element :arg1 in the :arg2 region
   */
  public function iClickOnTheElementInTheRegion($element, $region) {
    $session = $this->getSession();

    $found_region = $session->getPage()->find('css', $region);
    // Errors must not pass silently.
    if (NULL === $found_region) {
      throw new \InvalidArgumentException(sprintf('Could not find region: "%s"', $region));
    }
    $found_element = $found_region->find('css', $element);
    // Errors must not pass silently.
    if (NULL === $found_element) {
      throw new \InvalidArgumentException(sprintf('Could not find link: "%s"', $element));
    }

    $found_element->click();
  }

  /**
   * @When I click on the link :arg1 in the :arg2 region
   */
  public function iClickOnTheLinkInTheRegion($link, $region) {
    $session = $this->getSession();

    $found_region = $session->getPage()->find('css', $region);
    // Errors must not pass silently.
    if (NULL === $found_region) {
      throw new \InvalidArgumentException(sprintf('Could not find region: "%s"', $region));
    }
    $found_link = $found_region->findlink($link);
    // Errors must not pass silently.
    if (NULL === $found_link) {
      throw new \InvalidArgumentException(sprintf('Could not find link: "%s"', $link));
    }

    $found_link->click();
  }

  /**
   * @When I click on the element :arg1 in the :arg2 region containing the text :arg3
   */
  public function iClickOnTheElementintheRegionContainingTheText($element, $region, $text) {
    $session = $this->getSession();
    $found_region = $session->getPage()->find('css', $region);
    // Errors must not pass silently.
    if (NULL === $found_region) {
      throw new \InvalidArgumentException(sprintf('Could not find element: "%s"', $element));
    }

    $found_elements = $found_region->findAll('css', $element);
    // Errors must not pass silently.
    if (NULL === $found_elements) {
      throw new \InvalidArgumentException(sprintf('Could not find element: "%s"', $element));
    }
    $found = FALSE;
    foreach($found_elements as $element) {
      $pos = strpos($element->getText(), $text);
      if ($pos === FALSE) {
      }
      else {
        $found = TRUE;
        $element->click();
      }
    }
    // Errors must not pass silently.
    if (!$found) {
      throw new \InvalidArgumentException(sprintf('Could not find link with text: "%s"', $text));
    }


  }

  /**
   * @When /^I switch to the iframe "([^"]*)"$/
   */
  public function iSwitchToTheIframe($name) {
    if ($name) {
      $this->getSession()->switchToIFrame($name);
    }
    else {
      $this->getSession()->switchToIFrame();
    }
  }

  /**
   * Sets an iFrame ID if there is no ID. You can then add a Switch to iFrame step after it using the na_name_iframe ID.
   *
   * @When I the set the iframe located in element with an id of :arg1 to :arg2
   */
  public function iSetTheIframeLocatedInElementWithAnIdOfTo($element_id,$name) {

    $check = 1; //@todo need to check using js if exists
    if($check <= 0) {
      throw new \Exception('Element not found');
    }
    else {
      $javascript = <<<JS
            (function(){
              var elem = document.getElementById('$element_id');
              var iframes = elem.getElementsByTagName('iframe');
              var f = iframes[0];
              f.id = '$name';
            })()
JS;
      $this->getSession()->executeScript($javascript);
    }
  }


  /**
   * @Then I should see the css selector :arg1 with the attribute :arg2 with the exact value :arg3
   */
  public function iShouldSeeTheCssSelectorWithTheAttributeWithTheExactValue($region, $attribute, $value) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not find CSS selector: "%s"', $region));
    }
    $attr = $element->getAttribute($attribute);
    if (NULL === $attr) {
      throw new \InvalidArgumentException(sprintf('Could not find attribute: "%s"', $attribute));
    }
    if ($attr !== $value) {
      throw new \Exception(sprintf("The value %s was not found in the attribute '%s' in the element %s. Instead, it found %s", $value, $attribute, $region, $attr));
    }
  }

  /**
   * @Then I should see the css element :arg1 with the attribute :arg2 with the value containing :arg3
   */
  public function iShouldSeeTheCssElementWithTheAttributeWithTheValueContaining($region, $attribute, $value) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not find CSS selector: "%s"', $region));
    }
    $attr = $element->getAttribute($attribute);
    if (NULL === $attr) {
      throw new \InvalidArgumentException(sprintf('Could not find attribute: "%s"', $attribute));
    }
    if (strpos($attr, $value) === FALSE) {
      throw new \Exception(sprintf("The value %s was not found in the attribute '%s' in the element %s. Instead, it found %s", $value, $attribute, $region, $attr));
    }
  }

  /**
   * @Then I should see the :arg1 css selector with pseudo element :arg2 with css property :arg3 containing :arg4
   */
  public function iShouldSeeTheCssSelectorWithPseudoElementWithCssPropertyContaining($element, $pseudo_element, $property, $value) {
    $session = $this->getSession();
    $returned_element = $session->getPage()->find('css', $element);
    if (NULL === $returned_element) {
      throw new \InvalidArgumentException(sprintf('Could not find CSS selector: "%s"', $element));
    }
    $returned_value = $this->getSession()->evaluateScript("window.getComputedStyle(document.querySelector('" . $element . "'), '" . $pseudo_element . "').getPropertyValue('" . $property . "')");
    if (NULL === $returned_value) {
      throw new \InvalidArgumentException(sprintf('Found "%s", but could not find CSS property: "%s"', $element, $property));
    }
    if (strpos($returned_value, $value) === FALSE) {
      throw new \Exception(sprintf("The value '%s' was not found in the property '%s' in the element '%s%s'. Instead, it found %s", $value, $property, $element, $pseudo_element, $returned_value));
    }
  }

  /**
  *
  *
   * @Then I should see the :arg1 css selector with css property :arg2 containing :arg3
   */
  public function iShouldSeeTheCssSelectorWithCssPropertyContaining($element, $property, $value) {
    $session = $this->getSession();
    $returned_element = $session->getPage()->find('css', $element);
    if (NULL === $returned_element) {
      throw new \InvalidArgumentException(sprintf('Could not find CSS selector: "%s"', $element));
    }
    $returned_value = $this->getSession()->evaluateScript("window.getComputedStyle(document.querySelector('" . $element . "')).getPropertyValue('" . $property . "')");
    if (NULL === $returned_value) {
      throw new \InvalidArgumentException(sprintf('Found "%s", but could not find CSS property: "%s"', $element, $property));
    }
    if (strpos($returned_value, $value) === FALSE) {
      throw new \Exception(sprintf("The value '%s' was not found in the property '%s' in the element '%s'. Instead, it found %s", $value, $property, $element, $returned_value));
    }
  }

  /**
   * Verify presence of an image path in a CSS element.
   *
   * @Then I should see the image path :arg1 in the css element :arg2
   */
  public function iShouldSeeTheImagePathInTheCssElement($filename, $region) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $region));
    }
    // Get image source.
    $src = $element->getAttribute('src');
    if (strpos($src, $filename) === FALSE) {
      throw new \Exception(sprintf("The image '%s' was not found in the region '%s' on the page %s", $filename, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * Verify presence of CSS element.
   *
   * @Then I should see the css element :arg1
   */
  public function iShouldSeeTheCssElement($region) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    // Verify presence of CSS element
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $region));
    }
  }

  /**
   * Fills in WYSIWYG editor with specified id.
   *
   * @When /^(?:|I )fill in "(?P<text>[^"]*)" in WYSIWYG editor "(?P<iframe>[^"]*)"$/
   */
  public function iFillInInWYSIWYGEditor($text, $iframe) {
    try {
      $this->getSession()->switchToIFrame($iframe);
    }
    catch (Exception $e) {
      throw new \Exception(sprintf("No iframe with id '%s' found on the page '%s'.", $iframe, $this->getSession()->getCurrentUrl()));
    }
    $this->getSession()->executeScript("document.body.innerHTML = '<p>".$text."</p>'");
    $this->getSession()->switchToIFrame();
  }

  /**
   * Verify absence of CSS element.
   *
   * @Then I should not see the css element :arg1
   */
  public function iShouldNotSeeTheCssElement($region) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    // Verify absence of CSS element.
    if (NULL !== $element) {
      throw new \InvalidArgumentException(sprintf('CSS selector "%s" was found, though it is not supposed to be present', $region));
    }
  }

  /**
   * @Then I should see HTML :arg1 in the :arg2 region
   */
  public function iShouldSeeHTMLInTheRegion($html, $region) {
    $session = $this->getSession();
    $found_region = $session->getPage()->find('css', $region);
    // Errors must not pass silently.
    if (NULL === $found_region) {
      throw new \InvalidArgumentException(sprintf('Could not find region: "%s"', $region));
    }
    $cleaned_html = str_replace('\\', '', $html);
    $found_html = $found_region->getHtml();
    $pos = strpos($found_html, $cleaned_html);
    if ($pos === FALSE) {
      throw new \InvalidArgumentException(sprintf('Could not find HTML: "%s"', $cleaned_html));
    }
  }

  /**
   * @Then I should not see HTML :arg1 in the :arg2 region
   */
  public function iShouldNotSeeHTMLInTheRegion($html, $region) {
    $session = $this->getSession();
    $found_region = $session->getPage()->find('css', $region);
    // Errors must not pass silently.
    if (NULL === $found_region) {
      throw new \InvalidArgumentException(sprintf('Could not find region: "%s"', $region));
    }
    $cleaned_html = str_replace('\\', '', $html);
    $found_html = $found_region->getHtml();
    $pos = strpos($found_html, $cleaned_html);
    if ($pos !== FALSE) {
      throw new \InvalidArgumentException(sprintf('Found HTML: "%s"', $cleaned_html));
    }
  }

  /**
   * @Then I should see today's AP style date in the css element :arg1
   */
  public function iShouldSeeTodaySApStyleDateInTheCssElement($region) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $region);
    // Use the existing ap style format to get expected output.
    $date = utexas_admin_ap_style_date(time());
    if (NULL === $element) {
      throw new \InvalidArgumentException(sprintf('Could not evaluate CSS selector: "%s"', $region));
    }
    if (strpos($element->getText(), $date) === FALSE) {
      throw new \Exception(sprintf("The text '%s' was not found in the region '%s' on the page %s", $date, $region, $this->getSession()->getCurrentUrl()));
    }
  }

  /**
   * @Then I wait for css element :element to :appear
   */
  public function iWaitForCssElement($element, $appear) {
    $xpath = $this->getSession()->getSelectorsHandler()->selectorToXpath('css', $element);
    $this->waitForXpathNode($xpath, $appear == 'appear');
  }

  /**
   * @When I set browser window size to :arg1 x :arg2
   */
  public function iSetBrowserWindowSizeToX2($width, $height) {
    $this->getSession()->resizeWindow((int) $width, (int) $height, 'current');
  }

  /**
   * @When I take a screenshot for regression testing of page :arg1
   */
  public function iTakeaScreenshotForRegressionTestingOfPage($page) {
    if ($this->getSession()->getDriver() instanceof \Behat\Mink\Driver\Selenium2Driver) {
      $file_name = DRUPAL_ROOT . '/profiles/utexas/tests/regressions/behat-regression-' . $page . '-' . time() . '.png';
      $screenshot = $this->getSession()->getDriver()->getScreenshot();
      file_put_contents($file_name, $screenshot);
      print "Screenshot for regression testing created at $file_name";
    }
  }

  /**
   * @When I wait for :arg1 seconds
   */
  public function iWaitForSeconds($seconds) {
    $this->getSession()->wait($seconds*1000);
  }

  /**
   * Helper function; Execute a function until it return TRUE or timeouts.
   *
   * @param $fn
   *   A callable to invoke.
   * @param int $timeout
   *   The timeout period. Defaults to 10 seconds.
   *
   * @throws Exception
   */
  private function waitFor($fn, $timeout = 10000) {
    $start = microtime(TRUE);
    $end = $start + $timeout / 1000.0;
    while (microtime(TRUE) < $end) {
      if ($fn($this)) {
        return;
      }
    }
    throw new \Exception('waitFor timed out.');
  }

  /**
   * Wait for an element by its XPath to appear or disappear.
   *
   * @param string $xpath
   *   The XPath string.
   * @param bool $appear
   *   Determine if element should appear. Defaults to TRUE.
   *
   * @throws Exception
   *   Failed.
   */
  private function waitForXpathNode($xpath, $appear = TRUE) {
    $this->waitFor(function($context) use ($xpath, $appear) {
      try {
        $nodes = $context->getSession()->getDriver()->find($xpath);
        if (count($nodes) > 0) {
          $visible = $nodes[0]->isVisible();
          return $appear ? $visible : !$visible;
        }
        return !$appear;
      }
      catch (WebDriver\Exception $e) {
        if ($e->getCode() == WebDriver\Exception::NO_SUCH_ELEMENT) {
          return !$appear;
        }
        throw $e;
      }
    });
  }

  /**
   * @AfterStep
   *
   * Take a screen shot after failed steps for Selenium drivers.
   */
  public function takeScreenshotAfterFailedStep($event) {
    if ($event->getTestResult()->isPassed()) {
      // Not a failed step.
      return;
    }
    if ($this->getSession()->getDriver() instanceof \Behat\Mink\Driver\Selenium2Driver) {
      $file_name = DRUPAL_ROOT . '/profiles/utexas/tests/failures/behat-failed-step-' . time() . '.png';
      $screenshot = $this->getSession()->getDriver()->getScreenshot();
      file_put_contents($file_name, $screenshot);
      print "Screenshot for failed step created in $file_name";
    }
  }

}
