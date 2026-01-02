
#include <stdio.h>

#define STUDENT_COUNT 5
#define NAME_LEN 32

typedef struct {
    int id;
    char name[NAME_LEN];
    int math;
    int pe;
    int english;
} Student;

int should_before(const Student *a, const Student *b, int mode) {
    if (mode == 1) {            // English
        if (a->english != b->english)
            return a->english > b->english;
    } else if (mode == 2) {     // PE
        if (a->pe != b->pe)
            return a->pe > b->pe;
    } else if (mode == 3) {     // Math
        if (a->math != b->math)
            return a->math > b->math;
    }
    return a->id < b->id;
}

void print_students(const Student s[], int count) {
    printf("ID    Name     Math  PE  English\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-8s %-5d %-3d %-7d\n",
               s[i].id,
               s[i].name,
               s[i].math,
               s[i].pe,
               s[i].english);
    }
}

int main(void) {
    Student students[STUDENT_COUNT] = {
        {1001, "Alice", 85, 90, 88},
        {1002, "Bob",   92, 78, 85},
        {1003, "Cara",  88, 85, 92},
        {1004, "David", 75, 95, 80},
        {1005, "Evan",  90, 88, 88}
    };

    int mode;

    /* Step 1: print students by ID order */
    printf("Students sorted by ID:\n");
    print_students(students, STUDENT_COUNT);

    /* Step 2: choose sort mode */
    printf("\nEnter sort mode (1=English, 2=PE, 3=Math): ");
    scanf("%d", &mode);

    /* Step 3: sort by selected subject */
    for (int i = 0; i < STUDENT_COUNT - 1; i++) {
        int best = i;
        for (int j = i + 1; j < STUDENT_COUNT; j++) {
            if (should_before(&students[j], &students[best], mode)) {
                best = j;
            }
        }
        if (best != i) {
            Student temp = students[i];
            students[i] = students[best];
            students[best] = temp;
        }
    }

    /* Step 4: print sorted result */
    printf("\nStudents sorted by selected subject:\n");
    print_students(students, STUDENT_COUNT);

    return 0;
}

