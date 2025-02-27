#include <iostream.h>
#include<math.h>
#include <stdlib.h>

//Задача 1. Предаване на константен псевдоним на обект като параметър на функция.
class point 
{ private:
double x;
double y;
public:
point(double xcoord, double ycoord); 
void print(); 
double dist(const point &p1, const point &p2); 
~point(); 
};
point::point(double xcoord, double ycoord) 
{
cout << ”Creating Point(” << xcoord << ”,” << ycoord << ”)” << endl;
x = xcoord;
y = ycoord;
}
void point::print()
{
cout << ”Point(” << x << ”,” << y << ”)”;
}
double point::dist(const point &p1, const point &p2) 
{
return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point::~point() 
{ cout << ”Destructing ”;
print();
cout << endl;
}
void main()
{ point a(3,4), b(10,4);
cout << ”Distance between ”; a.print();
cout << ” and ”; b.print();
cout << ” is ” << a.dist(a,b) << endl;
}

//Задача 2. Следната програма създава клас за масив, който автоматично прави проверка за границите на масива. Класа за масив съдържа 2 основни функции – една, която съхранява информацията от масива, и друга, която извлича информацията. Тези функции могат да проверяват по време на изпълнение дали не се надхвърлят границите на масива.

class array {
int size;
char *p;
public:
array(int num);
~array() { delete [] p; }
char &put(int i);
char get(int i);
};
array::array(int num)
{
p = new char [num];
if(!p){
cout << ”Allocation error\n”;
exit(1);
}
size = num;
}
char &array::put(int i) 
{
if(i<0 || i>=size) {
cout << ”Bounds error!!!\n”;
exit(1);
}
return p[i];
}
char array::get(int i) 
{
if(i<0 || i>=size) {
cout << ”Bounds error!!!\n”;
exit(1);
}
return p[i]; 
}
int main()
{
array a(10);
a.put(3) = ’X’;
a.put(2) = ’R’;
cout << a.get(3) << ”\n” << a.get(2);
cout << ”\n”;
a.put(11) = ’!’;
return 0;
}

