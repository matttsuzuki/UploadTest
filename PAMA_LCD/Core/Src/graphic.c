/*
 * graphic.c
 *
 *  Created on: Mar 4, 2019
 *      Author: Boning
 */

#include "main.h"
#include "lcd.h"

uint16_t COLOR = 0x5566;
uint8_t COLOR_LTDC = 0xF0;

void LCD_SetDrawAddr(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	// Set Column Address
	LCD_WriteCommand(0x2A);
	LCD_WriteData( (x0 >> 8) & 0xFF);
	LCD_WriteData( x0 & 0xFF);
	LCD_WriteData((x1 >> 8) & 0xFF);
	LCD_WriteData(x1 & 0xFF);
	// Set Line Address
	LCD_WriteCommand(0x2B);
	LCD_WriteData((y0 >> 8) & 0xFF);
	LCD_WriteData(y0 & 0xFF);
	LCD_WriteData((y1 >> 8) & 0xFF);
	LCD_WriteData(y1 & 0xFF);
	// Memory Write
	LCD_WriteCommand(0x2c);
}

void LCD_SetColor(uint16_t c) {
	COLOR = c;
}

void LCD_SetColorLtdc(uint8_t c) {
	COLOR_LTDC = c;
}

void LCD_DrawRect_Spi(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	LCD_SetDrawAddr(x0, y0, x1, y1);
	uint8_t buffer[] = {COLOR >> 8, COLOR};
	for(int y = y0; y <= y1; y++){
		for(int x = x0; x <= x1; x++) {
			LCD_WriteBulkData(buffer, 2);
		}
	}
}

void LCD_DrawRect_Ltdc(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1) {
	for(int y = y0; y <= y1; y++){
		for(int x = x0; x <= x1; x++) {
			LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
		}
	}
}

