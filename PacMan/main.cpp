#include"Game.h"

const int WINDOWS_SIZE_X = (MAP_SIZE + SIDE_INFO_UI_SIEZ) * 2 - 1;
const int WINDOWS_SIZE_Y = MAP_SIZE + INFO_UI_SIZE;
int main() {

	//������Ϸ 
	Game gameCtrl;
	int choice = 0;
	while (true) {
		//�������ѡ���ѡ��
		choice = gameCtrl.start();
		if (choice == 0) { //��ʼ��Ϸ
			// ������Ϸǰ���Ѷ�ѡ��
			if(!gameCtrl.settings()) continue;
			// ����һ����Ϸ
			gameCtrl.init();
			gameCtrl.loop();
		}
	}
}