#pragma once
#include"finance_t.h"

void loan_application_bdb_insert(application *applicationAddr);
void loan_application_bdb_readAll(application *loanApplicationList,int *noOfObjects);
int loan_application_bdb_readByName(application* loanApplicationAddr, char applicationCustNameAddr[]);
int loan_application_bdb_readByEmail(application* loanApplicationAddr, char applicationCustEmailAddr[]);
void loan_application_bdb_update(application applicationAddr);
int loan_application_bdb_count();






