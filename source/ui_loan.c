#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include"generic_enums.h"
#include"util.h"
#include"loan_application_bdb_file_operation.h"

void displayLoanApplicationObject(application loanApplicationObject, int Index)
{
    printf("\t %d)\n", Index + 1);
    // printf("\tCustomer Name :%s",loanApplicationObject.CUSTOMER.customerID);
    // printf("\n");
    printf("\tCustomer Name :%s", loanApplicationObject.CUSTOMER.accHolderName);
    printf("\n");
    printf("\tAAdhar ID :%s", loanApplicationObject.CUSTOMER.aadhaarID);
    printf("\n");
    printf("\tGender :%c", loanApplicationObject.CUSTOMER.gender);
    printf("\n");
    printf("\tEmail :%s", loanApplicationObject.CUSTOMER.email);
    printf("\n");
    printf("\tAddress :%s", loanApplicationObject.CUSTOMER.address);
    printf("\tPhone no :%s", loanApplicationObject.CUSTOMER.phoneNumber);
    printf("\n");
    printf("\tPAN  no :%s", loanApplicationObject.CUSTOMER.panCard);
    printf("\n"); 
    printf("\tDate of birth :");
    printf("%02d-%02d-%04d",
           loanApplicationObject.CUSTOMER.DOB.day,
           loanApplicationObject.CUSTOMER.DOB.month,
           loanApplicationObject.CUSTOMER.DOB.year);
    printf("\n");
    printf("\tScheme ID :%d", loanApplicationObject.SCHEME.schemeId);
    printf("\n");
    printf("\tScheme Name :%s", loanApplicationObject.SCHEME.schemeName);
    printf("\n");
    printf("\tLoan Amount :%lf", loanApplicationObject.SCHEME.maxLoanAmt);
    printf("\n");
    printf("\tInterest Rate :%f", loanApplicationObject.SCHEME.interestRate);
    printf("\n");
    printf("\tTenure :%d", loanApplicationObject.SCHEME.tenure);
    printf("\n");
    printf("\tEMI :%lf", loanApplicationObject.EMI);
    printf("\n");
    printf("\tStatus :%s", getStatus(loanApplicationObject.status));
    printf("\n\n\n");
}

void displayAllLoanApplicationObjects(application *applicationAddr, int applicationCount)
{
    for (int i = 0; i < applicationCount; i++)
    {
        // displayCustomerObject(applicationAddr[i], i);
        displayLoanApplicationObject(applicationAddr[i], i);
    }
}

void process_loan()
{
    printf("\n\t Below are loan applications to process: \n\n");

    int size = loan_application_bdb_count();
    if(size  == -1)
    {
        return ;
    }
    application *app = (application *)malloc(10 * sizeof(application));
    int noOfApplicationObject = 0;
    loan_application_bdb_readAll(app, &noOfApplicationObject);
    displayAllLoanApplicationObjects(app, noOfApplicationObject);

    application appObj;
    char custName[128];
    printf("\n\tEnter Customer Name to find: ");
    scanf("%s", custName);
    int isCustomerFound = loan_application_bdb_readByName(&appObj, custName);
    if (isCustomerFound == 1 && appObj.status == PENDING)
    {
        printf("\n\n\nThe searched customer Application:\n");
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
        printf("\n");
        printf("\tStatus : %s", getStatus(appObj.status));
        printf("\n\n\n");
        char ch;
        printf("\n\tSelect A : Approval R : Reject ");
        scanf(" %c", &ch);
        if ('a' == ch || 'A' == ch)
        {
            appObj.status = APPROVED;
            // strcpy(appObj.status, "Loan Application is approved");
            loan_application_bdb_update(appObj);
             printf("\n\tApplication is approved.\n");
        
        }
        else if ('r' == ch || 'R' == ch)
        {
            appObj.status = REJECTED;
            loan_application_bdb_update(appObj);
            printf("\n\tApplication is rejected.\n");
        
        }

        printf("\n\tApplication is processed successfully.\n");
        free(app);
        print_line();
    }
    else
    {
        printf("\n\tLoan Application not found for name : %s\n", custName);
        print_line();
    }
    app = NULL;
}
void release_loan()
{
    //printf("\n\t Below are loan applications to release: \n\n");
	
    int size =  loan_application_bdb_count();
    application *app = (application*) malloc (10 * sizeof(application));
    int noOfApplicationObject = 0;
    loan_application_bdb_readAll(app, &noOfApplicationObject);
    displayAllLoanApplicationObjects(app, noOfApplicationObject);

    application appObj;
    char custName[128];
    printf("\n\tEnter Customer Name to find: ");
    scanf("%s", custName);
    int isCustomerFound  = loan_application_bdb_readByNameAndStatus(&appObj, custName);
    if(isCustomerFound == 1)
    {
    printf("\n\n\nThe searched customer Application:\n");
    printf("\tCustomer Name :%s",appObj.CUSTOMER.accHolderName);
    printf("\n");
    printf("\tAadhar ID :%s",appObj.CUSTOMER.aadhaarID);
    printf("\n");
    printf("\tGender :%c",appObj.CUSTOMER.gender);
    printf("\n");
    printf("\tEmail :%s",appObj.CUSTOMER.email);
    printf("\n");  
    printf("\tAddress :%s",appObj.CUSTOMER.address);
    printf("\n");  
    printf("\tPhone no :%s",appObj.CUSTOMER.phoneNumber);
    printf("\n"); 
    printf("\tPan Card :%s",appObj.CUSTOMER.panCard);
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
    printf("\tStatus : %s",getStatus(appObj.status));
    printf("\n\n\n");

    char ch;
    printf("\n\tSelect R :  Release loan ");
    scanf(" %c", &ch);
    if('r' == ch || 'R' == ch)
    {
    releaseLoan releaseLoan;
    releaseLoan.APPLICATION = appObj;
    double releaseAmount = 0.0f;
    clear_buffer();
   
  	
  	 printf("Enter release amount :");
     scanf("%lf", &releaseAmount);
    label:
    if(releaseAmount < appObj.SCHEME.maxLoanAmt){
    	releaseLoan.releaseAmount = releaseAmount;
    	}
	else{
		printf("Enter lesser amount than maximum..");
		goto label;
		}
    clear_buffer();
    char releasedate[20];
    DOB_t dob;
    printf("Enter date of release(format dd-MM-yyyy):");
    scanf("%s", releasedate);
    sscanf(releasedate, "%02d-%02d-%04d",
           &dob.day,
           &dob.month,
           &dob.year);
		releaseLoan.releaseDate.day = dob.day;
		releaseLoan.releaseDate.month = dob.month;
		releaseLoan.releaseDate.year = dob.year;
    	appObj.status = PROCESSED;
        loan_application_bdb_update(appObj);
        release_loan_application_bdb_insert(&releaseLoan);
    }

    printf("\n\tApplication is processed successfully.\n");
    free(app);
    print_line();
    }
    else
    {
        printf("\n\tLoan Application not found for name : %s\n",custName);
        print_line();
    }   
    app = NULL;
}

