/* suppliers.h - Supplier Module Headers */
#ifndef SUPPLIERS_H
#ifndef RECORDS_H
#include "records.h"
#endif

// Function prototypes for supplier management
void addSupplier(Supplier **suppliers, int *count, int *capacity);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

#endif