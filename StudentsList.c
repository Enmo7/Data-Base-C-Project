#include "STD_TYPES.h"
#include "SDB.h"
#include <stddef.h>
#define MAX 10
#define MIN 3
extern num;
extern studentslist;

student* insertinbeginning (student*studentslist,u32 id,u32 year,u32 course1id,u32 course1grade,u32 course2id,u32 course2grade,u32 course3id,u32 course3grade)
{
    printf("Please enter the data you require for student[1](ID,YEAR,COURSE1ID,COURSE1GRADE,COURSE2ID,COURSE2GRADE,COURSE3ID,COURSE3GRADE)\n");
    //scanning all the values for the first student in the list
    scanf("%d%d%d%d%d%d%d%d",&id,&year,&course1id,&course1grade,&course2id,&course2grade,&course3id,&course3grade);
    student* temp=(student*) malloc(sizeof(student));
    if(temp!=NULL)
    {
        temp->Student_ID=id;
        temp->Student_year=year;
        temp->Course1_ID=course1id;
        temp->Course1_grade=course1grade;
        temp->Course2_ID=course2id;
        temp->Course2_grade=course2grade;
        temp->Course3_ID=course3id;
        temp->Course3_grade=course3grade;
        temp->link=studentslist;
        studentslist=temp;
    }
    return studentslist;
}
void insertatend (student*studentslist,u32 id,u32 year,u32 course1id,u32 course1grade,u32 course2id,u32 course2grade,u32 course3id,u32 course3grade)
{
        scanf("%d%d%d%d%d%d%d%d",&id,&year,&course1id,&course1grade,&course2id,&course2grade,&course3id,&course3grade);
    student* temp=(student*) malloc(sizeof(student));
    if(temp != NULL)
    {
        temp->Student_ID=id;
        temp->Student_year=year;
        temp->Course1_ID=course1id;
        temp->Course1_grade=course1grade;
        temp->Course2_ID=course2id;
        temp->Course2_grade=course2grade;
        temp->Course3_ID=course3id;
        temp->Course3_grade=course3grade;
        student* ptr=studentslist; //pointer to struct for loop formation
        while(ptr->link != NULL) //condition for loop to find the last student to add after
        {
            ptr=ptr->link;
        }
        ptr->link = temp;
        temp->link= NULL;
    }
}
student* createlist(student*studentslist)
{
    printf("Please enter the number of students needed to create the list :\n");
    scanf("%d",&num);
    if(num<=MAX && MIN<=num)//to limit my list i used if condition
    {
        u32 id,year,course1id,course1grade,course2id,course2grade,course3id,course3grade;
    //creating the first node
    studentslist=insertinbeginning(studentslist,id,year,course1id,course1grade,course2id,course2grade,course3id,course3grade);
    //adding nodes to the first one by (number of students-1)
    int counter;
    for(counter=1;counter<num;counter++)
    {
        printf("Please enter the data you require for the student[%d](ID,YEAR,COURSE1ID,COURSE1GRADE,COURSE2ID,COURSE2GRADE,COURSE3ID,COURSE3GRADE)\n",(counter+1));
        insertatend(studentslist,id,year,course1id,course1grade,course2id,course2grade,course3id,course3grade);
    }
    return studentslist;}
    else
       {
        printf("\nMinimum number of students is 3 and the maximum is 10, please re-enter number of students\n");
        createlist(studentslist);
       }
}



