#include<stdio.h>

void dashBoard(){
    int num;
    printf("\t========= HOT ON WHEELS RESTAURANT =========");
    printf("\n\nPlease select your option:");
    printf("\n\n1.Generate Invoice");
    printf("\n2.Show all the Inovices");
    printf("\n3.Search an Invoice");
    printf("\n4.Exit\n");

    printf("\n\nYour Choice\t:");
    scanf("%d",&num);
    fgetc(stdin);
}