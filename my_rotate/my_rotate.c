#include <stdio.h>


/*	FUNCTION PROTOTYPE	*/
unsigned short my_rotate (unsigned short,char);
void printbinery (unsigned short);


int main ()
{
	unsigned short basicNumber = 0, finalNumber=0; /*The main numbers of the input and output program*/
	int rotationsNumber = 0; /*A variable that save the number of rotations*/

	/*Receiving numbers from the user*/
	printf ("\nHi,\nplease enter a number (unsigned) that you want to rotate:\n");
	scanf ("%hu",&basicNumber);
	printf ("how many rotations do you want to do?\n");
	scanf ("%d",&rotationsNumber);

	finalNumber = my_rotate (basicNumber,rotationsNumber);

	
	/*Printing the results*/
	printf ("\nThe basic number = %d\n",basicNumber);
	printbinery (basicNumber);
	printf ("\nThe final number = %d\n",finalNumber);
	printbinery (finalNumber);

	if (rotationsNumber>=0)	/*positive number = rotating left*/
	{
		printf ("\nyou asked for rotating \"the basic number\" %d bits to the left\n",rotationsNumber);
	}
	else	/*negative number = rotating right*/
	{
		printf ("\nyou asked for rotating \"the basic number\" %d bits to the right\n",rotationsNumber*-1);
	}
	printf ("\n");

	return 0;

}


/*
 * The function Receives 2 numbers, the first one is the number that will be rotated and the second is the number of rotations.
 *	input: unsigned short = number (for rotating), int = num of rotations.
 *	output: unsigned short =  the number after the rotating.
 */
unsigned short my_rotate (unsigned short a, char b)
{

	unsigned short mask = a;  /*auxiliary variable to save carry bits*/
	b = b%(sizeof(a)*8); /*Prevents duplicate rotations*/

	if (b<0)	/*Rotate to the right*/
	{
		b=b*-1;
		mask <<= (sizeof(a)*8-b);	/*save carry bits on left */
		a >>= b;	/*do rotations*/
		a|=mask; 	/*Restores deleted bits*/

	}

	if (b>0)	/*Rotate to the left*/
	{
		mask >>= (sizeof(a)*8-b);	/*save carry bits on right*/
		a <<= b;	/*do rotations*/
		a|=mask;	/*Restores deleted bits*/

	}
	return a;
}


/*
 * The function get input number and print (on the standart output) this number in binery.
 *	input: unsigned number
 *	output: --------------
 */
void printbinery (unsigned short x)
{
	unsigned short mask = 1<<(sizeof(x)*8-1); /*Loop variable,Starts in MSB*/

	while (mask)
	{
		if( (x&mask) == 0) /*print '0' or '1'*/
			printf ("0");
		else
			printf ("1");

		mask >>= 1; /*Promotion loop*/
	}
	printf ("\n");
}


