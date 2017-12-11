#include <gmock/gmock.h>
#include "http_getter.hh"

using ::testing::Eq;

TEST(HttpGetterTest, CanBeConstructed) {
    HttpGetter *getter = new QtHttpGetter;
    ASSERT_THAT(2+2, Eq(4));
}

