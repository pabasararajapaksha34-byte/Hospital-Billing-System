#ifndef BILLING_H
#define BILLING_H

float calculateWaitingTime(int specialtyIndex);
float calculateSurcharge(int specialtyIndex, int triage);
float calculateWardCost(int wardIndex, int days, int admitted);
float calculateGrossTotal(float baseFee, float surcharge, float wardCost);
float calculateDiscount(float grossTotal, int age);

#endif
