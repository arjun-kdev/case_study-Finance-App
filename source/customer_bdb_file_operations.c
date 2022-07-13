#include<stdio.h>
#include<string.h>
#include"finance_t.h"
#include"generic_enums.h"
#include"util.h"
#include"customer_bdb_file_operations.h"

void add_customer_intoFile(customer *customerAddr)
{
    
    char fileName[45];
    strcpy(fileName,getFilePath(CUSTOMER_DB_PATH));

    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(customerAddr,1,sizeof(customer),out);

    fclose(out);
}
void customer_bdb_readall(customer *customerList,int *customerCount){
    int I=0;
    customer customerObj;
    
    char fileName[45];
    strcpy(fileName,getFilePath(CUSTOMER_DB_PATH));

    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&customerObj,1,sizeof(customer),in)){
       customerList[I] = customerObj;
       I++;
    }
    *customerCount = I;
    fclose(in);
}

//customer_bdb_readByEmail
//void scheme_bdb_readById(scheme* schemeAddr, int schemeIdAddr)
void customer_bdb_readByEmail(customer* customerAddr, char customerEmailAddr[])
{
    int i=0;
    customer cust;
    

    char fileName[45];
    strcpy(fileName,getFilePath(CUSTOMER_DB_PATH));

    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&cust,1,sizeof(customer),in)){
        if(strcmp(cust.email, customerEmailAddr) == 0){
        	(*customerAddr) = cust;
        	break;
        }
        i++;
    }
    fclose(in);
}