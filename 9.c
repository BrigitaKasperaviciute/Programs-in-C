/*
Programos paskirtis: pagal vartotojo įvestį - sveiką skaičių (N) bei N sveikų skaičių - apskaičiuoti maximumą ir minimumą ir ir išvesti N įvestų skaičių 3 grupėmis pagal duotus intervalus.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 100000
#define CAPACITY_1 100 // for storing user's input (yes/no) whether they want to reenter positive integer that will define the quantity of numbers that they will enter
int is_in_range(int number, int start_of_the_range, int end_of_the_range)
{
    if (number >= start_of_the_range && number <= end_of_the_range && start_of_the_range <= end_of_the_range)
        return 1;
    else
        return 0;
}
int MIN_MAX(int N, int integers[], int min_not_max)
{
    int maximum = integers[0], minimum = integers[0];
    for (int i = 1; i < N; ++i)
    {
        if (integers[i] < minimum && min_not_max == 1)
            minimum = integers[i];
        if (integers[i] > maximum && min_not_max == 0)
            maximum = integers[i];
    }
    if (min_not_max)
        return minimum;
    else
        return maximum;
}
int get_integer(int index, char *msg_1, char *msg_2, char *msg_3, char *msg_for_correct_input, char *msg_for_incorrect_input)
{
    int number, loop_works = 1, correct_input = 0, digits;
    char input[CAPACITY];
    if (index == -1)
        printf("%s%s%s", msg_1, msg_2, msg_3);
    else if (index == -2)
    {
        printf("%s%s%s", msg_1, msg_2, msg_3);
        while (getchar() != '\n')
            ;
    }
    else
    {
        printf("%s%d %s: ", msg_1, index, msg_2);
        while (getchar() != '\n')
            ;
    }
    while (loop_works)
    {
        scanf("%[^\n]s", input);
        digits = 0;
        if (input[0] == '-')
        {
            digits++;
            for (int i = 1; i < strlen(input); ++i)
            {
                for (int j = '0'; j <= '9'; ++j)
                {
                    if (input[i] == j)
                    {
                        digits++;
                    }
                }
                if (digits == strlen(input))
                    correct_input = 1;
            }
        }
        else
        {
            for (int i = 0; i < strlen(input); ++i)
            {
                for (int j = '0'; j <= '9'; ++j)
                {
                    if (input[i] == j)
                    {
                        digits++;
                    }
                }
                if (digits == strlen(input))
                    correct_input = 1;
            }
        }
        if (correct_input == 1)
        {
            printf("%s", msg_for_correct_input);
            loop_works = 0;
            number = atoi(input);
            return number;
        }
        else
        {
            printf("%s", msg_for_incorrect_input);
            if (index == -1 || index == -2)
                printf("%s%s%s", msg_1, msg_2, msg_3);
            else
                printf("%s%d %s: ", msg_1, index, msg_2);
            while (getchar() != '\n')
                ;
        }
    }
    return 0;
}
int update_N(char *yes, char *no, char *msg_for_correct_input, char *msg_for_incorrect_input)
{
    char enter_N_again[CAPACITY_1];
    int N_will_be_entered_again;
    do
    {
        N_will_be_entered_again = 0;
        memset(enter_N_again, 0, sizeof(enter_N_again)); // to clear enter_N_again[];
        while (getchar() != '\n')
            ;
        scanf("%[^\n]s", enter_N_again);
        if ((strcmp(enter_N_again, yes) == 0)||(strcmp(enter_N_again, no) == 0))
        {
                printf("%s", msg_for_correct_input);
                N_will_be_entered_again++;
        }
        else
            {
                printf("%sWrite yes or no: ", msg_for_incorrect_input);
            }
    } while (N_will_be_entered_again != 1);
    if (strcmp(enter_N_again, yes) == 0)
    {
        return 1;
    }
    else if (strcmp(enter_N_again, no) == 0)
        return 0;
}
void PRINT(int N, int integers[], int start_of_the_range, int end_of_the_range)
{
    int printed_integers = 0;
    for (int i = 0; i < N; ++i)
    {
        if (is_in_range(integers[i], start_of_the_range, end_of_the_range))
        {
            if (printed_integers == 0)
                printf("Integers that belong to the interval [%d; %d]: %d", start_of_the_range, end_of_the_range, integers[i]);
            else
                printf(", %d", integers[i]);
            printed_integers++;
        }
        if ((i == (N - 1)) && (printed_integers >= 1))
            printf(".\n");
        else if ((i == (N - 1)) && (printed_integers == 0))
            printf("There were not any integers that belong to the interval [%d; %d].\n", start_of_the_range, end_of_the_range);
    }
}
int main()
{
    printf("After user writes integer that defines how many other integers they will enter and writes those integers, this program calculates input's minimum and maximum and prints entered numbers in three groups, each of which belongs to the corresponding interval:\n");
    printf("1) [MIN , MIN+(MAX-MIN)/3];\n");
    printf("2) [MIN+(MAX-MIN)/3 , MIN+(MAX-MIN)*2/3];\n");
    printf("3) [MIN+(MAX-MIN)*2/3 , MAX].\n");
    int N, integers[CAPACITY]; // for storing correct user's input
    int input = 0;             // for storing the number of integers that the user has entered (N excluded)
    int MINIMUM, MAXIMUM;
    char *msg_1 = "Please enter ", *msg_2 = "integer", *msg_for_correct_input = "Input is correct.\n", *msg_for_incorrect_input = "Input is incorrect.\n", *msg_3 = " that defines how many other integers you will enter: ";
    char *yes = "yes", *no = "no", *N_higher_than_CAPACITY = "However N is greater than CAPACITY!\n", *reenter1 = "Would you like to write positive integer that is not greater than ", *reenter2 = "and that will define the quantity of numbers that you will enter? Please type yes or no: ";
    char *msg_not_positive = "Written input was not a positive number. It is only possible to write positive quantity of numbers.\n";
    N = get_integer(-1, msg_1, msg_2, msg_3, msg_for_correct_input, msg_for_incorrect_input);
    while (N <= 0 || CAPACITY < N)
    {
        if (CAPACITY < N)
            printf("%s%s%d %s", N_higher_than_CAPACITY, reenter1, CAPACITY, reenter2);
        else if (N <= 0)
            printf("%s%s%d %s", msg_not_positive, reenter1, CAPACITY, reenter2);
        if (update_N(yes, no, msg_for_correct_input, msg_for_incorrect_input))
            N = get_integer(-2, msg_1, msg_2, msg_3, msg_for_correct_input, msg_for_incorrect_input);
        else
            break;
    }
    if (N > 0 && CAPACITY >= N)
    {
        while (input < N)
        {
            integers[input] = get_integer(input + 1, msg_1, msg_2, msg_3, msg_for_correct_input, msg_for_incorrect_input);
            input++;
        }
        MINIMUM = MIN_MAX(N, integers, 1);
        MAXIMUM = MIN_MAX(N, integers, 0);
        printf("\nResults:\n");
        PRINT(N, integers, MINIMUM, MINIMUM + (MAXIMUM - MINIMUM) / 3);
        PRINT(N, integers, MINIMUM + (MAXIMUM - MINIMUM) / 3, MINIMUM + (MAXIMUM - MINIMUM) * 2 / 3);
        PRINT(N, integers, MINIMUM + (MAXIMUM - MINIMUM) * 2 / 3, MAXIMUM);
        printf("\nThe integers were printed successfully. The program has finished working.\n");
    }
    else
        printf("There are no integers to print. The program has finished working.\n");
    return 0;
}
