#pragma once

struct scheme_
{
int schemeId;
char schemeName[120];
double maxLoanAmt;
float interestRate;
int tenure;
}; 
typedef struct scheme_ scheme;

typedef struct _DOB_t
{
	int Day;
	int Month;
	int Year;
}DOB_t;

struct customer_
{
	char AccHolderName[128];
	char PhoneNumber[16];
	char Gender;
	char Email[128];
	char AadhaarID[16];
	char PanCard[16];
	char CustomerID[32];
	char Password[32];
	int  PreferredAccountType;
	char Address[256];
  	DOB_t DOB;
  	scheme appliedScheme;
}__attribute__((__packed__));

typedef struct customer_ customer;

struct employee_
{
	char empId[10];
	char employeeName[128];
	char PhoneNumber[16];
	char Gender;
	char Email[128];
	char Password[32];
    	DOB_t DOB;
}__attribute__((__packed__));

typedef struct employee_ employee;


