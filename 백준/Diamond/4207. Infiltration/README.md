# [Diamond V] Infiltration - 4207 

[문제 링크](https://www.acmicpc.net/problem/4207) 

### 성능 요약

메모리: 2028 KB, 시간: 832 ms

### 분류

백트래킹(backtracking), 비트마스킹(bitmask), 비트 집합(bitset), 브루트포스 알고리즘(bruteforcing), 그래프 이론(graphs), 수학(math)

### 문제 설명

<p>Good morning, agent W-12. Your mission, should you choose to accept it, is as follows.</p>

<p>We are inﬁltrating the ever so insidious Association of Chaos and Mischief (ACM) in order to take down their command structure. Unfortunately, they appear to be prepared for such an eventuality, and have given their command structure an annoyingly complex design which makes our inﬁltration quite difﬁcult.</p>

<p>The ACM command structure is divided into several cells. For each pair of cells A and B, either A controls B or B controls A. But this “control” relation can be cyclic, so it could happen that A controls B and B controls C and C controls A.</p>

<p>We can send in agents to inﬁltrate any particular cell, which gives us control over that cell and the cells that it controls, but not any other cells. So in the example above, inﬁltrating A would give us control over A and B, but not C.</p>

<p>For a successful inﬁltration of the ACM, we must obtain control over all of its cells, otherwise the cells that are out of our control will discover us and start causing some of their trademark chaos and mischief. As you know, we’re on a tight spending leash from higher authority these days, so we need to execute this mission as efﬁciently as possible. Your mission is to ﬁgure out the minimum number of cells we need to inﬁltrate in order to succeed.</p>

<p>This mission brieﬁng will self-destruct in ﬁve hours. Good luck!</p>

### 입력 

 <p>The ﬁrst line of a test case contains the number n of cells the ACM has (1 ≤ n ≤ 75). Each of the next n lines contains a binary string of length n where the i<sup>th</sup> character of the j<sup>th</sup> line is 1 if cell j controls cell i, and 0 otherwise (1 ≤ i, j ≤ n).</p>

<p>The i<sup>th</sup> character of the i<sup>th</sup> line is 0 and for i ≠ j, either the i<sup>th</sup> character of the j<sup>th</sup> line is 1 or the j<sup>th</sup> character of the i<sup>th</sup> line is 1, but not both.</p>

### 출력 

 <p>For each test case, display its case number followed by the minimum number m of cells that must be inﬁltrated to obtain complete control of the ACM. Then display m numbers c<sub>1</sub>, ..., c<sub>m</sub> in any order, indicating the list of cells to inﬁltrate (cells are numbered from 1 to n). If more than one set of m cells gives complete control, any one will be accepted.</p>

