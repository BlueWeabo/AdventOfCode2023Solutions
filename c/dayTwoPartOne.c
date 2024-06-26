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
        //printf("%s", line);
        remove_spaces(line);
        //printf("Game: %s \n", line);
        int current = atoi(line+4);
        //printf("Id: %d \n", current);
        int valid = 1;

        char *game = strchr(line, ':') + 1;
        printf("%s", game);

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
                printf("setPart: %s \n", set);
                if (strstr(set, "blue")) {
                    if (atoi(set) > MAX_BLUE) valid = 0;
                }
                if (strstr(set, "red")) {
                    if (atoi(set) > MAX_RED) valid = 0;
                }
                if (strstr(set, "green")) {
                    if (atoi(set) > MAX_GREEN) valid = 0;
                }
                set = strtok_r(NULL, ",", &settok);
            }

            sets = strtok_r(NULL, ";", &setstok);
            free(set);
        }
        free(sets);

        if (valid) total+=current;
    }
    printf("Total: %d \n", total);
    fclose(input);
}
