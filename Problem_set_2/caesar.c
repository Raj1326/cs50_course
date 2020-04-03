#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //condition to only when one argument is give
    if (argc == 2)
    {
        int k;
        char *next;
        k = strtol(argv[1], &next, 10);
        //to check wheather argument contain number
        if (k != 0)
        {
            //condition if argument is combination of alpabets and numbers
            if ((next == argv[1]) || (*next != '\0'))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
            //else condition
            else
            {
                //prompt user for string
                string p = get_string("plaintext: ");
                for (int i = 0; i < strlen(p); i++)
                {
                    //condition for upper case character
                    if (isupper(p[i]))
                    {
                        //converting char to int
                        int c = p[i] - 'A';
                        //formula
                        c = (c + k) % 26;
                        //converting int to char
                        c += 'A';
                        p[i] = c;
                        //printf("%c",p[i]);
                    }
                    //condition for lower case character
                    if (islower(p[i]))
                    {
                        //converting char to int
                        int c = p[i] - 'a';
                        //formula
                        c = (c + k) % 26;
                        //converting int to char
                        c += 'a';
                        p[i] = c;
                        //printf("%c",p[i]);
                    }
                }
                //printing encrypted message
                printf("ciphertext: %s\n", p);
            }
        }
        //else condition
        //when key is not a number
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    //else condition
    //when number of agrument is more or less
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}