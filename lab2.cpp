#include <iostream>
/*
class Rectangle {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    // Функция за изчисляване на лицето и периметъра
    void face() {
        double area = length * width;
        double perimeter = 2 * (length + width);

        // Извеждане на резултатите
        std::cout << "Лицето на правоъгълника е: " << area << std::endl;
        std::cout << "Периметърът на правоъгълника е: " << perimeter << std::endl;
    }
};

int main() {
    // Въвеждане на дължина и ширина от потребителя
    double length, width;
    std::cout << "Въведете дължина на правоъгълника: ";
    std::cin >> length;
    std::cout << "Въведете ширина на правоъгълника: ";
    std::cin >> width;

    // Създаване на обект от класа Rectangle
    Rectangle myRectangle(length, width);

    // Извикване на функцията за изчисляване на лицето и периметъра
    myRectangle.face();

    return 0;
}


//Напишете клас Stack, който изобразява стек. Напишете функцията функцията loadstack(), която връща като резултат стек, напълнен със символите от азбуката (a-z). Предефинирайте функцията така, че да приема като параметър стойност от тип int с име upper. Ако upper е 1, попълнете
//стека с голями букви от азбуката. В противен случай го попълнете с малки букви.

#include <iostream>
#include <stack>

class Stack {
private:
    std::stack<char> data;

public:
    // Функция за добавяне на елемент в стека
    void push(char c) {
        data.push(c);
    }

    // Функция за изваждане на елемент от стека
    char pop() {
        if (!data.empty()) {
            char top = data.top();
            data.pop();
            return top;
        }
        // Връщаме някакъв стандартен символ, ако стекът е празен
        return '\0';
    }

    // Функция за проверка дали стекът е празен
    bool isEmpty() const {
        return data.empty();
    }
};

// Функция за зареждане на стека с буквите от азбуката
Stack loadstack(int upper) {
    Stack myStack;

    char startChar = (upper == 1) ? 'A' : 'a';
    char endChar = (upper == 1) ? 'Z' : 'z';

    for (char c = startChar; c <= endChar; ++c) {
        myStack.push(c);
    }

    return myStack;
}

int main() {
    int upper;
    std::cout << "Въведете 1 за големи букви или 0 за малки букви: ";
    std::cin >> upper;

    // Зареждане на стека
    Stack myStack = loadstack(upper);

    // Извеждане на елементите на стека
    while (!myStack.isEmpty()) {
        std::cout << myStack.pop() << " ";
    }

    return 0;
}
*/

//Задача 2: Представете си ситуация, в която два класа pr1 и pr2 си поделят един принтер. След това си представете, че други части от вашата програма трябва да знаят кога принтерът се използва от обект от някой от тези два класа. Създайте функцията inuse(), която връща резултат true, ако принтерът се използва от някой от двата класа и false във всички останали случаи. Направете тази функция приятелска и за двата класа.

#include <iostream>

class Printer; // Декларация на класа Printer

class pr1 {
public:
    void usePrinter(Printer& printer);
};

class pr2 {
public:
    void usePrinter(Printer& printer);
};

class Printer {
private:
    bool inUse;

public:
    Printer() : inUse(false) {}

    // Приятелска функция
    friend bool inuse(const pr1& obj1, const pr2& obj2, const Printer& printer);
};

// Дефиниция на метода usePrinter за pr1
void pr1::usePrinter(Printer& printer) {
    // Използване на принтера от pr1
    printer.inUse = true;
}

// Дефиниция на метода usePrinter за pr2
void pr2::usePrinter(Printer& printer) {
    // Използване на принтера от pr2
    printer.inUse = true;
}

// Дефиниция на приятелската функция inuse
bool inuse(const pr1& obj1, const pr2& obj2, const Printer& printer) {
    return printer.inUse;
}

int main() {
    pr1 obj1;
    pr2 obj2;
    Printer printer;

    obj1.usePrinter(printer);

    if (inuse(obj1, obj2, printer)) {
        std::cout << "Принтерът се използва от поне един от класовете." << std::endl;
    } else {
        std::cout << "Принтерът не се използва от нито един от класовете." << std::endl;
    }

    return 0;
}
