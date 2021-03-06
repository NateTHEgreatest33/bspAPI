/*********************************************************************
*
*   HEADER:
*       header file for bspAPI
*
*   Copyright 2020 Nate Lenze
*
*********************************************************************/

/*--------------------------------------------------------------------
                           GENERAL INCLUDES
--------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>

/*--------------------------------------------------------------------
                          LITERAL CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                TYPES
--------------------------------------------------------------------*/
typedef uint8_t LED_colors;        /* LED color list */
enum
    {
    OFF,                                     /* 0x00 */
    RED,                                     /* 0x01 */
    BLUE,                                    /* 0x02 */
    PINK,                                    /* 0x03 */
    GREEN,                                   /* 0x04 */
    YELLOW,                                  /* 0x05 */
    TEAL,                                    /* 0x06 */
    WHITE                                    /* 0x07 */
    };

typedef uint8_t button_state;   /* state of buttons  */
enum
    {
    button_ENABLED,             /* button pushed     */
    button_DISABLED             /* button not pushed */
    };

typedef uint8_t button;         /* state of buttons */
enum
    {
    L_BUTTON,                   /* left button      */
    R_BUTTON                    /* right button     */
    };

/*--------------------------------------------------------------------
                           MEMORY CONSTANTS
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                              VARIABLES
--------------------------------------------------------------------*/

/*--------------------------------------------------------------------
                                MACROS
--------------------------------------------------------------------*/

/*----------------------------------------------------ß----------------
                              PROCEDURES
--------------------------------------------------------------------*/
/*--------------------------------------------------------------------
bspAPI.c
--------------------------------------------------------------------*/
void bsp_Init
    (
    void
    );

void bsp_LED
    (
    LED_colors color /* color selected */
    );

button_state bsp_button_state
    (
    button button; /* button selected */
    );
/* bspAPI.h */
