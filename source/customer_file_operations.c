#include"customer_file_operations.h"
#include<stdio.h>
#include<string.h>



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
       I++;
    }
    *customerCount = I;
    fclose(in);
}

