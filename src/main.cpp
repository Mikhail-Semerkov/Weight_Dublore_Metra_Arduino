#include <Arduino.h>                    // Общая библиотека под Visual Code
#include <SoftwareSerial.h>             // Подключаем библиотеку SoftwareSerial
#include <TM1637TinyDisplay6.h>         // Модернизированная библиотека под 6 разрядный экран с точками
#include "GyverTimer.h"                 // Подключаем библиотеку GyverTimer
#include "GyverButton.h"                // Подключаем библиотеку GyverButton

#define STABLE_LED_PIN 6                // Пин LED
#define CLK 7                           // CLK LCD
#define DIO 8                           // DIO LCD
#define BTN_Set0 11                     // Пин кнопки Set-0
#define PIEZO_PIN 12                    // Пин Piezo   12

const int packageSize = 15;             // Количество байт в пакете
char buffer[packageSize];               // Буфеер
int INT_TOCHKA;                         // Переменная для библиотеки под 6 разрядов
int Tochka;                             // Переменная для библиотеки под 6 разрядов
char massa[] = {      };                // Переменная для библиотеки под 6 разрядов
int BRIGHTNESS;                         // Переменная яркости дисплея
bool SET0;                              // Переменная отправки команды обнуления
bool BUTTON_TICK_CLICK;                 // Переменная кнопки смены яркости

GTimer Timer_DataOK(MS);                // Таймер проверки данных
SoftwareSerial LORA(5, 4);              // Выводы RX и TX   5/4
GButton Btn_Set0(BTN_Set0);             // Кнопка Set-0

TM1637TinyDisplay6 display(CLK, DIO);   // Инициализация дисплея как display
 
const uint8_t ANIMATION[12][4] =        // Анимация загрузки дисплея
{
  { 0x08, 0x00, 0x00, 0x00 },
  { 0x00, 0x08, 0x00, 0x00 },  
  { 0x00, 0x00, 0x08, 0x00 },  
  { 0x00, 0x00, 0x00, 0x08 },  
  { 0x00, 0x00, 0x00, 0x04 },  
  { 0x00, 0x00, 0x00, 0x02 },  
  { 0x00, 0x00, 0x00, 0x01 }, 
  { 0x00, 0x00, 0x01, 0x00 },  
  { 0x00, 0x01, 0x00, 0x00 },  
  { 0x01, 0x00, 0x00, 0x00 },  
  { 0x20, 0x00, 0x00, 0x00 },  
  { 0x10, 0x00, 0x00, 0x00 }   
};


void LOAD_ANIMATION()
{
  display.clear();
  for (int count = 0; count < 3; count++) {
    display.showAnimation(ANIMATION, FRAMES(ANIMATION), TIME_MS(10));
  }
  display.clear();
}

void setup()
{


  Serial.begin(9600);                       // открываем серийный порт
  LORA.begin(9600);                         // открываем софт порт под модуль лора
  Timer_DataOK.setTimeout(5000);            // таймаут 5 сек для проверки есть ли данные в порту

  Btn_Set0.setDebounce(80);                 // настройка антидребезга (по умолчанию 80 мс)
  Btn_Set0.setTimeout(500);                 // настройка таймаута на удержание (по умолчанию 500 мс)
  Btn_Set0.setType(HIGH_PULL);              // кнопку выставляем как высокий уровень
  Btn_Set0.setDirection(NORM_OPEN);         // обычное состояние кнопки нормально открытое
  Btn_Set0.setTickMode(AUTO);               // автоматический тик для кнопки

  pinMode(STABLE_LED_PIN, OUTPUT);          // объявляем пин для индикации стабилизации



  BRIGHTNESS = 3;
  display.setBrightness(BRIGHTNESS); 
  SET0 = false;
  
  LOAD_ANIMATION();
}


