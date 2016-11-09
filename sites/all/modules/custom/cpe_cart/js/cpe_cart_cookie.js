
var mycookie = document.cookie;

function getCookie(name) {
  var index = mycookie.indexOf(name + '=');
  if (index == -1)
  return null;
  index = mycookie.indexOf("=", index) + 1;
  var endstr = mycookie.indexOf(';', index);
  if (endstr == -1)
  endstr = mycookie.length;
  return unescape(mycookie.substring(index, endstr));
}

function setCookie(name, value) {
  if (value == '') {
    document.cookie=name + "=; path=/; domain=" + Drupal.settings.cpe_cart.cpeCartCookieDomain;
  } else {
    var oldvalue = getCookie(name);
    if (oldvalue != null) {
      var index = oldvalue.indexOf(value);
    } else {
      var index = -1;
    }

    if (index == -1) {
      if (value != null && value != "") {
        if (oldvalue != null) {
          document.cookie=name + "=" + oldvalue + escape(value) + "; path=/ ; domain=" + Drupal.settings.cpe_cart.cpeCartCookieDomain;
        } else {
          document.cookie=name + "=" + escape(value) + "; path=/ ; domain=" + Drupal.settings.cpe_cart.cpeCartCookieDomain;
        }
        mycookie = document.cookie;
      }
      mycookie = document.cookie;
      this.document.cartform.submit();
    } else {
      alert("Cart contains this course already!");
    }
  }
}
