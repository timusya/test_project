#include <iostream>

using namespace std;

// класс Точка
class Point {
protected:
	int x{ 0 };
	int y{ 0 };
public:
	// конструктор по умолчанию
	Point() {
		cout << "Point()\n";
	}
	// конструктор с параметрами
	Point(int x, int y) : x(x), y(y) {
		cout << "Point(int x, int y)\n";
	}
	// конструктор копирования
	Point(const Point& p) : x(p.x), y(p.y) {
		cout << "Point(const Point& p)\n";
	}
	// деструктор
	~Point() {
		cout << x << ' ' << y << '\n';
		cout << "~Point()\n";
	}
	// реализация метода в определении класса
	void move(int dx, int dy) {
		x += dx;
		y += dy;
	}
	void reset();
};
// реализация метода после определения класса
void Point::reset() {
	x = 0;
	y = 0;
}

// класс-наследник Цветная точка
class ColoredPoint : public Point {
private:
	int color{ 0 };
public:
	// конструктор по умолчанию
	ColoredPoint() : Point() {
		cout << "ColoredPoint()\n";
	}
	// конструктор с параметрами
	ColoredPoint(int x, int y, int color) : Point(x, y), color(color) {
		cout << "ColoredPoint(int x, int y, int color)\n";
	}
	// конструктор копирования
	ColoredPoint(const ColoredPoint& p) : Point(p), color(p.color) {
		cout << "ColoredPoint(const ColoredPoint& p)\n";
	}
	// деструктор
	~ColoredPoint() {
		cout << x << ' ' << y << ' ' << color << '\n';
		cout << "~ColoredPoint()\n";
	}
	void change_color(int new_color) {
		color = new_color;
	}
};

// класс Отрезок
class Section {
private:
	// композиция объектов
	Point *p1;
	Point *p2;
public:
	// конструктор по умолчанию
	Section() {
		cout << "Section()\n";
		p1 = new Point();
		p2 = new Point();
	}
	// конструктор с параметрами
	Section(int x1, int y1, int x2, int y2) {
		cout << "Section(int x1, int y1, int x2, int y2)\n";
		p1 = new Point(x1, y1);
		p2 = new Point(x2, y2);
	}
	// конструктор копирования
	Section(const Section& s) {
		cout << "Section(const Section& s)\n";
		p1 = new Point(*(s.p1));
		p2 = new Point(*(s.p2));
	}
	// деструктор
	~Section() {
		delete p1;
		delete p2;
		cout << "~Section()\n";
	}
};

int main() {
	/*
	// Создание, использование и уничтоженеие статически создаваемых объектов
	Point a;
	Point b(1, 3);
	Point c(b);
	Point d(c);
	d.reset();
	d.move(5, 5);
	*/

	/*
	// Создание, использование и уничтоженеие динамически создаваемых объектов
	Point *pa = new Point;
	Point *pb = new Point(13, 9);
	Point *pc = new Point(*pb);
	Point* pd = new Point(*pb);
	pd->move(2, 3);
	delete pa;
	delete pb;
	delete pc;
	delete pd;
	*/

	/*
	// работа с объектом класса-наследника
	ColoredPoint *p = new ColoredPoint(1, 7, 23);
	p->change_color(9);
	p->move(1, 1);
	delete p;
	*/

	/*
	// переменные различных типов
	Point *p2 = new ColoredPoint(1, 3, 9);
	delete p2;
	*/

	/*
	// создание объекта класса с композицией
	Section *s1 = new Section();
	Section *s2 = new Section(*s1);
	delete s1;
	delete s2;
	*/
	return 0;
}