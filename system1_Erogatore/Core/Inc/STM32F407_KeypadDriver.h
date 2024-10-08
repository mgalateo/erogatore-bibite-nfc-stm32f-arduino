#ifndef STM32F407_KEYPADDRIVER_H
#define STM32F407_KEYPADDRIVER_H

#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

/** 
  Keypad	STM32F3xx	 Description      I/O

     R1			PD12			Row 1           Output
     R2			PD13			Row 2           Output
     R3			PD11			Row 3           Output
     R4			PD10			Row 4           Output
		 
     C1			PC3				Column 1        Input
     C2			PC2				Column 2        Input
     C3			PC1				Column 3        Input
     C4			PC0				Column 4        Input
**/


/* Rows */
/* Row 1 default */
#define KEYPAD_ROW_1_PORT			  GPIOD
#define KEYPAD_ROW_1_PIN			  GPIO_PIN_12

/* Row 2 default */
#define KEYPAD_ROW_2_PORT			  GPIOD
#define KEYPAD_ROW_2_PIN			  GPIO_PIN_13

/* Row 3 default */
#define KEYPAD_ROW_3_PORT			  GPIOD
#define KEYPAD_ROW_3_PIN			  GPIO_PIN_11

/* Row 4 default */
#define KEYPAD_ROW_4_PORT			  GPIOD
#define KEYPAD_ROW_4_PIN			  GPIO_PIN_10


/* Columns */
/* Column 1 default */
#define KEYPAD_COLUMN_1_PORT		GPIOC
#define KEYPAD_COLUMN_1_PIN			GPIO_PIN_3

/* Column 2 default */
#define KEYPAD_COLUMN_2_PORT		GPIOC
#define KEYPAD_COLUMN_2_PIN			GPIO_PIN_2

/* Column 3 default */
#define KEYPAD_COLUMN_3_PORT		GPIOC
#define KEYPAD_COLUMN_3_PIN			GPIO_PIN_1

/* Column 4 default */
#define KEYPAD_COLUMN_4_PORT		GPIOC
#define KEYPAD_COLUMN_4_PIN			GPIO_PIN_0

/* ROW port clock enable */
#define KEYPAD_ROW_1_PORT_CLK_ENABLE        __HAL_RCC_GPIOC_CLK_ENABLE()
#define KEYPAD_ROW_2_PORT_CLK_ENABLE        __HAL_RCC_GPIOC_CLK_ENABLE()
#define KEYPAD_ROW_3_PORT_CLK_ENABLE        __HAL_RCC_GPIOA_CLK_ENABLE()
#define KEYPAD_ROW_4_PORT_CLK_ENABLE        __HAL_RCC_GPIOA_CLK_ENABLE()

/* COLUMN Port clock enable */
#define KEYPAD_COLUMN_1_PORT_CLK_ENABLE     __HAL_RCC_GPIOA_CLK_ENABLE()
#define KEYPAD_COLUMN_2_PORT_CLK_ENABLE     __HAL_RCC_GPIOA_CLK_ENABLE() 
#define KEYPAD_COLUMN_3_PORT_CLK_ENABLE     __HAL_RCC_GPIOC_CLK_ENABLE() 
#define KEYPAD_COLUMN_4_PORT_CLK_ENABLE     __HAL_RCC_GPIOB_CLK_ENABLE() 


/*------------------------Define your GPIO pins here - END----------------------------*/
/* Keypad NOT pressed */
#define NULL_CHARACTER              '\0'
#define KEYPAD_NOT_PRESSED			NULL_CHARACTER 

/**
 * @brief  Initializes keypad functionality
 * @param  none
 * @retval None
 */
void KEYPAD_Init(void);

/**
 * @brief  Reads keypad data
 * @param  None
 * @retval Button status. This parameter will be a value of KEYPAD_Button_t enumeration
 */
char KEYPAD_Read(void);

#endif


