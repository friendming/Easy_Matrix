#pragma once

#include<cstring>
#include<iostream>

using namespace std;
/////////////////////
char Command[20][100];
int commandPlace[100]={-1};
/////////////////////
int* getCommand(char incom[100]);
int pipeiCommand(char incom[100], char pipeiCom[100]);//指令匹配函数 目前只支持一行中 一种指令只出现一次
void initCommand();
/////////////////////
int* getCommand(char incom[100]) {//返回数组地址
	//清空数组
	for (int i = 0; i < 100; i++) {
		commandPlace[i] = -1;
	}
	initCommand();//初始化
	//压缩空格：多个空格合为一个
	int spaceTimes = 0;
	for (int i = 0; incom[i] != 0; i++) {
		if (incom[i] == 32) {//空格
			spaceTimes++;
		}
		else {
			if (spaceTimes >= 2) {//他前面有好几个空格的话
				for (int j = i-spaceTimes+1; incom[j]!=0; j++) {//后面的填补一波到前面去
					incom[j] = incom[j + spaceTimes-1];
				}
			}
			spaceTimes = 0;//复位0个空格
		}
	}
	///压缩空格结束
	//cout << "空格压缩后>>" << incom << endl;
	for (int com = 0; com < 4; com++) {//逐个指令依次匹配 有几个指令 com就小于几
		int place = pipeiCommand(incom, Command[com]);//返回匹配字符串起始位置
		if (place != -1) {//如果匹配上了
			commandPlace[place] = com;//在相应的位置（该指令在字符串中字符的位置）记录匹配到了第几个指令//之后进行压缩！！！
		}
	}

	return commandPlace;
}

int pipeiCommand(char incom[100], char pipeiCom[100]) {

	//cout << incom << endl << pipeiCom << endl;

	int lenIncom = 0, lenPipeiCom = 0;
	for (int i = 0; incom[i] != 0; i++) {
		lenIncom++;
	}
	for (int i = 0; pipeiCom[i] != 0; i++) {
		lenPipeiCom++;
	}

	//cout << "lenIncom=" << lenIncom << " lenpipeicom=" << lenPipeiCom << endl;

	int i, j;
	for (i = 0; i <= lenIncom - lenPipeiCom; ++i) {
		for (j = 0; j < lenPipeiCom; ++j) {
			if (incom[i + j] != pipeiCom[j]) {
				break;//该字符匹配失败 下一个字符
			}
		}
		if (j == lenPipeiCom) {
			return i;//成功 返回起始字符
		}
	}
	return -1;//全部失败 返回-1
}

void initCommand() {//初始化命令数组
	strcpy_s(Command[0], "set language to Chinese");
	strcpy_s(Command[1], "set language to English");
	strcpy_s(Command[2], "help");
	strcpy_s(Command[3], "end");
}