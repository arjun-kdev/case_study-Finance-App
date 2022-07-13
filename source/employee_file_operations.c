#include"employee_file_operations.h"
#include<stdio.h>
#include"util.h"
#include "Generic_Enums.h"
#include<string.h>

void add_employee_intoFile(employee *employeeAddr)
{
    char fileName[45];
    strcpy(fileName,getFilePath(EMPLOYEE_DB_PATH));
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(employeeAddr,1,sizeof(employee),out);

    fclose(out);
}

void employee_bdb_readall(employee *employeeList,int *employeeCount)
  {  int I=0;
    employee employeeObj;
    
    char fileName[45];
    strcpy(fileName,getFilePath(EMPLOYEE_DB_PATH));

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
int employee_bdb_count()
{ 
	int countChars = 0;
	int countObjects = 0;
	
    char fileName[45];
    strcpy(fileName,getFilePath(EMPLOYEE_DB_PATH));
    
	FILE *input = fopen(fileName,"rb"); 
    if(input == NULL)
    {
        printf("Scheme Catlog Does not exist ...!\n");
        return -1;
    }
	fseek(input,0,SEEK_END);
	countChars = ftell(input);	
	fclose(input); 	
	countObjects = countChars / (int)sizeof(scheme);
	return countObjects;
}