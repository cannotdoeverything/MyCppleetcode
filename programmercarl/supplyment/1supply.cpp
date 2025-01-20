/*现出String类的构造函数、拷贝构造函数、赋值函数以及析构函数
C++ 中动态内存管理：如何正确地分配与释放内存。
深拷贝与浅拷贝的区别：当对象之间共享资源时，如何避免潜在问题。
运算符重载的实现：尤其是赋值运算符和输出运算符的重载。
现代 C++ 特性：包括移动语义、右值引用等。
https://www.ppmy.cn/devtools/116825.html
*/
#include<iostream>
#include <cstring>
using namespace std;

class String{
public:
    String(const char* str = nullptr);
    String(const String &rhs);  //拷贝构造函数
    ~String();
    String &operator = (const String &rhs);
    void print() const { cout << (data ? data : "") << endl; } //常量成员函数。
private:
    char* data;
};

String::String(const char*str){
    if(str == nullptr){
        data = new char(1); //分配一个字节的内存
        *data = '\0';   //初始化为空字符串
    }else{
        int len = strlen(str);  //计算字符串长度
        data  = new char[len+1]; //为字符串分配足够的内存 (包括结尾的 '\0')
        strcpy(data,str);       //将传入的字符串拷贝到 data 中 char* strcpy(char* destination, const char* source);
    }
}
String::~String(){
    if(data != nullptr){
        delete[] data;
        data = nullptr;     //将 data 设置为 nullptr，防止悬空指针
    }
}
String::String(const String&rhs){
    int len = strlen(rhs.data);     //获取 rhs 的字符串长度
    data = new char[len+1];         //分配内存
    strcpy(data, rhs.data);         //深拷贝字符串内容
}
String &String::operator = (const String &rhs){     //赋值运算符重载
    if(this == &rhs){           //// 检查是否是自赋值
        return *this;
    }
    delete [] data;
    int len = strlen(rhs.data);
    data = new char[len+1];
    strcpy(data, rhs.data);
    return *this;
}

int main() {
    String str1("Hello");
    String str2(str1); // 拷贝构造函数
    String str3;
    str3 = str1;       // 赋值运算符重载

    cout << "str1: ";
    str1.print();
    cout << "str2: ";
    str2.print();
    cout << "str3: ";
    str3.print();

    return 0;
}