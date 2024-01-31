#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	const int K_Max = 20;//
	int n;
	int K[K_Max];
	bool sort = false;
	short punkt;
	int sum_T = 0;
	int mx = INT_MIN;//
	int count1 = 0;
	int count2 = 0;
	int sum_1 = 0;
	do {
		cout << endl;
		cout << "Номер пункта: ";
		cin >> punkt;
		switch (punkt) {

			// Сортировка элементов последовательности

		case 1://
			cout << "Введите кол-во чисел последовательности: ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cin >> K[i];
			}
			cout << endl;
			// Проверка условия
			for (int i = 0; i < n; i++)
			{
				int digits = K[i];
				sum_1 = 0;
				while (digits > 0)
				{
					sum_1 += digits % 10;
					digits /= 10;

					if (sum_1 > 25)
					{
						count1 ++;
					}
				}

			}



			if (count1 >= 2) // Сортировка по возрастанию, учитывая условия
			{
				for (int i = 0; i < n - 1; i++)
				{
					for (int j = i + 1; j < n; j++)
					{
						if (K[i] > K[j])
						{
							int tmp = K[i];
							K[i] = K[j];
							K[j] = tmp;
						}
					}
				}
				for (int i = 0; i < n; i++) {
					cout << K[i] << " ";
				}
				cout << endl;
			}
			else
			{
				cout << "Sum less than 25! Try again!" << endl;
			}
			break;

			//Работа с матрицей
		case 2:
			long T[10][10];

			int M, N;
			cout << "Введите кол-во строк и столбцов соответственно: ";
			cin >> M >> N;
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cin >> T[i][j];
				}
			}
			cout << endl;
			cout << endl;
			for (int i = 0; i < M; i++) // Поиск максимальной суммы элементов каждой строки матрицы
			{
				for (int j = 0; j < N; j++)
				{
					sum_T += T[i][j];
				}
				if (mx < sum_T)
				{
					mx = sum_T;
					count2 = i;
				}
				sum_T = 0;

			}
			// Замена элементов строки на 0
			for (int j = 0; j < N; j++)
			{
				T[count2][j] = 0;
			}
			// Вывод
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					cout << T[i][j] << " ";
				}
				cout << endl;
			}
			cout << mx << endl;
			mx = 0;
			break;
		default:
			cout << "The end." << endl;
			break;
		}
	} while (punkt <= 2 and punkt > 0);

}