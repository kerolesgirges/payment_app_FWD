 /******************************************************************************
 *
 * Module: CARD_Entering_Data 
 *
 * Date_Creation: 2/27/2023
 * 
 * File Name: CARD.h
 *
 * Description: Header file for card module
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/
#ifndef CARD_h_
#define CARD_h_


#include "std_types.h"
#include <stdio.h>
#include <string.h>


/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
typedef struct ST_user_card_data
{
    uint8 CardHolderNames_uint8 [25];
    uint8 CardExpirDate_uint8[6];
    uint8 CardPan_uint8[19];
    
}ST_user_card_data;

typedef enum name
{
    CARD_OK,WRONG_NAME,WRONG_EXP_DATE,WRONG_PAN
}EN_CardErrors;





 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
EN_CardErrors getCardHolderName(ST_user_card_data *CardData);
EN_CardErrors getCardExpiryData(ST_user_card_data *CardData);
EN_CardErrors getCardPAN(ST_user_card_data *CardData);
void getCardHolderName_test (void);
void getCardExpiryDate_test (void);
void getCardPAN_test (void);










#endif /* CARD_H_ */
