int calcularAnchoBarra(int medidoValor, int minValor, int maxValor) {
  float anchoBarraFilled = 0;
  if (medidoValor > minValor){
    float delta = medidoValor - minValor;
    anchoBarraFilled = delta / (maxValor - minValor) * anchobarras;
  }
  return (int(anchoBarraFilled));
}

void dibujarTempBlock(){
  int valorMedido = medirTempBlock();
  display.drawCircle(49,3,2,WHITE);
  display.drawRect(iniciobarras, 2, anchobarras,  altobarras, WHITE);
  display.fillRect(iniciobarras, 2, calcularAnchoBarra(valorMedido,tempMinBlock,tempMaxBlock), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(1, 5);
  display.println("BLK");
  if (valorMedido > tempMinBlock) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 5);
  display.println(tempMinBlock);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 5);
  display.println(tempMaxBlock);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,12);
  //display.print("b ");
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarTempAgua(){
  int valorMedido = medirTempAgua();
  display.drawCircle(49,20,2,WHITE);
  display.drawRect(iniciobarras, 18, anchobarras,  altobarras, WHITE);
  display.fillRect(iniciobarras, 18, calcularAnchoBarra(valorMedido,tempMinAgua,tempMaxAgua), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setCursor(1, 20);
  display.println("RFR");
  if (valorMedido > tempMinAgua) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 21);
  display.println(tempMinAgua);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 21);
  display.println(tempMaxAgua);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,28);
  //display.print("a ");
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarPresionAceite(){
  int valorMedido = medirPresionAceite();
  display.drawRect(iniciobarras, 34, anchobarras, altobarras, WHITE);
  display.fillRect(iniciobarras, 34, calcularAnchoBarra(valorMedido,presMinAceite,presMaxAceite), altobarras, WHITE);
  display.setFont(); // usa fuente default
  display.setCursor(47, 29);
  display.println("p");
  display.setCursor(47, 36);
  display.println("s");
  display.setCursor(47, 42);
  display.println("i");
  display.setCursor(1, 35);
  display.println("PRE");
  if (valorMedido > presMinAceite) {
    display.setTextColor(BLACK);
  } 
  display.setCursor(iniciobarras+2, 37);
  display.println(presMinAceite);
  display.setTextColor(WHITE);
  display.setCursor(iniciobarras+anchobarras-20, 37);
  display.println(presMaxAceite);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(16,45);
  if (valorMedido<100) {
    display.print("  ");
  }
  display.print(valorMedido);
}

void dibujarVolajeBateria(){
  int valorMedido = medirVoltajeBateria();
  display.drawRect(iniciobarras, 50, anchobarras, altobarras, WHITE);
  if (valorMedido < voltMedioBateria && valorMedido >= voltMinBat) {
    float delta_ = voltMedioBateria - valorMedido;
    int anchoBarraFilled_ = int (delta_/(voltMedioBateria-voltMinBat)*anchobarras/2);
    display.fillRect(iniciobarras+anchobarras/2-anchoBarraFilled_, 50, anchoBarraFilled_, altobarras, WHITE);    
  } else if (valorMedido > voltMedioBateria) { //  && valorMedido <= voltMaxBat
    display.fillRect(iniciobarras+anchobarras/2, 50 ,calcularAnchoBarra(valorMedido,voltMedioBateria,voltMaxBat)/2, altobarras, WHITE);
  } else if (valorMedido < voltMinBat) {
    display.fillRect(iniciobarras, 50, anchobarras/2, altobarras, WHITE);
  } else if (valorMedido = voltMedioBateria) {
    display.fillCircle(iniciobarras+anchobarras/2,56,3,WHITE);
  }
  display.setFont(); // usa fuente default
  display.setTextColor(WHITE);
  display.setCursor(1, 53);
  display.println("BAT");
  display.setCursor(47, 55);
  display.print("V");
  display.setCursor(iniciobarras+3, 53);
  display.println(voltMinBat);
  display.setCursor(iniciobarras+anchobarras-14, 53);
  display.println(voltMaxBat);
  display.setFont(&FreeSans9pt7b);
  display.setCursor(26,62);
  display.print(valorMedido);
}


