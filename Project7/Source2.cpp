#include <conio.h>   
#include <iostream>   
#include <Windows.h> 
#include <ctime>
#define clear system("cls");   
#define pause system("pause")

using namespace std;




int main() {
    setlocale(0, "");
menu:
    bool isOpenBaron = false;
    int map_width = 11;
    int map_height = 11;
    int size = 10;
    char charaster = static_cast<char>(11);
    char Empty_Space = ' ';
    int playerY;
    int playerX;
    int VES = 0;
    int offerVES = 0;
    int mass[11][11]{
    {2,3,3,3,3,3,3,3,3,3,2},
    {2,5,0,0,0,6,6,6,5,0,2},
    {2,6,0,6,0,5,0,6,5,0,2},
    {2,6,5,0,6,0,0,0,0,5,2},
    {2,6,6,6,0,6,5,6,0,6,2},
    {2,0,0,5,6,1,6,6,0,0,2},
    {2,0,6,0,6,0,5,0,0,6,2},
    {2,0,0,0,6,0,6,6,0,0,2},
    {2,0,6,0,6,0,0,6,6,0,2},
    {2,9,6,0,0,0,5,6,0,5,2},
    {2,3,3,3,3,3,3,3,3,3,2},
    };



    system("cls");
    cout << "\n\n\n\t\t\t\t\x1b[94m<<<<<<<<<������>>>>>>>>\n\n\x1b[0m";
    cout << "\t\t\x1b[93m------------------------[1]������------------------------\x1b[0m\n";
    cout << "\t\t\x1b[93m------------------------[2]�������------------------------\x1b[0m\n";
    cout << "\t\t\x1b[93m------------------------[3]�����------------------------\x1b[0m\n";
    int cnt = _getch();
    
    switch (cnt) {
    case 49://��ͨ���
        goto start;
    case 50://������

        clear;
        cout << "\t\t\t\t\x1b[95m�������\x1b[0m\n\n";
        cout << "\x1b[94m �� - \x1b[34m�����������(������)\x1b[0m \n\n";
        cout << " \x1b[93m���� ������ ������� \x1b[92m��� ( # ) \x1b[93m� ������ ��� \x1b[95m������ ( ! )\x1b[93m\n\n";
        cout << " ��� ��� �� ����� �������  \x1b[31m�������� ( & ),\x1b[93m ��� ���� �������� ��, \x1b[31m�������� � �����\x1b[93m\n\n";
        cout << " ���������� �������������� ��� ������ ������ WASD �� ������ ������� �� ��� ������� \n\n";
        cout << " ������� ��� ���� \x1b[92m���,\x1b[93m ������� ������ � �������� WIN\x1b[0m\n\n";
        cout << " \x1b[33m������� ��� ���� �� �������� ����������� ������������ � ������� �� ���������� \n �� ����� ��������� � ���������\n";
        cout << " ��� �� ����� ������, ����� �������� ������ ������� �����\n ������� ������ �����, ������������ ������������ ���� �������������� ����\n";
        cout << " ����� 600 ��������� ���������� ����\n ��������� ������� ����������� ������ ������.(DLC)\x1b[0m\n\n";
        cout << " \x1b[32m��� ������ � ���� ����� ����� �����\n\x1b[0m";
        switch (_getch());
        goto menu;
        break;
    case 51:
        return 0;
        break;
    default:
        clear;
        cout << "\t\t\t\t \x1b[31m��� ���������,�����������\x1b[0m\n";
        cout << "\t\t\t\t���� ������ ���� 1 ����� ������ ���� 2 ����� ������������ � ���������\n";
        pause;
        goto menu;
    }

start:
    clock_t t0 = clock();
    while (true) {
        clear;
        cout << "\n\t\t\t\t\t\x1b[95m   ������ � ���  \x1b[0m\n\n";
        cout << "\t\t\t\t\t\x1b[32m  ������� ����: " << VES << "\x1b[0m\n\n";
        for (int y = 0; y < map_height; y++) {
            cout << "\t\t\t\t\t";
            for (int x = 0; x < map_width; x++) {
                if (mass[y][x] == 1) {
                    cout << "\x1b[94m" << static_cast<char>(11) << Empty_Space << "\x1b[0m";
                    playerY = y; playerX = x;

                }

                else if (mass[y][x] == 2) {
                    cout << "\x1b[34m|\x1b[0m";
                }
                else if (mass[y][x] == 3) {
                    cout << "\x1b[33m- \x1b[0m";
                }
                else if (mass[y][x] == 5) {
                    cout << "\x1b[92m# \x1b[0m"; //���
                }
                else if (mass[y][x] == 6) {
                    cout << "\x1b[31m&\x1b[0m ";   //��������
                }
                else if (mass[y][x] == 10) {
                    cout << ". ";
                }
                else if (mass[y][x] == 9) {
                    cout << "\x1b[95m! \x1b[0m";
                }
                

                else {
                    cout << ". ";
                }


            }
            cout << endl;
        }

        if (VES >= 10) {
            isOpenBaron = true;
            
        }

        switch (_getch()) {
            //w 
        case 150:
        case 119:
        case 230:
        case 87:

            if (mass[playerY - 1][playerX] != 2 && mass[playerY - 1][playerX] != 3) {
                if (mass[playerY - 1][playerX] == 6) {
                    clear;
                    cout << "\t\t\t\t\x1b[91m �����������, ������� , ��������� \x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;

                }
                else if (mass[playerY - 1][playerX] == 5) {
                    VES++;
                    cout << "�� ������� ���. ";
                    system("pause");
                }
                mass[playerY][playerX] = 0;
                mass[--playerY][playerX] = 1;
            }



            break;
            //a 
        case 148:
        case 97:
        case 65:
        case 228:
            if (mass[playerY][playerX - 1] != 2) {

                if (mass[playerY][playerX - 1] == 6) {
                    clear;
                    cout << "\t\t\t\t\x1b[91m �����������, ������� , ������ ���� ���� �����\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;
                }
                else if (mass[playerY][playerX - 1] == 5) {
                    VES++;
                    cout << "�� ������� ���. ";
                    system("pause");
                }
                mass[playerY][playerX] = 0;
                mass[playerY][--playerX] = 1;

            }

            break;
            //s 
        case 155:
        case 83:
        case 115:
        case 235:

            if (mass[playerY + 1][playerX] != 2 && mass[playerY + 1][playerX] != 3 && mass[playerY + 1][playerX] != 9 ) {
                if (mass[playerY + 1][playerX] == 6) {
                    clear;
                    cout << "\t\t\t\t\x1b[91m ������ ���� ���� �����\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;

                }
                
                else if (mass[playerY + 1][playerX] == 5) {
                    VES++;
                    cout << "�� ������� ���. ";
                    system("pause");
                }

                
                mass[playerY][playerX] = 0;
                mass[++playerY][playerX] = 1;


                if (mass[playerY + 1][playerX] == 9 && isOpenBaron == true) {
                    cout << "\x1b[32m�� ������ ������ ����������� ���� ������\n";
                    mass[playerY][playerX] = 0;
                    mass[++playerY][playerX] = 1;
                    offerVES = VES;
                    VES = 0;
                    mass[playerY][playerX] = 0;
                    mass[++playerY][playerX] = 1;
                    pause;
                    cout << "\x1b[0m";
                }
                else if (mass[playerY + 1][playerX] == 9 && isOpenBaron == false) {
                    cout << "�� ������ ������������ ����, ������� ����� ������� 10\n";
                    pause;
                    
                  
                }


            }
      

            break;
            //d 
        case 130:
        case 100:
        case 68:
        case 162:
            if (mass[playerY][playerX + 1] != 2) {
                if (mass[playerY][playerX + 1] == 6) {
                    clear;
                    cout << "\t\t\t\t\x1b[91m ������ ���� ���� �����\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;
                }
                else if (mass[playerY][playerX + 1] == 5) {
                    VES++;
                    cout << "�� ������� ���. ";
                    system("pause");
                }
                mass[playerY][playerX] = 0;
                mass[playerY][++playerX] = 1;
            }

            break;

        default:
            cout << "��..... ������ ?\n";
            pause;
        }

        if (offerVES >= 10) {
            goto win;
        }

    }
win:
    clear;
    clock_t t1 = clock();
    cout << "\t\t\t\x1b[32m���,�������,�� ������ ���� ���\x1b[0m\n";
    cout << "\t\t\t\t\x1b[32m���� �������:" << offerVES << "\x1b[0m\n\n";
    cout << "\t\t\t\t\x1b[32;45m���� �����: " << (double)(t1 - t0) / CLOCKS_PER_SEC << "\x1b[0m"<< endl << endl;
    if ((double)(t1 - t0) / CLOCKS_PER_SEC < 15) {
        cout << "\t\x1b[95m��������� ������ ? ������� ��� � ���� �� ���������� ��� �������� ?\x1b[0m\n\n";
    }
    else if ((double)(t1 - t0) / CLOCKS_PER_SEC > 55) {
        cout << "\x1b[95m���� ��� ����� ������� �� ��� �������� �������\x1b[0m\n";
    }
    cout << "\x1b[93m";
    pause;
    cout << "\x1b[0m";
    goto menu;

    int _;
    cin >> _;
    return 0;


}