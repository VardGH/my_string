#include "my_string.hpp"
#include <cstring>
#include <iostream>
#include <string>

my_string::my_string()
    : m_cap(0)
    , m_buf(nullptr)
{
}

my_string::my_string(const char* str)
{
    m_cap = strlen(str);
    m_buf = new char[m_cap + 1];
    strcpy(m_buf, str);
}

my_string::my_string(const my_string& other)
{
    m_cap = other.m_cap;
    m_buf = new char [m_cap + 1];
    strcpy(m_buf, other.m_buf);
}

my_string::my_string(my_string&& other) noexcept
    : m_cap(std::move(other.m_cap))
    , m_buf(std::move(other.m_buf))
{
    other.m_cap = 0;
    other.m_buf = nullptr;
}

my_string& my_string::operator=(const my_string& other)
{
    if (this != &other) {
        m_cap = other.m_cap;
        delete m_buf;
        m_buf = new char [m_cap + 1];
        std::strcpy(m_buf, other.m_buf);
    }
    return *this;
}

my_string& my_string::operator=(my_string&& other) noexcept
{
    if (this != &other) {
        m_cap = other.m_cap;
        delete m_buf;
        m_buf = other.m_buf;

        other.m_cap = 0;
        other.m_buf = nullptr;
    }
    return *this;
}

my_string::~my_string()
{
    delete [] m_buf;
}

char& my_string::operator[](int index)
{
    if (index > 0 && index < m_cap) {
        return m_buf[index];
    }
    throw std::out_of_range("Index out of range");
}

const char& my_string::operator[](int index) const
{
    if (index > 0 && index < m_cap) {
        return m_buf[index];
    }
    throw std::out_of_range("Index out of range");
}

my_string my_string::operator+(const my_string& other) const
{
    my_string tmp;

    tmp.m_cap = m_cap + other.m_cap;
    tmp.m_buf = new char [tmp.m_cap + 1];

    std::strcpy(tmp.m_buf, m_buf);
    std::strcat(tmp.m_buf, other.m_buf);

    return tmp;
}

const char* my_string::c_str() const
{
    return m_buf;
}

int my_string::size() const
{
    return std::strlen(m_buf);
}

my_string my_string::operator+(const std::string& str) const
{
    my_string tmp;
    
    tmp.m_cap = m_cap + str.size();
    tmp.m_buf = new char[tmp.m_cap + 1];
    std::strcpy(tmp.m_buf, m_buf);
    std::strcat(tmp.m_buf, str.c_str());

    return tmp;
}

my_string my_string::operator+(const char* str) const
{
    my_string tmp;
    
    tmp.m_cap = m_cap + std::strlen(str);
    tmp.m_buf = new char[tmp.m_cap + 1];
    std::strcpy(tmp.m_buf, m_buf);
    std::strcat(tmp.m_buf, str);

    return tmp;
}

std::ostream& operator<<(std::ostream& os, const my_string& str) {
    os << str.c_str();
    return os;
}

int my_string::get_cap() const {
    return m_cap;
}

void my_string::set_cap(const int cap) {
    if (cap <= m_cap) {
        return;
    }
    m_cap = cap;
}

my_string operator+(const char* lhs, const my_string& rhs)
{
    int len = std::strlen(lhs) + rhs.size();

    char* tmp = new char[len + 1];  
    strcpy(tmp, lhs);                   
    strcat(tmp, rhs.c_str());           

    my_string res(tmp);  

    delete[] tmp;  

    return res;
}

my_string operator+(const std::string& lhs, const my_string& rhs)
{
    int len = lhs.size() + rhs.size();

    char* tmp = new char[len + 1];  
    strcpy(tmp, lhs.c_str());                   
    strcat(tmp, rhs.c_str());           

    my_string res(tmp);  

    delete[] tmp;  

    return res;
}