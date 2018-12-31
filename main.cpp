#include <ncurses.h>
#include <locale.h>

#include <iostream>
#include <fstream>
#include <string>

#define PAGE 10

int main(void)
{
	
	int key;
	int page = 1;
	char str[256];

	setlocale(LC_ALL,"");	//日本語対応

	initscr();
	noecho();
	cbreak();

	do{

		//ファイル読み込み
		std::string file_name = "anime/anime" + std::to_string(page) + ".txt";

		std::ifstream ifs(file_name);
		if (!ifs)
		{
			std::cerr << "失敗" << std::endl;
			ifs.close();
			return -1;
		}

		//表示
		erase();
		int i = 0;
		while(ifs.getline(str,255)){
			move(i,0);
			addstr(str);
			i++;
		}
		refresh();

		//ページの管理
		page = page==10 ? 1 : page+1;

		ifs.close();
		timeout(500);
		key = getch();

	}while(key != 'q');

	endwin();

	return 0;
}
