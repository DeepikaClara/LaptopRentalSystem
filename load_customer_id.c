#include <stdio.h>
#include "customer.h"

FILE * id_file,*cust_file;

int load_customer_id()
{
    cust_file = fopen("customer_details.txt","r");
    id_file = fopen("customer_id_count.txt","r");
    int id = 0;
    if(cust_file == NULL)
    {
        id_file = fopen("customer_id_count.txt","w");
        fprintf(id_file, "0");
        fclose(id_file);
    }
    else
    {
        fscanf(id_file, "%d", &id);
        fclose(id_file);
    }
 
    return id;
    }

void save_customer_id()
    {
        id_file = fopen("customer_id_count.txt","w");

        if(id_file != NULL)
        {
            fprintf(id_file,"%d",c.customer_id);
            fclose(id_file);
        }
    }

