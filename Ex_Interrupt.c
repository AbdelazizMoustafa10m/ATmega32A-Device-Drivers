/*
 * Ex_Interrupt.c
 *
 * Created: 1/20/2020 9:16:21 PM
 *  Author: Abdelaziz
 */ 

#include "EX_Interrupts.h"

void Ex_Interrupt_Enable(interrupt_source Source, interrupt_mode Mode)
{
	switch(Source)
	{
		case INTERRUPT0 :
			/* Disable Interrupt */
			GICR->Bits.b6=0;
			/* Configure Interrupt */
			switch(Mode)
			{
				case RISINGMODE :
									MCUCR->Bits.b0=1;
									MCUCR->Bits.b1=1;
									break;
				case FALLINGMODE :
									MCUCR->Bits.b0=0;
									MCUCR->Bits.b1=1;
									break;
				case LOWLEVELMODE :
									MCUCR->Bits.b0=0;
									MCUCR->Bits.b1=0;
									break;
				case EDGETRIG :
									MCUCR->Bits.b0=1;
									MCUCR->Bits.b1=0;
									break;
				default:
									break;
			}
			/* Clear Flags */
			GIFR->Bits.b6=1;
			/* Enable Interrupt */
			GICR->Bits.b6=1;
			break;
		case INTERRUPT1 :
				/* Disable Interrupt */
				GICR->Bits.b7=0;
				/* Configure Interrupt */
				switch(Mode)
				{
					case RISINGMODE :
										MCUCR->Bits.b2=1;
										MCUCR->Bits.b3=1;
										break;
					case FALLINGMODE :
										MCUCR->Bits.b2=0;
										MCUCR->Bits.b3=1;
										break;
					case LOWLEVELMODE :
										MCUCR->Bits.b2=0;
										MCUCR->Bits.b3=0;
										break;
					case EDGETRIG :
										MCUCR->Bits.b2=1;
										MCUCR->Bits.b3=0;
										break;
					default:
									    break;
			}
			/* Clear Flags */
			GIFR->Bits.b7=1;
			/* Enable Interrupt */
			GICR->Bits.b7=1;
		    break;
			
		case INTERRUPT2 :
			/* Disable Interrupt */
			GICR->Bits.b5=0;
			/* Configure Interrupt */
			switch(Mode)
			{
				case RISINGMODE :
										MCUCSR->Bits.b6=1;
										break;
				case FALLINGMODE :
										MCUCSR->Bits.b6=0;
										break;
				default:
										break;
			}
			/* Clear Flags */
			GIFR->Bits.b5=1;
			/* Enable Interrupt */
			GICR->Bits.b5=1;
			break;
		default:
			break;
	}
	
}
void Ex_Interrupt_Disable(interrupt_source Source)
{
	switch(Source)
	{
		case INTERRUPT0 :
							MCUCR->Bits.b6=0;
							break;
		case INTERRUPT1 :
							MCUCR->Bits.b7=0;
							break;
		case INTERRUPT2 :
							MCUCR->Bits.b5=0;
							break;
		default:
							break;
	}
}
void Global_Interrupt_Enable(void)
{
	SREG->Bits.b7=1;
}
void Global_Interrupt_Disable(void)
{
	SREG->Bits.b7=0;
}