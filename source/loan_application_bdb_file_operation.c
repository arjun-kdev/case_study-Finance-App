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