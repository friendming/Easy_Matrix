#include<iostream>
#include"Command.h"

using namespace std;

int main() {
	char inputCommand[100];
	cout << "Easy Matrix|You can solve easy matrix problems easily!|Produced by QM" << endl;
	cout << "Enter \"set language = English\"to change language." << endl;
	cin >> inputCommand;
	getCommand(inputCommand);

	return 0;
}