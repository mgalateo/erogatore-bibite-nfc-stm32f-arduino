#include "STM32F407_KeypadDriver.h"
#include "stm32f3xx_hal.h"
#include "stm32f3xx_hal_gpio.h"
#include <stdint.h>

/* Row pins are output */
#define SET_ROW_1_HIGH              HAL_GPIO_WritePin(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_PIN_SET)
#define SET_ROW_2_HIGH              HAL_GPIO_WritePin(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_PIN_SET)
#define SET_ROW_3_HIGH              HAL_GPIO_WritePin(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_PIN_SET)
#define SET_ROW_4_HIGH              HAL_GPIO_WritePin(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_PIN_SET)
#define SET_ROW_1_LOW               HAL_GPIO_WritePin(KEYPAD_ROW_1_PORT, KEYPAD_ROW_1_PIN, GPIO_PIN_RESET)
#define SET_ROW_2_LOW               HAL_GPIO_WritePin(KEYPAD_ROW_2_PORT, KEYPAD_ROW_2_PIN, GPIO_PIN_RESET)
#define SET_ROW_3_LOW               HAL_GPIO_WritePin(KEYPAD_ROW_3_PORT, KEYPAD_ROW_3_PIN, GPIO_PIN_RESET)
#define SET_ROW_4_LOW               HAL_GPIO_WritePin(KEYPAD_ROW_4_PORT, KEYPAD_ROW_4_PIN, GPIO_PIN_RESET)

/*Column pin are input, so read the pins */
#define READ_COLUMN_1               HAL_GPIO_ReadPin(KEYPAD_COLUMN_1_PORT, KEYPAD_COLUMN_1_PIN)
#define READ_COLUMN_2               HAL_GPIO_ReadPin(KEYPAD_COLUMN_2_PORT, KEYPAD_COLUMN_2_PIN) 
#define READ_COLUMN_3               HAL_GPIO_ReadPin(KEYPAD_COLUMN_3_PORT, KEYPAD_COLUMN_3_PIN) 
#define READ_COLUMN_4               HAL_GPIO_ReadPin(KEYPAD_COLUMN_4_PORT, KEYPAD_COLUMN_4_PIN)        

/* Keypad Button Values*/
const char Keypad_Button_Values[4][4] =  {  {'1', '2', '3', 'A'},
	                                          {'4', '5', '6', 'B'},
	                                          {'7', '8', '9', 'C'},
	                                          {'*', '0', '#', 'D'},
                                         };

/* Set Specific Keypad row to LOW */
static void Set_Keypad_Row(uint8_t Row)
{
	/*Make all Rows HIGH*/
	SET_ROW_1_HIGH;
	SET_ROW_2_HIGH;
	SET_ROW_3_HIGH;
	SET_ROW_4_HIGH;

	/*Make the specific Row low based on "Row" value */
	if(Row == 1)
		SET_ROW_1_LOW;

	if(Row == 2)
		SET_ROW_2_LOW;

	if(Row == 3)
		SET_ROW_3_LOW;

	if(Row == 4)
		SET_ROW_4_LOW;
}


/*For specific row value sent , check all the cloumns*/
static char Check_Keypad_Column(uint8_t Row)
{
	if(!READ_COLUMN_1)                           //If COLUMN_1 is LOW
	{
		while(!READ_COLUMN_1);                   //Wait till Key is pressed 
		return Keypad_Button_Values[Row-1][0];   
	}

	if(!READ_COLUMN_2)                           //If COLUMN_2 is LOW  
	{
		while(!READ_COLUMN_2);                   //Wait till Key is pressed 
		return Keypad_Button_Values[Row-1][1];
	}

    if(!READ_COLUMN_3)                           //If COLUMN_3 is LOW
	{
		while(!READ_COLUMN_3);                   //Wait till Key is pressed 
		return Keypad_Button_Values[Row-1][2];
	}

	if(!READ_COLUMN_4)                           //If COLUMN_3 is LOW
	{
		while(!READ_COLUMN_4);                   //Wait till Key is pressed 
		return Keypad_Button_Values[Row-1][3];
	}

	return KEYPAD_NOT_PRESSED;                   //If NO Key is pressed 

}



/* Initialize the keypad */
void KEYPAD_Init(void)
{
	
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* ROW Ports Clock Enable */
	KEYPAD_ROW_1_PORT_CLK_ENABLE;
	KEYPAD_ROW_2_PORT_CLK_ENABLE;
	KEYPAD_ROW_3_PORT_CLK_ENABLE;
	KEYPAD_ROW_4_PORT_CLK_ENABLE;

  /* COLUMN Ports Clock Enable */
	KEYPAD_COLUMN_1_PORT_CLK_ENABLE;
	KEYPAD_COLUMN_2_PORT_CLK_ENABLE;
	KEYPAD_COLUMN_3_PORT_CLK_ENABLE;
	KEYPAD_COLUMN_4_PORT_CLK_ENABLE;
	
	/*Configure ROW pins Output Level - RESET all pins */
	SET_ROW_1_LOW;
	SET_ROW_2_LOW;
	SET_ROW_3_LOW;
	SET_ROW_4_LOW;
	
  /*Configure KEYPAD_ROW_1_PIN */
  GPIO_InitStruct.Pin = KEYPAD_ROW_1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KEYPAD_ROW_1_PORT, &GPIO_InitStruct);

  /*Configure KEYPAD_ROW_2_PIN */
  GPIO_InitStruct.Pin = KEYPAD_ROW_2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KEYPAD_ROW_2_PORT, &GPIO_InitStruct);
	
  /*Configure KEYPAD_ROW_3_PIN */
  GPIO_InitStruct.Pin = KEYPAD_ROW_3_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KEYPAD_ROW_3_PORT, &GPIO_InitStruct);	

  /*Configure KEYPAD_ROW_4_PIN */
  GPIO_InitStruct.Pin = KEYPAD_ROW_4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(KEYPAD_ROW_4_PORT, &GPIO_InitStruct);

  /*Configure KEYPAD_COLUMN_1_PIN */
  GPIO_InitStruct.Pin = KEYPAD_COLUMN_1_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COLUMN_1_PORT, &GPIO_InitStruct);

  /*Configure KEYPAD_COLUMN_2_PIN */
  GPIO_InitStruct.Pin = KEYPAD_COLUMN_2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COLUMN_2_PORT, &GPIO_InitStruct);
	
  /*Configure KEYPAD_COLUMN_3_PIN */
  GPIO_InitStruct.Pin = KEYPAD_COLUMN_3_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COLUMN_3_PORT, &GPIO_InitStruct);

  /*Configure KEYPAD_COLUMN_4_PIN */
  GPIO_InitStruct.Pin = KEYPAD_COLUMN_4_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_COLUMN_4_PORT, &GPIO_InitStruct);
	
}



/* Read the keypad */
char KEYPAD_Read(void)
{

    char check;
    /*Set ROW_1 LOW and scan all the columns*/
    Set_Keypad_Row(1);
    check = Check_Keypad_Column(1);
    if(check)
    	return check;

    /*Set ROW_2 LOW and scan all the columns*/
    Set_Keypad_Row(2);
    check = Check_Keypad_Column(2);
    if(check)
    	return check;
    /*Set ROW_3 LOW and scan all the columns*/
    Set_Keypad_Row(3);
    check = Check_Keypad_Column(3);
    if(check)
    	return check;
    /*Set ROW_4 LOW and scan all the columns*/
    Set_Keypad_Row(4);
    check = Check_Keypad_Column(4);
    if(check)
    	return check;

    /*Key not pressed */
    return KEYPAD_NOT_PRESSED;

}
	
	

																		 





