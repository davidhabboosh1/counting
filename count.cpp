#include <iostream>

#ifdef _WIN32
#include <Windows.h>;
#else
#include <unistd.h>;
#endif

#include <limits.h>

void count(int start, double speed);

int main()
{
    printf("Counting: ");
    count(INT_MAX - 2, 10);
}

void count(int start, double speed) {
    int c = start;
    while (true) {
        printf("\033[s"); // save cursor position
        printf("%d", c); // print the number

        Sleep(100 / speed); // wait according to the given time

        printf("\033[u"); // return to the saved position
        printf("\033[0K"); // delete everything after the cursor

        c = (c == INT_MAX) ? 0 : c + 1; // increment c
    }
}