#include <stdio.h>
#include "customer.h"

FILE *file;
void read_customer()
{
    
   file=fopen("customer_details.bin","r"); 
   
//    char data;
//    while((data = fgetc(file)) != EOF)
//    {
//     printf("%c",data);
//    } 
    if(file ==NULL)
    {
        printf("file not found!\n");
    }
    else
    {
        while(fread(&c,sizeof(c),1,file) == 1)
        {
            printf("\nCustomer ID: %d", c.customer_id);
        printf("\nCustomer Name: %s", c.customer_name);
        printf("\nCustomer Phone Number: %s", c.phone_number);
        printf("\nCustomer Address: %s\n", c.address);
        printf("------------------------\n");
        }
    }
    fclose(file); 
}


int read_customer_by_id()
{
    int search_id, found=0; 
    char line[256];
    file = fopen("customer_details.bin","rb"); //since using fread using binary "rb"

    printf("Enter the customer ID to search: ");
    scanf("%d", &search_id);
    getchar();

    if(file == NULL)
    {
        printf("File not found!\n");
        return -1;
    }
    else
    {
        //printf("Entered into customer search loop..\n");
        // while(fscanf(file,"Customer ID: %d\n",&c.customer_id)==1)
        // {
        //     fscanf(file,"Customer Name: %[^\n]\n",&c.customer_name);
        //     fscanf(file,"Phone Number: %[^\n]\n",&c.phone_number);
        //     fscanf(file,"Address: %[^\n]\n",&c.address);
        //     fgets(line,sizeof(line),file);//skips separator line

        //using fread for reading struct data from file
        while(fread(&c,sizeof(c),1,file) ==1) 
        {
            if(c.customer_id == search_id)
            {
                printf("\nCustomer with Customer ID %d Found!",c.customer_id);
                printf("\nCustomer Name: %s",c.customer_name);
                printf("\nCustomer Phone Number: %s",c.phone_number);
                printf("\nCustomer Address: %s",c.address);
                found=1;
                break;
            }
        }
    
        if(found != 1)
        {
            printf("Customer not found!\n");
        }
    }
        fclose(file);
        return 0;
    
}