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

	virtual double operator()(double x)=0;
	virtual ~Funcao(){}


};

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao{
public:


	void agrega (Funcao* f)
	{
		fv.push_back(f);

	}

	double operator()(double x)
	{
		return 0;
	}

private:
	FuncaoVector fv;

};



//---------------------------------------------------

class Constante: public Funcao{
public:

	Constante(double v): value(v){

	}
	double operator()(double v)
	{
		cout<< "Constante"<< endl;
		cout<< "f(x) = "<< value << endl;
		cout<< endl;
		return value;
	}


private:
	double value;
};

//------------------------------------------------------


int main() {


   Constante i(5.13);
   i(5.13);
   FuncaoAgregada fa;
   fa.agrega(&i);



	return 0;
}
