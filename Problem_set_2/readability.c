#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//function decalartions
int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    int index;
    float letters, words, sentences, i, L, S;
    //prompt users to get input
    string text = get_string("Text: ");
    //calling function to count no. of letters
    letters = (float) count_letters(text);
    //printf("%f letter(s)\n", letters);
    //calling function to count no. of words
    words = (float) count_words(text);
    //printf("%f word(s)\n", words);
    //calling function to count no. of sentences
    sentences = (float) count_sentences(text);
    //printf("%f sentence(s)\n", sentences);
    //calculating the L variable used in formula
    L = (float)((letters * 100) / words);
    //printf("L = %f\n", L);
    //calculating the S variable used in formula
    S = (float)((sentences * 100) / words);
    //printf("S = %f\n", S);
    i = (0.0588 * L - 0.296 * S - 15.8);
    index = round(i);
    //else if ladder to print grade according to index
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index <= 1)
    {
        printf("Before Grade 1\n");

    }
    else
    {
        printf("Grade %d\n", index);
    }
}
//function to count no. of letters
int count_letters(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        //condition to check wheather character is alphabate
        if (isalpha(s[i]))
        {
            count++;
        }
    }
    return count;
}
//function to count no. of words
int count_words(string s)
{
    int count = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        //condition to check wheather character is space
        if (isspace(s[i]))
        {
            count++;
        }
    }
    //adding one to add last word
    return count + 1;
}
//function to count no. of sentences
int count_sentences(string s)
{
    int count = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        //condition to check sentence is completed
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            count++;
        }
    }
    return count;
}