#include "finance_t.h"
#include "ui_customer.h"
#include <stdio.h>

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
