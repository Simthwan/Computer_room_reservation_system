#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include<map>
#include<string>

class OrderFile
{
public:

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updataOrder();

	//��ȡ�ļ���Ϣ��������map������
	void interceptdata(string &item, map<string, string>&m);

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��¼������	key��¼����		value�����¼��ֵ����Ϣ
	map<int, map<string, string>>m_orderData;

};