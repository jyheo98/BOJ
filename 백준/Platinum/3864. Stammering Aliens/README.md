# [Platinum II] Stammering Aliens - 3864 

[문제 링크](https://www.acmicpc.net/problem/3864) 

### 성능 요약

메모리: 16896 KB, 시간: 856 ms

### 분류

이분 탐색(binary_search), 매개 변수 탐색(parametric_search), 문자열(string), 접미사 배열과 LCP 배열(suffix_array)

### 문제 설명

<p>Dr. Ellie Arroway has established contact with an extraterrestrial civilization. However, all efforts to decode their messages have failed so far because, as luck would have it, they have stumbled upon a race of stuttering aliens! Her team has found out that, in every long enough message, the most important words appear repeated a certain number of times as a sequence of consecutive characters, even in the middle of other words. Furthermore, sometimes they use contractions in an obscure manner. For example, if they need to say bab twice, they might just send the message babab, which has been abbreviated because the second b of the first word can be reused as the first b of the second one.</p>

<p>Thus, the message contains possibly overlapping repetitions of the same words over and over again. As a result, Ellie turns to you, S.R. Hadden, for help in identifying the gist of the message.</p>

<p>Given an integer m, and a string s, representing the message, your task is to find the longest substring of s that appears at least m times. For example, in the message baaaababababbababbab, the length-5 word babab is contained 3 times, namely at positions 5, 7 and 12 (where indices start at zero). No substring appearing 3 or more times is longer (see the first example from the sample input). On the other hand, no substring appears 11 times or more (see example 2).</p>

<p>In case there are several solutions, the substring with the rightmost occurrence is preferred (see example 3).</p>

### 입력 

 <p>The input contains several test cases. Each test case consists of a line with an integer m (m ≥ 1), the minimum number of repetitions, followed by a line containing a string s of length between m and 40 000, inclusive. All characters in s are lowercase characters from “a” to “z”. The last test case is denoted by m = 0 and must not be processed.</p>

### 출력 

 <p>Print one line of output for each test case. If there is no solution, output none; otherwise, print two integers in a line, separated by a space. The first integer denotes the maximum length of a substring appearing at least m times; the second integer gives the rightmost starting position of this substring.</p>

