#include"scheme_file_operations.h"
#include<stdio.h>
#include<string.h>

void add_scheme_intoFile(scheme *schemeAddr)
{
    char fileName[] = "scheme_db.dat";
    FILE* out = fopen(fileName,"ab");
    if(out == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    
    fwrite(schemeAddr,1,sizeof(scheme),out);

    fclose(out);
}

void scheme_bdb_readAll(scheme *schemeList,int *noOfObjects){
    int I=0;
    scheme schemeObj;
    
    char fileName[] = "scheme_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&schemeObj,1,sizeof(scheme),in)){
       schemeList[I] = schemeObj;
        I++;
    }
    *noOfObjects = I;
    fclose(in);
}
void scheme_bdb_readById(scheme* schemeAddr, int schemeIdAddr)
{
    int i=0;
    scheme sch;
    
    char fileName[] = "scheme_db.dat";
    FILE* in = fopen(fileName,"rb");
    if(in == NULL){
        printf("FILE ERROR.\n");
        return;
    }
    while(fread(&sch,1,sizeof(scheme),in)){
        if(sch.schemeId == schemeIdAddr){
        	(*schemeAddr) = sch;
        	break;
        }
        i++;
    }
    fclose(in);
}
void scheme_bdb_update(scheme schemeAddr)
{
	
    int i=0;
    scheme sch;
    char fileName[] = "scheme_db.dat";
	
    FILE* in = fopen(fileName,"rb+");

    if(in == NULL){  
        printf("FILE ERROR.\n");
        return;
    }
	
    while(fread(&sch,1,sizeof(scheme),in)){
        i++;
        if(sch.schemeId == schemeAddr.schemeId){          
              break;
        }       
    }
	
    if(i > 0){

       fseek(in,(i-1)*sizeof(scheme),SEEK_SET);
       fwrite(&schemeAddr,1,sizeof(scheme),in);
    }

    fclose(in);
}
void scheme_bdb_delete(scheme schemeAddr)
{
    int i=0;
    scheme sch;
    char fileName[] = "scheme_db.dat";
    char tempFileName[] = "schemeTemp_db.dat";
	
    FILE* in = fopen(fileName,"r");
    FILE* out = fopen(tempFileName,"w");
	
    if(in == NULL){
        printf("(in)FILE ERROR.\n");
        return;
    }
    
    if(out == NULL){
        printf("(out)FILE ERROR.\n");
        return;
    }
	
    while(fread(&sch,1,sizeof(scheme),in)){
       i++;
        if(sch.schemeId != schemeAddr.schemeId){          
              fwrite(&sch,1,sizeof(scheme),out);
	
        }       
    }
    
    fclose(out);
    fclose(in);

    remove(fileName);

    rename(tempFileName,fileName);
}

int scheme_bdb_count(){ 
	int countChars = 0;
	int countObjects = 0;
	
    char fileName[] = "scheme_db.dat";
	FILE *input = fopen(fileName,"r"); 
	fseek(input,0,SEEK_END);
	countChars = ftell(input);	
	fclose(input); 
	
	countObjects = countChars / (int)sizeof(scheme);
	return countObjects;
}