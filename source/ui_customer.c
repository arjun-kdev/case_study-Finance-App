#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "finance_t.h"
#include "ui_customer.h"
#include "ui_scheme.h"
#include "customer_file_operations.h"
#include "customer_bdb_file_operations.h"
#include "loan_application_bdb_file_operation.h"
#include"login_file_operations.h"

login *customerLoggedIn;

void displayAllCustomerObjects(customer *customerAddr, int customerCount)
{
    for (int i = 0; i < customerCount; i++)
    {
        displayCustomerObject(customerAddr[i], i);
    }
}
void displayCustomerObject(customer customerObject,int Index)
{
      
      
        printf("\tName :%s",customerObject.accHolderName);
        printf("\n");
    	printf("\tPhone :%s",customerObject.phoneNumber);
        printf("\n");
        printf("\tGender :%c",customerObject.gender);
        printf("\n");
        printf("\tEmail :%s",customerObject.email);
        printf("\n");  
        printf("\tAddress :%s",customerObject.address);
        printf("\n");  
        printf("\tAccountType :%d",customerObject.preferredAccountType);
        printf("\n"); 
		printf("\tDate of birth :"); 
		printf("%02d-%02d-%04d",
		    customerObject.DOB.day,
		    customerObject.DOB.month,
		    customerObject.DOB.year);
        printf("\n");  
}

void applyForLoan()
{
	printf("\n\t Below are available scheme: \n\n");
	
    int size =  scheme_bdb_count();
    scheme* sch = (scheme*) malloc (size * sizeof(scheme));
    int noOfSchemeObject = 0;
    scheme_bdb_readAll(sch, &noOfSchemeObject);
    displayAllSchemeObjects(sch, noOfSchemeObject);

    scheme schemes;
    int id;
    printf("\n\t Please select scheme ID: \n\n");
    scanf("%d", &id);
    scheme_bdb_readById(&schemes, id);

    customer cust;
    customer_bdb_readByEmail(&cust, customerLoggedIn->username);
    
    application applicationObj;
    strcpy(applicationObj.CUSTOMER.accHolderName, cust.accHolderName);
    strcpy(applicationObj.CUSTOMER.aadhaarID, cust.aadhaarID);
    strcpy(applicationObj.CUSTOMER.accHolderName, cust.accHolderName);
    strcpy(applicationObj.CUSTOMER.address, cust.address);
    applicationObj.CUSTOMER.gender = cust.gender;
    strcpy(applicationObj.CUSTOMER.phoneNumber, cust.phoneNumber);
    strcpy(applicationObj.CUSTOMER.email, cust.email);
    applicationObj.CUSTOMER.DOB.day = cust.DOB.day;
    applicationObj.CUSTOMER.DOB.month = cust.DOB.month;
    applicationObj.CUSTOMER.DOB.year = cust.DOB.year;
    strcpy(applicationObj.CUSTOMER.panCard, cust.panCard);

    applicationObj.SCHEME.schemeId = schemes.schemeId;
    strcpy(applicationObj.SCHEME.schemeName, schemes.schemeName);
    applicationObj.SCHEME.maxLoanAmt = schemes.maxLoanAmt;
    applicationObj.SCHEME.interestRate = schemes.interestRate;
    applicationObj.SCHEME.tenure = schemes.tenure;

    double P = schemes.maxLoanAmt;
    float R = schemes.interestRate;
    int T = schemes.tenure;
    applicationObj.EMI = ( P * ( R / 100 ) * pow( (1 + (R / 100) ), T ) / ( pow( (1 + ( R / 100) ),( T - 1) ) ) );

    strcpy(applicationObj.status, "Loan Application is pending for approval");

    printf("\n\nBelow is the scheme you have selected:\n\n");
    printf("Scheme ID: %d\n", schemes.schemeId);
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n", schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n", schemes.tenure);
    //printf("customerLoggedIn is: %s\n", customerLoggedIn->username);
    printf("EMI on Maximum loan amount is: %lf\n", applicationObj.EMI);

    char ch;
    printf("\nPlease confirm (y/n)?");
    clear_buffer();
    scanf("%c", &ch);
    if ('y' == ch || 'Y' == ch)
    {
        loan_application_bdb_insert(&applicationObj);
        printf("\nLoan is applied successfully.");
        printf("\nLoan status will be updated after verification.\n");
    }

    free(sch);
    sch = NULL;
}

void statusOfLoan()
{
    printf("\n\t Below is current status of your loan: \n\n");

    application appObj;
    //char custName[128];
    //printf("Enter Customer Name to find:");
    //scanf("%s", custName);
    loan_application_bdb_readByEmail(&appObj, customerLoggedIn->username);

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
    printf("\n***************************************************\n");
    printf("\tStatus :%s",appObj.status);
    printf("\n***************************************************\n");
    printf("\n\n");
}

void displaycustomerchoice(char *customerId)
{
    int menu;
    do
    {
        printf("\n\tChoice (\n\t1-Update profile\n\t2-apply for Loan\n\t3-read all loan types\n\t4-update loan application\n\t5-Status of loan \n\t6-withdraw loan application\n\t0-Exit):\n\n");
        scanf("%d", &menu);
        if(2 == menu)
        {
			applyForLoan();
		}
        if(5 == menu)
        {
			statusOfLoan();
		}
    } while (1 == menu || 2 == menu || 3 == menu || 4 == menu || 5 == menu );
}
void dologin_customer(login *loginAddr)
{
            char customerId[32];
            printf("\n\n\t******Enter Login credentails *******\n\n");
            printf("\n\temail :");
            scanf("%s",loginAddr->username);
            printf("\n\tpassword :");
            scanf("%s",loginAddr->pass);
            int isValidLogin = validatelogin(loginAddr->username,loginAddr->pass,customerId);
            if(isValidLogin)
            {    
                printf("\n\n\t******Login successfull *******\n\n");
                customerLoggedIn = (login*) malloc (sizeof(login));
                strcpy(customerLoggedIn->username,loginAddr->username);
                displaycustomerchoice(customerId);
            }else
            {
                printf("\n\tplease retry again\n\n");
                printf("\n\n\t******Login Unscessfull *******\n\n");
            }
}


void readAllCustomers()
{
    customer customer[256] = {};
    int noOfcustomerObject = 0;
    customer_bdb_readall(customer, &noOfcustomerObject);
    displayAllCustomerObjects(customer,noOfcustomerObject);
}
