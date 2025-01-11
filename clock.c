#include <ncurses.h>
#include <time.h>
#include <string.h>

void printcenter(char *str, int yoffset) {
    WINDOW *win = stdscr;
    int h, w;
    getmaxyx(win, h, w);
    int x = (w - strlen(str)) / 2;
    int y = h / 2 + yoffset;
    mvwprintw(win, y, x, "%s", str);
}

int main(void) {
    initscr();
    noecho();
    curs_set(0);
    start_color();
    timeout(1000);

    init_pair(1, COLOR_WHITE, COLOR_BLUE);
    bkgd(COLOR_PAIR(1));

    int h, w;
    getmaxyx(stdscr,h,w);

    while(1)
    {
        time_t t = time(NULL);
        struct tm *tm_info = localtime(&t);

        char timestr[9];
        strftime(timestr, sizeof(timestr), "%H:%M:%S", tm_info);

        char datestr[30];
        strftime(datestr, sizeof(datestr), "%A, %B %d, %Y", tm_info);

        clear();
        printcenter(timestr, -1);
        printcenter(datestr, 0);// Print the date
        refresh();

        if(getch() == 'q') break;
    }

    endwin();
    return 0;
}
