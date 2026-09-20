#ifndef PATIENT_H
#define PATIENT_H
#define MAX_PATIENTS 100
#define MAX_NAME 50

struct Patient
{
    int id;
    char name[MAX_NAME];
    int age;
    int triage;
    int specialty;
    int admitted;
    int ward;
    int bed;
    int days;
};

extern struct Patient patients[MAX_PATIENTS];
extern int patientCount;

void registerPatient(void);
void displayPatients(void);

#endif
