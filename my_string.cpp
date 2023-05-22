#include "my_string.hpp"

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
        m_baf = new char [m_cap + 1];
        strcpy(m_baf, other.m_baf);
    }
    return *this;
}

my_string& my_string::operator=(my_string&& other) noexcept
{
    if (this != &other) {
        m_cap = other.m_cap;
        delete m_baf;
        m_baf = other.m_baf;

        other.m_cap = 0;
        other.m_buf = nullptr;
    }
    return *this;
}

my_string::~my_string()
{
    delete [] m_baf;
}

char& my_string::operator[](int index)
{
    if (index > 0 && index < m_cap) {
        return m_baf[index];
    }
    throw std::out_of_range("Index out of range");
}

const char& my_string::operator[](int index) const
{
    if (index > 0 && index < m_cap) {
        return m_baf[index];
    }
    throw std::out_of_range("Index out of range");
}

my_string& my_string::operator+(const my_string& other) const
{
    my_string tmp;

    tmp.m_cap = m_cap + other.m_cap;
    tmp.m_baf = new char [tmp.m_cap + 1];

    strcpy(tmp.m_baf, m_baf);
    strcpy(tmp.m_baf, other.m_baf);

    return tmp;

}

const char* my_string::c_str() const
{
    return m_baf;
}
