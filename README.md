# Library_for_project
Library was created for my project. With the functions of this library you can support temperature and humidity conditions in the incubator
# ClimateControlLib

Библиотека для управления климатической системой на базе Arduino с поддержкой:
- Контроля температуры и влажности (DHT22)
- Управления нагревателем и увлажнителем
- Отображения информации на OLED-экране (SSD1306)
- Настройки параметров через энкодер
- Работы с RTC (DS3231)

## Установка

1. Скопируйте файлы `ClimateControlLib.h` и `ClimateControlLib.cpp` в папку вашего проекта Arduino
2. Убедитесь, что установлены все необходимые зависимости:
   - GyverOLED
   - microDS3231
   - DHT22
   - GyverEncoder

## Подключение оборудования

```plaintext
DHT22   -> pin 13
OLED    -> I2C (SDA, SCL)
Энкодер -> A1 (SW), A2 (DT), A3 (CLK)
Нагреватель -> 4 (DIR), 5 (PWM)
Увлажнитель -> 6 (PWM), 7 (DIR)
```
## Основные функции

// Инициализация системы
climateSystem.initSystem();

// Основной цикл обработки
climateSystem.processLoop();

// Установка целевых значений
climateSystem.setTemperature(25);  // °C
climateSystem.setHumidity(60);     // %

// Получение текущих значений
int temp = climateSystem.getCurrentTemperature();
int hum = climateSystem.getCurrentHumidity();

## Управление режимами
- Долгое нажатие энкодера - переключение между главным меню и рабочими режимами
- Короткое нажатие - переключение между подрежимами:
- Настройка температуры
- Настройка влажности
- Рабочий режим
## Пример использования

#include "ClimateControlLib.h"

ClimateControl climateSystem;

void setup() {
  climateSystem.initSystem();
}

void loop() {
  climateSystem.processLoop();
}
