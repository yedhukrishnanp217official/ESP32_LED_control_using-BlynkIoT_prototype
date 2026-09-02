#define BLYNK_TEMPLATE_ID "TMPL3HnbpjzX-"
#define BLYNK_TEMPLATE_NAME "ESP32 LED Control"
#define BLYNK_AUTH_TOKEN "IeskRJuOhm0nEwHP3gl29Fku_SW_wNbq"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "KNSCBE-W";
char pass[] = "Kns@2026";

// =========================
// LED PIN DEFINITIONS
// =========================

#define LED1 23
#define LED2 22
#define LED3 21


// =========================
// LED 1 → BLYNK V0
// =========================

BLYNK_WRITE(V0)
{
  int value = param.asInt();

  digitalWrite(LED1, value);

  Serial.print("LED 1 / V0 = ");
  Serial.println(value ? "ON" : "OFF");
}


// =========================
// LED 2 → BLYNK V1
// =========================

BLYNK_WRITE(V1)
{
  int value = param.asInt();

  digitalWrite(LED2, value);

  Serial.print("LED 2 / V1 = ");
  Serial.println(value ? "ON" : "OFF");
}


// =========================
// LED 3 → BLYNK V2
// =========================

BLYNK_WRITE(V2)
{
  int value = param.asInt();

  digitalWrite(LED3, value);

  Serial.print("LED 3 / V2 = ");
  Serial.println(value ? "ON" : "OFF");
}


// =========================
// BLYNK CONNECTION
// =========================

BLYNK_CONNECTED()
{
  Serial.println("Connected to Blynk!");

  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
}


// =========================
// SETUP
// =========================

void setup()
{
  Serial.begin(115200);

  // Configure LED pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  // Start with LEDs OFF
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  Serial.println();
  Serial.println("============================");
  Serial.println("ESP32 3-LED IoT CONTROLLER");
  Serial.println("============================");

  Serial.println("Connecting to Blynk...");

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


// =========================
// LOOP
// =========================

void loop()
{
  Blynk.run();
}