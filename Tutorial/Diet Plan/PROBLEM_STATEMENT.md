```
[Programming Test]

Bob eats bread every day.
One day, he decides to go on a diet for "N" days.
He gains "C(i)"kg of weight when he eats bread on "i" day from the
start of his diet plan.
Also, if he stops eating bread for a day, he can lose "A"kg of weight.

However, Bob feels stressed when he doesn't eat bread.
If he doesn't eat bread, the "stress point" will increase "1 point",
and his weight will increase by "B * (stress point)" kg at the end of
the day.
The "stress point" at the start of this diet plan is 0.
Also, every time after he eats bread, the stress point returns to 0.

Please note that on each day, his weight changes after a change in stress point.

If Bob's weight before the start of the diet plan is "W"kg, how many
kg is the minimum weight in "N" days diet?


Please write the programming code to calculate how many kg is the
minimum weight in "N" days diet? And make the plan which date he
should eat & whcih date he shouldn't eat.
Variable number: N, W, A, B, C(i)

1≤N≤100
1≤W≤100
0≤A≤10
0≤B≤10
0≤C(i)≤10

[Example 1]
--------  
input
--------
N=5
W=70
A=3
B=2
C(1)=4
C(2)=6
C(3)=2
C(4)=5
C(5)=3

--------
output of Example 1
--------
1st day= eat
2nd day= not eat
3rd day= eat
4th day= not eat
5th day= not eat

minimum weight is "50"kg.


[Example 2]
--------
input
--------
N=20
W=70
A=3
B=2
C(1)=4
C(2)=6
C(3)=2
C(4)=5
C(5)=3
C(6)=4
C(7)=5
C(8)=4
C(9)=1
C(10)=3
C(11)=4
C(12)=3
C(13)=2
C(14)=1
C(15)=2
C(16)=1
C(17)=4
C(18)=2
C(19)=1
C(20)=3
--------
output of Example 2
--------
1st day= eat
2nd day= not eat
3rd day= eat
4th day= not eat
5th day= not eat
6th day= not eat
7th day= not eat
8th day= not eat
9th day= not eat
10th day= not eat
11th day= not eat
12th day= not eat
13th day= not eat
14th day= not eat
15th day= not eat
16th day= not eat
17th day= not eat
18th day= not eat
19th day= not eat
20th day= not eat
minimum weight is "50"kg.
```