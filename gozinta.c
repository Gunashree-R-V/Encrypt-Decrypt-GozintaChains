#include "gozinta.h"

/*	Function to get the proper divisors of a given number	*/
int *divisors(int n,int *arrsize)
{
	int *arr = (int *)calloc(sizeof(int),1);
	int j = 0;
    for (int i=1; i<n; i++)
    {
        if (n%i == 0)
        {
		arr[j] = i;
		j += 1;
		arr = (int *)realloc(arr,sizeof(int)*(j+1));
        }
    }
    *arrsize = j;
    return arr;
}

/*	Function which returns the list of lists of gozinta chains of a given number	
 *	Example :- gozinta(15) returns  {{1,15},{1,3,15},{1,5,15}}
 */
 
list *gozinta(int num,int *m)
{
	list *retarr = (list *)calloc(sizeof(list),1);
	int size;
	int *div = divisors(num,&size);
	/*	If num is 1 then returns {{1}}	*/
	if(size==0)
	{
		retarr[0].arr = (int *)calloc(sizeof(int),1);
		retarr[0].arr[0] = 1;
		*m = 1 ; 
		retarr[0].n = 1;
		return retarr; 
	}
	/*	Otherwise recursively find gozinta for each divisor 	*/
	int iin = 0;
	for(int i=0 ; i<size ; ++i)
	{
		int inM;
		list *gozArr = gozinta(div[i] , &inM);
		int gozi ;
		for(gozi=0;gozi<inM ; gozi++,iin++)
		{
			retarr = (list *)realloc(retarr,sizeof(list)*(iin+1));
			retarr[iin].n =  gozArr[gozi].n+1;
			retarr[iin].arr = (int *)calloc(sizeof(int) , retarr[iin].n);
			int jin;
			/*	Copy the gozinta list to main list	*/
			for(jin=0 ; jin<gozArr[gozi].n; ++jin)
			{
				retarr[iin].arr[jin] = gozArr[gozi].arr[jin];
			}
			/*	Append number itself for each list in the list	*/
			retarr[iin].arr[jin] = num;
		}
		free(gozArr);
	}
	*m = iin;
	/*	Return main list of lists	*/
	return	retarr;
}

/*	Function to return the longest gozinta chain	*/
int *maxiGozinta(int num,int *len)
{
	int m;
	list *arr = gozinta(num, &m);
	int *maxi = maximum(arr,m,len);
	free(arr);
	return maxi;	
}

/*	Function to find the longest gozinta chain	*/
int *maximum(list *arr , int m , int *len)
{
	int max = 0;
	int maxi = 0;
	for(int i=0;i<m;++i)
	{
		int n = arr[i].n;
		if(max < n)
		{
			max = n;	
			maxi = i;
		}
	}
	*len = arr[maxi].n;
	return arr[maxi].arr;
}

