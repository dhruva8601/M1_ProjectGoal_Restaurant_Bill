#include "../inc/restaurant_operations.h"

void generate_header(char name[100], time_t date);
void generate_body( items item);
void generate_footer(float total);

/* Start of Application */
int main(){
int num;
time_t date;//prints date on the invoice
time(&date);
orders order,order_to_show;
char save= 'y',contFlag='y';
FILE *fp;
char name[100];
while(contFlag =='y'){
	system("clear");
	float total=0;
	int invoiceFound = 0;
	printf("\t======== HOT ON WHEELS RESTAURANT ==========");
	printf("\n\nPlease select an operation :");
	printf("\n\n1. Generate Invoice");
	printf("\n\n2. Show all Invoices");
	printf("\n\n3. Search Invoice");
	printf("\n\n4. Exit");
	printf("\n\nYour choice:\t");
	scanf("%d",&num);
	fgetc(stdin);
	switch(num){
		case 1:
		system("clear");
		printf("Enter the name of customer :\t");
		fgets(order.customer,100,stdin);
		order.customer[strlen(order.customer)-1] =0;
		printf("\nEnter number of items buyed:\t");
		scanf("%d",&order.numOfitems);
		for(int i=0;i<order.numOfitems;i++){//enters the loop with the no.of items you bought
			fgetc(stdin);
			printf("\n\n");
			printf("Please Enter the name of item %d \t:",i+1);
			fgets(order.itm[i].item,20,stdin);
			order.itm[i].item[strlen(order.itm[i].item)-1] = 0;
			printf("Please Enter the Quantity\t\t:");
			scanf("%f",&order.itm[i].qty);
			printf("Please enter the unit price\t\t:");
			scanf("%f",&order.itm[i].price);
			total= total_bill(order.itm[i].qty, order.itm[i].price);//calls total_bill function 			
		}
		generate_header(order.customer,date);
		for(int i=0;i<order.numOfitems;i++){
			generate_body(order.itm[i]);
		}
		generate_footer(total);
		printf("\nDo you want to save invoice [y/n]\t:");
		scanf("%1s",&save);
		if(save =='n'||save=='N'){
			break;
		}
		else{
			printf("\nEnter correct value [y/n]\t:");
			scanf("%1s",&save);
		}
		if(save == 'y' || save == 'Y'){//saves the bill in file and reads the contents when invoked in case2
			fp = fopen("InvoiceBill.txt","a+");
			fwrite(&order,sizeof(orders),1,fp);			
			if(fwrite != 0)
			printf("\n Invoice Successfully Saved\n");
			else
			printf("\n Error in  Saving\n");
			fclose(fp);
		}
		break;

		case 2:
		system("clear");
		fp = fopen("InvoiceBill.txt","r");
		if(fp){		
		printf("\n ****** Your Previous Invoices ********\n");
		while (fread(&order_to_show,sizeof(orders),1,fp))
		{
			float total_to_show = 0;
			generate_header(order_to_show.customer, date);
			for(int i = 0; i<order_to_show.numOfitems;i++){
				generate_body(order_to_show.itm[i]);
				total_to_show+= order_to_show.itm[i].qty * order_to_show.itm[i].price;
			}
			generate_footer(total_to_show);	
		
		}		fclose(fp);
		}
		else{
			printf("\n************* Sorry no Saved Invoices **************\n");
		}
		break;

		case 3:
		system("clear");
		printf("\nEnter name of customer\t:");
		fgets(name,50,stdin);
		name[strlen(name)-1]=0;
		fp = fopen("InvoiceBill.txt","r");
		printf("\n \t****** Invoice of %s ********",name);
		while (fread(&order_to_show,sizeof(orders),1,fp))
		{			
			float total_to_show = 0;
			if(!strcmp(order_to_show.customer,name)){
				generate_header(order_to_show.customer, date);
				for(int i = 0; i<order_to_show.numOfitems;i++){
				generate_body(order_to_show.itm[i]);
				total_to_show+= order_to_show.itm[i].qty * order_to_show.itm[i].price;
			}
			generate_footer(total_to_show);	
			invoiceFound = 1;		
		}	
			}
			if(!invoiceFound){
				printf("\nSorry the invoice for %s does not exist",name);
			}
			fclose(fp);
		break;

		case 4:
		printf("\n\t\t Bye bye \n\n");
		exit(0);
		break;
		default:
		printf("Sorry... Invalid Option!!!");
		break;
		
	}
	printf("\n Do you want to perform another operation [y/n]?\t:");
	scanf("%1s",&contFlag);
	}
	printf("\n\t\t Bye bye \n\n");
	return 0;
}
void generate_header(char name[100], time_t date){
	printf("\n\n" );
	printf("\t  HOT ON WHEELS RESTAURANT");
	printf("\n\t   ================");
	printf("\n Date: %s", ctime(&date));
	printf("\n Invoice To: %s",name);
	printf("\n");
	printf("============================================\n");
	printf("Items\t\t");
	printf("Quantity\t\t");
	printf("Total\t\t");
	printf("\n============================================");
	printf("\n\n");
}
void generate_body(items item){
	printf("%s\t\t",item.item);
	printf("%.2f\t\t", item.qty);
	printf("%.2f\t\t", item.qty * item.price);
	printf("\n");
}
void generate_footer(float total){
	printf("\n");	
	float netTotal = net_total(total);
	float grandTotal = grand_total(netTotal);
	printf("-------------------------------------------\n");
	printf("Sub Total\t\t\t%.2f",total);
	printf("\nDiscount @20%s\t\t\t%.2f","%",0.2*total);
	printf("\n\t\t\t\t----------");
	printf("\nNet Total\t\t\t%.2f",netTotal);
	printf("\nGST @18%s\t\t\t%.2f","%",0.18*netTotal);
	printf("\n-------------------------------------------");
	printf("\n Grand Total\t\t\t%.2f",grandTotal);
	printf("\n-------------------------------------------\n");
}
float total_bill(float quantity, float price){
    float total=0;
        total = quantity * price; // calculates the total for the customer
    return total;
}

float net_total(float total){
    float dis = 0.2 * total; //20% discount
    total = total - dis;
    return total;
}

float grand_total(float net_total){
    float gst = 0.18 * net_total; //GST @18%
    float grand_total = net_total + gst;
    return grand_total;
}
int save_bill( orders order){
    FILE *fp;
    fp = fopen("InvoiceBill.txt","a+");
			fwrite(&order,sizeof(orders),1,fp);
            fclose(fp);
			if(fwrite != 0)
				return 1;
			else
			return -1;
}

