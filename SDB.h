/*
********************************************************     Date : 31/3/2023     ******************************************************
********************************************************     Version : 1          ******************************************************
********************************************************     File Name : SDB      ******************************************************
*/

#ifndef SDB_H_
#define SDB_H_


typedef struct SimpleDb
{
 u32 Student_ID;
 u32 Student_year;
 u32 Course1_ID;
 u32 Course1_grade;
 u32 Course2_ID;
 u32 Course2_grade;
 u32 Course3_ID;
 u32 Course3_grade;
 struct SimpleDb*link;
}student;

#endif
