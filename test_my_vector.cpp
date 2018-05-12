#include "my_vector.hpp"
#include <algorithm>

#include "gtest/gtest.h"
#include "my_vector_iterator.hpp"

class VectorTest : public ::testing::Test {
protected:
    virtual void SetUp() {
        vec_i_2 = my_vector<int>(4);
        vec_i_3 = my_vector<int>{1, 2, 3};
        vec_i_4 = my_vector<int>(2, 49);
        vec_s_2 = my_vector<std::string>{"abc", "abcd"};
        vec_vec = my_vector<my_vector<int> >(3, my_vector<int>(3, 134));
    }
protected:
    my_vector<int> vec_i_1;
    my_vector<int> vec_i_2;
    my_vector<int> vec_i_3;
    my_vector<int> vec_i_4;
    my_vector<std::string> vec_s_1;
    my_vector<std::string> vec_s_2;
    my_vector<my_vector<int> > vec_vec;
};

TEST_F(VectorTest, Constructor_Size) {
    ASSERT_EQ(vec_i_1.size(), 0);
    ASSERT_EQ(vec_s_1.size(), 0);
    ASSERT_EQ(vec_i_2.size(), 4);
    ASSERT_EQ(vec_vec.size(), 3);

    ASSERT_EQ(vec_i_3.size(), 3);
    ASSERT_EQ(vec_i_4.size(), 2);
    ASSERT_EQ(vec_s_2.size(), 2);

    ASSERT_EQ(vec_i_4[0], 49);
    ASSERT_EQ(vec_i_3[0], 1);
    ASSERT_EQ(vec_s_2[0], "abc");

    my_vector<int> vec(vec_i_4);
    ASSERT_EQ(vec.size(), 2);
    ASSERT_EQ(vec[0], 49);
    my_vector<std::string>vec_s(vec_s_2);
    ASSERT_EQ(vec_s.size(), 2);
    ASSERT_EQ(vec_s[0], "abc");

    my_vector<int> vec_1(vec);
    ASSERT_EQ(vec_1.size(), 2);
    ASSERT_EQ(vec_1[0], 49);
    my_vector<std::string>vec_s2(vec_s);
    ASSERT_EQ(vec_s2.size(), 2);
    ASSERT_EQ(vec_s2[0], "abc");

}

TEST_F(VectorTest, Assign) {
    vec_i_1.assign(8, 2);
    ASSERT_EQ(vec_i_1.size(), 8);
    for(int i = 0; i < 8; i++) {
        ASSERT_EQ(vec_i_1[i], 2);
    }

    vec_s_1.assign(16, "hello");
    ASSERT_EQ(vec_s_1.size(), 16);
    for(int i = 0; i < 16; i++) {
        ASSERT_EQ(vec_s_1[i], "hello");
    }
}

TEST_F(VectorTest, Reserve) {
    ASSERT_EQ(vec_i_2.capacity(), 4);
    vec_i_1.reserve(10);
    ASSERT_EQ(vec_i_1.capacity(), 10);

    ASSERT_EQ(vec_i_2.capacity(), 4);
    vec_i_2.reserve(2);
    ASSERT_EQ(vec_i_2.capacity(), 4);

    ASSERT_EQ(vec_s_2.capacity(), 2);
    vec_s_2.reserve(1);
    ASSERT_EQ(vec_s_2.capacity(), 2);

    ASSERT_EQ(vec_s_2.capacity(), 2);
    vec_s_2.reserve(7);
    ASSERT_EQ(vec_s_2.capacity(), 7);

}

TEST_F(VectorTest, Resize) {
    ASSERT_EQ(vec_i_1.size(), 0);
    vec_i_1.resize(3);
    ASSERT_EQ(vec_i_1.size(), 3);

    ASSERT_EQ(vec_s_2.size(), 2);
    vec_s_2.resize(1);
    ASSERT_EQ(vec_s_2.size(), 1);
}

TEST_F(VectorTest, Empty) {
    ASSERT_TRUE(vec_i_1.empty());
    ASSERT_FALSE(vec_i_2.empty());
    ASSERT_FALSE(vec_i_3.empty());
    ASSERT_FALSE(vec_i_4.empty());

    ASSERT_TRUE(vec_s_1.empty());
    ASSERT_FALSE(vec_s_2.empty());
}

