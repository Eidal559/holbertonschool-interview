#!/usr/bin/python3

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

    # Function to play a single round with n integers
    def play_round(n):
        # Create a set of available numbers from 1 to n
        numbers = set(range(1, n + 1))

        # Alternate turns until someone loses
        maria_turn = True

        while numbers:
            # Find available primes
            primes = [num for num in numbers if is_prime(num)]

            # If no primes left, current player loses
            if not primes:
                return "Ben" if maria_turn else "Maria"

            # Choose optimal move (smallest prime is optimal)
            chosen_prime = min(primes)

            # Remove the chosen prime and its multiples
            multiples = {chosen_prime}
            for num in numbers:
                if num % chosen_prime == 0:
                    multiples.add(num)

            # Update available numbers
            numbers -= multiples

            # Switch turns
            maria_turn = not maria_turn

        # If we run out of numbers, the last player to move wins
        return "Ben" if maria_turn else "Maria"

    # Play all rounds and count wins
    maria_wins = 0
    ben_wins = 0

    for i in range(x):
        if i < len(nums):
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
