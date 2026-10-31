#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

char names[MAX_SUPPLIERS][100];
char emails[MAX_SUPPLIERS][100];
char phones[MAX_SUPPLIERS][30];
char towns[MAX_SUPPLIERS][50];
int supplierCount = 0;

/* Reads a line with fgets and removes the newline */
void readLine(const char *prompt, char *buffer, int size)
{
    printf("%s", prompt);
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main()
{
    char line[20];
    char searchName[100];
    char description[200];
    char backup[100];
    int choice = 0;
    int i, found;

    do
    {
        printf("\n================================\n");
        printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
        printf("================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Show Name Length\n");
        printf("5. Exit\n");

        readLine("Enter choice: ", line, sizeof(line));
        choice = 0;
        sscanf(line, "%d", &choice);

        switch (choice)
        {
            case 1:
                if (supplierCount >= MAX_SUPPLIERS)
                {
                    printf("Supplier list is full.\n");
                }
                else
                {
                    readLine("Enter supplier name: ", names[supplierCount], sizeof(names[0]));
                    readLine("Enter email: ", emails[supplierCount], sizeof(emails[0]));
                    readLine("Enter phone: ", phones[supplierCount], sizeof(phones[0]));
                    readLine("Enter town: ", towns[supplierCount], sizeof(towns[0]));
                    supplierCount++;
                    printf("Supplier added.\n");
                }
                break;

            case 2:
                if (supplierCount == 0)
                {
                    printf("No suppliers yet.\n");
                }
                for (i = 0; i < supplierCount; i++)
                {
                    printf("\n--- SUPPLIER %d ---\n", i + 1);
                    printf("Name : %s\n", names[i]);
                    printf("Email: %s\n", emails[i]);
                    printf("Phone: %s\n", phones[i]);
                    printf("Town : %s\n", towns[i]);

                    /* strcpy: copy the name into a backup */
                    strcpy(backup, names[i]);
                    printf("Backup copy of name: %s\n", backup);

                    /* strcat: build a sentence from pieces */
                    strcpy(description, names[i]);
                    strcat(description, " operates in ");
                    strcat(description, towns[i]);
                    strcat(description, ".");
                    printf("%s\n", description);
                }
                break;

            case 3:
                readLine("Enter supplier name to search: ", searchName, sizeof(searchName));
                found = 0;
                for (i = 0; i < supplierCount; i++)
                {
                    if (strcmp(names[i], searchName) == 0)
                    {
                        printf("Supplier found: %s (%s)\n", names[i], towns[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Supplier not found.\n");
                }
                break;

            case 4:
                if (supplierCount == 0)
                {
                    printf("No suppliers yet.\n");
                }
                for (i = 0; i < supplierCount; i++)
                {
                    printf("%s - name length: %zu, email length: %zu, town length: %zu\n",
                           names[i], strlen(names[i]), strlen(emails[i]), strlen(towns[i]));
                }
                break;

            case 5:
                printf("Goodbye.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}