#include<cs50.h>
#include<stdio.h>

int main()
{
    int r = 0; 
    int sum1 = 0, sum2 = 0, i = 0, count = 0;
    //prompt to get input
    long int cno = get_long("Number : ") ; 
    int cnoa[20] ;
    while (cno)
    {
        count++ ;
        r = cno % 10 ;
        cno = cno / 10 ;
        cnoa[i] = r ;
        i++ ;
    }

    for (i = 1; i <= count - 1; i = i + 2)
    {
        r = 0 ;
        int temp = cnoa[i] * 2;
        if (temp >= 10)
        {
            r = temp % 10 ;
            temp = temp / 10 ;
            sum1 = sum1 + temp + r ;
        } 
        else
        {
            sum1 += temp ;
        }
    }
    
    for (i = 0; i <= count - 1 ; i = i + 2)
    {
        sum2 = sum2 + cnoa[i] ;
    }
     
    int first_dig = cnoa[count - 1] * 10 + cnoa[count - 2] ;
    //to check wheather sum is divisible by ten
    if ((sum1 + sum2) % 10 == 0)
    {
        //condition for AMERICAN EXPRESS
        if (count == 15 && (first_dig == 34 || first_dig == 37))
        {
            printf("AMEX\n") ;
        }
        //condition for MASTERCARD
        else if (count == 16 && (first_dig == 51 || first_dig == 52 || first_dig == 53 || first_dig == 54 || first_dig == 55))
        {
            printf("MASTERCARD\n") ;
        }
        //comdition for VISA
        else if ((count == 13 || count == 16) && (cnoa[count - 1] == 4))
        { 
            printf("VISA\n") ;
        }
        else
        {
            printf("INVALID\n") ;
        }
    }
    else
    {
        printf("INVALID\n") ;
    }
}
