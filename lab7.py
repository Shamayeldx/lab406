def scan_disk(requests, head, direction):
    requests.sort()
    seq = []
    current = head
    seek = 0
    left = [i for i in requests if i < head]
    right = [i for i in requests if i > head]
    if direction == "left":
        path = list(reversed(left)) + right
    else:
        path = right + list(reversed(left))
    for i in path:
        seek += abs(current - i)
        seq.append(i)
        current = i
    return seek, seq

n = int(input("Enter number of requests: "))
requests = list(map(int, input("Enter request sequence: ").split()))
head = int(input("Enter initial head position: "))
direction = input("Enter direction (left/right): ").lower()
time, seq = scan_disk(requests, head, direction)
print("\nSeek Sequence:", [head] + seq)
print("Total Seek Time:", time)
