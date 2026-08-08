#include <stdio.h>
#include <string.h>
#define MAX 100
struct Student
{
    int rollNo;
    char name[50];
    char branch[20];

    int marks1;
    int marks2;
    int marks3;

    int total;
    float average;
    char grade;
};

struct Student students[MAX];
int count = 0;
void calculateGrade(struct Student *s)
{
    s->total = s->marks1 + s->marks2 + s->marks3;
    s->average = s->total / 3.0;

    if(s->average >= 90)
        s->grade = 'A';
    else if(s->average >= 80)
        s->grade = 'B';
    else if(s->average >= 70)
        s->grade = 'C';
    else if(s->average >= 60)
        s->grade = 'D';
    else
        s->grade = 'F';
}
void addStudent()
{
    printf("\nEnter Roll Number : ");
    scanf("%d",&students[count].rollNo);

    printf("Enter Name : ");
    scanf(" %[^\n]",students[count].name);

    printf("Enter Branch : ");
    scanf("%s",students[count].branch);

    printf("Enter Marks in Subject 1 : ");
    scanf("%d",&students[count].marks1);

    printf("Enter Marks in Subject 2 : ");
    scanf("%d",&students[count].marks2);

    printf("Enter Marks in Subject 3 : ");
    scanf("%d",&students[count].marks3);

    calculateGrade(&students[count]);

    count++;

    printf("\nStudent Added Successfully.\n");
}
void displayStudents()
{
    int i;

    if(count==0)
    {
        printf("\nNo Records Found.\n");
        return;
    }

    printf("\n--------------------------------------------------------------------------------\n");
    printf("Roll\tName\t\tBranch\tTotal\tAverage\tGrade\n");
    printf("--------------------------------------------------------------------------------\n");

    for(i=0;i<count;i++)
    {
        printf("%d\t%-15s%-10s%d\t%.2f\t%c\n",
               students[i].rollNo,
               students[i].name,
               students[i].branch,
               students[i].total,
               students[i].average,
               students[i].grade);
    }
}
int main()
{
    int choice;

    while(1)
    {
        printf("\n===== STUDENT MARKS SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");

        printf("Enter Choice : ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                return 0;

            default:
                printf("Invalid Choice");
        }
    }
}

