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
    friend std::ostream& operator<<(std::ostream&, const my_string&);

public:
    const char* c_str() const;
    int size() const;

private:
    int m_cap;
    char* m_buf;
};

#endif // MY_STRIING_HPP