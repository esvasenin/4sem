#include <iostream>
#include <chrono>
#include <cmath>

using namespace std::chrono;

class Timer {
public:
    steady_clock::time_point start;
    int time = 0;
    Timer() {

    }
    ~Timer() {}

    void pause (){
        time += duration_cast<std::chrono::seconds>
                (steady_clock::now() - start).count();
        std::cout << time << std::endl;
    };

    void show (){
        std::cout <<
                  duration_cast<std::chrono::seconds>(steady_clock::now() - start).count() + time
                  << std::endl;
    }


    void begin (){
        start = steady_clock::now();
    }



};

int main() {
    Timer timer;
    std::string s;
    std::cin >> s;
    while (s!= "end") {
        if (s == "start")
            timer.begin();
        if (s == "show")
            timer.show();
        if (s == "pause")
            timer.pause();
        std::cin >> s;
    }

    return 0;
}