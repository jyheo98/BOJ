# [Platinum III] Turns - 8352 

[문제 링크](https://www.acmicpc.net/problem/8352) 

### 성능 요약

메모리: 22212 KB, 시간: 244 ms

### 분류

문자열(string), 접미사 배열과 LCP 배열(suffix_array)

### 문제 설명

<p>Byteman decided to go for a ride in his car to the mountains. He took a map with him, however, he is not able to locate himself on the map.</p>

<p>The road on the map is represented by <em>n</em> turns, each of which is 90° turn to the right or to the left. For simplicity we can represent the map by <em>n</em>-letter string consisting of <code>L</code> and/or <code>P</code> letters.</p>

<p>Assuming that Byteman has the <em>i</em>'th turn in front of him (he might not know, however, that it is the <em>i</em>'th turn), by <em>a<sub>i</sub></em> we represent the number of turns Byteman has to drive through, in order to be sure in which place on the map he is located.</p>

<p>We will explain the meaning of the number <em>a<sub>i</sub></em> using an example. Let's assume that road on the map is represented by a string <code>LLPPLPL</code> (<code>L</code> represents a left turn and <code>P</code> - a right turn, for "prawo" means right in Polish). If Byteman is in front of his second turn, before passing that turn he knows that he could be in front of one of the turns: 1, 2, 5 or 7 (as he sees a left turn in front of him). After passing that turn, Byteman sees a turn to the right - <code>P</code>, which means that initially he could not had been in front of the first turn (as the following turn was to the left) as well as the last turn (as it is followed by the end of the road). Therefore, he knows that he is in front of third or sixth turn on the map. After passing that turn, Byteman sees a turn to the right - <code>P</code>, which means that initially he could not had been in front of the fifth turn. This leads to the observation, that after passing two turns Byteman is in front of the fourth turn, so <em>a</em><sub>2</sub> = 2.</p>

<p>Write a program which:</p>

<ul>
	<li>reads a description of the map from the standard input,</li>
	<li>determines <em>a<sub>i</sub></em> values, for 1 ≤ i ≤ n,</li>
	<li>writes the result to the standard output.</li>
</ul>

### 입력 

 <p>The first line of the input contains one integer <em>n</em> (1 ≤ <em>n</em> ≤ 500 000). The second line contains description of the road - <em>n</em> letters <code>L</code> and/or <code>P</code>, without any spaces.</p>

### 출력 

 <p>Your program should write to the output exactly <em>n</em> lines. The <em>i</em>'th line should contain one integer: <em>a<sub>i</sub></em>.</p>

