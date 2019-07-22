#include<iostream>
#include<sstream>   //getline包含 cin不支持输入空格
#include"Command.h"

using namespace std;

void showHelp();//输出帮助

int language=0;

int main() {

	char inputCommand[100];
	int findCommand[20];
	showHelp();
	while (1) {//循环
		cout << ">> ";
		cin.getline(inputCommand, 100);//用getline可以读取空格
		//cout << inputCommand << endl;
		*findCommand = *getCommand(inputCommand);

		if (findCommand[0] == 0) {
			cout << "语言 = 中文 (部分功能未适配中文 请见谅)" << endl;
			language = 1;
		}
		else if (findCommand[0] == 1) {
			cout << "Language = English" << endl;
			language = 0;
		}
		else if (findCommand[0] == 2) {
			showHelp();
		}
		else if (findCommand[0] == 3) {
			exit(0);
		}
		else {
			if (language == 0) {
				cout << "Unknown command." << endl;
			}
			else {
				cout << "未知指令" << endl;
			}
		}
	}

	return 0;
}

void showHelp() {
	if (language == 0) {
		cout << "Help:" << endl;
		cout << "Easy Matrix||You can solve easy matrix problems easily!||Produced by QM" << endl;
		cout << "1-Case-sensitive!" << endl;
		cout << "2-Enter \"set language to Chinese\"to change language." << endl;
		cout << "3-Enter \"help\"to show help." << endl;
		cout << "4-Enter \"end\"to close EasyMatrix." << endl;
	}
	else if (language == 1) {
		cout << "帮助：" << endl;
		cout << "Easy Matrix||轻松解决简单的矩阵问题！||作者：QM" << endl;
		cout << "1-大小写敏感！" << endl;
		cout << "2-输入 \"set language to English\"切换语言。" << endl;
		cout << "3-输入 \"help\"显示帮助。" << endl;
		cout << "4-输入 \"end\"关闭程序。" << endl;
	}
}