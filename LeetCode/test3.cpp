#include <iostream>
#include <vector>

class FrogJump {
public:
    int solution(const std::vector<int>& blocks) {
        if (blocks.size() == 1) {
            return 1;
        }

        int max = 0;
        for (size_t i = 0; i < blocks.size(); i++) {
            int distance = findDistance(i, blocks);
            max = std::max(distance, max);
            if (max == blocks.size()) {
                break;
            }
        }
        return max;
    }

private:
    int findDistance(int startingBlock, const std::vector<int>& blocks) {
        int total = blocks.size();
        int left = startingBlock;
        int right = startingBlock;
        bool leftSide = false;
        bool rightSide = false;
        while (!leftSide || !rightSide) {
            if (right < (total - 1) && canJump(blocks[right], blocks[right + 1])) {
                right++;
            }
            else {
                rightSide = true;
            }

            if (left > 0 && canJump(blocks[left], blocks[left - 1])) {
                left--;
            }
            else {
                leftSide = true;
            }
        }

        return right - left + 1;
    }

    bool canJump(int block1, int block2) {
        return block2 >= block1;
    }
};

int main() {
    FrogJump solution;
    std::vector<int> blocks = { 12, 6, 8, 5 };
    std::cout << solution.solution(blocks) << std::endl;

    return 0;
}
