#ifndef BILLING_H
#define BILLING_H
#define MAX_SPECIALTIES 4
#define MAX_WARDS 4

extern char specialty[MAX_SPECIALTIES][30];
extern float specialtyFee[MAX_SPECIALTIES];
extern char ward[MAX_WARDS][30];
extern float wardRate[MAX_WARDS];

struct Patient
{
    int id;
    char name[50];
    int age;
    int triage;
    int specialty;
    int admitted;
    int ward;
    int bed;
    int days;
    float surcharge;
    float wardCost;
    float total;
    float discount;
    float finalAmount;
};

/* Function declaration */

void printBill(struct Patient p);

#endif
