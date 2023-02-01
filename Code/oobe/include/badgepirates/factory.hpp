#pragma once
//#define AUTOMATIC_UPDATES // Comment out to disable, Does not require boot to be pressed to initialize an update.
//#define AUTOMATIC_UPDATE_DELAY 5000 // Wait X second before beginning the update process.

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <FastLED.h>
#define NUM_LEDS 3
#define DATA_PIN 17

#include "config.hpp"
#include "ota.hpp"

// Add all leds here, you will need to increase the array size accordingly.
// Cactuscon behavior, Drone will be yellow, house will be white.
const int all_leds[1] = {
    GPIO_NUM_10 // Camera
};

const int all_leds_inverted[6] = {
    GPIO_NUM_13, // Right side red
    GPIO_NUM_12, // Right side green
    GPIO_NUM_11, // Right side blue
    GPIO_NUM_5, // Left side red
    GPIO_NUM_4, // Left side green
    GPIO_NUM_3 // Left side blue
};

const int down_btn_pin = GPIO_NUM_38;
const int up_btn_pin = GPIO_NUM_37;
const int center_btn_pin = GPIO_NUM_36;
const int right_btn_pin = GPIO_NUM_35;
const int left_btn_pin = GPIO_NUM_34;

class Factory{
    private:
        // Any additonal code, for running screens, inputs, etc.
        CRGB rgbleds[NUM_LEDS];
        Adafruit_SSD1306* display;

        void test_ws2812();
        void test_oled();
        void button_setup();
        
        // BP Standard test code
        void leds_setup();
        void leds_off();
        void leds_on();
        void leds_test();
    public:
        void setup();
        void loop();
};