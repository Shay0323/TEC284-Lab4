#include <U8x8lib.h>
#include <DHT.h>
#include <Grove_Temperature_And_Humidity_Sensor.h>

U8X8_SSD1306_128X64_ALT0_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);

DHT dht(3, DHT11);

void setup() {
u8x8.begin();
u8x8.setFlipMode(1);
u8x8.clear();
dht.begin();
}
void loop() {
u8x8.setFont(u8x8_font_chroma48medium8_r);
u8x8.setCursor(0, 0);
u8x8.print("Hum: ");
u8x8.println(dht.readHumidity());
u8x8.println("%");
u8x8.print("Temp: ");
u8x8.println(dht.readTemperature());
u8x8.println("C");
float temp = dht.readTemperature();
float humidity = dht.readHumidity();
}
