#pragma once
#include"finance_t.h"

void ReadAll_employee_fromFile(employee *employeeHeadAddr,int *employeeCount);
void add_employee_intoFile(employee *employeeAddr);
void ReadAll_customer_fromFile(customer *customerAddr, int *customerCount);
void add_customer_intoFile(customer *customerAddr);
void update_customerinfo_intoFile(customer *customerAddr);
