#include<iostream>
#include<sstream>   //getline���� cin��֧������ո�
#include"Command.h"

using namespace std;

int main() {

	char inputCommand[100];
	cout << "Easy Matrix|You can solve easy matrix problems easily!|Produced by QM" << endl;
	cout << "Enter \"set language = English\"to change language." << endl;
	cin.getline(inputCommand,100);//��getline���Զ�ȡ�ո�
	getCommand(inputCommand);

	return 0;
}