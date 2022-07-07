#include <stdio.h>
#include "finance_t.h"
#include "ui_customer.h"
#include "ui_scheme.h"
#include "customer_bdb_file_operations.h"
#include"login_file_operations.h"

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
	scheme scheme[100] = {};
    int noOfSchemeObject = 0;
    scheme_bdb_readAll(scheme, &noOfSchemeObject);
    displayAllSchemeObjects(scheme, noOfSchemeObject);
    printf("\n\t Please select scheme ID: \n\n");
    //ToDo insert customer and scheme detail in "Loan Application" db
    //loan applied successfully
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
                displaycustomerchoice(customerId);
            }else
            {
                printf("\n\tplease retry again\n\n");
                printf("\n\n\t******Login Unscessfull *******\n\n");
            }
}

