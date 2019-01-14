def function(n):
    for i in range(2,n+1):
        p = True
        for j in range(2,i//2):
            if i%j==0:
               p = False
               break
        if p:
            print(i) 

