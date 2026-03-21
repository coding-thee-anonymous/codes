#include <iostream>
using namespace std;

class Rectangle
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }
    
    double area()
    {
        return length * width;
    }
    
    void display()
    {
        cout << "Length: " << length << ", Width: " << width << ", Area: " << area() << endl;
    }
};

int main()
{
    double l, w;
    
    cout << "Enter length and width for Rectangle 1: ";
    cin >> l >> w;
    Rectangle rect1(l, w);
    cout << "Rectangle 1: ";
    rect1.display();
    
    cout << "Enter length and width for Rectangle 2: ";
    cin >> l >> w;
    Rectangle rect2(l, w);
    cout << "Rectangle 2: ";
    rect2.display();
    
    cout << "Enter length and width for Rectangle 3: ";
    cin >> l >> w;
    Rectangle rect3(l, w);
    cout << "Rectangle 3: ";
    rect3.display();
    
    return 0;
}