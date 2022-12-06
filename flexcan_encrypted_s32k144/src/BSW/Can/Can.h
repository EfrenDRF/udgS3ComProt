/*
 * Can.h
 *
 *  Created on: 5 dic. 2022
 *      Author: Efren Del Real
 */

#ifndef BSW_CAN_CAN_H_
#define BSW_CAN_CAN_H_

#include "Can_GeneralTypes.h"

/**************************************************************************************
 * CAN Peripheral Access Layer
 **************************************************************************************/

/** CAN - Size of Registers Arrays */
#define CAN_RAMn_COUNT                           128u
#define CAN_RXIMR_COUNT                          32u
#define CAN_WMB_COUNT                            4u

/** CAN - Register Layout Typedef */
typedef struct {
  __IO uint32 MCR;                               /**< Module Configuration Register, offset: 0x0 */
  __IO uint32 CTRL1;                             /**< Control 1 register, offset: 0x4 */
  __IO uint32 TIMER;                             /**< Free Running Timer, offset: 0x8 */
       uint8 RESERVED_0[4];
  __IO uint32 RXMGMASK;                          /**< Rx Mailboxes Global Mask Register, offset: 0x10 */
  __IO uint32 RX14MASK;                          /**< Rx 14 Mask register, offset: 0x14 */
  __IO uint32 RX15MASK;                          /**< Rx 15 Mask register, offset: 0x18 */
  __IO uint32 ECR;                               /**< Error Counter, offset: 0x1C */
  __IO uint32 ESR1;                              /**< Error and Status 1 register, offset: 0x20 */
       uint8 RESERVED_1[4];
  __IO uint32 IMASK1;                            /**< Interrupt Masks 1 register, offset: 0x28 */
       uint8 RESERVED_2[4];
  __IO uint32 IFLAG1;                            /**< Interrupt Flags 1 register, offset: 0x30 */
  __IO uint32 CTRL2;                             /**< Control 2 register, offset: 0x34 */
  __I  uint32 ESR2;                              /**< Error and Status 2 register, offset: 0x38 */
       uint8 RESERVED_3[8];
  __I  uint32 CRCR;                              /**< CRC Register, offset: 0x44 */
  __IO uint32 RXFGMASK;                          /**< Rx FIFO Global Mask register, offset: 0x48 */
  __I  uint32 RXFIR;                             /**< Rx FIFO Information Register, offset: 0x4C */
  __IO uint32 CBT;                               /**< CAN Bit Timing Register, offset: 0x50 */
       uint8 RESERVED_4[44];
  __IO uint32 RAMn[CAN_RAMn_COUNT];              /**< Embedded RAM, array offset: 0x80, array step: 0x4 */
       uint8 RESERVED_5[1536];
  __IO uint32 RXIMR[CAN_RXIMR_COUNT];            /**< Rx Individual Mask Registers, array offset: 0x880, array step: 0x4 */
       uint8 RESERVED_6[512];
  __IO uint32 CTRL1_PN;                          /**< Pretended Networking Control 1 Register, offset: 0xB00 */
  __IO uint32 CTRL2_PN;                          /**< Pretended Networking Control 2 Register, offset: 0xB04 */
  __IO uint32 WU_MTC;                            /**< Pretended Networking Wake Up Match Register, offset: 0xB08 */
  __IO uint32 FLT_ID1;                           /**< Pretended Networking ID Filter 1 Register, offset: 0xB0C */
  __IO uint32 FLT_DLC;                           /**< Pretended Networking DLC Filter Register, offset: 0xB10 */
  __IO uint32 PL1_LO;                            /**< Pretended Networking Payload Low Filter 1 Register, offset: 0xB14 */
  __IO uint32 PL1_HI;                            /**< Pretended Networking Payload High Filter 1 Register, offset: 0xB18 */
  __IO uint32 FLT_ID2_IDMASK;                    /**< Pretended Networking ID Filter 2 Register / ID Mask Register, offset: 0xB1C */
  __IO uint32 PL2_PLMASK_LO;                     /**< Pretended Networking Payload Low Filter 2 Register / Payload Low Mask Register, offset: 0xB20 */
  __IO uint32 PL2_PLMASK_HI;                     /**< Pretended Networking Payload High Filter 2 low order bits / Payload High Mask Register, offset: 0xB24 */
       uint8 RESERVED_7[24];
  struct {                                         /* offset: 0xB40, array step: 0x10 */
    __I  uint32 WMBn_CS;                           /**< Wake Up Message Buffer Register for C/S, array offset: 0xB40, array step: 0x10 */
    __I  uint32 WMBn_ID;                           /**< Wake Up Message Buffer Register for ID, array offset: 0xB44, array step: 0x10 */
    __I  uint32 WMBn_D03;                          /**< Wake Up Message Buffer Register for Data 0-3, array offset: 0xB48, array step: 0x10 */
    __I  uint32 WMBn_D47;                          /**< Wake Up Message Buffer Register Data 4-7, array offset: 0xB4C, array step: 0x10 */
  } WMB[CAN_WMB_COUNT];
       uint8 RESERVED_8[128];
  __IO uint32 FDCTRL;                            /**< CAN FD Control Register, offset: 0xC00 */
  __IO uint32 FDCBT;                             /**< CAN FD Bit Timing Register, offset: 0xC04 */
  __I  uint32 FDCRC;                             /**< CAN FD CRC Register, offset: 0xC08 */
} CAN_MemMapRegType, *CAN_MemMapRegPtr;

 /** Number of instances of the CAN module. */
