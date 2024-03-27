#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Student{
    public:
        string name;
        int height;
        int weight;

        Student(string name, int height, int weight){
            this->name = name;
            this->height = height;
            this->weight = weight;
        }
};

int n;

vector<Student> v;

bool cmp(Student a, Student b){
    return a.height < b.height;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin >> n;
    string str1;
    int h, w;
    for(int i = 0; i < n; i++){
        cin >> str1 >> h >> w;
        v.push_back(Student(str1, h, w));
    }

    sort(v.begin(), v.end(), cmp);

    for(int i = 0; i < n; i++){
        cout << v[i].name << ' ' << v[i].height << ' ' << v[i].weight <<'\n';
    }

    return 0;
}