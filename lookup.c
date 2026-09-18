#include <stdio.h>
#include "hospital.h"

char specialtyName[MAX_SPECIALTIES][30] = {
    "General Practice (OPD)",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};
float specialtyFee[MAX_SPECIALTIES] = { 1500.00, 2500.00, 4500.00, 5000.00};
int specialtyTimePerPatient[MAX_SPECIALTIES] = { 15, 20, 30, 30};
int specialtyDailyCap[MAX_SPECIALTIES] = { 30, 20, 12, 10};

char wardName[MAX_WARDS][40] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU (Intensive Care Unit)"
};
float wardDailyRate[MAX_WARDS] = { 3000.00, 6000.00, 12000.00, 25000.00};
int wardBedCapacity[MAX_WARDS] = { 20, 10, 10, 5};
int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initialiseBedMatrix(void)
{
    for (int w = 0; w < MAX_WARDS; w++) {
        for (int b = 0; b < MAX_BEDS; b++) {
            if (b < wardBedCapacity[w]) {
                bedOccupancy[w][b] = 0;
            } else {
                bedOccupancy[w][b] = 1;
            }
        }
    }
}
void displaySpecialtyTable(void)
{
    printf("\n--- Doctor Specialties ---\n");

    printf("%-4s %-25s %-12s %-10s %-6s\n",
           "ID",
           "Name",
           "Fee(LKR)",
           "Time/Pt",
           "Cap");
    for (int i = 0; i < MAX_SPECIALTIES; i++) {
        printf("%-4d %-25s %-12.2f %-10d %-6d\n",
               i + 1,
               specialtyName[i],
               specialtyFee[i],
               specialtyTimePerPatient[i],
               specialtyDailyCap[i]);
    }
}
void displayWardTable(void)
{
    printf("\n--- Hospital Wards ---\n");

    printf("%-4s %-28s %-15s %-10s\n",
           "ID",
           "Name",
           "Rate(LKR/Day)",
           "Beds");

    for (int i = 0; i < MAX_WARDS; i++) {
        printf("%-4d %-28s %-15.2f %-10d\n",
               i + 1,
               wardName[i],
               wardDailyRate[i],
               wardBedCapacity[i]);
    }
}
void displayBedMatrix(void)
{
    printf("\n--- Bed Occupancy Matrix (0 = Available, 1 = Occupied) ---\n");

    for (int w = 0; w < MAX_WARDS; w++) {
        printf("%-28s: ", wardName[w]);

        for (int b = 0; b < wardBedCapacity[w]; b++) {
            printf("%d ", bedOccupancy[w][b]);
        }
        printf("\n");
    }
}
int findFreeBed(int wardIndex)
{
    for (int b = 0; b < wardBedCapacity[wardIndex]; b++) {
        if (bedOccupancy[wardIndex][b] == 0) {
            return b;
        }
    }
    return -1;
}
void occupyBed(int wardIndex, int bedIndex)
{
    bedOccupancy[wardIndex][bedIndex] = 1;
}
void freeBed(int wardIndex, int bedIndex)
{
    bedOccupancy[wardIndex][bedIndex] = 0;
}
