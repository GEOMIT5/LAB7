#include <iostream>
#include <string>
#include <Windows.h>
#include <fstream>
#include <conio.h>
#include <iomanip>

using namespace std;

int chooseFillArray();
int chooseMenu();
int writeNumbers();

template <class T> class Matrix
{
private:
	T** a;// ������ ��������� �������
	T n;	// ������ �������
	T m;
public:
	// ������������ 
	Matrix()
	{
		n = 0;
		m = 0;
		a = NULL;
	};
	Matrix(T n1, T m1)
	{
		n = n1; m = m1;
		a = new double* [m];
		for (int i = 0; i < m; i++)
			a[i] = new double[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++) 
				a[i][j] = 0;

	}
	Matrix(const Matrix<T>& ob)
	{
		n = ob.n;
		m = ob.m; if (ob.a == NULL)
		{
			a = NULL;
			return;
		}
		a = new double* [m];
		for (int i = 0; i < m; i++)
			a[i] = new double[n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = ob.a[i][j];

	}

	void operator + (Matrix<T>& ob)
	{
		if (n == ob.n && m == ob.m)
		{
			Matrix<T> temp(n, m);
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					temp.a[i][j] = a[i][j] + ob.a[i][j];

			temp.show();

		}
		else
			return;

		system("pause");
	}

	void operator < (Matrix<T>& ob)
	{
		if (n == ob.n && m == ob.m)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
				{
					if (a[i][j] > ob.a[i][j])
					{
						infNET();
						return;
					}

				}
			infDA();
		}


		else
			return;
			
		system("pause");
	}
	
	void show()
	{

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << a[i][j] << " ";
			cout << endl;
		}
		
	}

	void max_el()
	{
		int max = a[0][0];
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (max < a[i][j]) {
					max = a[i][j];
				}
			}
		}
	
		cout <<"������������ ������� �������"<< max << endl;
	
	}

	void sredn()
	{
		double sr=0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				
				sum += a[i][j];
				
			}
		}
		sr = sum / (n * m);
		cout << "������� �������� ��������� ��������" << sr<<endl;
		system("pause");
	}

	void fillArray() {
		int choose = chooseFillArray();
		if (choose == 0) {

			cout << "������� ����� ������� ���������: ";
			int l = 0, r = 0;
			cin >> l;
			cout << "������� ������ ������� ���������: ";
			cin >> r;
			srand(time(NULL));
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					a[i][j] = rand() % (r - l + 1) + l;
		}
		else {
			cout << "������� �������� �������: " << endl;
			for (int i = 0; i < n; i++) {
				cout << i + 1 << " - ������ �� " << m << " ��������: ";
				for (int j = 0; j < m; j++)
					cin >> a[i][j];
			}
		}
	}
	void infDA()
	{
		cout << "��" << endl;
	}
	void infNET()
	{
		cout << "���" << endl;
	}
};


int main()
{
	setlocale(0, "rus");
	int n, m, k, p;
	cout << "������� ����������� ������� ";
	cin >> n;
	cout << "������� ������ ����������� ������� ";
	cin >> m;
	k = n;
	p = m;
	Matrix<double> ob(n,m);
	while (true) {
		int choose = chooseMenu();
		if (choose == 0) {
			
			
			ob.fillArray();
		}
		else
			if (choose == 1) {
				cout << "�������:" << endl;
				
				ob.show();
				system("pause");
				
			}
			else
				if (choose == 2) {
					ob.sredn();
				}
				else
					if (choose == 3) {
						ob.max_el();
						system("pause");
						
					}
					else
						if (choose == 4) {
							
							cout << "�������� ������" << endl;
							Matrix<double> ob1(k, p);
							ob1.fillArray();
							ob1.show();
							system("pause");
							ob + ob1;
								system("pause");
							
						}
						else
							if (choose == 5) {

								Matrix<double> ob1(k, p);
								ob1.fillArray();
								ob1.show();
								system("pause");
								cout << "��������� ������� �������� ������ ������� � ���������� ������" << endl;
								
								ob < ob1;

							}
					else
						break;



	}
	
		
	
		


}

int chooseFillArray() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "����������� ����� � ���� �������� ��� ��������� �������: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { cout << " -> ����� ��������� �����" << endl; }
		else { cout << " ����� ��������� �����" << endl; }

		if (choose_menu == 1) { cout << " -> � ����������" << endl; }
		else { cout << " � ����������" << endl; }

		keyboard_button = _getch();
		if (keyboard_button == 224) {
			keyboard_button = _getch();
			if (keyboard_button == 72) choose_menu--;
			if (keyboard_button == 80) choose_menu++;
		}
		if (keyboard_button == 13) { return choose_menu; }

	}
}
int chooseMenu() {
	int choose_menu = 0, key = 0;
	
	while (true) {
		choose_menu = (choose_menu + 7) % 7;

		if (choose_menu == 0) cout << "-> ��������� �������" << endl;
		else cout << " ��������� �������" << endl;

		if (choose_menu == 1) cout << "-> �������� �������" << endl;
		else cout << " �������� �������" << endl;

		if (choose_menu == 2) cout << " -> ����� ������� �������� ��������� �������" << endl;
		else cout << " ����� ������� �������� ��������� �������" << endl;

		if (choose_menu == 3) cout << " -> ����� ������������ ������� �������" << endl;
		else cout << " ����� ������������ ������� �������" << endl;

		if (choose_menu == 4) cout << " -> ������� ��� �������" << endl;
		else cout << " ������� ��� �������" << endl;

		if (choose_menu == 5) cout << " -> ������ ������� ������ ������� ������ �������� ������" << endl;
		else cout << " ������ ������� ������ ������� ������ �������� ������" << endl;

		if (choose_menu == 6) cout << " -> �����" << endl;
		else cout << " �����" << endl;

		key = _getch();
		if (key == 224) {
			key = _getch();
			if (key == 72) choose_menu--;
			if (key == 80) choose_menu++;
		}
		if (key == 13) {
			return choose_menu;
		}
		
	}
}
int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0 && numbers != "-") break;
				else
					if ((key >= '0' && key <= '9') || (key == '-' && numbers.length() == 0)) {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}
