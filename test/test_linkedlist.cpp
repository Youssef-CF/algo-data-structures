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
        Node* n = new Node();
        n->data = 56;
        n->next = nullptr;
        REQUIRE(search(n, 56) == n);
        REQUIRE(search(n, 55) == nullptr);
    }

    SECTION("search linked list with 2 elements") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
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
        Node* n = new Node();
        REQUIRE_FALSE(isEmpty(n));
    }

    SECTION("isEmpty list with two elements") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
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
        Node* n = new Node();
        REQUIRE(toString(n) == " => 0");
    }

    SECTION("toString list with two elements") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        REQUIRE(toString(n1) == " => 1 => 2");
    }

    SECTION("toString list with 3 elements") {
        Node* n1 = new Node();
        n1->data = 678;
        Node* n2 = new Node();
        n2->data = 23;
        Node* n3 = new Node();
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
            Node* result = insert(nullptr, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next == nullptr);
        }SECTION("list with one element") {
            Node* n = new Node();
            n->data = 0;
            Node* result = insert(n, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 0);
            REQUIRE(result->next->next == nullptr);
        }SECTION("list with two elements") {
            Node* n1 = new Node();
            n1->data = 1;
            Node* n2 = new Node();
            n2->data = 2;
            n1->next = n2;
            Node* result = insert(n1, 7, place);
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
            Node* result = insert(nullptr, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 7);
            REQUIRE(result->next == nullptr);
        }

        SECTION("list with one element") {
            Node* n = new Node();
            n->data = 0;
            Node* result = insert(n, 7, place);
            REQUIRE(result != nullptr);
            REQUIRE(result->data == 0);
            REQUIRE(result->next != nullptr);
            REQUIRE(result->next->data == 7);
            REQUIRE(result->next->next == nullptr);
        }

        SECTION("list with two elements") {
            Node* n1 = new Node();
            n1->data = 1;
            Node* n2 = new Node();
            n2->data = 2;
            n1->next = n2;
            Node* result = insert(n1, 7, place);
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

TEST_CASE("remove") {
    SECTION("remove from empty list") {
        REQUIRE(remove(nullptr, 7) == nullptr);
    }

    SECTION("remove from single element list") {
        Node* n = new Node();
        Node* r1 = remove(n, 78);
        REQUIRE(r1->data == 0);
        REQUIRE(r1->next == nullptr);

        Node* r2 = remove(n, 0);
        REQUIRE(r2 == nullptr);
    }

    SECTION("remove from 2 elements list") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        SECTION("remove non existing value") {
            Node* r = remove(n1, 7);
            REQUIRE(r->data == 1);
            REQUIRE(r->next != nullptr);
            REQUIRE(r->next->data == 2);
            REQUIRE(r->next->next == nullptr);
        }SECTION("remove last element") {
            Node* r = remove(n1, 2);
            REQUIRE(r->data == 1);
            REQUIRE(r->next == nullptr);
        }SECTION("remove first element") {
            Node* r = remove(n1, 1);
            REQUIRE(r->data == 2);
            REQUIRE(r->next == nullptr);
        }
    }

    SECTION("remove from 3 elements list") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 2;
        Node* n3 = new Node();
        n3->data = 3;
        n1->next = n2;
        n2->next = n3;
        SECTION("remove non existing value") {
            Node* r = remove(n1, 7);
            REQUIRE(r->data == 1);
            REQUIRE(r->next != nullptr);
            REQUIRE(r->next->data == 2);
            REQUIRE(r->next->next != nullptr);
            REQUIRE(r->next->next->data == 3);
            REQUIRE(r->next->next->next == nullptr);
        }SECTION("remove last element") {
            Node* r = remove(n1, 3);
            REQUIRE(r->data == 1);
            REQUIRE(r->next != nullptr);
            REQUIRE(r->next->data == 2);
            REQUIRE(r->next->next == nullptr);
        }SECTION("remove first element") {
            Node* r = remove(n1, 1);
            REQUIRE(r->data == 2);
            REQUIRE(r->next != nullptr);
            REQUIRE(r->next->data == 3);
            REQUIRE(r->next->next == nullptr);
        }SECTION("remove middle element") {
            Node* r = remove(n1, 2);
            REQUIRE(r->data == 1);
            REQUIRE(r->next != nullptr);
            REQUIRE(r->next->data == 3);
            REQUIRE(r->next->next == nullptr);
        }
    }
}

TEST_CASE("occurrence") {
    SECTION("occurrence for empty list") {
        REQUIRE(occurrence(nullptr, 6) == 0);
    }

    SECTION("occurrence for single element list") {
        Node* n = new Node();
        n->data = 56;
        REQUIRE(occurrence(n, 32) == 0);
        REQUIRE(occurrence(n, 56) == 1);
    }

    SECTION("occurrence for list with 2 distinct elements") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        REQUIRE(occurrence(n1, 1) == 1);
        REQUIRE(occurrence(n1, 2) == 1);
        REQUIRE(occurrence(n1, 3) == 0);
    }

    SECTION("occurrence for list with 2 duplicate elements") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 1;
        n1->next = n2;
        REQUIRE(occurrence(n1, 1) == 2);
        REQUIRE(occurrence(n1, 2) == 0);
    }

    SECTION("occurrence for list with 3 elements with 2 duplicates") {
        Node* n1 = new Node();
        n1->data = 1;
        Node* n2 = new Node();
        n2->data = 2;
        n1->next = n2;
        Node* n3 = new Node();
        n3->data = 2;
        n1->next = n2;
        n2->next = n3;
        REQUIRE(occurrence(n1, 1) == 1);
        REQUIRE(occurrence(n1, 2) == 2);
        REQUIRE(occurrence(n1, 3) == 0);
    }

    SECTION("occurrence for list with 10 elements") {
        int values [10] = { 1, 1, 5, 4, 9, 8, 8, 8, 4, 8 };
        Node* n;
        for (int i = 9; i > -1; --i) {
            Node* newNode = new Node();
            newNode->data = values[i];
            newNode->next = n;
            n = newNode;
        }

        REQUIRE(occurrence(n, 1) == 2);
        REQUIRE(occurrence(n, 5) == 1);
        REQUIRE(occurrence(n, 4) == 2);
        REQUIRE(occurrence(n, 9) == 1);
        REQUIRE(occurrence(n, 8) == 4);
        REQUIRE(occurrence(n, 3) == 0);
    }

}