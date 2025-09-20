def cscan_disk(requests, head, direction):
    requests.sort()
    seq = []
    current = head
    seek = 0
    left = [i for i in requests if i < head]
    right = [i for i in requests if i > head]
    direction = direction.lower()

    if direction == "right":
        path = right + [max(requests)] + left
    elif direction == "left":
        path = list(reversed(left)) + [min(requests)] + list(reversed(right))
    else:
        print("Invalid direction! Enter 'left' or 'right'.")
        return None, None
    for i in path:
        seek += abs(current - i)
        seq.append(i)
        current = i

    return seek, seq
    
n = int(input("Enter number of requests: "))

requests = list(map(int, input("Enter request sequence: ").split()))
head = int(input("Enter initial head position: "))
direction = input("Enter direction (left/right): ")

time, seq = cscan_disk(requests, head, direction)

if time is not None:
    print("\nSeek Sequence:", [head] + seq)
    print("Total Seek Time:", time)
