/*

 [ 2, 3, 0, -4, 1] k = 1

result [ [3,2], [1,0] 2,1] ]

expted: [ [3,2], [1,0], [2,1] ]

 x - y = k
 const int x = k + y


 function findPairsWithGivenDifference(arr, k):
    # since we don't allow duplicates, no pair can satisfy x - 0 = y
    if k == 0:
        return []

    map = {}
    answer = []

    for (x in arr):
        map[x - k] = x

    for (y in arr):
        if y in map:
            answer.push([map[y], y])

    return answer

 How can you eliminate this redundancy?

 I am trying to make sense of it

*/