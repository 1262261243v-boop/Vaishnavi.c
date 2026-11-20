#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 50
#define SUBJECTS 3

struct Student {
    int rollNo;
    char name[100];
    float marks[SUBJECTS];
    float total;
    float percentage;
    char grade;
};

char calculateGrade(float percentage) {
    if (percentage >= 90.0) return 'A';
    else if (percentage >= 75.0) return 'B';
    else if (percentage >= 60.0) return 'C';
    else if (percentage >= 40.0) return 'D';
    else return 'F';
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n, i, j;

    printf("Enter number of students (1 to %d): ", MAX_STUDENTS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &students[i].rollNo);

        // Clear input buffer before reading string with spaces
        while (getchar() != '\n');

        printf("Name: ");
        fgets(students[i].name, sizeof(students[i].name), stdin);
        students[i].name[strcspn(students[i].name, "\n")] = '\0';

        students[i].total = 0.0f;
        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter marks for Subject %d (out of 100): ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }

        students[i].percentage = students[i].total / SUBJECTS;
        students[i].grade = calculateGrade(students[i].percentage);
    }

    printf("\n==================== STUDENT RESULT SHEET ====================\n");
    printf("%-8s %-20s %-8s %-12s %-6s\n", "Roll No", "Name", "Total", "Percentage", "Grade");
    printf("--------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-8d %-20s %-8.2f %-11.2f%% %-6c\n",
               students[i].rollNo,
               students[i].name,
               students[i].total,
               students[i].percentage,
               students[i].grade);
    }
    printf("==============================================================\n");

    return 0;
}
