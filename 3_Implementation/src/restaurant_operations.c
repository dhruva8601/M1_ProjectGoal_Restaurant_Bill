#include "../inc/restaurant_operations.h"

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