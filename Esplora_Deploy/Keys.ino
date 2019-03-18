uint8_t get_key(String s){
  if (s == "ESCAPE" || s == "ESC") return KEY_ESC;
  else if (s == "SPACE") return ' ';
  else if (s == "TAB") return KEY_TAB;
  else if (s == "GUI" || s == "WINDOWS" || s == "COMMAND") return KEY_LEFT_GUI;
  else if (s == "MENU" || s == "APP") return 229;
  else if (s == "ENTER" || s == "RETURN") return KEY_RETURN;
  else if (s == "UP" || s == "UPARROW") return KEY_UP_ARROW;
  else if (s == "DOWN" || s == "DOWNARROW") return KEY_DOWN_ARROW;
  else if (s == "LEFT" || s == "LEFTARROW") return KEY_LEFT_ARROW;
  else if (s == "RIGHT" || s == "RIGHTARROW") return KEY_RIGHT_ARROW;
  else if (s == "CAPSLOCK") return KEY_CAPS_LOCK;
  else if (s == "DELETE" || s == "DEL") return KEY_DELETE;
  else if (s == "PAGEUP") return KEY_PAGE_UP;
  else if (s == "PAGEDOWN") return KEY_PAGE_DOWN;
  else if (s == "PRINTSCREEN") return 206;
  else if (s == "END") return KEY_END;
  else if (s == "ALT" || s == "LALT") return KEY_LEFT_ALT;
  else if (s == "RALT") return KEY_RIGHT_ALT;
  else if (s == "SHIFT" || s == "LSHIFT") return KEY_LEFT_SHIFT;
  else if (s == "RSHIFT") return KEY_RIGHT_SHIFT;
  else if (s == "CTRL" || s == "LCTRL" || s == "CONTROL") return KEY_LEFT_CTRL;
  else if (s == "RCTRL") return KEY_RIGHT_CTRL;
  else if (s == "F1") return KEY_F1;
  else if (s == "F2") return KEY_F2;
  else if (s == "F3") return KEY_F3;
  else if (s == "F4") return KEY_F4;
  else if (s == "F5") return KEY_F5;
  else if (s == "F6") return KEY_F6;
  else if (s == "F7") return KEY_F7;
  else if (s == "F8") return KEY_F8;
  else if (s == "F9") return KEY_F9;
  else if (s == "F10") return KEY_F10;
  else if (s == "F11") return KEY_F11;
  else if (s == "F12") return KEY_F12;
  else return s.charAt(0);
}

bool is_key(String s){
  return s == "ESCAPE" || s == "ESC" || s == "SPACE" || s == "TAB" || s == "GUI" || s == "WINDOWS" || s == "COMMAND" || s == "MENU" || s == "APP" || s == "ENTER" || s == "RETURN" || s == "UP" || s == "UPARROW" || s == "DOWN" || s == "DOWNARROW" || s == "LEFT" || s == "LEFTARROW" || s == "RIGHT" || s == "RIGHTARROW" || s == "CAPSLOCK" || s == "DELETE" || s == "DEL" || s == "PAGEUP" || s == "PAGEDOWN" || s == "PRINTSCREEN" || s == "END" || s == "ALT" || s == "LALT" || s == "RALT" || s == "SHIFT" || s == "LSHIFT" || s == "RSHIFT" || s == "CTRL" || s == "LCTRL" || s == "RCTRL" || s == "CONTROL" || s == "F1" || s == "F2" || s == "F3" || s == "F4" || s == "F5" || s == "F6" || s == "F7" || s == "F8" || s == "F9" || s == "F10" || s == "F11" || s == "F12" || s.length() == 1;
}
