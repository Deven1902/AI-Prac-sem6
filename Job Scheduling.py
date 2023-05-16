# profit = [15,27,10,100,150]
# jobs = ["j1","j2","j3","j4","j5"]
# deadline = [2,3,3,3,4]

profit = []
jobs = []
deadline = []

n = int(input("Number of elements in the array are : "))
print("Insert values for profit array")
for i in range(0, n):
    profit_elements = int(input())
    profit.append(profit_elements)
print("Inputted values of profit are : ", profit)

print("Insert the values for job array")
for i in range(0, n):
    job_elements = int(input())
    jobs.append(job_elements)
print("Inputted values of jobs are : ", jobs)

print("Insert values for deadline array")
for i in range(0, n):
    deadline_elements = int(input())
    deadline.append(deadline_elements)
print("Inputted values of profit are : ", deadline)


profitNJobs = list(zip(profit,jobs,deadline))
profitNjobs = sorted(profitNJobs, key = lambda x: x[0], reverse = True)
slot = []
for _ in range(len(jobs)):
    slot.append(0)
   
profit = 0
ans = []

for i in range(len(jobs)):
    ans.append('null')
   
for i in range(len(jobs)):
    job = profitNJobs[i]
    for j in range(job[2],0,-1):
        if slot[j] == 0:
            ans[j] = job[1]
            profit += job[0]
            slot[j] = 1
            break

print("jobs are : ", jobs)
print("deadlines are : ", deadline)
print("Jobs scheduled : ", ans[1:])
print("Profit of the jobs is : ", profit)
