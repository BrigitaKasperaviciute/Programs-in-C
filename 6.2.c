#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CAPACITY 1000
int validateInput(char input[])
{
    int numberCount = 0;
    int comma = 0;
    int commaIndex = 0;
    for (int i = 0; i < strlen(input); ++i)
    {
        if (input[i] < '0' || input[i] > '9')
        {
            if (input[i] == ',')
            {
                comma = 1;
                commaIndex = i;
            }
            continue;
        }
        else if (input[i] >= '0' && input[i] <= '9')
            ++numberCount;
    }
    if (comma && numberCount != strlen(input) - 1 || !comma && numberCount != strlen(input))
    {
        return 0;
    }
    int decimalPlaces = 0;
    int integerPart = atoi(input);
    int zerosCount = 0;
    for (int i = commaIndex + 1; i < strlen(input); ++i)
    {
        ++decimalPlaces;
        if (input[i] - '0' == 0)
        {
            ++zerosCount;
        }
    }
    if ((integerPart == 1000 && zerosCount == decimalPlaces && decimalPlaces <= 3) || (integerPart >= 10 && integerPart <= 1000 && decimalPlaces <= 3))
    {
        return numberCount;
    }
    if ((integerPart < 10 || integerPart >= 1000) && zerosCount != decimalPlaces && decimalPlaces <= 3)
        printf("%s is out of range [10;1000]\n\n", input);
    if ((integerPart < 10 || integerPart >= 1000) && zerosCount != decimalPlaces && decimalPlaces >= 3)
        printf("%s is out of range [10;1000] and had more than 3 numbers after comma\n\n", input);
    if (decimalPlaces >= 3)
        printf("%s had more than 3 numbers after comma\n\n", input);
    if (numberCount == 0)
        printf("%s is is not a number\n\n", input);
    return 0;
}
int main()
{
    FILE *file;
    FILE *file1;
    char pav[CAPACITY], msg[CAPACITY] = "Write new file name, which will have new possibly correct number\n";
    file = fopen("in.txt", "r+");
    char input[CAPACITY];
    int rightFile = 0;
    printf("Si programa vartotojui duomenų faile „in.txt“ pateikus realų skaičių, ne mažesnį už 10 ir nedidesnį už 1000, suskaiciuoja kiek tas skaicius turi skaitmenu.\n");
    printf("Duomenų faile „in.txt“ pateikite realų skaičių, ne mažesnį už 10 ir nedidesnį už 1000, su ne daugiau kaip 3 skaičiais po kablelio. Laikykite, kad įvestyje trupmeninę dalį nuo sveikosios skiria kablelis.\n\n");
    int firstWrongInput = 0, rightInput = 0;
    do
    {
        if (firstWrongInput == 0)
        {
            fscanf(file, "%s", input);
            firstWrongInput++;
            rightInput = validateInput(input);
        }
        if (rightInput == 0)
        {
            printf("%s", msg);
            do
            {
                scanf("%s", pav);
                int length = strlen(pav);
                if (length > 4 && pav[length - 4] == '.' && pav[length - 3] == 't' && pav[length - 2] == 'x' && pav[length - 1] == 't')
                    rightFile++;
                else
                {
                    printf("Wrong input. Write new file name (it has to have .txt at the end and 1 or more symbols before that) with correct input.\n");
                    while (getchar() != '\n')
                        ;
                }
            } while (rightFile == 0);
            file1 = fopen(pav, "r+");
            fscanf(file1, "%s", input);
            rightInput = validateInput(input);
            fclose(file1);
        }
    } while (rightInput == 0);
    printf("%s has %d digit(-s)\n", input, rightInput);
    fclose(file);
    return 0;
}