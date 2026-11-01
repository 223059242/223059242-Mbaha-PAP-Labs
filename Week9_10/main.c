#include <stdio.h>
#include <stdlib.h>
#include "suppliers.h"

int main(void) {
    int choice;
    
    // Automatically attempt to load persistent data on startup
    loadSuppliersFromFile();

    do {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM  \n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Lengths\n");
        printf("5. Save Data to File\n");
        printf("6. Exit & Save\n");
        printf("Enter choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input.\n");
            while(getchar() != '\n');
            continue;
        }
        getchar(); // clear buffer

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: showNameLength(); break;
            case 5: saveSuppliersToFile(); break;
            case 6: 
                saveSuppliersToFile();
                printf("Exiting program. Goodbye!\n"); 
                break;
            default: printf("Invalid option. Try again.\n");
        }
    } while (choice != 6);

    return 0;
}