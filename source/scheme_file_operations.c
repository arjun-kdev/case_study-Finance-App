#include"scheme_file_operations.h"
#include<stdio.h>
#include<string.h>

void add_scheme_infoFile(scheme *schemeAddr)
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
void showSchemeObjects(scheme schemObject,int Index)
{
        printf("\n %d)\n",Index);
        printf("\tScheme ID :%d",schemObject.schemeId);
        printf("\n");
    	  printf("\tScheme Name :%s",schemObject.schemeName);
        printf("\n");
        printf("\tMax loan Amount :%lf",schemObject.maxLoanAmt);
        printf("\n");
        printf("\tinterestRate :%f",schemObject.interestRate);
        printf("\n");  
        printf("\ttenure :%d",schemObject.tenure);
        printf("\n");  
                 
}
void ReadAll_scheme_fromFile(scheme *schemeList,int *NoOfSchemes){
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
       showSchemeObjects(schemeList[I],I);
       I++;
    }
    *NoOfSchemes = I;
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
