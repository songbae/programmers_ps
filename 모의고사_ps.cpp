def solution(answers) :
    answer = []
    a = [1, 2, 3, 4, 5]
    b = [2, 1, 2, 3, 2, 4, 2, 5]
    c = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]
    score = [0, 0, 0]
    for k in range(3) :
        ans = []
        for i in range(len(answers)) :
            if k == 0 :
                ans.append(a[i % 5])
                elif k == 1 :
                ans.append(b[i % 8])
                elif k == 2 :
                ans.append(c[i % 10])
                for j in range(len(answers)) :
                    if ans[j] == answers[j] :
                        score[k] += 1
                        for i in range(3) :
                            if max(score) == score[i] :
                                answer.append(i + 1)

                                return answer