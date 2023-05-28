#ifndef MY_STRIING_HPP
#define MY_STRIING_HPP

#include <string>

class my_string
{
public:
    my_string();
    my_string(const char* str);
    my_string(const my_string& other);
    my_string(my_string&& other) noexcept;
    my_string& operator=(const my_string& other);
    my_string& operator=(my_string&&) noexcept;
    ~my_string();

public:
    char& operator[](int index);
    const char& operator[](int index) const;
    my_string operator+(const my_string& other) const;
    my_string operator+(const std::string& str) const;
    my_string operator+(const char* str) const;

public:
    const char* c_str() const;
    int size() const;
    int get_cap() const;
    void set_cap(const int cap);

private:
    int m_cap;
    char* m_buf;
};


my_string operator+(const char* lhs, const my_string& rhs);
my_string operator+(const std::string& lhs, const my_string& rhs);
std::ostream& operator<<(std::ostream& os, const my_string& str);

#endif // MY_STRIING_HPP