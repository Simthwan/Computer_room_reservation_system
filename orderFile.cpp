#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date; //����
	string interval; //ʱ���
	string stuId; //ѧ��ѧ��
	string stuName; //ѧ������
	string roomId; //�������
	string status; //ԤԼ״̬

	this->m_Size = 0; //��¼����

	while (ifs >> date && ifs >> interval && ifs
		>> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string>m;

		//date:1(ʾ��)
		this->interceptdata(date,m);

		//��ȡʱ��� interval:2(ʾ��)
		this->interceptdata(interval,m);

		//��ȡѧ�� stuId:1(ʾ��)
		this->interceptdata(stuId,m);

		//��ȡ���� stuName:����(ʾ��)
		this->interceptdata(stuName,m);

		//��ȡ������ roomId:3(ʾ��)
		this->interceptdata(roomId,m);

		//��ȡ����״̬ status:1(ʾ��)
		this->interceptdata(status,m);

		//��Сmap�������뵽���map������
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//��������map����
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "����Ϊ: " << it->first << " value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key=" << mit->first << " value=" << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}

//��ȡ�ļ���Ϣ��������map������
void OrderFile::interceptdata(string &item,map<string,string>&m)
{
	string key;
	string value;

	int pos = item.find(":");
	if (pos != -1)
	{
		key = item.substr(0, pos);
		value = item.substr(pos + 1, item.size() - pos - 1); //size=6,pos=4,size-pos-1=1

		m.insert(pair<string, string>(key, value));
	}
}

//����ԤԼ��¼
void OrderFile::updataOrder()
{
	if (this->m_Size == 0)
	{
		return; //ԤԼ��¼0����ֱ��return
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //�����д
	for (int i = 0; i < this->m_Size; i++)
	{
		ofs << "date:" << this->m_orderData[i]["date"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuId:" << this->m_orderData[i]["stuId"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomId:" << this->m_orderData[i]["roomId"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}