#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <iomanip> // std::setw()


int rottenOranges(std::vector<std::vector<int>>& oranges)
{
    // this is what we want to calculate
    int time_elapsed = 0;

    // rows and cols of the fruit bucket
    int rows = oranges.size();
    int cols = oranges[0].size();
    

    // count number of fresh oranges, if not then we are done
    // also if rotton orange is found, add to queue and change its state to -1 (processed)
    int total_fresh = 0;
    enum state{ processed = -1, empty, fresh, rotten };
    std::queue<std::pair<int, int>> bfs_queue;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int& orange = oranges[i][j];
            if (orange == state::fresh)
                total_fresh++;
            
            else if (orange == state::rotten)
            {
                bfs_queue.push({i, j});
                orange = state::processed;
            }
        }
    }
    if (!total_fresh)
        return 0;
    
    // bfs to rot all oranges, 1 minute for each iteration
    while (bfs_queue.size())
    {
        // run 1 iteration of rotton process
        int queue_size = bfs_queue.size();
        for (int i = 0; i < queue_size; i++)
        {
            // there is a rotton orange
            std::pair<int, int> next_rottenOrange = bfs_queue.front();
            bfs_queue.pop();
            
            // grab the location
            int row = next_rottenOrange.first;
            int col = next_rottenOrange.second;
            
            // now rotton left, right, below, above
            const std::vector<std::pair<int, int>> adj{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto adj_orange: adj)
            {
                // rotton adjacent orange
                int offset_row = row + adj_orange.first;
                int offset_col = col + adj_orange.second;
                
                // boundary chek
                if (offset_row >= 0 && offset_row < rows &&
                    offset_col >= 0 && offset_col < cols)
                {
                    int& orange = oranges[offset_row][offset_col];
                    
                    // if the orange is already rotton or it is empty, skip it
                    if (orange == state::processed || orange == state::empty)
                        continue;
                    
                    // or if it is a fresh orange, it become rotton,
                    // in which we should add to it to rotton list for next iteration
                    else if (orange == state::fresh)
                    {
                        total_fresh = total_fresh - 1;
                        orange = state::rotten;
                        bfs_queue.push({offset_row, offset_col});
                    }
                }
            }
        }
        time_elapsed = time_elapsed + 1;
        for (auto vec: oranges)
        {
            for (auto val: vec)
            {
                std::cout << std::setw(3) << val;
            }
            std::cout << '\n';
        }
        std::cout << '\n';
        if (total_fresh == 0)
            break;
    }
    return total_fresh ? -1 : time_elapsed;
}

int main()
{
    std::vector<std::vector<int>> arr{ {2, 1, 0, 2, 1},
                                        {1, 0, 1, 2, 1},
                                        {1, 0, 0, 2, 1}};
    std::cout << rottenOranges(arr) << '\n';

    return 0;
}

