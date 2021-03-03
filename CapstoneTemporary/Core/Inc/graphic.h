/*
 * graphic.h
 *
 *  Created on: Mar 4, 2019
 *      Author: Boning
 */

#ifndef GRAPHIC_H_
#define GRAPHIC_H_

void LCD_SetDrawAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void LCD_SetColor(uint16_t c);
void LCD_SetColorLtdc(uint8_t c);
void LCD_DrawRect_Spi(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void LCD_DrawRect_Ltdc(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
void LCD_DrawH(uint16_t x0, uint16_t y0);
void LCD_DrawABig(uint16_t x0, uint16_t y0);
void LCD_DrawBBig(uint16_t x0, uint16_t y0);
void LCD_DrawCBig(uint16_t x0, uint16_t y0);
void LCD_DrawDBig(uint16_t x0, uint16_t y0);
void LCD_DrawEBig(uint16_t x0, uint16_t y0);
void LCD_DrawHBig(uint16_t x0, uint16_t y0);
void LCD_DrawIBig(uint16_t x0, uint16_t y0);
void LCD_DrawLBig(uint16_t x0, uint16_t y0);
void LCD_DrawMBig(uint16_t x0, uint16_t y0);
void LCD_DrawNBig(uint16_t x0, uint16_t y0);
void LCD_DrawOBig(uint16_t x0, uint16_t y0);
void LCD_DrawPBig(uint16_t x0, uint16_t y0);
void LCD_DrawSBig(uint16_t x0, uint16_t y0);
void LCD_DrawTBig(uint16_t x0, uint16_t y0);
void LCD_DrawUBig(uint16_t x0, uint16_t y0);
void LCD_Draw0Big(uint16_t x0, uint16_t y0);
void LCD_Draw1Big(uint16_t x0, uint16_t y0);
void LCD_Draw2Big(uint16_t x0, uint16_t y0);

#endif /* GRAPHIC_H_ */
