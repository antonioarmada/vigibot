// ALARMAS
  int iniciobarras= 54;
  int anchobarras= 74;
  int altobarras= 13;
  
  int tempMinBlock= 60;
  int tempAlertaBlock= 105;
  int tempMaxBlock= 110;
  
  int tempMinAgua= 60;
  int tempAlertaAgua= 95;
  int tempMaxAgua= 105;

  int presMinAceite= 0;
  int presAlertaMinAceite= 5;
  int presAlertaMaxAceite= 125;
  int presMaxAceite=125;

  int voltMedioBateria= 12;
  int voltMinBat= 8;
  int voltAlertaMinBat= 11;
  int voltAlertaMaxBat= 15;
  int voltMaxBat= 16;


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
  
  


