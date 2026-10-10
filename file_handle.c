#include <stdio.h>
#include "customer.h"//header file need to be included in every c file inorder to prevent prototype mismatches and improves maintainability


FILE* file;

void file_creation()
{
file = fopen("customer_details.bin","rb");
if(file == NULL)
{
    printf("\nCustomer details file not found..\n");
    
}
else
{
    printf("\nCustomer details file Exists!\n");
    
   
}
fclose(file);
}
