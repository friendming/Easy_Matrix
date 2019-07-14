#pragma once

#include<cstring>
#include<iostream>

using namespace std;
/////////////////////
char Command[20][100];
int commandPlace[100]={-1};
/////////////////////
int* getCommand(char incom[100]);
int pipeiCommand(char incom[100], char pipeiCom[100]);//ָ��ƥ�亯�� Ŀǰֻ֧��һ���� һ��ָ��ֻ����һ��
void initCommand();
/////////////////////
int* getCommand(char incom[100]) {//���������ַ
	initCommand();//��ʼ��
	//ѹ���ո񣺶���ո��Ϊһ��
	int spaceTimes = 0;
	for (int i = 0; incom[i] != 0; i++) {
		if (incom[i] == 32) {//�ո�
			spaceTimes++;
		}
		else {
			if (spaceTimes >= 2) {//��ǰ���кü����ո�Ļ�
				for (int j = i-spaceTimes+1; incom[j]!=0; j++) {//������һ����ǰ��ȥ
					incom[j] = incom[j + spaceTimes-1];
				}
			}
			spaceTimes = 0;//��λ0���ո�
		}
	}
	///ѹ���ո����
	cout << "�ո�ѹ����>>" << incom << endl;
	for (int com = 0; com < 20; com++) {//���ָ������ƥ��
		int place = pipeiCommand(incom, Command[com]);//����ƥ��λ��
		if (place != -1) {//���ƥ������
			commandPlace[place] = com;//����Ӧ��λ�ã���ָ�����ַ������ַ���λ�ã���¼ƥ�䵽�˵ڼ���ָ��//֮�����ѹ��������
		}
	}
	return commandPlace;
}

int pipeiCommand(char incom[100], char pipeiCom[100]) {//ָ��ƥ�亯�� Ŀǰֻ֧��һ���� һ��ָ��ֻ����һ��

	int lenIncom=0, lenPipeiCom=0;
	for (int i = 0; incom[i] != 0; i++) {
		lenIncom++;
	}
	for (int i = 0; pipeiCom[i] != 0; i++) {
		lenPipeiCom++;
	}
	int i, j;
	for (i = 0; i <= lenIncom - lenPipeiCom; ++i) {
		for (j = 0; j < lenPipeiCom; ++j) {
			if (incom[i + j] != pipeiCom[j]) {
				break;
			}
		}
		if (j == lenPipeiCom) {
			return i;//����ָ�������ĸλ��
		}
	}
	return -1;
}

void initCommand() {//��ʼ����������
	strcpy_s(Command[0], "set language to English");
	strcpy_s(Command[1], "set language to Chinese");
	strcpy_s(Command[2], "help");
}