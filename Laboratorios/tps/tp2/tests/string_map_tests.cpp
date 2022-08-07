#include "gtest-1.8.1/gtest.h"
#include "../src/string_map.h"

TEST(string_map_test, vacio) {
    string_map<int> vacio;

    EXPECT_TRUE(vacio.empty());
    EXPECT_EQ(vacio.count("hola"), 0);
}

TEST(string_map_test, asignar) {
    string_map<int> singleton;
    singleton.insert(make_pair("hola", 1));

    EXPECT_EQ(singleton.at("hola"), 1);
    EXPECT_EQ(singleton.size(), 1);
}

TEST(string_map_test, obtener) {
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios", 3));

    con_prefijos.insert(make_pair("c",  1));
    con_prefijos.insert(make_pair("casa",  2));
    con_prefijos.insert(make_pair("casona",  3));

    EXPECT_EQ(sin_prefijos.at("hola"), 1);
    EXPECT_EQ(sin_prefijos.at("chau"), 2);
    EXPECT_EQ(sin_prefijos.at("adios"), 3);

    EXPECT_EQ(con_prefijos.at("c"), 1);
    EXPECT_EQ(con_prefijos.at("casa"), 2);
    EXPECT_EQ(con_prefijos.at("casona"), 3);
}

TEST(string_map_test, redefinir) {
    string_map<int> con_prefijos;

    con_prefijos.insert(make_pair("c",  1));
    con_prefijos.insert(make_pair("casa",  2));
    con_prefijos.insert(make_pair("casona",  3));

    con_prefijos.insert(make_pair("c", 2));
    EXPECT_EQ(con_prefijos.at("c"), 2);
    con_prefijos.insert(make_pair("c", 3));
    EXPECT_EQ(con_prefijos.at("c"), 3);
}

TEST(string_map_test, count) {
    string_map<int> vacio;
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios", 3));

    con_prefijos.insert(make_pair("c", 1));
    con_prefijos.insert(make_pair("casa", 2));
    con_prefijos.insert(make_pair("casona", 3));

	// Estos tests admiten implementaciones rotas donde se devuelve un
    // count > 1 para las claves que no están definidas en el diccionario.
    // Se debería pedir explícitamente que el count sea 0:
    // EXPECT_TRUE(vacio.count("a") == 0);

    EXPECT_FALSE(vacio.count("a") == 1);
	EXPECT_FALSE(vacio.count("aaaa") == 1);
	EXPECT_FALSE(vacio.count("adios") == 1);

	EXPECT_TRUE(sin_prefijos.count("hola") == 1);
	EXPECT_TRUE(sin_prefijos.count("chau") == 1);
	EXPECT_TRUE(sin_prefijos.count("adios") == 1);

	EXPECT_FALSE(sin_prefijos.count("h") == 1);
	EXPECT_FALSE(sin_prefijos.count("ho") == 1);
	EXPECT_FALSE(sin_prefijos.count("hol") == 1);

	EXPECT_TRUE(con_prefijos.count("c") == 1);
	EXPECT_TRUE(con_prefijos.count("casa") == 1);
	EXPECT_TRUE(con_prefijos.count("casona") == 1);
	EXPECT_FALSE(con_prefijos.count("ca") == 1);
	EXPECT_FALSE(con_prefijos.count("cas") == 1);
	EXPECT_FALSE(con_prefijos.count("caso") == 1);
}

TEST(string_map_test, copiar) {
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios", 3));

    con_prefijos.insert(make_pair("c", 1));
    con_prefijos.insert(make_pair("casa", 2));
    con_prefijos.insert(make_pair("casona", 3));

    string_map<int> copia(sin_prefijos);

	EXPECT_TRUE(copia.count("hola") == 1);
	EXPECT_TRUE(copia.count("chau") == 1);
	EXPECT_TRUE(copia.count("adios") == 1);

	EXPECT_FALSE(copia.count("h") == 1);
	EXPECT_FALSE(copia.count("ho") == 1);
	EXPECT_FALSE(copia.count("hol") == 1);

	EXPECT_EQ(sin_prefijos.at("hola"), copia.at("hola"));
	EXPECT_EQ(sin_prefijos.at("chau"), copia.at("chau"));
	EXPECT_EQ(sin_prefijos.at("adios"), copia.at("adios"));

	string_map<int> copia2(con_prefijos);

	EXPECT_TRUE(copia2.count("c") == 1);
	EXPECT_TRUE(copia2.count("casa") == 1);
	EXPECT_TRUE(copia2.count("casona") == 1);
	EXPECT_FALSE(copia2.count("ca") == 1);
	EXPECT_FALSE(copia2.count("cas") == 1);
	EXPECT_FALSE(copia2.count("caso") == 1);

	EXPECT_EQ(copia2.at("c"), 1);
	EXPECT_EQ(copia2.at("casa"), 2);
	EXPECT_EQ(copia2.at("casona"), 3);
}

