#include <iostream>
#include <string>

#include "doctest.h"
#include "PhoneticFinder.hpp"

using namespace std;
using namespace phonetic;

TEST_CASE ("Test replacement of w and v"){
	string text = "wow very wecovifilv";
	CHECK(find(text,"wow") == string ("wow"));
	CHECK(find(text,"vov") == string ("wow"));
	CHECK(find(text,"very") == string ("very"));
	CHECK(find(text,"wery") == string ("very"));
	CHECK(find(text,"wecovifilv") == string("wecovifilv"));
	CHECK(find(text,"vecovifilv") == string("wecovifilv"));
    CHECK(find(text,"wecowifilv") == string("wecovifilv"));    
    CHECK(find(text,"vecowifilv") == string("wecovifilv"));
    CHECK(find(text,"wecovifilw") == string("wecovifilv"));
	CHECK(find(text,"wecowifilw") == string("wecovifilv"));
	CHECK(find(text,"vecowifilw") == string("wecovifilv"));
	CHECK(find(text,"vecovifilw") == string("wecovifilv"));
    }

TEST_CASE ("Test replacement of b, f and p"){
	string text = "before piber left";
	CHECK(find(text,"before") == string ("before"));
	CHECK(find(text,"fefore") == string ("before"));
	CHECK(find(text,"bebore") == string ("before"));
	CHECK(find(text,"febore") == string ("before"));
	CHECK(find(text,"piber") == string ("piber"));
	CHECK(find(text,"biber") == string ("piber"));
	CHECK(find(text,"piper") == string ("piber"));
	CHECK(find(text,"biper") == string ("piber"));
	CHECK(find(text,"left") == string ("left"));
	CHECK(find(text,"lebt") == string ("left"));
	CHECK(find(text,"lept") == string ("left"));
	}

TEST_CASE ("Test replacement of j and g"){
	string text = "jojo got pijama";
	CHECK(find(text,"jojo") == string ("jojo"));
	CHECK(find(text,"gojo") == string ("jojo"));
	CHECK(find(text,"jogo") == string ("jojo"));
	CHECK(find(text,"gogo") == string ("jojo"));
	CHECK(find(text,"got") == string ("got"));
	CHECK(find(text,"jot") == string ("got"));
	CHECK(find(text,"pijama") == string ("pijama"));
	CHECK(find(text,"pigama") == string ("pijama"));
}

TEST_CASE ("Test replacement of c, k and q"){
	string text = "cokoq talk icq";
	CHECK(find(text,"cokoq") == string ("cokoq"));
	CHECK(find(text,"kokoq") == string ("cokoq"));
	CHECK(find(text,"coqoq") == string ("cokoq"));
	CHECK(find(text,"qokoc") == string ("cokoq"));
	CHECK(find(text,"cococ") == string ("cokoq"));
	CHECK(find(text,"kokok") == string ("cokoq"));
	CHECK(find(text,"qoqoq") == string ("cokoq"));
	CHECK(find(text,"talk") == string ("talk"));
	CHECK(find(text,"talc") == string ("talk"));
	CHECK(find(text,"talq") == string ("talq"));
	CHECK(find(text,"icq") == string ("icq"));
	CHECK(find(text,"iqc") == string ("icq"));
	CHECK(find(text,"ikk") == string ("icq"));
	CHECK(find(text,"ikc") == string ("icq"));
	CHECK(find(text,"iqq") == string ("icq"));
	CHECK(find(text,"icc") == string ("icc"));
}

TEST_CASE("Test replacement of z ans s"){
	string text = "soozy saw the zoo";
	CHECK(find(text,"soozy") == string ("soozy"));
	CHECK(find(text,"soosy") == string ("soozy"));
	CHECK(find(text,"zoozy") == string ("soozy"));
	CHECK(find(text,"zoosy") == string ("soozy"));
	CHECK(find(text,"saw") == string ("saw"));
	CHECK(find(text,"zaw") == string ("saw"));
	CHECK(find(text,"zoo") == string ("zoo"));
	CHECK(find(text,"soo") == string ("zoo"));
}