void BRIGHTNESS_Loop()
{
      BUTTON_TICK_CLICK = true;
      tone(PIEZO_PIN, 2000);
      delay(100);
      noTone(PIEZO_PIN);

      if(Btn_Set0.getClicks() == 1)
      {
        BRIGHTNESS++;
      }  

      if(BRIGHTNESS == 4 && BUTTON_TICK_CLICK == true)    
       {
         display.setBrightness(0);
         display.showString("Set  1", MAXDIGITS, 0 , false);    
         delay(500); 
         BUTTON_TICK_CLICK = false;
       } 
      if(BRIGHTNESS == 5 && BUTTON_TICK_CLICK == true)    
       {
         display.setBrightness(2);
         display.showString("Set  2", MAXDIGITS, 0 , false);       
         delay(500);
         BUTTON_TICK_CLICK = false;
       }   
       if(BRIGHTNESS == 6 && BUTTON_TICK_CLICK == true)    
       {
         display.setBrightness(4);
         display.showString("Set  3", MAXDIGITS, 0 , false);      
         delay(500);
         BUTTON_TICK_CLICK = false;
       }   
       if(BRIGHTNESS == 7 && BUTTON_TICK_CLICK == true)    
       {
         display.setBrightness(7);
         display.showString("Set  4", MAXDIGITS, 0 , false);        
         delay(500);
         BUTTON_TICK_CLICK = false;
       }  
       if(BRIGHTNESS == 8 && BUTTON_TICK_CLICK == true)    
       {
         BRIGHTNESS = 4;
         display.setBrightness(0); 
         display.showString("Set  1", MAXDIGITS, 0 , false);      
         delay(500);
         BUTTON_TICK_CLICK = false;
       }   
}


void loop()
{

  while (LORA.available() && SET0 == false)
  {
    LORA.readBytes(buffer, packageSize);
    String FULL_DATA = String(buffer[0]) + String(buffer[1]) + String(buffer[2]) + String(buffer[3]) + String(buffer[4]) + String(buffer[5]) + String(buffer[6]) + String(buffer[7]) + String(buffer[8]) + String(buffer[9]) + String(buffer[10]) + String(buffer[11]) + String(buffer[12]) + String(buffer[13]) + String(buffer[14]);
    String DATA = String(buffer[2]) + String(buffer[3]) + String(buffer[4]) + String(buffer[5]) + String(buffer[6]) + String(buffer[7]) + String(buffer[8]);

    if (buffer[13] != 0x0D && buffer[14] != 0x0A && Timer_DataOK.isReady() == false)
    {
      Timer_DataOK.reset();
      LORA.end();
      delay(100);
      LORA.begin(9600);
    }

    if (buffer[13] == 0x0D && buffer[14] == 0x0A && Timer_DataOK.isReady() == false)
    {
      INT_TOCHKA = DATA.indexOf(".");
      DATA.replace(".", "");
      DATA.replace("⸮", "");

      DATA.toCharArray(massa, 7);

      if (INT_TOCHKA == 6 || INT_TOCHKA == 5 || INT_TOCHKA == 4 || INT_TOCHKA == 3 || INT_TOCHKA == 2 || INT_TOCHKA == 1)
      {
        Tochka = INT_TOCHKA - 1;
      }
      else if (INT_TOCHKA == -1)
      {
        Tochka = INT_TOCHKA;
      }

      if (buffer[2] != 0x45 && buffer[9] == 0x20)
      {

        digitalWrite(STABLE_LED_PIN, HIGH); 

      }

      if (buffer[9] == 0x3F)
      {
        digitalWrite(STABLE_LED_PIN, LOW);
      }

      display.showString(massa, MAXDIGITS, 0 , Tochka);
      Serial.print(FULL_DATA);
      
      Timer_DataOK.reset();
      Timer_DataOK.start();
    }

  }

  if (Timer_DataOK.isReady())
  {
    LOAD_ANIMATION();
    digitalWrite(STABLE_LED_PIN, LOW);
    display.showString("Error", MAXDIGITS, 0 , false);

    tone(PIEZO_PIN, 2000);
    delay(200);
    noTone(PIEZO_PIN);
    tone(PIEZO_PIN, 1800);
    delay(120);
    noTone(PIEZO_PIN);

    Timer_DataOK.start();
    LORA.end();
    LORA.begin(9600);
  }

  if (Btn_Set0.isHold())                                // Если кнопка удержана то отправляем команду обнуления терминала, запускаем цикл пока кнопка нажата!
  {  
      
    SET0 = true;

   while(SET0 == true)
   { 

      tone(PIEZO_PIN, 2000);
      delay(500);
      noTone(PIEZO_PIN);    

      LORA.print("A");
      delay(300);

      LORA.print("A");
      delay(300);

      SET0 = false;

      break;
    }
  }   

  if (Btn_Set0.hasClicks())
  {
    BRIGHTNESS_Loop();
  }

  while (Serial.available())
  {
    LORA.print(Serial.readString());
  }

}