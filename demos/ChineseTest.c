//使用curses库编写一个程序，先清除屏幕，然后在(2,4)位置显示字符串"Hello"
#include <curses.h>
int main()
{
    initscr(); //初始化
    clear(); //清除屏幕
    mvprintw(2,10,"01234567890123456789");  // expect : 01234567890123456789
    mvprintw(3,10,"零一二三四五六七八九");  // expect : 零一二三四五六七八九
    mvprintw(3,13,"012345");                // expect : 零 012345 五六七八九
    mvprintw(3,40,"012345 @ 13"); 
    mvprintw(4,10,"零一二三四五六七八九");  
    mvprintw(4,14,"中文");                  // expect : 零一中文四五六七八九
    mvprintw(4,40,"中文 @ 14"); 
    mvprintw(5,10,"零一二三四五六七八九"); 
    mvprintw(5,13,"中文字符");              // expect : 零 中文字符 六七八九
    mvprintw(5,40,"中文字符 @ 13"); 
    mvprintw(6,10,"零一二三四五六七八九"); 
    mvprintw(6,14,"0123456");               // expect : 零一0123456 六七八九
    mvprintw(6,40,"0123456 @ 14"); 
    mvprintw(7,10,"01234567890123456789"); 
    getch(); //等待用户输入
    endwin(); //释放资源
    return 0;
}