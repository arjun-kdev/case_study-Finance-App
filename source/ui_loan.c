#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include"loan_application_bdb_file_operation.h"

void displayLoanApplicationObject(application loanApplicationObject,int Index)
{ 
    printf("\t %d)\n",Index+1);
    //printf("\tCustomer Name :%s",loanApplicationObject.CUSTOMER.customerID);
    //printf("\n");
    printf("\tCustomer Name :%s",loanApplicationObject.CUSTOMER.accHolderName);
    printf("\n");
    printf("\tAAdhar ID :%s",loanApplicationObject.CUSTOMER.aadhaarID);
    printf("\n");
    printf("\tGender :%c",loanApplicationObject.CUSTOMER.gender);
    printf("\n");
    printf("\tEmail :%s",loanApplicationObject.CUSTOMER.email);
    printf("\n");  
    printf("\tAddress :%s",loanApplicationObject.CUSTOMER.address);
    printf("\n");  
    printf("\tPhone no :%s",loanApplicationObject.CUSTOMER.phoneNumber);
    printf("\n"); 
    printf("\tPhone no :%s",loanApplicationObject.CUSTOMER.panCard);
    printf("\n");
    printf("\tDate of birth :"); 
    printf("%02d-%02d-%04d",
        loanApplicationObject.CUSTOMER.DOB.day,
        loanApplicationObject.CUSTOMER.DOB.month,
        loanApplicationObject.CUSTOMER.DOB.year);
    printf("\n");
    printf("\tScheme ID :%d",loanApplicationObject.SCHEME.schemeId);
    printf("\n");
    printf("\tScheme Name :%s",loanApplicationObject.SCHEME.schemeName);
    printf("\n");
    printf("\tLoan Amount :%lf",loanApplicationObject.SCHEME.maxLoanAmt);
    printf("\n");
    printf("\tInterest Rate :%f",loanApplicationObject.SCHEME.interestRate);
    printf("\n");
    printf("\tTenure :%d",loanApplicationObject.SCHEME.tenure);
    printf("\n");
    printf("\tEMI :%lf",loanApplicationObject.EMI);
    printf("\n");
    printf("\tStatus :%s",loanApplicationObject.status);
    printf("\n\n\n");
        
}

void displayAllLoanApplicationObjects(application *applicationAddr, int applicationCount)
{
    for (int i = 0; i < applicationCount; i++)
    {
        //displayCustomerObject(applicationAddr[i], i);
        displayLoanApplicationObject(applicationAddr[i], i);
    }
}

void process_loan()
{
    printf("\n\t Below are loan applications to process: \n\n");
	
    int size =  loan_application_bdb_count();
    application* app = (application*) malloc (size * sizeof(application));
    int noOfApplicationObject = 0;
    loan_application_bdb_readAll(app, &noOfApplicationObject);
    displayAllLoanApplicationObjects(app, noOfApplicationObject);

    application appObj;
    char custName[128];
    printf("Enter Customer Name to find:");
    scanf("%s", custName);
    loan_application_bdb_readByName(&appObj, custName);

    printf("\n\n\nThe searched customer Application:\n");

    printf("\tCustomer Name :%s",appObj.CUSTOMER.accHolderName);
    printf("\n");
    printf("\tAAdhar ID :%s",appObj.CUSTOMER.aadhaarID);
    printf("\n");
    printf("\tGender :%c",appObj.CUSTOMER.gender);
    printf("\n");
    printf("\tEmail :%s",appObj.CUSTOMER.email);
    printf("\n");  
    printf("\tAddress :%s",appObj.CUSTOMER.address);
    printf("\n");  
    printf("\tPhone no :%s",appObj.CUSTOMER.phoneNumber);
    printf("\n"); 
    printf("\tPhone no :%s",appObj.CUSTOMER.panCard);
    printf("\n");
    printf("\tDate of birth :"); 
    printf("%02d-%02d-%04d",
        appObj.CUSTOMER.DOB.day,
        appObj.CUSTOMER.DOB.month,
        appObj.CUSTOMER.DOB.year);
    printf("\n");
    printf("\tScheme ID :%d",appObj.SCHEME.schemeId);
    printf("\n");
    printf("\tScheme Name :%s",appObj.SCHEME.schemeName);
    printf("\n");
    printf("\tLoan Amount :%lf",appObj.SCHEME.maxLoanAmt);
    printf("\n");
    printf("\tInterest Rate :%f",appObj.SCHEME.interestRate);
    printf("\n");
    printf("\tTenure :%d",appObj.SCHEME.tenure);
    printf("\n");
    printf("\tEMI :%lf",appObj.EMI);
    printf("\n");
    printf("\tStatus :%s",appObj.status);
    printf("\n\n\n");

    char ch;
    printf("\nSelect A : Approval R : Reject");
    scanf(" %c", &ch);
    if('a' == ch || 'A' == ch)
    {
        strcpy(appObj.status, "Loan Application is approved");
        loan_application_bdb_update(appObj);

    }
    else if('r' == ch || 'R' == ch)
    {
        strcpy(appObj.status, "Loan Application has been rejected");
        loan_application_bdb_update(appObj);
    }

    printf("Application is processed successfully.\n");
    
    free(app);
    app = NULL;
}