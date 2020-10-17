#include<stdio.h>

int main()
{
	int len,i;
	int onesCount=0;
	int presentCount=0;
	char ch;
	printf("Enter Len :");
	scanf("%d",&len);
	printf("Enter String :");
	for(i=0;i<=len;i++)
	{
		scanf("%c",&ch);
		if(ch=='1')
		{
			presentCount++;
		}
		else
		{
			if(presentCount > onesCount)onesCount=presentCount;
			presentCount=0;
		}
	}
	if(presentCount > onesCount)onesCount=presentCount;
	printf("There are %d 1's are consecutive.",onesCount);
	return 0;
}

