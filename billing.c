#include "billing.h"
#include "hospital.h"

int queueCount[MAX_SPECIALTIES] = {0, 0, 0, 0};

float calculateWaitingTime(int specialtyIndex)
{
    return queueCount[specialtyIndex] *
           specialtyTimePerPatient[specialtyIndex];
}

float calculateSurcharge(int specialtyIndex, int triage)
{
    float surcharge = 0;

    if (triage == 2)
        surcharge = specialtyFee[specialtyIndex] * 0.20;
    else if (triage == 3)
        surcharge = specialtyFee[specialtyIndex] * 0.50;

    return surcharge;
}

float calculateWardCost(int wardIndex, int days, int admitted)
{
    if (admitted == 1)
        return wardDailyRate[wardIndex] * days;

    return 0;
}

float calculateGrossTotal(float baseFee, float surcharge, float wardCost)
{
    return baseFee + surcharge + wardCost;
}

float calculateDiscount(float grossTotal, int age)
{
    if (age < 5 || age > 65)
        return grossTotal * 0.15;

    return 0;
}
