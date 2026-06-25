#include <stdio.h>
#include <string.h>
#include "customer.h"

FILE * temp_file,* cust_file;

struct CustomerDetails cust;
int found=0;

int delete_customer_by_id(int deleted_id)
{
    cust_file = fopen("customer_details.bin","rb");

    if(cust_file == NULL)
    {
        printf("Customer File not found\n");
    }
    else
    {
        temp_file =  fopen("temporary.bin","wb");//opening temporary bin file

        while(fread(&cust,sizeof(cust),1,cust_file) == 1)//reading struct one by one
        {
            if(cust.customer_id != deleted_id) //if customer id not matches then storing that struct details in temp file
            {
                fwrite(&cust,sizeof(cust),1,temp_file);
                //printf("\nCustomer id copied into temp file is: %d",cust.customer_id);
                found =1;
            }   
        }
        fclose(cust_file);
        fclose(temp_file);

        if(found)
        {
            remove("customer_details.bin"); //removing older file
            rename("temporary.bin","customer_details.bin"); //renaming temp_file which had deleted particular customer details
            printf("\nCustomer details of ID %d deleted succesfully!\n",deleted_id);
            return 0;
        }
        else
        {
            printf("Customer not deleted..\n");
            return -1;
        }
    }
    
}
