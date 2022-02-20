#include <iostream>
#include <vector>
#include <string>
#include <initializer_list>



class Person {
public:
    Person(std::string first_name, std::string last_name,
                                std::string phone_number) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->phone_number = phone_number;
    };
    ~Person() {};
    std::string first_name;
    std::string last_name;
    std::string phone_number;
    std::string get_first_name() const {
        return this->first_name;
    }
    std::string get_last_name() const {
        return this->last_name;
    }
    std::string get_phone_number() const {
        return this->phone_number;
    }
};

bool operator < (Person p1, Person p2) {
    return p1.get_last_name() < p2.get_last_name();
}

class Phone_book {
public:
    Phone_book(std::initializer_list<Person> args) {
        for (auto& arg: args) {
            this->container.push_back(arg);
        }
        this->n = this->container.size();
    };
    ~Phone_book() {};
    std::vector <Person> container;
    int n;
    void show_book() const { // Первый пункт упражнения
        std::vector <Person> tmp_book = this->container;
        std::sort(tmp_book.begin(), tmp_book.end());
        for (Person& p: tmp_book){
            std::cout << p.get_last_name() << " " << p.get_first_name() << " " << p.get_phone_number() << std::endl;
        }
    }
    void get_entry(int k) { // Второй пункт упражнения
        if (k > n) {
            std::cout << "OUT OF PHONE BOOK RANGE" << std::endl;
            return;
        }
        std::cout << "First name: " << this->container[k-1].get_first_name() << std::endl;
        std::cout << "Last name: " << this->container[k-1].get_last_name() << std::endl;
        std::cout << "Phone number: " << this->container[k-1].get_phone_number() << std::endl;
        return;
    }

    void find(std::string l_name) { // Третий пункт
        for (Person& p: this->container) {
            if (p.get_last_name() == l_name) {
                std::cout << "First name: " << p.get_first_name() << std::endl;
                std::cout << "Last name: " <<  p.get_last_name() << std::endl;
                std::cout << "Phone number: " << p.get_phone_number() << std::endl;
                return;
            }
        }
        std::cout << l_name << " NOT FOUND" << std::endl;
        return;
    }

};

int main() {
    Phone_book thbook{Person("Ushat", "Pomoev", "1111"), // Создаем справочник
                                   Person("Podriv", "Ustoev", "2222"),
                                   Person("Record", "Nadoev", "3333"),
                                   Person("Otryad", "Covboev", "4444"),
                                   Person("Kamaz", "Othodov", "5555"),
                                   Person("Barak", "Mongolov", "6666"),
                                   Person("Tridnya", "Zapoev", "7777"),
                                   Person("Egor", "Vasenin", "8888")};

    thbook.show_book(); // Первое упражнение
    std::cout << std::endl;
    thbook.get_entry(3); // Второе упражнение
    std::cout << std::endl;
    thbook.get_entry(4);
    std::cout << std::endl;
    thbook.get_entry(2);
    std::cout << std::endl;
    thbook.find("Vasenin"); // Третье упражнение
    std::cout << std::endl;
    thbook.find("Noname");
    return 0;
}
