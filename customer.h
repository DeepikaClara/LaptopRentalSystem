#ifndef CUSTOMER_H
#define CUSTOMER_H


struct CustomerDetails
{
    int customer_id;
    char customer_name[100];
    char phone_number[25];
    char address[500];
} ;

struct CustomerDetails c;

void add_customer();

void read_customer();

void file_creation();

int load_customer_id();

void save_customer_id();

int read_customer_by_id();

int update_customer_by_id(int search_id,char new_name[],char new_phn[],char new_address[]);

int update_file(int customer_id, char customer_name[], char phone_number[], char address[]);

int delete_customer_by_id(int deleted_id);
#endif