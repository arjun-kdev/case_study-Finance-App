
#include<string.h>
#include<stdio.h>
#include"loan_application_bdb_file_operation.h"
#include "util.h"
#include "generic_enums.h"
#include"util.h"

void loan_application_bdb_insert(application *applicationAddr)
{

    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));

    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(applicationAddr,1,sizeof(application),out);

    fclose(out);
}

void loan_application_bdb_readAll(application *loanApplicationList,int *noOfObjects)
{
    int I=0;
    application appObj;
    

    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));

    FILE* in = fopen(fileName,"rb");
    if(in == NULL){

        printf("\n\tloan list is empty\n");
        return;
    }
    while(fread(&appObj,1,sizeof(application),in)){
       loanApplicationList[I] = appObj;
        I++;
    }
    *noOfObjects = I;
    fclose(in);
}

int loan_application_bdb_readByName(application* loanApplicationAddr, char applicationCustNameAddr[])
{
    int i=0;
    application app;
    int isCustomerFound = 0;

    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));

    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("\n\tloan list is empty\n");
        return -1;
    }
    while(fread(&app,1,sizeof(application),in)){
        if(strcmp(app.CUSTOMER.accHolderName, applicationCustNameAddr) == 0){
        	(*loanApplicationAddr) = app;
        	isCustomerFound  = 1;
            break;

        }
        i++;
    }

    fclose(in);
    return isCustomerFound;
}

int loan_application_bdb_readByNameAndStatus(application* loanApplicationAddr, char applicationCustNameAddr[])
{
    int i=0;
    application app;
    int isCustomerFound = 0;
     char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));

    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return -1;
    }
    while(fread(&app,1,sizeof(application),in)){
        if(strcmp(app.CUSTOMER.accHolderName, applicationCustNameAddr) == 0){
        	if(strcmp(getStatus(app.status),"Approved") == 0){
        	(*loanApplicationAddr) = app;
        	isCustomerFound  = 1;
            break;
		}
        }
        i++;
    }

    fclose(in);
    return isCustomerFound;
}
int loan_application_bdb_readByEmail(application* loanApplicationAddr, char applicationCustEmailAddr[])
{
    int i=0;
    application app;
    int isRecordFound  = 0;

    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("\n\tNO data Found.\n");
        return -1;
    }
    while(fread(&app,1,sizeof(application),in)){
        if(strcmp(app.CUSTOMER.email, applicationCustEmailAddr) == 0){
        	(*loanApplicationAddr) = app;
            isRecordFound = 1;
        	break;
        }
        i++;
    }

    fclose(in);
    return isRecordFound;
}

void loan_application_bdb_update(application applicationAddr)
{
	
    int i=0;
    application app;
    
    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));

    FILE* in = fopen(fileName,"rb+");

    if(in == NULL){  
        printf("FILE ERROR.\n");
        return;
    }
	
    while(fread(&app,1,sizeof(application),in)){
        i++;
        if(strcmp(app.CUSTOMER.accHolderName, applicationAddr.CUSTOMER.accHolderName) == 0){          
              break;
        }       
    }
	
    if(i > 0){

       fseek(in,(i-1)*sizeof(application),SEEK_SET);
       fwrite(&applicationAddr,1,sizeof(application),in);
    }

    fclose(in);
}


int loan_application_bdb_count()
{ 
	int countChars = 0;
	int countObjects = 0;
	
    char fileName[45];
    strcpy(fileName,getFilePath(LOAN_DB_PATH));
	FILE *input = fopen(fileName,"rb"); 
    if(input == NULL)
    {
        printf("Loan list is Empty ...!\n");
       return -1;
    }
	fseek(input,0,SEEK_END);
	countChars = ftell(input);	
	fclose(input); 
	
	countObjects = countChars / (int)sizeof(application);
	return countObjects;
}

