#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "simple_string.h"

const int DEFAULT_SIZE = 20;

SimpleStr::SimpleStr() {
    buf = new char [1];
    buf[0] = '\0';
}

SimpleStr::SimpleStr(const char * val) {
    buf = new char[strlen(val) + 1];
    strcpy(buf, val);
}

SimpleStr::SimpleStr(const SimpleStr& other) {
    buf = new char [strlen(other.buf) + 1];
    strcpy(buf, other.buf);
}

SimpleStr::SimpleStr(SimpleStr && other) {
    buf = other.buf;
    other.buf = nullptr;
}

SimpleStr & SimpleStr::operator= (const SimpleStr & other) {
    delete [] buf;
    buf = new char [strlen(other.buf) + 1];
    strcpy(buf, other.buf);

    return *this;
}

SimpleStr::~SimpleStr() {
    if (buf != nullptr) {
        delete [] buf;
    }
}

int SimpleStr::size() {
    return static_cast<int>(strlen(buf));
}

char * SimpleStr::toChar() {
    return buf;
}

bool operator==(const SimpleStr &l, const SimpleStr &r) {
    return !strcmp(l.buf, r.buf);
}

SimpleStr StrFrom(bool val) {
    char buf[DEFAULT_SIZE];
    sprintf(buf, "%s", val ? "true" : "false");
    return SimpleStr((const char *)buf);
}

SimpleStr StrFrom(int val) {
    char buf[DEFAULT_SIZE];
    sprintf(buf, "%d", val);
    return SimpleStr((const char *)buf);
}

SimpleStr StrFrom(const char * val) {
    return SimpleStr(val);
}

SimpleStr StrFrom(long val) {
    char buf[DEFAULT_SIZE];
    sprintf(buf, "%ld", val);
    return SimpleStr((const char *)buf);
}

SimpleStr StrFrom(double val) {
    char buf[DEFAULT_SIZE];
    sprintf(buf, "%lf", val);
    return SimpleStr((const char *)buf);
}
