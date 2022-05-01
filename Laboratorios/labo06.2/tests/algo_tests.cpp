#include "../src/algoritmos.hpp"
#include <set>
#include <vector>
#include "gtest-1.8.1/gtest.h"
#include <list>

using namespace std;

#if EJ >= 1

TEST(algo_tests, test_minimo) {
    const set<int> s = {2, 3, 4};
    EXPECT_EQ(minimo(s), 2);

    const vector<int> v = {100, 2, 3, 2, 4};
    EXPECT_EQ(minimo(v), 2);

    list<int> l = {5, 4};
    EXPECT_EQ(minimo(l), 4);

    # if EJ >= 8
    map<int, string> m;
    m[5] = "Hola";
    m[6] = "Mundo";
    EXPECT_EQ(minimo(m), (pair<const int,string>(5, "Hola")));
    #endif
}

#endif
#if EJ >= 2

TEST(algo_tests, test_promedio) {
    const set<int> s = {2, 3, 4};
    EXPECT_EQ(promedio(s), 3);

    vector<double> v = {100, 2, 3, 2, 4};
    EXPECT_EQ(promedio(v), 111.0/5.0);

    list<double> l = {5, 4};
    EXPECT_EQ(promedio(l), 4.5);
}

#endif
#if EJ >= 3

TEST(algo_tests, test_minimoIter) {
    const set<int> s = {2, 3, 4};
    EXPECT_EQ(minimoIter(s.begin(),s.end()), 2);

    const vector<int> v = {100, 2, 3, 2, 4};
    EXPECT_EQ(minimoIter(v.begin(),v.end()), 2);
    EXPECT_EQ(minimoIter(v.begin(),v.begin()+1), 100);
    EXPECT_EQ(minimoIter(v.begin(),v.begin()+2), 2);

    const list<int> l = {5, 4};
    EXPECT_EQ(minimoIter(l.begin(),l.end()), 4);

    # if EJ >= 8
    map<int, string> m;
    m[5] = "Hola";
    m[6] = "Mundo";
    EXPECT_EQ(minimoIter(m.begin(),m.end()), (pair<const int,string>(5,"Hola")));
    #endif
}

TEST(algo_tests, test_promedioIter) {
    const set<int> s = {2, 3, 4};
    EXPECT_EQ(promedioIter(s.begin(),s.end()), 3);

    const vector<double> v = {100, 2, 3, 2, 4};
    EXPECT_EQ(promedioIter(v.begin(),v.end()), 111.0/5.0);

    EXPECT_EQ(promedioIter(v.begin(),v.begin()+3), 105.0/3.0);

    const list<double> l = {5, 4};
    EXPECT_EQ(promedioIter(l.begin(),l.end()), 4.5);
}

#endif
#if EJ >= 4

TEST(algo_tests, test_filtrar) {
    set<int> s = {1, 2, 3, 4};
    filtrar(s, 1);
    EXPECT_EQ(s.size(), 3);
    EXPECT_EQ(s.find(1), s.end());

    vector<int> v = {1, 2, 3, 2, 4};
    filtrar(v, 2);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v[1], 3);

    list<int> l = {1, 3, 5, 5 ,2};
    filtrar(l, 5);
    EXPECT_EQ(l, list<int>({1,3,2}));

    map<int, string> m;
    m[5] = "Hola";
    m[6] = "Mundo";
    filtrar(m, std::pair<int, string>(5,"Hola"));
    EXPECT_EQ(m.size(), 1);
}

#endif
#if EJ >= 5

TEST(algo_tests, test_ordenado) {
    const vector<int> v1 = {1,2,3,4}, v2 = {4,3,2,1};
    const set<int> s1 = {1,2,3,4}, s2 = {4,3,2,1};

    EXPECT_TRUE(ordenado(v1));
    EXPECT_FALSE(ordenado(v2));
    EXPECT_TRUE(ordenado(s1));
    EXPECT_TRUE(ordenado(s2));
}

