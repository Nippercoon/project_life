#ifndef REALIZATION_H_
#define REALIZATION_H_
#include <iostream>
#include <fstream>
using namespace std;

const int m = 10; // высота поля
const int n = 10; // ширина поля
const char dead = '.';
const char alive = '#';

struct Cell
{
	bool life;
	bool next;
};

int countNeighbors(Cell** cells, int i, int j);
void setNextGeneration(Cell** cells);
void generateNextGeneration(Cell** cells);
void printGeneration(Cell** cells);
void setDefaultSettings(Cell** cells);
bool checkStable(Cell** cells);
bool checkDead(Cell** cells);
void readFile(string s, Cell** cells);
void scen1(string s, Cell** cells);
void scen2(Cell** cells);



#endif /* REALIZATION_H_ */
