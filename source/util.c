#include "util.h"
void clear_buffer()
{
   while ((getchar()) != '\n')
      ;
}
void print_line()
{
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}
char *getStatus(int iStatus)
{
   if (iStatus == 0)
   {
      return "Pending";
   }
   else if (iStatus == 1)
   {
      return "Approved";
   }
   else if (iStatus == 2)
   {
      return "Rejected";
   }
   else if (iStatus == 3)
   {
      return "Processed";
   }
   else if (iStatus == 4)
   {
      return "Withdrawn";
   }
   else
   {
      return "Unknown";
   }
}
char * getFilePath(int code)
{
 if (code  == 0)
   {
      return "../DB/customer_db.dat";
   }
   else if (code == 1)
   {
      return "../DB/employee_db.dat";
   }
   else if (code == 2)
   {
      return "../DB/loan_application_db.dat";
   }
   else if (code == 3)
   {
      return "../DB/release_loan_db.dat";
   }
   else if(code == 4)
   {
      return "../DB/scheme_db.dat";
   }
   else
   {
      return "";
   }  
}