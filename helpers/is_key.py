keys = {'ESCAPE': 'KEY_ESC', 'ESC': 'KEY_LEFT_ESC', 'SPACE': '\' \'', 'TAB': 'KEY_TAB', 'GUI': 'KEY_LEFT_GUI', 'WINDOWS': 'KEY_LEFT_GUI', 'COMMAND': 'KEY_LEFT_GUI', 'MENU': '229', 'APP': '229', 'ENTER': 'KEY_RETURN', 'RETURN': 'KEY_RETURN', 'UP': 'KEY_UP_ARROW', 'UPARROW': 'KEY_UP_ARROW', 'DOWN': 'KEY_DOWN_ARROW', 'DOWNARROW': 'KEY_DOWN_ARROW', 'LEFT': 'KEY_LEFT_ARROW', 'LEFTARROW': 'KEY_LEFT_ARROW', 'RIGHT': 'KEY_RIGHT_ARROW', 'RIGHTARROW': 'KEY_RIGHT_ARROW', 'CAPSLOCK': 'KEY_CAPS_LOCK', 'DELETE': 'KEY_DELETE', 'DEL': 'KEY_DELETE', 'PAGEUP': 'KEY_PAGE_UP', 'PAGEDOWN': 'KEY_PAGE_DOWN', 'PRINTSCREEN': '206', 'END': 'KEY_END', 'ALT': 'KEY_LEFT_ALT', 'LALT': 'KEY_LEFT_ALT', 'RALT': 'KEY_RIGHT_ALT', 'SHIFT': 'KEY_LEFT_SHIFT', 'LSHIFT': 'KEY_LEFT_SHIFT', 'RSHIFT': 'KEY_RIGHT_SHIFT', 'CTRL': 'KEY_LEFT_CTRL', 'LCTRL': 'KEY_LEFT_CTRL', 'RCTRL': 'KEY_RIGHT_CTRL', 'CONTROL': 'KEY_LEFT_CTRL', 'F1': 'KEY_F1', 'F2': 'KEY_F2', 'F3': 'KEY_F3', 'F4': 'KEY_F4', 'F5': 'KEY_F5', 'F6': 'KEY_F6', 'F7': 'KEY_F7', 'F8': 'KEY_F8', 'F9': 'KEY_F9', 'F10': 'KEY_F10', 'F11': 'KEY_F11', 'F12': 'KEY_F12'}

'''result = 'bool is_key(String s){\n'
result += '  if (s.length() == 1) return true;\n';
result += '  switch (s){\n'
for key, val in keys.items():
	result += '    case "' + key + '":\n'
result += '      return true; break;\n'
result += '    default:\n';
result += '      return false; break;\n';
result += '  }\n'
result += '}'
print(result)'''

result = 'bool is_key(String s){\n'
cases = ['s == "' + key + '"' for key,val in keys.items()]
cases.append('s.length() == 1')
result += '  return ' + ' || '.join(cases) + ';\n';
result += '}'
print(result)