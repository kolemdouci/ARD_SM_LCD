

// Shield LCD TFT 2.4" displej dotykový

// připojení potřebných knihoven
#include "SWTFT.h"

// nastavení různých barev pro výpis na displej
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// inicializace LCD displeje z knihovny
SWTFT displej;
// inicializace řadiče dotykové vrstvy z knihovny,

int malina = 0;

void setup() {
  
  // zahájení komunikace s displejem
  displej.begin();
   // initialize the serial communications:
  Serial.begin(9600);
  
  // pro otočení displeje stačí změnit číslo
  // v závorce v rozmezí 0-3
  displej.setRotation(3);
  // vyplnění displeje černou barvou
  displej.fillScreen(BLACK);
  // nastavení kurzoru na souřadnice x,y
  displej.setCursor(0, 0);
  displej.setTextColor(MAGENTA);
  // velikost textu lze nastavit změnou čísla v závorce
  displej.setTextSize(4);
  
}

void loop() {
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // read all the available characters
    while (Serial.available() > 0) {
      malina = Serial.read();
      // display each character to the LCD
      displej.write(malina);
      // display serial input to serial monitor
      Serial.write(malina);
    }

  }
  }
