/**
 * @file SRC.c
 * @author Dhruva
 * @brief Restaurant Invoice Generator, which helps you keep track of your generated invoices
 * @version 0.1
 * @date 2022-02-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "generateBill.h"
#include "dashboard.h"


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



int main(){
    struct orders o1,o2;
    //dashboard
    int num,n;
    char name[50];
    char savebill = 'y', contFlag ='y';
    FILE *fp;
    while(contFlag =='y'){
    system("clear");
    float total;
    int invoiceFound =0;
    
    switch (num)
    {
    case 1:
    system("clear"); // clears the output before the execution of next block
    printf("\nPlease enter the name of the customer\t: ");
    fgets(o1.customer,50,stdin);
    o1.customer[strlen(o1.customer)-1]=0; //to remove the last (\n) character from name variable
    strcpy(o1.date,__DATE__);
    printf("\nPlease enter the number of Items\t:");
    scanf("%d",&n);
    o1.numofItems=n;

    for(int i=0;i<n;i++){
        fgetc(stdin);
        printf("\n\n");
        printf("Please enter the item %d\t\t:",i+1);
        fgets(o1.itm[i].item,20,stdin);
        o1.itm[i].item[strlen(o1.itm[i].item)-1]=0;
        printf("\nPlease enter the quantity\t\t:");
        scanf("%d",&o1.itm[i].qty);
        printf("\nPlease enter the price of one item\t:");
        scanf("%f",&o1.itm[i].price);
        total += o1.itm[i].qty * o1.itm[i].price;
    }
    generateBillHeader(o1.customer,o1.date);
    for(int i=0;i<o1.numofItems;i++){
        generateBillBody(o1.itm[i].item,o1.itm[i].qty,o1.itm[i].price);        

    }
    billfooter(total);
    printf("\n DO you want to save the Invoice [y/n]:\t");
    scanf("%s",&savebill);

    if(savebill == 'y'){
        fp = fopen("Invoice.txt","a+");
        fwrite(&o1,sizeof(struct orders), 1,fp);
        if(fwrite != 0){
            printf("\n Successfully Saved");
        }
        else{
            printf("\n Error Saving");
        }
        fclose(fp);
    }
     break;
    case 2 :
    system("clear");
    fp = fopen("Invoice.txt","rb+");
    printf("\n *****Your Previous Invoices*****\n");
    while(fread(&o2,sizeof(struct orders),1,fp)){
        float tot = 0;
        generateBillHeader(o1.customer,o1.date);
        for(int i=0;i<o2.numofItems;i++){
            generateBillBody(o1.itm[i].item,o1.itm[i].qty,o1.itm[i].price);
            tot+=o1.itm[i].qty*o1.itm[i].price;
        }
        billfooter(tot);
    }
    fclose(fp);
    break;

    case 3: 
    printf("\n Enter the name of the customer:\t");
    fgets(name,50,stdin);
    name[strlen(name)-1]=0;
    system("clear");
    fp = fopen("Invoice.txt","rb+");
    printf("\t*****Invoice of %s*****\n",name);
    while(fread(&o2,sizeof(struct orders),1,fp)){
        float tot = 0;
        if(!strcmp(o1.customer,name)){
        generateBillHeader(o1.customer,o1.date);
        for(int i=0;i<o2.numofItems;i++){
            generateBillBody(o1.itm[i].item,o1.itm[i].qty,o1.itm[i].price);
            tot+=o1.itm[i].qty*o1.itm[i].price;
        }
        billfooter(tot);
        invoiceFound =1;
        }
        
    }
    if(invoiceFound != 0){
        printf("Sorry the invoice for %s doesn't exists",name );
    }
    fclose(fp);
    break;

    case 4:
    printf("\n\t\tThankyou for using the software ");
    exit(0);
    break;
    
    default:
    printf("\nSorry Invalid Option");
        break;
    }
    printf("\n Do you want to perform another operation? [y/n]: \t");
    scanf("%s",&contFlag);
    }
    printf("\n\t\tThankyou for using the software ");
    printf("\n\n");
return 0;
}