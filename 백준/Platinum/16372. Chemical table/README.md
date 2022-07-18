# [Platinum III] Chemical table - 16372 

[문제 링크](https://www.acmicpc.net/problem/16372) 

### 성능 요약

메모리: 4964 KB, 시간: 48 ms

### 분류

자료 구조(data_structures), 깊이 우선 탐색(dfs), 분리 집합(disjoint_set), 그래프 이론(graphs), 그래프 탐색(graph_traversal)

### 문제 설명

<p>Innopolis University scientists continue to investigate the periodic table. There are n · m known elements and they form a periodic table, a rectangle with n rows and m columns. Each element can be described by its coordinates (r, c) (1 ≤ r ≤ n, 1 ≤ c ≤ m) in the table. Recently scientists discovered that for every four different elements in this table that form a rectangle with sides parallel to sides of the table, if they have samples of three of four elements, they can produce a sample of the fourth element using nuclear fusion. So if we have elements in positions (r<sub>1</sub>, c<sub>1</sub>), (r<sub>1</sub>, c<sub>2</sub>), (r<sub>2</sub>, c<sub>1</sub>), where r<sub>1</sub> ≠ r<sub>2</sub> and c<sub>1</sub> ≠ c<sub>2</sub>, then we can produce element (r<sub>2</sub>, c<sub>2</sub>).</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d619a22a-dd64-4073-9072-da383feec811/-/preview/" style="width: 416px; height: 142px;"></p>

<p>Original samples of elements as well as newly crafted elements can be used again in future fusions.</p>

<p>Innopolis University scientists already have samples of q elements. They want to obtain samples of all n·m elements. To achieve that, they will purchase some samples from other laboratories and then produce all remaining elements using arbitrary number of nuclear fusions in some order. Help them find the minimal number of elements they need to purchase.</p>

### 입력 

 <p>First line contains three integers n, m, q (1 ≤ n, m ≤ 200 000; 0 ≤ q ≤ min(n·m, 200 000))—chemical table dimensions and the number of elements scientists already have. Following q lines contain two integers r<sub>i</sub>, c<sub>i</sub> (1 ≤ r<sub>i</sub> ≤ n, 1 ≤ c<sub>i</sub> ≤ m) each—descriptions of the elements that scientists already have. All elements in the input are different.</p>

### 출력 

 <p>In the only line print k—the minimal number of elements to be purchased.</p>

