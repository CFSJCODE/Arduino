//Programa: GY302 Com Relé e LCD


//Inclusão De Bibliotecas

//Inclui biblioteca responsável por gerenciar a comunicação I2C
#include <Wire.h>

//Inclui biblioteca do sensor de luminosidade
#include <BH1750.h>

//Inclui biblioteca do display LCD
#include <LiquidCrystal.h>


//Define a pinagem do módulo relé

//Porta ligada ao pino IN1 do modulo
int porta_rele1 = 8;
//Porta ligada ao pino IN2 do modulo
int porta_rele2 = 9;


//Define a pinagem do display LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 6);


//Cria uma instância do sensor de luminosidade
BH1750 lightMeter;


void setup() {


  //Inicializa o monitor serial na velocidade 9600
  Serial.begin(9600);


  //Inicializa o I2C Bus
  Wire.begin();


  //Inicializa a medidação da luminosidade
  lightMeter.begin();


  //Inicializa o LCD e define o seu tamanho como 16x2
  lcd.begin(16, 2);


  //Define os pinos para o relé como saída
  pinMode(porta_rele1, OUTPUT);
  pinMode(porta_rele2, OUTPUT);
}



void loop() {

  // A Variável recebe o valor da luminosidade medido
  float lux = lightMeter.readLightLevel();
  Serial.print("Luminosidade: ");

  //Imprime no monitor serial o valor da luminosidade medido
  Serial.print(lux);


  //Seta o cursor do LCD para a posição 0,0
  lcd.setCursor (0, 0);

  //Imprime no LCD (Intensidade Da Luz);
  lcd.print ("Intensidade Luz");

  //Seta o cursor do LCD para a posição 0,1
  lcd.setCursor (0, 1);

  //Imprime no LCD o valor da variável (lux)
  lcd.print (lux);


  //Verifica se o índice de luminosidade medido está abaixo de 50 e ativa os relés
  if (lux >= 50) {
    digitalWrite(porta_rele1, LOW);
    digitalWrite(porta_rele2, LOW);
  }


  //Verifica se o índice de luminosidade medido está acima de 50 e desativa os relés
  if (lux <= 50) {
    digitalWrite(porta_rele1, HIGH);
    digitalWrite(porta_rele2, HIGHv);
  }

  //Define um intervalo de 1 segundo
  delay(1000);

}