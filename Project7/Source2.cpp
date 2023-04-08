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
    cout << "\n\n\n\t\t\t\t\x1b[94m<<<<<<<<<ШИРЯЛА>>>>>>>>\n\n\x1b[0m";
    cout << "\t\t\x1b[93m------------------------[1]Начать------------------------\x1b[0m\n";
    cout << "\t\t\x1b[93m------------------------[2]Правила------------------------\x1b[0m\n";
    cout << "\t\t\x1b[93m------------------------[3]Выход------------------------\x1b[0m\n";
    int cnt = _getch();
    
    switch (cnt) {
    case 49://ОДНЁРКА
        goto start;
    case 50://Двойка

        clear;
        cout << "\t\t\t\t\x1b[95mПравила\x1b[0m\n\n";
        cout << "\x1b[94m Вы - \x1b[34mШНЫРЬКУРЬЕР(ШИРЯЛА)\x1b[0m \n\n";
        cout << " \x1b[93mВаша задача собрать \x1b[92mВЕС ( # ) \x1b[93mи отдать его \x1b[95mБАРОНУ ( ! )\x1b[93m\n\n";
        cout << " Вас так же могут поймать  \x1b[31mСПОРТИКИ ( & ),\x1b[93m вам надо избегать их, \x1b[31mСПОРТИКИ в гневе\x1b[93m\n\n";
        cout << " Управление осуществляется при помощи клавиш WASD ты должен собрать то что потерял \n\n";
        cout << " Доставь мне весь \x1b[92mВЕС,\x1b[93m который найдёшь и получишь WIN\x1b[0m\n\n";
        cout << " \x1b[33mГоворят что если не проявить достаточной осторожности и выпасть из реальности \n то можно оказаться в Закулисье\n";
        cout << " где не будет ничего, кроме затхлого запаха ветхого ковра\n безумия желтых обоев, бесконечного невыносимого шума люминесцентных ламп\n";
        cout << " также 600 миллионов квадратных миль\n случайным образом совмещённых пустых комнат.(DLC)\x1b[0m\n\n";
        cout << " \x1b[32mДля выхода в меню нажми любую попку\n\x1b[0m";
        switch (_getch());
        goto menu;
        break;
    case 51:
        return 0;
        break;
    default:
        clear;
        cout << "\t\t\t\t \x1b[31mЖми нормально,ШНЫРЬКУРЬЕР\x1b[0m\n";
        cout << "\t\t\t\tНадо нажать либо 1 чтобы начать либо 2 чтобы ознакомиться с правилами\n";
        pause;
        goto menu;
    }

start:
    clock_t t0 = clock();
    while (true) {
        clear;
        cout << "\n\t\t\t\t\t\x1b[95m   ШИРЯЛА И ВЕС  \x1b[0m\n\n";
        cout << "\t\t\t\t\t\x1b[32m  Собрано ВЕСА: " << VES << "\x1b[0m\n\n";
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
                    cout << "\x1b[92m# \x1b[0m"; //ВЕС
                }
                else if (mass[y][x] == 6) {
                    cout << "\x1b[31m&\x1b[0m ";   //СПОРТИКИ
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
                    cout << "\t\t\t\t\x1b[91m ШНЫРЬКУРЬЕР, ПОПАЛСЯ , ИЗВИНЯЙСЯ \x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;

                }
                else if (mass[playerY - 1][playerX] == 5) {
                    VES++;
                    cout << "Вы собрали ВЕС. ";
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
                    cout << "\t\t\t\t\x1b[91m ШНЫРЬКУРЬЕР, ПОПАЛСЯ , ЛОМАЕМ РУКУ НОГУ БИТОЙ\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;
                }
                else if (mass[playerY][playerX - 1] == 5) {
                    VES++;
                    cout << "Вы собрали ВЕС. ";
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
                    cout << "\t\t\t\t\x1b[91m ЛОМАЕМ РУКУ НОГУ БИТОЙ\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;

                }
                
                else if (mass[playerY + 1][playerX] == 5) {
                    VES++;
                    cout << "Вы собрали ВЕС. ";
                    system("pause");
                }

                
                mass[playerY][playerX] = 0;
                mass[++playerY][playerX] = 1;


                if (mass[playerY + 1][playerX] == 9 && isOpenBaron == true) {
                    cout << "\x1b[32mВы отдали нужное колличество веса барону\n";
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
                    cout << "Ты собрал недостаточно веса, приходи когда соберёшь 10\n";
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
                    cout << "\t\t\t\t\x1b[91m ЛОМАЕМ РУКУ НОГУ БИТОЙ\x1b[0m\n\n\n\n\n\n\n";
                    pause;
                    goto menu;
                }
                else if (mass[playerY][playerX + 1] == 5) {
                    VES++;
                    cout << "Вы собрали ВЕС. ";
                    system("pause");
                }
                mass[playerY][playerX] = 0;
                mass[playerY][++playerX] = 1;
            }

            break;

        default:
            cout << "Ты..... Далбоёб ?\n";
            pause;
        }

        if (offerVES >= 10) {
            goto win;
        }

    }
win:
    clear;
    clock_t t1 = clock();
    cout << "\t\t\t\x1b[32mООО,молодец,ты достал весь вес\x1b[0m\n";
    cout << "\t\t\t\t\x1b[32mВеса собрано:" << offerVES << "\x1b[0m\n\n";
    cout << "\t\t\t\t\x1b[32;45mВаше время: " << (double)(t1 - t0) / CLOCKS_PER_SEC << "\x1b[0m"<< endl << endl;
    if ((double)(t1 - t0) / CLOCKS_PER_SEC < 15) {
        cout << "\t\x1b[95mНастолько быстро ? Сколько раз в день ты исполняешь акт онанизма ?\x1b[0m\n\n";
    }
    else if ((double)(t1 - t0) / CLOCKS_PER_SEC > 55) {
        cout << "\x1b[95mДаже моя бабка быстрее бы эти пакетики собрала\x1b[0m\n";
    }
    cout << "\x1b[93m";
    pause;
    cout << "\x1b[0m";
    goto menu;

    int _;
    cin >> _;
    return 0;


}