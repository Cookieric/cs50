#include <string.h>
#include <stdio.h>
#include <stdbool.h>
// using namespace std;
//istream& getline (char* s, streamsize n );
//istream& getline (char* s, streamsize n, char delim );
//Get line Extracts characters from the stream as unformatted input and stores them into s as a c-string, until either the extracted character is the delimiting character
int main ()
{
	char s[100];
	char Ans[100];
	// char test[6];
	// cout << "Please, enter your full name: ";
	printf("Please, enter your full name: ");
	fgets(s, sizeof(s), stdin);
    // scanf("%s %s %s",&s,&s1,&s2);
    // strcat(s," ");
    // strcat (s,s1);
    // strcat(s," ");
    // strcat (s,s2);
	// getline (cin,s);// get input string from cin in arg.
	// cout<<sizeof(test);
	// cin.getline(test,sizeof(test));//get input string from string variable in std cin
	// cout<<test<<endl;
	// cout << "Hello, " << s << "!\n";
	// system("pause");
	int i=0,j=0;
	bool flag=true;
	while(s[i]!='\0')
	{
		if(s[i]==' ')
		{
			flag=false;
			i++;
			if(s[i]!=' ')	flag=true;
			continue;
		}
	    if(flag)
	    {
	    	Ans[j]=s[i];
	    	flag=false;
	    	++j;
	    }
	    ++i;
	}
	// cout<<j<<endl;
	for(int z=0;z<j;++z)
	{
	    // cout<<Ans[z];
	    printf("%c",Ans[z]);
	}
	printf("\n");
	return 0;
}
// int main(void)
// {
//     char s[]={0},s1[]={0},s2[]={0};
//     sscanf("%s %s %s",&s,&s1,&s2);
//     printf("%s %s %s",s,s1,s2);
//     system("pause");
//     char * Ans[]={0};
//     int i=0,j=0,k=0;
//     while(s[i]!='\0')
//     {
//         while(s[i]!=' ')
//         {
//             Ans[j][k]=s[i];
//             i++;
//             k++;
//         }
//         i++;
//         j++;
//         k=0;
//     }
//     for(int z=0;z<j;++z)
//     {
//         printf("%s",Ans[z]);
//     }
//     return 0;
// }
