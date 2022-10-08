#include<iostream>;
using namespace std;


//实现一个万年历，输入年月日能输出对应月份的日历
/* 输出日历
 * firstWeek	一号是周几
 * days			这个月有几天
 * sameDay		输入的那天
**/
void Calendar(int firstWeek, int days, int sameDay);

int monthDays(int year, int month);//判断输入的月份有几天

int calculationFirstWeek(int year, int month, int day);//判断当月的一号是星期几

bool leapYear(int year);//判断输入的年份是不是闰年

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
 	for (int i = firstYear; i < year; i++)//计算年与年之间间隔的天数
	{
		if (leapYear(i))
			total += 366;
		else
			total += 365;
	}
	for (int a = 1; a < month; a++)//计算月份之间间隔的天数
	{
		total += monthDays(year,a);
	}
	return (total + 4) % 7;

}

void Calendar(int firstWeek, int days, int sameDay)
{
	cout << "        日      一      二      三      四      五      六" << endl;
	int num = firstWeek % 7;
	for (int b = 0; b < num * 8; b++) //每月一号前的空格
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
	cout << "*               万年历菜单              *" << endl;
	cout << "*      1、开始               2、结束    *" << endl;
	cout << "*****************************************" << endl;
	cout << "请输入你要进行的操作：";
	int a = 0;
	cin >> a;

	if (a == 1)
		{

		int year = 1970;
		int month = 1;
		int day = 1;
		while (1)//重复输入年月日并打印日历
			{

			cout << "欢迎使用万年历，年月日之间请用空格分开,若要退出，请输入0 0 0" << endl;
			cout << "请输入日期：";
				cin >> year;
				cin >> month;
				cin >> day;
				system("cls");//清屏
				cout << "*****************************************" << endl;
				cout << "*               万年历菜单              *" << endl;
				cout << "*      1、开始               2、结束    *" << endl;
				cout << "*****************************************" << endl;
				cout << "请输入你要进行的操作：" << endl;
					if (year == 0)
					break;
				Calendar(calculationFirstWeek(year, month, day), monthDays(year, month), day);
				cout << " " << endl;

			}
		}
	cout << "您选择退出万年历，欢迎您的下次使用" << endl;
	system("pause");

	return 0;
}