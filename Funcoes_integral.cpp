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

	Funcao(){};
	virtual double operator()(double x)=0;
	virtual double getvalue(void)=0;
	virtual void setvalue(double x)=0;

   static double integrar(Funcao* f, double x0, double x1, double step)
	{
	   //Integral = (step/2).(f(x0) + 2.soma(f(xi)) + f(xn)) , sendo i=1 até i=n-1

       double n, soma, fx0, fxn;
	   double k = x0 + step;
       n= (x1 - x0)/step;
       cout<<endl;
       cout<<"Numero de segmentos: "<< n << endl;
       cout<< "Passo: "<< step<< endl;
       cout<<"Intervalo: [" << x0 << "," << x1 << "]" << endl;
       cout<<endl;



       while (k < x1)
       {
           f->setvalue(k);
           soma += f->getvalue();
           cout<<"soma = " << soma << endl;
           k = k+step;
       }

       i = (step/2.0);

		return i;
	}

	virtual ~Funcao() {
	}

private:
	static double i;

};

 double Funcao :: i;

//----------------------------------------------------
typedef vector<Funcao*> FuncaoVector;
typedef vector<double> fxVector;

class FuncaoAgregada: public Funcao {
public:

	FuncaoAgregada(){}

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

		fxresultados.push_back(fx);
		cout << "f("<<x<<")= " << fx << endl;
		return fx;
	}

	double getvalue(void) {

        double value;
        value = fxresultados[0];
        fxresultados.pop_back();
		cout<<" fx resultado: " <<value<<endl;
		return value;
	}

	void setvalue(double xvalue)
	{
        x = xvalue;
	}
private:
	FuncaoVector fv;
	fxVector fxresultados;
	double fx;
	double x;
};

//---------------------------------------------------

class Constante: public Funcao {
public:

	Constante(){}
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
		cout<<"x = "<<xvalue<<endl;
		cout<<a<<".x="<<fx<<endl;
		return fx;
	}

	void setvalue(double x)
	{
			xvalue = x;

	}

private:
	double a;
	Funcao *fe;
	double fx;
	double xvalue;
};
//------------------------------------------------------

int main() {

	double k, x0, x1, step;
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

	x0 = 0;
	x1 = 1;
	step = 0.1;
	k = x0 + step;

	while (k<x1)
	{
		fa(k);
		k = k+step;
	}
   Funcao::integrar(&fa,x0,x1,step);

	return 0;
}
