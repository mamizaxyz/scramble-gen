#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SLEN randint(25, 29)

/* Function deceleration */
int randint(int min, int max);
void genscramble();

/* Variables */
char *moves[] = {
        "U",
        "D",
        "F",
        "B",
        "L",
        "R"
};
char *dirs[] = {
        "" ,
        "'",
        "2"
};
char scramble[100];

/* Function implementation */
int
randint(int min, int max)
{
        size_t result = (rand() % (max - min)) + min;
        return result;
}

void
genscramble()
{
        char *move  = moves[randint(0, 6)];
        char *dir   = dirs [randint(0, 3)];
        char *tmove = move;
        char slen[2];
        sprintf(slen, "%d", SLEN);
        size_t i = 0;
        do {
                while (tmove == move) {
                        move = moves[randint(0, 6)];
                }
                strcat(scramble, move);
                strcat(scramble, dir);
                strcat(scramble, " ");
                tmove = move;
                dir = dirs[randint(0, 3)];
                i++;
        } while (i < SLEN);
        strcat(scramble, "[");
        strcat(scramble, slen);
        strcat(scramble, "]");
}

int
main(void)
{
        srand(time(NULL));
        genscramble();
        printf("%s\n", scramble);
        return 0;
}
