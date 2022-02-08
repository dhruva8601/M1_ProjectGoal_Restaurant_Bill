#include<stdio.h>

struct items
{
    char item[20];
    float price;
    int qty;
};
struct orders
{
    /* data */
    char customer[50];
    char date[50];
    int numofItems;
    struct items itm[50];
};