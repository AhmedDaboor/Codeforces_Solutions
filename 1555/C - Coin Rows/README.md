<h2><a href="https://codeforces.com/contest/1555/problem/C" target="_blank" rel="noopener noreferrer">1555C — Coin Rows</a></h2>

| | |
|---|---|
| **Difficulty** | 1300 |
| **Language** | C++23 (GCC 14-64, msys2) |
| **Verdict** | ✅ Accepted |
| **Problem Link** | [Codeforces 1555C](https://codeforces.com/contest/1555/problem/C) |

## Topics
`brute force` `constructive algorithms` `dp` `implementation`

---

## Problem Statement

<div class="header"><div class="title">C. Coin Rows</div><div class="time-limit"><div class="property-title">time limit per test</div>2 seconds</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file input-standard"><div class="property-title">input</div>standard input</div><div class="output-file output-standard"><div class="property-title">output</div>standard output</div></div><div><p>Alice and Bob are playing a game on a matrix, consisting of $$$2$$$ rows and $$$m$$$ columns. The cell in the $$$i$$$-th row in the $$$j$$$-th column contains $$$a_{i, j}$$$ coins in it.</p><p>Initially, both Alice and Bob are standing in a cell $$$(1, 1)$$$. They are going to perform a sequence of moves to reach a cell $$$(2, m)$$$.</p><p>The possible moves are: </p><ul> <li> Move right — from some cell $$$(x, y)$$$ to $$$(x, y + 1)$$$; </li><li> Move down — from some cell $$$(x, y)$$$ to $$$(x + 1, y)$$$. </li></ul><p>First, Alice makes <span class="tex-font-style-bf">all her moves</span> until she reaches $$$(2, m)$$$. She collects the coins in all cells she visit (including the starting cell).</p><p>When Alice finishes, Bob starts his journey. He also performs the moves to reach $$$(2, m)$$$ and collects the coins in all cells that he visited, <span class="tex-font-style-bf">but Alice didn't</span>.</p><p>The score of the game is the total number of coins Bob collects.</p><p>Alice wants to minimize the score. Bob wants to maximize the score. What will the score of the game be if both players play optimally?</p></div><div class="input-specification"><div class="section-title">Input</div><p>The first line contains a single integer $$$t$$$ ($$$1 \le t \le 10^4$$$) — the number of testcases.</p><p>Then the descriptions of $$$t$$$ testcases follow.</p><p>The first line of the testcase contains a single integer $$$m$$$ ($$$1 \le m \le 10^5$$$) — the number of columns of the matrix.</p><p>The $$$i$$$-th of the next $$$2$$$ lines contain $$$m$$$ integers $$$a_{i,1}, a_{i,2}, \dots, a_{i,m}$$$ ($$$1 \le a_{i,j} \le 10^4$$$) — the number of coins in the cell in the $$$i$$$-th row in the $$$j$$$-th column of the matrix.</p><p>The sum of $$$m$$$ over all testcases doesn't exceed $$$10^5$$$.</p></div><div class="output-specification"><div class="section-title">Output</div><p>For each testcase print a single integer — the score of the game if both players play optimally.</p></div><div class="sample-tests"><div class="section-title">Example</div><div class="sample-test"><div class="input"><div class="title">Input<div title="Copy" data-clipboard-target="#id00468623976024261" id="id0014780001971646417" class="input-output-copier">Copy</div></div><pre id="id00468623976024261">3
3
1 3 7
3 5 1
3
1 3 9
3 5 1
1
4
7
</pre></div><div class="output"><div class="title">Output<div title="Copy" data-clipboard-target="#id003610945083367846" id="id005623543702470494" class="input-output-copier">Copy</div></div><pre id="id003610945083367846">7
8
0
</pre></div></div></div><div class="note"><div class="section-title">Note</div><p>The paths for the testcases are shown on the following pictures. Alice's path is depicted in red and Bob's path is depicted in blue.</p><center> <img class="tex-graphics" src="https://espresso.codeforces.com/b4f742c0500010b79f12902767f16863d1fe3d3c.png" style="max-width: 100.0%;max-height: 100.0%;"> </center></div>