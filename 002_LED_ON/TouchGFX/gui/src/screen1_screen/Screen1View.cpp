#include <gui/screen1_screen/Screen1View.hpp>
#include "main.h"
uint8_t BlinkFlag;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::led_on()
{
	HAL_GPIO_WritePin(GPIOG	, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_SET);
	BlinkFlag = 0;

}
void Screen1View::led_off()
{
	HAL_GPIO_WritePin(GPIOG	, GPIO_PIN_13 | GPIO_PIN_14, GPIO_PIN_RESET);
	BlinkFlag = 0;

}
void Screen1View::led_blink()
{
	BlinkFlag = 1;
}

