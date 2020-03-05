#include <string.h>
#include "strings_filter.h"


int main() {
    char** str_vec = NULL;
    char** res_str_vec = NULL;

    size_t vec_len = 0;
    str_vec = input_str_vec(str_vec, &vec_len);
    if (str_vec == NULL){
        return -2;
    }

    size_t res_vec_len = strings_filter(str_vec, vec_len, &res_str_vec);
    if (res_vec_len == -1){
        return -1;
    }

    del_vec(str_vec, vec_len);
    del_vec(res_str_vec, res_vec_len);

    return 0;
}
