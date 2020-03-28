#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        // Prompt user for height
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int x, i, j, k;
    // outer loop to handle number of rows 
    for (i = height ; i >= 1 ; i--)
    {
        // inner loop to handle number spaces 
        // values changing acc. to requirement
        for (j = 1 ; j < i ; j++)
        {
            printf(" ");
        }
        //  inner loop to handle number of columns 
        //  values changing acc. to outer loop 
        for (k = height ; k >= i ; k--)
        {
            // printing hash
            printf("#");
        }
        // ending line after each row
        printf("  ");
        for (j = 0 ; j <= height - i ; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}
