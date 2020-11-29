/*********************************************************************
*
*   NAME:
*       bspAPI.c
*
*   DESCRIPTION:
*       Board Support Packet for interfacing Tiva Launchpad
*
*   Copyright 2020 Nate Lenze
*
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include "bspAPI.h"

#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/
#define L_BUTTON_MASK 0x10
#define R_BUTTON_MASK 0x00
#define LED_MASK 0x0E
/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/
static bool initilized = false;   /* has init function been run yet */
/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              PROCEDURES
--------------------------------------------------------------------*/

/*********************************************************************
*
*   PROCEDURE NAME:
*       bspInit()
*
*   DESCRIPTION:
*       Initilaize LED and push buttons
*
*********************************************************************/
void bsp_Init
    (
    void
    )
{
//init
initilized = true;
} /* bsp_Init() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       bsp_LED()
*
*   DESCRIPTION:
*       toggle LED
*
*********************************************************************/
void bsp_LED
    (
    LED_colors color
    )
{
/*----------------------------------------------------------
Verify bspInit() has been run
----------------------------------------------------------*/
if( initilized == true )
    {
    /*--------------------------------------------------
    shift color over by one to fit in LED_MASK portion
    of register
    --------------------------------------------------*/
    GPIO_PORTF_BASE |= ( ( uint8_t ) color << 1 );
    }
} /* bsp_LED() */

/*********************************************************************
*
*   PROCEDURE NAME:
*       bsp_button_state()
*
*   DESCRIPTION:
*       get current state of buttons
*
*********************************************************************/
button_state bsp_button_state
    (
    button button; /* button selected */
    )
{
/*----------------------------------------------------------
Verify bspInit() has been run
----------------------------------------------------------*/
if( initilized == true )
    {
    switch ( button )
        {
        case L_BUTTON:
            if ( ( GPIO_PORTF_BASE & L_BUTTON_MASK ) == L_BUTTON_MASK )
                {
                return button_ENABLED;
                }
            else
                {
                return button_DISABLED;
                }
            break;
        case R_BUTTON:
            if ( ( GPIO_PORTF_BASE & R_BUTTON_MASK ) == R_BUTTON_MASK )
                {
                return button_ENABLED;
                }
            else
                {
                return button_DISABLED;
                }
            break;
        default:
            /* error case */
            break;
        }
    }
} /* bsp_button_state() */