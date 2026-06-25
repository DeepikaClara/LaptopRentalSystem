#include <stdio.h>
#include "customer.h"
//#include "add_customer.h"

int main()
{
    int option;
    char customer_name[50];
    c.customer_id = load_customer_id();
    file_creation();
    printf("\nRLDC COMPUTERS");
    printf("\nIf you want to login as Admin, please enter your user credentials..");
    printf("\nUsername: ");
    printf("\nPassword:");
    
    printf("\nChoose option 1 for Adding new Customers..");
    printf("\n Choose option 2 for reading all customer entries..");
    printf("\n Choose option 3 for searching customer details with customer id..");
    printf("\n Choose option 4 for updating customer details using customer id..");
    printf("\n Choose option 5 for deleting customer details using customer id");
    printf("\n Choose option 6 for exit...");

    while(1)
    {
        printf("\n\nEnter the option, you want to perform: ");
        scanf("%d",&option);
        getchar();
    //struct CustomerDetails c;
        switch(option)
        {
            case 1:
            {
                add_customer();
           // printf("Crossed add_customer function %s",c.customer_name);
                update_file(c.customer_id,c.customer_name,c.phone_number,c.address);
                //printf("Customer details were stored successfully with customer id: %d",c.customer_id);
                break;
            }
            case 2:
            {
                read_customer();
                break;
            }
            case 3:
            {
                read_customer_by_id();
                break;
            }
            case 4:
            {
                int id;
                char name[100],phone[25],address[500];
                
                printf("Enter customer ID to update: ");
                scanf("%d", &id);
                getchar();
    
                printf("Enter new name: ");
                scanf("%[^\n]", name);
                getchar();
    
                printf("Enter new phone: ");
                scanf("%[^\n]", phone);
                getchar();
    
                printf("Enter new address: ");
                scanf("%[^\n]", address);
                getchar();

                update_customer_by_id(id,name,phone,address);
                break;
            }
            case 5:
            {
                int delete_id;
                printf("\nEnter the Customer ID to be deleted: ");
                scanf("%d",&delete_id);
                getchar();

                delete_customer_by_id(delete_id);
                break;
            }
            case 6:
            {
                printf("Thanks for using RLDC Computers - Laptop rental system");
                break;
            }
        }
        if(option == 6)
        {
            break;
        }
    }
    
}

