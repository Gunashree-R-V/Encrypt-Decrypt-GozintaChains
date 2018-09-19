#include <stdio.h>
#include <stdlib.h>

typedef struct list{
	int *arr;
	int n;	
}list;

list *arr2D;

int *maximum(list *arr , int m , int *len);
int *divisors(int n,int *arrsize);
list *gozinta(int num,int *m);
int *maxiGozinta(int num, int *len);

