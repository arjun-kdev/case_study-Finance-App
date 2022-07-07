#include<stdio.h>
#include<string.h>
#include"finance_t.h"
#include"customer_bdb_file_operations.h"

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