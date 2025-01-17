#include <stdio.h>
#include <stdlib.h>

#define NAME_LENGTH 1024
#define STU_COUNT 5

struct stu_info {
    size_t id;
    char name[NAME_LENGTH];
    unsigned short grade;
};

int stu_info_grade_greater(const void* left_ptr, const void* right_ptr) {
    struct stu_info left_info = *(const struct stu_info*)left_ptr;
    struct stu_info right_info = *(const struct stu_info*)right_ptr;
    
    if (left_info.grade > right_info.grade) {
        return -1;
    } else if (left_info.grade < right_info.grade) {
        return 1;
    } else {
        return 0;
    }
}

void print_sorted_info(struct stu_info* info_array_ptr, size_t array_size) {
    qsort(info_array_ptr, array_size, sizeof(struct stu_info), stu_info_grade_greater);

    for (size_t index = 0; index < STU_COUNT; index++) {
        printf_s("Information of student %u is :\n", index + 1);

        printf_s("ID : %u\n", info_array_ptr[index].id);
        printf_s("Name : %s\n", info_array_ptr[index].name);
        printf_s("Grade : %u\n", info_array_ptr[index].grade);
    }
}

int main(int, char**){
    struct stu_info info_array[STU_COUNT] = {};

    for (size_t index = 0; index < STU_COUNT; index++) {
        printf_s("Reading the information from student %u\n", index + 1);

        printf_s("Input the ID of student %u : ", index + 1);
        scanf_s("%u", &info_array[index].id);

        printf_s("Input the name of student %u : ", index + 1);
        scanf_s("%s", info_array[index].name);


        printf_s("Input the grade of student %u : ", index + 1);
        scanf_s("%u", &info_array[index].grade);
    }

    print_sorted_info(info_array, STU_COUNT);
}
