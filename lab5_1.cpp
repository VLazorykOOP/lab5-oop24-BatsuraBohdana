#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
    string lastName;
    string firstName;
    string patronymic;
    int course;
    string idNumber;

public:
    Student() : lastName(""), firstName(""), patronymic(""), course(0), idNumber("000000") {}

    // Конструктор з параметрами
    Student(string ln, string fn, string pn, int c, string id)
        : lastName(ln), firstName(fn), patronymic(pn), course(c), idNumber(id) {}

    virtual ~Student() {
        cout << "Видалення об'єкта Student\n";
    }

    virtual void print() const {
        cout << "Студент: " << lastName << " " << firstName << " " << patronymic << endl;
        cout << "Курс: " << course << ", ІД: " << idNumber << endl;
    }
};

class GraduateStudent : public Student {
private:
    string diplomaTopic;

public:
    GraduateStudent() : Student(), diplomaTopic("Невідома тема") {}

    // Конструктор з усіма параметрами
    GraduateStudent(string ln, string fn, string pn, int c, string id, string topic)
        : Student(ln, fn, pn, c, id), diplomaTopic(topic) {}

    // Конструктор лише з темою диплома
    GraduateStudent(string topic) : Student(), diplomaTopic(topic) {}

    ~GraduateStudent() {
        cout << "Видалення об'єкта GraduateStudent\n";
    }

    void print() const override {
        Student::print();
        cout << "Тема диплома: " << diplomaTopic << endl;
    }

    // Заміна ідентифікаційного номера
    void setID(string newID) {
        idNumber = newID;
    }

    // Заміна теми диплома
    void setDiplomaTopic(string newTopic) {
        diplomaTopic = newTopic;
    }
};

int main() {
    cout << "=== Тестування Student ===\n";
    Student s1("Іваненко", "Іван", "Іванович", 2, "123456");
    s1.print();

    cout << "\n=== Тестування GraduateStudent (повний конструктор) ===\n";
    GraduateStudent g1("Петренко", "Петро", "Петрович", 4, "654321", "Штучний інтелект");
    g1.print();

    cout << "\n=== Тестування GraduateStudent (тільки тема диплома) ===\n";
    GraduateStudent g2("Квантові обчислення");
    g2.print();

    cout << "\n=== Заміна теми диплома та ID ===\n";
    g1.setDiplomaTopic("Комп'ютерний зір");
    g1.setID("777888");
    g1.print();

    return 0;
}
