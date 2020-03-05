#include <string.h>
#include "strings_filter.h"


int main() {
    char** str_vec = NULL;
    char** res_str_vec = NULL;

    size_t vec_len = 2;
    //str_vec = input_str_vec(str_vec, &vec_len);
    //if (str_vec == NULL){
    //return -2;
    //}

    str_vec = (char **) malloc(vec_len * sizeof(char *));
    str_vec[0] = (char*)malloc(13* sizeof(char));
    char* str = (char*)"Hello world!";
    str_vec[0] = (char*)memcpy(str_vec[0], str, 13);

    str_vec[1] = (char*)malloc(8* sizeof(char));
    str = (char*)"mail.ru";
    str_vec[1] = (char*)memcpy(str_vec[1], str, 8);


    size_t res_vec_len = strings_filter(str_vec, vec_len, &res_str_vec);
    if (res_vec_len == -1){
        return -1;
    }

    del_vec(str_vec, vec_len);
    del_vec(res_str_vec, res_vec_len);

    return 0;
}
