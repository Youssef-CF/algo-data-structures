//
// Created by youssef on 1/1/21.
//
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <linkedlist.hpp>

TEST_CASE("search") {
    SECTION("search null linked list") {
        REQUIRE(search(nullptr, 7) == nullptr);
    }

    SECTION("search linked list with single element") {
        Node *n = new Node();
        n->data = 56;
        n->next = nullptr;
        REQUIRE(search(n, 56) == n);
        REQUIRE(search(n, 55) == nullptr);
    }

    SECTION("search linked list with 2 elements") {
        Node *n1 = new Node();
        n1->data = 1;
        Node *n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        REQUIRE(search(n1, 1) == n1);
        REQUIRE(search(n1, 2) == n2);
        REQUIRE(search(n1, 3) == nullptr);
    }
}

TEST_CASE("isEmpty") {
    SECTION("isEmpty empty list") {
        REQUIRE(isEmpty(nullptr));
    }

    SECTION("isEmpty list with one element") {
        Node *n = new Node();
        REQUIRE_FALSE(isEmpty(n));
    }

    SECTION("isEmpty list with two elements") {
        Node *n1 = new Node();
        n1->data = 1;
        Node *n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        REQUIRE_FALSE(isEmpty(n1));
    }
}

TEST_CASE("toString") {
    SECTION("toString empty list") {
        REQUIRE(toString(nullptr).empty());
    }

    SECTION("toString list with one element") {
        Node *n = new Node();
        REQUIRE(toString(n) == " => 0");
    }

    SECTION("toString list with two elements") {
        Node *n1 = new Node();
        n1->data = 1;
        Node *n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        REQUIRE(toString(n1) == " => 1 => 2");
    }

    SECTION("toString list with 3 elements") {
        Node *n1 = new Node();
        n1->data = 678;
        Node *n2 = new Node();
        n2->data = 23;
        Node *n3 = new Node();
        n3->data = 0;
        n1->next = n2;
        n2->next = n3;
        REQUIRE(toString(n1) == " => 678 => 23 => 0");
    }
}

TEST_CASE("insert") {
    SECTION("at the beginning") {
        char place = 'd';
        SECTION("empty list") {
            Node *result = insert(nullptr, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next == nullptr);
        }SECTION("list with one element") {
            Node *n = new Node();
            n->data = 0;
            Node *result = insert(n, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 0);
            REQUIRE(result->next->next == nullptr);
        }SECTION("list with two elements") {
            Node *n1 = new Node();
            n1->data = 1;
            Node *n2 = new Node();
            n2->data = 2;
            n1->next = n2;
            Node *result = insert(n1, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 1);
            REQUIRE(result->next->next != nullptr);
            REQUIRE(result->next->next->data == 2);
            REQUIRE(result->next->next->next == nullptr);
        }
    }SECTION("at the end") {
        char place = 'f';

        SECTION("empty list") {
            Node *result = insert(nullptr, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next == nullptr);
        }

        SECTION("list with one element") {
            Node *n = new Node();
            n->data = 0;
            Node *result = insert(n, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 0);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 7);
            REQUIRE(result->next->next == nullptr);
        }

        SECTION("list with two elements") {
            Node *n1 = new Node();
            n1->data = 1;
            Node *n2 = new Node();
            n2->data = 2;
            n1->next = n2;
            Node *result = insert(n1, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 1);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 2);
            REQUIRE(result->next->next != nullptr);
            REQUIRE(result->next->next->data == 7);
            REQUIRE(result->next->next->next == nullptr);
        }
    }
}
