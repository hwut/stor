#include "string.h"
#include "iostream"
#include "CppUnitLite/TestHarness.h"
#include "../utils/simple_string.h"

TEST(simple, simple_string) {
    SimpleStr str("test");
    CHECK(strcmp("test", str.toChar()) == 0);

    SimpleStr other(str);
    CHECK(strcmp("test", other.toChar()) == 0);

    SimpleStr three = StrFrom("test");
    std::cout << three.toChar() << std::endl;

    CHECK(strcmp("test", three.toChar()) == 0);
}
