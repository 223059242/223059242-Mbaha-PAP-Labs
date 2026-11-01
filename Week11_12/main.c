#include <stdio.h>
#include <stdlib.h>
#include "records.h"
#include "suppliers.h"

#define SUPPLIER_FILE "suppliers.txt"

void loadSuppliersFromFile(Supplier suppliers[], int *count) {
    FILE *fp = fopen(SUPPLIER_FILE, "rb");
    if (fp == NULL) {
        printf("No existing supplier file found. Starting fresh.\n");
        return;
    }
    *count = fread(suppliers, sizeof(Supplier), MAX_RECORDS, fp);
    fclose(fp);
    printf("Loaded %d supplier records from file.\n", *count);
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
    Supplier suppliers[MAX_RECORDS];
    int supplierCount = 0;
    int choice;

    // Load existing records on startup
    loadSuppliersFromFile(suppliers, &supplierCount);

    do {
        printf("\n=========================================\n");
        printf("   MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("=========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier by ID\n");
        printf("4. Save Data to File\n");
        printf("5. Exit & Save\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // clear input buffer
            continue;
        }

        switch (choice) {
            case 1:
                addSupplier(suppliers, &supplierCount);
                break;
            case 2:
                displaySuppliers(suppliers, supplierCount);
                break;
            case 3:
                searchSupplier(suppliers, supplierCount);
                break;
            case 4:
                saveSuppliersToFile(suppliers, supplierCount);
                break;
            case 5:
                saveSuppliersToFile(suppliers, supplierCount);
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}