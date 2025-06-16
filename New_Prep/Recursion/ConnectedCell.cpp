#include <iostream>
#include <vector>


//REvisit after Graphs, should be solved efficiently using DFS
void FindLongestConnectedCellsLength(std::vector<std::vector<int>>& matrix)
{
    int size  = 0;
    int maxSize = 0;
    int element = 0;

    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            element = matrix[i][j]

            //row comparsion
            if(element == matrix[i][j+1])
            {

            }

            //column comparison
            if(element == matrix[i+1][j])
            {

            }

            //diagonal comparison
            if(element == matrix[i+1][j+1])
            {

            }

            std::cout << matrix[i][j] << ", ";
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<std::vector<int>> input = {{1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 0},
                              {0, 0, 1, 0, 1},
                              {1, 0, 0, 0, 1},
                              {0, 1, 0, 1, 1}};
    FindLongestConnectedCellsLength(input);
    return 0;
}