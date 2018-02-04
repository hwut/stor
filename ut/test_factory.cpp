#include <functional>
#include <string.h>
#include <CppUnitLite/TestHarness.h>
#include "../utils/factory.h"

using namespace std;


class base {
public:
    base() {}
    virtual ~base() {}

    virtual int call() {}
    virtual string getName() = 0;
};

class Sub : public base {
public:
    Sub() {}

    Sub(string str)
        : name(str) {
        }

    virtual int call() {
        return 1;
    }

    virtual string getName() {
        return name;
    }

private:
    string name = "noname";
};

int factoryCall() {
    return 9527;
}

REG_MODULE(Sub, "simple");
// REG_MODULE(Sub, "complex", "huangwei");

TEST(simple, Factory) {
    base * call = Factory<Sub>::Get("simple");
    LONGS_EQUAL(call->call(), 1);

    CHECK(strcmp("noname", call->getName().c_str()) == 0);
}

class Sub2 : public base {
public:
    Sub2 (string str)
        : name(str) {}

    virtual int call() {
        return 2;
    }

    virtual string getName() {
        return name;
    }

private:
    string name = "noname";
};

REG_MODULE(Sub2, "param", "param")

TEST(param, Factory) {
    base * call = Factory<Sub2> :: Get("param");
    CHECK(call != nullptr);
    LONGS_EQUAL(call->call(), 2);

    CHECK(strcmp("param", call->getName().c_str()) == 0);
}


TEST(null, Factory) {
    base * call = Factory<Sub>::Get("null");
    CHECK_EQUAL(call, nullptr);
}
