#include <iostream>


using namespace std;

/*Задание 1.
Создать абстрактный класс Figure (фигура).
Его наследниками являются классы Parallelogram (параллелограмм) и Circle (круг).
Класс Parallelogram — базовый для классов Rectangle (прямоугольник), Square (квадрат), Rhombus (ромб).
Для всех классов создать конструкторы. Для класса Figure добавить чисто виртуальную функцию area() (площадь).
Во всех остальных классах переопределить эту функцию, исходя из геометрических формул нахождения площади.
*/
class Figure 
{
public:
    virtual void area() = 0; 
};

class Parallelogram : protected Figure
{
public:
    int base;   
    int height; 
public:
    Parallelogram() {
        base = 2;
        height = 2;
    }
    Parallelogram(int x_base, int v_height) : base(x_base), height(v_height) {}
    void area() override 
    {
        cout << "Площадь параллелограмма = " << base * height << "\n\n";
    }
};

class Circle : protected Figure
{
public:
    double radius;   
    double P;   
    
public:
    Circle() {
        radius = 3;
        P = 3.1415;
    }
    Circle(double x_radius, double x_p) : radius(x_radius), P(x_p = 3.1415) {} 
    void area() override
    {
        cout << "Площадь круга = " << P * (radius * radius) << "\n\n";
    }
};

class Rectangle : protected Parallelogram 
{
public:
    Rectangle() {
        base = 4;
        height = 4;
    }
    Rectangle(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "Площадь прямоугольника = " << base * height << "\n\n";
    }
};

class Square : protected Parallelogram 
{
public:
    Square() {
        base = 5;
        height = 5;
    }
    Square(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "Площадь квадрата = " << base * height << "\n\n";
    } 
};

class Rombus : protected Parallelogram 
{
public:
    Rombus() {
        base = 6;
        height = 6;
    }
    Rombus(double x_base, double v_height) : Parallelogram(x_base, v_height) {}
    void area() override
    {
        cout << "Площадь ромба = " << base * height << "\n\n";
    }
};


/* Задание 2
Создать класс Car (автомобиль) с полями company (компания) и model (модель). 
Классы-наследники: PassengerCar (легковой автомобиль) и Bus (автобус). От этих классов наследует класс Minivan (минивэн). 
Создать конструкторы для каждого из классов, чтобы они выводили данные о классах.
Создать объекты для каждого из классов и посмотреть, в какой последовательности выполняются конструкторы. 
Обратить внимание на проблему «алмаз смерти». */

class Car
{
protected:
    string company, model;
public:
    Car(){}
    
       Car(string inputCompany, string inputModel): company(inputCompany), model(inputModel)
       {
        setlocale(LC_ALL, "rus");
        
            cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
       }
        virtual ~Car()
        {
            cout << "\nДеструктор базового класса Car сработал!";
        }
    
};

class PassengerCar : virtual protected Car
{
public:
    
    PassengerCar(){}
    PassengerCar(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~PassengerCar()
    {
        cout << "\nДеструктор наследника PassengerCar сработал!";
    }
};

class Bus : virtual protected Car
{
public:
  
    Bus(){}
    Bus(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~Bus()
    {
        cout << "\nДеструктор наследника Bus сработал!";
    }
};

class Minivan : public PassengerCar, public Bus
{
public:
    
    Minivan(){}
    Minivan(string inputCompany, string inputModel) : Car(inputCompany, inputModel)
    {
        setlocale(LC_ALL, "rus");

        cout << "\n" << "(Конструктор)\n" << "company - " << company << "\nmodel - " << model << endl;
    }
    ~Minivan()
    {
        cout << "\nДеструктор множественного наследника Minivan сработал!";
    }
};

/*Task 3
 Создать класс: Fraction (дробь). Дробь имеет числитель и знаменатель (например, 3/7 или 9/2). 
 Предусмотреть, чтобы знаменатель не был равен 0.
 Перегрузить:
 математические бинарные операторы (+, -, *, /) для выполнения действий с дробями
 унарный оператор (-)
 логические операторы сравнения двух дробей (==, !=, <, >, <=, >=). 

*/
class Fraction
{
protected:
    double Chislitel, Znaminatel; 
public:
    Fraction() {}
    Fraction(double xChislitel, double yZnaminatel) : Chislitel(xChislitel), Znaminatel(yZnaminatel)
    {
        if (Znaminatel == 0) Znaminatel = 0.00000001; 
    }
    friend Fraction operator+(const Fraction& d1, const Fraction& d2); 
    friend Fraction operator-(const Fraction& d1, const Fraction& d2);
    friend Fraction operator*(const Fraction& d1, const Fraction& d2);
    friend Fraction operator/(const Fraction& d1, const Fraction& d2);
    friend Fraction operator-(const Fraction& d1); 



    double getChislitel() 
    {
        return Chislitel;
    }

    double getZnaminatel()
    {
        return Znaminatel;
    }

