/*
 * screens.c
 *
 *  Created on: Mar 4, 2021
 *      Author: Matthew T Suzuki
 */

#include "main.h"
#include "graphic.h"
#include "lcd.h"

void InitialScreen(void)
{
	int x = 50;
	LCD_ClearScreenLtdc(0x10);
	LCD_DrawWBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawLBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawCBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawOBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawMBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	HAL_Delay(2000);
	LCD_ClearScreenLtdc(0xFF);
}

void MenuScreen(void)
{
	int x = 50;
	LCD_ClearScreenLtdc(0x11);
	LCD_DrawMBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawNBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawUBig(x,100);
}

void BluetoothScreen(void)
{
	int x = 30;
	LCD_ClearScreenLtdc(0x12);
	LCD_DrawBBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawLBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawUBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawTBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawOBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawOBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawTBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawHBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	x = 30;
	LCD_DrawPBig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawABig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawIBig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawRBig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawIBig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawNBig(x, 118);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawGBig(x,118);
}

void ScheduleScreen()
{
	int x = 50;
	LCD_ClearScreenLtdc(0x13);
	LCD_DrawSBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawCBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawHBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawDBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawUBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawLBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
}

void DispensedScreen()
{
	int x = 50;
	LCD_ClearScreenLtdc(0x14);
	LCD_DrawDBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawIBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawSBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawPBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawNBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawSBig(x,100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawEBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
	LCD_DrawDBig(x, 100);
	x = (x + 18) % LCD_WIDTH;
}
