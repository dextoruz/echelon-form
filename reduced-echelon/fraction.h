#include <iostream>
#include <string>
#include <algorithm>

#define size 10

using namespace std;

class fraction{

private:
	char c;
	int p,q;

	int xGCD(int a, int b, int &x, int &y) {
	    if(b == 0) {
	       x = 1; y = 0;
	       return a;
	    }
	    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
	    x = y1;
	    y = x1 - (a / b) * y1;
	    return gcd;
	}
	int getFraction(int a, int b){
	  int x, y, gcd;
	  if(a < b) swap(a, b);
	  gcd = xGCD(a, b, x, y);
	  return gcd;
	}

public:

	void simplify(){
		int sign = 0,gcd;
		if(p == 0){	q = 1;	}
		if(p < 0 && q < 0){	p*=-1;	q*=-1;	}
		if(q < 0){	p*=-1;	q*=-1;	}
		if(p < 0){	p*=-1;	sign++;	}
		gcd = getFraction(p,q);
		p /= gcd;
		q /= gcd;
		if(sign == 1){	p*=-1;	sign = 0;	}
		return;
	}

	friend istream& operator>>(istream& s, fraction& f){
		// cout<<"Enter fraction: ";
		int fl = 0;
		string str = "", num="", dem="1";
		s>>str;
		for(int i = 0; i < str.length(); i++){
	    if(str[i] >= '0' && str[i] <= '9' || str[i] == '/'){
	      if(str[i] == '/'){
	        dem ="";
	        fl = 1;
	        continue;
	      }
	      if(fl == 0 )
	        num += str[i];
	      else
	        dem += str[i];
	    }
	    else{
	      cout<<"wrong attempt\n";
	      _Exit(EXIT_FAILURE);
	    }
	  }
		f.p = stoi(num);
		f.c = '/';
		f.q = stoi(dem);
		if(f.q == 0){
			cout<<"Zero division error.\n";
			_Exit(EXIT_FAILURE);
		}
		return s;
	}
	friend ostream& operator<<(ostream& ss, fraction& f){
		if(f.q == 1 || f.p == 0)	ss<<f.p;
		else	ss<<f.p<<"/"<<f.q;
		return ss;
	}
	bool operator==( fraction f){
		// cout<<p<<c<<q<<" == "<<f.p<<f.c<<f.q<<" is ";
		fraction f1;
		f1.p = p;
		f1.q = q;
		f1.c = c;
		f1.simplify();
		f.simplify();
		if(f1.p == f.p && f1.q == f.q){
			// cout<<"true"<<endl;
			return true;
		}
		// cout<<"false"<<endl;
		return false;
	}
	bool operator!=( fraction f){
		// cout<<p<<c<<q<<" != "<<f.p<<f.c<<f.q<<" is ";
		fraction f1;
		f1.p = p;
		f1.q = q;
		f1.c = c;
		f1.simplify();
		f.simplify();
		if(f1.p == f.p && f1.q == f.q){
			// cout<<"false"<<endl;
			return false;
		}
		// cout<<"true"<<endl;
		return true;
	}
	bool operator>( fraction f){
		// cout<<p<<c<<q<<" > "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		int x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x > y)
		{
			// cout<<"true"<<endl;
			return true;
		}
		// cout<<"false"<<endl;
		return false;
	}
	bool operator<( fraction f){
		// cout<<p<<c<<q<<" < "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		int x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x < y)
		{
			// cout<<"true"<<endl;
			return true;
		}
		// cout<<"false"<<endl;
		return false;
	}
	bool operator>=( fraction f){
		// cout<<p<<c<<q<<" >= "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		int x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x >= y)
		{
			// cout<<"true"<<endl;
			return true;
		}
		// cout<<"false"<<endl;
		return false;
	}
	bool operator<=(fraction f){
		// cout<<p<<c<<q<<" <= "<<f.p<<f.c<<f.q<<" is ";
		fraction temp;
		temp.p = p;
		temp.q = q;
		temp.c = c;
		temp.simplify();
		f.simplify();
		int x ,y;
		x = temp.p * f.q;
		y = temp.q * f.p;
		if(x <= y)
		{
			// cout<<"true"<<endl;
			return true;
		}
		// cout<<"false"<<endl;
		return false;
	}
	fraction operator++(int){
		fraction f;
		f.p = p + q;
		f.q = q;
		f.c = c;
		return f;
	}
	fraction operator++(){
		fraction f;
		f.p = p;
		f.q = q;
		f.c = c;
		p+=q;
		return f;
	}
	fraction operator--(int){
		fraction f;
		f.p = p - q;
		f.q = q;
		f.c = c;
		return f;
	}
	fraction operator--(){
		fraction f;
		f.p = p;
		f.q = q;
		f.c = c;
		p-=q;
		return f;
	}
	fraction operator +(fraction f){
		// cout<<p<<c<<q<<" + "<<f.p<<c<<f.q<<" = ";
		fraction f1;
		f1.p = (p * f.q)+(q * f.p);
		f1.q = q * f.q;
		f1.c = c;
		f1.simplify();
		// cout<<f1<<endl;
		return f1;
	}
	fraction operator +(int value)const{
		// cout<<p<<c<<q<<" + "<<value<<" = ";
		fraction f1;
		f1.p = p +(q * value);
		f1.q = q;
		f1.c = c;
		f1.simplify();
		// cout<<f1<<endl;
		return f1;
	}
	friend fraction operator +(int value, fraction &f){
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		// cout<<value<<" + "<<f.p<<f.c<<f.q<<" = ";
		f0.p = f0.p +(f0.q * value);
		f0.simplify();
		return f0;
	}
	fraction operator -( fraction f)const{
		// cout<<p<<c<<q<<" - "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = (p * f.q)-(q * f.p);
		f0.q = q * f.q;
		f0.c = c;
		f0.simplify();
		// cout<<f0<<endl;
		return f0;
	}
	fraction operator -(int value)const{
		// cout<<p<<c<<q<<" - "<<value<<" = ";
		fraction f1;
		f1.p = p -(q * value);
		f1.q = q;
		f1.c = c;
		f1.simplify();
		return f1;

	}
	friend fraction operator -(int value, fraction &f){
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		// cout<<value<<" - "<<f.p<<f.c<<f.q<<" = ";
		f0.p = f0.p -(f0.q * value);
		f0.simplify();
		return f0;
	}
	fraction operator -(){
		fraction temp;
		temp.p = p;
		temp.q = q;
		if(temp.p<0 && temp.q<0) temp.q*=-1;
		else if(temp.p>0 && temp.q>0)	temp.p*=-1;
		else if(temp.p<0 && temp.q>0)	temp.p*=-1;
		else if(temp.p>0 && temp.q<0)	temp.q*=-1;
		return temp;
	}
	fraction operator *(fraction f){
		// cout<<p<<c<<q<<" * "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = p * f.p;
		f0.q = q * f.q;
		f0.c = c;
		f0.simplify();
		return f0;
	}
	fraction operator *(int value){
		// cout<<p<<c<<q<<" * "<<value<<" = ";
		fraction f0;
		f0.p = p * value;
		f0.q = q;
		f0.c = c;
		f0.simplify();
		return f0;
	}
	friend fraction operator *(int value, fraction &f){
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		// cout<<value<<" * "<<f.p<<f.c<<f.q<<" = ";
		f0.p *= value;
		f0.simplify();
		return f0;
	}
	fraction operator /(fraction f){
		// cout<<p<<c<<q<<" / "<<f.p<<c<<f.q<<" = ";
		fraction f0;
		f0.p = p * f.q;
		f0.q = q * f.p;
		f0.c = c;
		if(f0.q == 0){
			cout<<"Zero division error divide .\n";
			_Exit(EXIT_FAILURE);
		}
		f0.simplify();
		return f0;
	}
	fraction operator /(int value){
		// cout<<p<<c<<q<<" / "<<value<<" = ";
		fraction f1;
		f1.p = p;
		f1.c = c;
		f1.q = q * value;
		if(f1.q == 0){
			cout<<"Zero division error divide 2.\n";
			_Exit(EXIT_FAILURE);
		}
		f1.simplify();
		return f1;
	}
	friend fraction operator /(int value, fraction &f){
		fraction f0;
		f0.p = f.p;
		f0.q = f.q;
		f0.c = f.c;
		int x;
		// cout<<value<<" / "<<f.p<<f.c<<f.q<<" = ";
		x = f0.p;
		f0.p = f0.q * value;
		f0.q = x;
		f0.simplify();
		return f0;
	}
	void operator+=(fraction f){
		// cout<<p<<c<<q<<" + "<<f.p<<f.c<<f.q<<" = ";
		p = (p * f.q)+(q * f.p);
		q *= f.q;
		simplify();
		return;
	}
	void operator+=(int value){
		// cout<<p<<c<<q<<" + "<<value<<" = ";
		p += (q * value);
		q *= q;
		simplify();
		return;
	}
	void operator-=(fraction f){
		// cout<<p<<c<<q<<" - "<<f.p<<f.c<<f.q<<" = ";
		p = (p * f.q)-(q * f.p);
		q = q * f.q;
		simplify();
		return;
	}
	void operator-=(int value){
		// cout<<p<<c<<q<<" - "<<value<<" = ";
		p -= (q * value);
		simplify();
		return;
	}
	void operator*=(fraction f){
		// cout<<p<<c<<q<<" * "<<f.p<<f.c<<f.q<<" = ";
		p *= f.p;
		q *= f.q;
		simplify();
		return;
	}
	void operator*=(int value){
		// cout<<p<<c<<q<<" * "<<value<<" = ";
		p *= value;
		simplify();
		return;
	}
	void operator/=(fraction f){
		// cout<<p<<c<<q<<" / "<<f.p<<f.c<<f.q<<" = ";
		p *= f.q;
		q *= f.p;
		simplify();
		return;
	}
	void operator/=(int value){
		// cout<<p<<c<<q<<" / "<<value<<" = ";
		q *= value;
		simplify();
		return;
	}

	 fraction(){
     p = 0;
		 c = '/'; q = 1;
	 }
	~fraction(){}
};
