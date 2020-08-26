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

	virtual double operator()(double x)=0;
	virtual double getvalue(void)=0;
	virtual void setvalue(double x)=0;

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

	double operator()(double x) {
		fx = 0;
		for (FuncaoVector::iterator it = fv.begin(); it != fv.end(); it++) {

		    static_cast<Funcao*>(*it)->setvalue(x);
			cout << "f(x) agregada: " << static_cast<Funcao*>(*it)->getvalue()	<< endl;
			fx += static_cast<Funcao*>(*it)->getvalue();
		}

		cout << "f(x)= " << fx << endl;

		return fx;
	}

	double getvalue(void) {
		return fx;
	}

	void setvalue(double xvalue)
	{
        x = xvalue;
	}
private:
	FuncaoVector fv;
	double fx;
	double x;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(double v) :
			value(v) {
	}

	double operator()(double x) {
		cout << "Constante" << endl;
		cout << "f(x) = " << value << endl;
		cout << endl;
		return value;
	}
	double getvalue(void) {
		return value;
	}

	void setvalue(double x)
		{

		}
private:
	double value;
};

//------------------------------------------------------
class Escalar: public Funcao {
public:

	Escalar(){}
	Escalar(double v): a(v){}
	Escalar(Funcao* f): fe(f){}
	Escalar(Funcao* f, double v): a(v), fe(f){}



	double operator()(double x) {
		cout<< "Escalar"<<endl;
		cout<<"f(x) =" << a <<"x"<<endl;
		cout<< endl;
		return a;
	}
	double getvalue(void) {
		fx = a*xvalue;
		cout<<"fx= "<<fx<<endl;
		return fx;
	}

	void setvalue(double x)
	{
			xvalue = x;
			cout<<"x = "<<x<<endl;

	}

private:
	double a;
	Funcao *fe;
	double fx;
	double xvalue;
};
//------------------------------------------------------

int main() {

	Constante i(5.15);
	i(5.15);
	Constante j(10.50);
	j(10.50);
	Escalar e(20.50);
	e(20.50);
	FuncaoAgregada fa;
	fa.agrega(&i);
	fa.agrega(&j);
	fa.agrega(&e);
	fa(2);

	return 0;
}
