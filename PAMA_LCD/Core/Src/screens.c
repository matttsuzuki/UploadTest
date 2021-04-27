/*
 * screens.c
 *
 *  Created on: Mar 4, 2021
 *      Author: Matthew T Suzuki
 */

#include "main.h"
#include "graphic.h"
#include "lcd.h"
#include <string.h>

void letterselect(const char letter, int x, int y){
	if( letter == 'A' ) {
		LCD_A(x, y);
	}
	else if( letter == 'B' ) {
		LCD_B(x, y);
	}
	else if( letter == 'C' ) {
		LCD_C(x, y);
	}
	else if( letter == 'D' ) {
		LCD_D(x, y);
	}
	else if( letter == 'E' ) {
		LCD_E(x, y);
	}
	else if( letter == 'F' ) {
		LCD_F(x, y);
	}
	else if( letter == 'G' ) {
		LCD_G(x, y);
	}
	else if( letter == 'H' ) {
		LCD_H(x, y);
	}
	else if( letter == 'I' ) {
		LCD_I(x, y);
	}
	else if( letter == 'J' ) {
		LCD_J(x, y);
	}
	else if( letter == 'K' ) {
		LCD_K(x, y);
	}
	else if( letter == 'L' ) {
		LCD_L(x, y);
	}
	else if( letter == 'M' ) {
		LCD_M(x, y);
	}
	else if( letter == 'N' ) {
		LCD_N(x, y);
	}
	else if( letter == 'O' ) {
		LCD_O(x, y);
	}
	else if( letter == 'P' ) {
		LCD_P(x, y);
	}
	else if( letter == 'Q' ) {
		LCD_Q(x, y);
	}
	else if( letter == 'R' ) {
		LCD_R(x, y);
	}
	else if( letter == 'S' ) {
		LCD_S(x, y);
	}
	else if( letter == 'T' ) {
		LCD_T(x, y);
	}
	else if( letter == 'U' ) {
		LCD_U(x, y);
	}
	else if( letter == 'V' ) {
		LCD_V(x, y);
	}
	else if( letter == 'W' ) {
		LCD_W(x, y);
	}
	else if( letter == 'X' ) {
		LCD_X(x, y);
	}
	else if( letter == 'Y' ) {
		LCD_Y(x, y);
	}
	else if( letter == 'Z') {
		LCD_Z(x, y);
	}
	else if( letter == '0' ) {
		LCD_0(x, y);
	}
	else if( letter == '1' ) {
		LCD_1(x, y);
	}
	else if( letter == '2' ) {
		LCD_2(x, y);
	}
	else if( letter == '3' ) {
		LCD_3(x, y);
	}
	else if( letter == '4' ) {
		LCD_4(x, y);
	}
	else if( letter == '5') {
		LCD_5(x, y);
	}
	else if( letter == '6' ) {
		LCD_6(x, y);
	}
	else if( letter == '7' ) {
		LCD_7(x, y);
	}
	else if( letter == '8' ) {
		LCD_8(x, y);
	}
	else if( letter == '9') {
		LCD_9(x, y);
	}
	else if ( letter == '.'){
		LCD_Period(x,y);
	}
	else if ( letter == ':'){
		LCD_Colon(x, y);
	}
	else if( letter == ' ') {
	}
}

void type(char const * word, int x, int y){
	for (int i = 0; i < strlen(word); i++){
		if ( x >= 224 ){
			x = 0;
			y = y + 18;
		}
		if ( y >= 304 ){
			y = 0;
			x = 0;
		}
		letterselect(word[i], x, y);
		x = (x + 18) % LCD_WIDTH;
	}
}



void InitialScreen(void)
{
	LCD_ClearScreenLtdc(0xFF);
	type("WELCOME", 50, 152);
	type("PAMA" , 85, 294);
	HAL_Delay(3000);
	LCD_ClearScreenLtdc(0xFF);
}

void MenuScreen(void)
{
	LCD_ClearScreenLtdc(0x05);
	type("MENU", 70, 152);
	type("PAMA" , 85, 294);
}

void BluetoothScreen(void)
{
	LCD_ClearScreenLtdc(0x05);
	type("BLUETOOTH", 40, 50);
	type("PAIRING", 40, 68);
	//DEMONSTRATION PURPOSES
	type("PAIRING...", 20, 152);
	type("PAMA" , 85, 294);
}

void ScheduleScreen()
{
	LCD_ClearScreenLtdc(0x05);
	type("SCHEDULE", 30, 50);
	//DEMONSTRATION PURPOSES
	type("TYLENOL", 10, 100);
	type("2:30 2", 10, 118);
	type("SIMVASTATIN", 10, 154);
	type("3:00 1", 10, 172);
	type("AZITHROMYCIN", 10, 208);
	type("3:30 1", 10, 226);
	type("PAMA", 85, 294);
}

void DispensedScreen()
{
	LCD_ClearScreenLtdc(0x05);
	type("DISPENSE", 50, 50);
	//DEMONSTRATION PURPOSES
	type("PREPARING:", 25, 100);
	type("TYLENOL", 10, 118);
	type("SIMVASTATIN", 10, 136);
	type("AZITHROMYCIN", 10, 154);
	type("PAMA" , 85, 294);
}