#endif
#if EJ >= 6

TEST(algo_tests, test_split) {
    const set<int> s = {2,16,1, 3,9, 45,6,7,8};
    set <int> s1 = {1,2,3,6};
    set <int> s2 = {7,8,9,16,45};
    EXPECT_EQ(get<0>(split(s,7)),s1);
    EXPECT_EQ(get<1>(split(s,7)),s2);

    const vector<double> v = {100, 2, 3, 2, 4};
    vector <double> v3 = {2,3,2,4};
    vector <double> v4 = {100};

    EXPECT_EQ(get<0>(split(v,7)),v3);
    EXPECT_EQ(get<1>(split(v,7)),v4);

    vector <double> v5 = {100,2,3,2,4};
    vector <double> v6 = {};


    EXPECT_EQ(get<0>(split(v,101)),v5);
    EXPECT_EQ(get<1>(split(v,101)),v6);

    { // list
    const list<double> v = {100, 2, 3, 2, 4};
    list <double> v3 = {2,3,2,4};
    list <double> v4 = {100};

    EXPECT_EQ(get<0>(split(v,7)),v3);
    EXPECT_EQ(get<1>(split(v,7)),v4);

    list <double> v5 = {100,2,3,2,4};
    list <double> v6 = {};


    EXPECT_EQ(get<0>(split(v,101)),v5);
    EXPECT_EQ(get<1>(split(v,101)),v6);
    }

}

#endif
#if EJ >= 7

TEST(algo_tests, test_merge) {

    const vector<int> v1 = {1,2,3,6,7};
    const vector<int> v2 = {8,9,16,45};
    const vector<int> v3 = {2,5,6,8};
    const vector<int> v4 = {};

    vector<int> v_merge1 = {1,2,3,6,7,8,9,16,45};
    vector<int> v_merge2 = {1,2,2,3,5,6,6,7,8};

    vector<int> res1;
    vector<int> res2;
    vector<int> res3;
    vector<int> res4;
    merge(v1,v2,res1);
    merge(v1,v3,res2);
    merge(v1,v4,res3);
    merge(v4,v1,res4);
    EXPECT_EQ(res1,v_merge1);
    EXPECT_EQ(res2,v_merge2);
    EXPECT_EQ(res3,v1);
    EXPECT_EQ(res4,v1);

    { //list
        const list<int> v1 = {1,2,3,6,7};
        const list<int> v2 = {8,9,16,45};
        const list<int> v3 = {2,5,6,8};
        const list<int> v4 = {};

        list<int> v_merge1 = {1,2,3,6,7,8,9,16,45};
        list<int> v_merge2 = {1,2,2,3,5,6,6,7,8};

        list<int> res1;
        list<int> res2;
        list<int> res3;
        list<int> res4;
        merge(v1,v2,res1);
        merge(v1,v3,res2);
        merge(v1,v4,res3);
        merge(v4,v1,res4);
        EXPECT_EQ(res1,v_merge1);
        EXPECT_EQ(res2,v_merge2);
        EXPECT_EQ(res3,v1);
        EXPECT_EQ(res4,v1);
    }

    { //set
        const set<int> v1 = {1,2,3,6,7};
        const set<int> v2 = {8,9,16,45};
        const set<int> v3 = {2,5,6,8};
        const set<int> v4 = {};

        set<int> v_merge1 = {1,2,3,6,7,8,9,16,45};
        set<int> v_merge2 = {1,2,2,3,5,6,6,7,8};

        set<int> res1;
        set<int> res2;
        set<int> res3;
        set<int> res4;
        merge(v1,v2,res1);
        merge(v1,v3,res2);
        merge(v1,v4,res3);
        merge(v4,v1,res4);
        EXPECT_EQ(res1,v_merge1);
        EXPECT_EQ(res2,v_merge2);
        EXPECT_EQ(res3,v1);
        EXPECT_EQ(res4,v1);
    }

}

#endif
