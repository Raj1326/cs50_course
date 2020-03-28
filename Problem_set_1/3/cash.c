#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    float dollars;
    int count = 0;
    do
    {
        //prompt to get owed from user
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    //converting dollars to coins
    int coins = round(dollars * 100);
    int i = 0;
    //loop until there are coins
    while (coins)
    { 
        //condition for coins greater then or equal to 25 
        if (coins >= 25)
        {
            coins -= 25;
            count++;
        }
        //condition for coins greater then or equal to 10 but less then 25
        else if (coins >= 10)
        {
            coins -= 10;
            count++;
        }
        //condition for coins greater then or equal to 5 but less then 10
        else if (coins >= 5)
        {
            coins -= 5;
            count++;
        }
        //condition for coins greater then or equal to 1 but less then 5
        else
        {
            coins -= 1;
            count++;
        }
    }
    printf("%d \n", count);

}
