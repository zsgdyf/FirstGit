// os3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include <algorithm>
#include<fstream>
using namespace std;

void Fcfs(int n,int begin,int *a)
{
	cout << endl << "�����ȷ���FCFS���㷨��" << endl;
	cout << "��ͷ���η��ʵĴŵ�������Ϊ��";
	cout << begin << "->";
	for (int i = 0; i < n-1; i++)//��˳������ŵ�������
	{
		cout << a[i] << "->";
	}
	cout << a[n - 1] << endl;
	int sum = abs(begin - a[0]);
	for (int i = 0; i < n-1; i++)
	{
		sum = sum + abs(a[i] - a[i + 1]);
	}
	cout << "��ͷ�ƶ����ܴŵ���Ϊ��" << sum << endl;
}

void Sstf(int n, int begin, int *a)
{
	cout << endl << "���Ѱ��ʱ�����ȣ�SSTF���㷨��" << endl;
	cout << begin;
	int sum = 0;
	int *visited = new int[n];
	int *next = new int[n];//�洢��һ���ŵ��ţ��������
	next[0] = begin;
	for (int i = 0; i < n; i++)//���÷���λ
	{
		visited[i] = 0;//0��ʾδ������
	}
	for (int j = 0; j < n; j++)
	{
		int min = 9999, key = 0;
		for (int i = 0; i < n; i++)//�ҳ�ÿ�ε����Ѱ��ʱ��
		{
			if (!visited[i] && abs(a[i] - begin) < min)
			{
				min = abs(a[i] - begin);
				key = i;
			}
		}
		cout << "->" << a[key];
		begin = a[key];
		next[j + 1] = a[key];
		visited[key] = 1;//ÿ�ν����ʹ��Ĵŵ�����Ϊ1
	}
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		sum = sum + abs(next[i] - next[i + 1]);
	}
	cout << "��ͷ�ƶ����ܴŵ���Ϊ��" << sum << endl;
}

void ScanL(int n, int begin, int *a)
{
	cout << endl << "�����㷨����ͷ��ʼ�ƶ�����Ϊ�󣩣�" << endl;
	int key;
	int *s = new int[n + 1];
	for (int i = 0; i < n; i++)//���ŵ������к͵�ǰ��ͷλ��һ�����һ��������
	{
		s[i] = a[i];
	}
	s[n] = begin;
	sort(s, s + n + 1);//��ǰ��ͷλ�úʹŵ���������������
	for (int i = 0; i < n + 1; i++)//�ҵ���ǰ��ͷ����λ��
	{
		if (s[i] == begin)
		{
			key = i;
		}
	}
	cout << "��ͷ���η��ʵĴŵ�������Ϊ��";
	for (int i = key; i >= 0; i--)//�������ƶ�
	{
		cout << s[i] << "->";
	}
	for (int i = key + 1; i < n; i++)//�����ƶ�
	{
		cout << s[i] << "->";
	}
	cout << s[n] << endl;
	int sum = 0;
	sum = s[key] - s[0] + s[n] - s[0];//�����ܴŵ���
	cout << "��ͷ�ƶ����ܴŵ���Ϊ��" << sum << endl;
}

void ScanR(int n,int begin,int *a)
{
	cout << endl << "�����㷨����ͷ��ʼ�ƶ�����Ϊ�ң���" << endl;
	int key;
	int *s = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		s[i] = a[i];
	}
	s[n] = begin;
	sort(s, s + n + 1);
	for (int i = 0; i < n + 1; i++)
	{
		if (s[i] == begin)
		{
			key = i;
		}
	}
	cout << "��ͷ���η��ʵĴŵ�������Ϊ��";
	for (int i = key; i <= n; i++)
	{
		cout << s[i] << "->";
	}
	for (int i = key - 1; i > 0; i--)
	{
		cout << s[i] << "->";
	}
	cout << s[0] << endl;
	int sum = 0;
	sum = s[n] - s[key] + s[n] - s[0];
	cout << "��ͷ�ƶ����ܴŵ���Ϊ��" << sum << endl;
}


int main()
{
	int begin, n, i = 0;
	cout << "������Ҫ���ʵĴŵ���Ŀ��";
	cin >> n;
//�ļ�����
	int *a = new int[n];//��̬����
	ifstream in;
	in.open("C:\\Users\\sherlock\\Desktop\\os3.txt", ios::in);
	if (!in.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}
	in >> begin;//��ǰ��ͷλ��
	while (!in.eof() && i < n)
	{
		in >> a[i];//���ŵ������д�������
		i++;
	}
	in.close();
//�ֶ�����
/*	cout << "�����뵱ǰ��ͷ��λ�ã�";
	cin >> begin;
	cout << "�ŵ������������У�";
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
*/
	Fcfs(n, begin, a);
	ScanL(n, begin, a);
	ScanR(n, begin, a);
	Sstf(n, begin, a);
    return 0;
}

