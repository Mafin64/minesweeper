#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
using std::cout;
using std::cin;

void vypispole(char hracipole[5][5]);
void konechry(char hracipole[5][5]);
int main()
{
    char* loc = setlocale(LC_CTYPE, "");
    char hracipole[5][5] = {
        {'#', 'X', '#', '#', '#'},
        {'#', '#', '#', 'X', '#'},
        {'#', '#', '#', '#', '#'},
        {'#', '#', 'X', 'X', '#'},
        {'X', '#', '#', 'X', '#'} };

    int vstupX = 0;
    int vstupY = 0;
    int bombyvokoli = 0;

    while (true) {
        system("cls");
        vypispole(hracipole);

        printf("Zadejte X souřadnici: ");
        cin >> vstupX;
        printf("Zadejte Y souřadnici: ");
        cin >> vstupY;

        if (hracipole[vstupY][vstupX] == 'X')
        {
            konechry(hracipole);
            printf("Vybouch jsi.");
            return 1;
        }

        if (hracipole[vstupY][vstupX] == '#')
        {
            printf("Nevybouch jsi, vyber další pozici.\n\n");
        }

        for (int k = vstupY - 1; k <= vstupY + 1; k++)

        {
            for (int o = vstupX - 1; o <= vstupX + 1; o++)
            {
                if (hracipole[k][o] == 'X');
                {
                    bombyvokoli++;
                }
            }
        }

        hracipole[vstupY][vstupX] = bombyvokoli + '0';
        bombyvokoli = 0;
    }
}

void vypispole(char hracipole[5][5]) {
    cout << "    0 1 2 3 4 X\n";
    cout << "  " << char(218) << "-----------\n";

    for (int i = 0; i < 5; i++)
    {
        printf("%d |", i);
        for (int j = 0; j < 5; j++)
        {
            if (hracipole[i][j] == 'X')
            {
                cout << " #";
            }

            else if (hracipole[i][j] == '#')
            {
                cout << " #";
            }

            else
            {
                cout << " " << hracipole[i][j];
            }
        }
        puts("");
    }
    cout << "Y\n\n";
}

void konechry(char hracipole[5][5])
{
    system("cls");
    cout << "    0 1 2 3 4 X\n";
    cout << "  " << char(218) << "-----------\n";

    for (int i = 0; i < 5; i++)
    {
        printf("%d |", i);

        for (int j = 0; j < 5; j++)
        {
            if (hracipole[i][j] == 'X')
            {
                cout << " X";
            }

            else if (hracipole[i][j] == '#')
            {
                cout << " #";
            }

            else
            {
                cout << " " << hracipole[i][j];
            }
        }
        puts("");
    }

    cout << "Y\n\n";
}
