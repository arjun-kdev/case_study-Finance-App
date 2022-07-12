 #include "util.h"
 void clear_buffer()
 {
    while ((getchar()) != '\n');
 }
 void print_line()
 {
   printf("\n\t^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
 }
 char * getStatus(int iStatus)
 {

   if(iStatus == 0)
   {
      return "Pending";

   }else if(iStatus == 1)
   {
      return "Approved";
   }
   else if(iStatus ==2)
   {
      return "Rejected";
   }else if(iStatus == 3)
   {
      return "Processed";
   }else if(iStatus == 4)
   {
      return "Withdrawn";
   }else
   {
      return "Unknown";
   }

 }