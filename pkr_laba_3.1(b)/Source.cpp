#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;

enum Specialty { ��, ��, ��, ��, �� };
string strSpecialty[] = { "��","��","��","��","��" };
struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kurs;
	short unsigned physic;
	short unsigned math;
	union
	{
		short unsigned programing;
		short unsigned metods;
		short unsigned pedagogika;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void BestMedium(Student* s, const int N);
double Percent(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ ������� ��������: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	BestMedium(s, N);

	double perc = Percent(s, N);
	cout << "������� ��������, �� ������� �� ������: " << perc << "%" << endl;

	delete[] s;

	return 0;
}

void Create(Student* s, const int N)
{
	int kurs, specialty{};
	for (int i = 0; i < N; i++)
	{
		cout << "������� " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "�������: "; getline(cin, s[i].prizv);
		cout << "����: "; cin >> s[i].kurs;
		cout << "������������ (0 - ��, 1 - ��, 2 - ��, 3 - ��, 4 - ��):  "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  ������ � ������: "; cin >> s[i].physic;
		cout << "  ������ � ����������: "; cin >> s[i].math;
	
		switch (s[i].specialty)
		{
		case ��:
			cout << "������ � ������������� "; cin >> s[i].programing;
			break;
		case ��:
			cout << "������ � ��������� "; cin >> s[i].pedagogika;
			break;
		case ��:
			cout << "������ � ��������� "; cin >> s[i].pedagogika;
			break;
		case ��:
			cout << "������ � ��������� ������ "; cin >> s[i].metods;
			break;
		case ��:
			cout << "������ � ��������� "; cin >> s[i].pedagogika;
			break;
		}
	}
}

void Print(Student* s, const int N)
{
	cout << "========================================================================================================================"
		<< endl;
	cout << "| � | ������� | ���� | ������������ | Գ���� | ���������� | �������������| ������� ������|���������|"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------";
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " "
			<< "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(3) << right << s[i].kurs << " "
			<< "| " << setw(8) << right << strSpecialty[s[i].specialty] << "    "
			<< "| " << setw(4) << right << s[i].physic << "  "
			<< "| " << setw(6) << right << s[i].math << "  ";
		switch (s[i].specialty)
		{
		case 0:
			cout << "| " << setw(7) << right << s[i].programing << "     |" << setw(18) << "|" << setw(13) << "|" << endl;
			break;
		case 3:
			cout << "| " << setw(15) << "|" << setw(10) << right << s[i].metods << "    |" << setw(13) << "|" << endl;
			break;
		case 1:
		case 2:
		case 4:
			cout << "| " << setw(15) << "|" << setw(18) << "|" << right << setw(7) << s[i].pedagogika << "    |" << endl;
			break;
		}
		cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	}
	cout << "==================================================================================================================" << endl;
}
void BestMedium(Student* s, const int N)
{
	string prizv1;
	double best = 0;
	double tmp;
	for (int i = 0; i < N; i++)
	{
		tmp = (s[i].physic + s[i].math + s[i].pedagogika + s[i].metods + s[i].programing) / 3;

		if (tmp > best)
		{
			prizv1 = s[i].prizv;
			best = tmp;
		}
	}
	cout << "������� ��������, � ����� ��������� ������� ���: " << prizv1 << endl;
}

double Percent(Student* s, const int N)
{
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		n++;
		if (s[i].physic == 5)
			if (s[i].math == 5)
				if (s[i].pedagogika == 5)
				{
					k++;

				}
	}
	return 100.0 * k / n;
}