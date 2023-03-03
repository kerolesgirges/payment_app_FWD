 /******************************************************************************
 *
 * Module: CARD_Main 
 *
 * Date_Creation: 2/28/2023
 * 
 * File Name: Application.c
 *
 * Description: main file for payment app program
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/

#include "Card.h"
#include "Terminal.h"
#include "Server.h"

int main(void)
{
    uint8 CardFeedBack_uint8=0;
    uint8 TerminalFeedBack_uint8=0;
    uint8 ServerFeedBack_uint8=0;


    ST_user_card_data CardData;
    ST_user_card_data *Ptr_UserCardData = &CardData;

    ST_CardData_Terminal termi_data;
    ST_CardData_Terminal *Ptr_TermiData= &termi_data;

    while(1)
    {
    	//-------------------Start_Card_Side------------------------------------
        CardFeedBack_uint8= getCardHolderName(Ptr_UserCardData);
        
        while(CardFeedBack_uint8 ==WRONG_NAME )
        {
        	printf("WRONG_NAME \n");
            CardFeedBack_uint8= getCardHolderName(Ptr_UserCardData);
        }
        
        CardFeedBack_uint8=getCardExpiryData(Ptr_UserCardData);
        
        while(CardFeedBack_uint8==WRONG_EXP_DATE)
        {
        	printf("WRONG_Expiration date \n");
            CardFeedBack_uint8=getCardExpiryData(Ptr_UserCardData);
        }

        CardFeedBack_uint8=getCardPAN(Ptr_UserCardData);
        while(CardFeedBack_uint8==WRONG_PAN)
        {
        	printf("WRONG_PAN \n");
            CardFeedBack_uint8=getCardPAN(Ptr_UserCardData);
        }
        CardFeedBack_uint8=CARD_OK;

        //-------------------End_Card_Side------------------------------------

        //*******************Start_terminal_side------------------------------
        GetTransactionDate(Ptr_TermiData);
        TerminalFeedBack_uint8= IsCardExpired(Ptr_TermiData,Ptr_UserCardData);

        if (TerminalFeedBack_uint8== Card_EXPIRED)
        {
        	printf("EXPIRED_CARD \n");
        	printf("Bye....Bye \n");
        	break;
        	//TerminalFeedBack_uint8= IsCardExpired(Ptr_TermiData,Ptr_UserCardData );
        }

        TerminalFeedBack_uint8=GetTransactionAmount(Ptr_TermiData);

        while(TerminalFeedBack_uint8==Transaction_amount_error)
        {
        	printf("invalid amount input amount below %f\n",UserMaxAmount);
		TerminalFeedBack_uint8=GetTransactionAmount(Ptr_TermiData);

        }

        printf("here input amonunt1 \n");
        TerminalFeedBack_uint8=ISBelowMax(Ptr_TermiData);
        printf("here input amonunt2 \n");
        while(TerminalFeedBack_uint8==Below_Max_error)
        {
        	printf("EXCEED_max_AMOUNT\n");
        	TerminalFeedBack_uint8=GetTransactionAmount(Ptr_TermiData);
        }
        TerminalFeedBack_uint8=Termi_OK;
        printf("TERMINAL_OK \n");
        printf ("*********************************** \n");

        //*******************End_terminal_side------------------------------

        //*******************start_server_side------------------------------
        //ST_user_card_data ServerData;
        ST_user_card_data *Ptr_ServerData =&CardData;
        ST_user_Server_data User_server_data;
        ST_user_Server_data *Ptr_User_server_data=&User_server_data;
        ServerFeedBack_uint8 = IsValidAccount( Ptr_ServerData ,Ptr_User_server_data , ST_Acount_data);

        if (ServerFeedBack_uint8 ==notValid_account )
        {
        	printf("your account is not valid account ");
        	break;
        }
        if (ServerFeedBack_uint8==Account_ok){
        	printf("\n your account has been found \n");

        }
        	// all works good to here


        ServerFeedBack_uint8 =IsAmountAvilable(Ptr_TermiData,Ptr_User_server_data,ST_Acount_data);

        if (ServerFeedBack_uint8==AmmountNotAvilable){
        	printf("Declined insuffecient funds \n");
        	break;
        	//ServerFeedBack_uint8=IsAmountAvilable(Ptr_ServerData,Ptr_User_server_data,ST_Acount_data);
        }
        if (ServerFeedBack_uint8==Account_ok){
        	SaveTransactionServerSide (Ptr_ServerData,Ptr_User_server_data,ST_Acount_data);
        	printf("transaction saved ..... have a nice day \n");
        	break;
        }
    //*******************End_server_side------------------------------
       // EN_Server_Account_status IsAmountAvilable(ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data)

       //EN_Server_Account_status SaveTransactionServerSide (ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data)

    }
}









        //*******************End_server_side------------------------------










