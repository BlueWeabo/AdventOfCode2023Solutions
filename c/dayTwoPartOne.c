#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static const int MAX_GREEN = 13;
static const int MAX_RED = 12;
static const int MAX_BLUE = 14; 

typedef struct {
    int red;
    int green;
    int blue;
} Set;

typedef struct {
    int id;
    Set *sets;
    int amountOfSets;
} Game;

void removeSpaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}


int main() {
    Game *games = (Game*) malloc(sizeof(Game) * 2);
    int gamesCount = 0;
    int gamesMax = 2;
    FILE *input = fopen("../inputs/dayTwo.txt", "r");
    if (input == NULL) {
        printf("Couldn't find file\n");
        fclose(input);
        return -1;
    }
    char line[100];
    memset(line, 0, sizeof(line));
    while(fgets(line, sizeof(line), input) != NULL) {
        removeSpaces(line);
        int gameId;
        Set *sets = (Set*) malloc(sizeof(Set) * 2);
        int setsCount = 0;
        int setsMax = 2;
        printf(line);
        char *gamePart = strchr(line, ':') + 1;
        gameId = atoi(line+4);
        char *setsPart = (char*) malloc(sizeof(char) * strlen(gamePart));
        setsPart = strtok(gamePart, ";");
        printf("GameID: %d  game part: %s\n", gameId,gamePart);
        while (setsPart != NULL) {
            Set *set = (Set*) malloc(sizeof(Set));
            set->blue=0;
            set->green=0;
            set->red=0;
            char *setPart = strchr(setsPart, ','); 
            while (setPart != NULL) {
                printf("setPart: %s \n", setPart);
                int length = strlen(setPart);
                char *copy = (char*) malloc(sizeof(char) * 10);
                memcpy(copy, setsPart, setsPart - setPart);
                if (strstr(copy, "blue")) {
                    char *num = (char*) malloc(sizeof(char) * 5);
                    strncpy(num, copy, strlen(copy)-4);
                    set->blue = atoi(num); 
                }
                if (strstr(copy, "green")) {
                    char *num = (char*) malloc(sizeof(char) * 5);
                    strncpy(num, copy, strlen(copy)-5);
                    set->green = atoi(num);
                }
                if (strstr(copy, "red")) {
                    char *num = (char*) malloc(sizeof(char) * 5);
                    strncpy(num, copy, strlen(copy)-3);
                    set->red = atoi(num); 
                }
                setPart = strchr(setsPart+strlen(copy), ',');
            }
            if (setsCount >= setsMax) {
                sets = realloc(sets, sizeof(Set) * setsMax * 2);
                setsMax *= 2;
            }
            sets[setsCount] = *set;
            setsCount++;
            setsPart = strtok(NULL, ";");
        }
        if (gamesCount >= gamesMax) {
            games = realloc(games, sizeof(Game) * gamesMax * 2);
            gamesMax *= 2;
        }
        Game *game = malloc(sizeof(Game));
        game->id = gameId;
        game->sets = sets;
        game->amountOfSets = setsCount;
        games[gamesCount] = *game;
        gamesCount++;
        memset(line,0,sizeof(line));
    }
    int sum = 0;
    for (int i = 0; i < gamesCount; i++) {
        Game *game = &games[i];
        int possible = 1;
        for (int j = 0; j < game->amountOfSets; j++) {
            Set *set = &game->sets[j];
            if (set->blue > MAX_BLUE) {
                possible = 0;
                break;
            }
            if (set->green > MAX_GREEN) {
                possible = 0;
                break;
            }
            if (set->red > MAX_RED) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            printf("game id possible: %d amount of sets: %d\n",game->id,game->amountOfSets);
            sum += game->id;
        }
    }
    printf("%d", sum);
    free(games);
}