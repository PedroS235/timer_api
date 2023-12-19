# Timer API
This is a platformIO library that can be used in your Arduino projects to have a timer like behaviour without stoping your program, like when using delay(x).
This library can be used in case you need to run some routine every x amount of ms, or to run once after some interval has passed.

## Installation
In your `platformio.ini`, you need to add the following to your lib_depencies:
```toml
lib_deps=
  https://github.com/PedroS235/timer_api#v1.0.1
```

## Example (Blynk Program)
```cpp
#include <Arduino.h>
#include <timer_api.hpp>

bool toggle_led = false;
// interval, auto_start = true, auto_reset = true
TimerAPI timer(1000); // setting the timer to trigger every 1 second

void setup(void){
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void){
  if(timer.has_elapsed()){
    toggle_led = !toggle_led;
    digitalWrite(LED_BUILTIN, toggle_led);
  }
}
```

## Example (Blynk Once)
```cpp
#include <Arduino.h>
#include <timer_api.hpp>

// interval, auto_start = true, auto_reset = true
TimerAPI timer(3000, true, false); // setting the timer to trigger after 3 seconds, only once

void setup(void){
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(void){
  if(timer.has_elapsed()){
    digitalWrite(LED_BUILTIN, HIGH);
  }
}
``` 