    void Print()
    {
        cout << "Chislitel:" << Chislitel << " Znaminatel:" << Znaminatel << endl;
    }

};

Fraction operator+(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.Chislitel * d2.Znaminatel + d2.Chislitel * d1.Znaminatel, d1.Znaminatel * d2.Znaminatel);
}

Fraction operator-(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.Chislitel * d2.Znaminatel - d2.Chislitel * d1.Znaminatel, d1.Znaminatel * d2.Znaminatel);
}

Fraction operator*(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.Chislitel * d2.Chislitel, d1.Znaminatel * d2.Znaminatel);
}

Fraction operator/(const Fraction& d1, const Fraction& d2)
{
    return Fraction(d1.Chislitel * d2.Znaminatel, d1.Znaminatel * d2.Chislitel);
}

Fraction operator-(const Fraction& d1)
{
    return Fraction(-d1.Chislitel, d1.Znaminatel);
}

bool operator==(Fraction& d1, Fraction& d2) 
{
    if ((d1.getChislitel() == d2.getChislitel()) && (d1.getZnaminatel() == d2.getZnaminatel())) return true;
    else return false;
}

bool operator!=(Fraction& d1, Fraction& d2) 
{
    if (d1 == d2) return false;
    else return true;
}

bool operator<(Fraction& d1, Fraction& d2) 
{
    if ((d1.getChislitel() / d1.getZnaminatel()) < (d2.getChislitel() / d2.getZnaminatel())) return true;
    else return false;
}

bool operator>(Fraction& d1, Fraction& d2) 
{
    if ((d1.getChislitel() / d1.getZnaminatel()) > (d2.getChislitel() / d2.getZnaminatel())) return true;
    else return false;
}

bool operator<=(Fraction& d1, Fraction& d2) 
{
    if (!(d1 > d2)) return true;
    else return false;
}

bool operator>=(Fraction& d1, Fraction& d2) 
{
    if (!(d1 < d2)) return true;
    else return false;
}
  
    



int main()
{
    //Task 1

    cout << "Task 1\n" << endl;
    setlocale(LC_ALL, "rus");

    int a;

    do {
        cout << "Введите цифру 1 для вывода дефолтного значения полей заданых через конструктор." << endl;
        cout << "Введите цифру 2 для пользовательского ввода значения полей." << endl;
        cout << "Введите цифру 1 или 2: ";
        cin >> a;
        cout << endl;
    } while (a <= 0 || a >= 3);

    switch (a)
    {
    case 1:
    {
        Parallelogram paral;
        paral.area();
        Circle circ;
        circ.area();
        Rectangle rect;
        rect.area();
        Square squar;
        squar.area();
        Rombus romb;
        romb.area();
    }
       break;

    case 2:
    {
        double x_base;
        double v_height;
        double x_radius;
        double P = 3.1415;

        cout << "    Parallelogram\n" << "Введите первое число: ";
        cin >> x_base;
        cout << "Введите второе число: ";
        cin >> v_height;
        Parallelogram paral(x_base, v_height);
        paral.area();

        cout << "    Circle\n" << "Введите число: ";
        cin >> x_radius;
        Circle circ(x_radius, P);
        circ.area();

        cout << "     Rectangle\n" << "Введите первое число: ";
        cin >> x_base;
        cout << "Введите второе число: ";
        cin >> v_height;
        Rectangle rect(x_base, v_height);
        rect.area();

        cout << "       Square\n" << "Введите первое число: ";
        cin >> x_base;
        cout << "Введите второе число: ";
        cin >> v_height;
        Square squar(x_base, v_height);
        squar.area();

        cout << "       Rombus\n" << "Введите первое число: ";
        cin >> x_base;
        cout << "Введите второе число: ";
        cin >> v_height;
        Rombus romb(x_base, v_height);
        romb.area();
    }
       break;
    };
        //Task 2
{
    cout << "Task 2" << endl;
    Car* car = new Car("Mercedes", "S500");
    PassengerCar* passengercar = new PassengerCar("Porsche", "911");
    Bus* bus = new Bus("Audi", "Q8");
    Minivan* minivan = new Minivan("Tesla", "Roadser");
    delete car;
    delete passengercar;
    delete bus;
    delete minivan;
};
        //Task 3
        {
            cout << "\n\nTask 3\n\n";
            Fraction d1(3, 2);
            Fraction d2(8, 3);
            (d1 + d2).Print();
            (d1 - d2).Print();
            (d1 * d2).Print();
            (d1 / d2).Print();
            (-d1).Print();
            if (d1 == d2) cout << "\nFraction 1 == Fraction 2";
            if (d1 != d2) cout << "\nFraction 1 != Fraction 2";
            if (d1 > d2) cout << "\nFraction 1 > Fraction 2";
            if (d1 <= d2) cout << "\nFraction 1 <= Fraction 2";
            if (d1 < d2) cout << "\nFraction 1 < Fraction 2";
            if (d1 >= d2) cout << "\nFraction 1 >= Fraction 2";
            cout << "\n";
        }
        return 0;  
};