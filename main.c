#include <stdio.h>
#include "hospital.h"
#include "patient.h"
#include "priority.h"
#include "bill.h"

int main(void)
{
    int choice;
    int patientID;

    initialiseBedMatrix();

    do {
        printf("\n\n=================================\n");
        printf("       SMART HOSPITAL SYSTEM\n");
        printf("=================================\n");
        printf("1. Display Specialties\n");
        printf("2. Display Wards\n");
        printf("3. Display Bed Availability\n");
        printf("4. Register Patient\n");
        printf("5. Display Patients\n");
        printf("6. Display Patients by Priority\n");
        printf("7. Generate Patient Bill\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displaySpecialtyTable();
                break;
            case 2:
                displayWardTable();
                break;
            case 3:
                displayBedMatrix();
                break;
            case 4:
                registerPatient();
                break;
            case 5:
                displayPatients();
                break;
            case 6:
                sortAndDisplayByPriority();
                break;
            case 7:
    if (patientCount == 0) {
        printf("\nNo patients registered.\n");
    } else {
        int found = 0;
        displayPatients();
        printf("\nEnter Patient ID: ");
        scanf("%d", &patientID);

        for (int i = 0; i < patientCount; i++) {
            if (patients[i].id == patientID) {
                generateBill(i);
                found = 1;
                break;
            }
        }
        if (found == 0) {
            printf("\nInvalid Patient ID!\n");
        }
    }
    break;
            case 8:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 8);
    
    return 0;
}
