#include <stack>
template<typename T>
class Human : public std::stack<T>  {
    int age_;
public:
    void SetAge(int age_) {
        this->age_ = age_;
    }
};