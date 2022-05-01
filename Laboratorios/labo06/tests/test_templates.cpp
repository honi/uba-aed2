#include "gtest/gtest.h"
#include <string>
#include <vector>
#include "../src/Templates.hpp"

using namespace std;

#if EJ>=1

TEST(Templates, cuadrado) {
  EXPECT_EQ(cuadrado(5), 25);
  EXPECT_EQ(cuadrado(10), 100);
  EXPECT_EQ(cuadrado(1), 1);

  EXPECT_EQ(cuadrado(5.0), 25);
  EXPECT_EQ(cuadrado(10.5), 110.25);
  EXPECT_EQ(cuadrado(1.5), 2.25);
}

#endif

#if EJ>=2

TEST(Templates, contiene) {
  EXPECT_TRUE(contiene(string("Hola todos"), 't'));
  EXPECT_TRUE(contiene(string("Hola todos"), 'H'));
  EXPECT_TRUE(contiene(string("Hola todos"), ' '));
  EXPECT_FALSE(contiene(string("Hola todos"), 'h'));
  
  EXPECT_TRUE(contiene(vector<int>({1, 2, 3}), 3));
  EXPECT_FALSE(contiene(vector<int>({1, 2, 3}), 4));
  EXPECT_TRUE(contiene(vector<char>({'h', 'o', 'l', 'a'}), 'o'));
  EXPECT_FALSE(contiene(vector<char>({'h', 'o', 'l', 'a'}), ' '));
}

#endif

#if EJ>=3

TEST(Templates, esPrefijo) {
  EXPECT_TRUE(esPrefijo(string("Hola"), string("Hola mundo")));
  EXPECT_TRUE(esPrefijo(string("Hol"), string("Hola")));
  EXPECT_FALSE(esPrefijo(string("hol"), string("Hola")));
  EXPECT_FALSE(esPrefijo(string("hol"), string("ho")));

  EXPECT_TRUE(esPrefijo(vector<int>({1, 2, 3}), vector<int>({1, 2, 3, 4})));
  EXPECT_TRUE(esPrefijo(vector<int>({1, 2}), vector<int>({1, 2, 3, 4})));
  EXPECT_FALSE(esPrefijo(vector<int>({0, 2}), vector<int>({1, 2, 3, 4})));
  EXPECT_FALSE(esPrefijo(vector<int>({0, 2, 5}), vector<int>({0, 2})));
}

#endif

#if EJ>=4

TEST(Templates, maximo) {
  EXPECT_EQ((maximo<string, char>(string("Hola"))), 'o');
  EXPECT_EQ((maximo<string, char>(string("HOla"))), 'l');
  EXPECT_EQ((maximo<string, char>(string("hOLA"))), 'h');

  EXPECT_EQ((maximo<vector<int>, int>(vector<int>({1, 2, 3}))), 3);
  EXPECT_EQ((maximo<vector<int>, int>(vector<int>({1, 5, 3}))), 5);
  EXPECT_EQ((maximo<vector<int>, int>(vector<int>({1, 0, 0}))), 1);
}

#endif
