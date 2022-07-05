#include "finance_t.h"
#include "ui_scheme.h"
#include <stdio.h>
void displayAllSchemeObjects(scheme *schemeAddr, int objectCount)
{
    for (int i = 0; i < objectCount; i++)
    {
        displaySchemeObject(schemeAddr[i], i);
    }
}
void displaySchemeObject(scheme schemObject, int Index)
{
    printf("\n %d)\n", Index);
    printf("\tScheme ID :%d", schemObject.schemeId);
    printf("\n");
    printf("\tScheme Name :%s", schemObject.schemeName);
    printf("\n");
    printf("\tMax loan Amount :%lf", schemObject.maxLoanAmt);
    printf("\n");
    printf("\tinterestRate :%f", schemObject.interestRate);
    printf("\n");
    printf("\ttenure :%d", schemObject.tenure);
    printf("\n");
}