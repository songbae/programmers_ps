#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());
    for (auto T : phone_book)cout << T << " ";
    for (int i = 0; i < phone_book.size() - 1; i++) {
        if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()))
            return false;
    }
    return answer;
}
//���̽� 
def solution(phone_book) :
    answer = True
    phone_book.sort(key = lambda x : len(x))
    for i in range(len(phone_book) - 1) :
        if phone_book[i] == phone_book[i + 1][:len(phone_book[i])] :
            return False
            return answer
