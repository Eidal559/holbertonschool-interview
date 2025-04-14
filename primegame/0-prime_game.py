#!/usr/bin/python3
"""
Prime Game Module

This module contains the implementation of a prime game where players
take turns choosing prime numbers and their multiples from a set
of consecutive integers.
"""


def isWinner(x, nums):
    """
    Determines the winner of the prime game.

    Args:
        x: number of rounds
        nums: an array of n values

    Returns:
        name of the player that won the most rounds, or None if tied
    """
    if not nums or x <= 0:
        return None

    # Function to determine if a number is prime
    def is_prime(n):
        if n <= 1:
            return False
        if n <= 3:
            return True
        if n % 2 == 0 or n % 3 == 0:
            return False
        i = 5
        while i * i <= n:
            if n % i == 0 or n % (i + 2) == 0:
                return False
            i += 6
        return True

    # Pre-compute primes up to the maximum possible n for efficiency
    max_n = max(nums) if nums else 0
    primes_up_to_max = [is_prime(i) for i in range(max_n + 1)]

    # Function to play a single round with n integers
    def play_round(n):
        # Count the number of primes in the range [1, n]
        prime_count = sum(1 for i in range(2, n + 1) if primes_up_to_max[i])

        # Optimal play analysis: whoever has an odd number
        # of primes to choose wins
        # Maria goes first, so if prime_count is odd, Maria wins
        return "Maria" if prime_count % 2 == 1 else "Ben"

    # Play all rounds and count wins
    maria_wins = 0
    ben_wins = 0

    for i in range(min(x, len(nums))):
        winner = play_round(nums[i])
        if winner == "Maria":
            maria_wins += 1
        else:
            ben_wins += 1

    # Return the player with the most wins, or None if tied
    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
