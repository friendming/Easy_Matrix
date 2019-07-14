#include<iostream>
#include<sstream>   //getline包含 cin不支持输入空格
#include"Command.h"

using namespace std;

int language=0;

int main() {

	char inputCommand[100];
	int findCommand[20];
	showHelp();
	while (1) {//循环
		cin.getline(inputCommand, 100);//用getline可以读取空格
		*findCommand = *getCommand(inputCommand);

		if (findCommand[0] == 0) {
			cout << ">>";
			cout << "语言 = 中文 (部分功能未适配中文 请见谅)" << endl;
			language = 1;
		}
		else if (findCommand[0] == 1) {
			cout << ">>";
			cout << "Language = English" << endl;
			language = 0;
		}
		else if (findCommand[0] == 2) {
			showHelp();
		}
	}

	return 0;
}

void showHelp() {
	if (language == 0) {
		cout << ">>";
		cout << "Help:";
		cout << ">>";
		cout << "Easy Matrix||You can solve easy matrix problems easily!||Produced by QM" << endl;
		cout << ">>";
		cout << "1-Case-sensitive!" << endl;
		cout << ">>";
		cout << "2-Enter \"set language to Chinese\"to change language." << endl;
		cout << ">>";
		cout << "3-Enter \"help\"to show help." << endl;
	}
	else if (language == 1) {
		cout << ">>";
		cout << "帮助：";
		cout << ">>";
		cout << "Easy Matrix||轻松解决简单的矩阵问题！||作者：QM" << endl;
		cout << ">>";
		cout << "1-大小写敏感！" << endl;
		cout << ">>";
		cout << "2-输入 \"set language to English\"切换语言。" << endl;
		cout << ">>";
		cout << "3-输入 \"help\"显示帮助。" << endl;
	}
}