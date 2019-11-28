/*
 * test.c
 *
 *  Created on: 23 Nov 2019
 *      Author: benjamin
 */

#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "rtc.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "display.h"
#include "lcd.h"
#include "backlight.h"
#include "test.h"
#include "string.h"


char *test1 = "Hello world!\n\r";

/**
 @brief test_program, runs all the program test functions.
 @param void
 */
void test_program_lcd(void){
//	test_backlight_colors();
	test_lcd_initialize();
	test_lcd_rom();
	test_lcd_clear();
	test_write_string();
	HAL_Delay(1800);
	test_lcd_set_position();
}

/**
 @brief test_write_string, a test function that send a string to lcd_write_string function
 	 	and the string should be printed on the display.
 @param void
 @return void
 */
void test_write_string(void){
	lcd_write_string("Wassup");
}


/**
@brief test_write_char, a test to write a char to the display.
@param void
@return void
*/
void test_write_char(void){
	lcd_send_inst(0x80);
	lcd_send_data(0x77);
	lcd_send_data(0x61);
	lcd_send_data(0x64);
	lcd_send_data(0x64);
	lcd_send_data(0x61);
	lcd_send_data(0x70);
	lcd_send_data(0x3F);
}

/**
@brief test_screen_colors, the screen blinkes in three colors green, white and red.
@param void
@return void
*/
void test_backlight_colors(void){
	HAL_GPIO_WritePin(GPIOC, Disp_White_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOC, Disp_White_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, Disp_Red_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOC, Disp_Red_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOC, Disp_Green_Pin, GPIO_PIN_SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOC, Disp_Green_Pin, GPIO_PIN_RESET);
}

/**
 @brief test_display_initialize, a test to initialize the display
 @param void
 @return void
 */
void test_lcd_initialize(void){
	lcd_initialize();
	HAL_UART_Transmit(&huart5, (uint8_t*)test1, strlen(test1), 5000);
}

/**
 @brief test_lcd_rom, test to set the LCD ROM with function call to lcd_setROM.
 @param void
 @return void
 */
void test_lcd_rom(void){
	lcd_setROM();
}

/**
 @brief test_lcd_clear, a test function to run lcd_clear.
 @param void
 @return void
 */
void test_lcd_clear(void){
	lcd_clear();
}

/**
 @brief test_lcd_set_position, prints string "Line x", where x is the number of the line
 	 	 it is going to be printed on.
 @param void
 @return void
 */
void test_lcd_set_position(void){
	lcd_set_position(LINE1);
	lcd_write_string("Line 1");
	HAL_Delay(1000);
	lcd_set_position(LINE2);
	lcd_write_string("Line 2");
	HAL_Delay(1000);
	lcd_set_position(LINE3);
	lcd_write_string("Line 3");
	HAL_Delay(1000);
	lcd_set_position(LINE4);
	lcd_write_string("Line 4");
	HAL_Delay(5000);
}



