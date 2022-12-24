
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <Fonts/FreeSans9pt7b.h>
#include <OneWire.h>                
#include <DallasTemperature.h>
#include "config.h"


#define OLED_RESET -1 //4
Adafruit_SH1106 display(OLED_RESET);

OneWire ourWire(PIN_TERMOMETRO);                //Se establece el pin 2  como bus OneWire
DallasTemperature sensors(&ourWire);            //Se declara una variable u objeto para nuestro sensor


void setup() {
  Serial.begin(9600);
  Serial.println("HOLA MUNDO");
  
  pinMode(PIN_BUZZER, OUTPUT);
  digitalWrite(PIN_BUZZER, LOW);
  pinMode(PIN_SENSOR_NIVEL_REF, INPUT);
  pinMode(PIN_LATIDO, OUTPUT);
  digitalWrite(PIN_LATIDO, LOW);


  display.begin(SH1106_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3D (for the 128x64)
  display.clearDisplay(); // si no borro aca muestra logo de Adafruit
  display.setRotation(2);
  display.display();
  printLogo();
  delay(ESPERA_EN_CONTACTO);
}

void loop() {
  static bool latido=false;
  static unsigned long tiempoUltimoPitido;
  bool enAlarma = false;
  bool cartelParar = false;
  int valorMedido;

  // INTERFASE
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  // Check Temp Block
  valorMedido = medirTempBlock();
  //valorMedido = 90;
  if (!cartelParar && valorMedido < TEMP_ALERTA_BLOCK) {
    dibujarTempBlock(valorMedido);
  }
   if (!cartelParar && valorMedido >= TEMP_ALERTA_BLOCK) {
    dibujarAlarmaTempBlock(valorMedido);
    enAlarma=true;
  }
  if (!cartelParar && valorMedido >= TEMP_MAX_BLOCK) {
    dibujarPararTempBlock(valorMedido);
    cartelParar = true;
  }

  // Check Temp Refrigerante
  valorMedido = medirTempAgua();
  //valorMedido = 90;
  if (!cartelParar && valorMedido < TEMP_ALERTA_AGUA) {
    dibujarTempAgua(valorMedido);
  }
   if (!cartelParar && valorMedido >= TEMP_ALERTA_AGUA) {
    dibujarAlarmaTempAgua(valorMedido);
    enAlarma=true;
  }
  if (!cartelParar && valorMedido >= TEMP_MAX_AGUA) {
    dibujarPararTempAgua(valorMedido);
    cartelParar = true;
  }

  // Check Presion Aceite
  valorMedido = medirPresionAceite();
  //valorMedido = 121;
  if (!cartelParar && valorMedido < PRES_ALERTA_MAX_ACEITE && valorMedido > PRES_ALERTA_MIN_ACEITE) {
    dibujarPresionAceite(valorMedido);
  }
   if (!cartelParar && valorMedido >= PRES_ALERTA_MAX_ACEITE) {
    dibujarAlarmaMaxPresionAceite(valorMedido);
    enAlarma=true;
  }
  if (!cartelParar && valorMedido <= PRES_ALERTA_MIN_ACEITE) {
    dibujarAlarmaMinPresionAceite(valorMedido);
    enAlarma=true;
  }
  if (!cartelParar && valorMedido >= PRES_MAX_ACEITE) {
    dibujarPararMaxAceite(valorMedido);
    cartelParar = true;
  }
  if (!cartelParar && valorMedido <= PRES_MIN_ACEITE) {
    dibujarPararMinAceite(valorMedido);
    cartelParar = true;
  }

  // Check Voltaje de carga Batería
  valorMedido = medirVoltajeBateria();
  //valorMedido = 12;
  if (!cartelParar && valorMedido < VOLTAJE_MAX_BAT && valorMedido > VOLTAJE_MIN_BAT) {
    dibujarVolajeBateria(valorMedido);
  }
  if (!cartelParar && valorMedido >= VOLTAJE_MAX_BAT) {
    dibujarPararMaxBateria(valorMedido);
    cartelParar = true;
  }
  if (!cartelParar && valorMedido <= VOLTAJE_MIN_BAT) {
    dibujarPararMinBateria(valorMedido);
    cartelParar = true;
  }

  // Check Nivel de Regrigerante
  bool noHayRefrigerante = digitalRead(PIN_SENSOR_NIVEL_REF);
  //noHayRefrigerante = 0;
  if (noHayRefrigerante) {
    dibujarPararNivelBajoAgua();
    cartelParar = true;
  }
  
  // latido
  if (!latido) {
    display.fillCircle(23,7,1,WHITE); // Latido
    digitalWrite(PIN_LATIDO,HIGH);
    latido = true;
  } else {
    latido = false;
    digitalWrite(PIN_LATIDO,LOW);
  }
  display.display();
  
  // Activacion de Buzzer de alarma
  if (enAlarma && millis()-tiempoUltimoPitido > INTERVALO_BUZZER_ALARMA) { 
    digitalWrite(PIN_BUZZER, HIGH); 
    delay (DUARACION_BUZZER_ALARMA); // congela el programa pero es simple y funciona para esto
    digitalWrite(PIN_BUZZER, LOW);
    tiempoUltimoPitido = millis();
  }
  if (cartelParar) {
    digitalWrite(PIN_BUZZER, HIGH);
  } else {
    digitalWrite(PIN_BUZZER, LOW);
  }

  delay(500);
}

// delay al empezaar
// logo



