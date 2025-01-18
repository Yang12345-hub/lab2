#include <stdio.h>
/*Step 1: Create a Student struct with:

A name field (a string with 50 characters).
An array of 3 integers to hold grades.
A float field to store the student's average grade.*/

// Define the Student struct
struct Student {
    char name[50];
    int grades[3];
    float average;  // To store the average grade
    float weightedAverage;
};
// Function to calculate the average (pass-by-reference)

void calculateAverage(struct Student *student) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        //TODO: calculate the sum;
        sum += student->grades[i];  
    }
    student->average = sum / 3.0;  // Calculate and update the average
}


void calculateWeightedAverage(struct Student *student) {
    float result = 0;
    result += student->grades[0] * 0.4 + student->grades[1] * 0.3 + student->grades[2] * 0.3;
    student->weightedAverage = result;  // Calculate and update the average
}

// Main function
int main() {
    // Create and initialize an array of 3 students
    struct Student students[3] = {
        {"Andy", {85, 90, 78}, 0},
        {"Randy", {88, 76, 92}, 0},
        {"Sandy", {70, 80, 75}, 0}
    };

    // Call calculateAverage for each student
    for (int i = 0; i < 3; i++) {
        //TODO;  // Pass each student by reference
        calculateAverage(&students[i]);
        calculateWeightedAverage(&students[i]);
    }

    // Print student details
    float highest = 0;
    struct Student topStudent;
    
    for (int i = 0; i < 3; i++) {
        printf("Name: %s\n", students[i].name);
        printf("Grades: %d, %d, %d\n", students[i].grades[0], students[i].grades[1], students[i].grades[2]);
        printf("Average: %.2f\n", students[i].average);
        printf("Weighted Average: %.2f\n\n", students[i].weightedAverage);
        if (highest <= students[i].weightedAverage) {
            highest = students[i].weightedAverage;
            topStudent = students[i];
        }
    }
    printf("Student with highest score is %s\n", topStudent.name);


    return 0;
}

