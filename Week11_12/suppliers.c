#include <stdio.h>
#include <string.h>
#include "suppliers.h"

void addSupplier(Supplier suppliers[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Supplier database is full!\n");
        return;
    }

    printf("\n--- Add New Supplier ---\n");
    printf("Enter ID: ");
    scanf("%d", &suppliers[*count].id);
    
    printf("Enter Name (one word): ");
    scanf("%39s", suppliers[*count].name);
    
    printf("Enter Email: ");
    scanf("%39s", suppliers[*count].email);
    
    printf("Enter Phone: ");
    scanf("%14s", suppliers[*count].phone);
    
    printf("Enter Town: ");
    scanf("%19s", suppliers[*count].town);

    (*count)++;
    printf("Supplier added successfully!\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    if (count == 0) {
        printf("\nNo suppliers found in the system.\n");
        return;
    }

    printf("\n=================================================================\n");
    printf("%-6s %-20s %-25s %-15s %-15s\n", "ID", "Name", "Email", "Phone", "Town");
    printf("=================================================================\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-6d %-20s %-25s %-15s %-15s\n",
            suppliers[i].id,
            suppliers[i].name,
            suppliers[i].email,
            suppliers[i].phone,
            suppliers[i].town
        );
    }
    printf("=================================================================\n");
    printf("Total Suppliers: %d\n", count);
}

void searchSupplier(const Supplier suppliers[], int count) {
    int searchId;
    int found = 0;

    printf("\nEnter Supplier ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (suppliers[i].id == searchId) {
            printf("\n--- Supplier Found ---\n");
            printf("ID:    %d\n", suppliers[i].id);
            printf("Name:  %s\n", suppliers[i].name);
            printf("Email: %s\n", suppliers[i].email);
            printf("Phone: %s\n", suppliers[i].phone);
            printf("Town:  %s\n", suppliers[i].town);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Supplier with ID %d not found.\n", searchId);
    }
}