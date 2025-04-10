#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <windows.h>
using std::cout;
using std::cin;


void vypispole(char hracipole[5][5]);
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

        if (hracipole[vstupX][vstupY] == 'X')
        {
            system("cls");
            cout << "    0 1 2 3 4 Y\n";
            cout << "   " << "-----------\n";

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

            cout << "X\n\n";
            printf("Vybouch jsi.");
            return 1;
        }

        if (hracipole[vstupX][vstupY] == '#')
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

        hracipole[vstupX][vstupY] = bombyvokoli + '0';
        bombyvokoli = 0;
    }
}

void vypispole(char hracipole[5][5]) {
    cout << "    0 1 2 3 4 Y\n";
    cout << "   " << "-----------\n";

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
    cout << "X\n\n";
}
