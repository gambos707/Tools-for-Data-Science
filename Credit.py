#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long credit_card_number;


    // 1- Accept the input from the user
    do
    {
        credit_card_number = get_long("Number: ");
    }
    while (credit_card_number < 1); // Prompt the user to inter a valid Credit Card Number


    // After checking the validity of the credit card number
    // display the credit card type massege
    // if it's invlid display Invalid masssege
    if (credit_card_valid)
    {
        printf("credit_card_type\n");
    }else
    {
        printf("Invalid Card Number");
    }


    // 2- Check the validity of the Credit Card Number
    str cred_card_valid (credit_card_number)
    {
        long card_nmber1 = credit_card_number / 10, card_number2 = credit_card_number;
        int total_sum = 0, sum1 = 0, sum2 = 0;

        // 1) Loop through the credit card number and multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
        while (card_number1 > 0)
        {
            int last_digit = card_number1 % 10;    // capture the last digit that needs to be summed.
            last_digit_tims_two = last_digit * 2;   // multiply last digit by 2
            sum1 = sum1 + (last_digit_tims_two % 10) + (last_digit_tims_two / 10);      // the sum of the digits those multiplied by 2 (starting from the end).
            card_number1 = card_number1 / 100;      // drop the last 2 digets from the credit card number so the loop will start with new digit at the end.
        }

        // 2) Loop through the credit card number and add the sum to the sum of the digits that weren’t multiplied by 2.
        while (card_number2 > 0)
        {
            int last_digit = card_number2 % 10;      // capture the last digit that needs to be summed.
            sum2 = sum2 + last_digit;               // the sum of the digits that weren’t multiplied by 2 (starting from the end).
            card_number2 = card_number2 / 100;        // drop the last 2 digets from the credit card number so the loop will start with new digit at the end.
        }

        total_sum = sum1 + sum2;

        // 3) Check if the the total_sum moduler equal to zero.
        if (total_sum % 10 == 0)
        {
            return "Valid";
        }
            return "Invalid";


    }

    // 3- Identify the Credit Card Type

}
