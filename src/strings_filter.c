#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>
#include "strings_filter.h"

#define PATTERN "((https?|ftp):\/\/)?(www\.)?([-a-z0-9\.]+)[\.]([a-z]{2,6})([\/\w\.-]*)*[\/]?"


char** grow(char** str_vec, size_t* len)
{
    char** temp = NULL;
    if (*len != 0){
        temp = (char**)realloc(str_vec, ((*len)*2)* sizeof(char*));
        *len *= 2;
    }
    else {
        temp = (char**)malloc(sizeof(char*));
        *len = 1;
    }

    return temp;
}

char** input_str_vec(char** str_vec, size_t* vec_len)
{
    int iter = 0;

    char* buf = (char*)malloc(sizeof(char));
    size_t buf_len = 1;
    while (getline(&buf, &buf_len, stdin) != -1){

        if (iter == *vec_len){
            char** temp = NULL;
            temp = grow(str_vec, vec_len);
            if (temp != NULL){
                str_vec = temp;
            }
            else{
                printf("\n Error, memory is gone");
                return NULL;
            }
        }

        str_vec[iter] = (char*)malloc(buf_len*sizeof(char));
        if (str_vec[iter] == NULL){
            printf("\n Error, memory is gone");
            return NULL;
        }

        str_vec[iter] = memcpy(str_vec[iter], buf, buf_len);

        ++iter;
        if (iter == 3)/////////////////////////////trhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
            break;
        buf_len = 1;
    }

    *vec_len = iter;

    free(buf);

    return str_vec;
}

void print(char** vec, size_t len)
{
    for (int i = 0; i < len; ++i){
        printf("%s", vec[i]);
    }
}

size_t strings_filter(char** str_vec, size_t vec_len, char*** res_str_vec)
{
    size_t res_vec_len = 0;
    int iter = 0;

    regex_t preg;
    int error = 0;
    error = regcomp(&preg, PATTERN, REG_EXTENDED);
    if (error != 0){
        return 0;
    }

    regmatch_t pm;

    for (int i = 0; i < vec_len; ++i){
        size_t len = (int)strlen(str_vec[i]);
        if (regexec(&preg, str_vec[i], 0, &pm, 0) == 0){
            // Heykskmgkwmgwm!!!!!ernklhhhhhhhnkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk
            if (iter == res_vec_len){
                char** temp = NULL;
                temp = grow(*res_str_vec, &res_vec_len);
                if (temp != NULL) {
                    *res_str_vec = temp;
                }
                else{
                    printf("\n Memory error");
                    return -1;
                }
            }

            (*res_str_vec)[iter] = (char*)malloc((len + 1) * sizeof(char));
            if ((*res_str_vec)[iter] != NULL){
                (*res_str_vec)[iter] = memcpy((*res_str_vec)[iter], str_vec[i], len + 1);
            }
            else{
                printf("\n Memory error");
                return -1;
            }

            ++iter;
        }

    }

    res_vec_len = iter;

    regfree(&preg);

    print(*res_str_vec, res_vec_len);

    return res_vec_len;
}

void del_vec(char** str_vec, size_t vec_len)
{
    for(int i = 0; i < vec_len; ++i){
        free(str_vec[i]);
    }
    free(str_vec);
}

