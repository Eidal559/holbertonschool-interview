#!/usr/bin/python3
import sys
import signal

# Variables to store metrics
total_file_size = 0
status_codes = {'200': 0, '301': 0, '400': 0, '401': 0, '403': 0, '404': 0, '405': 0, '500': 0}
line_count = 0

# Function to print metrics
def print_metrics():
    print(f"File size: {total_file_size}")
    for code in sorted(status_codes.keys()):
        if status_codes[code] > 0:
            print(f"{code}: {status_codes[code]}")

# Signal handler to print metrics on keyboard interruption (CTRL + C)
def signal_handler(sig, frame):
    print_metrics()
    sys.exit(0)

# Register signal handler
signal.signal(signal.SIGINT, signal_handler)

# Process each line from stdin
try:
    for line in sys.stdin:
        try:
            parts = line.split()
            if len(parts) < 9:
                continue

            status_code = parts[-2]
            file_size = int(parts[-1])

            # Increment total file size
            total_file_size += file_size

            # Increment status code count
            if status_code in status_codes:
                status_codes[status_code] += 1

            # Increment line counter
            line_count += 1

            # Print metrics after every 10 lines
            if line_count % 10 == 0:
                print_metrics()

        except Exception:
            continue

except KeyboardInterrupt:
    print_metrics()
    sys.exit(0)

# Print final metrics after processing all lines
print_metrics()
