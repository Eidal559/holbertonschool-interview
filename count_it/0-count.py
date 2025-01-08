#!/usr/bin/python3
"""
Module to count keywords in Reddit post titles using the Reddit API.
"""

import requests
import sys


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries the Reddit API, parses titles of hot articles,
    and counts occurrences of specified keywords.

    Args:
        subreddit (str): The name of the subreddit to query.
        word_list (list): List of keywords to count (case-insensitive).
        after (str): The 'after' parameter for pagination.
        word_count (dict): Dictionary to store keyword counts.

    Returns:
        None
    """
    if word_count is None:
        word_count = {word.lower(): 0 for word in word_list}

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'MyAPI/0.0.1'}
    params = {'after': after}

    try:
        response = requests.get(
            url, headers=headers, params=params, timeout=10
        )
        if response.status_code != 200:
            return
        data = response.json()
    except Exception:
        return

    # Process titles in the current page
    for post in data['data']['children']:
        title = post['data']['title'].lower()
        for word in word_count:
            word_count[word] += title.split().count(word)

    # Recursively fetch the next page if available
    after = data['data']['after']
    if after:
        count_words(subreddit, word_list, after, word_count)
    else:
        # Sort and print results once all pages are processed
        sorted_results = sorted(
            word_count.items(), key=lambda x: (-x[1], x[0])
        )
        for word, count in sorted_results:
            if count > 0:
                print(f"{word}: {count}")


if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(
            "Usage: {} <subreddit> <list of keywords>".format(sys.argv[0])
        )
        print(
            "Example: {} programming 'python java javascript'".format(
                sys.argv[0]
            )
        )
    else:
        subreddit = sys.argv[1]
        word_list = sys.argv[2].split()
        count_words(subreddit, word_list)
