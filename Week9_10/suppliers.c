#include <stdio.h>
#include <string.h>
#include "suppliers.h"

#define MAX_SUPPLIERS 5

static char names[MAX_SUPPLIERS][100];
static char emails[MAX_SUPPLIERS][100];
static char phones[MAX_SUPPLIERS][30];
static char towns[MAX_SUPPLIERS][50];
static int supplierCount = 0;

static void readLine(const char *prompt, char *buffer, int size) {
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("Supplier list is full.\n");
        return;
    }
    readLine("Enter supplier name: ", names[supplierCount], sizeof(names[0]));
    readLine("Enter email: ", emails[supplierCount], sizeof(emails[0]));
    readLine("Enter phone: ", phones[supplierCount], sizeof(phones[0]));
    readLine("Enter town: ", towns[supplierCount], sizeof(towns[0]));
    supplierCount++;
    printf("Supplier added successfully.\n");
}

void displaySuppliers(void) {
    if (supplierCount == 0) {
        printf("No suppliers recorded yet.\n");
        return;
    }
    for (int i = 0; i < supplierCount; i++) {
        printf("\n--- SUPPLIER %d ---\n", i + 1);
        printf("Name  : %s\n", names[i]);
        printf("Email : %s\n", emails[i]);
        printf("Phone : %s\n", phones[i]);
        printf("Town  : %s\n", towns[i]);
    }
}

void searchSupplier(void) {
    char searchName[100];
    int found = 0;
    readLine("Enter supplier name to search: ", searchName, sizeof(searchName));
    
    for (int i = 0; i < supplierCount; i++) {
        if (strcmp(names[i], searchName) == 0) {
            printf("Supplier found: %s located in %s\n", names[i], towns[i]);
            found = 1;
            break;
        }
    }
    if (!found) printf("Supplier not found.\n");
}

void showNameLength(void) {
    if (supplierCount == 0) {
        printf("No suppliers to analyze.\n");
        return;
    }
    for (int i = 0; i < supplierCount; i++) {
        printf("Supplier: %s | Name Length: %zu\n", names[i], strlen(names[i]));
    }
}

// Week 10: Save to Text File using fprintf()[cite: 85]
void saveSuppliersToFile(void) {
    FILE *fp = fopen("suppliers.txt", "w");
    if (fp == NULL) {
        perror("Error opening file for writing");
        return;
    }
    for (int i = 0; i < supplierCount; i++) {
        fprintf(fp, "%s|%s|%s|%s\n", names[i], emails[i], phones[i], towns[i]);
    }
    fclose(fp);
    printf("Suppliers successfully saved to suppliers.txt\n");
}

// Week 10: Load from Text File using fscanf()[cite: 85, 86]
void loadSuppliersFromFile(void) {
    FILE *fp = fopen("suppliers.txt", "r");
    if (fp == NULL) {
        printf("No existing save file found.\n");
        return;
    }
    supplierCount = 0;
    while (fscanf(fp, "%99[^|]|%99[^|]|%29[^|]|%49[^\n]\n", 
           names[supplierCount], emails[supplierCount], 
           phones[supplierCount], towns[supplierCount]) == 4) {
        supplierCount++;
        if (supplierCount >= MAX_SUPPLIERS) break;
    }
    fclose(fp);
    printf("Loaded %d supplier records from file.\n", supplierCount);
}