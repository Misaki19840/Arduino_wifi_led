# Arduino_wifi_led
Turn on leds via wifi.

# Description
Turn on and off Leds by a controller on a web page.
ESP-WROOM-02 is used for wifi connection.

Set status of leds on a web based controller. Then leds get it from Arduino.

LED1 = OFF, LED2 = ON

![190131_arduino_wifi_led_off_photo](https://user-images.githubusercontent.com/27729058/52098494-90ac7980-2612-11e9-83b2-714335c75611.png)

LED1 = ON, LED2 = ON

![190131_arduino_wifi_led_photo](https://user-images.githubusercontent.com/27729058/52098524-a4f07680-2612-11e9-8a7e-5b57bfd46d03.png)


# Code & circuit
A sketch file for Arduino is in "arduino_wifi_led".
Controller written by html and php is find in "controller_html".
An example for the circuit is like follows.

![190201_aruduino_wifi_led_](https://user-images.githubusercontent.com/27729058/52103780-cbbaa700-262a-11e9-9056-c4d0ace14a48.jpg)

# Before to get started
## ESP-WROOM-02 setting
Change baud rate for the device.
At first, connect Arduino and ESP-WROOM-02 like follows and write a sketch in "arduino_setting".
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

How to choose resistance for a transistor switch

https://sagara-works.jp/research-and-development/electronics/transistor-basic/transistor-switch/

AT command used for ESP8266
https://www.espressif.com/sites/default/files/documentation/4a-esp8266_at_instruction_set_en.pdf
