#include <stdio.h>
#include <stdlib.h>
#include "conio.h"

enum
{
    MONSTER_PLAYER,
    MONSTER_SLIME,
    MONSTER_MAX
};

enum
{
    CARACTER_PLAYER,
    CARACTER_MONSTER,
    CARACTER_MAX
};

enum
{
    COMMAND_FIGHT,
    COMMAND_SPELL,
    COMMAND_RUN,
    COMMAND_MAX,
};


typedef struct{
    int hp;
    int maxHp;
    int mp;
    int maxMp;
    char name[10 * 2 +1];
    char aa[256];
    int command;
}CARACTER;

CARACTER monsters[MONSTER_MAX] =
{

    {
        15,
        15,
        15,
        15,
        "ゆうしゃ",
    },
    {
        3,
        3,
        0,
        0,
        "スライム",
        "／・д・＼\n"
        "~~~~~~~~~"
    },
};

CARACTER characters[CARACTER_MAX];

void Init()
{
    characters[CARACTER_PLAYER] =monsters[MONSTER_PLAYER];
}

void DrawBattleScreen()
{
    system("clear");
    
    printf("%s\n",characters[CARACTER_PLAYER].name);

    printf("HP: %d/%d MP :%d/%d\n",
        characters[CARACTER_PLAYER].hp,
        characters[CARACTER_PLAYER].maxHp,
        characters[CARACTER_PLAYER].mp,
        characters[CARACTER_PLAYER].maxMp);

    printf("\n");

    printf("%s",characters[CARACTER_MONSTER].aa);

    printf("(HP: %d/%d)\n",
        characters[CARACTER_MONSTER].hp,
        characters[CARACTER_MONSTER].maxHp);

    printf("\n");
}

void Battle(int _monster)
{
    characters[CARACTER_MONSTER] = monsters[_monster]; 
    DrawBattleScreen();

    printf("%sが あらわれた ! \n", characters[CARACTER_MONSTER].name);

    _getch();

    while (1)
    {
        for(int i=0; i < CARACTER_MAX; i++)
        {
            DrawBattleScreen();

            switch(characters[i].command)
            {
            case COMMAND_FIGHT:
                printf("%sのこうげき!\n", characters[i].name);
                _getch();

                break;

            case COMMAND_SPELL:
                break;

            case COMMAND_RUN:
                break;
            }

        }
    }
    
}

int main()
{
    Init();

    Battle(MONSTER_SLIME);
}
