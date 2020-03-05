#include "gtest/gtest.h"
extern "C" {
#include "strings_filter.h"
}

TEST(str1, str1)
{
char** test_str_vec = NULL;
char** test_res_str_vec = NULL;
size_t test_vec_len = 1;
size_t test_res_vec_len = 0;
test_str_vec = (char **) malloc(test_vec_len * sizeof(char *));
test_str_vec[0] = (char*)malloc(13* sizeof(char));
char* str = (char*)"Hello world!";
test_str_vec[0] = (char*)memcpy(test_str_vec[0], str, 13);
ASSERT_EQ(strings_filter(test_str_vec, test_vec_len ,&test_res_str_vec),0);
del_vec(test_res_str_vec, test_res_vec_len);
del_vec(test_str_vec, test_vec_len);
}

TEST(str2,stri2)
{
    char** test_str_vec = NULL;
    char** test_res_str_vec = NULL;
    size_t test_vec_len = 1;
    size_t test_res_vec_len = 0;
    test_str_vec = (char **) malloc(test_vec_len * sizeof(char *));
    test_str_vec[0] = (char*)malloc(8* sizeof(char));
    char* str = (char*)"mail.ru";
    test_str_vec[0] = (char*)memcpy(test_str_vec[0], str, 8);
    ASSERT_EQ(strings_filter(test_str_vec, test_vec_len ,&test_res_str_vec),1);
    del_vec(test_res_str_vec, test_res_vec_len);
    del_vec(test_str_vec, test_vec_len);
}

TEST(str3,str3)
{
    char** test_str_vec = NULL;
    char** test_res_str_vec = NULL;
    size_t test_vec_len = 1;
    size_t test_res_vec_len = 0;
    test_str_vec = (char **) malloc(test_vec_len * sizeof(char *));
    test_str_vec[0] = (char*)malloc(20* sizeof(char));
    char* str = (char*)"http://park.mail.ru";
    test_str_vec[0] = (char*)memcpy(test_str_vec[0], str, 20);
    ASSERT_EQ(strings_filter(test_str_vec, test_vec_len ,&test_res_str_vec),1);
    del_vec(test_res_str_vec, test_res_vec_len);
    del_vec(test_str_vec, test_vec_len);
}

TEST(str4,str4)
{
    char** test_str_vec = NULL;
    char** test_res_str_vec = NULL;
    size_t test_vec_len = 1;
    size_t test_res_vec_len = 0;
    test_str_vec = (char **) malloc(test_vec_len * sizeof(char *));
    test_str_vec[0] = (char*)malloc(27* sizeof(char));
    char* str = (char*)"https://park.mail.ru/feed/";
    test_str_vec[0] = (char*)memcpy(test_str_vec[0], str, 27);
    ASSERT_EQ(strings_filter(test_str_vec, test_vec_len ,&test_res_str_vec),1);
    del_vec(test_res_str_vec, test_res_vec_len);
    del_vec(test_str_vec, test_vec_len);
}

TEST(str5,str5)
{
    char** test_str_vec = NULL;
    char** test_res_str_vec = NULL;
    size_t test_vec_len = 1;
    size_t test_res_vec_len = 0;
    test_str_vec = (char **) malloc(test_vec_len * sizeof(char *));
    test_str_vec[0] = (char*)malloc(15* sizeof(char));
    char* str = (char*)"ftp://foo.net/";
    test_str_vec[0] = (char*)memcpy(test_str_vec[0], str, 15);
    ASSERT_EQ(strings_filter(test_str_vec, test_vec_len ,&test_res_str_vec),1);
    del_vec(test_res_str_vec, test_res_vec_len);
    del_vec(test_str_vec, test_vec_len);
}
