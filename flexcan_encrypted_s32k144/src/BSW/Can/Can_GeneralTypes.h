/*
 * Can_GeneralTypes.h
 *
 *  Created on: 5 dic. 2022
 *      Author: Efren Del Real
 */

#ifndef BSW_CAN_CAN_GENERALTYPES_H_
#define BSW_CAN_CAN_GENERALTYPES_H_

#include "StandardTypes.h"

#ifndef __IO
#	define	__IO			volatile
#endif

#ifndef __I
#	define __I				volatile
#endif

/* [SWS_CAN_00416] */
typedef uint32				Can_IdType;

/* [SWS_CAN_00429] */
typedef uint8				Can_HwHandleType;

/* [SWS_CAN_00496] */
typedef struct
{
	Can_IdType				CanId;
	Can_HwHandleType		Hoh;
	uint8					ControllerId;
}Can_HwType;


/* [SWS_CAN_91013] */
typedef enum
{
	CAN_CS_UNINIT			= 0x00u ,
	CAN_CS_STARTED			= 0x01u ,
	CAN_CS_STOPPED			= 0x02u ,
	CAN_CS_SLEEP			= 0x03u
}Can_ControllerStateType;

#endif /* BSW_CAN_CAN_GENERALTYPES_H_ */
