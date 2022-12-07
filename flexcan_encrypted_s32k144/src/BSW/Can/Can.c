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
#define Can_GetCanCtrlBaseAdr( idx )		( ( Can_MemMapRegPtrType ) Can_ControllerConfig[ idx ].baseAdr )
#define Can_GetCanNumMsgBuff( idx )			( Can_ControllerConfig[ idx ].numMsgBuff )



/*[SWS_Can_00103]*/
static Can_ControllerStateType Can_DriverState    = CAN_CS_UNINIT;


/**************************************************************************************
 * Can_ClearRAM()
 **************************************************************************************/
static void Can_ClearRAM( uint8 controller )
{
    uint32 databyte;
    uint32 RAM_size =  Can_GetCanNumMsgBuff( controller ) * 4U;
	const Can_MemMapRegPtrType Can_MemMapRegPtr = Can_GetCanCtrlBaseAdr( controller );

    /* Clear MB region */
    for ( databyte = 0x00u; ( RAM_size > databyte ); databyte++)
	{
        Can_MemMapRegPtr->RAMn[ databyte ] = 0x00u;
    }

    /* Clear RXIMR region */
    for ( databyte = 0; ( Can_GetCanNumMsgBuff( controller ) > databyte ); databyte++ ) 
	{
        Can_MemMapRegPtr->RXIMR[ databyte ] = 0x00u;
    }
}

/**************************************************************************************
 * Can_SetRegisterInit()
 **************************************************************************************/
static void Can_SetRegisterInit( uint8 controller )
{
	const Can_MemMapRegPtrType Can_MemMapRegPtr = Can_GetCanCtrlBaseAdr( controller );

    /* Reset the CAN */
    Can_MemMapRegPtr->MCR = ( Can_MemMapRegPtr->MCR & ~CAN_MCR_SOFTRST_MASK ) | CAN_MCR_SOFTRST(1U);

    /* Wait for reset cycle to complete */
    while ((( Can_MemMapRegPtr->MCR & CAN_MCR_SOFTRST_MASK) >> CAN_MCR_SOFTRST_SHIFT) != 0U) {}

    /* Clear CAN peripheral memory */
    Can_ClearRAM( controller );

    /* Rx global mask*/
    Can_MemMapRegPtr->RXMGMASK = (uint32)(CAN_RXMGMASK_MG_MASK);

    /* Rx reg 14 mask*/
    Can_MemMapRegPtr->RX14MASK =  (uint32)(CAN_RX14MASK_RX14M_MASK);

    /* Rx reg 15 mask*/
    Can_MemMapRegPtr->RX15MASK = (uint32)(CAN_RX15MASK_RX15M_MASK);

    /* Disable all MB interrupts */
    Can_MemMapRegPtr->IMASK1 = 0x0;

    /* Clear all MB interrupt flags */
    Can_MemMapRegPtr->IFLAG1 = CAN_IMASK1_BUF31TO0M_MASK;

    /* Clear all error interrupt flags */
    Can_MemMapRegPtr->ESR1 = Can_ESR1InitAll;
}

/**************************************************************************************
 * Can_Init()
 **************************************************************************************/
void Can_Init( const Can_ConfigType * ConfigPtr )
{
	(void) ConfigPtr;

	if ( CAN_CS_UNINIT != Can_DriverState )
	{
		/* RAISE CAN_E_TRANSITION */
	}
	else
	{


		for ( uint8 controller = 0x00u ; ( Can_NumberOfControles > controller ); controller++ )
		{
			/* [SWS_Can_00259] */
			Can_ControllerState[ controller ] = CAN_CS_STOPPED;

			Can_SetRegisterInit( controller );

		}
	}

}

/**************************************************************************************
 * Can_DeInit()
 **************************************************************************************/
void Can_DeInit( void )
{
	/* [SWS_Can_91010] */
	Can_DriverState = CAN_CS_UNINIT;


	for ( uint8 controller = 0x00u ; ( Can_NumberOfControles > controller ); controller++ )
	{
		Can_ControllerState[ controller ] = CAN_CS_STOPPED;
	}
}

/**************************************************************************************
 * Can_SetBaudrate()
 **************************************************************************************/
Std_ReturnType Can_SetBaudrate( uint8 Controller , uint16 BaudRateConfigID )
{
	Std_ReturnType retVal;

	(void) Controller;
	(void) BaudRateConfigID;


	if ( CAN_CS_STOPPED != Can_DriverState )
	{
		/* [SWS_CAN_00256] */
		retVal = E_NOT_OK;
	}
	else
	{
		/* [SWS_CAN_00260] */
		Can_DriverState = CAN_CS_STOPPED;

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
			if ( CAN_CS_STOPPED != Can_DriverState )
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
