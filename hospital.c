#include <stdio.h>
#include "hospital.h"

char specialtyName[MAX_SPECIALTIES][30] = {
    "General Practice",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};

float specialtyFee[MAX_SPECIALTIES] = { 1500, 2500, 4500, 5000 };
int specialtyTimePerPatient[MAX_SPECIALTIES] = {15, 20, 30, 30};
int specialtyDailyCap[MAX_SPECIALTIES] = {30, 20, 12, 10};
char wardName[MAX_WARDS][40] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};
float wardDailyRate[MAX_WARDS] = {3000, 6000, 12000, 25000};
int wardBedCapacity[MAX_WARDS] = {20, 10, 10, 5};
int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initialiseBedMatrix(void)
{
    for (int w = 0; w < MAX_WARDS; w++) {
        for (int b = 0; b < MAX_BEDS; b++) {
            if (b < wardBedCapacity[w])
                bedOccupancy[w][b] = 0;
            else
                bedOccupancy[w][b] = 1;
        }
    }

    /* Load previously saved bed status */
    loadBedStatus();
}
void displaySpecialtyTable(void)
{
    printf("\n--- Doctor Specialties ---\n");
    printf("%-4s %-25s %-12s %-10s %-6s\n", "ID", "Name", "Fee", "Time", "Cap");
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
    printf("%-4s %-28s %-15s %-10s\n", "ID", "Name", "Rate/Day", "Beds");
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
    printf("\n--- Bed Occupancy ---\n");
    printf("0 = Available, 1 = Occupied\n");

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
        if (bedOccupancy[wardIndex][b] == 0)
            return b;
    }
    return -1;
}
void occupyBed(int wardIndex, int bedIndex)
{
    bedOccupancy[wardIndex][bedIndex] = 1;
    saveBedStatus();
}
void freeBed(int wardIndex, int bedIndex)
{
    bedOccupancy[wardIndex][bedIndex] = 0;
    saveBedStatus();
}
void saveBedStatus(void)
{
    FILE *file;
    file = fopen("beds_status.txt", "w");
    if (file == NULL) {
        printf("\nError saving bed status!\n");
        return;
    }
    for (int w = 0; w < MAX_WARDS; w++) {
        for (int b = 0; b < MAX_BEDS; b++) {
            fprintf(file, "%d ", bedOccupancy[w][b]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}
void loadBedStatus(void)
{
    FILE *file;
    file = fopen("beds_status.txt", "r");
    if (file == NULL) {
        return;
    }
    for (int w = 0; w < MAX_WARDS; w++) {
        for (int b = 0; b < MAX_BEDS; b++) {
            fscanf(file, "%d", &bedOccupancy[w][b]);
        }
    }
    fclose(file);
}
