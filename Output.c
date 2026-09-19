#include <stdio.h>
#include <string.h>
#include "billing.h"

char specialty[MAX_SPECIALTIES][30] = {
    "General Practice",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};
float specialtyFee[MAX_SPECIALTIES] = { 1500, 2500, 4500, 5000 };
char ward[MAX_WARDS][30] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};
float wardRate[MAX_WARDS] = { 3000, 6000, 12000, 25000 };

void printBill(struct Patient p)
{
    printf("\n====================================\n");
    printf("       SMART HOSPITAL BILL\n");
    printf("====================================\n");
    printf("Patient ID   : %d\n", p.id);
    printf("Name         : %s\n", p.name);
    printf("Age          : %d\n", p.age);
    printf("Specialty    : %s\n", specialty[p.specialty]);
    printf("Triage       : ");

    if (p.triage == 3)
        printf("Critical\n");
    else if (p.triage == 2)
        printf("Urgent\n");
    else
        printf("Normal\n");

    if (p.admitted == 1) {
        printf("Ward         : %s\n", ward[p.ward]);
        printf("Bed          : %d\n", p.bed);
        printf("Days         : %d\n", p.days);
    } else {
        printf("Ward         : Not Admitted\n");
    }

    printf("\n----------- BILL -----------\n");
    printf("Consultation : LKR %.2f\n", specialtyFee[p.specialty]);
    printf("Surcharge    : LKR %.2f\n", p.surcharge);
    printf("Ward Cost    : LKR %.2f\n", p.wardCost);
    printf("Gross Total  : LKR %.2f\n", p.total);
    printf("Discount     : LKR %.2f\n", p.discount);
    printf("Final Amount : LKR %.2f\n", p.finalAmount);
    printf("============================\n");
}
