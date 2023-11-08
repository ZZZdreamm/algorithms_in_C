#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *largestNumber(char *str)
{
    char *result = malloc(sizeof(char) * 100);
    result = strdup(str);
    int length = strlen(result);
    for (int i = 0; i < length; i++)
    {
        int biggest_index = i;
        int biggest_value = (int)result[i];
        for (int j = i + 1; j < length; j++)
        {
            int current_value = (int)result[j];
            if ((current_value % 2) == (biggest_value % 2))
            {
                if (current_value > biggest_value)
                {
                    biggest_index = j;
                    biggest_value = current_value;
                }
            }
        }
        if (biggest_index != i)
        {
            char temp = result[i];
            result[i] = result[biggest_index];
            result[biggest_index] = temp;
        }
    }
    return result;
}

int main(int argc, char *argv[])
{

    char *str = "0028663";
    char *result = largestNumber(str);
    printf("input: %s\n", str);
    printf("result: %s\n", result);

    char *str2 = "0028663";
    char *result2 = largestNumber(str2);
    printf("input: %s\n", str2);
    printf("result: %s\n", result2);

    char *str3 = "0028663";
    char *result3 = largestNumber(str3);
    printf("input: %s\n", str3);
    printf("result: %s\n", result3);

    char *str4 = "000119758882";
    char *result4 = largestNumber(str4);
    printf("input: %s\n", str4);
    printf("result: %s\n", result4);

    char *str5 = "000000000000000999999999999999999999999999999777777777777777777777777777788888888888888888888888888888";
    char *result5 = largestNumber(str5);
    printf("input: %s\n", str5);
    printf("result: %s\n", result5);

    char *str6 = "11231243542199912";
    char *result6 = largestNumber(str6);
    printf("input: %s\n", str6);
    printf("result: %s\n", result6);

    return 0;
}