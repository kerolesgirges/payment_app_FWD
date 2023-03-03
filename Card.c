 /******************************************************************************
 *
 * Module: CARD_Entering_Data 
 *
 * Date_Creation: 2/27/2023
 * 
 * File Name: CARD.c
 *
 * Description: get data from user and verifay it's ok and handling data to terminal module .
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/

#include "Card.h"


/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
EN_CardErrors getCardHolderName(ST_user_card_data *Ptr_cardData)
{

    setvbuf(stdout,0,_IONBF,0);
    uint8 CardNumLen_unit8;

    printf("please enter Card holder name letter between 20 to 25 charecter  \n" );
    fflush(stdout);
    gets(Ptr_cardData ->CardHolderNames_uint8);
    CardNumLen_unit8 = strlen(Ptr_cardData->CardHolderNames_uint8);
    if (CardNumLen_unit8<20 || CardNumLen_unit8>25 )
    /* function to check entered name length */
    {
        return WRONG_NAME;
    }

    for (uint8 i =0;i<CardNumLen_unit8;i++ )
    {

        if ((Ptr_cardData->CardHolderNames_uint8[i]>='a' &&Ptr_cardData->CardHolderNames_uint8[i]<='z')||(Ptr_cardData->CardHolderNames_uint8[i]>='A' &&Ptr_cardData->CardHolderNames_uint8[i]<='Z') )
        {
                continue;
        }
        else
        {
            return WRONG_NAME;
        }

    }

    return CARD_OK;
}

EN_CardErrors getCardExpiryData(ST_user_card_data *Ptr_cardData)
{
    printf("please enter your expiration Data in form 'MM/YY': \n");
    fflush(stdout);
    gets(Ptr_cardData->CardExpirDate_uint8);
    uint8 CardExp_Len_uint8 = strlen(Ptr_cardData->CardExpirDate_uint8);

    if (CardExp_Len_uint8 !=5)
    {
        return WRONG_EXP_DATE;
    }

    for (uint8 i =0 ;i<CardExp_Len_uint8;i++)
    {
        if ((Ptr_cardData->CardExpirDate_uint8[0] =='0'&&(Ptr_cardData->CardExpirDate_uint8[1]>='1'&&Ptr_cardData->CardExpirDate_uint8[1]<='9'))
            ||
            (Ptr_cardData->CardExpirDate_uint8[0]=='1' &&(Ptr_cardData->CardExpirDate_uint8[1]>='0'&&Ptr_cardData->CardExpirDate_uint8[1]<='2'))
            &&
            Ptr_cardData->CardExpirDate_uint8[2]=='/'
            &&
            Ptr_cardData->CardExpirDate_uint8[3]>='0'&&Ptr_cardData->CardExpirDate_uint8[3]<='9'
            &&
            Ptr_cardData->CardExpirDate_uint8[4]>='0'&&Ptr_cardData->CardExpirDate_uint8[4]<='9'
            )

        {
            continue;
        }
        else
        {
            return WRONG_EXP_DATE;
        }



    }
    return CARD_OK;
}



EN_CardErrors getCardPAN(ST_user_card_data *Ptr_cardData)
{

printf ("please  enter you card number without spaces :\n ");
gets(Ptr_cardData->CardPan_uint8);
uint8 CardPan_Len_uint8 = strlen(Ptr_cardData->CardPan_uint8);

if (CardPan_Len_uint8 <16 ||CardPan_Len_uint8>19){
    return WRONG_PAN;
}
for (uint8 i=0;i<CardPan_Len_uint8;i++)
{
    if (Ptr_cardData->CardPan_uint8[i] >='0'&&Ptr_cardData->CardPan_uint8[i] <='9')
    {
        continue;
    }
    else 
    {
        return WRONG_PAN;
    }

}
return CARD_OK;

}

void getCardHolderName_test(void)

