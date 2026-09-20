#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_SPECIALTIES 4
#define MAX_WARDS 4
#define MAX_BEDS 20

extern char specialtyName[MAX_SPECIALTIES][30];
extern float specialtyFee[MAX_SPECIALTIES];
extern int specialtyTimePerPatient[MAX_SPECIALTIES];
extern int specialtyDailyCap[MAX_SPECIALTIES];

extern char wardName[MAX_WARDS][40];
extern float wardDailyRate[MAX_WARDS];
extern int wardBedCapacity[MAX_WARDS];

extern int bedOccupancy[MAX_WARDS][MAX_BEDS];

void initialiseBedMatrix(void);
void displaySpecialtyTable(void);
void displayWardTable(void);
void displayBedMatrix(void);

int findFreeBed(int wardIndex);
void occupyBed(int wardIndex, int bedIndex);
void freeBed(int wardIndex, int bedIndex);

void saveBedStatus(void);
void loadBedStatus(void);

#endif
