#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

unsigned int *resizeArray(unsigned int *array, unsigned int count);
unsigned int convertToNumber(unsigned int *number);
unsigned int sumArray(unsigned int *array, unsigned int count);
int isNumber(char c);

int main() {
    FILE *input = fopen("../inputs/dayOne.txt", "r");
    if (input == NULL) {
        printf("Couldn't find file\n");
        fclose(input);
        return -1;
    }
    char line[100];
    memset(line, 0, sizeof(line));
    unsigned int *numbers = malloc(sizeof(unsigned int) * 2);
    unsigned int count = 0;
    while (fgets(line, sizeof(line), input) != NULL) {
        printf(line);
        unsigned int *toRead = malloc(3*sizeof(unsigned int));
        for (int i = 0; i < sizeof(line); i++) {
            if (isNumber(line[i])) {
                printf("first %d\n", line[i] -'0');
                toRead[0] = line[i] - '0';
                break;
            }
        }
        for (int i = sizeof(line) - 1; i >= 0; i--) {
            if (isNumber(line[i])) {
                printf("second %d\n", line[i] -'0');
                toRead[1] = line[i] - '0';
                break;
            }
        }
        unsigned int num = convertToNumber(toRead);
        
        if (sizeof(numbers) / sizeof(unsigned int) <= count) {
            numbers = resizeArray(numbers, count);
        }
        numbers[count++] = num;
        //printf("number in array: %d\n", numbers[count - 1]);
        printf("number= %d count= %d\n",num, count);
        free(toRead);
        memset(line,0,sizeof(line));
    }
    fclose(input);
    unsigned int sum = sumArray(numbers, count);
    free(numbers);
    printf("%d\n",sum);
    return 0;
}

unsigned int *resizeArray(unsigned int *array, unsigned int count) {
    unsigned int *newArray = malloc(sizeof(array) * count * 2);
    for (int i = 0; i < count * 2; i++) {
        newArray[i] = array[i];
    }
    free(array);
    return newArray;
}
unsigned int convertToNumber(unsigned int *number) {
    unsigned int num = 0;
    for (int i = sizeof(number) / sizeof(unsigned int) - 1; i >= 0; i--) {
        num += number[i] * pow(10, sizeof(number)/sizeof(unsigned int) - i - 1);
    }
    return num;
}

unsigned int sumArray(unsigned int *array, unsigned int count) {
    unsigned int sum = 0;
    for (int i = 0; i < count; i++) {
        //printf("number to add: %d \n", array[i]);
        //printf("current sum: %d\n", sum);
        sum += array[i];
        //printf("new sum: %d\n", sum);
    }
    return sum;
}

int isNumber(char c) {
    return c >= '0' && c <= '9';
}