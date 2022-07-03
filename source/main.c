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
void manage_scheme()
{
    int menu;
    do {
        printf("Choice (1-Add Scheme, 2-Update Loan, 3-Display Schemes, 0-Exit):\n");
        scanf("%d",&menu);
        
        if(1 == menu){
            createSchemes();
        }
        else if(3 ==  menu)
        {
          getSchemeDetails();
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
