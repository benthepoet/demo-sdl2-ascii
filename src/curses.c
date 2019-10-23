#include <ncurses.h>
#include <unistd.h>

int main (int argc, char **argv) {
  initscr();
  noecho();
  curs_set(FALSE);

  for (int i = 0; i < 80; i++) {
    clear();
    mvprintw(0, i, "oOo");
    refresh();
    usleep(30000);
  }
  
  endwin();
  
  return 0;
}
