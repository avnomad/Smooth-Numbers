#include <stdio.h>
#include <stdlib.h>

#define length(A) (sizeof(A)/sizeof(A[0]))
typedef unsigned long long int ull;
typedef unsigned int ui;

ui primes[] = {
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,
	73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,
	151,157,163,167,173,179,181,191,193,197,199,211,223,227,
	229,233,239,241,251,257,263,269,271,277,281,283,293,307,
	311,313,317,331,337,347,349,353,359,367,373,379,383,389,
	397,401,409,419,421,431,433,439,443,449,457,461,463,467,
	479,487,491,499,503,509,521,523,541,547,557,563,569,571,
	577,587,593,599,601,607,613,617,619,631,641,643,647,653,
	659,661,673,677,683,691,701,709,719,727,733,739,743,751,
	757,761,769,773,787,797,809,811,821,823,827,829,839,853,
	857,859,863,877,881,883,887,907,911,919,929,937,941,947,
	953,967,971,977,983,991,997,1009,1013,1019,1021
}; // primes


ull i,j;
ui b;
ui smooths = 0;
ui *primes_end;	// points just after the greatest prime <= b



static void count_smooths(ui *prime,ull accumulated_product)
{
	if(prime == primes_end)
	{
		if(accumulated_product <= j && accumulated_product >= i)
			smooths++;
	}
	else
		while(accumulated_product <= j)
		{
			count_smooths(prime+1,accumulated_product);
			accumulated_product *= *prime;
		} // end while
} // end count_smooths




int main(int argc, char* argv[])
{
	// read input
	if(argc != 4)
	{
		printf("Usage: smooth b i j\n");
		return 1;
	} // end if
	sscanf(argv[1], "%u",  &b);
	sscanf(argv[2], "%lu", &i);
	sscanf(argv[3], "%lu", &j);

	// preparations
	primes_end = primes;
	while(*primes_end <= b && primes_end < primes+length(primes))
		primes_end++;

	// actual work	
	count_smooths(primes,1);

	printf("%d\n",smooths);
	return 0;
}
