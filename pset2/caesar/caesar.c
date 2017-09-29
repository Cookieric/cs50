// #include <iostream>
// #include <string>
#include <stdio.h>
// using namespace std;

int main ()
{
	char s[6]="hello";
	char c[6];
	int cnt=3,k=0,i=0,j=0;//secret key
	while(s[i]!='\0')
	{
		if(k%cnt==0)	k=0;
		int shift=k%26;
		int tempCovert=s[i]+shift;
		if(('A'<=tempCovert&&tempCovert<='Z')||('Z'<tempCovert&&tempCovert<'a'))
		{
			if(tempCovert>'Z')
				tempCovert='A'+tempCovert-'Z'-1;
			c[i]=tempCovert;
		}
		else if(('a'<=tempCovert&&tempCovert<='z')||tempCovert>'z')
		{
			if(tempCovert>'z')
				tempCovert='a'+tempCovert-'z'-1;
			c[i]=tempCovert;
		}
		++k;
		++i;
	}
	c[i]='\0';
	printf("plaintext:%s\n",s);
	printf("ciphertext:");
	while(c[j]!='\0')	
	{
		printf("%c",c[j]);
		j++;
	}
	printf("\n");
	return 0;
}