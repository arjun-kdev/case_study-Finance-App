#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "generic_enums.h"
#include "finance_t.h"
#include "ui_customer.h"
#include "ui_scheme.h"
#include "customer_file_operations.h"
#include "customer_bdb_file_operations.h"
#include "loan_application_bdb_file_operation.h"
#include "login_file_operations.h"
#include "util.h"

login *customerLoggedIn;

void displayAllCustomerObjects(customer *customerAddr, int customerCount)
{
    for (int i = 0; i < customerCount; i++)
    {
        displayCustomerObject(customerAddr[i], i);
    }
}
void displayCustomerObject(customer customerObject, int Index)
{

    printf("\tName :%s", customerObject.accHolderName);
    printf("\n");
    printf("\tPhone :%s", customerObject.phoneNumber);
    printf("\n");
    printf("\tGender :%c", customerObject.gender);
    printf("\n");
    printf("\tEmail :%s", customerObject.email);
    printf("\n");
    printf("\tAddress :%s", customerObject.address);
    printf("\n");
    printf("\tAccountType :%d", customerObject.preferredAccountType);
    printf("\n");
    printf("\tDate of birth :");
    printf("%02d-%02d-%04d",
           customerObject.DOB.day,
           customerObject.DOB.month,
           customerObject.DOB.year);
    printf("\n");
}
void updateProfile()
{
    printf("Below fields only permitted to update :\n\n");
    printf("Select the field you want to update :\n\n");
    int opt = -1;
    printf("1.Name\n2.number\n3.password\n");
    scanf("%d", &opt);
    customer customerObject = {};
	customer_bdb_readByEmail(&customerObject, customerLoggedIn->username);
    switch (opt)
    {
    case 1:
        printf("\tEnter new name : ");
        scanf("%s", customerObject.accHolderName);
        printf("\n");
        break;
    case 2:
        printf("\tEnter newnumber : ");
        scanf("%s", customerObject.phoneNumber);
        printf("\n");
        break;
    case 3:
        printf("\tEnter new password : ");
        scanf("%s", customerObject.password);
        printf("\n");
        break;
    }
    update_customer_bdb_update_intoFile(&customerObject, customerLoggedIn->username);
}

void applyForLoan()
{
    printf("\n\t Below are available scheme: \n\n");

    int size = scheme_bdb_count();
    if(size  == -1)
    {
        printf("\n\tPlease contact to support team\n");
        return ;
    }
    scheme *sch = (scheme *)malloc(size * sizeof(scheme));
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
    applicationObj.EMI = (P * (R / 100) * pow((1 + (R / 100)), T) / (pow((1 + (R / 100)), (T - 1))));

    applicationObj.status = PENDING;
    // strcpy(applicationObj.status, "Loan Application is pending for approval");

    printf("\n\nBelow is the scheme you have selected:\n\n");
    printf("Scheme ID: %d\n", schemes.schemeId);
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n", schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n", schemes.tenure);
    // printf("customerLoggedIn is: %s\n", customerLoggedIn->username);
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
void withDrawloanApplication()
{
    application appObj;
    int isRecordFound = 0;
    isRecordFound = loan_application_bdb_readByEmail(&appObj, customerLoggedIn->username);
    if (isRecordFound == 1 && appObj.status == PROCESSED)
    {
        printf("\n\t You can withdraw loan application as it is already processed ..!\n");
        return;
    }
    else if (isRecordFound == 1 && appObj.status != PROCESSED)
    {
        char ch;
        printf("\n\tSure ??Do you want to withdraw loan applicatio(y/n): ");
        scanf(" %c", &ch);
        if ('y' == ch || 'Y' == ch)
        {
            appObj.status = WITHDRAWAL;
            // strcpy(appObj.status, "Loan Application is approved");
            loan_application_bdb_update(appObj);
            printf("\n\tload application withdrawn :(\n");
            print_line();
        }
    }
    else
    {
        printf("\n\t You have not applied to any loan ..!\n");
    }
}
void statusOfLoan()
{
    //printf("\n\t Below is current status of your loan: \n\n");

    application appObj;

    int isRecordFound = 0;
    isRecordFound = loan_application_bdb_readByEmail(&appObj, customerLoggedIn->username);

    if (isRecordFound == 1)
    {
        printf("\tCustomer Name :%s", appObj.CUSTOMER.accHolderName);
        printf("\n");
        printf("\tAAdhar ID :%s", appObj.CUSTOMER.aadhaarID);
        printf("\n");
        printf("\tGender :%c", appObj.CUSTOMER.gender);
        printf("\n");
        printf("\tEmail :%s", appObj.CUSTOMER.email);
        printf("\n");
        printf("\tAddress :%s", appObj.CUSTOMER.address);
        printf("\n");
        printf("\tPhone no :%s", appObj.CUSTOMER.phoneNumber);
        printf("\n");
        printf("\tPhone no :%s", appObj.CUSTOMER.panCard);
        printf("\n");
        printf("\tDate of birth :");
        printf("%02d-%02d-%04d",
               appObj.CUSTOMER.DOB.day,
               appObj.CUSTOMER.DOB.month,
               appObj.CUSTOMER.DOB.year);
        printf("\n");
        printf("\tScheme ID :%d", appObj.SCHEME.schemeId);
        printf("\n");
        printf("\tScheme Name :%s", appObj.SCHEME.schemeName);
        printf("\n");
        printf("\tLoan Amount :%lf", appObj.SCHEME.maxLoanAmt);
        printf("\n");
        printf("\tInterest Rate :%f", appObj.SCHEME.interestRate);
        printf("\n");
        printf("\tTenure :%d", appObj.SCHEME.tenure);
        printf("\n");
        printf("\tEMI :%lf", appObj.EMI);
        printf("\n***************************************************\n");
        printf("\tStatus :%s", getStatus(appObj.status));
        printf("\n***************************************************\n");
        printf("\n\n");
    }
    else
    {
        // printf("\n\t You have not applied to any loan ..!\n");
    }
}

