#include <stdio.h>
#include <string.h>
#include "report.h"
#include "patient.h"
#include "hospital.h"

void generatePerformanceReport(void)
{
    int critical = 0;
    int urgent = 0;
    int normal = 0;
    float totalRevenue = 0;
    float totalDiscount = 0;
    float highestAmount = 0;
    char highestPatient[50] = "None";

    FILE *file;

    /* 1. Count patients by urgency */

    for (int i = 0; i < patientCount; i++) {
        if (patients[i].triage == 3)
            critical++;
        else if (patients[i].triage == 2)
            urgent++;
        else if (patients[i].triage == 1)
            normal++;
    }

    /* 2. Read billing records */

    file = fopen("patient_records.txt", "r");

    if (file != NULL) {

        int id;
        char name[50];
        float gross;
        float discount;
        float finalAmount;

        while (fscanf(file,
                      "%d|%49[^|]|%f|%f|%f",
                      &id,
                      name,
                      &gross,
                      &discount,
                      &finalAmount) == 5) {

            totalRevenue = totalRevenue + finalAmount;
            totalDiscount = totalDiscount + discount;

            if (finalAmount > highestAmount) {
                highestAmount = finalAmount;
                strcpy(highestPatient, name);
            }
        }
        fclose(file);
    }

    /* Display report */

    printf("\n========================================\n");
    printf("          PERFORMANCE REPORT\n");
    printf("========================================\n");

    /* Patient summary */

    printf("\n--- Patient Summary ---\n");

    printf("Total Patients : %d\n", patientCount);
    printf("Critical       : %d\n", critical);
    printf("Urgent         : %d\n", urgent);
    printf("Normal         : %d\n", normal);

    /* Financial summary */

    printf("\n--- Financial Summary ---\n");
    printf("Total Revenue   : LKR %.2f\n", totalRevenue);
    printf("Total Discounts : LKR %.2f\n", totalDiscount);

    /* Bed occupancy */

    printf("\n--- Bed Occupancy ---\n");
    for (int w = 0; w < MAX_WARDS; w++) {
        int occupied = 0;
        for (int b = 0; b < wardBedCapacity[w]; b++) {
            if (bedOccupancy[w][b] == 1)
                occupied++;
        }
        float percentage = ((float)occupied / wardBedCapacity[w]) * 100;

        printf("%-20s : %d/%d beds (%.2f%%)\n",
               wardName[w],
               occupied,
               wardBedCapacity[w],
               percentage);
    }

    /* Highest-paying patient */

    printf("\n--- Highest-Paying Patient ---\n");

    if (highestAmount > 0) {
        printf("Patient Name : %s\n", highestPatient);
        printf("Total Bill   : LKR %.2f\n", highestAmount);
    } else {
        printf("No billing records available.\n");
    }
    printf("\n========================================\n");
}
