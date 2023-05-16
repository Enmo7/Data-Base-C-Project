/*
******************************************************************************************************************************************
********************************************************     Date : 31/3/2023       ******************************************************
********************************************************     Version : 1            ******************************************************
********************************************************     File Name : SDBAPP     ******************************************************
******************************************************************************************************************************************

******************************************************************************************************************************************
************************************************************* Liberaries *****************************************************************
******************************************************************************************************************************************
*/

#include "STD_TYPES.h"
#include "SDB.h"
#include <stddef.h>
#define MAX 10
#define MIN 3


/*
******************************************************************************************************************************************
************************************************************ Variables *******************************************************************
******************************************************************************************************************************************
*/

extern num;
u32 id;

/*
******************************************************************************************************************************************
************************************************************** First Function ************************************************************
******************************************************************************************************************************************

Description: It has a super loop it will make your project until the user chose to exit you will ask the user to choose between these 
options :
1. To add entry, enter 1 
2. To get used size in database, enter 2
3. To read student data, enter 3 
4. To get the list of all student IDs, enter 4
5. To check is ID is existed, enter 5 
6. To delete student data, enter 6
7. To check is database is full, enter 7
8. To exit enter 0
*/

void SDB_APP ()
{

    //showing off the choices
    u8 choice;
    printf("\n1. To add entry, enter 1\n");
    printf("2. To get used size in database, enter 2\n");
    printf("3. To read student data, enter 3\n");
    printf("4. To get the list of all student IDs, enter 4\n");
    printf("5. To check is ID is existed, enter 5\n");
    printf("6. To delete student data, enter 6\n");
    printf("7. To check is database is full, enter 7\n");
    printf("8. To exit press 0\n");
    //taking the choice from user
    scanf("%d",&choice);
    //calling the chosen function
    SDB_action (choice);
}


/*
*****************************************************************************************************************************************
**************************************************************** Second Function ********************************************************
*****************************************************************************************************************************************

Description: it well takes the user choice and call the responding function for this choice. You make the right response to give a valid 
Output for the user.
*/

void SDB_action (u8 choice)
{
    switch(choice)
    {
    case 1:
        SDB_AddEntry();
        break;
    case 2:
        SDB_GetUsedSize();
            SDB_APP();  //calling the sdbAPP again after finishing the function to choose another function after
        break;
    case 3:
        SDB_ReadEntry ();
            SDB_APP();
        break;
    case 4:
        SDB_GetList();
            SDB_APP();
            break;
    case 5:
        SDB_IsIdExist(id);
            SDB_APP();
        break;
    case 6:
        SDB_DeletEntry ();
        break;
    case 7:
        SDB_IsFull();
            SDB_APP();
            break;
    case 8:
        printf("the program is closed");
        return 0;
        break;
    default:                //making a default case to re-enter a right choice for the switch case3
        printf("\nThe Choice is wrong, please choose a right choice from the list below\n");
            SDB_APP();
            break;
    }
}











