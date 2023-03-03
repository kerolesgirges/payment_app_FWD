 /******************************************************************************
 *
 * Module: Server module
 *
 * Date_Creation: 3/01/2023
 * 
 * File Name: Server.c
 *
 * Description: Server get data from terminal and card test it according to data base and make final work .
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/
#include "Server.h"



/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
*******************************************************************************/

/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

void Server_DataBase(struct Acount_User_Data *ST_Acount_data){
strcpy(ST_Acount_data[0].Acount_Name_uint8 ,"keroloesgirgesattalla");
strcpy(ST_Acount_data[0].Acount_PAN_uint8 , "1111111111111111");
       ST_Acount_data[0].Acount_HoldingAmount_uint8=1000800.46;
strcpy(ST_Acount_data[0].Acount_ExpirDAte_uint8,"02/23");
//printf("hi from data base \n");
//printf("%s",ST_Acount_data[0].Acount_Name_uint8);
strcpy(ST_Acount_data[1].Acount_Name_uint8 ,"kokokokokokokokokokoo");
strcpy(ST_Acount_data[1].Acount_PAN_uint8 , "22222222222222222");
       ST_Acount_data[1].Acount_HoldingAmount_uint8=50600.96;
strcpy(ST_Acount_data[1].Acount_ExpirDAte_uint8,"02/28");

strcpy(ST_Acount_data[2].Acount_Name_uint8 ,"keroloeskokokerokuro");
strcpy(ST_Acount_data[2].Acount_PAN_uint8 , "333333333333333333");
       ST_Acount_data[2].Acount_HoldingAmount_uint8=912355.90;
strcpy(ST_Acount_data[2].Acount_ExpirDAte_uint8,"02/30");


strcpy(ST_Acount_data[3].Acount_Name_uint8 ,"tamergirgesemadmenako");
strcpy(ST_Acount_data[3].Acount_PAN_uint8 , "44444444444444444");
       ST_Acount_data[3].Acount_HoldingAmount_uint8=500.5;
strcpy(ST_Acount_data[3].Acount_ExpirDAte_uint8,"10/23");

strcpy(ST_Acount_data[4].Acount_Name_uint8 ,"keroloesgirgesattalla");
strcpy(ST_Acount_data[4].Acount_PAN_uint8 , "555555555555555555");
       ST_Acount_data[4].Acount_HoldingAmount_uint8=50.70;
strcpy(ST_Acount_data[4].Acount_ExpirDAte_uint8,"12/24");

}
EN_Server_Account_status IsValidAccount( ST_user_card_data *Ptr_ServerData ,ST_user_Server_data *Ptr_User_server_data , struct Acount_User_Data *ST_Acount_data)
{
    Server_DataBase(ST_Acount_data);
    int func_counter;

    for(func_counter=0;func_counter<=4;func_counter++)
    {
        //printf("here now server for loop searching data  \n");
//printf("%s\n",Ptr_ServerData->CardHolderNames_uint8);
//printf("%s\n",Ptr_ServerData->CardPan_uint8);

//printf("%s\n",ST_Acount_data[func_counter].Acount_Name_uint8);
//printf("%s\n",ST_Acount_data[func_counter].Acount_PAN_uint8);

        if ((strcmp(Ptr_ServerData->CardHolderNames_uint8,ST_Acount_data[func_counter].Acount_Name_uint8)==0)
        
            &&(strcmp(Ptr_ServerData->CardPan_uint8,ST_Acount_data[func_counter].Acount_PAN_uint8) ==0 ))
        {
            Ptr_User_server_data->Account_orderInServer_uint8 =func_counter;
           // printf("order num %d \n",func_counter);
            return Account_ok;

        }
    }
    
    return notValid_account;

}

EN_Server_Account_status IsAmountAvilable(ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data)
{
    //puts(ST_Acount_data[Ptr_User_server_data->Account_orderInServer_uint8].Acount_HoldingAmount_uint8);
    Server_DataBase(ST_Acount_data);
   // printf("here last 1\n ");
//printf("%.2lf\n",Ptr_ServerData->Trans_amount_Float);
//printf("%.2lf\n",Ptr_User_server_data->Account_orderInServer_uint8);

//printf("%.2lf\n",ST_Acount_data[Ptr_User_server_data->Account_orderInServer_uint8].Acount_HoldingAmount_uint8);

//printf("here last 2\n ");
if ((Ptr_ServerData->Trans_amount_Float) <= ( ST_Acount_data[Ptr_User_server_data->Account_orderInServer_uint8].Acount_HoldingAmount_uint8 ))
    {

        printf("account ok \n");
        return Account_ok;
    }

return AmmountNotAvilable;
}




void SaveTransactionServerSide (ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data)

{
    ST_Acount_data[Ptr_User_server_data->Account_orderInServer_uint8].Acount_HoldingAmount_uint8 -= Ptr_ServerData->Trans_amount_Float;
printf("remaining :  %.3f",ST_Acount_data[Ptr_User_server_data->Account_orderInServer_uint8].Acount_HoldingAmount_uint8);
    //Printf("\n your transaction has been made successfully, nice to meet you hope to see you againe\n ");

}