TEST(string_map_test, no_aliasing) {
    string_map<int> singleton;
    singleton.insert(make_pair("hola", 1));

	string_map<int> copia(singleton);
	copia.insert(make_pair("hare", 2));
	ASSERT_FALSE(singleton.count("hare") == 1);
}


TEST(string_map_test, TrieDeTries) {
    string_map<int> vacio;
    string_map<int> singleton;
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;
    string_map<string_map<int>> dicc_dicc;

    singleton.insert(make_pair("hola", 1));

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios",  3));

    con_prefijos.insert(make_pair("c",  1));
    con_prefijos.insert(make_pair("casa",  2));
    con_prefijos.insert(make_pair("casona",  3));

    dicc_dicc.insert(make_pair("vacio",  vacio));
    dicc_dicc.insert(make_pair("singleton",  singleton));
    dicc_dicc.insert(make_pair("sin_prefijos",  sin_prefijos));
    dicc_dicc.insert(make_pair("con_prefijos",  con_prefijos));

	EXPECT_FALSE(dicc_dicc.at("vacio").count("hola") == 1);

	EXPECT_EQ(dicc_dicc.at("singleton").at("hola"), 1);

	EXPECT_EQ(dicc_dicc.at("sin_prefijos").at("hola"), 1);
	EXPECT_EQ(dicc_dicc.at("sin_prefijos").at("chau"), 2);
	EXPECT_EQ(dicc_dicc.at("sin_prefijos").at("adios"), 3);

	EXPECT_EQ(dicc_dicc.at("con_prefijos").at("c"), 1);
	EXPECT_EQ(dicc_dicc.at("con_prefijos").at("casa"), 2);
	EXPECT_EQ(dicc_dicc.at("con_prefijos").at("casona"), 3);

}

TEST(string_map_test, eraseUnicaClave) {
    string_map<int> singleton;
    singleton.insert(make_pair("hola", 1));

    EXPECT_TRUE(singleton.count("hola") == 1);

    singleton.erase("hola");

    EXPECT_FALSE(singleton.count("hola") == 1);
}


TEST(string_map_test, erase) {
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos.insert(make_pair("hola", 1));
    sin_prefijos.insert(make_pair("chau", 2));
    sin_prefijos.insert(make_pair("adios",  3));

    con_prefijos.insert(make_pair("c",  1));
    con_prefijos.insert(make_pair("casa",  2));
    con_prefijos.insert(make_pair("casona",  3));

    con_prefijos.erase("c");
    EXPECT_FALSE(con_prefijos.count("c") == 1);

    EXPECT_TRUE(con_prefijos.count("casa") == 1);
    EXPECT_TRUE(con_prefijos.count("casona") == 1);

    con_prefijos.erase("casona");
    EXPECT_FALSE(con_prefijos.count("casona") == 1);

    EXPECT_TRUE(con_prefijos.count("casa") == 1);

    con_prefijos.erase("casa");
    EXPECT_FALSE(con_prefijos.count("casa") == 1);

    sin_prefijos.erase("hola");
    EXPECT_FALSE(sin_prefijos.count("hola") == 1);

    sin_prefijos.erase("chau");
    EXPECT_FALSE(sin_prefijos.count("chau") == 1);

    sin_prefijos.erase("adios");
    EXPECT_FALSE(sin_prefijos.count("adios") == 1);
}

TEST(string_map_test, operator_corchetes) {
    string_map<int> sin_prefijos;
    string_map<int> con_prefijos;

    sin_prefijos["hola"] = 1;
    sin_prefijos["chau"] = 2;
    sin_prefijos["adios"] =  3;

    con_prefijos["c"] =  1;
    con_prefijos["casa"] =  2;
    con_prefijos["casona"] =  3;

    EXPECT_EQ(sin_prefijos["hola"], 1);
    EXPECT_EQ(sin_prefijos["chau"], 2);
    EXPECT_EQ(sin_prefijos["adios"], 3);

    EXPECT_EQ(con_prefijos["c"], 1);
    EXPECT_EQ(con_prefijos["casa"], 2);
    EXPECT_EQ(con_prefijos["casona"], 3);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
