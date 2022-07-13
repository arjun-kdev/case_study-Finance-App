
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scheme_file_operations.h"
#include "employee_file_operations.h"
#include "customer_bdb_file_operations.h"
#include "customer_file_operations.h"
#include "login_file_operations.h"
#include "ui_scheme.h"
#include "ui_employee.h"
#include "ui_customer.h"
#include "util.h"

int main()
{

    int menu;
    login loginAddr;

    do
    {
        printf("\n\tEnter Choice : \n\n\t1=>Signup(customer) \n\t2=>SignIn as customer \n\t3=>SignIn as employee\n\t4=>admin login\n\t0=>exit : ");
        scanf("%d", &menu);

        printf("\n\n\n\n");
        if (menu == 1)
        {
            registrationForCustomer();
        }
        else if (menu == 2)
        {
            dologin_customer(&loginAddr);
        }
        else if (menu == 3)
        {
           printf("\n\n\t******Enter Login credentails *******\n\n");
   
            printf("\n\temail :");
            scanf("%s", loginAddr.username);
            printf("\n\tpassword :");
            scanf("%s", loginAddr.pass);
            validate(loginAddr.username, loginAddr.pass);
        }
        else if (menu == 4)
        {
            do_adminLogin();
        }
    } while (menu == 1 || menu == 2 || menu == 3 || menu == 4);

    return EXIT_SUCCESS;
}
