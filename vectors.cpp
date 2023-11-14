



#include <stdio.h>
#include <iostream>
using namespace std;

class Vector
{
	public:
	static int count;
	Vector (int d);
	Vector (int d,double *x);
	Vector(const Vector &);      //  copy constructor
	Vector();                   // constructor
	~Vector();                 // destructor

	Vector (Vector &x);
	void printb();
	Vector& operator +(Vector &r);
	friend Vector& operator -(Vector&l, Vector&r);
	double operator*(Vector&r);

	Vector& operator=(Vector&r);

	Vector& operator-();
	Vector& operator*(int c);


	private:
	int dim;
	double *b;
	int number;

};


int Vector::count = 0;

Vector::Vector()
{
count++;
number = count;
cout<<endl<<"Created vector "<<number<<":";
}
Vector::Vector(int d)
{
count++;
number = count;
	dim=d;
	b=new double [dim];
	for (int i=0; i<dim; i++)
		b[i]=0;
cout <<endl<<"Created vector "<<number<<":";
}
Vector::Vector(int d, double *x) {
	count++;
	number=count;
	dim=d;
	b=new double [dim];
	for (int i=0; i<dim; i++)
	b[i]=x[i];
	cout<<endl<<"Created vector "<< number<<":";
}

Vector& Vector::operator +(Vector&r)    // sum
{
	cout<<endl<<"Sum of vector "<<number<<" and "<<r.number<<":";
		Vector tmp (dim);
		for (int i=0; i<dim; i++)
		tmp.b[i]=b[i]+r.b[i];
		tmp.printb();
		return tmp;
}

Vector::~Vector()             // Destroing vector
{
	cout<<endl<<"Destroing vector #"<<number;
	delete[]b;
}

Vector& operator-(Vector &l, Vector &r)       // Subtraction
{
cout<<endl<<"Subtraction vectors "<<l.number<<" and  "<<r.number<<":";
Vector tmp (l.dim);
for (int i = 0; i < l.dim; i++)
 	tmp.b[i]=l.b[i]-r.b[i];
		tmp.printb();
	return tmp;

}
Vector::Vector(Vector &x)            // Copy vectors
{
	count++;
	number=count;
	dim=x.dim;
	b = new double[dim];
	for(int i = 0;i<dim;i++)
		b[i]=x.b[i];
	cout<<"Copy vectors. Create vector ?"<<number<<endl;
}

double Vector::operator*(Vector &r)
{
	Vector tmp (r.dim);
	int p=0;
	for (int i=0; i<r.dim; i++)
	p=p+(b[i]*r.b[i]);
	return p;
}

Vector& Vector::operator*(int c)            // scalar product
{
	Vector tmp (dim);
	for (int i=0; i<dim; i++)
		tmp.b[i]=c*b[i];
	tmp.printb();
	return tmp;
}

Vector& Vector::operator=(Vector &r)     // assignment
{
	Vector tmp (dim);
	for(int i=0;i<dim;i++)
		tmp.b[i]=r.b[i];
	tmp.printb();
	return tmp;
}

void Vector::printb()                // vector printing
{
cout<<endl<<"Vector "<<number<<": ";
for (int i=0; i<dim; i++)
	{
		cout<<b[i];
		if(i<dim-1)
			cout<<",";
	}
}

Vector& Vector::operator-()
	{
		Vector tmp(dim,b);
		for (int i = 0;i<dim;i++)
			if (tmp.b[i]!=0) tmp.b[i] = -tmp.b[i];
		tmp.printb();
		return tmp;
	}
int main()
{
	double a1[3]={1,10,11}, a2[3]={7,12,-6};
	Vector b1(3,a1), b2(3,a2);

	b1.printb();
	b2.printb();
	int c = b1*b2;
	cout<<endl<<c<<endl;

	b1+b2;
	b1-b2;
	b1*6;
	-b2;
	b2=b1;


}
