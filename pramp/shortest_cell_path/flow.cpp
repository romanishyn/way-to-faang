/*

{{1, 1, 1, 1},
 {0, 0, 0, 1},
 {1, 1, 1, 1}},
 shortestCellPath( {{1, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 1, 1}}, 0, 0, 0, 1);

 The idea is inspired from Lee algorithm and uses BFS.

We start from the source cell and calls BFS procedure.
We maintain a queue to store the coordinates of the matrix and initialize it with the source cell.
We also maintain a Boolean array visited of same size as our input matrix and initialize all its elements to false.
We LOOP till queue is not empty
Dequeue front cell from the queue
Return if the destination coordinates have reached.
For each of its four adjacent cells, if the value is 1 and they are not visited yet, we enqueue it in the queue and also mark them as visited.
Note that BFS works here because it doesn’t consider a single path at once. It considers all the paths starting from the source and moves ahead one unit in all those paths at the same time which makes sure that the first time when the destination is visited, it is the shortest path.

*/