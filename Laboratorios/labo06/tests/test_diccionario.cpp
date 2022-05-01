#include "gtest/gtest.h"
#include "../src/Diccionario.hpp"

using namespace std;

#if EJ >= 5
TEST(diccionario, dicc_int_int) {
	Diccionario<int, int> d;
	ASSERT_FALSE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	d.definir(1, 10);
	ASSERT_TRUE(d.def(1));
	ASSERT_FALSE(d.def(2));
	ASSERT_FALSE(d.def(3));
	ASSERT_EQ(d.obtener(1), 10);
	d.definir(2, 20);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
	ASSERT_EQ(d.obtener(1), 10);
	ASSERT_EQ(d.obtener(2), 20);
	d.definir(1, 30);
	ASSERT_TRUE(d.def(1));
	ASSERT_TRUE(d.def(2));
	ASSERT_FALSE(d.def(3));
	ASSERT_EQ(d.obtener(1), 30);
	ASSERT_EQ(d.obtener(2), 20);
}
#endif

#if EJ >= 6

// Agregar un test para diccionario con clave string y valor bool.
TEST(diccionario, dicc_string_bool) {
	Diccionario<string, bool> d;
	ASSERT_FALSE(d.def("1"));
	ASSERT_FALSE(d.def("2"));
	ASSERT_FALSE(d.def("3"));
	d.definir("1", true);
	ASSERT_TRUE(d.def("1"));
	ASSERT_FALSE(d.def("2"));
	ASSERT_FALSE(d.def("3"));
	ASSERT_EQ(d.obtener("1"), true);
	d.definir("2", false);
	ASSERT_TRUE(d.def("1"));
	ASSERT_TRUE(d.def("2"));
	ASSERT_FALSE(d.def("3"));
	ASSERT_EQ(d.obtener("1"), true);
	ASSERT_EQ(d.obtener("2"), false);
	d.definir("1", false);
	ASSERT_TRUE(d.def("1"));
	ASSERT_TRUE(d.def("2"));
	ASSERT_FALSE(d.def("3"));
	ASSERT_EQ(d.obtener("1"), false);
	ASSERT_EQ(d.obtener("2"), false);
}

#endif

#if EJ >= 8

TEST(diccionario, claves) {
	Diccionario<int, char> d;
	d.definir(8, 'A');
	d.definir(3, 'B');
	d.definir(4, 'C');
	d.definir(9, 'D');
	d.definir(7, 'E');
	d.definir(5, 'F');
	d.definir(1, 'G');
	d.definir(2, 'H');
	d.definir(6, 'I');
	d.definir(0, 'J');

	std::vector<int> c;
	for (int i = 0; i < 10; i++) {
		c.push_back(i);
	}

	ASSERT_EQ(d.claves(), c);

	// Verificar que el diccionario no haya cambiado
	ASSERT_EQ(d.obtener(8), 'A');
	ASSERT_EQ(d.obtener(3), 'B');
	ASSERT_EQ(d.obtener(4), 'C');
	ASSERT_EQ(d.obtener(9), 'D');
	ASSERT_EQ(d.obtener(7), 'E');
	ASSERT_EQ(d.obtener(5), 'F');
	ASSERT_EQ(d.obtener(1), 'G');
	ASSERT_EQ(d.obtener(2), 'H');
	ASSERT_EQ(d.obtener(6), 'I');
	ASSERT_EQ(d.obtener(0), 'J');
}

#endif
