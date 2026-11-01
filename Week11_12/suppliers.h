#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#include "records.h"

// Function prototypes for supplier management
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

#endif