TEST_CASE ("Test replacement of d and t"){
	string text = "matilda eat drakonite";
	CHECK(find(text,"matilda") == string ("matilda"));
	CHECK(find(text,"madilda") == string ("matilda"));
	CHECK(find(text,"matilta") == string ("matilda"));
	CHECK(find(text,"madilta") == string ("matilda"));
	CHECK(find(text,"eat") == string ("eat"));
	CHECK(find(text,"ead") == string ("ead"));
	CHECK(find(text,"drakinite") == string ("drakonite"));
	CHECK(find(text,"trakinite") == string ("drakonite"));
	CHECK(find(text,"drakinide") == string ("drakonite"));
	CHECK(find(text,"trakinide") == string ("drakonite"));
}

TEST_CASE ("Test replacement of o and u"){
	string text = "do you under uosif";
	CHECK(find(text,"do") == string ("do"));
	CHECK(find(text,"du") == string ("do"));
	CHECK(find(text,"you") == string ("you"));
	CHECK(find(text,"yuo") == string ("you"));
	CHECK(find(text,"yoo") == string ("you"));
	CHECK(find(text,"yuu") == string ("you"));
	CHECK(find(text,"under") == string ("under"));
	CHECK(find(text,"onder") == string ("under"));
	CHECK(find(text,"uosif") == string ("uosif"));
	CHECK(find(text,"ousif") == string ("uosif"));
	CHECK(find(text,"uusif") == string ("uosif"));
	CHECK(find(text,"oosif") == string ("uosif"));
}

TEST_CASE ("Test replacement of i and y"){
	string text = "yosi if iyog";
	CHECK(find(text,"yosi") == string ("yosi"));
	CHECK(find(text,"iosi") == string ("yosi"));
	CHECK(find(text,"yosy") == string ("yosi"));
	CHECK(find(text,"iosy") == string ("yosi"));
	CHECK(find(text,"if") == string ("if"));
	CHECK(find(text,"yf") == string ("if"));
	CHECK(find(text,"iyog") == string ("iyog"));
	CHECK(find(text,"yyog") == string ("iyog"));
	CHECK(find(text,"iiog") == string ("iyog"));
	CHECK(find(text,"yiog") == string ("iyog"));
}

TEST_CASE ("Test replacement of lowercase and uppercase letters"){
	string text = "Adam Love Apple";
	CHECK(find(text,"Adam") == string ("Adam"));
	CHECK(find(text,"adam") == string ("Adam"));
	CHECK(find(text,"ADam") == string ("Adam"));
	CHECK(find(text,"aDam") == string ("Adam"));
	CHECK(find(text,"AdAm") == string ("Adam"));
	CHECK(find(text,"aDAm") == string ("Adam"));
	CHECK(find(text,"ADAm") == string ("Adam"));
	CHECK(find(text,"AdaM") == string ("Adam"));
	CHECK(find(text,"AdAM") == string ("Adam"));
	CHECK(find(text,"aDAM") == string ("Adam"));
	CHECK(find(text,"ADAM") == string ("Adam"));
	CHECK(find(text,"Love") == string ("Love"));
	CHECK(find(text,"LOve") == string ("Love"));
	CHECK(find(text,"LOVe") == string ("Love"));
	CHECK(find(text,"LOVE") == string ("Love"));
	CHECK(find(text,"lOVE") == string ("Love"));
	CHECK(find(text,"loVE") == string ("Love"));
	CHECK(find(text,"LovE") == string ("Love"));
	CHECK(find(text,"love") == string ("Love"));
	CHECK(find(text,"Apple") == string ("Apple"));
	CHECK(find(text,"apple") == string ("Apple"));
	CHECK(find(text,"APPle") == string ("Apple"));
	CHECK(find(text,"AppLe") == string ("Apple"));
	CHECK(find(text,"ApplE") == string ("Apple"));
	CHECK(find(text,"APple") == string ("Apple"));
	CHECK(find(text,"APPLe") == string ("Apple"));
	CHECK(find(text,"APplE") == string ("Apple"));
}