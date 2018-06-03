#include "realization.h"

int main(int argc, char* argv[])
{
	Cell** cells = new Cell* [m]; // Создаем поле(матрицу) клеток

	for (int i = 0; i < m; i++)
	{
		cells[i] = new Cell [n];
	}

	if (argc == 2)
	{
		scen1(argv[1], cells);
	}
	else if (argc == 1)
	{
		scen2(cells);
	}
	else
	{
		cout << "Что-то пошло не так, попробуйте снова.";
	}
	return 0;
}
