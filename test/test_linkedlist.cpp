//
// Created by youssef on 1/1/21.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <linkedlist.hpp>

TEST_CASE( "search null linked list", "[search]" ) {
    REQUIRE( search(nullptr, 7) == nullptr );
}

TEST_CASE( "search linked list with single element", "[search]" ) {
    Node* n = new Node();
    n->data = 56;
    n->next = nullptr;
    REQUIRE( search(n, 56) == n );
    REQUIRE( search(n, 55) == nullptr );
}

TEST_CASE( "search linked list with 2 elements", "[search]" ) {
    Node* n1 = new Node(); n1->data = 1;
    Node* n2 = new Node(); n2->data = 2;
    n1->next = n2;
    REQUIRE( search(n1, 1) == n1 );
    REQUIRE( search(n1, 2) == n2 );
    REQUIRE( search(n1, 3) == nullptr );
}

TEST_CASE("isEmpty empty list", "[isEmpty]") {
    REQUIRE( isEmpty(nullptr) );
}

TEST_CASE("isEmpty list with one element", "[isEmpty]") {
    Node* n = new Node();
    REQUIRE_FALSE( isEmpty(n) );
}

TEST_CASE("isEmpty list with two elements", "[isEmpty]") {
    Node* n1 = new Node();n1->data = 1;
    Node* n2 = new Node();n2->data = 2;
    n1->next = n2;
    REQUIRE_FALSE( isEmpty(n1) );
}



