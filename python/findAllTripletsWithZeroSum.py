def findAllTripletsWithZeroSum(arr,n):
    found = False
   
    arr.sort()

    for i in range(0,n-2):
        x = arr[i]
        l = i + 1
        r = n - 1

        while l < r:
            if x + arr[l] + arr[r] == 0:
                print "num1 = %d  num2 = %d num3 = %d" % (x,arr[l],arr[r])
                found = True
                l = l+1
                r = r-1
            elif x + arr[l] + arr[r] < 0:
                l = l+1
            else:
                r = r-1

    if found == False:
        print('No Triplet Found')

#arr = [0,-1,2,-3,1]
arr = [0,-1,2,-3,0]
n = len(arr)
findAllTripletsWithZeroSum(arr,n)
