
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include<SoftwareSerial.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
SoftwareSerial Bluetooth(3,2);                                      //rx,tx


#define NUMFLAKES     10

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

void setup() {
  Serial.begin(9600);
  Bluetooth.begin(9600); 
  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.drawPixel(10, 10, WHITE);
  display.display();
  delay(2000);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,10);
  display.print("Hii\n");
  display.print("User");
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
}

void loop() {
  
  char val;
  if(Bluetooth.available())     
  {
    val = Bluetooth.read();    
    Serial.print(val);  
  }
  if( val=='C')
  {
  for(int i=0;i<8;i++)
  {
  display.setCursor(0,0);
  display.print("INCOMING\n");
  display.println("CALL");
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  delay(500);
  }
  }
  else if(val=='M')
  {
  for(int i=0;i<3;i++)
  {
  display.setCursor(0,0);
  display.print("MISSED\n");
  display.print("CALL");
  display.display();
  delay(500);
  display.clearDisplay();
  display.display();
  delay(500);
  } 
  val=' ';
  }
}

