#include"loan_application_bdb_file_operation.h"
#include<stdio.h>
#include<string.h>

void loan_application_bdb_insert(application *applicationAddr)
{
    char fileName[] = "loan_application_db.dat";
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
    
    char fileName[] = "loan_application_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&appObj,1,sizeof(application),in)){
       loanApplicationList[I] = appObj;
        I++;
    }
    *noOfObjects = I;
    fclose(in);
}

void loan_application_bdb_readByName(application* loanApplicationAddr, char applicationCustNameAddr[])
{
    int i=0;
    application app;
    
    char fileName[] = "loan_application_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&app,1,sizeof(application),in)){
        if(strcmp(app.CUSTOMER.accHolderName, applicationCustNameAddr) == 0){
        	(*loanApplicationAddr) = app;
        	break;
        }
        i++;
    }
    fclose(in);
}

void loan_application_bdb_readByEmail(application* loanApplicationAddr, char applicationCustEmailAddr[])
{
    int i=0;
    application app;
    
    char fileName[] = "loan_application_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&app,1,sizeof(application),in)){
        if(strcmp(app.CUSTOMER.email, applicationCustEmailAddr) == 0){
        	(*loanApplicationAddr) = app;
        	break;
        }
        i++;
    }
    fclose(in);
}

void loan_application_bdb_update(application applicationAddr)
{
	
    int i=0;
    application app;
    char fileName[] = "loan_application_db.dat";
	
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
	
    char fileName[] = "loan_application_db.dat";
	FILE *input = fopen(fileName,"r"); 
	fseek(input,0,SEEK_END);
	countChars = ftell(input);	
	fclose(input); 
	
	countObjects = countChars / (int)sizeof(application);
	return countObjects;
}

