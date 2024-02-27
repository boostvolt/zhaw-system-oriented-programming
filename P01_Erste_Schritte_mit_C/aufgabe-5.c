//
// Created by Jan Kott on 27.02.2024.
//
#include <stdio.h>

#define NUM_ROWS 8
#define INITIAL_AMOUNT 200

int main()
{
    double factor;
    printf("Enter a factor: ");
    scanf("%lf", &factor); // fgets and strtod would be better here due to error handling

    int maxChfAmount = INITIAL_AMOUNT * NUM_ROWS;

    for (int chfAmount = INITIAL_AMOUNT; chfAmount <= maxChfAmount; chfAmount += INITIAL_AMOUNT)
    {
        printf("%i CHF \t<-->\t %.5f BTC\n", chfAmount, chfAmount / factor);
    }

    return 0;
}