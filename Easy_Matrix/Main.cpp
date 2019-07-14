#include<iostream>
#include<sstream>   //getline包含 cin不支持输入空格
#include"Command.h"

using namespace std;

int main() {

	char inputCommand[100];
	cout << "Easy Matrix|You can solve easy matrix problems easily!|Produced by QM" << endl;
	cout << "Enter \"set language = English\"to change language." << endl;
	cin.getline(inputCommand,100);//用getline可以读取空格
	getCommand(inputCommand);

	return 0;
}