#include <stdio.h>
#include <string.h>
#include "patient.h"

char patientName[MAX_PATIENTS][MAX_NAME];
int patientAge[MAX_PATIENTS];
int patientTriage[MAX_PATIENTS];
int patientCount = 0;

void addPatient(void)
{
    int n;

    printf("Enter number of patients: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char name[MAX_NAME];
        int age, triage;

        printf("\nEnter patient %d details\n", i + 1);

        printf("Name: ");
        scanf("%s", name);

        printf("Age: ");
        scanf("%d", &age);

        printf("Triage (3=Critical, 2=Urgent, 1=Normal): ");
        scanf("%d", &triage);

        int position = 0;

        while (position < patientCount && patientTriage[position] >= triage)
        {
            position++;
        }
        for (int j = patientCount; j > position; j--) {
            strcpy(patientName[j], patientName[j - 1]);
            patientAge[j] = patientAge[j - 1];
            patientTriage[j] = patientTriage[j - 1];
        }
        strcpy(patientName[position], name);
        patientAge[position] = age;
        patientTriage[position] = triage;

        patientCount++;
    }
}
void displayPatients(void)
{
    printf("\n===== PATIENTS IN PRIORITY ORDER =====\n");
    for (int i = 0; i < patientCount; i++) {
        printf("%d. %s  Age: %d  ", i + 1, patientName[i], patientAge[i]);

        if (patientTriage[i] == 3)
            printf("Critical\n");
        else if (patientTriage[i] == 2)
            printf("Urgent\n");
        else
            printf("Normal\n");
    }
}
