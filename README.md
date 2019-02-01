# Arduino_wifi_led
Turn on leds via wifi.

# Description
Turn on and off Leds by a controller on a web page.
ESP-WROOM-02 is used for wifi connection.

# Code & circuit
A scketch file for Arduino is in "arduino_wifi_led".
An example for the circuit is like follows.

# Before to get started
## ESP-WROOM-02 setting
Need to change baud rate for the device ahead.
At first, connect Arduino and ESP-WROOM-02 like follows and write a scketch in "arduino_setting".
Messages will be appear.
```
Hello from Arduino!
Hello from the Serial port!
```
Then, open serial monitor and put a command.
```
AT+UART_DEF=9600,8,1,0,0
```

# Requirements
* Arduino ESP8266 library
https://github.com/itead/ITEADLIB_Arduino_WeeESP8266

# Reference
Example for Arduino - ESP-WROOM-02 connection
http://nn-hokuson.hatenablog.com/entry/2017/04/09/091148

https://sagara-works.jp/research-and-development/electronics/transistor-basic/transistor-switch/

AT command used for ESP8266
https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf
