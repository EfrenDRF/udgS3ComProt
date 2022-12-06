/*
 * Can.c
 *
 *  Created on: 5 dic. 2022
 *      Author: Efren Del Real
 */

#include "Can.h"

/**************************************************************************************
 * Macro definition
 **************************************************************************************/




/*[SWS_Can_00103]*/
static Can_ControllerStateType Can_ControllerState    = CAN_CS_UNINIT;

/**************************************************************************************
 * Can_Init()
 **************************************************************************************/
void Can_Init( const Can_ConfigType * ConfigPtr )
{
	(void) ConfigPtr;

	if ( CAN_CS_UNINIT != Can_ControllerState )
	{
		/* RAISE CAN_E_TRANSITION */
	}
	else
	{

		/* [SWS_Can_00259] */
		Can_ControllerState = CAN_CS_STOPPED;

#	if ( 0 )
		for ( controller = 0x00u ; ( Can_NumberOfChannels > controller ); controller++ )
#	endif
		{

		}
	}

}

/**************************************************************************************
 * Can_DeInit()
 **************************************************************************************/
void Can_DeInit( void )
{
	/* [SWS_Can_91010] */
	Can_ControllerState = CAN_CS_UNINIT;
}

/**************************************************************************************
 * Can_SetBaudrate()
 **************************************************************************************/
Std_ReturnType Can_SetBaudrate( uint8 Controller , uint16 BaudRateConfigID )
{
	Std_ReturnType retVal;

	(void) Controller;
	(void) BaudRateConfigID;


	if ( CAN_CS_STOPPED != Can_ControllerState )
	{
		/* [SWS_CAN_00256] */
		retVal = E_NOT_OK;
	}
	else
	{
		/* [SWS_CAN_00260] */
		Can_ControllerState = CAN_CS_STOPPED;

		/* [SWS_CAN_00422] */
	}

	return retVal;
}

/**************************************************************************************
 * Can_SetControllerMode()
 **************************************************************************************/
Std_ReturnType Can_SetControllerMode( uint8 Controller , Can_ControllerStateType Transition )
{
	Std_ReturnType retVal;

	(void) Controller;

	switch ( Transition )
	{
		case CAN_CS_STARTED:
		{
			if ( CAN_CS_STOPPED != Can_ControllerState )
			{
				/* [SWS_CAN_00256] */
				/* raise CAN_E_TRANSITION */
				retVal = E_NOT_OK;
			}
		}break;
		case CAN_CS_STOPPED:
		{

		}break;
		
		default:
			break;
	}



	return retVal;
}

/**************************************************************************************
 * Can_MainFunction_Read()
 **************************************************************************************/
void Can_MainFunction_Read( void )
{

}

/**************************************************************************************
 * Can_MainFunction_Write()
 **************************************************************************************/
void Can_MainFunction_Write( void )
{

}
