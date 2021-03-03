
#include "main.h"
#include "ltdc.h"
#include "spi.h"
#include "gpio.h"
#include "lcd.h"
#include "graphic.h"



void SystemClock_Config(void);

extern uint8_t *GRAM;

int main(void)
{
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  LCD_GpioInit();
  LCD_LtdcInit();
  LCD_DispInit_Spi();
  LCD_DispInit_Ltdc();

//  BSP_LED_Init(LED3);
  //BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);	//added

  int x = 50;
  //horizontal speed
  int v = 1;
  while (1)
  {
//	  LCD_SetColorLtdc(0x2c);
//	  LCD_DrawRect_Ltdc(10, 10, 50, 50);
//
	  LCD_SetColorLtdc(0x16);
//	  LCD_DrawRect_Ltdc(10, 70, 50, 120);
//
//	  LCD_SetColorLtdc(0x2a);
//	  LCD_DrawRect_Ltdc(10, 130, 50, 180);
//
//	  LCD_SetColorLtdc(0xff);
//	  if (BSP_PB_GetState(BUTTON_KEY) == 1) {

//Prints 'HELLO' and moves
//	  LCD_DrawHBig(x, 100);
//	  x = (x + 18) % LCD_WIDTH;
//	  LCD_DrawEBig(x, 100);
//	  x = (x + 18) % LCD_WIDTH;
//	  LCD_DrawLBig(x, 100);
//	  x = (x + 18) % LCD_WIDTH;
//	  LCD_DrawLBig(x, 100);
//	  x = (x + 18) % LCD_WIDTH;
//	  LCD_DrawOBig(x, 100);

//	  	  HAL_Delay(500);
//	  	  LCD_ClearScreenLtdc();
//	  	  x = (x + v) % LCD_WIDTH;

	  //Initialize
	  LCD_DrawHBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawEBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawLBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawLBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawOBig(x, 100);
	  HAL_Delay(2000);
	  LCD_ClearScreenLtdc();
	  HAL_Delay(2000);
	  x = 50;
	  //main menu
	  LCD_DrawMBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawEBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawNBig(x, 100);
	  x = (x + 18) % LCD_WIDTH;
	  LCD_DrawUBig(x,100);
	  HAL_Delay(2000);
	  x = 50;
	  LCD_ClearScreenLtdc();
	  //bluetooth
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
	  HAL_Delay(2000);
	  x = 50;
	  LCD_ClearScreenLtdc();
	  //Schedule
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

	  HAL_Delay(2000);
	  x = 50;
	  LCD_ClearScreenLtdc();
	  //Dispensed
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
	  HAL_Delay(2000);
	  x = 50;
  }
//	  LCD_SetColorLtdc(0x15);
//	  LCD_DrawRect_Ltdc(10, 10, 50, 50);
//
//	  LCD_SetColorLtdc(0x2b);
//	  LCD_DrawRect_Ltdc(10, 70, 50, 120);
//
//	  LCD_SetColorLtdc(0x20);
//	  LCD_DrawRect_Ltdc(10, 130, 50, 180);
//
//	  LCD_SetColorLtdc(0xff);
//	  	  LCD_DrawH(x, 200);
//	  HAL_Delay(1000);
}

void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /**Configure the main internal regulator output voltage 
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /**Activate the Over-Drive mode 
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /**Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 56;
  PeriphClkInitStruct.PLLSAI.PLLSAIR = 7;
  PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

void Error_Handler(void)
{

}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t *file, uint32_t line)
{ 

}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
