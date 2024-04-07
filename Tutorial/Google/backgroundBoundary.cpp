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

#include <iostream>
#include <vector>

using namespace std;

// Function to check if a pixel is a boundary pixel
bool isBoundaryPixel(const vector<vector<int>>& image, int x, int y) {
  // Check if the current pixel is foreground
  if (image[x][y] == 1) {
    // Check the neighbors (up, down, left, right)
    if ((x > 0 && image[x - 1][y] == 0) || // Up
      (x < image.size() - 1 && image[x + 1][y] == 0) || // Down
      (y > 0 && image[x][y - 1] == 0) || // Left
      (y < image[0].size() - 1 && image[x][y + 1] == 0)) // Right
    {
      return true;
    }
  }
  return false;
}

// Function to find and print boundary pixels
void findBoundaryPixels(const vector<vector<int>>& image) {
  for (int i = 0; i < image.size(); i++) {
    for (int j = 0; j < image[i].size(); j++) {
      if (isBoundaryPixel(image, i, j)) {
        cout << "b ";
      }
      else {
        cout << image[i][j] << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  // Example image
  vector<vector<int>> image = {
      {0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 0},
      {0, 1, 1, 1, 1, 0},
      {0, 1, 1, 1, 0, 0},
      {0, 0, 0, 1, 0, 0}
  };

  // Find and print boundary pixels
  findBoundaryPixels(image);

  return 0;
}
