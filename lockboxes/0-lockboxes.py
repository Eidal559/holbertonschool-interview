#!/usr/bin/python3

def canUnlockAll(boxes):
    opened = [False] * len(boxes)
    opened[0] = True
    keys = boxes[0]
    
    while keys:
        new_key = keys.pop()
        if new_key < len(boxes) and not opened[new_key]:
            opened[new_key] = True
            keys.extend(boxes[new_key])
    
    return all(opened)

# Testing with the provided examples
if __name__ == "__main__":
    boxes = [[1], [2], [3], [4], []]
    print(canUnlockAll(boxes))  # True

    boxes = [[1, 4, 6], [2], [0, 4, 1], [5, 6, 2], [3], [4, 1], [6]]
    print(canUnlockAll(boxes))  # True

    boxes = [[1], [4], [2], [0, 4, 1], [3], [3], [5, 6]]
    print(canUnlockAll(boxes))  # False
