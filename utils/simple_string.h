#pragma once

class SimpleStr {
    friend bool operator==(const SimpleStr &l, const SimpleStr &r);

public:
    SimpleStr();

    SimpleStr(const char * val);

    SimpleStr(const SimpleStr & other);

    SimpleStr(SimpleStr && other);

    ~SimpleStr();

    int size();

    char * toChar();

    SimpleStr & operator= (const SimpleStr & other);

private:
    char * buf;
};

SimpleStr StrFrom(bool val);
SimpleStr StrFrom(int val);
SimpleStr StrFrom(long val);
SimpleStr StrFrom(double val);
SimpleStr StrFrom(const char *val);
