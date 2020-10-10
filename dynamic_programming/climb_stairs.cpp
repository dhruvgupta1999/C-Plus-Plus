/**
 * @file
 * @brief Implementation of Climbing Stairs problem
 *
 * @details
 * problem link: https://leetcode.com/problems/climbing-stairs/
 * It takes n steps to reach to the top of a stair case.
 * Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 *
 * ### Algorithm
 * The idea is that to reach the nth stair, you can take either (n-1)th stair or the (n-2)th stair
 * Therefore the number of ways to reach the nth stair = number of ways to reach (n-1)th stair + number of ways to reach (n-2)th stair
 * 
 *
 * @author [Dhruv](https://github.com/dhruvgupta1999)
 * 
 */

#include <array>
#include <cassert>
#include <climits>
#include <iostream>
/**
 * @namespace dynamic_programming
 * @brief Dynamic Programming algorithms
 */
namespace dynamic_programming {
/**
 * @namespace climb_stairs
 * @brief Implementation of climbing stairs problem
 */
namespace climb_stairs {
/**
 * @brief Calculates number of distinct ways to climb n stairs
 * @param n number of stairs
 * @return distinct ways to climb stairs
 */

int numWaysClimbStairs(const int n) {
    
    int * dp = new int[n+1];
    // initializing base case
    dp[0] = 1;
    dp[1] = 1;
    for(int i =2;i<=n;i++)
    {
        // ith stair can be reached from (i-1)th and (i-2)th stair
        dp[i] = dp[i-1]+dp[i-2];
    }
    int res = dp[n];
    delete [] dp;
    return res;
}
}  // namespace climb_stairs
}  // namespace dynamic_programming

/**
 * @brief Function to test above algorithm
 * @returns void
 */
static void test() {
    // Test 1
    const int n1 = 8;                                           // number of stairs
    
    const int num_ways1 =
        dynamic_programming::climb_stairs::numWaysClimbStairs(n1);
    const int expected_ways1 = 34;
    assert(num_ways1 == expected_ways1);
    std::cout << "number of distinct ways to climb " << n1 << " stairs are " << num_ways1
              << std::endl;

    // Test 2
    const int n2 = 20;                                           // number of stairs
    
    const int num_ways2 =
        dynamic_programming::climb_stairs::numWaysClimbStairs(n2);
    const int expected_ways2 = 10946;
    assert(num_ways2 == expected_ways2);
    std::cout << "number of distinct ways to climb " << n2 << " stairs are " << num_ways2
              << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    // Testing
    test();
    return 0;
}
