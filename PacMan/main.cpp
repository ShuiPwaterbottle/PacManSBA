#include"Game.h"

const int WINDOWS_SIZE_X = (MAP_SIZE + SIDE_INFO_UI_SIEZ) * 2 - 1;
const int WINDOWS_SIZE_Y = MAP_SIZE + INFO_UI_SIZE;
int main() {

	//进入游戏 
	Game gameCtrl;
	int choice = 0;
	while (true) {
		//主界面的选项的选择
		choice = gameCtrl.start();
		if (choice == 0) { //开始游戏
			// 开启游戏前的难度选择
			if(!gameCtrl.settings()) continue;
			// 开启一局游戏
			gameCtrl.init();
			gameCtrl.loop();
		}
	}
}