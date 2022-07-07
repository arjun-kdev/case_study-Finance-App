#include "finance_t.h"
#include "ui_scheme.h"
#include "scheme_file_operations.h"
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

void updateScheme()
{
    scheme schemes;
    int id;
    printf("Enter scheme id to find:");
    scanf("%d", &id);
    scheme_bdb_readById(&schemes, id);

    printf("\n\n\nThe searched scheme:\n");

    printf("Scheme ID: %d\n", schemes.schemeId);
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n", schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n", schemes.tenure);

    printf("Enter scheme Name (new) ");
    clear_buffer();
    scanf("%[^\n]s", schemes.schemeName);
    printf("Enter maximum loan amount (new)");
    scanf("%lf", &schemes.maxLoanAmt);
    printf("Enter rate of interest (new)");
    scanf("%f", &schemes.interestRate);
    printf("Enter tenure (new)");
    scanf("%d", &schemes.tenure);
    scheme_bdb_update(schemes);

    printf("Scheme is updated successfully.\n");
}
void deleteScheme()
{
    scheme schemes;
    int id;
    printf("Enter scheme id to find:");
    scanf("%d", &id);
    scheme_bdb_readById(&schemes, id);
    printf("\n\n\nThe searched scheme:\n");
    printf("Scheme ID: %d\n", schemes.schemeId);
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n", schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n", schemes.tenure);

    char ch;
    printf("Are you sure to delete(y/n)?");
    clear_buffer();
    scanf("%c", &ch);
    if ('y' == ch || 'Y' == ch)
    {
        scheme_bdb_delete(schemes);
        printf("Scheme is deleted successfully.\n");
    }
}
