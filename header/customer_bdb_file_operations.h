#include "finance_t.h"
int validatelogin(char *username ,char *pass,char customerId[]);
void add_customer_intoFile(customer *customerAddr);
void customer_bdb_readall(customer *customerList,int *customerCount);
void customer_bdb_readByEmail(customer* customerAddr, char customerEmailAddr[]);

