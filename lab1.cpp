#include <iostream>
#include <string>
#include <vector>

#1 
class Time{
    private:
        int hour;
        int minute;
        int second;

    public:
        Time(int hour, int minute, int second){
            set_time(hour,minute, second);
        }
    void set_time(int hour, int minute, int second){
            if(hour >= 0 && hour < 24 && minute >= 0 && minute < 60 && second >= 0 && second < 60){
                this->hour = hour;
                this->minute = minute;
                this->second = second;
            }else{
                std::cout<< "Невалидно време!";
            }
    }
void display_24h_format() {
        std::cout << (hour < 10 ? "0" : "") << hour << ":"
                  << (minute < 10 ? "0" : "") << minute << ":"
                  << (second < 10 ? "0" : "") << second << std::endl;
    }

    void display_12h_format() {
        std::string period = (hour >= 12) ? "PM" : "AM";
        int hour_12 = (hour > 12) ? hour - 12 : hour;
        if (hour_12 == 0) {
            hour_12 = 12;
        }

        std::cout << (hour_12 < 10 ? "0" : "") << hour_12 << ":"
                  << (minute < 10 ? "0" : "") << minute << ":"
                  << (second < 10 ? "0" : "") << second << " " << period << std::endl;
    }
};


#2
class Employee {
private:
    std::string socialSecurityNumber;
    std::string name;
    int yearsOfWorkExperience;
    std::string currentPosition;
    std::vector<double> salaries;

public:
    // Конструктор, инициализиращ социалния номер и годините трудов стаж с нулева стойност
    Employee() : yearsOfWorkExperience(0) {
        // Въвеждане на текуща длъжност от клавиатурата
        std::cout << "Въведете текуща длъжност: ";
        std::getline(std::cin, currentPosition);
    }

    // Конструктор, инициализиращ текущата длъжност с въведената стойност
    Employee(const std::string& position) : yearsOfWorkExperience(0), currentPosition(position) {}

    // Функция за задаване на стойности за член-променливите
    void setValues(const std::string& ssn, const std::string& employeeName, int experience) {
        socialSecurityNumber = ssn;
        name = employeeName;
        yearsOfWorkExperience = experience;
    }

    // Функция за получаване на текущата длъжност
    std::string getCurrentPosition() const {
        return currentPosition;
    }

    // Функция за пресмятане на средно аритметичната стойност от заплатите
    double calculateAverageSalary() const {
        if (salaries.empty()) {
            return 0.0;
        }

        double totalSalary = 0.0;
        for (double salary : salaries) {
            totalSalary += salary;
        }

        return totalSalary / salaries.size();
    }

    // Функция за намиране на минимална заплата
    double findMinSalary() const {
        if (salaries.empty()) {
            return 0.0;
        }

        double minSalary = salaries[0];
        for (double salary : salaries) {
            if (salary < minSalary) {
                minSalary = salary;
            }
        }

        return minSalary;
    }

    // Функция за добавяне на нова заплата към списъка
    void addSalary(double salary) {
        salaries.push_back(salary);
    }
};


#3
class Line {
private:
    int length;

public:
    // Конструктор с параметър за инициализация на дължината и изчертаване на линията
    Line(int len) : length(len) {
        drawLine();
    }

    // Деструктор за изтриване на линията
    ~Line() {
        std::cout << "Линия с дължина " << length << " беше изтрита." << std::endl;
    }

private:
    // Функция за изчертаване на линията
    void drawLine() const {
        for (int i = 0; i < length; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
};

int main() {

    #1
    // Създаване на обект от класа и задаване на време
    Time my_time(13, 24, 7);

    // Отпечатване на времето в два формата
    std::cout << "Време в 24-часов формат:" << std::endl;
    my_time.display_24h_format();

    std::cout << "\nВреме в 12-часов формат:" << std::endl;
    my_time.display_12h_format();



    #2
    // Създаване на обект от класа
    Employee employee;

    // Задаване на стойности за член-променливите
    employee.setValues("123-45-6789", "Иван Иванов", 5);

    // Добавяне на няколко заплати
    employee.addSalary(3000.0);
    employee.addSalary(3500.0);
    employee.addSalary(3200.0);

    // Извеждане на информация за работника
    std::cout << "Име: " << employee.getCurrentPosition() << std::endl;
    std::cout << "Текуща длъжност: " << employee.getCurrentPosition() << std::endl;
    std::cout << "Средна заплата: " << employee.calculateAverageSalary() << std::endl;
    std::cout << "Минимална заплата: " << employee.findMinSalary() << std::endl;


    #3
    // Създаване на обект от класа с дължина 10
    Line myLine(10);

    // Обектът ще бъде изтрит автоматично, когато излезе извън обхвата на main функцията
    return 0;
}

