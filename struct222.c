#include <stdio.h>
#include <string.h>

// โครงสร้างข้อมูลนักเรียน
struct student
{
    int id;
    char name[50];
    float gpa;
    char grade[2];
    float grade1;
    float grade2;
    float grade3;
} std[100];

int size = 0;

void grade(struct student *s)
{
    s->gpa = (s->grade1 + s->grade2 + s->grade3) / 3;

    if (s->gpa <= 1.49)
    {
        strcpy(s->grade, "Retire");
    }
    else if (s->gpa <= 1.74)
    {
        strcpy(s->grade, "Low Probation");
    }
    else if (s->gpa <= 1.99)
    {
        strcpy(s->grade, "High Probation");
    }
    else
    {
        strcpy(s->grade, "Normal");
    }
}

void add_student()
{
    int choice = 0;
    do
    {
        printf("Enter Student ID: ");
        scanf("%d", &std[size].id);
        printf("Enter Student Name: ");
        scanf("%s", std[size].name);
        printf("Grade CS1003: ");
        scanf("%f", &std[size].grade1);
        printf("Grade MA1013: ");
        scanf("%f", &std[size].grade2);
        printf("Grade GE1033: ");
        scanf("%f", &std[size].grade3);

        grade(&std[size]);

        size++;
        printf("Add more? (1=Yes, 0=No): ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void display_students()
{
    printf("\n--- Student List ---\n");
    for (int i = 0; i < size; i++)
    {
        printf("ID: %d, Name: %s, GPA: %.2f, Grade: %s\n",
               std[i].id, std[i].name, std[i].gpa, std[i].grade);
    }
}

void search_student()
{
    int key;
    printf("Enter ID to search: ");
    scanf("%d", &key);
    for (int i = 0; i < size; i++)
    {
        if (std[i].id == key)
        {
            printf("Found: ID: %d, Name: %s, GPA: %.2f, Grade: %s\n",
                   std[i].id, std[i].name, std[i].gpa, std[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", key);
}

void delete_student()
{
    int key;
    printf("Enter ID to delete: ");
    scanf("%d", &key);
    for (int i = 0; i < size; i++)
    {
        if (std[i].id == key)
        {
            for (int j = i; j < size - 1; j++)
            {
                std[j] = std[j + 1];
            }
            size--;
            printf("Student with ID %d deleted.\n", key);
            return;
        }
    }
    printf("Student with ID %d not found.\n", key);
}

void sort_students_by_gpa()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (std[j].gpa < std[j + 1].gpa)
            {
                struct student temp = std[j];
                std[j] = std[j + 1];
                std[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by GPA (Descending).\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nMenu\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Sort Students by GPA\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            display_students();
            break;
        case 3:
            search_student();
            break;
        case 4:
            delete_student();
            break;
        case 5:
            sort_students_by_gpa();
            break;
        case 6:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
