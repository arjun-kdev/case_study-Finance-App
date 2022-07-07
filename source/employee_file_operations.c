#include"employee_file_operations.h"
#include<stdio.h>
#include<string.h>

void add_employee_intoFile(employee *employeeAddr)
{
    char fileName[] = "employee_db.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(employeeAddr,1,sizeof(employee),out);

    fclose(out);
}
void add_customer_intoFile(customer *customerAddr)
{
    char fileName[] = "customer_db.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(customerAddr,1,sizeof(customer),out);

    fclose(out);
}
void showEmployeeObjects(employee employeeObject,int Index)
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
void employee_bdb_readall(employee *employeeList,int *employeeCount){
    int I=0;
    employee employeeObj;
    
    char fileName[] = "employee_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&employeeObj,1,sizeof(employee),in)){
       employeeList[I] = employeeObj;
       showEmployeeObjects(employeeList[I],I);
       I++;
    }
    *employeeCount = I;
    fclose(in);
}
void showCustomerObjects(customer customerObject,int Index)
{
      
        printf("\tName :%s",customerObject.accHolderName);
        printf("\n");
    	printf("\tPhone :%s",customerObject.phoneNumber);
        printf("\n");
        printf("\tGender :%c",customerObject.gender);
        printf("\n");
        printf("\tEmail :%s",customerObject.email);
        printf("\n"); 
         printf("\tPassword :%s",customerObject.password);
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
void customer_bdb_readall(customer *customerList,int *customerCount){
    int I=0;
    customer customerObj;
    
    char fileName[] = "customer_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&customerObj,1,sizeof(customer),in)){
       customerList[I] = customerObj;
       showCustomerObjects(customerList[I],I);
       I++;
    }
    *customerCount = I;
    fclose(in);
}

