#include "gtest-1.8.1/gtest.h"
#include "funciones.cpp"

#include <set>

set<int> v2s(vector<int> v) {
  set<int> ret;
  for (int x : v) {
    ret.insert(x);
  }
  return ret;
}

bool misma_cantidad_de_apariciones(vector<int> vector1, vector<int> vector2);

void test_ej1(vector<int> (*qr)(vector<int>)) {
  EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>()),vector<int>()));
  EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 1, 1, 1})),vector<int>({1})));
  EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 2, 2, 3, 3})),vector<int>({1,2,3})));
  EXPECT_TRUE(misma_cantidad_de_apariciones((*qr)(vector<int>({1, 1, 2, 3, 3})),vector<int>({1,2,3})));
}

unsigned int cantidad_apariciones(int i, vector<int> v) {
    unsigned int resultado = 0;
    for (int n : v) {
        if (i==n) {
            resultado ++;
        }
    }
    return resultado;
}

bool misma_cantidad_de_apariciones(vector<int> vector1, vector<int> vector2) {
    for (int n : vector1) {
        if (cantidad_apariciones(n, vector1) != cantidad_apariciones(n, vector2)) {
            return false;
        }
    }
    for (int n : vector2) {
        if (cantidad_apariciones(n, vector1) != cantidad_apariciones(n, vector2)) {
            return false;
        }
    }
    return true;
}

void test_ej3(bool (*me)(vector<int>, vector<int>)) {
  EXPECT_TRUE((*me)(vector<int>{}, vector<int>{}));
  EXPECT_TRUE((*me)(vector<int>{1, 1, 1}, vector<int>{1}));
  EXPECT_TRUE((*me)(vector<int>{1, 2, 3}, vector<int>{1, 2, 3}));
  EXPECT_TRUE((*me)(vector<int>{3, 2, 1}, vector<int>{1, 2, 3}));
  EXPECT_TRUE(!(*me)(vector<int>{4, 3, 2, 1}, vector<int>{1, 2, 3}));
  EXPECT_TRUE((*me)(vector<int>{3, 3, 2, 1}, vector<int>{1, 2, 3}));
  EXPECT_TRUE(!(*me)(vector<int>{3, 3, 2, 1}, vector<int>{1, 3}));
}

TEST(Ej, 01) { test_ej1(quitar_repetidos); }

TEST(Ej, 02) { test_ej1(quitar_repetidos_v2); }

TEST(Ej, 03) { test_ej3(mismos_elementos); }

TEST(Ej, 04) { test_ej3(mismos_elementos_v2); }

TEST(Ej, 05) {
  EXPECT_TRUE((contar_apariciones(vector<int>()) == map<int, int>()));
  EXPECT_TRUE((contar_apariciones(vector<int>({1, 2, 3})) == map<int, int>({{1, 1}, {2, 1}, {3, 1}})));
  EXPECT_TRUE((contar_apariciones(vector<int>({1, 2, 3, 1})) == map<int, int>({{1, 2}, {2, 1}, {3, 1}})));
  EXPECT_TRUE((contar_apariciones(vector<int>({1, 1})) == map<int, int>({{1, 2}})));
}

TEST(Ej, 06) {
  EXPECT_EQ(v2s(filtrar_repetidos(vector<int>{})), set<int>());
  EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 1}))), set<int>());
  EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 1, 2}))), set<int>({2}));
  EXPECT_EQ(v2s(filtrar_repetidos(vector<int>({1, 2}))), set<int>({2, 1}));
}

TEST(Ej, 07) {
  EXPECT_EQ(interseccion(set<int>(), set<int>()), set<int>());
  EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>()), set<int>());
  EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({4})), set<int>());
  EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({2, 4})), set<int>({2}));
  EXPECT_EQ(interseccion(set<int>({1, 2, 3}), set<int>({2, 1, 4})), set<int>({1, 2}));
}

TEST(Ej, 08) {
  vector<int> v;
  map<int, set<int>> m;
  EXPECT_EQ(agrupar_por_unidades(v), m);

  map<int, set<int>> r1 = agrupar_por_unidades(vector<int>({1, 2, 3}));
  map<int, set<int>> e1 = map<int, set<int>>({{1, set<int>{1}}, {2, set<int>{2}}, {3, set<int>{3}}});
  EXPECT_EQ(r1, e1);

  map<int, set<int>> r3 = agrupar_por_unidades(vector<int>({1, 2, 3, 12}));
  map<int, set<int>> e3 = map<int, set<int>>({{1, set<int>{1}}, {2, set<int>{2, 12}}, {3, set<int>{3}}});
  EXPECT_EQ(r3, e3);

  map<int, set<int>> r4 = agrupar_por_unidades(vector<int>({1, 2, 3, 12, 20}));
  map<int, set<int>> e4 = map<int, set<int>>({{1, set<int>{1}}, {2, set<int>{2, 12}}, {0, set<int>{20}},
                                              {3, set<int>{3}}});
  EXPECT_EQ(r4, e4);

  map<int, set<int>> r5 = agrupar_por_unidades(vector<int>({1, 2, 3, 12, 20, 1101}));
  map<int, set<int>> e5 = map<int, set<int>>({{1, set<int>{1, 1101}}, {2, set<int>{2, 12}}, {0, set<int>{20}},
                                              {3, set<int>{3}}});
  EXPECT_EQ(r5, e5);
}

