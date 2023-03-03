 /******************************************************************************
 *
 * Module: Server module
 *
 * Date_Creation: 3/1/2023
 * 
 * File Name: Server.h
 *
 * Description: Header file for Server module
 *
 * Author: Keroles_Girges
 *
 *******************************************************************************/
#ifndef Server_h_
#define Server_h_

#include "std_types.h"
#include <stdio.h>
#include <string.h>
#include "Card.h"
#include "terminal.h"


/*******************************************************************************
 *                      Preprocessor Macros                                    *
*******************************************************************************/

typedef enum EN_Server_Account_status
{
    Account_ok,notValid_account,AmmountNotAvilable
}EN_Server_Account_status;

typedef struct ST_user_Server_data
{
    uint8 CardAccountStaus_uint8 ; //account valid or nor valid 
    int Account_orderInServer_uint8;//get account order in server
    
}ST_user_Server_data;
struct Acount_User_Data
{
    uint8 Acount_Name_uint8 [25];
    uint8 Acount_PAN_uint8[19];
    float Acount_HoldingAmount_uint8;
    uint8 Acount_ExpirDAte_uint8[6];
};

struct Acount_User_Data ST_Acount_data[5];






/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/
//EN_Server_Account_status IsValidAccount(ST_user_card_data *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data);
EN_Server_Account_status IsValidAccount(ST_user_card_data *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data);
EN_Server_Account_status IsAmountAvilable(ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data);
void SaveTransactionServerSide (ST_CardData_Terminal *Ptr_ServerData,ST_user_Server_data *Ptr_User_server_data,struct Acount_User_Data *ST_Acount_data);


#endif
