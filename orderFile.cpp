#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date; //日期
	string interval; //时间段
	string stuId; //学生学号
	string stuName; //学生姓名
	string roomId; //机房编号
	string status; //预约状态

	this->m_Size = 0; //记录条数

	while (ifs >> date && ifs >> interval && ifs
		>> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string>m;

		//date:1(示例)
		this->interceptdata(date,m);

		//截取时间段 interval:2(示例)
		this->interceptdata(interval,m);

		//截取学号 stuId:1(示例)
		this->interceptdata(stuId,m);

		//截取姓名 stuName:张三(示例)
		this->interceptdata(stuName,m);

		//截取机房号 roomId:3(示例)
		this->interceptdata(roomId,m);

		//截取机房状态 status:1(示例)
		this->interceptdata(status,m);

		//将小map容器放入到大的map容器中
		this->m_orderData.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}
	ifs.close();

	//测试最大的map容器
	//for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	//{
	//	cout << "条数为: " << it->first << " value=" << endl;
	//	for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
	//	{
	//		cout << "key=" << mit->first << " value=" << mit->second << " ";
	//	}
	//	cout << endl;
	//}
}

//截取文件信息，并存入map容器中
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

//更新预约记录
void OrderFile::updataOrder()
{
	if (this->m_Size == 0)
	{
		return; //预约记录0条，直接return
	}

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc); //清空重写
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