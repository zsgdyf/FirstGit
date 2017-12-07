// os1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;

struct P
{
	char name[10];//������
	double ComeTime;//���̵���ʱ��
	double RunTime;//Ԥ������ʱ��
	int Priority;//�������ȼ�
	double BeginTime;//���̿�ʼʱ��
	double FinishTime;//�������ʱ��
	double RoundTime;//������תʱ��
	double LRoundTime;//���̴�Ȩ��תʱ��
};

void Print(int n,P *p)
{
	double roundTime = 0, lroundTime = 0;
	cout << "������\t" << "��ʼʱ��\t" << "���ʱ��\t" << "��תʱ��\t" << "��Ȩ��תʱ��\t" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << p[i].name <<"\t"
			<< p[i].BeginTime <<"\t\t"
			<< p[i].FinishTime <<"\t\t"
			<< p[i].RoundTime <<"\t\t"
			<< p[i].LRoundTime << endl;
		roundTime = roundTime + p[i].RoundTime;//����ƽ����תʱ��
		lroundTime = lroundTime + p[i].LRoundTime;//����ƽ����Ȩ��תʱ��
	}
	cout << "ƽ����תʱ��Ϊ��" << roundTime / n << endl;
	cout << "ƽ����Ȩ��תʱ��Ϊ��" << lroundTime / n << endl << endl;
}

void FCFS(P *p,int n)
{
	cout << "�����ȷ����㷨��" << endl;
	P temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].ComeTime > p[j].ComeTime)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	p[0].BeginTime = p[0].ComeTime;//��ʼʱ��
	for (int i = 1; i < n; i++)
	{
		if (p[i].ComeTime > p[i - 1].BeginTime + p[i - 1].RunTime)
			p[i].BeginTime = p[i].ComeTime;
		else p[i].BeginTime = p[i - 1].BeginTime + p[i - 1].RunTime;
	}
	for (int i = 0; i < n; i++)
	{
		p[i].FinishTime = p[i].BeginTime + p[i].RunTime;//���ʱ��
		p[i].RoundTime = p[i].FinishTime - p[i].ComeTime;//��תʱ��
		p[i].LRoundTime = p[i].RoundTime / p[i].RunTime;//��Ȩ��תʱ��
	}
	cout << "����˳��Ϊ��";
	for (int i = 0; i < n-1; i++)
	{
		cout << p[i].name << "->";
	}
	cout << p[n - 1].name << endl;

}

void Priority(P *p, int n)
{
	cout << "���ȼ�����" << endl;
	P temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].ComeTime > p[j].ComeTime)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	p[0].BeginTime = p[0].ComeTime;//��ʼʱ��
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].Priority > p[j].Priority)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (p[i].ComeTime > p[i - 1].BeginTime + p[i - 1].RunTime)
			p[i].BeginTime = p[i].ComeTime;
		else p[i].BeginTime = p[i - 1].BeginTime + p[i - 1].RunTime;
	}
	for (int i = 0; i < n; i++)
	{
		p[i].FinishTime = p[i].BeginTime + p[i].RunTime;//���ʱ��
		p[i].RoundTime = p[i].FinishTime - p[i].ComeTime;//��תʱ��
		p[i].LRoundTime = p[i].RoundTime / p[i].RunTime;//��Ȩ��תʱ��
	}
	cout << "����˳��Ϊ��";
	for (int i = 0; i < n - 1; i++)
	{
		cout << p[i].name << "->";
	}
	cout << p[n - 1].name << endl;

}

void ShortFirst(P *p, int n)
{
	cout << "����ҵ���ȷ���" << endl;
	P temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].ComeTime > p[j].ComeTime)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	p[0].BeginTime = p[0].ComeTime;//��ʼʱ��
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (p[i].RunTime > p[j].RunTime)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (p[i].ComeTime > p[i - 1].BeginTime + p[i - 1].RunTime)
			p[i].BeginTime = p[i].ComeTime;
		else p[i].BeginTime = p[i - 1].BeginTime + p[i - 1].RunTime;
	}
	for (int i = 0; i < n; i++)
	{
		p[i].FinishTime = p[i].BeginTime + p[i].RunTime;//���ʱ��
		p[i].RoundTime = p[i].FinishTime - p[i].ComeTime;//��תʱ��
		p[i].LRoundTime = p[i].RoundTime / p[i].RunTime;//��Ȩ��תʱ��
	}
	cout << "����˳��Ϊ��";
	for (int i = 0; i < n - 1; i++)
	{
		cout << p[i].name << "->";
	}
	cout << p[n - 1].name << endl;
}

int main()
{
	int n, i = 0;
	cout << "��������̸���" << endl;
	cin >> n;
	struct P *p = new struct P[n];//��̬�ṹ������
//���ļ�����
	ifstream in("C:\\Users\\sherlock\\Desktop\\os1.txt", ios::in);
	if (!in.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}
	while (!in.eof() && i < n)
	{
//�������������������ʱ�䣬Ԥ��ִ��ʱ�䣬���ȼ�
		in >> p[i].name >> p[i].ComeTime >> p[i].RunTime >> p[i].Priority;
		i++;
	}
	in.close();
//�ֶ�����
/*	for (i = 0; i < n; i++)
	{
		cout << "�����������" << i + 1 << "�����̵���Ϣ�����������ύʱ�䣬Ԥ��ִ��ʱ�䣬���ȼ���" << endl;
		cin >> p[i].name >> p[i].ComeTime >> p[i].RunTime>>p[i].Priority;
	}
	/*
	cout << "��ѡ��һ�ֵ����㷨��\n 1.�����ȷ����㷨\n 2.���ȼ���\n 3.����ҵ���ȷ�" << endl;
	cin >> a;
	switch (a)
		case 1:
		case 2:
		case 3:
	*/
	FCFS(p, n);
	Print(n, p);
	Priority(p, n);
	Print(n, p);
	ShortFirst(p, n);
	Print(n, p);
    return 0;
}
