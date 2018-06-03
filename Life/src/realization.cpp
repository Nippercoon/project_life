#include "realization.h"

int countNeighbors(Cell** cells, int i, int j) // Подсчитывает количество соседей у заданной клетки
{
	int amount = 0;
	if(i == 0 && j == 0)
	{
		if(cells[i+1][j].life) amount++;
		if(cells[i+1][j+1].life) amount++;
		if(cells[i][j+1].life) amount++;
	}
	else if(i == 0 && j == n - 1)
	{
		if(cells[i+1][j].life) amount++;
		if(cells[i+1][j-1].life) amount++;
		if(cells[i][j-1].life) amount++;
	}
	else if(i == m - 1 && j == 0)
	{
		if(cells[i][j+1].life) amount++;
		if(cells[i-1][j+1].life) amount++;
		if(cells[i-1][j].life) amount++;
	}
	else if(i == m - 1 && j == n - 1)
	{
		if(cells[i-1][j].life) amount++;
		if(cells[i-1][j-1].life) amount++;
		if(cells[i][j-1].life) amount++;
	}
	else if(i == 0 && j > 0 && j < n - 1)
	{
		if(cells[i+1][j-1].life) amount++;
		if(cells[i+1][j].life) amount++;
		if(cells[i+1][j+1].life) amount++;
		if(cells[i][j-1].life) amount++;
		if(cells[i][j+1].life) amount++;
	}
	else if(i == m - 1 && j > 0 && j < n - 1)
	{
		if(cells[i-1][j+1].life) amount++;
		if(cells[i-1][j].life) amount++;
		if(cells[i-1][j-1].life) amount++;
		if(cells[i][j+1].life) amount++;
		if(cells[i][j-1].life) amount++;
	}
	else if(i > 0 && i < m - 1 && j == 0)
	{
		if(cells[i+1][j+1].life) amount++;
		if(cells[i][j+1].life) amount++;
		if(cells[i-1][j+1].life) amount++;
		if(cells[i+1][j].life) amount++;
		if(cells[i-1][j].life) amount++;
	}
	else if(i > 0 && i < m - 1 && j == n - 1)
	{
		if(cells[i+1][j-1].life) amount++;
		if(cells[i][j-1].life) amount++;
		if(cells[i-1][j-1].life) amount++;
		if(cells[i+1][j].life) amount++;
		if(cells[i-1][j].life) amount++;
	}
	else
	{
		if(cells[i+1][j+1].life) amount++;
		if(cells[i+1][j].life) amount++;
		if(cells[i+1][j-1].life) amount++;
		if(cells[i][j+1].life) amount++;
		if(cells[i][j-1].life) amount++;
		if(cells[i-1][j+1].life) amount++;
		if(cells[i-1][j].life) amount++;
		if(cells[i-1][j-1].life) amount++;
	}
	return amount;
}

void setNextGeneration(Cell** cells) // Устанавливает настройки следующего поколения
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j].next)
			{
				cells[i][j].life = true;
			}
			else
			{
				cells[i][j].life = false;
			}
			cells[i][j].next = false;
		}
	}
}
// Генерирует следующее поколение, посчитав количество соседей у каждой клетки и определив её состояние в след. поколении
void generateNextGeneration(Cell** cells)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int temp = countNeighbors(cells, i, j);
			if (cells[i][j].life)
			{
				if (temp < 2 || temp > 3)
				{
					cells[i][j].next = false;
				}
				else
				{
					cells[i][j].next = true;
				}
			}
			else
			{
				if (temp == 3)
				{
					cells[i][j].next = true;
				}
			}
		}
	}
}

void printGeneration(Cell** cells) // Печатаем поколение # - живая клетка, . - мертвая
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j].life)
			{
				cout << alive;
			}
			else
			{
				cout << dead;
			}
		}
		cout << "\n";
	}
	cout << "\n\n\n";
}

