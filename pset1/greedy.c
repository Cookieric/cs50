#include <stdio.h>
#include <cs50.h>
#include <math.h>


void fflushstdin( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}

int main()
{
    // Prompt user for valid input (amount of change owed) and convert it to number of cents
    float amount=0;
    int c=0,cnt=0;
    do
    {
        cnt=0;
        printf("O hai! How much change is owed?\n");
        scanf("%f",&amount);
        // printf("amount:%f\n",amount);
        while( (c = fgetc( stdin )) != EOF && c != '\n' )   
        {
            // printf("%d\n",c);
            cnt++;
        }
        printf("\n");
    }   while ((amount < 0) || (cnt != 0));
    
    // printf("amount:%f\n",amount);
    // printf("cnt:%d\n",cnt);
    // Finding minimum number of coins needed by decreasing it with each possible largest coin value
    int number_of_coins = 0;
    int cents = (int) round(amount * 100);
    // printf("cents:%d\n",cents);
    number_of_coins += cents / 25;
    cents %= 25;

    number_of_coins += cents / 10;
    cents %= 10;

    number_of_coins += cents / 5;
    cents %= 5;

    number_of_coins += cents;
    
    printf("%d\n", number_of_coins);
}