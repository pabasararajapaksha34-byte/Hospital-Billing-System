#include <stdio.h>
#include "billing.h"

char specialtyName[MAX_SPECIALTIES][30] = {
    "General Practice",
    "Paediatrics",
    "Cardiology",
    "Neurology"
};
float specialtyFee[MAX_SPECIALTIES] = { 1500, 2500, 4500, 5000};
int specialtyTime[MAX_SPECIALTIES] = { 15, 20, 30, 30};

char wardName[MAX_WARDS][30] = {
    "General Ward",
    "Paediatric Ward",
    "Surgical Ward",
    "ICU"
};
float wardRate[MAX_WARDS] = { 3000, 6000, 12000, 25000 };

int queueCount[MAX_SPECIALTIES] = { 0, 0, 0, 0 };

int main(void)
{
    int specialtyID;
    int specialtyIndex;
    int age;
    int triage;
    int admitted;
    int wardID;
    int wardIndex;
    int days;
    float baseFee;
    float surcharge;
    float wardCost;
    float grossTotal;
    float discount;
    float finalAmount;
    float waitingTime;

    printf("===== Billing Calculator =====\n");

    printf("\nSpecialties:\n");
    for (int i = 0; i < MAX_SPECIALTIES; i++) {
        printf("%d - %s\n", i + 1, specialtyName[i]);
    }

    printf("Enter Specialty ID: ");
    scanf("%d", &specialtyID);

    specialtyIndex = specialtyID - 1;

    printf("Enter Patient Age: ");
    scanf("%d", &age);

    printf("\nTriage Level:\n");

    printf("1 - Normal\n");
    printf("2 - Urgent\n");
    printf("3 - Critical\n");

    printf("Enter Triage Level: ");
    scanf("%d", &triage);

    printf("\nAdmitted to Ward?\n");

    printf("1 - Yes\n");
    printf("0 - No\n");

    printf("Enter choice: ");
    scanf("%d", &admitted);

    wardIndex = -1;
    days = 0;

    if (admitted == 1) {
        printf("\nWards:\n");
        for (int i = 0; i < MAX_WARDS; i++) {
            printf("%d - %s\n", i + 1, wardName[i]);
        }

        printf("Enter Ward ID: ");
        scanf("%d", &wardID);

        wardIndex = wardID - 1;

        printf("Enter number of days: ");
        scanf("%d", &days);
    }
    waitingTime = queueCount[specialtyIndex] * specialtyTime[specialtyIndex];
    baseFee = specialtyFee[specialtyIndex];
    surcharge = 0;

    if (triage == 2) {
        surcharge = baseFee * 0.20;
    } else if (triage == 3) {
        surcharge = baseFee * 0.50;
    }
    wardCost = 0;

    if (admitted == 1) {
        wardCost = days * wardRate[wardIndex];
    }
    grossTotal = baseFee + surcharge + wardCost;
    discount = 0;

    if (age < 5 || age > 65) {
        discount = grossTotal * 0.15;
    }
    finalAmount = grossTotal - discount;
    queueCount[specialtyIndex]++;

    printf("\n===== BILL DETAILS =====\n");
    printf("Specialty       : %s\n", specialtyName[specialtyIndex]);
    printf("Base Fee        : LKR %.2f\n", baseFee);
    printf("Surcharge       : LKR %.2f\n", surcharge);
    printf("Ward Cost       : LKR %.2f\n", wardCost);
    printf("Gross Total     : LKR %.2f\n", grossTotal);
    printf("Discount        : LKR %.2f\n", discount);
    printf("Final Amount    : LKR %.2f\n", finalAmount);
    printf("Waiting Time    : %.2f minutes\n", waitingTime);
    
    return 0;
}
