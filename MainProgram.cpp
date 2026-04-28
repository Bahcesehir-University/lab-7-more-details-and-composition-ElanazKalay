
#include <iostream>
#include <string>

#include <cmath>
// ============================================================
// CLASS DEFINITIONS
// ============================================================
@@ -18,18 +18,19 @@ class Point {
double y;
public:
// TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(0), y(0) {}  // stub — fix initializer
    Point(double x, double y) : x(x), y(y) {}  // stub — fix initializer

// TODO 2: const getter for x
double getX() { return x; }   // stub — add const

// TODO 3: const getter for y
    double getY() { return y; }   // stub — add const
    double getY() const { return y; }   // stub — add const

// TODO 4: const display()
    void display() const { std::cout << "(?, ?)"; }
    void display() const { std::cout << "("<<x<<","<<y<<")" ; }

// TODO 5: declare Rectangle as friend class
    friend class Rectangle;
};


@@ -40,27 +41,35 @@ class Rectangle {
public:
// TODO 6: constructor with member initializer list
Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(0,0), bottomRight(0,0) {}  // stub — fix initializer
        : topLeft(x1,y1), bottomRight(x2,y2) {}  // stub — fix initializer

// TODO 7: const getWidth()
    double getWidth() const { return 0; }  // stub
    double getWidth() const { return std::abs(bottomRight.x-topLeft.x) ; }  // stub

// TODO 8: const getHeight()
    double getHeight() const { return 0; }  // stub
    double getHeight() const { return std::abs(bottomRight.y-topLeft.y) ; }  // stub

// TODO 9: const getArea()
    double getArea() const { return 0; }  // stub
    double getArea() const { return getWidth()*getHeight(); }  // stub

// TODO 10: const display()
    void display() const {}

    void display() const {
        std::cout<<"TopLeft";
        topLeft.display();
        std::cout<<"\nBottomRight: ";
        bottomRight.display();
        std::cout <<"\nWidght "<<getWidth()
                  <<",Height: "<<getHeight()
                 <<" , Area: "<<getArea()<<"\n";
    }
// TODO 11: declare isSameSize as friend function
    friend bool isSameSize(const Rectangle& r1,const Rectangle& r2);
};


// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return false;  // stub
    return r1.getArea() == r2.getArea();  // stub
}


@@ -69,16 +78,16 @@ class ConstDemo {
int value;
public:
// TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(0) {}  // stub — fix initializer
    ConstDemo(int v) : value(v) {}  // stub — fix initializer

// TODO 14: const getValue()
    int getValue() { return value; }  // stub — add const
    int getValue()const { return value; }  // stub — add const

// TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() {}  // stub
    void doubleValue() {value*=2;}  // stub

// TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() { return 0; }  // stub — add const + fix body
    int constGetDouble()const { return value*2; }  // stub — add const + fix body
};


@@ -87,6 +96,19 @@ class ConstDemo {
// ============================================================
int main() {
// TODO 17-21: demo code
    std::cout << "Complete the TODOs above!" << std::endl;
    std::cout << "== Part 1 &2:Rectangle with Composition ===" << std::endl;
    Rectangle rect1(0,0,4,3);
    Rectangle rect2(1,1,4,4);
    std::cout <<"\nRect1:\n";rect1.display();
    std::cout <<"\nRect2:\n";rect2.display();
    std::cout <<"\nSame Size?"
              <<(isSameSize(rect1,rect2)?"yes ": "no")<<"\n";
     std::cout << "\n== Part 3" << std::endl;
     const ConstDemo cd1(7);
     std::cout<<"const obj value"<<cd1.getValue()<<"\n";
     std::cout<<"const obj double (no mutation)"<<cd1.constGetDouble()<<"\n";
     ConstDemo cd2(5);
     cd2.doubleValue();
     std::cout<<"non const obj after double value"<<cd2.getValue()<<"\n";
return 0;
}