vector<char> s2v(string str) {
  vector<char> v;
  for (char c : str) {
    v.push_back(c);
  }
  return v;
}

string v2s(vector<char> v) {
  stringstream ss;
  for (char c : v) {
    ss << c;
  }
  return ss.str();
}

TEST(Ej, 09) {
  EXPECT_EQ(traducir(vector<pair<char, char>>{}, s2v("Hola")), s2v("Hola"));
  EXPECT_EQ(traducir(vector<pair<char, char>>{{'H', 'h'}}, s2v("Hola")),
          s2v("hola"));
  EXPECT_EQ(traducir(
              vector<pair<char, char>>{
                  {'H', 'h'},
                  {'x', 'h'},
              },
              s2v("Hola")), s2v("hola"));
  EXPECT_EQ(traducir(
              vector<pair<char, char>>{
                  {'H', 'h'},
                  {'x', 'h'},
                  {'o', 'h'},
                  {'h', 'A'},
              },
              s2v("Hola")), s2v("hhla"));
}

Mail mfs(string asunto) { return Mail(asunto, 0, false); }

TEST(Ej, 10) {
  EXPECT_TRUE(!integrantes_repetidos(vector<Mail>{mfs("123/45"), mfs("111/11")}));
  EXPECT_TRUE(!integrantes_repetidos(
      vector<Mail>{mfs("123/45;222/11"), mfs("111/11")}));
  EXPECT_TRUE(!integrantes_repetidos(
      vector<Mail>{mfs("123/45;222/11"), mfs("111/11;222/22")}));
  EXPECT_TRUE(!integrantes_repetidos(vector<Mail>{
      mfs("123/45;222/11"), mfs("111/11;222/22"), mfs("123/45;222/11")}));
  EXPECT_TRUE(!integrantes_repetidos(
      vector<Mail>{mfs("123/45;222/11"), mfs("111/11;222/22"),
                   mfs("111/11;222/22"), mfs("123/45;222/11")}));
  EXPECT_TRUE(
      integrantes_repetidos(vector<Mail>{mfs("123/45"), mfs("123/45;222/22")}));
  EXPECT_TRUE(integrantes_repetidos(
      vector<Mail>{mfs("111/45;222/22"), mfs("123/45;222/22")}));
}

using dict_entrega = map<set<LU>, Mail>;

set<LU> pg(string s) { return mfs(s).libretas(); }

TEST(Ej, 11) {
  Mail e11 = Mail("123/45", 10, true);
  dict_entrega r1 = entregas_finales(vector<Mail>({e11}));
  EXPECT_EQ(r1, dict_entrega({{pg("123/45"), e11}}));

  Mail e12 = Mail("123/45", 20, true);
  EXPECT_EQ(entregas_finales(vector<Mail>({e11, e12})),
          dict_entrega({{pg("123/45"), e12}}));

  Mail e13 = Mail("123/45", 25, false);
  EXPECT_EQ(entregas_finales(vector<Mail>({e11, e12, e13})),
          dict_entrega({{pg("123/45"), e12}}));

  Mail e14 = Mail("123/45", 15, false);
  EXPECT_EQ(entregas_finales(vector<Mail>({e11, e12, e13, e14})),
          dict_entrega({{pg("123/45"), e12}}));

  Mail e21 = Mail("007/11", 15, true);
  EXPECT_EQ(entregas_finales(vector<Mail>({e21, e11, e12, e13, e14})),
          dict_entrega({{pg("123/45"), e12},
                       {pg("007/11"), e21}}));

  Mail e22 = Mail("007/11", 25, true);
  EXPECT_EQ(entregas_finales(vector<Mail>({e21, e22, e11, e12, e13, e14})),
          dict_entrega({{pg("123/45"), e12},
                       {pg("007/11"), e22}}));

  Mail e23 = Mail("007/11", 35, false);
  dict_entrega r2 = entregas_finales(vector<Mail>({e21, e22, e23, e11, e12, e13, e14}));
  EXPECT_EQ(r2, dict_entrega({{pg("123/45"), e12}, {pg("007/11"), e22}}));
};
