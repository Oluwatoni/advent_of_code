#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_map>

int main()
{
    // For the first half
    // Create the two min heaps(queues)
    std::priority_queue<int, std::vector<int>, std::greater<int> > left_pq, right_pq;

    // For the second half
    std::vector<int> left_list;
    std::unordered_map<int, size_t> right_counter;

    // Load the input file
    std::ifstream file("test_1.txt");
    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream linestream(line);
        std::string data;
        int left_val, right_val;

        linestream >> left_val;
        linestream >> right_val;

        // Build the min heaps as the file is loaded
        left_pq.push(left_val);
        right_pq.push(right_val);

        // Build the right dictionary to count the occurence of each ID
        if (right_counter.find(right_val) == right_counter.end())
        {
            right_counter[right_val] = 1;
        }
        else
        {
            right_counter[right_val]++;
        }

        // Build the left list
        left_list.push_back(left_val);
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

    // For the second part
    int similarity_score = 0;
    for (int val : left_list)
    {
        if (right_counter.find(val) != right_counter.end())
        {
            similarity_score += val * right_counter[val];
        }
    }

    std::cout << "similarity score: " << similarity_score << std::endl;
    return 0;
}