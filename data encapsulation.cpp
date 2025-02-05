#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    // ���캯�� 
    Student(string studentName, int studentAge) {
        name = studentName;
        age = studentAge;
    }

    // ����������(getter)
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    // �޸�������(setter)
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

    // ��ӡѧ����Ϣ 
    void printInfo() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

int main() {
    //����һ�� Student ����
    Student student1("Alice", 20);

    //���ʺ��޸����� 
    student1.printInfo();

    student1.setName("Bob");
    student1.setAge(22);

    student1.printInfo();

    return 0;
}
