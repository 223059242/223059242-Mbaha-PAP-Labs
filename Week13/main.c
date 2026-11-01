#include <stdio.h>
#include <stdlib.h>
#include "records.h"
#include "suppliers.h"

#define SUPPLIER_FILE "suppliers.txt"

void loadSuppliersFromFile(Supplier **suppliers, int *count, int *capacity) {
    FILE *fp = fopen(SUPPLIER_FILE, "rb");
    if (fp == NULL) {
        printf("No existing supplier file found. Starting fresh.\n");
        return;
    }
    
    // Determine how many records are in the binary file
    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    int recordsInFile = fileSize / sizeof(Supplier);
    if (recordsInFile > 0) {
        *capacity = recordsInFile > 2 ? recordsInFile : 2;
        *suppliers = malloc((*capacity) * sizeof(Supplier));
        if (*suppliers == NULL) {
            printf("Out of memory while loading file!\n");
            fclose(fp);
            return;
        }
        *count = fread(*suppliers, sizeof(Supplier), recordsInFile, fp);
        printf("Loaded %d supplier records from file (Capacity: %d).\n", *count, *capacity);
    }
    fclose(fp);
}

void saveSuppliersToFile(const Supplier suppliers[], int count) {
    FILE *fp = fopen(SUPPLIER_FILE, "wb");
    if (fp == NULL) {
        perror("Error opening supplier file for writing");
        return;
    }
    fwrite(suppliers, sizeof(Supplier), count, fp);
    fclose(fp);
    printf("Successfully saved %d supplier records to file.\n", count);
}

int main(void) {
    Supplier *suppliers = NULL;
    int count = 0;
    int capacity = 0;
    int choice;

    // Load existing records on startup (allocating heap memory dynamically)
    loadSuppliersFromFile(&suppliers, &count, &capacity);

    do {
        printf("\n=========================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("   (Week 13 - Dynamic Memory)\n");
        printf("=========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Save Data to File\n");
        printf("5. Exit & Free Memory\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addSupplier(&suppliers, &count, &capacity);
                break;
            case 2:
                displaySuppliers(suppliers, count);
                break;
            case 3:
                searchSupplier(suppliers, count);
                break;
            case 4:
                if (suppliers != NULL && count > 0) {
                    saveSuppliersToFile(suppliers, count);
                } else {
                    printf("No suppliers to save.\n");
                }
                break;
            case 5:
                if (suppliers != NULL && count > 0) {
                    saveSuppliersToFile(suppliers, count);
                }
                // Return heap memory back to the system (Week 13 requirement)[cite: 30]
                free(suppliers);
                suppliers = NULL;
                printf("Heap memory successfully freed. Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}