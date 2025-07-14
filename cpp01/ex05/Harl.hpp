#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <map>

class Harl {
private:
    std::map<std::string, std::string> messages;
    void debug();
    void info();
    void warning();
    void error();
public:
    Harl();
    void loadMessages(const std::string& filename);
    void complain(std::string level);
};

#endif
