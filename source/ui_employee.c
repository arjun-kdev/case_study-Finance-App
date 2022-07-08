#include <stdio.h>
#include <string.h>
#include "finance_t.h"
#include "ui_employee.h"
#include "ui_customer.h"
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

void displayAdminMenu()
{
    int menu;
    do
    {
        printf("\n\tChoice (1-Manage Scheme, 2-Process Loan, 3-Release Loan,\n\t4-Add Customer, 5-Update Customer,6- Add Employee,\n\t7-Read all customers,8- Read all employees, 0-Exit/logout): ");
        scanf("%d", &menu);

        if (1 == menu)
        {
            manage_scheme();
        }
        /*else if (4 == menu)
        {
            addCustomer();
        }
        else if (5 == menu)
        {
            // updateCustomer();
        }*/
       /* else if (6 == menu)
        {
            addEmployee();
        }*/
        else if (7 == menu)
        {
            readAllCustomers();
        }
        else if (8 == menu)
        {
            readAllEmployees();
        }

    } while (1 == menu || 2 == menu || 3 == menu || 4 == menu || 5 == menu || 6 == menu || 7 == menu || 8 == menu);
}
void validate(char username[], char pass[])
{
    //int elements_in_password = sizeof(pass) / sizeof(pass[0]);
    if (strstr(username, "@"))
    {
        if (strlen(pass) >= 4)
        {
        	int res = loginCheck(username,pass);
        	if(res==1){
            	printf("Login successful..!!");
                displayAdminMenu();
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


void do_adminLogin()
{
            char username[32],pass[32];
            printf("\n\n\t******Enter Login credentails *******\n\n");
            printf("\n\temail :");
            scanf("%s",username);
            printf("\n\tpassword :");
            scanf("%s",pass);
           if((strcmp(username,"admin@gmail.com")==0)&&(strcmp(pass,"admin123")==0))
           {
             displayAdminMenu();
           }else
           {
                printf("\n\tplease retry again\n\n");
                printf("\n\n\t******Login Unscessfull *******\n\n");
                return;
           }
}

void addEmployee()
{
    employee employeeObject = {};
    printf("\tEnter Id : ");
    scanf("%s", employeeObject.empId);
    printf("\n");
    printf("\tEnter name : ");
    scanf("%s", employeeObject.employeeName);
    printf("\n");
    printf("\tEnter number : ");
    scanf("%s", employeeObject.phoneNumber);
    printf("\n");
    printf("\tEnter Gender (M/F/T) : ");
    clear_buffer();
    scanf("%c", &employeeObject.gender);
    printf("\n");
    printf("\tEnter e-mail : ");
    scanf("%s", employeeObject.email);
    printf("\n");
    printf("\tEnter Password : ");
    scanf("%s", employeeObject.password);
    printf("\n");
    clear_buffer();
    char dateOfBirth[20];
    printf("Enter date of birth(format dd-MM-yyyy):");
    scanf("%s", dateOfBirth);
    sscanf(dateOfBirth, "%02d-%02d-%04d",
           &employeeObject.DOB.day,
           &employeeObject.DOB.month,
           &employeeObject.DOB.year);
    add_employee_intoFile(&employeeObject);
}
void readAllEmployees()
{
    employee employee[256] = {};
    int noOfemployeeObject = 0;
    employee_bdb_readall(employee, &noOfemployeeObject);
    displayAllEmployeeObjects(employee,noOfemployeeObject);
}
