#include "STD_TYPES.h"
#include "SDB.h"
#include <stddef.h>
#define MAX 10
#define MIN 3
extern num;
extern studentslist;

_Bool SDB_IsFull ()
{
    if(num==MAX)//check if list is full of students
    {
        printf("/nData base is full/n");
        return 1;
    }
    else       //if not then there's still empty places
    {
        printf("/nThere are still places in the Data base\n");
        return 0;
    }
}

u8 SDB_GetUsedSize()
{
    printf("\nThe number of added students is %d\n",num); //num is the number of students and is updated in upcoming functions
    return num;
}


student* SDB_AddEntry()
{
    if(SDB_IsFull()==0)//to check first if the list is full or not
    {
        printf("Please enter the required data for the student(ID,YEAR,COURSE1ID,COURSE1GRADE,COURSE2ID,COURSE2GRADE,COURSE3ID,COURSE3GRADE)\n");
        //insertatend();
        u32 id,year,course1id,course1grade,course2id,course2grade,course3id,course3grade;
        scanf("%d%d%d%d%d%d%d%d",&id,&year,&course1id,&course1grade,&course2id,&course2grade,&course3id,&course3grade);
        student* temp=(student*) malloc(sizeof(student));
        if(temp != NULL)
        {
            temp->Student_ID=id;
            temp->Student_year=year;
            temp->Course1_ID=course1id;
            temp->Course1_grade=course1grade;   //inserting a node at the end of the list
            temp->Course2_ID=course2id;
            temp->Course2_grade=course2grade;
            temp->Course3_ID=course3id;
            temp->Course3_grade=course3grade;
            student* ptr=studentslist;
            while(ptr->link != NULL)        //ptr is a pointer to make loop
            {
                ptr=ptr->link;
            }
            ptr->link = temp;
            temp->link= NULL;
        }
        num++;  //update number of students by incrementing it by 1 (if added successfully)
        SDB_APP();
    }
    else
    {
        printf(" cannot add more students\n");  //if no more space and no added students, theres no updates
        SDB_APP();
        return 0;
    }
}



_Bool SDB_IsIdExist (u32 id)
{
    printf("\nEnter ID\n");
    scanf("%d",&id);
    student*temp=studentslist; //creating pointer to student struct to loop with it till the end of the list searching for id
    while(temp!=NULL)
    {
        if(temp->Student_ID==id)
        {
            break;
        }
        temp=temp->link;
    }
    if(temp==NULL) //if the loop is finished and pointer points to NULL, then the id is not in the list
    {
        printf("\nID doesn't exist\n");
        return 0;
    }
    else
    {
        printf("\nID exists\n"); //if id is in the list, first if condition will break and execute this command
        return 1;
    }
}




_Bool SDB_ReadEntry (u32 id)
{
    printf("\nEnter ID\n");
    scanf("%d",&id);
    student*ptr=studentslist; //creating pointer to struct student for loop
    while(ptr->link!=NULL)
    {
        if(ptr->link->Student_ID==id)
        {
            break;
        }
        ptr=ptr->link;
    }
    if(ptr->link==NULL)
    {
        printf("ID not exist");
        return 0;
    }
    else //if id exists in list then the next line of code will print the students data
    {
        printf("student year: %d\ncourse 1 ID: %d\ncourse 1 grade: %d\ncourse 2 ID: %d\ncourse 2 grade: %d\ncourse 3 ID: %d\ncourse 3 grade: %d\n ",ptr->link->Student_year,ptr->link->Course1_ID,ptr->link->Course1_grade,ptr->link->Course2_ID,ptr->link->Course2_grade,ptr->link->Course3_ID,ptr->link->Course3_grade);
        return 1;
    }
}





void SDB_DeletEntry (u32 id)
{
    printf("please enter the ID of the student to delete:\n");
    scanf("%d",&id);
    student* ptr=studentslist;
    student*temp=(student*)malloc(sizeof(student));
    if(ptr->Student_ID == id)
    {
        temp=studentslist;
        ptr=ptr->link;
        free(temp);
        printf("\ndeleted successfully\n"); //checking if the student is at the beginning of the list (first node in linked list)
        num--;
        SDB_APP();

    }
     ptr=studentslist;
    while(ptr->link!=NULL)
    {
        if(ptr->link->Student_ID==id)
        {
            break;
        }
        ptr=ptr->link;
    }
    if(ptr->link==NULL)
    {
        printf("\nID not exist\n");
        SDB_APP();
        return 0;
    }
    else
    {
        temp=ptr->link;
        ptr->link=temp->link;
        free(temp);
        printf("\ndeleted successfully\n");
        num--;                         //decrement after deleting the student by 1 for the update
        SDB_APP();
    }
}


void SDB_GetList (u8 * count, student*list)
{
    count=num;     //assigning num (number of students) to the intiger count so it is updated with it
    printf("Number of IDs is :\n%d",count);
    printf("\nAnd the list of ids is :\n");
    list=(student*)malloc(sizeof(student));
    list=studentslist;     //assigning list (of the same type) to the real list so it can store its values inside it
    while(list!=NULL)
    {
        printf("%d\n",list->Student_ID);
        list=list->link;
    }
}

