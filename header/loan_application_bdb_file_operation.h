#pragma once
#include"finance_t.h"

void loan_application_bdb_insert(application *applicationAddr);
void release_loan_application_bdb_insert(releaseLoan *releaseloanAddr);
void loan_application_bdb_readAll(application *loanApplicationList,int *noOfObjects);
int loan_application_bdb_readByName(application* loanApplicationAddr, char applicationCustNameAddr[]);
int loan_application_bdb_readByEmail(application* loanApplicationAddr, char applicationCustEmailAddr[]);
void loan_application_bdb_update(application applicationAddr);
int loan_application_bdb_count();
int loan_application_bdb_readByNameAndStatus(application* loanApplicationAddr, char applicationCustNameAddr[]);

void loan_bdb_delete(application applicationAddr);





