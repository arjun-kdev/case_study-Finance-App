#include <stdio.h>
#include<string.h>
#include "finance_t.h"
#include "ui_employee.h"
#include "employee_file_operations.h"
#include"login_file_operations.h"

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

void validate(char username[], char pass[])
{
    //int elements_in_password = sizeof(pass) / sizeof(pass[0]);
    if (strstr(username, "@"))
    {
        if (strlen(pass) >= 8)
        {
        	int res = loginCheck(username,pass);
        	if(res==1){
            	printf("Login successful..!!");
            }else if(res==-1){
				printf("wrong password..!!");
        	}else if(res==-2){
        		printf("Wrong mail Id..!!");
        	}
    	}else
        {
            printf("Password minimum 8 characters..!!") ;
        }
    }
    else
    {
        printf("Invaild email..!!") ;
    }
}

