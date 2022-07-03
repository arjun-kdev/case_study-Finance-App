#include"scheme_file_operations.h"
#include "util.h"
#include<stdio.h>
#include<stdlib.h>

void createSchemes(){
    int N;
    printf("Enter N  For Schemes :");
    scanf("%d",&N);
    scheme schemeObject={};
    for (int i =0 ;i< N;i++)
    {

    	  printf("\tEnter scheme ID :[%d] ",i);
        scanf("%d",&schemeObject.schemeId);
        printf("\n");
    	  printf("\tEnter schemeName at index :[%d] ",i);
        scanf("%s",schemeObject.schemeName);
        clear_buffer();
        printf("\n");
        printf("\tEnter max Amount at index :[%d] ",i);
        scanf("%lf",&schemeObject.maxLoanAmt);
        printf("\n");
        printf("\tEnter interestRate at index :[%d] ",i);
        scanf("%f",&schemeObject.interestRate);
        printf("\n");  
        printf("\tEnter tenure at index :[%d] ",i);
        scanf("%d",&schemeObject.tenure);
        printf("\n");           
        add_scheme_infoFile(&schemeObject);
    }    
    
}
void getSchemeDetails()
{
    scheme scheme[100]={};
    int noOfSchemeObject = 0;
    printf("********************Reading scheme ***************");
    ReadAll_scheme_fromFile(scheme,&noOfSchemeObject);
    printf("********************End of Read ***************");
}
void updateScheme()
{
    scheme schemes;
    int id;
    printf("Enter scheme id to find:"); scanf("%d",&id);
    scheme_bdb_readById(&schemes,id);
    
    
    printf("\n\n\nThe searched scheme:\n");    
	
	  printf("Scheme ID: %d\n", schemes.schemeId); 
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n",schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n",schemes.tenure);
    
    printf("Enter scheme Name (new) "); clear_buffer(); scanf("%[^\n]s", schemes.schemeName);
    printf("Enter maximum loan amount (new)"); scanf("%lf", &schemes.maxLoanAmt);
    printf("Enter rate of interest (new)"); scanf("%f",&schemes.interestRate);
    printf("Enter tenure (new)"); scanf("%d",&schemes.tenure);
    
    scheme_bdb_update(schemes);
    
    printf("Scheme is updated successfully.\n");
}
void deleteScheme()
{
    scheme schemes;
    int id;
    printf("Enter scheme id to find:"); scanf("%d",&id);
    scheme_bdb_readById(&schemes,id);
    
    
    printf("\n\n\nThe searched scheme:\n");    
	
	  printf("Scheme ID: %d\n", schemes.schemeId); 
    printf("Scheme Name: %s\n", schemes.schemeName);
    printf("Maximum loan amount: %lf\n",schemes.maxLoanAmt);
    printf("Rate of interest: %f\n", schemes.interestRate);
    printf("Tenure: %d\n",schemes.tenure);
   
    char ch; 
    printf("Are you sure to delete(y/n)?"); clear_buffer(); scanf("%c",&ch);
    if('y' == ch || 'Y' == ch){ 
    	scheme_bdb_delete(schemes);
    	printf("Scheme is deleted successfully.\n");
    }
}
void manage_scheme()
{
    int menu;
    do {
        printf("Choice (1-Add Scheme, 2-Update Scheme, 3-Display Schemes, 4-Delete Scheme, 0-Exit):\n");
        scanf("%d",&menu);
        
        if(1 == menu){
            createSchemes();
        }
        else if(2 == menu){
            updateScheme();
        }
        else if(3 ==  menu)
        {
            getSchemeDetails();
        }
        else if(4 == menu){
            deleteScheme();
        }
    }while(1 == menu || 2 == menu || 3 == menu);
}   

int main()
{
    
     int menu;
    
    do {
        printf("Choice (1-Manage Scheme, 2-Process Loan, 3-Release Loan, 0-Exit):\n");
        scanf("%d",&menu);
        
        if(1 == menu){
            manage_scheme(); 
        }
    }while(1 == menu || 2 == menu || 3 == menu);
    
    return EXIT_SUCCESS;
}
