#include <stdio.h>

#include "customer.h"

void add_customer()
{
    //struct object from customer.h is global and can be used in this function
    
 

   //printing customer details
    printf("Customer Name: ");
    scanf("%[^\n]%*c",&c.customer_name);
    //getchar();

    printf("\nCustomer phone number: ");
    scanf("%[^\n]%*c",&c.phone_number);
    //getchar();

    printf("\n Customer Address:");
    scanf("%[^\n]%*c",&c.address);
    //getchar();
    c.customer_id++;
    save_customer_id(c.customer_id);

    printf("-------------------------------------------------------------");
}