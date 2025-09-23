
requests = [98, 183, 37 ,122, 14, 124 ,65, 67]
head = 53

seek_sequence = []
total_seek = 0
current = head
pending = requests.copy()

while pending:
    nearest = min(pending, key=lambda x: abs(current - x))
    seek_sequence.append(nearest)
    total_seek += abs(current - nearest)
    current = nearest
    pending.remove(nearest)

print("Seek Sequence:", " -> ".join(map(str, seek_sequence)))
print("Total Seek Time:", total_seek)
print("Average Seek Time:", total_seek / len(requests))

