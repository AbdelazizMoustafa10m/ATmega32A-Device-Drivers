/*
 * EX_Interrupts.h
 *
 * Created: 1/20/2020 8:53:25 PM
 *  Author: Abdelaziz
 */ 


#ifndef EX_INTERRUPTS_H_
#define EX_INTERRUPTS_H_

#include "Micro_Config.h"

/* Have Flags That Control The TRIGGER Event of INT0,INT1 */
#define MCUCR		((Reg8 *)(0x35+IO_OFFSET))		     /* MCUCR */
/* Have Flags That Control The TRIGGER Event of INT2 */
#define MCUCSR	    ((Reg8 *)(0x34+IO_OFFSET))		     /* MCUCSR */
/* have Flags That Enable/Disable INT0 , INT1 and INT2 */
#define GICR	    ((Reg8 *)(0x3B+IO_OFFSET))		     /* GICR */
/* Have The Flags That indicate , that the Event has occurred */
#define GIFR	    ((Reg8 *)(0x3A+IO_OFFSET))           /* GIFR */


typedef enum {RISINGMODE, FALLINGMODE, LOWLEVELMODE, EDGETRIG}interrupt_mode;
typedef enum {INTERRUPT0, INTERRUPT1, INTERRUPT2}interrupt_source;

/*this function will be used to ENABLE a certain interrupt in a certain mode*/
void Ex_Interrupt_Enable(interrupt_source Source, interrupt_mode Mode);
/*this function will be used to DISABLE a certain interrupt*/
void Ex_Interrupt_Disable(interrupt_source Source);
/*this function will be used to ENABLE the GLOBAL INNTERRUPT FLAG*/
void Global_Interrupt_Enable(void);
/*this function will be used to DISABLE the GLOBAL INTERRUPT FLAG*/
void Global_Interrupt_Disable(void);



#endif /* EX_INTERRUPTS_H_ */