#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "new_entry.h"
#include "search_record.h"
#include "modify_record.h"
#include "all_records.h"
#include "delete_record.h"
void patient_system() {
struct patient_data *ptr;
    ptr = (struct patient_data *)malloc(1 * sizeof(struct patient_data));
    int c;
    do {
        printf("[Enter a] Add New Patient Records\n");
        printf("[Enter b] Search Existing Patient Records\n");
        printf("[Enter c] Modify Existing Patient Records\n");
        printf("[Enter d] Delete Patient Records\n");
        printf("[Enter e] View All Records\n");
        printf("[Enter f] Exit\n");
        printf("Choice - ");

        char b;
        scanf("%c", &b);
        fflush(stdin);

        switch (b) {
            case 'a':
                new_entry(ptr);
                break;
            case 'b':
                search_record(ptr);
                break;
            case 'c':
                modify_record(ptr);
                break;
            case 'd':
                delete_record();
                break;
            case 'e':
                all_records();
                break;
            case 'f':
                printf("Thank You\n");
                break;
            default:
                printf("Error\n");
                break;
        }
        printf("\nEnter 1 to do it again or 0 to exit - ");
        scanf("%d", &c);
        printf("\n");
        fflush(stdin);
    } while (c != 0);

}
int main() {
    int choice;
    do {
        printf("[Enter 1] - Patient System\n");
        printf("[Enter 2] - Staff System\n");
        printf("[Enter 3] - Inventory System\n");
        printf("[Enter 4] - Exit\n");
        printf("Choice - ");
        scanf("%d", &choice);
        fflush(stdin);

    switch(choice) {
        case 1:
                patient_system();
                break;
        case 2:
                printf("Staff System\n");
                break;
        case 3:
                printf("Inventory System\n");
                break;

        default:
                printf("Thank You\n");
                break;
    }
    }while(choice !=4);

    return 0;
}