void displaycustomerchoice(char *customerId)
{
    int menu;
    do
    {
        printf("\n\tChoice (\n\t1-Update profile\n\t2-apply for Loan\n\t3-Status of loan \n\t4-withdraw loan application\n\t0-Exit):\n\n");
        scanf("%d", &menu);
        if (1 == menu)
        {
            updateProfile();
        }
        else if (2 == menu)
        {
            applyForLoan();
        }
        else if (3 == menu)
        {
            statusOfLoan();
        }
        else if (4 == menu)
        {
            withDrawloanApplication();
        }

    } while (1 == menu || 2 == menu || 3 == menu || 4 == menu);
}
void dologin_customer(login *loginAddr)
{
    char customerId[32];
    printf("\n\n\t******Enter Login credentails *******\n\n");
    printf("\n\temail :");
    scanf("%s", loginAddr->username);
    printf("\n\tpassword :");
    scanf("%s", loginAddr->pass);
    int isValidLogin = validatelogin(loginAddr->username, loginAddr->pass, customerId);
    if (isValidLogin)
    {
        printf("\n\n\t******Login success *******\n\n");
        customerLoggedIn = (login *)malloc(sizeof(login));
        strcpy(customerLoggedIn->username, loginAddr->username);
        displaycustomerchoice(customerId);
    }
    else
    {
        printf("\n\tplease retry again\n\n");
        printf("\n\n\t******Login Failed *******\n\n");
    }
}

void readAllCustomers()
{
    customer customer[256] = {};
    int noOfcustomerObject = 0;
    customer_bdb_readall(customer, &noOfcustomerObject);
    displayAllCustomerObjects(customer, noOfcustomerObject);
}

void registrationForCustomer()
{
    customer customerObject = {};
    printf("\tEnter name : ");
    scanf("%s", customerObject.accHolderName);
    printf("\n");
    printf("\tEnter number : ");
    scanf("%s", customerObject.phoneNumber);
    printf("\n");
    printf("\tEnter Gender (M/F/T) : ");
    clear_buffer();
    scanf("%c", &customerObject.gender);
    printf("\n");
    printf("\tEnter e-mail : ");
    scanf("%s", customerObject.email);
    printf("\n");
    printf("\tEnter Aadhar-ID : ");
    scanf("%s", customerObject.aadhaarID);
    printf("\n");
    printf("\tEnter PAN number : ");
    scanf("%s", customerObject.panCard);
    printf("\n");
    printf("\tEnter Password : ");
    scanf("%s", customerObject.password);
    printf("\n");
    printf("\tEnter Account type : ");
    clear_buffer();
    scanf("%d", &customerObject.preferredAccountType);
    printf("\n");
    printf("\tEnter Address : ");
    scanf("%s", customerObject.address);
    printf("\n");
    char dateOfBirth[20];
    printf("\tEnter date of birth(format dd-MM-yyyy):");
    scanf("%s", dateOfBirth);
    sscanf(dateOfBirth, "%02d-%02d-%04d",
           &customerObject.DOB.day,
           &customerObject.DOB.month,
           &customerObject.DOB.year);
    add_customer_intoFile(&customerObject);
}
