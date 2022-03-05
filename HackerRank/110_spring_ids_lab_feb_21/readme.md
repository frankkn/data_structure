# [110_spring_ids_lab] Search

## Link: https://www.hackerrank.com/110-spring-ids-lab-feb-21

Given a sequence of  positive integers, .

It is required to support operations of 3 type:
```
Search(A, key)
```
● return 1 if key is in ; otherwise, return 0
```
Predecessor(A, key)
```
● return the largest integer being smaller than key in  if such integer exists; otherwise, return 0
```
Successor(A, key)
```
● return the smallest integer being larger than key in  if such integer exists; otherwise, return 0

There will be  queries of either type.

Each query is an ordered pair of integers: (operation id, key).

The operation ids for search, predecessor, and successor are 1, 2, and 3 respectively.

Please try your best to respond these queries correctly and efficiently.

**Input Format**

● 1st line: n
● 2nd line: A( A~i~are seperated by single space)
● 3rd line: 
● 4th ~ (m+3)th lines: queries

**Constraints**

● 1 \leq n \leq 2 \ast $10^5$
 key 
Output Format

 lines of response

Sample Input 0

5
7 4 2 9 6
10
1 4
1 5
2 1
2 2
2 4
2 8
3 1
3 2
3 9
3 10
Sample Output 0

1
0
0
0
2
7
2
4
0
0
Explanation 0

Sample input 0
5 

7 4 2 9 6 

10 

1 4  Search 4

1 5

2 1  Predecessor 1

2 2

2 4

2 8

3 1  Successor 1

3 2

3 9

3 10

Sample output 0
1  4 is in 

0

0  there is no predecessor of 1 in 

0

2

7

2  successor of 1 in  is 2

4

0

0
