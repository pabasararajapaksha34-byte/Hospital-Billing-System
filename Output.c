#include <stdio.h>

#include "bill.h"
#include "patient.h"
#include "hospital.h"
#include "billing.h"

void generateBill(int patientIndex)
{
    struct Patient p;
    float baseFee;
    float surcharge;
    float wardCost;
    float grossTotal;
    float discount;
    float finalAmount;
    float waitingTime;

    p = patients[patientIndex];
    baseFee = specialtyFee[p.specialty];
    surcharge = calculateSurcharge( p.specialty, p.triage);
    wardCost = calculateWardCost(p.ward, p.days, p.admitted);
    grossTotal = calculateGrossTotal(baseFee, surcharge, wardCost);
    discount = calculateDiscount(grossTotal, p.age);
    finalAmount = grossTotal - discount;
    waitingTime = calculateWaitingTime(p.specialty);

    printf("\n====================================\n");
    printf("       SMART HOSPITAL BILL\n");
    printf("====================================\n");

    printf("Patient ID   : %d\n", p.id);
    printf("Name         : %s\n", p.name);
    printf("Age          : %d\n", p.age);
    printf("Specialty    : %s\n", specialtyName[p.specialty]);
    printf("Triage       : ");

    if (p.triage == 3)
        printf("Critical\n");
    else if (p.triage == 2)
        printf("Urgent\n");
    else
        printf("Normal\n");

    if (p.admitted == 1) {
        printf("Ward         : %s\n", wardName[p.ward]);
        printf("Bed          : %d\n", p.bed + 1);
        printf("Days         : %d\n", p.days);
    } else {
        printf("Ward         : Not Admitted\n");
    }

    printf("\n----------- BILL -----------\n");
    printf("Consultation : LKR %.2f\n", baseFee);
    printf("Surcharge    : LKR %.2f\n", surcharge);
    printf("Ward Cost    : LKR %.2f\n", wardCost);
    printf("Gross Total  : LKR %.2f\n", grossTotal);
    printf("Discount     : LKR %.2f\n", discount);
    printf("Final Amount : LKR %.2f\n", finalAmount);
    printf("Waiting Time : %.2f minutes\n", waitingTime);
    printf("============================\n");
}
