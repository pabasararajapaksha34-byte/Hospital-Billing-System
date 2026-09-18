#include <stdio.h>
#include <string.h>
#include "hospital.h"

char specialty[MAX_SPECIALTIES][30] = {
    "General Practice",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};
char ward[MAX_WARDS][30] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};

char name[MAX_PATIENTS][MAX_NAME];
int age[MAX_PATIENTS];
int triage[MAX_PATIENTS];
int specialtyID[MAX_PATIENTS];
int admitted[MAX_PATIENTS];
int wardID[MAX_PATIENTS];
int days[MAX_PATIENTS];
int patientCount = 0;
void registerPatient(void)
{
    if (patientCount >= MAX_PATIENTS) {
        printf("Patient limit reached!\n");
        return;
    }

    printf("\n===== REGISTER PATIENT =====\n");
    printf("Enter patient name: ");
    getchar();
    fgets(name[patientCount], MAX_NAME, stdin);
    name[patientCount][strcspn(name[patientCount], "\n")] = '\0';

    printf("Enter age: ");
    scanf("%d", &age[patientCount]);

    printf("\nTriage Level\n");

    printf("1 - Normal\n");
    printf("2 - Urgent\n");
    printf("3 - Critical\n");

    printf("Enter triage level: ");
    scanf("%d", &triage[patientCount]);

    printf("\nSpecialties\n");

    for (int i = 0; i < MAX_SPECIALTIES; i++) {
        printf("%d - %s\n", i + 1, specialty[i]);
    }

    printf("Enter specialty ID: ");
    scanf("%d", &specialtyID[patientCount]);

    printf("\nAdmitted to ward?\n");

    printf("1 - Yes\n");
    printf("0 - No\n");

    printf("Enter choice: ");
    scanf("%d", &admitted[patientCount]);

    if (admitted[patientCount] == 1) {
        printf("\nWards\n");

        for (int i = 0; i < MAX_WARDS; i++) {
            printf("%d - %s\n", i + 1, ward[i]);
        }

        printf("Enter ward ID: ");
        scanf("%d", &wardID[patientCount]);

        printf("Enter number of days: ");
        scanf("%d", &days[patientCount]);
    } else {
        wardID[patientCount] = 0;
        days[patientCount] = 0;
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
        printf("\nPatient %d\n", i + 1);
        printf("Name       : %s\n", name[i]);
        printf("Age        : %d\n", age[i]);
        printf("Triage     : %d\n", triage[i]);
        printf("Specialty  : %s\n", specialty[specialtyID[i] - 1]);

        if (admitted[i] == 1) {
            printf("Admitted   : Yes\n");
            printf("Ward       : %s\n", ward[wardID[i] - 1]);
            printf("Days       : %d\n", days[i]);
        } else {
            printf("Admitted   : No\n");
        }
    }
}
