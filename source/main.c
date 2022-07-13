
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

void addCustomer()
{
    customer customerObject = {};
    printf("\tEnter name : ");
    scanf("%s", customerObject.accHolderName);
    printf("\n");
    printf("\tEnter number : ");
    scanf("%s", customerObject.phoneNumber);
    printf("\n");
    printf("\tEnter Gender (M/F/T) : ");
    clear_buffer();
    scanf("%c", &customerObject.gender);
    printf("\n");
    printf("\tEnter e-mail : ");
    scanf("%s", customerObject.email);
    printf("\n");
    printf("\tEnter Aadhar-ID : ");
    scanf("%s", customerObject.aadhaarID);
    printf("\n");
    printf("\tEnter PAN number : ");
    scanf("%s", customerObject.panCard);
    printf("\n");
    printf("\tEnter Password : ");
    scanf("%s", customerObject.password);
    printf("\n");
    printf("\tEnter Account type : ");
    clear_buffer();
    scanf("%d", &customerObject.preferredAccountType);
    printf("\n");
    printf("\tEnter Address : ");
    scanf("%s", customerObject.address);
    printf("\n");
    char dateOfBirth[20];
    printf("\tEnter date of birth(format dd-MM-yyyy):");
    scanf("%s", dateOfBirth);
    sscanf(dateOfBirth, "%02d-%02d-%04d",
           &customerObject.DOB.day,
           &customerObject.DOB.month,
           &customerObject.DOB.year);
    add_customer_intoFile(&customerObject);
}

int main()
{

    int menu;
    login loginAddr;

    do
    {
        printf("\n\tEnter Choice : \n\n\t1=>registration as customer \n\t2=>Login as customer \n\t3=>Login as employee\n\t4=>admin login\n\t0=>exit : ");
        scanf("%d", &menu);

        printf("\n\n\n\n");
        if (menu == 1)
        {
            addCustomer();
        }
        else if (menu == 2)
        {
            dologin_customer(&loginAddr);
        }
        else if (menu == 3)
        {
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
