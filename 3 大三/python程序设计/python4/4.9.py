def palindromic(n):
    for i in range(int(len(n)/2)):
        if n[i]!=n[-1-i]:
            return False
    return True
print(palindromic(input()))
