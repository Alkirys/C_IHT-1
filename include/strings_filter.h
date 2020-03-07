#pragma once
#ifndef UNTITLED1_STRINGS_FILTER_H
#define UNTITLED1_STRINGS_FILTER_H

#endif //UNTITLED1_STRINGS_FILTER_H

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <string.h>

char** grow(char** str_vec, size_t* len);
char** input_str_vec(char** str_vec, size_t* vec_len);
size_t strings_filter(char** str_vec, size_t vec_len, char*** res_str_vec);
void del_vec(char** str_vec, size_t vec_len);