#pragma once
#include"finance_t.h"

void ReadAll_scheme_fromFile(scheme *schemeHeadAddr,int *NoOfSchemeObjects);
void add_scheme_infoFile(scheme *schemeAddr);
void showSchemeObjects(scheme schemObject,int index);
void scheme_bdb_update(scheme schemeAddr);
void scheme_bdb_delete(scheme schemeAddr);
void scheme_bdb_readById(scheme *scheme_addr, int schemeId);
