#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

unsigned int convertToNumber(unsigned int *number);
unsigned int sumArray(unsigned int *array, unsigned int count);
char *findFirstOccurrence(char *line);
unsigned int findFirstOccurrenceAndConvert(char *line);

int main() {
    FILE *input = fopen("../inputs/dayOne.txt", "r");
    if (input == NULL) {
        printf("Couldn't find file\n");
        fclose(input);
        return -1;
    }
    char line[100];
    char *starting = line;
    memset(line, 0, sizeof(line));
    unsigned int *numbers = malloc(sizeof(unsigned int) * 2);
    unsigned int count = 0;
    while (fgets(line, sizeof(line), input) != NULL) {
        printf(line);
        unsigned int *toRead = malloc(3*sizeof(unsigned int));
        char *pointers[100];
        int pointC = 0;
        for (int i = 0; i < sizeof(line); i++) {
            char * firstP = findFirstOccurrence(line + i);
            if (firstP == NULL) break;
            pointers[pointC++] = firstP;
        }
        char *first, *last;
        first = pointers[0];
        last = pointers[pointC -1];
        toRead[0] = findFirstOccurrenceAndConvert(first);
        toRead[1] = findFirstOccurrenceAndConvert(last);
        unsigned int num = convertToNumber(toRead);
        
        if (sizeof(numbers) / sizeof(unsigned int) <= count) {
            numbers = realloc(numbers, sizeof(unsigned int) * count * 2);
        }
        numbers[count++] = num;
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
        sum += array[i];
    }
    return sum;
}

char *findFirstOccurrence(char *line) {
    char *one = strstr(line, "one");
    char *oneN = strstr(line, "1");
    char *two = strstr(line, "two");
    char *twoN = strstr(line, "2");
    char *three = strstr(line, "three");
    char *threeN = strstr(line, "3");
    char *four = strstr(line, "four");
    char *fourN = strstr(line, "4");
    char *five = strstr(line, "five");
    char *fiveN = strstr(line, "5");
    char *six = strstr(line, "six");
    char *sixN = strstr(line, "6");
    char *seven = strstr(line, "seven");
    char *sevenN = strstr(line, "7");
    char *eight = strstr(line, "eight");
    char *eightN = strstr(line, "8");
    char *nine = strstr(line, "nine");
    char *nineN = strstr(line, "9");
    char *pointersAvailable[] = {one, oneN, two, twoN, three, threeN, four, fourN, five, fiveN, six, sixN, seven, sevenN, eight, eightN, nine, nineN};
    char *minPointer = one;
    for (int i = 1; i < 18; i++) {
        if (pointersAvailable[i] == NULL) continue;
        if (minPointer > pointersAvailable[i] || minPointer == NULL) {
            minPointer = pointersAvailable[i];
        }
    }
    return minPointer;
}

unsigned int findFirstOccurrenceAndConvert(char *line) {
    char *one = strstr(line, "one");
    char *oneN = strstr(line, "1");
    char *two = strstr(line, "two");
    char *twoN = strstr(line, "2");
    char *three = strstr(line, "three");
    char *threeN = strstr(line, "3");
    char *four = strstr(line, "four");
    char *fourN = strstr(line, "4");
    char *five = strstr(line, "five");
    char *fiveN = strstr(line, "5");
    char *six = strstr(line, "six");
    char *sixN = strstr(line, "6");
    char *seven = strstr(line, "seven");
    char *sevenN = strstr(line, "7");
    char *eight = strstr(line, "eight");
    char *eightN = strstr(line, "8");
    char *nine = strstr(line, "nine");
    char *nineN = strstr(line, "9");
    char *pointersAvailable[] = {one, oneN, two, twoN, three, threeN, four, fourN, five, fiveN, six, sixN, seven, sevenN, eight, eightN, nine, nineN};
    char *minPointer = one;
    int index = 0;
    for (int i = 1; i < 18; i++) {
        if (pointersAvailable[i] == NULL) continue;
        if (minPointer > pointersAvailable[i] || minPointer == NULL) {
            minPointer = pointersAvailable[i];
            index = i;
        }
    }
    return (unsigned int)ceil((index + 1)/2.0);
}