{
    ST_user_card_data CardData;
    ST_user_card_data *Ptr_UserCardData = &CardData;
    setvbuf(stdout,0,_IONBF,0);
    printf("Tester name        :keroles girges \n");
    printf("Function test name :getCardHolderName_test\n");

    for (uint8 i =1 ; i<= 4;i++)
    {
        printf("***************************************************\n" );
        printf("start getCardHolderName Test case number : %d \n",i );

        switch (i)
        {
        case(1):
            printf("Expected input :name less than 20 charecter \n");
            printf("Expected output:WRONG_NAME \n");
            break;
        case(2):
            printf("Expected input :name more than 25 charecter \n");
            printf("Expected output:WRONG_NAME \n");
            break;
        case(3):
            printf("Expected input :name have number in it \n");
            printf("Expected output:WRONG_NAME \n");
            break;
        case(4):
            printf("Expected input :real name  \n");
            printf("Expected output:Card_OK \n");
            break;        
        }
        uint8   Function_Test_output   =getCardHolderName(Ptr_UserCardData);
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resual : card name ok \n");
            break;

        case(1):
            printf("autual resual : card name error \n");
            break;
            
        }
    printf("End getCardHolderName Test case number : %d \n",i );
    printf("***************************************************\n" );
    
    }

}




void getCardExpiryDate_test(void)

{
    ST_user_card_data CardData;
    ST_user_card_data *Ptr_UserCardData = &CardData;
    printf("hi this's start\n");
    printf("Tester name        :keroles girges \n");
    printf("Function test name :getCardExpiryDate_test\n");

    for (uint8 i =1 ; i<=5;i++)
    {

        printf("start getCardExpiryDate Test case number : %d \n",i );

        switch (i)
        {
        case(1):
            printf("Expected input :enter month more than 12  \n");
            printf("Expected output:WRONG_ExpiryDate \n");
            break;
        case(2):
            printf("Expected input :enter letters in month  \n");
            printf("Expected output:WRONG_ExpiryDate \n");
            break;
        case(3):
            printf("Expected input : enter more than five charcters  \n");
            printf("Expected output:WRONG_ExpiryDate \n");
            break;
        case(4):
            printf("Expected input :enter '-' insted of / in expiry date  \n");
            printf("Expected output:WRONG_ExpiryDate \n");
            break;     
        case(5):
            printf("Expected input :enterexpiry date without errors    \n");
            printf("Expected output:Card ok  \n");
            break;      
        }
        uint8   Function_Test_output =getCardExpiryData(Ptr_UserCardData);
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resual : card expiry date ok \n");
            break;

        case(2):
            printf("autual resual : card expiry date error \n");
            break;
            
        }
    printf("End getCardExpiryDate Test case number : %d \n",i );
    
    }

}


void getCardPAN_test(void)

{
    ST_user_card_data CardData;
    ST_user_card_data *Ptr_UserCardData = &CardData;

    printf("Tester name        :keroles girges \n");
    printf("Function test name :getCardPAN_test\n");

    for (uint8 i =1 ; i<=5;i++)
    {

        printf("start getCardPAN_test Test case number : %d \n",i );

        switch (i)
        {
        case(1):
            printf("Expected input :enter PAN less than 16  \n");
            printf("Expected output:WRONG_PAN \n");
            break;
        case(2):
            printf("Expected input :enter PAN more than 19  \n");
            printf("Expected output:WRONG_PAN \n");
            break;
        case(3):
            printf("Expected input : enter LETTERS IN PAN numer  \n");
            printf("Expected output:WRONG_PAN \n");
            break;
        case(4):
            printf("Expected input :enter ok PAN number   \n");
            printf("Expected output:Card ok  \n");
            break;     
           
        }
        uint8   Function_Test_output=getCardPAN(Ptr_UserCardData);
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resual : card PAN ok \n");
            break;

        case(3):
            printf("autual resual : card PAN error \n");
            break;
            
        }
    printf("End getCardPAN_test Test case number : %d \n",i );
    
    }

}

