#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
void generateArray(int data[], int size, int low, int high)
{
    for (int i = 0; i < size; ++i)
    {
        data[i] = low + rand() % high;
    }
}
int *createArray(int size, int low, int high)
{
    int *data = (int *)calloc(size, sizeof(int));
    if (data)
    {
        generateArray(data, size, low, high);
        return data;
    }
    return NULL;
}
int splitData(int *data, int size, int firstPartSize, int **addressFirstArray, int **addressSecondArray)
{
    int correct_parameters = 0, arrayWasCreated = 0;
    for (int i = 0; i < size; ++i)
    {
        if (data[i] == (int)data[i])
        {
            correct_parameters++;
        }
    }
    if ((correct_parameters == size) && (size == (int)size) && (size > 0 && firstPartSize > 0) && (firstPartSize == (int)firstPartSize) && (*addressSecondArray == NULL) && (*addressFirstArray == NULL))
    {
        *addressFirstArray = (int *)realloc(*addressFirstArray, (firstPartSize * sizeof(int)));
        if (addressFirstArray)
        {
            memcpy(*addressFirstArray, data, firstPartSize * sizeof(int));
            arrayWasCreated++;
        }
        *addressSecondArray = (int *)realloc(*addressSecondArray, ((size - firstPartSize) * sizeof(int)));
        if (addressSecondArray)
        {
            memcpy(*addressSecondArray, &data[firstPartSize], (size - firstPartSize) * sizeof(int));
            arrayWasCreated++;
        }
        if (arrayWasCreated == 2)
            return 0;
    }
    return -1;
}
int main()
{
    int *addressFirstArray = NULL, *addressSecondArray = NULL, *addressOfDefaultArrayFirstElement;
    int amount;
    int size, low, high, FirstPartSize;
    srand(time(NULL));
    printf("Write array size high\n");
    scanf("%d", &size);
    printf("Write what lowest element could be in the array\n");
    scanf("%d", &low);
    printf("Write what highest element could be in the array\n");
    scanf("%d", &high);
    printf("Write first part's of an array size\n");
    scanf("%d", &FirstPartSize);
    addressOfDefaultArrayFirstElement = createArray(size, low, high);
    if (splitData(addressOfDefaultArrayFirstElement, size, FirstPartSize, &addressFirstArray, &addressSecondArray) == 0)
    {
        printf("splitData funtion works.\n");
        printf("Numbers in first array:\n");
        for (int i = 0; i < FirstPartSize; ++i)
            printf("%d\n", *(addressFirstArray + i));
        printf("Numbers in second array:\n");
        for (int i = 0; i < (size - FirstPartSize); ++i)
            printf("%d\n", *(addressSecondArray + i));
    }
    else
        printf("splitData funtion does not work.\n");
    free(addressSecondArray);
    free(addressFirstArray);
    free(addressOfDefaultArrayFirstElement);
    return 0;
}