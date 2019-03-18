int default_delay = 0;

void run_script(String fpath){
  File f = SD.open("/payloads/" + (String)os + "/" + fpath);
  // Loop through each line and execute the script
  Keyboard.begin();
  String line = "";
  short i = 0;
  while (f.available()){
    char c = f.read();
    if (c == '\n'){ // End of line, time to execute
      if (i == 0 && (line.startsWith("DEFAULTDELAY ") || line.startsWith("DEFAULT_DELAY "))){
        default_delay = line.startsWith("DEFAULTDELAY ") ? line.substring(13).toInt() : line.substring(14).toInt();
      } else {
        run_line(line);
      }
      line = "";
      i++;
    } else {
      line += f.read();
    }
  }
  f.close();
  Keyboard.end();
}

String prevLine = "";

void run_line(String line){
  short space = line.indexOf(' ');
  String first_word = (space > -1) ? line.substring(0,space) : line;
  String remainder = (space > -1) ? line.substring(space + 1) : "";
  if (first_word == "REM") { // Comment
    return;
  } else if (first_word == "STRING"){ // Type string
    Keyboard.print(remainder);
  } else if (first_word == "DELAY"){ // Delay
    delay(remainder.toInt());
  } else if (first_word == "REPEAT"){ // Repeat
    for (short i = 0; i < remainder.toInt(); i++){
      run_line(prevLine); // Recursively run previous line
    }
  } else if (is_key(line)){ // Single keypress
    Keyboard.write(get_key(line));
  } else if (is_key(first_word)){ // Multiple keypresses
    // Loop through each key listed
    short from = 0;
    short next = line.indexOf(' ', from);
    while (next > -1){ // Loop through while there are still more words
      next = line.indexOf(' ', from);
      String key = line.substring(from, next);
      Keyboard.press(get_key(key));
      from = next + 1;
    }
    // Do the last word
    Keyboard.press(get_key(line.substring(from)));
    Keyboard.releaseAll();
  }
  
  if (!line.startsWith("DELAY ")){ // Default delay if not manually defined
    delay(default_delay);
  }
  prevLine = line;
}
