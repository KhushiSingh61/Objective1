#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void clear_screen_fast() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {0, 0};
    SetConsoleCursorPosition(h, pos);
}

void draw_border_and_hud(int score, int lives, int sleepTime) {
    printf("|--- --- ---|   Score: %d   Lives: %d   Speed: %d ms\n", score, lives, sleepTime);
}

int read_key() {
    int ch = getch();
    if (ch == 0 || ch == 224) {
        ch = getch();
    }
    return ch;
}

void show_instructions() {
    system("cls");
    printf("=== Instructions ===\n\n");
    printf("Move the player left/right using the LEFT and RIGHT arrow keys.\n");
    printf("Avoid falling obstacles. You start with 3 lives.\n");
    printf("Score increases by 1 for each obstacle you avoid.\n");
    printf("Game speed increases as your score increases.\n\n");
    printf("Press any key to return to menu...\n");
    getch();
}

int play_game() {
    int x = 1;
    int step = 0;
    int obstaclePos;
    int score = 0;
    int lives = 3;
    int baseSleep = 120;
    int sleepTime = baseSleep;
    const int minSleep = 40;
    int difficulty_step = 5;

    srand((unsigned)time(NULL));
    obstaclePos = rand() % 3;

    while (1) {
        if (_kbhit()) {
            int ch = read_key();
            if (ch == 75 && x > 0)
                x--;
            else if (ch == 77 && x < 2)
                x++;
            else if (ch == 'q' || ch == 'Q') {
                return 1;
            }
        }

        clear_screen_fast();
        draw_border_and_hud(score, lives, sleepTime);
        for (int i = 0; i < 10; i++) {
            if (i == step) {
                if (obstaclePos == 0)
                    printf("| %c        |\n", 1);
                else if (obstaclePos == 1)
                    printf("|     %c    |\n", 1);
                else if (obstaclePos == 2)
                    printf("|        %c |\n", 1);
            } else {
                printf("|           |\n");
            }
        }

        if (x == 0)
            printf("| %c         |\n", 6);
        else if (x == 1)
            printf("|     %c     |\n", 6);
        else if (x == 2)
            printf("|        %c  |\n", 6);

        if (step == 10) {
            if (x == obstaclePos) {
                lives--;
                Sleep(900);

                if (lives <= 0) {
                    clear_screen_fast();
                    printf("\n\n   ********** GAME OVER **********\n");
                    printf("   Final Score: %d\n\n", score);
                    printf("   Press 'R' to restart, 'Q' to return to menu.\n");

                    while (1) {
                        if (_kbhit()) {
                            int k = read_key();
                            if (k == 'r' || k == 'R') {
                                score = 0;
                                lives = 3;
                                x = 1;
                                step = 0;
                                obstaclePos = rand() % 3;
                                baseSleep = 120;
                                sleepTime = baseSleep;
                                break;
                            } else if (k == 'q' || k == 'Q') {
                                return 1;
                            }
                        }
                        Sleep(50);
                    }
                } else {
                    obstaclePos = rand() % 3;
                    step = 0;
                    for (int t = 0; t < 6; t++) {
                        clear_screen_fast();
                        draw_border_and_hud(score, lives, sleepTime);
                        for (int i = 0; i < 10; i++) {
                            if (i == step) {
                                if (obstaclePos == 0)
                                    printf("| %c        |\n", 1);
                                else if (obstaclePos == 1)
                                    printf("|     %c    |\n", 1);
                                else if (obstaclePos == 2)
                                    printf("|        %c |\n", 1);
                            } else {
                                printf("|           |\n");
                            }
                        }
                        if (x == 0) printf("| %c         |\n", 6);
                        else if (x == 1) printf("|     %c     |\n", 6);
                        else printf("|        %c  |\n", 6);
                        Sleep(100);
                    }
                }
            } else {
                score++;
                if (score % difficulty_step == 0 && sleepTime > minSleep) {
                    sleepTime -= 10;
                    if (sleepTime < minSleep) sleepTime = minSleep;
                }
            }
            step++;
        }

        Sleep(sleepTime);

        step++;

        if (step > 10) {
            step = 0;
            obstaclePos = rand() % 3;
        }
    }

    return 1;
}

int main() {
    int menuChoice = 0;

    system("color 4F");

    while (1) {
        system("cls");
        printf("=====================================\n");
        printf("        SIMPLE LANE AVOIDANCE        \n");
        printf("=====================================\n\n");
        printf("1. Start Game\n");
        printf("2. Instructions\n");
        printf("3. Exit\n\n");
        printf("Choose option (1-3): ");

        int c = read_key();
        if (c == '1') {
            int ret = play_game();
            if (ret == 0) break;
        } else if (c == '2') {
            show_instructions();
        } else if (c == '3' || c == 'q' || c == 'Q') {
            system("cls");
            printf("Exiting... Goodbye!\n");
            break;
        } else {
            Sleep(150);
        }
    }

    return 0;
}