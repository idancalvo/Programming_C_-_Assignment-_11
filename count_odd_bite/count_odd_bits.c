#include <stdio.h>


/*	FUNCTION PROTOTYPE	*/
int count_odd_bits (unsigned long);
unsigned long makeMaskOdd ();


int main ()
{
	unsigned long num; /*save - user number*/
	int oddBitsNum; /*save - sum odds bits are'ON'*/
	printf ("Hi,\nplease enter a number (unsigned)\n");
	scanf("%lu",&num);
	oddBitsNum = count_odd_bits(num);
	printf ("In the number %lu , there are %d bits 'ON' in odd place \n",num,oddBitsNum);
	return 0;
}


/*
 * The function count the number of the odds bits which in 'ON'status.
 * 	input: unsigned number
 *	output: sum of the odds bits which in 'ON' status
 */
int count_odd_bits (unsigned long num)
{
	unsigned long oddnum = num & makeMaskOdd(); /*only odd bits stay 'ON'*/
	int cnt=0; /*counter for the 'ON' bits*/

	while (oddnum) /*checking how many bits are 'ON'*/
	{
			cnt ++;
			oddnum &= (oddnum-1);
	}
	return cnt;
}


/*
* The function creates an auxiliary variable (number) with odds bits in 'ON' only
*	input: -----
*	output: number with odds bits in 'ON' only
*/
unsigned long makeMaskOdd ()
{
	int size = (sizeof(unsigned long)*8)/2; /*type's length*/
	unsigned long mask = 2; /*set the first bit*/
	while (size) /*put '1' on any odd bit*/
	{
		mask <<=2;
		mask +=2;
		size--;
	}
	return mask;
}




















