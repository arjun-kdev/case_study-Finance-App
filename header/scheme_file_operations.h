#pragma once
#include"finance_t.h"

void scheme_bdb_readAll(scheme *schemeHeadAddr,int *NoOfSchemeObjects);
void add_scheme_intoFile(scheme *schemeAddr);
void showSchemeObjects(scheme schemObject,int index);
void scheme_bdb_update(scheme schemeAddr);
void scheme_bdb_delete(scheme schemeAddr);
void scheme_bdb_readById(scheme *scheme_addr, int schemeId);
