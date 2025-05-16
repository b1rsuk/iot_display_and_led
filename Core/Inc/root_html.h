/*
 * led_display_html.h
 *
 *  Created on: 15 мая 2025 г.
 *      Author: borsuk
 */

#ifndef INC_ROOT_HTML_H_
#define INC_ROOT_HTML_H_

#define LED_CONTROLLER_HTML \
"<!DOCTYPE html><html>" \
"<head><title>LED Control</title></head>" \
"<body>" \
"<h1>LED Control Panel</h1>" \
"<button onclick=\"sendCommand('/led1_on')\">LED 1 ON</button>" \
"<button onclick=\"sendCommand('/led1_off')\">LED 1 OFF</button><br><br>"\
"<button onclick=\"sendCommand('/led2_on')\">LED 2 ON</button>" \
"<button onclick=\"sendCommand('/led2_off')\">LED 2 OFF</button><br><br>" \
"<button onclick=\"sendCommand('/led3_on')\">LED 3 ON</button>" \
"<button onclick=\"sendCommand('/led3_off')\">LED 3 OFF</button><br><br>" \
"<button onclick=\"sendCommand('/led4_on')\">LED 4 ON</button>" \
"<button onclick=\"sendCommand('/led4_off')\">LED 4 OFF</button><br><br>" \
"<hr>" \
"<input type=\"text\" id=\"msgInput\" placeholder=\"Enter text\">" \
"<button onclick=\"sendText()\">Send</button>" \
"<script>" \
"function sendCommand(path) {" \
"  fetch(path, { method: 'POST' });" \
"}" \
"function sendText() {" \
"  const msg = document.getElementById('msgInput').value;" \
"  fetch('/send_text?msg=' + encodeURIComponent(msg));" \
"}" \
"</script>" \
"</body></html>"

#endif /* INC_ROOT_HTML_H_ */
