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

	virtual double operador(double x)=0;
	virtual ~Funcao(){}


};

//----------------------------------------------------
class FuncaoAgregada: public Funcao{
public:


	void agrega (Funcao* f)
	{
		FuncaoVetor.push_back(f);
	}

	double operador (double x)
	{
		return 0;
	}

private:
	vector<Funcao*> FuncaoVetor;

};

//---------------------------------------------------

class Constante: public Funcao{
public:

	Constante(double v): value(v){
		operador(v);
	}
	double operador(double v)
	{
		cout<< "f(x) = "<< value <<endl;
		return value;
	}


private:
	double value;
};

//------------------------------------------------------


int main() {


   Constante i(5.13);
   FuncaoAgregada fa;



	return 0;
}
