/*
 *   LCD_I2C örneği,
 *   LCD ekranın ilk satırında "Merhaba Dunya!!!"" ikinci satırında "Deneyap Kart" yazdırmaktadır.
 *
 *  ==============================================================================
 *    Bu uygulama örneği için "LiquidCrystal_I2C by Frank de Brabander" kütüphanesi indirilmelidir.  ->https://github.com/johnrickman/LiquidCrystal_I2C<-
 *    Bu uygulama örneği LiquidCrystal_I2C kütüphanesi 1.1.4 versiyonu ile yazılmıştır.
 *  ==============================================================================
*/
#include <LiquidCrystal_I2C.h>
int button_pin_home = D0;
int button_pin_deplasman =D1 ;
int button_pin_home_COUNT = 0;
int button_pin_deplasman_COUNT =0 ;
LiquidCrystal_I2C lcd_home(0x22, 16,2); 
LiquidCrystal_I2C lcd_deplasman(0x21, 16,2);
LiquidCrystal_I2C lcd_asil(0x27, 20,4);
void setup() {
pinMode(button_pin_home,INPUT);
pinMode(button_pin_deplasman,INPUT);
lcd_home.init();  // LCD'yi başlat
lcd_home.backlight();
lcd_deplasman.init();  // LCD'yi başlat
lcd_deplasman.backlight();  
lcd_asil.init();  // LCD'yi başlat
lcd_asil.backlight();
  lcd_asil.setCursor(0,0);
  lcd_asil.print("Ev Sahibi: ");
   lcd_asil.setCursor(0,2);
  lcd_asil.print("Deplasman Sahibi: ");
   lcd_home.setCursor(0,0);
  lcd_home.print("Ev Sahibi");
    lcd_deplasman.setCursor(0,0);
  lcd_deplasman.print("Deplasman ");
}
void loop(){
  if(digitalRead(D0) == 1){
    button_pin_home_COUNT +=1;
    Serial.print("Ev Sahibi" + button_pin_home_COUNT);
  }
   if(digitalRead(D1) == 1){
    button_pin_deplasman_COUNT +=1;
      Serial.print("dEPLASMAN Sahibi" + button_pin_deplasman_COUNT);
  }
    lcd_asil.setCursor(12,0);
  lcd_asil.print(button_pin_home_COUNT);
     lcd_asil.setCursor(18,2);
  lcd_asil.print(button_pin_deplasman_COUNT);
    lcd_home.setCursor(0,16);
  lcd_home.print(button_pin_home_COUNT);
    lcd_deplasman.setCursor(0,16);
  lcd_deplasman.print(button_pin_deplasman_COUNT);
delay(200);
}