TEST_F(VectorTest, Shrink_to_fit) {
    vec_i_1.shrink_to_fit();
    ASSERT_EQ(vec_i_1.size(), vec_i_1.capacity());
    vec_i_2.shrink_to_fit();
    ASSERT_EQ(vec_i_2.size(), vec_i_2.capacity());
    vec_i_3.shrink_to_fit();
    ASSERT_EQ(vec_i_3.size(), vec_i_3.capacity());
    vec_i_4.shrink_to_fit();
    ASSERT_EQ(vec_i_4.size(), vec_i_4.capacity());

    vec_s_1.shrink_to_fit();
    ASSERT_EQ(vec_s_1.size(), vec_s_1.capacity());
    vec_s_2.shrink_to_fit();
    ASSERT_EQ(vec_s_2.size(), vec_s_2.capacity());

}
TEST_F(VectorTest, Push_back) {
    vec_i_1.push_back(0);
    ASSERT_EQ(vec_i_1.size(), 1);

    vec_s_2.push_back("abc");
    ASSERT_EQ(vec_s_2.size(), 3);

    vec_s_2.push_back(vec_s_2[0]);
    ASSERT_EQ(vec_s_2.back(), vec_s_2[0]);
}

TEST_F(VectorTest, Pop_back) {
    vec_i_1.pop_back();
    ASSERT_EQ(vec_i_1.size(), 0);
    vec_i_2.pop_back();
    ASSERT_EQ(vec_i_2.size(), 3);
    vec_i_3.pop_back();
    ASSERT_EQ(vec_i_3.size(), 2);
    vec_i_4.pop_back();
    ASSERT_EQ(vec_i_4.size(), 1);


    vec_s_1.pop_back();
    ASSERT_EQ(vec_s_1.size(), 0);
    vec_s_2.pop_back();
    ASSERT_EQ(vec_s_2.size(), 1);
}

TEST_F(VectorTest, At_indexOperator) {
    for(int i = 0; i < vec_i_1.size(); i++) {
        ASSERT_EQ(vec_i_1[i], vec_i_1.at(i));
    }
    for(int i = 0; i < vec_i_2.size(); i++) {
        ASSERT_EQ(vec_i_2[i], vec_i_2.at(i));
    }
    for(int i = 0; i < vec_i_3.size(); i++) {
        ASSERT_EQ(vec_i_3[i], vec_i_3.at(i));
    }
    for(int i = 0; i < vec_i_4.size(); i++) {
        ASSERT_EQ(vec_i_4[i], vec_i_4.at(i));
    }
}

TEST_F(VectorTest, Front) {
    ASSERT_EQ(vec_i_2.front(), vec_i_2[0]);
    ASSERT_EQ(vec_i_3.front(), vec_i_3[0]);
    ASSERT_EQ(vec_i_4.front(), vec_i_4[0]);
    ASSERT_EQ(vec_s_2.front(), vec_s_2[0]);
}

TEST_F(VectorTest, End) {
    ASSERT_EQ(vec_i_2.back(), vec_i_2[vec_i_2.size()-1]);
    ASSERT_EQ(vec_i_3.back(), vec_i_3[vec_i_3.size()-1]);
    ASSERT_EQ(vec_i_4.back(), vec_i_4[vec_i_4.size()-1]);
    ASSERT_EQ(vec_s_2.back(), vec_s_2[vec_s_2.size()-1]);
}

TEST_F(VectorTest, Data) {
    auto dt_i = vec_i_2.data();
    for (int i = 0; i < vec_i_2.size(); ++i) {
        ASSERT_EQ(vec_i_2[i], dt_i[i]);
    }
    auto dt_s = vec_s_2.data();
    for (int i = 0; i < vec_s_2.size(); ++i) {
        ASSERT_EQ(vec_s_2[i], dt_s[i]);
    }
}

TEST_F(VectorTest, Clear) {
    vec_i_4.clear();
    ASSERT_EQ(vec_i_4.size(), 0);
    ASSERT_EQ(vec_i_4.capacity(), 0);
    vec_s_2.clear();
    ASSERT_EQ(vec_s_2.size(), 0);
    ASSERT_EQ(vec_s_2.capacity(), 0);
}

TEST_F(VectorTest, Swap) {
    vec_i_4.swap(vec_i_3);
    ASSERT_EQ(vec_i_4[0], 1);
    ASSERT_EQ(vec_i_3[0], 49);

    ASSERT_EQ(vec_i_4.size(), 3);
    ASSERT_EQ(vec_i_3.size(), 2);
}

TEST_F(VectorTest, Assiment) {
    vec_i_4 = vec_i_3;
    for(int i = 0; i < vec_i_3.size(); i++) {
        ASSERT_EQ(vec_i_3[i], vec_i_4[i]);
    }
    vec_i_2 = vec_i_2;
    for(int i = 0; i < vec_i_2.size(); i++) {
        ASSERT_EQ(vec_i_2[i], vec_i_2[i]);
    }
}
int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    my_vector<int> mv = my_vector<int>(2, 49);
    std::cout << mv[0];
}
