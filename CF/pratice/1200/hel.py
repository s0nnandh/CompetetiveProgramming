def historyDocuments(input1):
    input1 = str(input1)
    s = input1.split(" ")
    ans = set()
    for x in s:
        if(len(x) == 10 or len(x) == 11):
            ok = 1
            for i in range(10):
                if(i == 2 or i == 5):
                    if(x[i] != '-'):
                        ok = 0
                        break
                else:
                    if(x[i] > '9' or x[i] < '0'):
                        ok = 0
                        break
            if(ok == 1):
                y = ""
                for i in range(6,10):
                    y += x[i]
                # print(y)
                ans.add(y)
    return (len(ans))


            