#define CAN_INSTANCE_COUNT                       (3u)


/* CAN - Peripheral instance base addresses */
/** Peripheral CAN0 base address */
#define CAN0_BASE                                (0x40024000u)
/** Peripheral CAN0 base pointer */
#define CAN0                                     ((CAN_MemMapRegType *)CAN0_BASE)
/** Peripheral CAN1 base address */
#define CAN1_BASE                                (0x40025000u)
/** Peripheral CAN1 base pointer */
#define CAN1                                     ((CAN_MemMapRegType *)CAN1_BASE)
/** Peripheral CAN2 base address */
#define CAN2_BASE                                (0x4002B000u)
/** Peripheral CAN2 base pointer */
#define CAN2                                     ((CAN_MemMapRegType *)CAN2_BASE)
/** Array initializer of CAN peripheral base addresses */
#define CAN_BASE_ADDRS                           { CAN0_BASE, CAN1_BASE, CAN2_BASE }
/** Array initializer of CAN peripheral base pointers */
#define CAN_BASE_PTRS                            { CAN0, CAN1, CAN2 }
 /** Number of interrupt vector arrays for the CAN module. */
#define CAN_IRQS_ARR_COUNT                       (7u)
 /** Number of interrupt channels for the Rx_Warning type of CAN module. */
#define CAN_Rx_Warning_IRQS_CH_COUNT             (1u)
 /** Number of interrupt channels for the Tx_Warning type of CAN module. */
#define CAN_Tx_Warning_IRQS_CH_COUNT             (1u)
 /** Number of interrupt channels for the Wake_Up type of CAN module. */
#define CAN_Wake_Up_IRQS_CH_COUNT                (1u)
 /** Number of interrupt channels for the Error type of CAN module. */
#define CAN_Error_IRQS_CH_COUNT                  (1u)
 /** Number of interrupt channels for the Bus_Off type of CAN module. */
#define CAN_Bus_Off_IRQS_CH_COUNT                (1u)
 /** Number of interrupt channels for the ORed_0_15_MB type of CAN module. */
#define CAN_ORed_0_15_MB_IRQS_CH_COUNT           (1u)
 /** Number of interrupt channels for the ORed_16_31_MB type of CAN module. */
#define CAN_ORed_16_31_MB_IRQS_CH_COUNT          (1u)
/** Interrupt vectors for the CAN peripheral type */
#define CAN_Rx_Warning_IRQS                      { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_Tx_Warning_IRQS                      { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_Wake_Up_IRQS                         { CAN0_Wake_Up_IRQn, NotAvail_IRQn, NotAvail_IRQn }
#define CAN_Error_IRQS                           { CAN0_Error_IRQn, CAN1_Error_IRQn, CAN2_Error_IRQn }
#define CAN_Bus_Off_IRQS                         { CAN0_ORed_IRQn, CAN1_ORed_IRQn, CAN2_ORed_IRQn }
#define CAN_ORed_0_15_MB_IRQS                    { CAN0_ORed_0_15_MB_IRQn, CAN1_ORed_0_15_MB_IRQn, CAN2_ORed_0_15_MB_IRQn }
#define CAN_ORed_16_31_MB_IRQS                   { CAN0_ORed_16_31_MB_IRQn, NotAvail_IRQn, NotAvail_IRQn }

typedef struct
{
    char dummy;
}Can_ConfigType;


/**************************************************************************************
 * Can_Init()
 **************************************************************************************/
/*
 *
 *
 * 
***************************************************************************************/
extern void Can_Init( const Can_ConfigType * ConfigPtr );

/**************************************************************************************
 * Can_DeInit()
 **************************************************************************************/
/*
 *
 *
 * 
***************************************************************************************/
extern void Can_DeInit( void );

/**************************************************************************************
 * Can_MainFunction_Read()
 **************************************************************************************/
/*
 *
 *
 * 
***************************************************************************************/
extern void Can_MainFunction_Read( void );

/**************************************************************************************
 * Can_MainFunction_Write()
 **************************************************************************************/
/*
 *
 *
 * 
***************************************************************************************/
extern void Can_MainFunction_Write( void );
#endif /* BSW_CAN_CAN_H_ */
