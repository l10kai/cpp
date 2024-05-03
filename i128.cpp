#include <bits/stdc++.h>  
using i128 [[maybe_unused]] = __int128;  
const i128 &INT128_MAX = (i128(INT64_MAX) << 64) | UINT64_MAX;  
const i128 &INT128_MIN = ~INT128_MAX;  
#if __cplusplus >= 201103L  
i128 operator ""_i(const std::size_t value) {  
    return i128(value);  
}  
i128 operator ""_i(const char *str, std::size_t len) {  
    bool f = str[0] == '-';  
    if (not std::all_of(str + f, str + len, isdigit))  
        throw std::invalid_argument("无法转换为整数");  
    i128 value = 0;  
    for (int i = 0 + f; i < len; ++i)  
        value = (value << 3) + (value << 1) + (str[i] ^ '0');  
    return f ? -value : value;  
}  
#endif  
std::istream &operator>>(std::istream &is, i128 &value) {  
    value = 0;  
    bool isNegative = false;  
    int c = is.get();  
    while (not isdigit(c)) {  
        if (c == '-')  
            isNegative = true;  
        c = is.get();  
    }  
    while (isdigit(c)) {  
        value = (value << 3) + (value << 1) + (c ^ '0');  
        c = is.get();  
    }  
    if (isNegative)  
        value = -value;  
    return is;  
}  
std::ostream &operator<<(std::ostream &os, i128 value) {  
    static char sta[40];  
    unsigned char top = 0;  
    if (value < 0) {  
        sta[top++] = static_cast<char>(-(value % 10));  
        value /= 10;  
        value = ~value + 1;  
        os.put('-');  
    }  
    for (; value; value /= 10)  
        sta[top++] = static_cast<char>(value % 10);  
    for (; top--;)  
        os.put(static_cast<char>(sta[top] ^ '0'));  
    return os;  
}