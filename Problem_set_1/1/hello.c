#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //name variable to get the name from user
    string name = get_string("What is your name?\n");
    printf("Hello, %s!!\n", name);
}
