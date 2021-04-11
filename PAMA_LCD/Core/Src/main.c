#include "main.h"
#include "ltdc.h"
#include "spi.h"
#include "gpio.h"
#include "lcd.h"
#include "graphic.h"
#include "screens.h"


void SystemClock_Config(void);
void initializeGPIONVIC(void);

int view_index = 0;

extern uint8_t *GRAM;


int main(void)
{
  HAL_Init();
  SystemClock_Config();
//  MX_GPIO_Init();
  LCD_GpioInit();
  LCD_LtdcInit();
  LCD_DispInit_Spi();
  LCD_DispInit_Ltdc();
  initializeGPIONVIC();


  InitialScreen();
  MenuScreen();

  while (1)
  {

  }
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

// initialize GPIO, NVIC
void initializeGPIONVIC(void)
{
	/*Configure GPIO pin: PA0 */
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	/*EXTI interrupt init */
	HAL_NVIC_SetPriority(EXTI0_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);

	/*Configure GPIO pin: PE1 */
	GPIO_InitStruct.Pin = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	/*EXTI interrupt init */
	HAL_NVIC_SetPriority(EXTI1_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI1_IRQn);

	/*Configure GPIO pin: PE2 */
	GPIO_InitStruct.Pin = GPIO_PIN_2;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	/*EXTI interrupt init */
	HAL_NVIC_SetPriority(EXTI2_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);

	/*Configure GPIO pin: PE3 */
	GPIO_InitStruct.Pin = GPIO_PIN_3;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	/*EXTI interrupt init */
	HAL_NVIC_SetPriority(EXTI3_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI3_IRQn);

	/*Configure GPIO pin: PE4 */
	GPIO_InitStruct.Pin = GPIO_PIN_4;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);
	/*EXTI interrupt init */
	HAL_NVIC_SetPriority(EXTI4_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}


// EXIT0 handler
void EXTI0_IRQHandler(void)
{
	if (view_index == 0)
	{
		BluetoothScreen();
	}
	else if (view_index == 1)
	{
		ScheduleScreen();
	}
	else if (view_index == 2)
	{
		DispensedScreen();
	}
	else if (view_index == 3)
	{
		MenuScreen();
	}
	view_index = (view_index + 1) % 4;
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void EXTI1_IRQHandler(void)
{
	MenuScreen();
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_1);
}

void EXTI2_IRQHandler(void)
{
	BluetoothScreen();
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI3_IRQHandler(void)
{
	ScheduleScreen();
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
}

void EXTI4_IRQHandler(void)
{
	DispensedScreen();
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}
