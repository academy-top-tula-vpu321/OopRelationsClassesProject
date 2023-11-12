#include <iostream>
#include <string>

class Engine
{
public:
    Engine()
    {
        std::cout << this << " Engine construct\n";
    }

    ~Engine()
    {
        std::cout << this << " Engine destruct\n";
    }
};

class Car
{
    Engine engine;
    int speed;
public:
    Car()
    {
        std::cout << this << " Car construct\n";
    }

    ~Car()
    {
        std::cout << this << " Car destruct\n";
    }
};

class Teacher
{
    std::string name;
public:
    Teacher(std::string name)
        : name{ name } 
    {
        std::cout << this << " Teacher construct\n";
    }

    ~Teacher()
    {
        std::cout << this << " Teacher destruct\n";
    }
};

class Group
{
    std::string number;
    Teacher* teacher;
public:
    Group(std::string number)
        : number{ number }
    {
        std::cout << this << " Group construct\n";
    }

    ~Group()
    {
        std::cout << this << " Group destruct\n";
    }
};



class Person
{
protected:
    std::string name;

public:
    Person()
    {
        std::cout << this << " Person construct\n";
        this->name = "Anonim";
    }

    Person(std::string name)
    {
        std::cout << this << " Person construct\n";
        this->name = name;
    }

    std::string& Name() { return name; }

    std::string ToString()
    {
        return "Name: " + name;
    }

    ~Person()
    {
        std::cout << this << " Person destruct\n";
    }
};

class Employee : public Person
{
    int salary;
public:
    Employee()
    {
        std::cout << this << " Employee construct\n";
    }

    Employee(std::string name) : Person(name)
    {
        std::cout << this << " Employee construct\n";
    }

    ~Employee()
    {
        std::cout << this << " Employee destruct\n";
    }

    int& Salary() { return salary; }

    std::string ToString()
    {
        return Person::ToString() 
                    + ", Salary: " + std::to_string(salary);
    }
};

class Manager : public Employee
{
    std::string department;
public:
    Manager()
    {
        std::cout << this << " Manager construct\n";
    }

    ~Manager()
    {
        std::cout << this << " Manager destruct\n";
    }
};


class Gadget
{
public:
    std::string ToString()
    {
        return "Gadget";
    }
};

class Printer : public Gadget
{
public:
    Printer()
    {
        //std::cout << this << " Printer construct\n";
    }

    ~Printer()
    {
        //std::cout << this << " Printer destruct\n";
    }

    std::string ToString()
    {
        return "Printer";
    }

    void Print()
    {
        std::cout << this << " Printer print\n";
    }
};

class Scanner : public Gadget
{
public:
    Scanner()
    {
        //std::cout << this << " Scanner construct\n";
    }

    ~Scanner()
    {
        //std::cout << this << " Scanner destruct\n";
    }

    std::string ToString()
    {
        return "Scanner";
    }

    void Scan()
    {
        std::cout << this << " Scanner scan\n";
    }
};

class Mfu : public Scanner, public Printer
{
public:
    Mfu()
    {
        //std::cout << this << " Mfu construct\n";
    }

    ~Mfu()
    {
        //std::cout << this << " Mfu destruct\n";
    }
};

int main()
{
    //Car car;
    //Group group("SPU-321");

    /*
    Person person;
    person.Name() = "Tom";

    std::cout << person.ToString() << "\n";


    Employee employee("Joe");
    employee.Name() = "Bob";
    employee.Salary() = 50000;

    std::cout << employee.ToString() << "\n";
    

    Manager manager;
    */

    Mfu mfu;
    mfu.Print();
    mfu.Scan();

    std::cout << mfu.Gadget::ToString() << "\n";

    return 0;
}
