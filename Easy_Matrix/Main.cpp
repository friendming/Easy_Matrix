#include<iostream>
#include<sstream>   //getline���� cin��֧������ո�
#include"Command.h"

using namespace std;

int language=0;

int main() {

	char inputCommand[100];
	int findCommand[20];
	showHelp();
	while (1) {//ѭ��
		cin.getline(inputCommand, 100);//��getline���Զ�ȡ�ո�
		*findCommand = *getCommand(inputCommand);

		if (findCommand[0] == 0) {
			cout << ">>";
			cout << "���� = ���� (���ֹ���δ�������� �����)" << endl;
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
		cout << "������";
		cout << ">>";
		cout << "Easy Matrix||���ɽ���򵥵ľ������⣡||���ߣ�QM" << endl;
		cout << ">>";
		cout << "1-��Сд���У�" << endl;
		cout << ">>";
		cout << "2-���� \"set language to English\"�л����ԡ�" << endl;
		cout << ">>";
		cout << "3-���� \"help\"��ʾ������" << endl;
	}
}