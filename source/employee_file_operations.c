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
       I++;
    }
    *employeeCount = I;
    fclose(in);
}
