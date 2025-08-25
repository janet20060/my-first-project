#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Define the structure for a student
typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float marks;
} Student;

// Function prototypes
void displayMenu();
void addStudent(Student **students, int *count);
void displayStudents(Student *students, int count);
void searchStudent(Student *students, int count);
void deleteStudent(Student **students, int *count);
void freeStudents(Student *students);

int main() {
    Student *students = NULL;
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                addStudent(&students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                deleteStudent(&students, &count);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    freeStudents(students);
    return 0;
}

void displayMenu() {
    printf("\n--- Student Database Menu ---\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
}

void addStudent(Student **students, int *count) {
    *students = realloc(*students, (*count + 1) * sizeof(Student));
    if (*students == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter student name: ");
    fgets((*students)[*count].name, MAX_NAME_LENGTH, stdin);
    (*students)[*count].name[strcspn((*students)[*count].name, "\n")] = 0; // Remove newline

    printf("Enter student ID: ");
    scanf("%d", &((*students)[*count].id));
    getchar(); // Consume newline

    printf("Enter student marks: ");
    scanf("%f", &((*students)[*count].marks));
    getchar(); // Consume newline

    (*count)++;
    printf("Student added successfully.\n");
}

void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d, Marks: %.2f\n", students[i].name, students[i].id, students[i].marks);
    }
}

void searchStudent(Student *students, int count) {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    getchar(); // Consume newline

    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            printf("Student found: Name: %s, ID: %d, Marks: %.2f\n", students[i].name, students[i].id, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent(Student **students, int *count) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    getchar(); // Consume newline

    int index = -1;
    for (int i = 0; i < *count; i++) {
        if ((*students)[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    // Shift students after the deleted one
    for (int i = index; i < *count - 1; i++) {
        (*students)[i] = (*students)[i + 1];
    }

    *count -= 1;
    *students = realloc(*students, *count * sizeof(Student));
    printf("Student deleted successfully.\n");
}

void freeStudents(Student *students) {
    free(students);
}
