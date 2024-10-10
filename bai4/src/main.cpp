#include <Arduino.h>
#include "LED.h"
#include <OneButton.h>

LED led(LED_PIN, LED_ACT);
OneButton button(BTN_PIN, !BTN_ACT);

void btnPush();
void btnDoubleClick();


void setup()
{
    led.off();
    button.attachClick(btnPush);            // ấn 1 lần để ON/OFF
    button.attachDoubleClick(btnDoubleClick); // double click để chuyển sang nháy LED
}

void loop()
{
    led.loop();
    button.tick();
}

void btnDoubleClick()
{
    led.blink(200); // Đặt đèn LED ở chế độ nhấp nháy
}

void btnPush()
{
    led.flip(); // Bật/Tắt đèn LED

}


