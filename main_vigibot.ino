
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Fonts/FreeSans9pt7b.h>
#include <OneWire.h>                
#include <DallasTemperature.h>

// PINES
#define AIN_BAT  A0
#define AIN_TEMP_REGRIG  A1
#define AIN_PRESION  A2
#define PIN_TERMOMETRO 3
#define PIN_BUZZER 6
#define PIN_SENSOR_NIVEL_REF 4

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

OneWire ourWire(PIN_TERMOMETRO);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire);            //Se declara una variable u objeto para nuestro sensor


void setup() {
  Serial.begin(9600);
  Serial.println("HOLA MUNDO");
  
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);
  pinMode(PIN_SENSOR_NIVEL_REF, INPUT);

  //analogReference(INTERNAL);



  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.setRotation(2);
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(1000);

  // Clear the buffer.
  display.clearDisplay();
  display.display();


}

void loop() {
  static bool latido=false;

  // INTERFASE
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  dibujarTempBlock();
  dibujarTempAgua();
  dibujarPresionAceite();
  dibujarVolajeBateria();
  if (!latido) {
    display.fillCircle(23,7,1,WHITE); // Latido
    latido = true;
  } else {
    latido = false;
  }
  display.display();
  digitalWrite(PIN_BUZZER, HIGH); 
  bool hayRefrigerante = digitalRead(PIN_SENSOR_NIVEL_REF);
  Serial.println(hayRefrigerante);
  delay(500);
}



