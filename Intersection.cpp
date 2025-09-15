#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
void findIntersection(int list1[], int len1, int list2[], int len2, int result[], int &resultLen)
{
    int i = 0, j = 0, k = 0;

    while(i < len1 && j < len2)
    {
         if (list1[i] == list2[j])
        {
            result[k++] = list1[i];
            i++;
            j++;
            resultLen++;
        }
        else if (list1[i] < list2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

}

int main()
{
    int len1 = 0, len2 = 0;
    printf("Length of List 1 is:");
    scanf("%i", &len1);

    int list1[len1];

    printf("Input %i integers:\n", len1);
    for (int i = 0; i < len1; i++)
    {
         scanf("%i", &list1[i]);
    }

    printf("List 1 that you input is:");
     for (int i = 0; i < len1; i++)
    {
         printf("%i ", list1[i]);
    }
    printf("\n\n");




    printf("Length of List 2 is:");
    scanf("%i", &len2);

    int list2[len2];

    printf("Input %i integers:\n", len2);
    for (int i = 0; i < len2; i++)
    {
         scanf("%i", &list2[i]);
    }

    printf("List 2 that you input is:");
     for (int i = 0; i < len2; i++)
    {
         printf("%i ", list2[i]);
    }
    printf("\n\n");

    int result[min(len1, len2)];
    int resultLen = 0;

    findIntersection(list1, len1, list2, len2, result, resultLen);

    printf("Intersection:");
    for (int i = 0; i < resultLen; i++)
    {
        printf("%i ", result[i]);
    }
}
