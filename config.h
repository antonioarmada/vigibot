
  int iniciobarras= 54;
  int anchobarras= 74;
  int altobarras= 13;

// ALARMAS
  #define ESPERA_EN_CONTACTO 60000

  #define TEMP_MIN_BLOCK  60 
  #define TEMP_ALERTA_BLOCK  100
  #define TEMP_MAX_BLOCK  105
  
  #define TEMP_MIN_AGUA  60
  #define TEMP_ALERTA_AGUA 103
  #define TEMP_MAX_AGUA  108
  #define TEMP_NUMERO_LECTURAS_A_PROMEDIAR  10

  #define PRES_MIN_ACEITE  11
  #define PRES_ALERTA_MIN_ACEITE 20 
  #define PRES_ALERTA_MAX_ACEITE  120
  #define PRES_MAX_ACEITE 125
  #define PRES_NUMERO_LECTURAS_A_PROMEDIAR  3

  #define VOLTAJE_MEDIO_BAT  12
  #define VOLTAJE_MIN_BAT  8
  #define VOLTAJE_ALERTA_MIN_BAT  11
  #define VOLTAJE_ALERTA_MAX_BAT  15
  #define VOLTAJE_MAX_BAT  16 

  #define INTERVALO_BUZZER_ALARMA 30000 // long millis
  #define INTERVALO_BUZZER_PARAR 0 // long millis
  #define DUARACION_BUZZER_ALARMA 2000 // long millis

  #define INTERVALO_DE_REFRESCO_Y_LECTURAS 500 //  millis en delay


  // divisores de voltaje
  #define R1_BAT  4700 //+12-Vout 4639- 3675
  #define R2_BAT  983 // Vout-GND
  #define R1_TEMP  32.8 // Vout-GND
  #define R1_PRES 33.0 // Vout-GND
  #define VTOTAL = 5 // voltaje total

  //coef Steinhart-Hart para bulbo de temp SIEMENS AMR1425 (original)
  #define A_TEMP  0.00174810878912309
  #define B_TEMP  0.000252033176331
  #define C_TEMP  6.23E-08

  //coef Bulbo Presion de Aceite Orland Rober
  // lo calcule acá: https://docs.google.com/spreadsheets/d/1qfQCLduFSSs-z2fxA71gRAYeHIXaSkvhZlhe-7v67Lw/edit#gid=857753747
  #define A_PRES  0.87
  #define B_PRES  6.35 //- en la ecuacion

  // PINES
  #define AIN_BAT  A0
  #define AIN_TEMP_REGRIG  A1
  #define AIN_PRESION  A2
  #define PIN_TERMOMETRO 3
  #define PIN_BUZZER 6 // 6
  #define PIN_SENSOR_NIVEL_REF 4
  #define PIN_LATIDO 13 // 13
  
  


