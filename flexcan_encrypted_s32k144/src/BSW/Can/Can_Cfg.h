/*
 * Can_Cfg.h
 *
 *  Created on: 6 dic. 2022
 *      Author: Efren Del Real
 */

#ifndef BSW_CAN_CAN_CFG_H_
#define BSW_CAN_CAN_CFG_H_

#include "Can_GeneralTypes.h"

#define Can_NumberOfControles                ( 0x03u )


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define Can_PeriphBaseAdrCan0                  ( 0x40024000u )
/** Peripheral CAN1 base address */
#define Can_PeriphBaseAdrCan1                  ( 0x40025000u )
/** Peripheral CAN2 base address */
#define Can_PeriphBaseAdrCan2                  ( 0x4002B000u )

/* 46.1.3 Number of Messsage buffers */
#define Can_NumMsgBuffCan0                  ( 0x20u )
#define Can_NumMsgBuffCan1                  ( 0x10u )
#define Can_NumMsgBuffCan2                  ( 0x10u )


#define Can_ESR1InitAll                      ( 0x3B0006u )    /*!< Masks for wakeup, error, bus off*/

typedef struct 
{
    uint32                          baseAdr;
    uint8                           numMsgBuff;
}Can_ControllerConfigType;



extern const Can_ControllerConfigType Can_ControllerConfig[ Can_NumberOfControles ];


extern Can_ControllerStateType Can_ControllerState[ Can_NumberOfControles ];


#endif /* BSW_CAN_CAN_CFG_H_ */
