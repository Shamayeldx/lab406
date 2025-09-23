

processes = ['P1', 'P2', 'P3', 'P4']
arrival_time = [0,1,2,3,]
burst_time   = [6,8,7,3,]

n = len(processes)

proc_list = []
for i in range(n):
    proc_list.append([processes[i], arrival_time[i], burst_time[i], 0, 0, 0, 0])

time = 0
completed = 0

while completed < n:

    ready_queue = [p for p in proc_list if p[1] <= time and p[6] == 0]

    if ready_queue:

        ready_queue.sort(key=lambda x: x[2])
        current = ready_queue[0]


        idx = proc_list.index(current)
        time += proc_list[idx][2]
        proc_list[idx][3] = time
        proc_list[idx][4] = proc_list[idx][3] - proc_list[idx][1]
        proc_list[idx][5] = proc_list[idx][4] - proc_list[idx][2]
        proc_list[idx][6] = 1
        completed += 1
    else:
        time += 1


print(f"{'Process':<8}{'AT':<8}{'BT':<8}{'CT':<8}{'TAT':<8}{'WT':<8}")
for p in proc_list:
    print(f"{p[0]:<8}{p[1]:<8}{p[2]:<8}{p[3]:<8}{p[4]:<8}{p[5]:<8}")


avg_tat = sum(p[4] for p in proc_list) / n
avg_wt = sum(p[5] for p in proc_list) / n
print(f"\nAverage Turnaround Time: {avg_tat:.2f}")
print(f"Average Waiting Time: {avg_wt:.2f}")