#include <iostream>
#include <string>

using namespace std;

class SportGame {
protected:
    string name;
    int players;

public:
    SportGame() : name("Unknown"), players(0) {}
    SportGame(string n, int p) : name(std::move(n)), players(p) {}

    SportGame(const SportGame& other) : name(other.name), players(other.players) {
        cout << "Copy constructor SportGame" << endl;
    }

    SportGame(SportGame&& other) noexcept : name(std::move(other.name)), players(other.players) {
        cout << "Move constructor SportGame" << endl;
    }

    SportGame& operator=(const SportGame& other) {
        cout << "Copy assignment SportGame" << endl;
        if (this != &other) {
            name = other.name;
            players = other.players;
        }
        return *this;
    }

    SportGame& operator=(SportGame&& other) noexcept {
        cout << "Move assignment SportGame" << endl;
        if (this != &other) {
            name = std::move(other.name);
            players = other.players;
        }
        return *this;
    }

    virtual ~SportGame() = default;

    virtual void print(ostream& os) const {
        os << "Game: " << name << ", Players: " << players;
    }

    virtual void read(istream& is) {
        cout << "Enter game name and number of players: ";
        is >> name >> players;
    }

    friend ostream& operator<<(ostream& os, const SportGame& game);
    friend istream& operator>>(istream& is, SportGame& game);
};

class Football : public SportGame {
private:
    string league;

public:
    Football() : SportGame(), league("Unknown League") {}
    Football(string n, int p, string l)
        : SportGame(std::move(n), p), league(std::move(l)) {}

    Football(const Football& other)
        : SportGame(other), league(other.league) {
        cout << "Copy constructor Football" << endl;
    }

    Football(Football&& other) noexcept
        : SportGame(std::move(other)), league(std::move(other.league)) {
        cout << "Move constructor Football" << endl;
    }

    Football& operator=(const Football& other) {
        cout << "Copy assignment Football" << endl;
        if (this != &other) {
            SportGame::operator=(other);
            league = other.league;
        }
        return *this;
    }

    Football& operator=(Football&& other) noexcept {
        cout << "Move assignment Football" << endl;
        if (this != &other) {
            SportGame::operator=(std::move(other));
            league = std::move(other.league);
        }
        return *this;
    }

    void print(ostream& os) const override {
        SportGame::print(os);
        os << ", League: " << league;
    }

    void read(istream& is) override {
        SportGame::read(is);
        cout << "Enter league: ";
        is >> league;
    }

    friend ostream& operator<<(ostream& os, const Football& f);
    friend istream& operator>>(istream& is, Football& f);
};

// Оператори поза класом
ostream& operator<<(ostream& os, const SportGame& game) {
    game.print(os);
    return os;
}

istream& operator>>(istream& is, SportGame& game) {
    game.read(is);
    return is;
}

ostream& operator<<(ostream& os, const Football& f) {
    f.print(os);
    return os;
}

istream& operator>>(istream& is, Football& f) {
    f.read(is);
    return is;
}

int main() {
    Football f1("Football", 11, "Premier League");
    cout << f1 << endl;

    Football f2 = f1; // копіювання
    cout << f2 << endl;

    Football f3;
    f3 = std::move(f1); // перенесення
    cout << f3 << endl;

    Football f4;
    cin >> f4;
    cout << f4 << endl;

    return 0;
}
