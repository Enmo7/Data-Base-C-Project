#include <stdio.h>
#include <stdlib.h>
#include "STD_TYPES.h"
#include "SDB.h"
u8 num;
const student*studentslist=NULL; //there is the list initialization

int main()
{
    studentslist=createlist(studentslist); //creating the list to do commands on it by the next function
    SDB_APP();
    return 0;
}
