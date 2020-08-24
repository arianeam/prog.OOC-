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

	virtual double operador()=0;
	virtual ~Funcao(){}


};

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao{
public:


	void agrega (Funcao* f)
	{
		fv.push_back(f);
		cout<<"f(x) agregada : "<< endl;
		for(FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++){
				static_cast<Funcao*>(*it)->operador();
			}

	}

	double operador ()
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
		operador();
	}
	double operador(void)
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
   FuncaoAgregada fa;
   fa.agrega(&i);



	return 0;
}
