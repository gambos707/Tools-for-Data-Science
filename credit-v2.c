#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string credit_card_type(long credit_card_number);

    long credit_card_numbers;
    int total;
    string card_type;


    // 1) Accept the input from the user
    do
    {
        credit_card_numbers = get_long("Number: ");
    }
    while (credit_card_numbers < 1); // Prompt the user to inter a valid Credit Card Number


    // After checking the validity of the credit card number
    // display the credit card type massege
    // if it's invlid display Invalid masssege
    card_type = credit_card_type(credit_card_numbers);
    printf("%s\n", card_type);
}









//2- Check the validity of the Credit Card Number and get back the Credit  Card Type
string credit_card_type(long credit_card_number)
{
//_______________________________________________________________________________
//1) calculate the credit card totalt to Check the validity of the Credit Card Number
//(Luhn’s Algorithm)

    long card_number1 = credit_card_number / 10, card_number2 = credit_card_number;
    int total_sum = 0, sum1 = 0, sum2 = 0;

    //___________________
    //1.1) Loop through the credit card number and multiply every other digit by 2,
    //starting with the number’s second-to-last digit,
    //and then add those products digits together.

    while (card_number1 > 0)
    {
        int last_digit = card_number1 % 10;    // capture the last digit that needs to be summed.
        int last_digit_tims_two = last_digit * 2;   // multiply last digit by 2
// the sum of the digits those multiplied by 2 (starting from the end).
        sum1 = sum1 + (last_digit_tims_two % 10) + (last_digit_tims_two / 10);
// drop the last 2 digets from the credit card number so the loop will start with new digit at the end.
        card_number1 = card_number1 / 100;
    }

//___________________
//1.2) Loop through the credit card number
//and add the sum to the sum of the digits that weren’t multiplied by 2.

    while (card_number2 > 0)
    {
// capture the last digit that needs to be summed.
        int last_digit = card_number2 % 10;
// the sum of the digits that weren’t multiplied by 2 (starting from the end).
        sum2 = sum2 + last_digit;
// drop the last 2 digets from the credit card number so the loop will start with new digit at the end.
        card_number2 = card_number2 / 100;
    }

    total_sum = sum1 + sum2; // total sum of the credit card number

//___________________________________________________________________
//2) Identify the length of the credit card
//The calculated result will be used to identify the credit card type in section 4
    long card_number = credit_card_number;
    int count_digits = 0;

    while (card_number != 0)
    {
        card_number = card_number / 10;
        count_digits++;
    }


//___________________________________________________________________
//3) Find the divisor so that it can be used to find the first two digits
    long divisor = 1;  // intial the divisor by 10

    for (int i = 0; i < count_digits - 2; i++)
    {
        divisor = divisor * 10;
    }


//___________________________________________________________________
//4) Find the first digit and the first two digits
    long creditCardNumber = credit_card_number;

    int first_digits = creditCardNumber / (divisor * 10);   // the first digit
    int first_two_digits = creditCardNumber / divisor;  // the first two digits


//___________________________________________________________________
//5) Check if the the credit card is valid, by examin is the total moduler equal to zero.
//And identify the Credit Card Type.
    string card_type = "";

    if (total_sum % 10 == 0)
    {
        if (count_digits == 15 && (first_two_digits == 34 || first_two_digits == 37))
        {
            card_type = "AMEX";
        }
        else if (count_digits == 16 && (first_two_digits >= 51 && first_two_digits <= 55))
        {
            card_type = "MASTERCARD";
        }
        else if ((count_digits == 13 || count_digits == 16) && first_digits == 4)
        {
            card_type = "VISA";
        }
        else
        {
            card_type = "INVALID";
        }
    }
    else
    {
        card_type = "INVALID";
    }
    return card_type;
}
