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

/* uint8_t get_key(String s){
  switch (s){
    case "ESCAPE": case "ESC": return KEY_LEFT_ESC; break;
    case "SPACE": return ' '; break;
    case "TAB": return KEY_TAB; break;
    case "GUI": case "WINDOWS": case "COMMAND": return KEY_LEFT_GUI; break;
    case "MENU": case "APP": return 229; break;
    case "ENTER": case "RETURN": return KEY_RETURN; break;
    case "UP": case "UPARROW": return KEY_UP_ARROW; break;
    case "DOWN": case "DOWNARROW": return KEY_DOWN_ARROW; break;
    case "LEFT": case "LEFTARROW": return KEY_LEFT_ARROW; break;
    case "RIGHT": case "RIGHTARROW": return KEY_RIGHT_ARROW; break;
    case "CAPSLOCK": return KEY_CAPS_LOCK; break;
    case "DELETE": case "DEL": return KEY_DELETE; break;
    case "PAGEUP": return KEY_PAGE_UP; break;
    case "PAGEDOWN": return KEY_PAGE_DOWN; break;
    case "PRINTSCREEN": return 206; break;
    case "END": return KEY_END; break;
    case "ALT": case "LALT": return KEY_LEFT_ALT; break;
    case "RALT": return KEY_RIGHT_ALT; break;
    case "SHIFT": case "LSHIFT": return KEY_LEFT_SHIFT; break;
    case "RSHIFT": return KEY_RIGHT_SHIFT; break;
    case "CTRL": case "LCTRL": case "CONTROL": return KEY_LEFT_CTRL; break;
    case "RCTRL": return KEY_RIGHT_CTRL; break;
    case "F1": return KEY_F1; break;
    case "F2": return KEY_F2; break;
    case "F3": return KEY_F3; break;
    case "F4": return KEY_F4; break;
    case "F5": return KEY_F5; break;
    case "F6": return KEY_F6; break;
    case "F7": return KEY_F7; break;
    case "F8": return KEY_F8; break;
    case "F9": return KEY_F9; break;
    case "F10": return KEY_F10; break;
    case "F11": return KEY_F11; break;
    case "F12": return KEY_F12; break;
    default: return s.charAt(0);
  }
}

bool is_key(String s){
  if (s.length() == 1) return true;
  switch (s){
    case "ESCAPE":
    case "ESC":
    case "SPACE":
    case "TAB":
    case "GUI":
    case "WINDOWS":
    case "COMMAND":
    case "MENU":
    case "APP":
    case "ENTER":
    case "RETURN":
    case "UP":
    case "UPARROW":
    case "DOWN":
    case "DOWNARROW":
    case "LEFT":
    case "LEFTARROW":
    case "RIGHT":
    case "RIGHTARROW":
    case "CAPSLOCK":
    case "DELETE":
    case "DEL":
    case "PAGEUP":
    case "PAGEDOWN":
    case "PRINTSCREEN":
    case "END":
    case "ALT":
    case "LALT":
    case "RALT":
    case "SHIFT":
    case "LSHIFT":
    case "RSHIFT":
    case "CTRL":
    case "LCTRL":
    case "RCTRL":
    case "CONTROL":
    case "F1":
    case "F2":
    case "F3":
    case "F4":
    case "F5":
    case "F6":
    case "F7":
    case "F8":
    case "F9":
    case "F10":
    case "F11":
    case "F12":
      return true; break;
    default:
      return false; break;
  }
} */
