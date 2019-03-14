short line_height = 22; // Font size is 20, plus line spacing

short prevOS = 0;
short os = 0; // 0 = Linux, 1 = Mac, 2 = Windows
char oses[3][10] = {"Linux", "Mac", "Windows"};

bool os_chosen = false;

void menu_init() {
  os_chosen = false;
  EsploraTFT.background(0,0,0);
  EsploraTFT.stroke(255,255,255);
  EsploraTFT.text("BadArduino", 0, 0);
  
  for (short i = 0; i < 3; i++){
    short y = (line_height * i) + (line_height * 2 + 5);
    if (os == i){ // This is the selected OS, so highlight the text
      EsploraTFT.fill(255,255,255);
      EsploraTFT.rect(0,y-4,width,line_height+2);
      EsploraTFT.stroke(0,0,0);
    } else {
      EsploraTFT.stroke(255,255,255);
    }
    EsploraTFT.text(oses[i], 2, y);
  }
}

void menu_loop() {
  if (os_chosen){
    payload_loop(false);
    return;
  }

  // Detect whether to switch mode
  if (Esplora.readButton(JOYSTICK_DOWN) == LOW) os++;
  else if (Esplora.readButton(JOYSTICK_UP) == LOW) os--;
  if (os >= 3) os = 0;
  if (os <= -1) os = 2;

  // Draw menu if it has changed
  if (os != prevOS){
    // Clear previous OS
    short y = (line_height * prevOS) + (line_height * 2 + 5);
    EsploraTFT.fill(0,0,0);
    EsploraTFT.rect(0,y-4,width,line_height+2);
    EsploraTFT.stroke(255,255,255);
    EsploraTFT.text(oses[prevOS], 2, y);
    prevOS = os;
    // Highlight new OS
    y = (line_height * os) + (line_height * 2 + 5);
    EsploraTFT.fill(255,255,255);
    EsploraTFT.rect(0,y-4,width,line_height+2);
    EsploraTFT.stroke(0,0,0);
    EsploraTFT.text(oses[os], 2, y);
    delay(250);
  }

  // Check whether to initiate injection
  if(Esplora.readButton(SWITCH_RIGHT) == LOW){
    os_chosen = true;
    payload_init();
  }
}

short num_files = 64;
String payloads[64];
short payload = 0;
short prevPayload = num_files;

void payload_init(){
  // Clear any old payloads
  payload = 0;
  for (short i = 0; i < num_files; i++) payloads[i] = "";
  // Get list of payloads
  File dir = SD.open("/payloads/" + (String)oses[os]);
  short i = 0;
  while (true){
    File f = dir.openNextFile();
    if (!f) break;
    payloads[i] = f.name();
    Serial.println(payloads[i]);
    i++;
  }
  EsploraTFT.background(0,0,0);
  payload_loop(true);
}

void payload_loop(bool redraw){
  // Go back
  if (Esplora.readButton(SWITCH_DOWN) == LOW){
    os_chosen = false;
    menu_init();
  }
  
  // Navigate payloads
  if (Esplora.readButton(JOYSTICK_DOWN) == LOW) payload++;
  else if (Esplora.readButton(JOYSTICK_UP) == LOW) payload--;
  if (payloads[payload] == "") os = 0;
  if (payload <= -1) payload = 0;
  
  // Draw in groups
  if (payload != prevPayload || redraw){
    short num_rows = (short)(height/line_height);
    Serial.print("Redrawing screen for ");
    Serial.println(oses[os]);
    // Determine whether to redraw the entire screen
    short offset = payload - (payload % num_rows);
    if (offset != (prevPayload - (prevPayload % num_rows)) || redraw){ // Redraw entire thing
      Serial.println("Redrawing entire screen");
      EsploraTFT.background(0,0,0);
      EsploraTFT.stroke(255,255,255);
      EsploraTFT.text(oses[os],0,0);
      for (short i = 0; i < num_rows; i++){
        short y = line_height * i;
        if (payload == i + offset){
          EsploraTFT.fill(255,255,255);
          EsploraTFT.rect(0,y-4,width,line_height+2);
          EsploraTFT.stroke(0,0,0);
        } else {
          EsploraTFT.stroke(255,255,255);
        }
        short str_len = payloads[i].length()+1;
        char str[str_len];
        payloads[i].toCharArray(str, str_len);
        Serial.print("Printing filename: ");
        Serial.println(str);
        EsploraTFT.text(str, 2, y);
      }
    } else { // Only redraw changes
      // Clear previous payload
      short y = line_height * (prevPayload % num_rows);
      EsploraTFT.fill(0,0,0);
      EsploraTFT.rect(0,y-4,width,line_height+2);
      EsploraTFT.stroke(255,255,255);
      short str_len = payloads[prevPayload].length()+1;
      char str1[str_len];
      payloads[prevPayload].toCharArray(str1, str_len);
      EsploraTFT.text(str1, 2, y);
      // Highlight new OS
      y = line_height * (payload % num_rows);
      EsploraTFT.fill(255,255,255);
      EsploraTFT.rect(0,y-4,width,line_height+2);
      EsploraTFT.stroke(0,0,0);
      str_len = payloads[payload].length()+1;
      char str2[str_len];
      payloads[payload].toCharArray(str2, str_len);
      EsploraTFT.text(str2, 2, y);
    }
    prevPayload = payload;
    delay(250);
  }
}

