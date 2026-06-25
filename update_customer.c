#include <stdio.h>
#include <string.h>
#include "customer.h"

FILE *file;
int update_file(int customer_id, char customer_name[], char phone_number[], char address[])
{
file = fopen("customer_details.bin","ab");//since using fwrite using append binary here
if(file == NULL)
{
    printf("File not exist");
    return -1;
}
else
{
// fprintf(file,"Customer ID: %d\n",customer_id);
// fprintf(file,"Customer Name: %s\n",customer_name);
// fprintf(file,"Phone Number: %s\n",phone_number);
// fprintf(file,"Address: %s\n",address);
// fputs("------------------------\n",file);

//populate global struct
c.customer_id = customer_id;
strcpy(c.customer_name,customer_name);
strcpy(c.phone_number,phone_number);
strcpy(c.address,address);

//write entire struct into file at once
//using fwrite to store struct data at once
fwrite(&c,sizeof(c),1,file);
printf("\nCustomer details were saved successfully with customer id: %d\n",customer_id);
}

fclose(file);

return 0;
}

int update_customer_by_id(int search_id,char new_name[],char new_phn[],char new_address[])
{
    FILE *temp_file;
    struct CustomerDetails temp_customer;
    int found =0;

    file = fopen("customer_details.bin","rb");
    if(file == NULL)
    {
        printf("file not found\n");
        return -1;
    }
    else
    {
        temp_file = fopen("temp.bin","wb");
        while(fread(&temp_customer,sizeof(c),1,file)==1)
        {
            if(temp_customer.customer_id == search_id)
            {
                strcpy(temp_customer.customer_name,new_name);
                strcpy(temp_customer.phone_number,new_phn);
                strcpy(temp_customer.address,new_address);
                found = 1;
                printf("Customer %d updated!\n",search_id);
            }
            fwrite(&temp_customer,sizeof(c),1,temp_file);
        }
        fclose(file);
        fclose(temp_file);

        if(found)
        {
            remove("customer_details.bin");
            rename("temp.bin","customer_details.bin");
            return 0;
        }
        else
        {
            printf("Customer not found!\n");
            return -1;
        }
    }
}