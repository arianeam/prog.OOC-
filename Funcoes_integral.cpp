//============================================================================
// Name        : Funcoes_integral.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

class Funcao{
public:
    Funcao(){}
	virtual double operador(double x)=0;
	virtual ~Funcao(){}
};


class FuncaoAgregada: public Funcao{
public:
	void agrega (Funcao* f)
	{
		FuncaoVetor.push_back(f);
	}



private:
	vector<Funcao*> FuncaoVetor;
};


class Constante: public Funcao{
public:

	Constante(double v): value(v){}


private:
	double value;
};

int main() {
	cout << "git teste" << endl; // prints !!!Hello World!!!
	return 0;
}
