import os

benchmarks = ["./cg.S.x" ,"./ep.S.x","./ft.S.x","./is.S.x","./lu.S.x","./mg.S.x","./ua.S.x","./ep.C.x","./mg.C.x","./cg.B.x","./mg.B.x"]
threads= ["1","2","4"]
frequencies = [800000,2000000,3000000,4400000]
instructions = "cycles,instructions,RESOURCE_STALLS:SB,CYCLE_ACTIVITY:STALLS_L1D_MISS,L1D_PEND_MISS:FB_FULL,OFFCORE_REQUESTS_BUFFER:SQ_FULL,CYCLE_ACTIVITY:STALLS_TOTAL"


for b in benchmarks:
        for t in threads:
                    for f in frequencies:
                                    command = "scale "+str(f)
                                    os.system(command)
                                    command = "sudo sh -c \"export OMP_NUM_THREADS="+t+";task_rapl -i -e "+instructions+" "+b+" > testresult"+str(frequencies.index(f))+".txt\""
                                    os.system(command)
                    filenames = ['testresult0.txt', 'testresult1.txt','testresult2.txt' ,'testresult3.txt']
                    with open('results_'+b[2]+b[3]+b[5]+"_"+t+'Thread', 'w') as outfile:
                            for fname in filenames:
                                with open(fname) as infile:
                                    outfile.write(infile.read())
                    os.remove("testresult0.txt")
                    os.remove("testresult1.txt")
                    os.remove("testresult2.txt")
                    os.remove("testresult3.txt")
