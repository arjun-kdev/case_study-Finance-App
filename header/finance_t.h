#pragma once

struct scheme_
{
int schemeId;
char schemeName[120];
double maxLoanAmt;
float interestRate;
int tenure;// 45 months
}; 
typedef struct scheme_ scheme;

typedef struct _DOB_t
{
	int day;
	int month;
	int year;
}DOB_t;

struct customer_
{
	char accHolderName[128];
	char phoneNumber[16];
	char gender;
	char email[128];
	char aadhaarID[16];
	char panCard[16];
	char customerID[32];
	char password[32];
	int  preferredAccountType;
	char address[256];
  	DOB_t DOB;
  	
}__attribute__((__packed__));

typedef struct customer_ customer;

struct employee_
{
	char empId[10];
	char employeeName[128];
	char phoneNumber[16];
	char gender;
	char email[128];
	char password[32];
    	DOB_t DOB;
}__attribute__((__packed__));

typedef struct employee_ employee;

struct application_
{
	scheme SCHEME;
	customer CUSTOMER;
	double EMI;
	//char status[128];
	int status:4;
	int applicationId;
}; 
typedef struct application_ application;

struct releaseLoan_
{
	application APPLICATION;
	double releaseAmount;
	DOB_t releaseDate;
}; 
typedef struct releaseLoan_ releaseLoan;