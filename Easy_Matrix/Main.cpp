#include<iostream>
#include<sstream>   //getline���� cin��֧������ո�
#include"Command.h"

using namespace std;

void showHelp();//�������

int language=0;

int main() {

	char inputCommand[100];
	int findCommand[20];
	showHelp();
	while (1) {//ѭ��
		cout << ">> ";
		cin.getline(inputCommand, 100);//��getline���Զ�ȡ�ո�
		//cout << inputCommand << endl;
		*findCommand = *getCommand(inputCommand);

		if (findCommand[0] == 0) {
			cout << "���� = ���� (���ֹ���δ�������� �����)" << endl;
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
				cout << "δָ֪��" << endl;
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
		cout << "������" << endl;
		cout << "Easy Matrix||���ɽ���򵥵ľ������⣡||���ߣ�QM" << endl;
		cout << "1-��Сд���У�" << endl;
		cout << "2-���� \"set language to English\"�л����ԡ�" << endl;
		cout << "3-���� \"help\"��ʾ������" << endl;
		cout << "4-���� \"end\"�رճ���" << endl;
	}
}