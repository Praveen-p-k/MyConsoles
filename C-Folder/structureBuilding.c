#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 30
#define MED 15
#define MIN 10


struct Items 
{
    char name[MAX];
    int quantity;
    float rate;
} item[5];

struct Invoices 
{
    struct Items item;
    char uom[MIN];
    float subTotal;
    float tax;
    struct tm;
    struct Invoices *nextItem;
};
typedef struct Invoices invoices;

struct Customer
{
    char customerName[MAX];
    long int phone;
    float total;
    int dayCount;
    invoices *itemHead, *itemTail;
    invoices *collection[100];
    struct Customer *nextCustomer;

} *customerHead = NULL, *customerTail = NULL;
typedef struct Customer customer;

int main ()
{
    customer *newCustomer = (customer*) malloc (sizeof(customer));
    strcpy(newCustomer->customerName, "Praveen");
    newCustomer->phone = 9876543210;
    newCustomer->total = 0;
    newCustomer->dayCount = 1;
    
    invoices *newInvoices = (invoices*) malloc (sizeof(invoices));
    strcpy(newInvoices->item.name, "Rice");
    newInvoices->item.quantity = 2;
    newInvoices->item.rate = 200;
    strcpy(newInvoices->uom, "Kgs");
    newInvoices->subTotal = 0;
    newInvoices->tax = 10;
    newInvoices->currentDate = time(NULL);
    struct tm *local_time = localtime(&newInvoices->currentDate);
    newInvoices->currentDate = 
}