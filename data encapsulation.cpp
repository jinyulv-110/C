#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // 构造函数 
    Student(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }

    // 访问器函数(getter)
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // 修改器函数(setter)
    void setName(string studentName) {
        name = studentName;
    }

    void setAge(int studentAge) {
        if (studentAge > 0) {
            age = studentAge;
        } else {
            cout << "Invalid age!" << endl;
        }
    }

    // 打印学生信息 
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    //创建一个 Student 对象
    Student student1("Alice", 20);

    //访问和修改数据 
    student1.printInfo();

    student1.setName("Bob");
    student1.setAge(22);

    student1.printInfo();

    return 0;
}
