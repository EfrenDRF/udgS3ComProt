/*
 * Can_Cfg.c
 *
 *  Created on: 6 dic. 2022
 *      Author: Efren Del Real
 */

#include "Can_Cfg.h"



const Can_ControllerConfigType Can_ControllerConfig[ Can_NumberOfControles ] =
{
    { .baseAdr = Can_PeriphBaseAdrCan0  , .numMsgBuff = Can_NumMsgBuffCan0  } ,
    { .baseAdr = Can_PeriphBaseAdrCan1  , .numMsgBuff = Can_NumMsgBuffCan1  } ,
    { .baseAdr = Can_PeriphBaseAdrCan2  , .numMsgBuff = Can_NumMsgBuffCan2  }
};

Can_ControllerStateType Can_ControllerState[ Can_NumberOfControles ];
