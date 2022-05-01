#include "gtest/gtest.h"
#include "../src/Multiconjunto.hpp"

#if EJ >= 7
TEST(multiconjunto, multiconj_int) {
	Multiconjunto<int> m;
	ASSERT_EQ(m.ocurrencias(10), 0);
	ASSERT_EQ(m.ocurrencias(20), 0);
	ASSERT_EQ(m.ocurrencias(30), 0);
	m.agregar(10);
	m.agregar(20);
	m.agregar(30);
	m.agregar(20);
	m.agregar(30);
	m.agregar(30);
	ASSERT_EQ(m.ocurrencias(10), 1);
	ASSERT_EQ(m.ocurrencias(20), 2);
	ASSERT_EQ(m.ocurrencias(30), 3);
}

TEST(multiconjunto, multiconj_string) {
	Multiconjunto<std::string> m;
	ASSERT_EQ(m.ocurrencias("foo"), 0);
	ASSERT_EQ(m.ocurrencias("bar"), 0);
	m.agregar("foo");
	ASSERT_EQ(m.ocurrencias("foo"), 1);
	ASSERT_EQ(m.ocurrencias("bar"), 0);
	m.agregar("foo");
	ASSERT_EQ(m.ocurrencias("foo"), 2);
	ASSERT_EQ(m.ocurrencias("bar"), 0);
	m.agregar("bar");
	ASSERT_EQ(m.ocurrencias("foo"), 2);
	ASSERT_EQ(m.ocurrencias("bar"), 1);
	m.agregar("bar");
	ASSERT_EQ(m.ocurrencias("foo"), 2);
	ASSERT_EQ(m.ocurrencias("bar"), 2);
	m.agregar("bar");
	ASSERT_EQ(m.ocurrencias("foo"), 2);
	ASSERT_EQ(m.ocurrencias("bar"), 3);
}
#endif

#if EJ >= 9
TEST(multiconjunto_inclusion, vacio) {
	Multiconjunto<int> m1;
	Multiconjunto<int> m2;
	ASSERT_TRUE(m1 <= m2);
	ASSERT_TRUE(m2 <= m1);
}

TEST(multiconjunto_inclusion, iguales) {
	Multiconjunto<int> m1;
	Multiconjunto<int> m2;
	m1.agregar(1);
	m1.agregar(2);
	m1.agregar(2);
	m1.agregar(3);
	m1.agregar(3);
	m1.agregar(3);

	m2.agregar(3);
	m2.agregar(2);
	m2.agregar(1);
	m2.agregar(3);
	m2.agregar(3);
	m2.agregar(2);
	ASSERT_TRUE(m1 <= m2);
	ASSERT_TRUE(m2 <= m1);
}

TEST(multiconjunto_inclusion, no_incluido_claves) {
	Multiconjunto<int> m1;
	Multiconjunto<int> m2;

	m1.agregar(1);
	m1.agregar(2);
	m1.agregar(4);

	m2.agregar(1);
	m2.agregar(2);
	m2.agregar(2);
	m2.agregar(4);
	m2.agregar(4);
	m2.agregar(4);
	m2.agregar(4);
	ASSERT_TRUE(m1 <= m2);

	m1.agregar(3);
	ASSERT_FALSE(m1 <= m2);
}

TEST(multiconjunto_inclusion, no_incluido_ocurrencias) {
	Multiconjunto<int> m1;
	Multiconjunto<int> m2;

	m1.agregar(1);
	m1.agregar(2);
	m1.agregar(4);

	m2.agregar(1);
	m2.agregar(2);
	m2.agregar(2);
	m2.agregar(4);
	m2.agregar(4);
	m2.agregar(4);
	m2.agregar(4);
	ASSERT_TRUE(m1 <= m2);

	m1.agregar(2);
	ASSERT_TRUE(m1 <= m2);

	m1.agregar(2);
	ASSERT_FALSE(m1 <= m2);
}
#endif
