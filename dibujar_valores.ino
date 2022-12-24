int calcularAnchoBarra(int medidoValor, int minValor, int maxValor) {
  float anchoBarraFilled = 0;
  if (medidoValor > minValor){
    float delta = medidoValor - minValor;
    anchoBarraFilled = delta / (maxValor - minValor) * anchobarras;
  }
  return (int(anchoBarraFilled));
}

void dibujarTempBlock(int valorMedido){
  display.drawCircle(49,3,2,WHITE);
  display.drawRect(iniciobarras, 2, anchobarras,  altobarras, WHITE);
  display.fillRect(iniciobarras, 2, calcularAnchoBarra(valorMedido,TEMP_MIN_BLOCK,TEMP_MAX_BLOCK), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(1, 5);
  display.println(F("BLK"));
  if (valorMedido > TEMP_MIN_BLOCK) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 5);
  display.println(TEMP_MIN_BLOCK);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 5);
  display.println(TEMP_MAX_BLOCK);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,12);
  //display.print("b ");
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarTempAgua(int valorMedido){
  display.drawCircle(49,20,2,WHITE);
  display.drawRect(iniciobarras, 18, anchobarras,  altobarras, WHITE);
  display.fillRect(iniciobarras, 18, calcularAnchoBarra(valorMedido,TEMP_MIN_AGUA,TEMP_MAX_AGUA), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(1, 20);
  display.println(F("RFR"));
  if (valorMedido > TEMP_MIN_AGUA) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 21);
  display.println(TEMP_MIN_AGUA);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 21);
  display.println(TEMP_MAX_AGUA);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,28);
  //display.print("a ");
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarPresionAceite(int valorMedido){
  display.drawRect(iniciobarras, 34, anchobarras, altobarras, WHITE);
  display.fillRect(iniciobarras, 34, calcularAnchoBarra(valorMedido,PRES_MIN_ACEITE,PRES_MAX_ACEITE), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(47, 29);
  display.println("p");
  display.setCursor(47, 36);
  display.println("s");
  display.setCursor(47, 42);
  display.println("i");
  display.setCursor(1, 35);
  display.println(F("PRE"));
  if (valorMedido > PRES_MIN_ACEITE) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 37);
  display.println(PRES_MIN_ACEITE);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 37);
  display.println(PRES_MAX_ACEITE);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,45);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarVolajeBateria(int valorMedido){
  display.drawRect(iniciobarras, 50, anchobarras, altobarras, WHITE);
  if (valorMedido < VOLTAJE_MEDIO_BAT && valorMedido >= VOLTAJE_MIN_BAT) {
    float delta_ = VOLTAJE_MEDIO_BAT - valorMedido;
    int anchoBarraFilled_ = int (delta_/(VOLTAJE_MEDIO_BAT-VOLTAJE_MIN_BAT)*anchobarras/2);
    display.fillRect(iniciobarras+anchobarras/2-anchoBarraFilled_, 50, anchoBarraFilled_, altobarras, WHITE);    
  } else if (valorMedido > VOLTAJE_MEDIO_BAT) { //  && valorMedido <= VOLTAJE_MAX_BAT
    display.fillRect(iniciobarras+anchobarras/2, 50 ,calcularAnchoBarra(valorMedido,VOLTAJE_MEDIO_BAT,VOLTAJE_MAX_BAT)/2, altobarras, WHITE);
  } else if (valorMedido < VOLTAJE_MIN_BAT) {
    display.fillRect(iniciobarras, 50, anchobarras/2, altobarras, WHITE);
  } else if (valorMedido = VOLTAJE_MEDIO_BAT) {
    display.fillCircle(iniciobarras+anchobarras/2,56,3,WHITE);
  }
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(1, 53);
  display.println(F("BAT"));
  display.setCursor(47, 55);
  display.print(F("V"));
  display.setCursor(iniciobarras+3, 53);
  display.println(VOLTAJE_MIN_BAT);
  display.setCursor(iniciobarras+anchobarras-14, 53);
  display.println(VOLTAJE_MAX_BAT);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(26,62);
  display.print(valorMedido);
}


