//============================================================================
// Name        : Funcoes_integral.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Funcao {
public:

	Funcao() {}

	Funcao(Funcao *f) {}

	virtual double operator()(double x)=0;

	static double integrar(Funcao *f, double x0, double x1, double step) {
		//Integral = (step/2).(f(x0) + 2.soma(f(xi)) + f(xn)) , sendo i=1 até i=n-1

		double soma, fx0, fxn;
		double k = x0 + step;
		cout << endl;
		cout << "Passo: " << step << endl;
		cout << "Intervalo de integração : [" << x0 << "," << x1 << "]" << endl;
		cout << endl;

		while (k < x1) {

			soma += f->operator()(k);
			cout << "soma = " << soma << endl;
			k = k + step;
		}

		fx0 = f->operator()(x0);
		fxn = f->operator()(x1);

		i = (step / 2.0) * (fx0 + 2 * soma + fxn);
		cout << "integral = " << i << endl;

		return i;
	}

	virtual ~Funcao() {}

private:
	static double i;

};

double Funcao::i;

//----------------------------------------------------

typedef vector<Funcao*> FuncaoVector;

class FuncaoAgregada: public Funcao {
public:

	FuncaoAgregada() {}

	void agrega(Funcao *f) { fv.push_back(f); }

	double operator()(double x) {

		double fx = 0;

		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++) {

			static_cast<Funcao*>(*it)->operator()(x);
			cout << "f(x) agregada: "<< static_cast<Funcao*>(*it)->operator()(x) << endl;
			fx += static_cast<Funcao*>(*it)->operator()(x);
		}

		cout << "f(" << x << ")= " << fx << endl;
		return fx;
	}

private:
	FuncaoVector fv;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(): value(0) {
	}
	Constante(double v) :
			value(v) {
	}

	double operator()(double x) {
		cout << "Constante" << endl;
		cout << "C = " << value << endl;
		cout << endl;
		return value;
	}

private:
	double value;
};

//------------------------------------------------------
class Escalar: public Funcao {
public:

	Escalar():a(0), f(0) {
	}
	Escalar(double v) :
			a(v), f(0) {
	}
	Escalar(Funcao *func) :
			a(0), f(func) {
	}
	Escalar(Funcao *func, double v) :
			a(v), f(func) {
	}

	double operator()(double x) {

		double fx = 0;

		if (f != NULL)
		{
			x = f->operator()(x);
			cout<< "x = "<< x<< endl;
		}
		cout << "Escalar" << endl;
		cout << "f(x) =" << a << ".x" << endl;
		cout << endl;
		fx = a * x;
		cout << "x = " << x << endl;
		cout << a << ".x=" << fx << endl;
		return fx;
	}

private:
	double a;
	Funcao *f;
};
//------------------------------------------------------
class Seno: public Funcao {
public:
	Seno(): value(1), f(0) {
	}
	Seno(double v) :
			value(v), f(0) {
	}
	Seno(Funcao *func) :
			value(1), f(func) {
	}
	Seno(double v, Funcao *func) :
			value(v), f(func) {
	}

	double operator()(double x) {

		double fx = 0;
		if(f!= NULL)
		{
			x = f->operator()(x);
		}
		cout << "f(" << x << ")= "<< value<<".sen(" << x << ")" << endl;
		fx = sin(x);
		cout << "f(" << x << ")= " << fx << endl;
		return fx;
	}

private:
	double value;
	Funcao *f;

};

//------------------------------------------------------

class Cosseno: public Funcao {
public:
	Cosseno(): value(1), f(0) {
	}
	Cosseno(double v) :
			value(v), f(0) {
	}
	Cosseno(Funcao *func) :
			value(1), f(func) {
	}
	Cosseno(double v, Funcao *func) :
			value(v), f(func) {
	}

	double operator()(double x) {

		double fx = 0;
		if(f!= NULL)
		{
					x = f->operator()(x);
		}

		cout << "f(" << x << ")= "<<value<<".cos(" << x << ")" << endl;
		fx = value*cos(x);
		cout << "f(" << x << ")= " << fx << endl;
		return fx;
	}

private:
	double value;
	Funcao *f;
};

//-----------------------------------------------------

class Potencial: public Funcao {
public:

	Potencial(): a(0), f(0){
	}
	Potencial(double v) :
			a(v),f(0) {

	}
	Potencial(Funcao *func) :
			a(0), f(func) {
	}
	Potencial(double v, Funcao *func) :
			a(v), f(func) {
	}

	double operator()(double x) {

		double fx = 0;

		if (f != NULL) {
			x = f->operator()(x);
		}
		cout << "f(x) = x^" << a << endl;
		cout << "f(" << x << ")= " << x << "^" << a << endl;
		fx = pow(x, a);
		cout << "potenciacao resultado: " << fx << endl;

		return fx;
	}

private:

	double a;
	Funcao *f;

};

//----------------------------------------------------

class Exponencial: public Funcao {
public:

	Exponencial() {
	}
	Exponencial(double v) :
			a(v), f(0) {
	}
	Exponencial(Funcao *func) :
			f(func) {
	}
	Exponencial(double v, Funcao *func) :
			a(v), f(func) {
	}

	double operator()(double x) {

		double fx = 0;
		if(f!= NULL)
		{
			x = f->operator()(x);
		}


		cout << "f(x) = " << a << "^x" << endl;
		cout << "f(" << x << ")= " << a << "^" << x << endl;
		fx = pow(a, x);
		cout << "exponencial resultado: " << fx << endl;

		return fx;
	}

private:

	double a;
	Funcao *f;

};

//-----------------------------------------------------------------

int main() {

	double x0, x1, step;
	x0 = 0;
		x1 = 5;
		step = 0.0001;

	Escalar a(new Potencial(2), 1);
	Constante b(5);
	FuncaoAgregada f;
	f.agrega(&a);
	f.agrega(&b);

	Escalar c(2);
	Constante d(-1);
	FuncaoAgregada e;
	e.agrega(&c);
	e.agrega(&d);

	Seno s(&e);
	Escalar h(&s,5);
	FuncaoAgregada i;
	i.agrega(&h);

	FuncaoAgregada m;
	m.agrega(&f);
	m.agrega(&i);

	Funcao::integrar(&m, 0, 5, 0.01);

	return 0;
}
