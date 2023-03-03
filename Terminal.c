 /******************************************************************************
 *
 * Module: Terminal module
 *
 * Date_Creation: 2/28/2023
 * 
 * File Name: Terminal.c
 *
 * Description: Termainal_get data from card module and alalyse it send its data to server.
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/
#include "Terminal.h"
//#include "Card.h"
/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
void GetTransactionDate(ST_CardData_Terminal *Ptr_TermiData)
{
   time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    uint8 Date_time_uint8[10];
    strftime(Date_time_uint8, sizeof(Date_time_uint8), "%m/%y", tm);
    //assert(ret);
    //printf("%s\n", s);
    //Date_time_uint8[8]='\0';
    printf("today date is : %s\n", Date_time_uint8);
    strcpy(Ptr_TermiData->TransDate_uint8,Date_time_uint8);
    
    //return Date_time_uint8;
    
}


EN_CardStatus_terminal IsCardExpired(ST_CardData_Terminal *Ptr_TermiData,ST_user_card_data *CardData )
{
    //check year
    if ((CardData->CardExpirDate_uint8 [3] < Ptr_TermiData->TransDate_uint8 [3])
        ||
        ((CardData->CardExpirDate_uint8 [3] == Ptr_TermiData->TransDate_uint8 [3])&&(CardData->CardExpirDate_uint8 [4] < Ptr_TermiData->TransDate_uint8 [4]) )
        )
    {
printf("%c",Ptr_TermiData->TransDate_uint8 [3]);
        return Card_EXPIRED;
    }
    //check month if year are same 
    if((CardData->CardExpirDate_uint8 [3] == Ptr_TermiData->TransDate_uint8 [3])&&(CardData->CardExpirDate_uint8 [4] == Ptr_TermiData->TransDate_uint8 [4]))
    {
    	if ((CardData->CardExpirDate_uint8 [0] == Ptr_TermiData->TransDate_uint8 [0]))

    	{
    		if ((CardData->CardExpirDate_uint8 [1] < Ptr_TermiData->TransDate_uint8 [1]))
    		{
    			//printf("%c",CardData->CardExpirDate_uint8 [0]);
    			//printf("%c",Ptr_TermiData->TransDate_uint8 [0]);
    			//printf("%c",CardData->CardExpirDate_uint8 [1]);
    			//printf("%c",Ptr_TermiData->TransDate_uint8 [1]);
    			//printf("here 1\n");
    			return Card_EXPIRED;
    		}
    	}
    }
    /*if ((CardData->CardExpirDate_uint8 [0] < Ptr_TermiData->TransDate_uint8 [0]))
    {
    	printf("here 2\n");
        
            return Card_EXPIRED;
        
    }
*/
return Termi_OK;

}

EN_CardStatus_terminal GetTransactionAmount(ST_CardData_Terminal *Ptr_TermiData)
{
	float UserMaxInput =UserMaxAmount;
	//printf("%f",koko);
    printf("please input needed ammount below %.2lf : \n",UserMaxInput);

    scanf("%lf",&(Ptr_TermiData->Trans_amount_Float));
    //printf("here amonunt1 \n");
    if (Ptr_TermiData->Trans_amount_Float <=0 ) 
    {
    	//printf("here amonunt2 \n");
        return Transaction_amount_error;
    }

    return Termi_OK;


} 

EN_CardStatus_terminal ISBelowMax(ST_CardData_Terminal *Ptr_TermiData)
{
   // ST_CardData_Terminal->Max_Trans_amount_Float = UserMaxAmount;


    if (Ptr_TermiData->Trans_amount_Float > UserMaxAmount)
    {
    	//printf("no goooood ");
        return Below_Max_error;
    }

    return Termi_OK;

}


void IsCardExpired_Test(void){

    ST_CardData_Terminal TermiData;
    ST_CardData_Terminal *Ptr_UserTermiData = &TermiData;
    ST_user_card_data CardData;
        ST_user_card_data *Ptr_UserCardData = &CardData;
    printf("Tester name        :keroles girges \n");
    printf("Function test name :IsCardExpired_test\n");

      for (uint8 FuCounter =1 ; FuCounter<= 4;FuCounter++)
    {

        printf("***************************************************\n" );
        printf("start IsCardExpired Test case number : %d \n",FuCounter );

        switch (FuCounter)
        {
        case(1):
            printf("Expected input :input expire date last year \n");
            printf("Expected output:Card_expired \n");
            break;
        case(2):
            printf("Expected input :input expire date this year put last month \n");
            printf("Expected output:Card_expired\n");
            break;
        case(3):
            printf("Expected input :input expire date this year next month \n");
            printf("Expected output:Card_ok \n");
            break;
        case(4):
            printf("Expected input :input expire date this next year any month  \n");
            printf("Expected output:Card_OK \n");
            break;        
        }
        uint8   Function_Test_output   =IsCardExpired(Ptr_UserTermiData,Ptr_UserCardData );
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resualt : card ok \n");
            break;

        case(1):
            printf("autual resualt : card expired error \n");
            break;
            
        }
    printf("End IsCardExpired Test case number : %d \n",FuCounter );
    printf("***************************************************\n" );
    }


}

void GetTransactionAmount_Test(void){

    ST_CardData_Terminal TermiData;
    ST_CardData_Terminal *Ptr_UserTermiData = &TermiData;

    printf("Tester name        :keroles girges \n");
    printf("Function test name :GetTransactionAmount_Test\n");

      for (uint8 FuCounter =1 ; FuCounter<=3;FuCounter++)
    {
        
        printf("***************************************************\n" );
        printf("start GetTransactionAmount , Test case number : %d \n",FuCounter );

        switch (FuCounter)
        {
        case(1):
            printf("Expected input :input amount = 0 \n");
            printf("Expected output:Card_unout_amount_error \n");
            break;
        case(2):
            printf("Expected input :input amount less than zero \n");
            printf("Expected output:Card_unout_amount_error\n");
            break;
        case(3):
            printf("Expected input :input amount more than zero  \n");
            printf("Expected output:Card_ok \n");
            break;
        
        }
        uint8   Function_Test_output   =GetTransactionAmount(Ptr_UserTermiData);
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resualt : card ok \n");
            break;

        case(1):
            printf("autual resualt : card amount error \n");
            break;
            
        }
    printf("End GetTransactionAmount Test case number : %d \n",FuCounter );
    printf("***************************************************\n" );
    }


}


void ISBelowMax_Test(void){

    ST_CardData_Terminal TermiData;
    ST_CardData_Terminal *Ptr_UserTermiData = &TermiData;

    printf("Tester name        :keroles girges \n");
    printf("Function test name :ISBelowMax_Test\n");

      for (uint8 FuCounter =1 ; FuCounter<=2;FuCounter++)
    {
        
        printf("***************************************************\n" );
        printf("start ISBelowMax , Test case number : %d \n",FuCounter );

        switch (FuCounter)
        {
        case(1):
            printf("Expected input :input amount more than : %c \n",UserMaxAmount);
            printf("Expected output:Card_max_amount_error \n");
            break;
        case(2):
            printf("Expected input :input amount less than : %c \n",UserMaxAmount);
            printf("Expected output:Card_max_amount_ok \n");
            break;
        }
        uint8   Function_Test_output   =ISBelowMax(Ptr_UserTermiData);
        switch(Function_Test_output)
        {
        case(0):
            printf("autual resualt : card max amount ok  \n");
            break;

        case(1):
            printf("autual resualt : card max amount error \n");
            break;
            
        }
    printf("End ISBelowMax Test case number : %d \n",FuCounter );
    printf("***************************************************\n" );
    }


}

