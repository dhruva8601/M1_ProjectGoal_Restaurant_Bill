/**
 * @file restaurant_bill.h
 * @author Dhruva Kumar
 * @brief creating structures for variables
 * @version 0.1
 * @date 2022-02-10
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __RESTAURANT_BILL_H__
#define __RESTAURANT_BILL_H__


#include "math.h"

typedef struct entity_item{
char item[100];
	float price;
	float qty;
}items;

typedef struct entity_orders{
	char customer[100];
	char date[30];
	int numOfitems;
    items itm[50];
}orders;

#endif //#ifndef RESTAURANT_BILL