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
        int flag = 0;
        if (strlen(argv[1]) == 26)
        {
            //iterating the key
            for (int i = 0;  i < strlen(argv[1]); i++)
            {
                //other than alpabates in key
                if (!isalpha(argv[1][i]))
                {
                    flag = 1;
                    break;
                }

                for (int j = i + 1; j < strlen(argv[1]); j++)
                {
                    //duplicate character in key
                    if (argv[1][i] == argv[1][j])
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            //condition if argument is combination of alpabets and numbers
            if (flag == 1)
            {
                printf("./substitution key\n");
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
                        //changing the index of string with appropriate character
                        p[i] = toupper(argv[1][c]);
                    }
                    //condition for lower case character
                    if (islower(p[i]))
                    {
                        //converting char to int
                        int c = p[i] - 'a';
                        //changing the index of string with appropriate character
                        p[i] = tolower(argv[1][c]);
                    }
                }
                //printing encrypted message
                printf("ciphertext: %s\n", p);
            }
        }
        //else condition
        //when key is invalid
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    //else condition
    //when number of agrument is more or less
    else
    {
        printf("./substitution key\n");
        return 1;
    }
}