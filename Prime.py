def function(n):
    for i in range(2,n+1):
        p=1
        for j in range(2,i//2):
            if i%j==0:
               p =0
               break
        if p==1:
            print(i) 

