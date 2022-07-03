#pragma once
#include"finance_t.h"

void ReadAll_scheme_fromFile(scheme *schemeHeadAddr,int *NoOfSchemeObjects);
void add_scheme_infoFile(scheme *schemeAddr);
void showSchemeObjects(scheme schemObject,int index);
void  scheme_update(scheme schemeToUpdate);
void scheme_read_byid(scheme *scheme_addr, int scheme_id);
