#include <iostream>
#include <string>
using namespace std;

// Клас Кімната
class Room {
private:
    double area;  

public:
    Room(double a = 0) : area(a) {}

    double getArea() const {
        return area;
    }

    void setArea(double a) {
        area = a;
    }
};

// Клас Однокімнатна Квартира
class OneRoomApartment {
protected:
    Room room;         
    double kitchenArea; 
    int floor;         

public:
    OneRoomApartment(double roomArea = 0, double kitchen = 0, int fl = 0)
        : room(roomArea), kitchenArea(kitchen), floor(fl) {}

    double getRoomArea() const {
        return room.getArea();
    }

    double getKitchenArea() const {
        return kitchenArea;
    }

    int getFloor() const {
        return floor;
    }

    void setRoomArea(double a) {
        room.setArea(a);
    }

    void setKitchenArea(double a) {
        kitchenArea = a;
    }

    void setFloor(int f) {
        floor = f;
    }
};

// Похідний клас: Однокімнатна квартира в місті
class CityOneRoomApartment : public OneRoomApartment {
private:
    string city;

public:
    CityOneRoomApartment(double roomArea = 0, double kitchen = 0, int fl = 0, const string& c = "")
        : OneRoomApartment(roomArea, kitchen, fl), city(c) {}

    ~CityOneRoomApartment() {
        cout << "Деструктор викликаний для квартири в місті: " << city << endl;
    }

    void print() const {
        cout << "Місто: " << city << endl;
        cout << "Площа кімнати: " << getRoomArea() << " м²" << endl;
        cout << "Площа кухні: " << getKitchenArea() << " м²" << endl;
        cout << "Поверх: " << getFloor() << endl;
    }
};

int main() {
    CityOneRoomApartment apt(18.5, 6.2, 3, "Київ");
    apt.print();

    return 0;
}
