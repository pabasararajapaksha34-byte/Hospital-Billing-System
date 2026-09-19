#ifndef BILLING_H
#define BILLING_H

#define MAX_SPECIALTIES 4
#define MAX_WARDS 4

/* ---------------- Specialty Data ---------------- */

extern char specialtyName[MAX_SPECIALTIES][30];

extern float specialtyFee[MAX_SPECIALTIES];

extern int specialtyTime[MAX_SPECIALTIES];


/* ---------------- Ward Data ---------------- */

extern char wardName[MAX_WARDS][30];

extern float wardRate[MAX_WARDS];


/* ---------------- Queue Data ---------------- */

extern int queueCount[MAX_SPECIALTIES];

#endif
