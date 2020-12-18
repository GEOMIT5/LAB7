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
	T** a;// массив элементов матрицы
	T n;	// размер матрицы
	T m;
public:
	// конструкторы 
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
	
		cout <<"Максимальный элемент матрицы"<< max << endl;
	
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
		cout << "Среднее значение элементов мастрицы" << sr<<endl;
		system("pause");
	}

	void fillArray() {
		int choose = chooseFillArray();
		if (choose == 0) {

			cout << "Введите левую границу диапозона: ";
			int l = 0, r = 0;
			cin >> l;
			cout << "Введите правую границу диапозона: ";
			cin >> r;
			srand(time(NULL));
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					a[i][j] = rand() % (r - l + 1) + l;
		}
		else {
			cout << "Введите элементы массива: " << endl;
			for (int i = 0; i < n; i++) {
				cout << i + 1 << " - строка из " << m << " символов: ";
				for (int j = 0; j < m; j++)
					cin >> a[i][j];
			}
		}
	}
	void infDA()
	{
		cout << "Да" << endl;
	}
	void infNET()
	{
		cout << "Нет" << endl;
	}
};


int main()
{
	setlocale(0, "rus");
	int n, m, k, p;
	cout << "Введите размерность матрицы ";
	cin >> n;
	cout << "Введите вторую размерность матрицы ";
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
				cout << "Матрица:" << endl;
				
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
							
							cout << "Сложение матриц" << endl;
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
								cout << "Сравнение каждого элемента первой матрицы с элементами второй" << endl;
								
								ob < ob1;

							}
					else
						break;



	}
	
		
	
		


}

int chooseFillArray() {
	int choose_menu = 0, keyboard_button = 0;
	while (true) {
		cout << "Стрелочками ВВЕРХ и ВНИЗ выберите как заполнить матрицу: " << endl;
		choose_menu = (choose_menu + 2) % 2;

		if (choose_menu == 0) { cout << " -> Через случайные числа" << endl; }
		else { cout << " Через случайные числа" << endl; }

		if (choose_menu == 1) { cout << " -> С клавиатуры" << endl; }
		else { cout << " С клавиатуры" << endl; }

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

		if (choose_menu == 0) cout << "-> Заполнить матрицу" << endl;
		else cout << " Заполнить матрицу" << endl;

		if (choose_menu == 1) cout << "-> Показать матрицу" << endl;
		else cout << " Показать матрицу" << endl;

		if (choose_menu == 2) cout << " -> Найти среднее значение элементов матрицы" << endl;
		else cout << " Найти среднее значение элементов матрицы" << endl;

		if (choose_menu == 3) cout << " -> Найти максимальный элемент матрицы" << endl;
		else cout << " Найти максимальный элемент матрицы" << endl;

		if (choose_menu == 4) cout << " -> Сложить две матрицы" << endl;
		else cout << " Сложить две матрицы" << endl;

		if (choose_menu == 5) cout << " -> Каждый элемент первой матрицы меньше элемента второй" << endl;
		else cout << " Каждый элемент первой матрицы меньше элемента второй" << endl;

		if (choose_menu == 6) cout << " -> Выход" << endl;
		else cout << " Выход" << endl;

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
