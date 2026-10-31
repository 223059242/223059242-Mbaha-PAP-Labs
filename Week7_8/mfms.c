#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

/* Supplier data (parallel arrays from Week 7) */
char supplierNames[MAX_SUPPLIERS][100];
char supplierEmails[MAX_SUPPLIERS][100];
char supplierPhones[MAX_SUPPLIERS][30];
char supplierTowns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Function prototypes */
void displayWelcome(void);
void displayMenu(void);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);
int searchEmployee(int id, int ids[], int size);
void addSupplier(void);
void displaySupplier(void);
void searchSupplier(void);
void supplierMenu(void);
void readLine(const char *prompt, char *buffer, int size);
double readNumber(const char *prompt);

int main(void)
{
    int employeeIDs[] = {101, 102, 103, 104, 105};
    int choice = 0;
    double amount, basic, housing, transport, revenue, expenses;
    float balance;
    int id, position;

    displayWelcome();

    do
    {
        displayMenu();
        choice = (int)readNumber("");

        switch (choice)
        {
            case 1:
                amount = readNumber("Enter amount: ");
                printf("VAT: %.2f\n", calculateVAT((float)amount));
                break;

            case 2:
                basic = readNumber("Basic salary: ");
                housing = readNumber("Housing allowance: ");
                transport = readNumber("Transport allowance: ");
                printf("Gross salary: %.2f\n",
                       calculateSalary((float)basic, (float)housing, (float)transport));
                break;

            case 3:
                revenue = readNumber("Enter revenue: ");
                expenses = readNumber("Enter expenses: ");
                balance = calculateBudget((float)revenue, (float)expenses);
                printf("Budget balance: %.2f\n", balance);
                if (balance > 0)
                {
                    printf("SURPLUS\n");
                }
                else if (balance < 0)
                {
                    printf("DEFICIT\n");
                }
                else
                {
                    printf("BALANCED\n");
                }
                break;

            case 4:
                id = (int)readNumber("Enter employee ID: ");
                position = searchEmployee(id, employeeIDs, 5);
                if (position >= 0)
                {
                    printf("Employee found at position %d.\n", position);
                }
                else
                {
                    printf("Employee not found.\n");
                }
                break;

            case 5:
                supplierMenu();
                break;

            case 6:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}

void displayWelcome(void)
{
    printf("Welcome to the Municipal Financial Management System\n");
}

void displayMenu(void)
{
    printf("\n============================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT SYSTEM\n");
    printf("============================================\n");
    printf("1. Calculate VAT\n");
    printf("2. Calculate Employee Salary\n");
    printf("3. Calculate Budget\n");
    printf("4. Search Employee\n");
    printf("5. Supplier Management\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

float calculateVAT(float amount)
{
    return amount * 0.15f;
}

float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses)
{
    return revenue - expenses;
}

int searchEmployee(int id, int ids[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (ids[i] == id)
        {
            return i;
        }
    }
    return -1;
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }
    readLine("Enter supplier name: ", supplierNames[supplierCount], sizeof(supplierNames[0]));
    readLine("Enter email: ", supplierEmails[supplierCount], sizeof(supplierEmails[0]));
    readLine("Enter phone: ", supplierPhones[supplierCount], sizeof(supplierPhones[0]));
    readLine("Enter town: ", supplierTowns[supplierCount], sizeof(supplierTowns[0]));
    supplierCount++;
    printf("Supplier added.\n");
}

void displaySupplier(void)
{
    if (supplierCount == 0)
    {
        printf("No suppliers yet.\n");
        return;
    }
    for (int i = 0; i < supplierCount; i++)
    {
        printf("\n--- SUPPLIER %d ---\n", i + 1);
        printf("Name : %s\n", supplierNames[i]);
        printf("Email: %s\n", supplierEmails[i]);
        printf("Phone: %s\n", supplierPhones[i]);
        printf("Town : %s\n", supplierTowns[i]);
    }
}

void searchSupplier(void)
{
    char searchName[100];
    readLine("Enter supplier name to search: ", searchName, sizeof(searchName));
    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierNames[i], searchName) == 0)
        {
            printf("Supplier found: %s (%s)\n", supplierNames[i], supplierTowns[i]);
            return;
        }
    }
    printf("Supplier not found.\n");
}

void supplierMenu(void)
{
    int sub = 0;
    do
    {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back\n");
        sub = (int)readNumber("Enter choice: ");

        switch (sub)
        {
            case 1: addSupplier(); break;
            case 2: displaySupplier(); break;
            case 3: searchSupplier(); break;
            case 4: break;
            default: printf("Invalid choice.\n");
        }
    } while (sub != 4);
}

/* Reads a whole line and removes the newline */
void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    if (fgets(buffer, size, stdin) == NULL)
    {
        buffer[0] = '\0';
        return;
    }
    buffer[strcspn(buffer, "\n")] = '\0';
}

/* Reads a line and converts it to a number */
double readNumber(const char *prompt)
{
    char line[50];
    double value = 0;
    readLine(prompt, line, sizeof(line));
    sscanf(line, "%lf", &value);
    return value;
}