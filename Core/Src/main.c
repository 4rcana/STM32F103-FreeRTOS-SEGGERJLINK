/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LEDS.h"
#include "LPS25HB.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Marker1_Id 1
#pragma GCC diagnostic ignored "-Wcomment"
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c2;

UART_HandleTypeDef huart2;

/* Definitions for defaultTask
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for GreenTask
osThreadId_t GreenTaskHandle;
const osThreadAttr_t GreenTask_attributes = {
  .name = "GreenTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for BlueTask
osThreadId_t BlueTaskHandle;
const osThreadAttr_t BlueTask_attributes = {
  .name = "BlueTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityBelowNormal2,
};
/* Definitions for RedTask
osThreadId_t RedTaskHandle;
const osThreadAttr_t RedTask_attributes = {
  .name = "RedTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for LedMUX
osThreadId_t LedMUXHandle;
const osThreadAttr_t LedMUX_attributes = {
  .name = "LedMUX",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for myBlinkyCounter
osSemaphoreId_t myBlinkyCounterHandle;
const osSemaphoreAttr_t myBlinkyCounter_attributes = {
  .name = "myBlinkyCounter"
};
/* Definitions for SensorReadTask */
osThreadId_t SensorReadTaskHandle;
const osThreadAttr_t SensorReadTask_attributes = {
  .name = "SensorReadTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for DataTransferTask */
osThreadId_t DataTransferTaskHandle;
const osThreadAttr_t DataTransferTask_attributes = {
  .name = "DataTransferTask",
  .stack_size = 256 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for SensorRAWQueue */
osMessageQueueId_t SensorRAWQueueHandle;
const osMessageQueueAttr_t SensorRAWQueue_attributes = {
.name = "SensorRAWQueue"
};
/* USER CODE BEGIN PV
ButtonState Left_Button_State = WAIT;
LedState GreenState = OFF, RedState = OFF, BlueState = OFF;
*/
ButtonState Left_Button_State = TEMP;
char message_buffer[40];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C2_Init(void);
static void MX_USART2_UART_Init(void);

/*
void StartDefaultTask(void *argument);
void GreenLED(void *argument);
void BlueLED(void *argument);
void RedLED(void *argument);
void StartLedMUX(void *argument);
*/
void SensorRead(void *argument);
void DataTransfer(void *argument);
void ITM_Print(const char *argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C2_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  LPS25HB_Initialise(&hi2c2);
  /* USER CODE END 2 */

  /* Init scheduler */
  SEGGER_SYSVIEW_Conf();
  osKernelInitialize();

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* Create the semaphores(s) */
  /* creation of myBlinkyCounter
  myBlinkyCounterHandle = osSemaphoreNew(10, 0, &myBlinkyCounter_attributes);


  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* Create the queue(s) */
  /* creation of SensorRAWQueue */
  SensorRAWQueueHandle = osMessageQueueNew(3, sizeof(uint8_t), &SensorRAWQueue_attributes);

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of GreenTask
  GreenTaskHandle = osThreadNew(GreenLED, NULL, &GreenTask_attributes);

  /* creation of BlueTask
  BlueTaskHandle = osThreadNew(BlueLED, NULL, &BlueTask_attributes);

  /* creation of RedTask
  RedTaskHandle = osThreadNew(RedLED, NULL, &RedTask_attributes);

  /* creation of LedMUX
  LedMUXHandle = osThreadNew(StartLedMUX, NULL, &LedMUX_attributes);

   /* creation of SensorReadTask */
  SensorReadTaskHandle = osThreadNew(SensorRead, NULL, &SensorReadTask_attributes);

  /* creation of DataTransferTask */
  DataTransferTaskHandle = osThreadNew(DataTransfer, NULL, &DataTransferTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

  /* Start scheduler */
  SEGGER_SYSVIEW_Conf();
  osKernelStart();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI_DIV2;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL16;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 100000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */
  HAL_NVIC_SetPriority(I2C2_EV_IRQn, 40, 0); // Set priority
  HAL_NVIC_EnableIRQ(I2C2_EV_IRQn); // Enable interrupt

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
  /* USER CODE BEGIN MX_GPIO_Init_1 */

  /* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED2_Pin|LED1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Left_Button_Pin */
  GPIO_InitStruct.Pin = Left_Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Left_Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED4_Pin LED3_Pin */
  GPIO_InitStruct.Pin = LED4_Pin|LED3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : LED2_Pin LED1_Pin */
  GPIO_InitStruct.Pin = LED2_Pin|LED1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 13, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 47, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

  /* USER CODE BEGIN MX_GPIO_Init_2 */

  /* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

void SensorRead(void *argument)
{
    for(;;)
    {
	if(Left_Button_State == TEMP)
	{
	    LPS25HB_Measure_Temperature_IT(&hi2c2);
	}
	else if(Left_Button_State == PRESS)
	{
	    LPS25HB_Measure_Pressure_IT(&hi2c2);
	}
	osDelay(1000);
    }
}

void DataTransfer(void *argument)
{
    uint8_t ReceivedMSG = 0, counter = 0;
    int32_t temp = 0;
    float temperature = 0, pressure = 0;
    for(;;)
    {
	if(osMessageQueueGet(SensorRAWQueueHandle, &ReceivedMSG, NULL, osWaitForever) == osOK){
	    temp |= ReceivedMSG << (counter * 8);
	    counter++;
	    if(Left_Button_State == TEMP && counter == 2){
		if(temp > 32767) { temperature = 42.5f + (temp - 65535) / 480.0f; }	// Because value should be interpreted in 2's complement and int32_t is being used
		else { temperature = 42.5f + temp / 480.0f; }				// Calculated temperature is in degrees celsius.
		sprintf(message_buffer,"Temperature: %.2f C\r\n",temperature);
		HAL_UART_Transmit(&huart2,(uint8_t *)message_buffer,40,HAL_MAX_DELAY);
		temp = 0;
		counter = 0;
	    }
	    else if(Left_Button_State == PRESS && counter == 3){
		pressure =  temp / 4096.0f;						// Calculated pressure is in hPa
		sprintf(message_buffer,"Pressure: %.2f hPa\r\n",pressure);
		HAL_UART_Transmit(&huart2,(uint8_t *)message_buffer,40,HAL_MAX_DELAY);
		temp = 0;
		counter = 0;
	    }
	}
    }
}



/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN 5
  /* Infinite loop
  for(;;)
  {
    if(Left_Button_State == PRESSED){
	osDelay(100);	// for button debouncing
	SEGGER_SYSVIEW_Print("Button Press");
	osSemaphoreRelease(myBlinkyCounterHandle);
	Left_Button_State = WAIT;
    }
    else{
	osDelay(100);
    }
  }
  /* USER CODE END 5
}

/* USER CODE BEGIN Header_GreenLED */
/**
* @brief Function implementing the myTask01 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_GreenLED
void GreenLED(void *argument)
{
  /* USER CODE BEGIN GreenLED
  uint8_t counter = 0, semcounter = 0;
  /* Infinite loop
  for(;;)
  {
      SEGGER_SYSVIEW_Print("GreenTask is running");
      semcounter = osSemaphoreGetCount(myBlinkyCounterHandle);
      sprintf(message_buffer,"Semaphore counter = %d\n",semcounter);
      SEGGER_SYSVIEW_Print(message_buffer);

      if(osSemaphoreAcquire(myBlinkyCounterHandle, 100) == osOK){
	  counter++;
	  LEDGreen();
	  osDelay(200);
	  LEDOff();
	  osDelay(200);
      }
      else{
	  sprintf(message_buffer,"Button press counter = %d\n",counter);
	  SEGGER_SYSVIEW_Print(message_buffer);
	  counter = 0;
	  osDelay(3000);
      }


      if(GreenState == OFF) {
	  GreenState = ON;
      }
      else {
	  GreenState = OFF;
      }

      counter++;

      sprintf(message_buffer,"GreenTask counter = %d\n",counter);
      ITM_Print(message_buffer);

      if(Left_Button_State == PRESSED){
	  sprintf(message_buffer,"Terminating GreenTask\n");
	  ITM_Print(message_buffer);
	  GreenState = OFF;
	  osThreadTerminate(GreenTaskHandle);
      }

      if(counter==5){
	  sprintf(message_buffer,"Terminating RedTask\n");
	  ITM_Print(message_buffer);
	  osThreadTerminate(RedTaskHandle);
	  RedState = OFF;
      }

  }
  /* USER CODE END GreenLED
}

/* USER CODE BEGIN Header_BlueLED */
/**
* @brief Function implementing the myTask02 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_BlueLED
void BlueLED(void *argument)
{
  /* USER CODE BEGIN BlueLED
  uint8_t counter=0;
  SEGGER_SYSVIEW_NameMarker(Marker1_Id, "MyMarker");
  /* Infinite loop
  for(;;)
  {
      SEGGER_SYSVIEW_MarkStart(Marker1_Id);
      SEGGER_SYSVIEW_Print("BlueTask is running");
      for(uint32_t i=0; i<35000; i++)			//add some delay
	;
      if(BlueState == OFF) {
	  BlueState = ON;
      }
      else {
	  BlueState = OFF;
      }

      counter++;

      sprintf(message_buffer,"BlueTask counter = %d\n",counter);
      ITM_Print(message_buffer);
      SEGGER_SYSVIEW_MarkStop(Marker1_Id);
      osDelay(200);
  }
  /* USER CODE END BlueLED
}

/* USER CODE BEGIN Header_RedLED */
/**
* @brief Function implementing the myTask03 thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_RedLED
void RedLED(void *argument)
{
  /* USER CODE BEGIN RedLED
  uint8_t counter=0;
  /* Infinite loop
  for(;;)
  {
	if(RedState == OFF) {
		RedState = ON;
	}
	else {
		RedState = OFF;
	}
	counter++;

	sprintf(message_buffer,"RedTask counter = %d\n",counter);
	ITM_Print(message_buffer);

    osDelay(3000);
  }
  /* USER CODE END RedLED
}

/* USER CODE BEGIN Header_StartLedMUX */
/**
* @brief Function implementing the LedMUX thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartLedMUX
void StartLedMUX(void *argument)
{
  /* USER CODE BEGIN StartLedMUX
  /* Infinite loop
  for(;;)
  {
	if(GreenState == ON){
		LEDGreen();
		if (BlueState == ON || RedState == ON){
		osDelay(1);
		}
		else{
			osDelay(200);
		}
	}

	if(BlueState == ON){
		LEDBlue();
		if (GreenState == ON || RedState == ON){
		osDelay(1);
		}
		else{
			osDelay(200);
		}
	}

	if(RedState == ON){
		LEDRed();
		if (BlueState == ON || GreenState == ON){
		osDelay(1);
		}
		else{
			osDelay(200);
		}
	}

	if(GreenState == OFF && BlueState == OFF && RedState == OFF){
		LEDOff();
		osDelay(200);
	}
  }
  /* USER CODE END StartLedMUX
}

/**
  * @brief  Period elapsed callback in non blocking mode
  * @note   This function is called  when TIM4 interrupt took place, inside
  * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
  * a global variable "uwTick" used as application time base.
  * @param  htim : TIM handle
  * @retval None
  */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM4)
  {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	UNUSED(GPIO_Pin);

	if(GPIO_Pin == Left_Button_Pin){
		/*
		Left_Button_State = PRESSED;
		if(Left_Button_State == WAIT){
		    Left_Button_State = PRESSED;
		}
		else{
		    Left_Button_State = WAIT;
		}
		*/
		if(Left_Button_State == TEMP){
		    Left_Button_State = PRESS;
		}
		else{
		    Left_Button_State = TEMP;
		}
	}
}

void ITM_Print(const char *message_buffer){
	while(*message_buffer){
		ITM_SendChar(*message_buffer++);
	}
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
