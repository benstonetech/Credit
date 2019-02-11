#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void){


    long ccnumber = get_long_long("Enter credit card number: ");

    int multipliedTotal = 0;
    int nonmultipliedTotal = 0;

    int check = 0;

    string outcome=" ";

    //visa number 4012888888881881

//AMEX = 15 digits, mc = 16 digits, visa = 13 or 16
//100,000,000,000,000
    if (ccnumber >= 100000000000000 && ccnumber <= 999999999999999 )
    {
        int ccDigits[15];

        for (int i = 14; i >= 0; i--)
        {
            ccDigits[i] = ccnumber % 10;
            ccnumber = ccnumber / 10;
            //printf("ccDigits[%i]=%i",i,ccDigits[i]);
        }

       // printf(" \n ccDigits[array]=");
        // for (int i = 0; i < 15; i++)
        // {
        //     printf("%i", ccDigits[i]);
        // }

        if (ccDigits[0]==3)
        {
            if (ccDigits[1]==4 || ccDigits[1]==7)
            {
                for (int i = 14; i >= 0; i--)
                {
                    if ((i % 2)==0)
                    {
                        nonmultipliedTotal = nonmultipliedTotal + ccDigits[i];
                    }
                    else
                    {
                        if ((ccDigits[i] * 2) > 9)
                        {
                            multipliedTotal = multipliedTotal + 1 + ((ccDigits[i] * 2) % 10);
                        }
                        else
                        {
                            multipliedTotal = multipliedTotal + (ccDigits[i]*2);
                        }
                    }
                }

                if (((multipliedTotal + nonmultipliedTotal) % 10)==0)
                {
                    outcome = "AMEX\n";
                }
                else
                {
                    outcome = "INVALID\n";
                }

                //printf("multi: %i, nonmulti: %i", multipliedTotal, nonmultipliedTotal);
            }
            else
            {
                outcome = "INVALID\n";
            }
        }
        else
        {
            outcome = "INVALID\n";
            //printf("INVALID \n");
        }

    }
    else if(ccnumber >=1000000000000000 && ccnumber <= 9999999999999999) // if card is 16 digit ( VISA or MC)
    {
        int ccDigits[16];

        for (int i = 15; i >= 0; i--)
        {
            ccDigits[i] = ccnumber % 10;
            ccnumber = ccnumber / 10;
        }

        for (int i = 15; i >= 0; i--)
        {
            if ((i % 2)!=0)
            {
                nonmultipliedTotal = nonmultipliedTotal + ccDigits[i];
            }
            else
            {
                if ((ccDigits[i] * 2) > 9)
                {
                    multipliedTotal = multipliedTotal + 1 + ((ccDigits[i] * 2) % 10);
                }
                else
                {
                    multipliedTotal = multipliedTotal + (ccDigits[i]*2);
                }
            }
        }

        //rintf("multi: %i, non multi: %i",multipliedTotal, nonmultipliedTotal);
        if (((multipliedTotal + nonmultipliedTotal) % 10)==0)
        {
            if (ccDigits[0]==5)
            {
                if (ccDigits[1] == 1 || ccDigits[1] == 2 || ccDigits[1] == 3 || ccDigits[1] == 4 || ccDigits[1] == 5 )
                {
                    outcome="MASTERCARD\n";
                }
                else
                {
                    outcome="INVALID\n";
                }
            }
            else if (ccDigits[0] == 4)
            {
                outcome = "VISA\n";
            }
            else
            {
                outcome = "INVALID\n";
            }
        }
        else
        {
            outcome = "INVALID\n";
        }
    }
    else if (ccnumber >=1000000000000 && ccnumber <= 9999999999999) // 13 digit mastercard
    {
        int ccDigits[13];

        for (int i = 12; i >= 0; i--)
        {
            ccDigits[i] = ccnumber % 10;
            ccnumber = ccnumber / 10;
        }

        for (int i = 12; i >= 0; i--)
        {
            if ((i % 2)==0)
            {
                nonmultipliedTotal = nonmultipliedTotal + ccDigits[i];
            }
            else
            {
                if ((ccDigits[i] * 2) > 9)
                {
                    multipliedTotal = multipliedTotal + 1 + ((ccDigits[i] * 2) % 10);
                }
                else
                {
                    multipliedTotal = multipliedTotal + (ccDigits[i]*2);
                }
            }
        }

        if (((multipliedTotal + nonmultipliedTotal) % 10)==0)
        {
            outcome = "MASTERCARD\n";
        }
        else
        {
            outcome = "INVALID\n";
        }
    }
    else
    {
        outcome = "INVALID\n";
    }



    printf("%s",outcome);

    // check = (multipliedTotal + nonmultipliedTotal) % 10;

    // if (check == 0){
    //     printf("Number is valid");
    // } else {
    //     printf("Number is invalid");
    // }

}

