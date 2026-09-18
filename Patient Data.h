#ifndef HOSPITAL_H
#define HOSPITAL_H

#define MAX_PATIENTS 100
#define MAX_SPECIALTIES 4
#define MAX_WARDS 4
#define MAX_NAME 50

/* ---------------- Hospital Data ---------------- */

extern char specialty[MAX_SPECIALTIES][30];

extern char ward[MAX_WARDS][30];

/* ---------------- Patient Data ---------------- */

extern char name[MAX_PATIENTS][MAX_NAME];
extern int age[MAX_PATIENTS];
extern int triage[MAX_PATIENTS];
extern int specialtyID[MAX_PATIENTS];
extern int admitted[MAX_PATIENTS];
extern int wardID[MAX_PATIENTS];
extern int days[MAX_PATIENTS];

extern int patientCount;

/* ---------------- Function Declarations ---------------- */

void registerPatient(void);
void displayPatients(void);

#endif
