# [Platinum IV] Brexit Negotiations - 16602 

[문제 링크](https://www.acmicpc.net/problem/16602) 

### 성능 요약

메모리: 30680 KB, 시간: 288 ms

### 분류

그래프 이론(graphs), 그리디 알고리즘(greedy), 위상 정렬(topological_sorting)

### 문제 설명

<p>As we all know, Brexit negotiations are on their way—but we still do not know whether they will actually finish in time.</p>

<p>The negotiations will take place topic-by-topic. To organise the negotiations in the most effective way, the topics will all be discussed and finalised in separate meetings, one meeting at a time.</p>

<p>This system exists partly because there are (non-cyclic) dependencies between some topics: for example, one cannot have a meaningful talk about tariffs before deciding upon the customs union. The EU can decide on any order in which to negotiate the topics, as long as the mentioned dependencies are respected and all topics are covered.</p>

<p>Each of the topics will be discussed at length using every available piece of data, including key results from past meetings. At the start of each meeting, the delegates will take one extra minute for each of the meetings that has already happened by that point, even unrelated ones, to recap the discussions and understand how their conclusions were reached. See Figure B.1 for an example.</p>

<p>Nobody likes long meetings. The EU would like you to help order the meetings in a way such that the longest meeting takes as little time as possible.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/0ba313f1-164a-493b-a03b-a4ef58c2d39b/-/preview/" style="width: 541px; height: 103px;"></p>

<p style="text-align: center;">Figure B.1: Illustration of how time is spent in each meeting in a solution to Sample Input 2.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line containing an integer n (1 ≤ n ≤ 4 · 10<sup>5</sup>), the number of topics to be discussed. The topics are numbered from 1 to n.</li>
	<li>n lines, describing the negotiation topics.<br>
	The ith such line starts with two integers e<sub>i</sub> and d<sub>i</sub> (1 ≤ e<sub>i</sub> ≤ 10<sup>6</sup>, 0 ≤ d<sub>i</sub> < n), the number of minutes needed to reach a conclusion on topic i and the number of other specific topics that must be dealt with before topic i can be discussed.<br>
	The remainder of the line has di distinct integers b<sub>i,1</sub>, . . . , b<sub>i,d<sub>i</sub></sub> (1 ≤ b<sub>i,j</sub> ≤ n and b<sub>i,j</sub> ≠ i for each j), the list of topics that need to be completed before topic i.</li>
</ul>

<p>It is guaranteed that there are no cycles in the topic dependencies, and that the sum of d<sub>i</sub> over all topics is at most 4 · 10<sup>5</sup>.</p>

### 출력 

 <p>Output the minimum possible length of the longest of all meetings, if meetings are arranged optimally according to the above rules.</p>

