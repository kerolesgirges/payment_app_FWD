 /******************************************************************************
 *
 * Module: Terminal module
 *
 * Date_Creation: 2/28/2023
 * 
 * File Name: Terminal.h
 *
 * Description: Header file for terminal module
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/
#ifndef Terminal_h_
#define Terminal_h_

#include "std_types.h"
#include <stdio.h>
#include <string.h>
#include "Card.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define UserMaxAmount 8000

typedef struct ST_CardData_Terminal
{
    double Trans_amount_Float;
    //float Max_Trans_amount_Float;
    uint8 TransDate_uint8[9];
}ST_CardData_Terminal;


typedef enum EN_CardStatus_terminal
{
    Termi_OK,Card_EXPIRED,Transaction_amount_error,Below_Max_error
}EN_CardStatus_terminal;





/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/
void GetTransactionDate(ST_CardData_Terminal *Ptr_TermiData);
EN_CardStatus_terminal IsCardExpired(ST_CardData_Terminal *Ptr_TermiData,ST_user_card_data *CardData );

EN_CardStatus_terminal GetTransactionAmount(ST_CardData_Terminal *Ptr_TermiData);

EN_CardStatus_terminal ISBelowMax(ST_CardData_Terminal *Ptr_TermiData); 
void IsCardExpired_Test(void);

void GetTransactionAmount_Test(void);
void ISBelowMax_Test(void);
#endif
