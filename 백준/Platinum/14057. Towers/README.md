# [Platinum III] Towers - 14057 

[문제 링크](https://www.acmicpc.net/problem/14057) 

### 성능 요약

메모리: 50368 KB, 시간: 580 ms

### 분류

이분 탐색(binary_search), 자료 구조(data_structures), 다이나믹 프로그래밍(dp), 스택(stack)

### 문제 설명

<p>City X consists of N buildings, ordered in a row from west to east and numbered from 1 to N. Each building has a different height – an integer number, respectively h<sub>1</sub>, h<sub>2</sub>, …, h<sub>N</sub>. The city government plans to build a tower, which will be in the same row as the buildings (it can be before the first building, between any two of the buildings or after the last building). The tower will broadcast messages to the citizens. The tower must have height H, which should be different from all other buildings’ heights.</p>

<p>Due to some strange engineering ideas, the tower will be able to broadcast signals only to the west (to the beginning of the buildings’ row). The signals are also strange – they are rays which travel horizontally (parallel to the ground, which we consider as a straight line) and are emitted out of the whole body of the tower (from the top to the bottom). So we can imagine that the tower radiates a continuous band of signals with width equal to the tower’s height. When a ray hits a building, it stops. Each building receives the signals using a receiver located on its top. A building receives a message if at least one ray reaches its receiver.</p>

<p>In other words, a building numbered i will receive messages from the tower only when: the building i is to the west of the tower; i is not higher than the tower; and there is no other building j between them (j>i), which is higher than building i. </p>

<p style="text-align: center;"><img alt="" src="https://onlinejudgeimages.s3.amazonaws.com/problem/14057/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202016-12-22%20%EC%98%A4%ED%9B%84%208.20.45.png" style="height:180px; width:480px"></p>

<p>Take a look at the example in the figure above: the buildings, which are able to receive messages are with numbers 2, 5, 6, and 9.</p>

<p>Only one tower will be built, however the city government has received offers for K tower variants, each of different height (and having different building cost). The offered towers are numbered from 1 to K. Each of these towers has its height, which is also different from all the heights of buildings in the town. The city leaders would like to know the maximal number of buildings, which would receive messages, for each of the offered K towers, before they make their decision which one to accept. Of course, calculations should be made assuming optimal placement of each tower.</p>

<p>Write a program towers to determine the maximum number of buildings, which would receive messages for each of the K offers. You will be given the row of buildings in the town (actually, their heights) and the heights of all offered towers. Certainly, you have to consider the optimal placement for each tower.</p>

### 입력 

 <p>Two space separated positive integers are given on the first row of the standard input: N and K – the number of buildings and the number of offered towers.</p>

<p>N space separated positive integers are input from the second row – the heights of the buildings in the town, ordered by the building numbers (from the first to the N-th).</p>

<p>The third row consists of K space separated positive integers – the heights of the offered towers.</p>

### 출력 

 <p>The program should write on a single row of the standard output K space separated non-negative integers: for each offer in the third input row – the maximal number of buildings which would receive messages, if the tower were built, assuming optimal placement.</p>

