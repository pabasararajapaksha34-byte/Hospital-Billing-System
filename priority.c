#include <stdio.h>
#include "priority.h"
#include "patient.h"

void sortAndDisplayByPriority(void)
{
    struct Patient temp;

    if (patientCount == 0) {
        printf("\nNo patients registered.\n");
        return;
    }
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = i + 1; j < patientCount; j++) {
            if (patients[j].triage > patients[i].triage) {

                temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }
    printf("\n===== PATIENTS IN PRIORITY ORDER =====\n");

    for (int i = 0; i < patientCount; i++) {
        printf("%d. %s  Age: %d  ", i + 1, patients[i].name, patients[i].age);
        if (patients[i].triage == 3)
            printf("Critical\n");
        else if (patients[i].triage == 2)
            printf("Urgent\n");
        else
            printf("Normal\n");
    }
}