void setDefaultSettings(Cell** cells) // Возможность выбора варианта начальной установки
{
	int k;
	cout << "Введите число, для настройки определенной конфигурации:\n1 - Улей\n2 - Каравай\n3 - Пруд\n4 - Ящик\n5 - Блок\n6 - Змея\n"
			"7 - Баржа\n8 - Лодка\n9 - Корабль\n10 - Длинная баржа\n11 - Длинная лодка\n12 - Длинный корабль\n13 - Навигационные огни\n"
			"14 - Планер\n15 - Восьмёрка\n";
	cin >> k;
	switch(k)
	{
	case 1:
		cells[4][3].life = true;
		cells[5][3].life = true;
		cells[6][4].life = true;
		cells[3][4].life = true;
		cells[4][5].life = true;
		cells[5][5].life = true;
		break;
	case 2:
		cells[4][3].life = true;
		cells[3][4].life = true;
		cells[3][5].life = true;
		cells[4][6].life = true;
		cells[5][6].life = true;
		cells[5][4].life = true;
		cells[6][5].life = true;
		break;
	case 3:
		cells[4][3].life = true;
		cells[5][3].life = true;
		cells[4][6].life = true;
		cells[5][6].life = true;
		cells[3][4].life = true;
		cells[3][5].life = true;
		cells[6][4].life = true;
		cells[6][5].life = true;
		break;
	case 4:
		cells[4][3].life = true;
		cells[4][5].life = true;
		cells[3][4].life = true;
		cells[5][4].life = true;
		break;
	case 5:
		cells[4][3].life = true;
		cells[4][4].life = true;
		cells[3][3].life = true;
		cells[3][4].life = true;
		break;
	case 6:
		cells[4][3].life = true;
		cells[3][3].life = true;
		cells[4][4].life = true;
		cells[3][5].life = true;
		cells[4][6].life = true;
		cells[3][6].life = true;
		break;
	case 7:
		cells[4][3].life = true;
		cells[3][4].life = true;
		cells[5][4].life = true;
		cells[4][5].life = true;
		cells[6][5].life = true;
		cells[5][6].life = true;
		break;
	case 8:
		cells[4][3].life = true;
		cells[3][4].life = true;
		cells[4][5].life = true;
		cells[5][4].life = true;
		cells[5][5].life = true;
		break;
	case 9:
		cells[4][3].life = true;
		cells[3][3].life = true;
		cells[3][4].life = true;
		cells[4][5].life = true;
		cells[5][4].life = true;
		cells[5][5].life = true;
		break;
	case 10:
		cells[4][3].life = true;
		cells[3][4].life = true;
		cells[5][4].life = true;
		cells[4][5].life = true;
		cells[6][5].life = true;
		cells[5][6].life = true;
		cells[7][6].life = true;
		cells[6][7].life = true;
		break;
	case 11:
		cells[4][3].life = true;
		cells[3][4].life = true;
		cells[5][4].life = true;
		cells[4][5].life = true;
		cells[6][5].life = true;
		cells[6][6].life = true;
		cells[5][6].life = true;
		break;
	case 12:
		cells[4][3].life = true;
		cells[3][3].life = true;
		cells[3][4].life = true;
		cells[4][5].life = true;
		cells[5][4].life = true;
		cells[5][6].life = true;
		cells[6][5].life = true;
		cells[6][6].life = true;
		break;
	case 13:
		cells[4][4].life = true;
		cells[4][3].life = true;
		cells[4][5].life = true;
		cells[3][4].life = true;
		break;
	case 14:
		cells[2][0].life = true;
		cells[2][1].life = true;
		cells[2][2].life = true;
		cells[1][2].life = true;
		cells[0][1].life = true;
		break;
	case 15:
		cells[3][3].life = true;
		cells[3][2].life = true;
		cells[3][4].life = true;
		cells[2][2].life = true;
		cells[2][3].life = true;
		cells[2][4].life = true;
		cells[4][2].life = true;
		cells[4][3].life = true;
		cells[4][4].life = true;
		cells[6][6].life = true;
		cells[6][5].life = true;
		cells[6][7].life = true;
		cells[5][5].life = true;
		cells[5][6].life = true;
		cells[5][7].life = true;
		cells[7][5].life = true;
		cells[7][6].life = true;
		cells[7][7].life = true;
		break;
	default:
		cout << "Что-то пошло не так. Вероятно вы ввели число не от 1 до 15. Попробуйте снова";
		exit(1);
	}
}

bool checkStable(Cell** cells)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j].life != cells[i][j].next) return false;
		}
	}
	return true;
}

bool checkDead(Cell** cells)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cells[i][j].life) return false;
		}
	}
	return true;
}

void readFile(string s, Cell** cells) // Условимся, что в файле 10 строк и 10 стобцов (т.е. по значениям констант)
{
	ifstream file(s);
	if (file.is_open())
	{
		string line;
		for (int i = 0; i < m; i++)
		{
			getline(file, line);
			for (int j = 0; j < n; j++)
			{
				if (line[j] == '#') cells[i][j].life = true;
				else cells[i][j].life = false;
				cells[i][j].next = false;
			}
		}
	}
	file.close();
}

void scen1(string s, Cell** cells)
{
	readFile(s, cells);
	printGeneration(cells);
	cout << "Сколько поколений вывести?" << endl;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		generateNextGeneration(cells);
		if (checkStable(cells))
		{
			cout << "Композиция стабильна" << endl;
			break;
		}
		setNextGeneration(cells); // Устанавливаем нужные состояния и возвращаем next к стандартному значению
		printGeneration(cells);
		if (checkDead(cells))
		{
			cout << "Не осталось ни одной живой клетки" << endl;
			break;
		}
	}
}

void scen2(Cell** cells)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cells[i][j].life = false;
			cells[i][j].next = false;
		}
	}
	setDefaultSettings(cells); // Устанавливаем начальную конфигурацию
	printGeneration(cells); // Печатаем первое поколение
	cout << "Сколько поколений вывести?" << endl;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) // Генерируем и печатаем следующие k поколений
	{
		generateNextGeneration(cells);
		if (checkStable(cells))
		{
			cout << "Композиция стабильна" << endl;
			break;
		}
		setNextGeneration(cells); // Устанавливаем нужные состояния и возвращаем next к стандартному значению
		printGeneration(cells);
		if (checkDead(cells))
		{
			cout << "Не осталось ни одной живой клетки" << endl;
			break;
		}
	}
}
