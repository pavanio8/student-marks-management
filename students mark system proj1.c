
        #include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollNo;
    char name[50];
    float marks1;
    float marks2;
    float marks3;
    float total;
    float average;
    char result[10];
};

struct Student students[MAX_STUDENTS];
int count = 0;

/* Calculate total, average and result */
void calculateResult(struct Student *s)
{
    s->total = s->marks1 + s->marks2 + s->marks3;
    s->average = s->total / 3.0;

    if (s->marks1 >= 35 && s->marks2 >= 35 && s->marks3 >= 35)
        strcpy(s->result, "PASS");
    else
        strcpy(s->result, "FAIL");
}

/* Add student */
void addStudent()
{
    struct Student s;

    if (count >= MAX_STUDENTS) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks in Subject 1: ");
    scanf("%f", &s.marks1);

    printf("Enter Marks in Subject 2: ");
    scanf("%f", &s.marks2);

    printf("Enter Marks in Subject 3: ");
    scanf("%f", &s.marks3);

    calculateResult(&s);

    students[count] = s;
    count++;

    printf("\nStudent added successfully!\n");
}

/* Display all students */
void displayStudents()
{
    int i;

    if (count == 0) {
        printf("\nNo students available!\n");
        return;
    }

    printf("\n================ STUDENT DETAILS ================\n");

    for (i = 0; i < count; i++) {
        printf("\nRoll Number : %d", students[i].rollNo);
        printf("\nName        : %s", students[i].name);
        printf("\nSubject 1   : %.2f", students[i].marks1);
        printf("\nSubject 2   : %.2f", students[i].marks2);
        printf("\nSubject 3   : %.2f", students[i].marks3);
        printf("\nTotal       : %.2f", students[i].total);
        printf("\nAverage     : %.2f", students[i].average);
        printf("\nResult      : %s", students[i].result);
        printf("\n-----------------------------------------------");
    }

    printf("\n");
}

/* Search student */
void searchStudent()
{
    int rollNo;
    int i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("\nStudent Found!\n");
            printf("\nRoll Number : %d", students[i].rollNo);
            printf("\nName        : %s", students[i].name);
            printf("\nSubject 1   : %.2f", students[i].marks1);
            printf("\nSubject 2   : %.2f", students[i].marks2);
            printf("\nSubject 3   : %.2f", students[i].marks3);
            printf("\nTotal       : %.2f", students[i].total);
            printf("\nAverage     : %.2f", students[i].average);
            printf("\nResult      : %s\n", students[i].result);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Update student */
void updateStudent()
{
    int rollNo;
    int i;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter New Marks in Subject 1: ");
            scanf("%f", &students[i].marks1);

            printf("Enter New Marks in Subject 2: ");
            scanf("%f", &students[i].marks2);

            printf("Enter New Marks in Subject 3: ");
            scanf("%f", &students[i].marks3);

            calculateResult(&students[i]);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Delete student */
void deleteStudent()
{
    int rollNo;
    int i;
    int j;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    for (i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {

            for (j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }

            count--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nStudent not found!\n");
}

/* Main function */
int main()
{
    int choice;

    do {
        printf("\n====================================\n");
        printf("       STUDENT MARKS MANAGEMENT\n");
        printf("====================================\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                printf("\nThank you for using Student Marks Management!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}
    
        
                