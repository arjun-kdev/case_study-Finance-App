#include "finance_t.h"
#include "ui_employee.h"
#include <stdio.h>

void displayAllEmployeeObjects(employee *employeeAddr, int employeeCount)
{
    for (int i = 0; i < employeeCount; i++)
    {
        displayEmployeeObject(employeeAddr[i], i);
    }
}
void displayEmployeeObject(employee employeeObject,int Index)
{
      
        printf("\tEmployee ID :%s",employeeObject.empId);
        printf("\n");
    	printf("\tEmployee Name :%s",employeeObject.employeeName);
        printf("\n");
        printf("\tPhone :%s",employeeObject.phoneNumber);
        printf("\n");
        printf("\tGender :%c",employeeObject.gender);
        printf("\n");  
        printf("\temail :%s",employeeObject.email);
        printf("\n"); 
		printf("\tDate of birth :"); 
		printf("%02d-%02d-%04d",
		    employeeObject.DOB.day,
		    employeeObject.DOB.month,
		    employeeObject.DOB.year);
        printf("\n");   
}
