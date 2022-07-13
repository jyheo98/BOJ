# [Silver II] Climbing - 8273 

[문제 링크](https://www.acmicpc.net/problem/8273) 

### 성능 요약

메모리: 5928 KB, 시간: 124 ms

### 분류

애드 혹(ad_hoc), 그리디 알고리즘(greedy), 구현(implementation)

### 문제 설명

<p>The Byteburg University holds a climbing course. 2<em>n</em> students can attend the course simultaneously. Each of the climbers has their own separate climbing route along which they can go either upwards or downwards. The climbers are divided into <em>n</em> pairs, with the climbers in each pair climbing on adjacent routes and attached to the same belay rope. Each rope is attached at the top of the wall in a point lying between two routes and should be tense at all times.</p>

<p>The length of each rope is not greater than the height of the climbing wall. When one climber in a pair has reached the top of the wall, the other climber from the pair cannot go downwards.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 100px; width: 24px;"></p>

<p align="center">Figure: A pair of climbers attached to a single rope.</p>

<p>Every climber has exactly one adjacent climber to the left and to the right apart from the leftmost and the rightmost climbers who have just one adjacent climber. The climbing instructor has given an exercise to his students: they are to adjust their heights in such a way that there are as many pairs of <b>adjacent</b> climbers from <b>different</b> ropes hanging at the same heights as possible. Help the climbers and find the maximum number of such adjacent climbers.</p>

### 입력 

 <p>The first line of the standard input contains one integer <em>n</em> (1 ≤ <em>n</em> ≤ 500 00) that denotes the number of pairs of climbers. The following <em>n</em> lines contain descriptions of climbers from the respective pairs, given from left to right. Each line contains two integers <em>a</em>, <em>b</em> (0 ≤ <em>a</em>, <em>b</em> ≤ 10<sup>9</sup>) that denote the distances of the climbers in the pair from the point where their rope is attached.</p>

### 출력 

 <p>The first and only line of the standard output should contain one integer equal to the maximum number of adjacent pairs of climbers from different ropes that can align at the same height.</p>

