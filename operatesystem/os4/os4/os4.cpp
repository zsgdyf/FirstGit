// os4.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>  
using namespace std;

struct Avail//���з�����
{
	int Number;//���з������
	int Length;//���з�������
	int BeginAddress;//���з�����ʼ��ַ
	bool Used;//�÷����Ƿ�ʹ��
};
struct Busy//����ռ�÷�����
{
	char Name;//������
	int Length;//���̳���
	int BeginAddress;//������ʼ��ַ
};

void Print(Avail *avail, Busy *busy,int n,int m)
{
	cout << "-----------------------�������ڴ�洢���" << endl;
	cout << "������\t" << "������ʼ��ַ\t" << "���̴�С" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << busy[i].Name << "\t" << busy[i].BeginAddress << "\t\t" << busy[i].Length << endl;
	}
	cout << "-----------------------�ڴ�ռ���ñ�" << endl;
	cout << "���\t" << "��ʼ��ַ\t" << "��������" << endl;
	for (int i = 0; i < m; i++)
	{
		cout << avail[i].Number << "\t" << avail[i].BeginAddress << "\t\t" << avail[i].Length << endl;
	}
}

void Recover(Avail *avail,Busy *busy,int m,int n)
{
	char name;
	int key;
	cout << "��������Ҫ���յĽ�����:";
	cin >> name;
	struct Avail *Navail = new struct Avail[m + 1];//�����µĿ��ñ�
	for (int i = 0; i < m; i++)
	{//û�л��յĽ����ڴ�ռ�ò���
		Navail[i + 1].Number = avail[i].Number + 1;
		Navail[i + 1].BeginAddress = avail[i].BeginAddress;
		Navail[i + 1].Length = avail[i].Length;
	}
	Navail[0].Number = 1;
	for (int j = 0; j < n; j++)
	{
		if (name == busy[j].Name)//�ҵ���Ҫ���յĽ���
		{
			key = j;
			cout << "���̻��ճɹ���" << endl;
			break;
		}
	}
	Navail[0].BeginAddress = busy[key].BeginAddress;//�޸Ŀ��ñ���ʼ��ַ
	Navail[0].Length = busy[key].Length;//�ͷŷ�������
	Print(Navail, busy, n, m + 1);//����µĿ��ñ�
}

void Distribute(Avail *avail,Busy *busy,int m,int n)
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			if (avail[i].Length >= busy[j].Length && !avail[i].Used)
			{//���������ҷ������ȴ��ڽ������賤��
				//�����ڴ棬���������з�������
				avail[i].Length = avail[i].Length - busy[j].Length;
				if (avail[i].Length != 0)
				{//������������з�����ʼ��ַ
					avail[i].BeginAddress = avail[i].BeginAddress + busy[j].Length;
					busy[j + 1].BeginAddress = busy[j].BeginAddress + busy[j].Length;
				}
				else
				{//�����������С���ڿ��з�����С������Ϊ��ʹ��
					avail[i].Used = true;
				}
				//����ɹ�
				cout << busy[j].Name << "���̷���ɹ�" << endl;
				break;
			}
			else
			{
				cout << busy[j].Name << "����ʧ�ܣ�" << endl;
			}
		}
	}
	//������б���ڴ�������
	Print(avail, busy, n, m);
}

int main()
{
	int m = 0, n = 0;
	int i = 0;
	struct Avail *avail = new struct Avail[m];
	struct Busy *busy = new struct Busy[n];
	ifstream in("C:\\Users\\sherlock\\Desktop\\os4.txt", ios::in);
	if (!in.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}
	in >> m;
	while (!in.eof() && i < m)
	{
		in >> avail[i].Number >> avail[i].BeginAddress >> avail[i].Length;
		i++;
	}
	in >> n;
	i = 0;
	while (!in.eof() && i < n)
	{
		in >> busy[i].Name >> busy[i].BeginAddress >> busy[i].Length;
		i++;
	}
	in.close();
	avail->Used = false;
	Print(avail, busy, n, m);
	Distribute(avail, busy, m, n);
	Recover(avail, busy, m, n);
	return 0;
}