//Matthew's Addition
void LCD_A(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || (dy >= 6 && dy <= 9))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_B(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy >= 6 && dy <= 9 && dx <= 11) || (dy <= 3 && dx <= 11) || (dy >= 12 && dx <= 11)|| (dx >= 12 && (dy >= 3 && dy <= 6)) || ((dx >= 12) && (dy >= 9 && dy <= 12))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_C(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_D(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || (dy >= 12 && dx <= 11) || (dx >= 12 && (dy >= 4 && dy <= 11))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_E(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx < 4) || (dy <= 3 || dy == 6 || dy == 7 || dy == 8 || dy == 9|| dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_F(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 6 && dy <= 9 && dx <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_G(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3) || (dy >= 12) || (dy >= 6 && dx >= 12) || (dy >= 6 && dy <= 9 && dx >= 5)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_H(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy == 6 || dy == 7 || dy == 8 || dy == 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_I(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dy >= 12) || (dx >= 6 && dx <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_J(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx >= 6 && dx <= 9) || (dx <= 9 && dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_K(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12 && dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11) || (dx >= 4 && dx <= 7 && dy >= 4 && dy <= 7) || (dx >= 11 && dy <= 3) || (dx >= 8 && dx <= 11 && dy >= 4 && dy <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_L(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_M(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || ((dx >= 6 && dx <= 9) && (dy >= 6 && dy <= 9)) || ((dx >= 3 && dx <= 6) && (dy >= 3 && dy <= 6)) || ((dx >= 9 && dx <= 12) && (dy >= 3 && dy <= 6))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_N(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || ((dx >= 6 && dx <= 9) && (dy >= 6 && dy <= 9)) || ((dx >= 3 && dx <= 6) && (dy >= 3 && dy <= 6)) || ((dx >= 9 && dx <= 12) && (dy >= 9 && dy <= 12))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_O(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_P(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || ((dy >= 6 && dy <= 9) && dx <= 11) || (dx >= 12 && (dy >= 3 && dy <= 6))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Q(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3)||(dx >= 12) || (dy <= 3) || (dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_R(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dy <= 3 && dx <= 11) || ((dy >= 6 && dy <= 9) && dx <= 11) || (dx >= 12 && (dy >= 3 && dy <= 6))|| (dx >= 12 && dy >= 12) || (dx >= 8 && dx <= 11 && dy >= 8 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_S(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dx >= 12 && dy >= 6) || (dy <= 3 || dy == 6 || dy == 7 || dy == 8 || dy ==9 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_T(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx >= 6 && dx <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_U(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3) || (dx >= 12) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_V(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx >= 6 && dx <= 9 && dy >= 12) || (dy >= 4 && dy <= 7 && dx >= 2 && dx <= 5) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7) || (dy >= 4 && dy <= 7 && dx >= 10 && dx <= 13) || (dy >= 8 && dy <= 11 && dx >= 8 && dx <= 11) ) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_W(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dy >= 4 && dy <= 7 && dx >= 1 && dx <= 4) || (dy >= 8 && dy <= 11 && dx >= 2 && dx <= 5)  || (dy >= 12 && dy <= 15 && dx >= 3 && dx <= 6)|| (dy >= 4 && dy <= 7 && dx >= 11 && dx <= 14) || (dy >= 8 && dy <= 11 && dx >= 10 && dx <= 13) || (dy >= 12 && dy <= 15 && dx >= 9 && dx <= 12) || (dx >= 6 && dx <= 9 && dy >= 6 && dy <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_X(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx <= 3 && dy >= 12) || (dx >= 12 && dy >= 12) || (dy >= 4 && dy <= 11 && dx >= 4 && dx <= 11)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Y(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx >= 6 && dx <= 9 && dy >= 8) || (dx <= 3 && dy <= 3) || (dx >= 12 && dy <= 3) || (dx >= 4 && dx <= 7 && dy >= 4 && dy <= 7) || (dx >= 8 && dx <= 11 && dy >= 4 && dy <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Z(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 4 && dy <= 7 && dx >= 8 && dx <= 11) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_0(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 || dx >= 12) || (dy <= 3 || dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_1(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dx >= 6 && dx <= 9) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_2(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12|| (dx >= 12 && dy <= 5) || (dx <= 3 && dy >= 10) || (dy >= 6 && dy <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_3(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_4(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dy >= 6 && dy <= 9) || (dx >= 10 && dx <= 13)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_5(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12|| (dy >= 6 && dy <= 9) || (dx >= 12 && dy >= 6) || (dx <= 3 && dy <= 9)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_6(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dx <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12 && dy >= 6)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_7(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dy <= 3) || (dx <= 3 && dy >= 12) || (dy >= 4 && dy <= 7 && dx >= 8 && dx <= 11) || (dy >= 8 && dy <= 11 && dx >= 4 && dx <= 7)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_8(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if (dy <= 3 || dy >= 12 || (dy >= 6 && dy <= 9) || (dx >= 12) || (dx <= 3)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_9(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx <= 3 && dy <= 9) || (dy >= 6 && dy <= 9) || (dx >= 12) || (dy <= 3) || (dy >= 12)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Period(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx >= 3 && dx <= 6) && (dy >= 12 && dy <= 15)) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_Colon(uint16_t x0, uint16_t y0) {
	const uint8_t width = 15;
	for(int dy = 0; dy <= width; dy++){
		for(int dx = 0; dx <=width; dx++){
			if ((dx >= 6 && dx <= 9) && ((dy >= 3 && dy <= 6)|| (dy >= 10 && dy <= 13))) {
				int y = y0 + dy;
				int x = x0 + dx;
				LCD_WriteGRAM(COLOR_LTDC, y * LCD_WIDTH + x);
			}
		}
	}
}

void LCD_ClearTime(void){
  	  LCD_ClearChar(0, 0);
  	  LCD_ClearChar(18, 0);
  	  LCD_ClearChar(36, 0);
  	  LCD_ClearChar(54, 0);
  	  LCD_ClearChar(72, 0);
}
