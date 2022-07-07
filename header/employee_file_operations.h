#pragma once
#include"finance_t.h"

void employee_bdb_readall(employee *employeeHeadAddr,int *employeeCount);
void add_employee_intoFile(employee *employeeAddr);
void validate(char username[], char pass[]);