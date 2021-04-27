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
void LCD_A(uint16_t x0, uint16_t y0);
void LCD_B(uint16_t x0, uint16_t y0);
void LCD_C(uint16_t x0, uint16_t y0);
void LCD_D(uint16_t x0, uint16_t y0);
void LCD_E(uint16_t x0, uint16_t y0);
void LCD_F(uint16_t x0, uint16_t y0);
void LCD_G(uint16_t x0, uint16_t y0);
void LCD_H(uint16_t x0, uint16_t y0);
void LCD_I(uint16_t x0, uint16_t y0);
void LCD_J(uint16_t x0, uint16_t y0);
void LCD_K(uint16_t x0, uint16_t y0);
void LCD_L(uint16_t x0, uint16_t y0);
void LCD_M(uint16_t x0, uint16_t y0);
void LCD_N(uint16_t x0, uint16_t y0);
void LCD_O(uint16_t x0, uint16_t y0);
void LCD_P(uint16_t x0, uint16_t y0);
void LCD_Q(uint16_t x0, uint16_t y0);
void LCD_R(uint16_t x0, uint16_t y0);
void LCD_S(uint16_t x0, uint16_t y0);
void LCD_T(uint16_t x0, uint16_t y0);
void LCD_U(uint16_t x0, uint16_t y0);
void LCD_V(uint16_t x0, uint16_t y0);
void LCD_W(uint16_t x0, uint16_t y0);
void LCD_X(uint16_t x0, uint16_t y0);
void LCD_Y(uint16_t x0, uint16_t y0);
void LCD_Z(uint16_t x0, uint16_t y0);
void LCD_0(uint16_t x0, uint16_t y0);
void LCD_1(uint16_t x0, uint16_t y0);
void LCD_2(uint16_t x0, uint16_t y0);
void LCD_3(uint16_t x0, uint16_t y0);
void LCD_4(uint16_t x0, uint16_t y0);
void LCD_5(uint16_t x0, uint16_t y0);
void LCD_6(uint16_t x0, uint16_t y0);
void LCD_7(uint16_t x0, uint16_t y0);
void LCD_8(uint16_t x0, uint16_t y0);
void LCD_9(uint16_t x0, uint16_t y0);
void LCD_Period(uint16_t x0, uint16_t y0);
void LCD_Colon(uint16_t x0, uint16_t y0);


#endif /* GRAPHIC_H_ */
