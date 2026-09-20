#include <stdio.h>
#include <string.h>
#include "patient.h"
#include "hospital.h"

struct Patient patients[MAX_PATIENTS];
int patientCount = 0;

void registerPatient(void)
{
    int freeBed;

    if (patientCount >= MAX_PATIENTS) {
        printf("\nPatient limit reached!\n");
        return;
    }

    printf("\n===== REGISTER PATIENT =====\n");

    patients[patientCount].id = patientCount + 1;

    printf("Enter patient name: ");
    getchar();
    fgets(patients[patientCount].name, MAX_NAME, stdin);

    patients[patientCount].name[strcspn(patients[patientCount].name, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &patients[patientCount].age);

    printf("\nTriage Level\n");
    printf("1 - Normal\n");
    printf("2 - Urgent\n");
    printf("3 - Critical\n");

    printf("Enter triage level: ");
    scanf("%d", &patients[patientCount].triage);

    printf("\nSpecialties\n");

    for (int i = 0; i < MAX_SPECIALTIES; i++) {
        printf("%d - %s\n", i + 1, specialtyName[i]);
    }

    printf("Enter specialty ID: ");
    scanf("%d", &patients[patientCount].specialty);

    patients[patientCount].specialty--;

    printf("\nAdmitted to ward?\n");
    printf("1 - Yes\n");
    printf("0 - No\n");

    printf("Enter choice: ");
    scanf("%d", &patients[patientCount].admitted);

    if (patients[patientCount].admitted == 1) {

        printf("\nWards\n");

        for (int i = 0; i < MAX_WARDS; i++) {
            printf("%d - %s\n", i + 1, wardName[i]);
        }

        printf("Enter ward ID: ");
        scanf("%d", &patients[patientCount].ward);

        patients[patientCount].ward--;

        freeBed = findFreeBed(patients[patientCount].ward);

        if (freeBed == -1) {

            printf("\nNo free beds available!\n");

            patients[patientCount].admitted = 0;
            patients[patientCount].ward = -1;
            patients[patientCount].bed = -1;
            patients[patientCount].days = 0;

        } else {

            patients[patientCount].bed = freeBed;

            occupyBed(patients[patientCount].ward, patients[patientCount].bed);
            printf("Allocated Bed Number: %d\n", patients[patientCount].bed + 1);
            printf("Enter number of days: ");
            scanf("%d", &patients[patientCount].days);
        }

    } else {
        patients[patientCount].ward = -1;
        patients[patientCount].bed = -1;
        patients[patientCount].days = 0;
    }

    patientCount++;

    printf("\nPatient registered successfully!\n");
}

void displayPatients(void)
{
    if (patientCount == 0) {
        printf("\nNo patients registered.\n");
        return;
    }
    printf("\n===== PATIENT LIST =====\n");

    for (int i = 0; i < patientCount; i++) {
        printf("\nPatient ID : %d\n", patients[i].id);
        printf("Name       : %s\n", patients[i].name);
        printf("Age        : %d\n", patients[i].age);
        printf("Triage     : ");

        if (patients[i].triage == 3)
            printf("Critical\n");
        else if (patients[i].triage == 2)
            printf("Urgent\n");
        else
            printf("Normal\n");

        printf("Specialty  : %s\n",
               specialtyName[patients[i].specialty]);

        if (patients[i].admitted == 1) {
            printf("Admitted   : Yes\n");
            printf("Ward       : %s\n", wardName[patients[i].ward]);
            printf("Bed        : %d\n", patients[i].bed + 1);
            printf("Days       : %d\n", patients[i].days);
        } else {
            printf("Admitted   : No\n");
        }
    }
}
