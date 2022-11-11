#include <iostream>

using namespace std;

#include <cctype>

#define isdelim(c) (std::isspace((c)) || std::ispunct((c)))
bool is_poli(const char* s, size_t n);
size_t count_poli(const char* s);

int main(void){
    char s[] = "2112, LETO, LETEL, TENET";
    std::cout << "count: " << count_poli(s) << std::endl;
    std::cin.get();
    return 0;
}

//кол-во палиндромов
size_t count_poli(const char* s){
    size_t k = 0, i = 0;
    do {
        if(*s && !isdelim(*s))
            ++i;
        else if(i > 0){
            if(is_poli(s - i, i))
                ++k;
            i = 0;
        }
    } while(*s++ != '\0');
    return k;
}

//проверка на палиндром
bool is_poli(const char* s, size_t n){
    const size_t m = n / 2;
    for(size_t i = 0; i < m; ++i){
        if(s[i] != s[n - 1 - i])
            return false;
    }
    return true;
}
