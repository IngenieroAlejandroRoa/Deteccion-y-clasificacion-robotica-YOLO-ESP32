void setup() {
  Serial.begin(115200);
  delay(2000);  // Espera a que se establezca la conexión serial
  Serial.println("ESP32 esperando datos...");
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');  // Lee hasta salto de línea
    Serial.println("ESP32 recibió: " + data);    // Devuelve confirmación
  }
}
