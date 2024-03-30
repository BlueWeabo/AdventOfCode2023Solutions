#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int isNumber(char ch) {
    if (ch < '0' || ch > '9') return 0;
    return 1;
}

int isSymbol(char ch) {
    if (ch == '.' || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || isNumber(ch)) return 0;
    return 1;
}

int main() {
    char symbols[] = {"*+#$-@%/=&!^)(\"\':;,><?\\_\n"};
    int directions[] = {0,1,2,3,4,5,6,7};
    FILE *input = fopen("../inputs/dayThree.txt", "r");
    if (input == NULL) {
        printf("Couldn't find file\n");
        fclose(input);
        return -1;
    }
    char text[140][200];
    memset(text, '\n', sizeof(char) * 140 * 200);

    int lineNum = 0;
    int total = 0;
    while(fgets(text[lineNum], sizeof(text[lineNum]), input) != NULL) {
        lineNum++;
    }

    for (int i = 0; i < 140; i++) {
        char *line = text[i];

        for (int j = 0; j < 200; j++) {
            if (!isNumber(line[j])) continue;
            int start = j;
            int k = 0;
            int number = 0;
            while (isNumber(line[j])) {
                number *= 10;
                number += line[j]-'0';
                j++;
                k++;
            }
            //printf("Number found: %d \n", number);
            if (start != 0 && isSymbol(text[i][start])) {
                //printf("Number added1: %d \n", number);
                total += number;
                continue;
            }
            if (start+k > 139 && isSymbol(text[i][start+k])) {
                //printf("Number added2: %d \n", number);
                total += number;
                continue;
            }
            int oldTotal = total;
            if (i != 0) {
                for (int r = 0; r <= k; r++) {
                    if (isSymbol(text[i - 1][start+r])) {
                        //printf("Number added3: %d \n", number);
                        total += number;
                        break;
                    }
                }
            }
            if (total > oldTotal) continue;
            if (i != 139) {
                for (int r = 0; r <= k; r++) {
                    if (isSymbol(text[i + 1][start+r])) {
                        //printf("Number added4: %d \n", number);
                        total += number;
                        break;
                    }
                }
            }
        }
    }

    fclose(input);
    printf("%d\n", total);
    return 0;
}
