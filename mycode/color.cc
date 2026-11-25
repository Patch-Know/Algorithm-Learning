#include<iostream>
#include<ostream>

namespace ansi {
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& red(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[31m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& black(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[30m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& green(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[32m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& yellow(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[33m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& blue(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[34m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& cyan(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[36m";
    }
    template <class CharT,class Traits> 
    constexpr std::basic_ostream<CharT, Traits>& reset(std::basic_ostream<CharT, Traits>& os) {
        return os << "\033[0m";
    }

}

int main()
{
    // std::cout << "\033[31m red \033[0m" << std::endl;
    std::cout << ansi::cyan << "这是青色!" <<ansi::reset << std::endl;

}