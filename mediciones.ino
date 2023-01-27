int medirTempBlock(){
  sensors.requestTemperatures();   //Se envía el comando para leer la temperatura
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
    if (isnan(temp) || temp == -127) {
      Serial.println("Failed to read from sensor!");
      temp=0;
    } 
  return (int)temp;
}

long leerVccRef() {                                                               // https://www.luisllamas.es/analogicas-mas-precisas/
   ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
   delay(2);
   ADCSRA |= _BV(ADSC);
   while (bit_is_set(ADCSRA, ADSC));
   long result = ADCL;
   result |= ADCH << 8;
   result = 1126400L / result; 
   return result;
}

int medirTempAgua(){
  int temp = -99;
  int promedio_temp=-99;
  float Vcc = leerVccRef() / 1000.0;
  double tensionVout = (analogRead(AIN_TEMP_REGRIG) / 1024.0) * Vcc;
  double r2 = R1_TEMP * tensionVout / (Vcc - tensionVout);
  double temp_ = 1/(A_TEMP + B_TEMP  * log(r2)  + C_TEMP * pow(log(r2),3))-273.15; // Steinhart–Hart 
  temp = round(temp_);
  array_temp.push(temp);
  promedio_temp = round(array_temp.mean());
  return promedio_temp;
}

int medirPresionAceite(){
  int pres = -99;
  int promedio_pres= -99;
  float Vcc = leerVccRef() / 1000.0;
  double tensionVout = (analogRead(AIN_PRESION) / 1024.0) * Vcc;
  double r2 = R1_PRES * tensionVout / (Vcc - tensionVout);;
  double pres_ = A_PRES *r2 - B_PRES;
  pres = round(pres_);
  array_pres.push(pres);
  promedio_pres= round(array_pres.mean());
  return promedio_pres;
}

int medirVoltajeBateria(){
  float Vcc = leerVccRef() / 1000.0;
  double tensionVout = (analogRead(AIN_BAT) / 1024.0) * Vcc;
  int tensionBateria = round(tensionVout*(R1_BAT+R2_BAT)/R2_BAT);
  return tensionBateria;
}

int medirDepositoAgua (){
}




