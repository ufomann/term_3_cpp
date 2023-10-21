#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <iomanip>
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))

struct ProgBar final {
    ProgBar (int width = 100) :  width(width) { }
    void operator() (int perc) {
        int cnt = width * perc / 100;
        std::string s = "";
        while (cnt--){
            s += '#';
        }
        std::cout << '\r';
        std::cout << '[' << std::setw(width) << std::setfill('.') << std::left << s << std::flush << ']';
        std::cout << std::setw(5) << std::right << std::setfill(' ') << perc << '%' << std::flush;
    }
    int width;
};

int main(){
    ProgBar a(20);
    // float vel1 = 0.2, vel2 = 1, vel3 = 0.1;
    // float curr = 0.;
    // while(true) {
    //     a(curr);
    //     sleep(100);
    //     if (curr < 20)
    //         curr += vel1;
    //     else if (curr < 90)
    //         curr += vel2;
    //     else
    //         curr += vel3;
    //     if (curr > 100){
    //         curr = 100;
    //         break;
    //     }
    // }
    // a(curr);
    return 0;
}