#include "teacher.h"
#include"orderFile.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int empId, string name, string pwd)
{
	//��ʼ������
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::openMenu()
{
	cout << "��ӭ��ʦ: " << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|            2.���ԤԼ            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|            0.ע����¼            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ���: " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		string week = "ԤԼ����: ��";
		if (of.m_orderData[i]["date"] == "1")
		{
			week += "һ";
		}
		else if (of.m_orderData[i]["date"] == "2")
		{
			week += "��";
		}
		else if (of.m_orderData[i]["date"] == "3")
		{
			week += "��";
		}
		else if (of.m_orderData[i]["date"] == "4")
		{
			week += "��";
		}
		else if (of.m_orderData[i]["date"] == "5")
		{
			week += "��";
		}
		cout << week << " ";
		cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
		cout << "ѧ��: " << of.m_orderData[i]["stuId"] << " ";
		cout << "����: " << of.m_orderData[i]["stuName"] << " ";
		cout << "�������: " << of.m_orderData[i]["roomId"] << " ";
		string status = "ԤԼ״̬: ";
		//1 �����	2 ��ԤԼ	-1 ԤԼʧ��		0 ȡ��ԤԼ
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "����С���";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�!";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��...";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	vector<int>v;
	int index = 0;
	cout << "����˵�ԤԼ��¼����: " << endl;

	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��";
			string week = "ԤԼ����: ��";
			if (of.m_orderData[i]["date"] == "1")
			{
				week += "һ";
			}
			else if (of.m_orderData[i]["date"] == "2")
			{
				week += "��";
			}
			else if (of.m_orderData[i]["date"] == "3")
			{
				week += "��";
			}
			else if (of.m_orderData[i]["date"] == "4")
			{
				week += "��";
			}
			else if (of.m_orderData[i]["date"] == "5")
			{
				week += "��";
			}
			cout << week << " ";
			cout << "ʱ���: " << (of.m_orderData[i]["interval"] == "1" ? "����" : "����") << " ";
			cout << "ѧ��: " << of.m_orderData[i]["stuId"] << " ";
			cout << "����: " << of.m_orderData[i]["stuName"] << " ";
			cout << "�������: " << of.m_orderData[i]["roomId"] << " ";
			cout << "ԤԼ״̬: ����С���" << endl;
		}
	}

	cout << "������Ҫ��˵�ԤԼ��¼��0������" << endl;
	int select = 0; //�����û�ѡ���ԤԼ��¼
	int ret = 0; //����ԤԼ�����¼

	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "��������˽��: " << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				while (true) 
				{
					cin >> ret;
					if (ret == 1)
					{
						//ͨ��
						of.m_orderData[v[select - 1]]["status"] = "2";
						of.updataOrder();
						cout << "������!" << endl;
						break;
					}
					else if (ret == 2)
					{
						//��ͨ��
						of.m_orderData[v[select - 1]]["status"] = "-1";
						of.updataOrder();
						cout << "������!" << endl;
						break;
					}
					cout << "������������������..." << endl;
				}
				break;
			}
		}
		cout << "������������������..." << endl;
	}
	system("pause");
	system("cls");
}