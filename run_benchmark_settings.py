import os

benchmarks = ["./a.out 0 ", "./a.out 10","./a.out 20","./a.out 30" , "./a.out 40", "./a.out 50", "./a.out 60", "./a.out 70"]
threads= ["1","2","4"]
frequencies = [800000,2000000,3000000,4400000]
events = ["cycles","CYCLE_ACTIVITY:STALLS_TOTAL","LLC_MISSES","CYCLE_ACTIVITY:STALLS_L3_MISS,RESOURCE_STALLS:SB,CYCLE_ACTIVITY:STALLS_L1D_MISS"]

for b in benchmarks:
        for t in threads:
                    for f in frequencies:
                                    command = "scale "+str(f)
                                    os.system(command)
                                    command = "sudo sh -c \"export OMP_NUM_THREADS="+t+";task_rapl -i -e "+events+" " +b+"> testresult"+str(frequencies.index(f))+".txt\""
                                    os.system(command)
                    filenames = ['testresult0.txt', 'testresult1.txt','testresult2.txt' ,'testresult3.txt']
                    with open("results_"+b[8]+b[9]+"_"+t+"Thread", 'w') as outfile:
                            for fname in filenames:
                                with open(fname) as infile:
                                    outfile.write(infile.read())
                    os.remove("testresult0.txt")
                    os.remove("testresult1.txt")
                    os.remove("testresult2.txt")
                    os.remove("testresult3.txt")
i = 0
for b in benchmarks:
        for t in threads:
                with open("results_"+b[8]+b[9]+"_"+t+"Thread") as openfile:
                    print('\n'+b[8]+b[9]+"_"+t)
                    i=0
                    for line in openfile:
                        for part in line.split():
                            if "cycles" in part:
                                print(""+str(frequencies[i])+" Ghz")
                                i=i+1
                                print(line,end='')
                            if "CYCLE_ACTIVITY:STALLS_TOTAL" in part:
                                print(line,end='')
                            if "LLC_MISSES" in part:
                                print(line,end='')
                            if "CYCLE_ACTIVITY:STALLS_L3_MISS" in part:
                                print(line,end='')
                            if "RESOURCE_STALLS:SB" in part:
                                print(line,end='')
                            if "CYCLE_ACTIVITY:STALLS_L1D_MISS" in part:
                                print(line,end='')
                            if "Energy" in part:
                                print(line,end='')
                            if "Power" in part:
                                print(line)


