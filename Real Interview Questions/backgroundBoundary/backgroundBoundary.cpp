/*
Q: Given a binary image, with pixel value equal to 0(background) or 1 (foreground),
find the boundary pixels.

* A pixel is a boundary pixel if
(1) It's foreground (pixel value = 1) AND
(2) It has at least 1 background pixel among its 4 neighbors (up, bottom, left, right).

[Note: Pixels on the image border do not have 4 neighbors, see below]

Example
Image:
0 0 0 0 0 0
0 1 1 1 0 0
0 1 1 1 1 0
0 1 1 1 0 0
0 0 0 1 0 0

Boundary pixels (marked as b)
0 0 0 0 0 0
0 b b b 0 0
0 b 1 1 b 0
0 b b b 0 0
0 0 0 b 0 0
*/