#!/usr/bin/python3
"""
Coin Change Problem - Finding the minimum number of coins to make a given total.
"""

def makeChange(coins, total):
    """
    Determines the minimum number of coins needed to make change for a given total.

    Args:
        coins (list): A list of positive integers representing coin denominations.
        total (int): The target amount.

    Returns:
        int: Minimum number of coins needed to reach total, or -1 if not possible.
    """
    if total <= 0:
        return 0

    # Initialize an array for storing the minimum coins needed for each amount up to total
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: 0 coins needed to make total 0

    # Compute the minimum coins needed for each value from 1 to total
    for t in range(1, total + 1):
        for coin in coins:
            if coin <= t:
                dp[t] = min(dp[t], dp[t - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
