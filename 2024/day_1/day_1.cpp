#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>


int main()
{
    // Create the two min heaps(queues)
    std::priority_queue<int, std::vector<int>, std::greater<int> > left_pq, right_pq;

    // Load the input file
    std::ifstream file("test_2.txt");
    std::string line;

    // Build the min heaps as the file is loaded
    while(std::getline(file, line))
    {
        std::stringstream linestream(line);
        std::string data;
        int left_val, right_val;

        linestream >> left_val;
        linestream >> right_val;
        
        left_pq.push(left_val);
        right_pq.push(right_val);
    }
    file.close();

    int distance_sum = 0;
    const int pq_size = left_pq.size();
    // sum the distances of the min values between them
    for (size_t i = 0; i < pq_size; ++i)
    {
        const int left_min = left_pq.top();
        left_pq.pop();
        const int right_min = right_pq.top();
        right_pq.pop();

        distance_sum += abs(left_min - right_min);
    }

    std::cout << "total sum: " << distance_sum << std::endl;
    return 0;
}