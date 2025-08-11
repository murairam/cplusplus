#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <map>

class Harl {
    private:
        void debug();
        void info();
        void warning();
        void error();
    public:
        Harl();
        ~Harl();
        void harlFilter(std::string level);
        void complain(std::string level);
};

#endif
