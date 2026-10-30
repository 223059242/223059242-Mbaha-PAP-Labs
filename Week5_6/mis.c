#include <stdio.h>
#include <string.h>

#define SAL_COUNT 5   /* change to 50 for the final version */
#define BUD_COUNT 3   /* change to 10 for the final version */
#define REG_COUNT 3   /* change to 20 for the final version */

int main() {
    double salaries[SAL_COUNT];
    double budgets[BUD_COUNT];
    char registrations[REG_COUNT][20];
    double total, average, highest, lowest, target, temp;
    char searchReg[20];
    int found, i, j;

    /* ---------- PART A: EMPLOYEE SALARIES ---------- */
    printf("=== PART A: EMPLOYEE SALARIES ===\n");
    for (i = 0; i < SAL_COUNT; i++) {
        printf("Enter salary %d: ", i + 1);
        scanf("%lf", &salaries[i]);
    }

    printf("\nAll salaries:\n");
    total = 0;
    highest = salaries[0];
    lowest = salaries[0];
    for (i = 0; i < SAL_COUNT; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
        total += salaries[i];
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }
    average = total / SAL_COUNT;
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%lf", &target);
    found = 0;
    for (i = 0; i < SAL_COUNT; i++) {
        if (salaries[i] == target) {
            printf("Salary found at position %d (employee %d)\n", i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Salary not found.\n");
    }

    /* ---------- PART B: DEPARTMENT BUDGETS ---------- */
    printf("\n=== PART B: DEPARTMENT BUDGETS ===\n");
    for (i = 0; i < BUD_COUNT; i++) {
        printf("Enter budget %d: ", i + 1);
        scanf("%lf", &budgets[i]);
    }

    total = 0;
    printf("\nBudgets:\n");
    for (i = 0; i < BUD_COUNT; i++) {
        printf("%.2f\n", budgets[i]);
        total += budgets[i];
    }
    printf("Total budget: %.2f\n", total);
    printf("Average budget: %.2f\n", total / BUD_COUNT);

    /* bubble sort, lowest to highest */
    for (i = 0; i < BUD_COUNT - 1; i++) {
        for (j = 0; j < BUD_COUNT - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }
    printf("\nBudgets sorted (lowest to highest):\n");
    for (i = 0; i < BUD_COUNT; i++) {
        printf("%.2f\n", budgets[i]);
    }

    /* ---------- PART C: VEHICLE REGISTRATIONS ---------- */
    printf("\n=== PART C: VEHICLE REGISTRATIONS ===\n");
    for (i = 0; i < REG_COUNT; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\nVehicle Registrations:\n");
    for (i = 0; i < REG_COUNT; i++) {
        printf("%s\n", registrations[i]);
    }

    printf("\nEnter a registration to search for: ");
    scanf("%19s", searchReg);
    found = 0;
    for (i = 0; i < REG_COUNT; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration found at position %d\n", i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Registration not found.\n");
    }

    return 0;
}