/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: sapir peled
 * 
 * Date: 2020-02
 */

#include "doctest.h"
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));  
}

TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HapPI") == string("Happi"));
    CHECK(find(text, "haPpI") == string("Happi"));
    CHECK(find(text, "HAPpI") == string("Happi"));
    CHECK(find(text, "HaPpi") == string("Happi"));
    CHECK(find(text, "HApPi") == string("Happi"));
    CHECK(find(text, "hAPPI") == string("Happi"));
    CHECK(find(text, "HAPpi") == string("Happi"));
}

TEST_CASE("Test replacement of p and f") {
    string text = "xxx happy yyy";
    CHECK(find(text, "hafpy") == string("happy"));
    CHECK(find(text, "hapfy") == string("happy"));
    CHECK(find(text, "haffy") == string("happy"));
}

TEST_CASE("Test replacement of b and f") {
    string text = "flay xxx baby yyy";
    CHECK(find(text, "flay") == string("flay"));
    CHECK(find(text, "blay") == string("flay"));
    CHECK(find(text, "Blay") == string("flay"));
    CHECK(find(text, "baby") == string("baby"));
    CHECK(find(text, "faby") == string("baby"));
    CHECK(find(text, "bafy") == string("baby"));
    CHECK(find(text, "fafy") == string("baby"));
    CHECK(find(text, "faFy") == string("baby"));
    CHECK(find(text, "Faby") == string("baby"));
}

TEST_CASE("Test replacement of y and i") {
    string text = "xxx happy yyy";
    CHECK(find(text, "hafpi") == string("happy"));
    CHECK(find(text, "hafpI") == string("happy"));
    CHECK(find(text, "iii") == string("yyy"));
    CHECK(find(text, "iyy") == string("yyy"));
    CHECK(find(text, "iyi") == string("yyy"));
    CHECK(find(text, "yyi") == string("yyy"));
    CHECK(find(text, "yiy") == string("yyy"));
    CHECK(find(text, "yIy") == string("yyy"));
    CHECK(find(text, "yyy") == string("yyy"));
}

TEST_CASE("Test replacement of o and u") {
    string text = "doo forget";
    CHECK(find(text, "doo") == string("doo"));
    CHECK(find(text, "duo") == string("doo"));
    CHECK(find(text, "dou") == string("doo"));
    CHECK(find(text, "duu") == string("doo"));
    CHECK(find(text, "furget") == string("forget"));
}

TEST_CASE("Test replacement of d and t") {
    string text = "tedy daddy ";
    CHECK(find(text, "dedy") == string("tedy"));
    CHECK(find(text, "tety") == string("tedy"));
    CHECK(find(text, "dety") == string("tedy"));
    CHECK(find(text, "datty") == string("daddy"));
    CHECK(find(text, "detdy") == string("daddy"));
    CHECK(find(text, "dadty") == string("daddy"));
    CHECK(find(text, "tatty") == string("daddy"));
    CHECK(find(text, "tetdy") == string("daddy"));
    CHECK(find(text, "tadty") == string("daddy"));

}

TEST_CASE("Test replacement of s and z") {
    string text = "snozz uuu ";
    CHECK(find(text, "snozz") == string("snozz"));
    CHECK(find(text, "znozz") == string("snozz"));
    CHECK(find(text, "znoss") == string("snozz"));
    CHECK(find(text, "snozs") == string("snozs"));
    CHECK(find(text, "snoss") == string("snozz"));
    CHECK(find(text, "snosz") == string("snozs"));
    CHECK(find(text, "znozs") == string("snozz"));
    CHECK(find(text, "znosz") == string("snozs"));
    CHECK(find(text, "Znoss") == string("snozz"));
    CHECK(find(text, "snozS") == string("snozs"));
}

TEST_CASE("Test replacement of c and k and q") {
    string text = "cokky q ";
    CHECK(find(text, "qokky") == string("cokky"));
    CHECK(find(text, "koccy") == string("cokky"));
    CHECK(find(text, "coqky") == string("cokky"));
    CHECK(find(text, "cocqy") == string("cokky"));
    CHECK(find(text, "koqqy") == string("cokky"));
    CHECK(find(text, "kocqy") == string("cokky"));
    CHECK(find(text, "Kocqy") == string("cokky"));
    CHECK(find(text, "Qocqy") == string("cokky"));
    CHECK(find(text, "qoccy") == string("cokky"));
    CHECK(find(text, "qoqqy") == string("cokky"));
    CHECK(find(text, "k") == string("q"));
    CHECK(find(text, "c") == string("q"));
}

TEST_CASE("Test replacement of g and j") {
    string text = "google ";
    CHECK(find(text, "goojle") == string("google"));
    CHECK(find(text, "joojle") == string("google"));
    CHECK(find(text, "joogle") == string("google"));
    CHECK(find(text, "google") == string("google"));
    CHECK(find(text, "JooJle") == string("google"));
    CHECK(find(text, "Joogle") == string("google"));
    CHECK(find(text, "gooJle") == string("google"));
}

TEST_CASE("Test replacement of v and w") {
    string text = "Volkswagen ";
    CHECK(find(text, "Volkswagen") == string("Volkswagen"));
    CHECK(find(text, "wolkswagen") == string("Volkswagen"));
    CHECK(find(text, "Volksvagen") == string("Volkswagen"));
    CHECK(find(text, "Wolkswagen") == string("Volkswagen"));
    CHECK(find(text, "wolksVagen") == string("Volkswagen"));
    CHECK(find(text, "volksVagen") == string("Volkswagen"));
    CHECK(find(text, "volkswagen") == string("Volkswagen"));
}

TEST_CASE("Test take the first word") {
    string text = "send to send to ";
    CHECK(find(text, "send") == string("send"));
    CHECK(find(text, "zend") == string("send"));
    CHECK(find(text, "zent") == string("send"));
    CHECK(find(text, "sent") == string("send"));
    CHECK(find(text, "tu") == string("to"));
    CHECK(find(text, "to") == string("to"));
}

TEST_CASE("Test replacement from two groups or more") {
    string text = "dont worry be happy ";
    CHECK(find(text, "vorri") == string("worry"));
    CHECK(find(text, "wurry") == string("worry"));
    CHECK(find(text, "vurri") == string("worry"));
    CHECK(find(text, "Dond") == string("dont"));
    CHECK(find(text, "tund") == string("dont"));
    CHECK(find(text, "tunt") == string("dont"));
    CHECK(find(text, "hafbi") == string("happy"));
}

TEST_CASE("the word not in the text") {
     string text = "tedy";
    CHECK_THROWS(find(text, "xxx"));  // check that some exception is thrown
    CHECK_THROWS(find(text, "tddy"));
    CHECK_THROWS(find(text, "tady"));
}

TEST_CASE("look for empty word") {
     string text = "tedy";
    CHECK_THROWS(find(text, ""));  // check that some exception is thrown
    CHECK_THROWS(find(text, " "));
}