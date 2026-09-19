#ifndef PATIENT_H
#define PATIENT_H
#define MAX_PATIENTS 100
#define MAX_NAME 50

extern char patientName[MAX_PATIENTS][MAX_NAME];
extern int patientAge[MAX_PATIENTS];
extern int patientTriage[MAX_PATIENTS];
extern int patientCount;

void addPatient(void);
void displayPatients(void);

#endif
