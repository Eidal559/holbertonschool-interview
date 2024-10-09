#!/usr/bin/python3
"""
Log parsing script.

This script reads from standard input line by line and computes metrics based on the input format:
- File size is accumulated.
- HTTP status codes (200, 301, 400, 401, 403, 404, 405, 500) are counted.
Metrics are printed every 10 lines or upon keyboard interruption (CTRL + C).
"""
import sys

stats = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}
sizes = [0]

def print_stats():
    print('File size: {}'.format(sum(sizes)))
    for s_code, count in sorted(stats.items()):
        if count:
            print('{}: {}'.format(s_code, count))

try:
    for i, line in enumerate(sys.stdin, start=1):
        matches = line.rstrip().split()
        try:
            status_code = matches[-2]
            file_size = matches[-1]
            if status_code in stats.keys():
                stats[status_code] += 1
            sizes.append(int(file_size))
        except Exception:
            pass
        if i % 10 == 0:
            print_stats()
    print_stats()
except KeyboardInterrupt:
    print_stats()
    sys.exit(0)  # Graceful exit without traceback
