#include <SD.h>

const int chipSelect = 53;  // Pino CS conectado ao pino 53 do Arduino Mega

void setup() {
  Serial.begin(9600);
  pinMode(chipSelect, OUTPUT);

  if (!SD.begin(chipSelect)) {
    Serial.println("Falha ao iniciar o cartão SD!");
    return;
  }

  Serial.println("Cartão SD inicializado com sucesso.");
  formatSDCard();
}

void loop() {
  // Não há necessidade de fazer nada no loop neste exemplo
}

void formatSDCard() {
  Serial.println("Formatando o cartão SD...");

  if (SD.exists("usina.txt")) {
    SD.remove("usina.txt");  // Apagar um arquivo existente
  }

  Serial.println("Cartão SD formatado com sucesso.");
}