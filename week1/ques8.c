#include <stdio.h>

struct Student {
    int roll;
    char name[50];
    int marks[5];
    int total;
    float percentage;
    char grade;
};

int main() {
    struct Student s[50];
    int n, i, j;
    int topper = 0;
    float classTotal = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Roll number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        s[i].total = 0;

        printf("Enter marks in 5 subjects:\n");
        for (j = 0; j < 5; j++) {
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }

        s[i].percentage = s[i].total / 5.0;

        if (s[i].percentage >= 90)
            s[i].grade = 'A';
        else if (s[i].percentage >= 80)
            s[i].grade = 'B';
        else if (s[i].percentage >= 70)
            s[i].grade = 'C';
        else if (s[i].percentage >= 60)
            s[i].grade = 'D';
        else
            s[i].grade = 'F';

        classTotal += s[i].percentage;

        if (s[i].percentage > s[topper].percentage)
            topper = i;
    }

    printf("\n--- Student Results ---\n");

    for (i = 0; i < n; i++) {
        printf("\nRoll No: %d", s[i].roll);
        printf("\nName: %s", s[i].name);
        printf("\nTotal: %d", s[i].total);
        printf("\nPercentage: %.2f", s[i].percentage);
        printf("\nGrade: %c\n", s[i].grade);
    }

    printf("\n--- Class Topper ---\n");
    printf("Roll No: %d\n", s[topper].roll);
    printf("Name: %s\n", s[topper].name);
    printf("Percentage: %.2f\n", s[topper].percentage);

    printf("\n--- Students Failed in One or More Subjects ---\n");

    for (i = 0; i < n; i++) {
        int failed = 0;

        for (j = 0; j < 5; j++) {
            if (s[i].marks[j] < 40) {
                failed = 1;
                break;
            }
        }

        if (failed)
            printf("Roll No: %d, Name: %s\n", s[i].roll, s[i].name);
    }

    printf("\nClass Average: %.2f\n", classTotal / n);

    return 0;
}
