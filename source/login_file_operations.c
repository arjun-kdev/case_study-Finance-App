#include"login_file_operations.h"
#include<stdio.h>
#include<string.h>

int loginCheck(char username[], char pass[])
{
    employee emp;
    
    char fileName[] = "employee_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return 0;
    }
    while(fread(&emp,1,sizeof(employee),in)){
        if(strcmp(emp.email,username) == 0){
        	if(strcmp(emp.password,pass) == 0){
        		return 1;
        	}else {
        		return -1;
        	}
    }else {
    return -2;
    }
    fclose(in);
}
}


int validatelogin(char *username ,char *pass,char customerId[])
{ 
    int isvalidLogin = 0;
    customer sch;
    char fileName[] = "customer_db.dat";
    
    FILE* in = fopen(fileName,"r");
    
    if(in == NULL){
        printf("\n\t(in)FILE ERROR.\n");
        return -1;
    }
    
    while(fread(&sch,1,sizeof(customer),in)){
     
        if(strcmp(sch.email,username) == 0)
        {          

             if(strcmp(sch.password,pass) == 0)
             {
                strcpy(customerId,sch.customerID);
                isvalidLogin = 1;
             }
        }       
    }
    fclose(in);
    return isvalidLogin;
}

