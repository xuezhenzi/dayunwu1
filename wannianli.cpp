#include<iostream>;
using namespace std;


//ʵ��һ���������������������������Ӧ�·ݵ�����
/* �������
 * firstWeek	һ�����ܼ�
 * days			������м���
 * sameDay		���������
**/
void Calendar(int firstWeek, int days, int sameDay);

int monthDays(int year, int month);//�ж�������·��м���

int calculationFirstWeek(int year, int month, int day);//�жϵ��µ�һ�������ڼ�

bool leapYear(int year);//�ж����������ǲ�������

bool leapYear(int year) 
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	return false;
}

int monthDays(int year, int month) 
{
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		return 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if (month == 2) 
	{
		if (leapYear(year))
			return 29;
		else
			return 28;
	}
}

int calculationFirstWeek(int year, int month, int day)
{
	int date = 4;
	int firstYear = 1970;
	int  firstMonth = 1;
	int  firstDay = 1;
	int total = 0;
 	for (int i = firstYear; i < year; i++)//����������֮����������
	{
		if (leapYear(i))
			total += 366;
		else
			total += 365;
	}
	for (int a = 1; a < month; a++)//�����·�֮����������
	{
		total += monthDays(year,a);
	}
	return (total + 4) % 7;

}

void Calendar(int firstWeek, int days, int sameDay)
{
	cout << "        ��      һ      ��      ��      ��      ��      ��" << endl;
	int num = firstWeek % 7;
	for (int b = 0; b < num * 8; b++) //ÿ��һ��ǰ�Ŀո�
	{
		cout << " "  ;
	}
	for (int c = 1; c <= days; c++) 
	{
		if (c == sameDay)
			cout << "\t" <<"*"<< c;
		else
			cout << "\t" << c;
		if ((num+c) % 7 == 0)
			cout<<" "<<endl;
	}
}

int main()
{
	cout << "*****************************************" << endl;
	cout << "*               �������˵�              *" << endl;
	cout << "*      1����ʼ               2������    *" << endl;
	cout << "*****************************************" << endl;
	cout << "��������Ҫ���еĲ�����";
	int a = 0;
	cin >> a;

	if (a == 1)
		{

		int year = 1970;
		int month = 1;
		int day = 1;
		while (1)//�ظ����������ղ���ӡ����
			{

			cout << "��ӭʹ����������������֮�����ÿո�ֿ�,��Ҫ�˳���������0 0 0" << endl;
			cout << "���������ڣ�";
				cin >> year;
				cin >> month;
				cin >> day;
				system("cls");//����
				cout << "*****************************************" << endl;
				cout << "*               �������˵�              *" << endl;
				cout << "*      1����ʼ               2������    *" << endl;
				cout << "*****************************************" << endl;
				cout << "��������Ҫ���еĲ�����" << endl;
					if (year == 0)
					break;
				Calendar(calculationFirstWeek(year, month, day), monthDays(year, month), day);
				cout << " " << endl;

			}
		}
	cout << "��ѡ���˳�����������ӭ�����´�ʹ��" << endl;
	system("pause");

	return 0;
}