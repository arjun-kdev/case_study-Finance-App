#pragma once
#include"finance_t.h"

void employee_bdb_readall(employee *employeeHeadAddr,int *employeeCount);
void add_employee_intoFile(employee *employeeAddr);
void customer_bdb_readall(customer *customerAddr, int *customerCount);
void add_customer_intoFile(customer *customerAddr);
void update_customerinfo_intoFile(customer *customerAddr);
