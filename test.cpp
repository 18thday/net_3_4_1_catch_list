#include "list.h"

#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>


TEST_CASE("Test Empty", "[empty test]") {
    SECTION("Created list is empty") {
        List list_empty;
        CHECK(list_empty.Empty() == true);
    }

    SECTION("List with 1 element") {
        List list;
        list.PushBack(5);
        CHECK(list.Empty() == false);
        list.PopBack();
        CHECK(list.Empty() == true);
    }
}

TEST_CASE("Test Size", "[size test]") {
    SECTION("Created list has size == 0") {
        List list_empty;
        CHECK(list_empty.Size() == 0);
    }

    SECTION("Increasing size after push") {
        List list;
        list.PushBack(5);
        CHECK(list.Size() == 1);

        list.PushBack(5);
        CHECK(list.Size() == 2);

        list.PushFront(5);
        CHECK(list.Size() == 3);

        list.PushBack(5);
        CHECK(list.Size() == 4);
    }

    SECTION("Decreasing size after pop") {
        List list;
        size_t expected_size = 5;
        for (int i = 0 ; i < expected_size; ++i) {
            list.PushBack(i);
        }
        CHECK(list.Size() == expected_size);

        list.PopFront();
        --expected_size;
        CHECK(list.Size() == expected_size);

        list.PopBack();
        --expected_size;
        CHECK(list.Size() == expected_size);

        for (int i = expected_size; i > 0; --i, --expected_size) {
            list.PopFront();
        }
        CHECK(list.Size() == expected_size);

        CHECK_THROWS_AS(list.PopFront(), std::runtime_error);
        CHECK_THROWS_AS(list.PopBack(), std::runtime_error);
    }
}

TEST_CASE("Test Clear", "[clear test]") {
    SECTION("Clear empty list is empty") {
        List list_empty;
        list_empty.Clear();
        CHECK(list_empty.Empty() == true);
        CHECK(list_empty.Size() == 0);
    }

    SECTION("Clear list") {
        List list;
        size_t expected_size = 5;
        for (int i = 0 ; i < expected_size; ++i) {
            list.PushBack(i);
        }
        list.Clear();
        CHECK(list.Empty() == true);
        CHECK(list.Size() == 0);
    }

    SECTION("Double Clear") {
        List list;
        size_t expected_size = 5;
        for (int i = 0 ; i < expected_size; ++i) {
            list.PushBack(i);
        }
        list.Clear();
        list.Clear();
        CHECK(list.Empty() == true);
        CHECK(list.Size() == 0);
    }
}

int main() {
    return Catch::Session().run();
}