#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i <= participant.size(); i++) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
    }

}
// ÆÄÀÌ½ã 
import collections


def solution(participant, completion) :
    answer = collections.Counter(participant) - collections.Counter(completion)
    return list(answer.keys())[0]