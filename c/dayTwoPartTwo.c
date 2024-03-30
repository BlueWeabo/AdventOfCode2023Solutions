#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int MAX_GREEN = 13;
static const int MAX_RED = 12;
static const int MAX_BLUE = 14;

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    FILE *input = fopen("../inputs/dayTwo.txt", "r");
    if (input == NULL) {
        printf("Couldn't find file\n");
        fclose(input);
        return -1;
    }
    char *setstok;
    char *settok;

    int total = 0;
    char line[200];
    memset(line, '\n', sizeof(line));
    while (fgets(line, sizeof(line), input) != NULL) {
        remove_spaces(line);

        char *game = strchr(line, ':') + 1;

        int neededBlue = 0;
        int neededRed = 0;
        int neededGreen = 0;

        char *sets = malloc(sizeof(char) * strlen(game));
        if (sets == NULL) {
            fclose(input);
            free(sets);
            return -1;
        }
        sets = strtok_r(game, ";", &setstok);
        while (sets != NULL) {
            char *set = malloc(sizeof(char) * strlen(sets));
            if (set == NULL) {
                fclose(input);
                free(set);
                free(sets);
                return -1;
            }
            memset(set, '\n', strlen(sets));
            set = strtok_r(sets, ",", &settok);
            while (set != NULL) {
                if (strstr(set, "blue")) {
                    int blue = atoi(set);
                    neededBlue = max(blue, neededBlue);
                }
                if (strstr(set, "red")) {
                    int red = atoi(set);
                    neededRed = max(red, neededRed);
                }
                if (strstr(set, "green")) {
                    int green = atoi(set);
                    neededGreen = max(green, neededGreen);
                }
                set = strtok_r(NULL, ",", &settok);
            }

            sets = strtok_r(NULL, ";", &setstok);
            free(set);
        }
        free(sets);
        printf("red: %d \n", neededRed);
        printf("green: %d \n", neededGreen);
        printf("blue: %d \n", neededBlue);
        total += (neededBlue * neededGreen * neededRed);
    }
    printf("Total: %d \n", total);
    fclose(input);
}
