void dibujarAlarmaTempBlock(int valorMedido){
  display.fillRect(0, 0, 128, altobarras+2, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(BLACK);
  display.setCursor(1, 4);
  display.print("BLK: ");
  display.setCursor(24, 4);
  display.print(TEMP_ALERTA_BLOCK);
  display.print("<");
  display.setCursor(84, 4);
  display.print(">");
  display.print(TEMP_MAX_BLOCK);
  display.print("(!)");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(50,13);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarAlarmaTempAgua(int valorMedido){
  display.fillRect(0, 16, 128, altobarras+2, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(BLACK);
  display.setCursor(1, 20);
  display.print("RFR: ");
  display.setCursor(28, 20);
  display.print(TEMP_ALERTA_AGUA);
  display.print("<");
  display.setCursor(84, 20);
  display.print(">");
  display.print(TEMP_MAX_AGUA);
  display.print("(!)");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(50,29);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarAlarmaMinPresionAceite(int valorMedido){
  display.fillRect(0, 32, 128, altobarras+2, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(BLACK);
  display.setCursor(1, 36);
  display.print("PRE: ");
  display.setCursor(38, 36);
  display.print(PRES_MIN_ACEITE);
  display.print(" >");
  display.setCursor(84, 36);
  display.print(" > ");
  display.print(PRES_MIN_ACEITE);
  display.print("(!)");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(60,45);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido); //valorMedido  
}

void dibujarAlarmaMaxPresionAceite(int valorMedido){
  display.fillRect(0, 32, 128, altobarras+2, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(BLACK);
  display.setCursor(1, 36);
  display.print("PRE: ");
  display.setCursor(25, 36);
  display.print(PRES_ALERTA_MAX_ACEITE);
  display.print("<");
  display.setCursor(83, 36);
  display.print("<");
  display.print(PRES_MAX_ACEITE);
  display.print("(!)");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(50,45);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido); //valorMedido  
}

void dibujarPararTempBlock(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(35, 25);
  display.print(F("TEMP BLOCK"));
  display.setCursor(28, 53);
  display.print(F("MAYOR QUE "));
  display.print(TEMP_MAX_BLOCK);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(47,48);
  display.print(valorMedido); //valorMedido  
}

void dibujarPararTempAgua(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(10, 25);
  display.print(F("TEMP REFRIGERANTE"));
  display.setCursor(28, 53);
  display.print(F("MAYOR QUE "));
  display.print(TEMP_MAX_AGUA);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(47,48);
  display.print(valorMedido); //valorMedido  
}

void dibujarPararMinAceite(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(13, 25);
  display.print(F("PRESION DE ACEITE"));
  display.setCursor(28, 53);
  display.print(F("MENOR QUE "));
  display.print(PRES_MIN_ACEITE);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(60,48);
  display.print(valorMedido); //valorMedido  
}

void dibujarPararMaxAceite(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(13, 25);
  display.print(F("PRESION DE ACEITE"));
  display.setCursor(28, 53);
  display.print(F("MAYOR QUE "));
  display.print(PRES_MAX_ACEITE);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(50,48);
  display.print(valorMedido); //valorMedido  
}

void dibujarPararMinBateria(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(13, 25);
  display.print(F("VOLTAJE BATERIA"));
  display.setCursor(28, 53);
  display.print(F("MENOR QUE "));
  display.print(VOLTAJE_MIN_BAT);
  display.print("v");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(53,48);
  display.print(valorMedido); //valorMedido  
  display.print("v");
}

void dibujarPararMaxBateria(int valorMedido){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(22, 25);
  display.print(F("VOLTAJE BATERIA"));
  display.setCursor(25, 53);
  display.print(F("MAYOR QUE "));
  display.print(VOLTAJE_MAX_BAT);
  display.print("v");
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(49,48);
  display.print(valorMedido); //valorMedido  
  display.print("v");
}

void dibujarPararNivelBajoAgua(){
  display.fillRect(0, 0, 128, 64, WHITE);
  display.setTextColor(BLACK);
  display.setFont(); // usa fuente default
  display.setCursor(10, 27);
  display.print(F("NIVEL REFRIGERANTE"));
  display.setFont(&FreeSans9pt7b);
  display.setCursor(33,20);
  display.print(F("PARAR"));
  display.setCursor(45,54);
  display.print(F("BAJO")); //valorMedido  
}

void cartelEsperando(){
  long cuentaRegresiva;
  cuentaRegresiva = round((ESPERA_EN_CONTACTO - millis()) / 1000);
  display.fillRect(iniciobarras, 2, anchobarras, 62, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(BLACK);
  display.setCursor(iniciobarras+10, 15);
  display.println(F("ESPERANDO")); // uso F() porque se queda sin memoria
  display.setCursor(iniciobarras+12, 25);
  display.println(F("ARRANQUE"));
  display.setFont(&FreeSans9pt7b);
  display.setCursor(iniciobarras+25,50);
  display.print(cuentaRegresiva);
}
