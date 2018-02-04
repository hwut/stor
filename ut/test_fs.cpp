#include <CppUnitLite/TestHarness.h>
#include  "../utils/factory.h"
#include "../local/fs/fs.h"

TEST(fs, simple) {
    StorDrv * drv = Factory<storFs>::Get("fs");
    CHECK(drv != nullptr)
}

