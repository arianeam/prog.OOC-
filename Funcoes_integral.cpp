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

class Funcao {
public:

	virtual double operator()(void)=0;
	virtual double getvalue(void)=0;

	static double integrar(Funcao* f, double x0, double x1, double step)
	{

		return 0;
	}

	virtual ~Funcao() {
	}

private:
	double i;

};

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao {
public:

	void agrega(Funcao *f) {
		fv.push_back(f);

	}

	double operator()(void) {
		fx = 0;
		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++) {
			cout << "f(x) agregada: " << static_cast<Funcao*>(*it)->getvalue()
					<< endl;
			fx += static_cast<Funcao*>(*it)->getvalue();
		}

		cout << "f(x)= " << fx << endl;

		return fx;
	}

	double getvalue(void) {
		return fx;
	}

private:
	FuncaoVector fv;
	double fx;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(double v) :
			value(v) {
	}

	double operator()(void) {
		cout << "Constante" << endl;
		cout << "f(x) = " << value << endl;
		cout << endl;
		return value;
	}
	double getvalue(void) {
		return value;
	}

private:
	double value;
};

//------------------------------------------------------
class Escalar: public Funcao {
public:

	Escalar(){}
	Escalar(double v): value(v){}



	double operator()(void) {

		return 0;
	}
	double getvalue(void) {
		return value;
	}

private:
	double value;
};
//------------------------------------------------------

int main() {

	Constante i(5.13);
	i();
	Constante j(5.13);
	j();
	FuncaoAgregada fa;
	fa.agrega(&i);
	fa.agrega(&j);
	fa();

	return 0;
}
