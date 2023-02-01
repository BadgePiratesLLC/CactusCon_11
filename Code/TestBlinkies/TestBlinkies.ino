#include <Adafruit_NeoPixel.h>

#define NUMPIXELS 4 // How many NeoPixels are attached to the Arduino?
#define BRIGHTNESS 25 // Set BRIGHTNESS to about 1/5 (max = 255)
#define NeoPIN  4 // Which pin on the Arduino is connected to the NeoPixels?



#define DownButton  38  // the number of the pushbutton pin
#define UpButton  37  // the number of the pushbutton pin
#define CenterButton  36  // the number of the pushbutton pin
#define RightButton 35  // the number of the pushbutton pin
#define LeftButton  34  // the number of the pushbutton pin

#define BootButton 0 // the number of the boot Button Pin

#define DELAYVAL 150 // Time (in milliseconds) to pause
#define DELAYVAL2 250 // Time (in milliseconds) to pause
#define DELAYVAL3 2500 // Time (in milliseconds) to pause

Adafruit_NeoPixel pixels(NUMPIXELS, NeoPIN, NEO_GRBW + NEO_KHZ800);

void setup() {

  pinMode(DownButton, INPUT);
  pinMode(UpButton, INPUT);
  pinMode(CenterButton, INPUT);
  pinMode(RightButton, INPUT);
  pinMode(LeftButton, INPUT);
  pinMode(BootButton, INPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);
  Serial.begin(115200);
}

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<pixels.numPixels(); i++) { // For each pixel in strip...
    pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

 void Colors (){
  colorWipe(pixels.Color(255,   0,   0), BRIGHTNESS); // Red
  colorWipe(pixels.Color(  0, 255,   0), BRIGHTNESS); // Green
  colorWipe(pixels.Color(  0,   0, 255), BRIGHTNESS); // Blue
  colorWipe(pixels.Color(  0,   0,   0), BRIGHTNESS); // Off
 }


void loop(){
  

  Colors();  


}

