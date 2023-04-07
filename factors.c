#include "main.h"


long unsigned int getQuotient(int index, int quo)
{
	long unsigned int quotient;
	double quoPow;

	quoPow = pow(10, index);
	quotient = quo * quoPow;
	return (quotient);
}

int getRemainder(long unsigned int divisor, long unsigned int number)
{
	int rem;

	if (number % divisor == 0)
		rem = 0;
	else
		rem = number % divisor;
	return (rem);
}

long unsigned int addRemainder(long unsigned int rem)
{
	long unsigned int addRem;
	double remPow;

	remPow = pow(10, 1);
	addRem = rem * remPow;
	return (addRem);
}

int checkPrime(long unsigned int number)
{
	int respond = 0;
	long unsigned int i;

	for (i = 2; i < number / 2; i++)
	{
		if (number % i == 0)
			respond = 1;
			break;
	}
	return (respond);
}
/**
* factorize - factorize a number into two small factors
* @num: number to factorize
* Return: an array of the factors
*/

int factorize(char *buf)
{
	long unsigned int i, num, k, j, quotient = 0, temp, tmpNum = 0, factor = 2;
	int rem, quo;
	double remPow;

	j = strlen(buf) - 1;
	temp = j;
	while (factor < 1000000000000000)
	{
		for (i = 0; i <= temp && j >= 0; i++, j--)
		{
			num = buf[i] - '0';
			if (rem > 0)
				num += addRemainder(rem);
			if ((num % factor) != 0)
			{
				if (i < temp && num < factor)
				{
					num = (num * 10) + (buf[i + 1] - '0');
					tmpNum = num;
					rem = getRemainder(factor, num);
					quo = num / factor;
					quotient += getQuotient(j - 1, quo);
					i++;
					j--;
					if (i == temp && rem == 0)
					{
						printf("%s=%lu*%lu\n", buf, quotient, factor);
						return (0);
					}
				}
				else if (factor < num)
				{
					if (i == temp)
						break;
					rem = getRemainder(factor, num);
					quo = num / factor;
					quotient += getQuotient(j, quo);
				}
			}
			else if ((num % factor) == 0)
			{
				quo = num / factor;
				rem = 0;
				quotient += getQuotient(j, quo);
				if (j == 0)
				{
					printf("%s=%lu*%lu\n", buf, quotient, factor);
					return (0);
				}
			}
		}
		factor++;
		while(1)
		{
			if (checkPrime(factor) == 0)
				break;
			if (checkPrime(factor) == 1)
				factor++;
		}
		rem = 0;
		i = 0;
		quotient = 0;
		j = temp;
	}
	/*When no factor is found*/
	printf("%s=%s*1\n", buf, buf);
	return (0);
}

/**
* main - main func
* Return : Return 0 on success
*/
int main(int argc, char *argv[])
{
	int num, fd;
	size_t numLength = 175;
	char *buf;
	long unsigned int factors;

	if (argc == 2)
	{
		FILE *fp;
		size_t getNewline;
		fp = fopen(argv[1], "r");
		if (fd == -1)
			return (-1);
		buf = (char *)malloc(sizeof(int) * numLength);
		if (buf == NULL)
			return (-1);
		while (fgets(buf, numLength, fp))
		{
			buf[strcspn(buf, "\n")] = '\0';
			factors = factorize(buf);
		}
		fclose(fp);
	}
	return (0);
}