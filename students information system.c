#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

// Structure definition for a student
typedef struct {
    char firstName[50];
    char lastName[50];
    char department[100];
    char studentClass[20];
    char semester[20];
    int rollNumber;
} Student;


void addStudent(Student students[], int *count);
void viewStudents(Student students[], int count);
void findStudent(Student students[], int count);
void updateStudent(); // Placeholder for future functionality
void deleteStudent(Student students[], int *count);
void PrintMenu(Student students[], int *count);


int main() {
    printf("*****************WELCOME TO STUDENT INFORMATION SYSTEM ****************\n");
    printf("*****************DEPARTMENT OF COMPUTER SCIENCE ****************\n");

    Student students[MAX_STUDENTS]; 
    int studentCount = 0;          

    PrintMenu(students, &studentCount);

    return 0;
}

// Menu function
void PrintMenu(Student students[], int *count) {
    int selectopt;

    while (1) {
        printf("\n================= MENU =================\n");
        printf("Press 1 to Add student details\n");
        printf("Press 2 to Update student details\n");
        printf("Press 3 to Delete student details\n");
        printf("Press 4 to View student details\n");
        printf("Press 5 to Find student detail by Roll number\n");
        printf("Press 6 to Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &selectopt);

        switch (selectopt) {
            case 1:
                addStudent(students, count);
                break;
            case 2:
                updateStudent(students, count);
                break;
            case 3:
                deleteStudent(students, count);
                break;
            case 4:
                viewStudents(students, *count);
                break;
            case 5:
                findStudent(students, *count);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return;
            default:
                printf("Invalid option selected. Please try again.\n");
        }
    }
}

// Function to add a student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("\nStudent limit reached. Cannot add more students.\n");
        return;
    }
  FILE *fptr;

   // use appropriate location if you are using MacOS or Linux
   fptr = fopen("D:\\p\\prgram.txt","a");
    printf("\nEnter Student First Name: ");
    scanf("%s", students[*count].firstName);
            fprintf(fptr,"\n");
        fprintf(fptr,"%s",students[*count].firstName);


    printf("Enter Student Last Name: ");
    scanf("%s", students[*count].lastName);
       fprintf(fptr,"\n");
        fprintf(fptr,"%s",students[*count].lastName);


    printf("Enter Student Department: ");
    scanf("%s", students[*count].department);
       fprintf(fptr,"\n");
        fprintf(fptr,"%s",students[*count].department);


    printf("Enter Student Class: ");
    scanf("%s", students[*count].studentClass);
      fprintf(fptr,"\n");
        fprintf(fptr,"%s",students[*count].studentClass);


    printf("Enter Student Roll Number: ");
    scanf("%d", &students[*count].rollNumber);
      fprintf(fptr,"\n");
        fprintf(fptr,"%d",students[*count].rollNumber);


    printf("Enter Student Semester: ");
    scanf("%s", students[*count].semester);
  fprintf(fptr,"\n");
        fprintf(fptr,"%s",students[*count].semester);
        
         fprintf(fptr,"\n");
        fprintf(fptr,"...................Student Added....................");
  
        
        
   fclose(fptr);

    (*count)++; // Increment the student count

    printf("\nStudent added successfully!\n");
}

// Function to view all students
void viewStudents(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to display.\n");
        return;
    }

    printf("\nStudent Details:\n");
    int i = 0;
    for ( i = 0; i < count; i++) {
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
        printf("Department: %s\n", students[i].department);
        printf("Class: %s\n", students[i].studentClass);
        printf("Semester: %s\n", students[i].semester);
        printf("-----------------------------------\n");
    }
}

// Function to find a student by roll number
void findStudent(Student students[], int count) {
    int rollNumber;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNumber);

int i = 0;
    for ( i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Department: %s\n", students[i].department);
            printf("Class: %s\n", students[i].studentClass);
            printf("Semester: %s\n", students[i].semester);
            return;
        }
    }

    printf("\nStudent with Roll Number %d not found.\n", rollNumber);
}

void updateStudent(Student students[], int count) {
    if (count == 0) {
        printf("\nNo students to update.\n");
        return;
    }

    int rollNumber;
    printf("\nEnter Roll Number of the student to update: ");
    scanf("%d", &rollNumber);
int i = 0;
    for ( i = 0; i < count; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent Found:\n");
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s %s\n", students[i].firstName, students[i].lastName);
            printf("Department: %s\n", students[i].department);
            printf("Class: %s\n", students[i].studentClass);
            printf("Semester: %s\n", students[i].semester);

            // Update the details
            printf("\nEnter New First Name (current: %s): ", students[i].firstName);
            scanf("%s", students[i].firstName);

            printf("Enter New Last Name (current: %s): ", students[i].lastName);
            scanf("%s", students[i].lastName);

            printf("Enter New Department (current: %s): ", students[i].department);
            scanf("%s", students[i].department);

            printf("Enter New Class (current: %s): ", students[i].studentClass);
            scanf("%s", students[i].studentClass);

            printf("Enter New Semester (current: %s): ", students[i].semester);
            scanf("%s", students[i].semester);

            printf("\nStudent details updated successfully!\n");
            return;
        }
    }

    printf("\nStudent with Roll Number %d not found.\n", rollNumber);
}

// Function to delete a student
void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("\nNo students to delete.\n");
        return;
    }

    int rollNumber;
    printf("\nEnter Roll Number of the student to delete: ");
    scanf("%d", &rollNumber);

int i = 0;
    for ( i = 0; i < *count; i++) {
        if (students[i].rollNumber == rollNumber) {
        	int j = i;
            // Shift all elements after the found student to the left
            for ( j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--; // Decrement the student count
            printf("\nStudent with Roll Number %d deleted successfully.\n", rollNumber);
            return;
        }
    }

    printf("\nStudent with Roll Number %d not found.\n", rollNumber);
}

