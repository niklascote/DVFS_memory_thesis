import os

benchmarks = ["./ep.S.x","./mg.S.x","./ft.S.x","./is.S.x","./lu.S.x","./ua.S.x","./ep.C.x", "./mg.C.x", "./mg.B.x", "./cg.B.x"]
threads= ["1","2","4"]
frequencies = [800000,2000000,3000000,4400000]
i=0



for b in benchmarks:
        for t in threads:
                with open("results_"+b[2]+b[3]+b[5]+"_"+t+"Thread") as openfile:
                    print('\n'+b[2]+b[3]+b[5]+"_"+t)
                    i=0
                    for line in openfile:
                        for part in line.split():
                            if "Energy" in part:
                                print(""+str(frequencies[i])+" Ghz")
                                i=i+1
                                print(line,end='')
                            if "Power" in part:
                                print(line)
                            if "cycles" in part:
                                print(line,end='')
                            if "instructions" in part:
                                print(line)
                            if "RESOURCE_STALLS:SB" in part:
                                print(line,end='')
                            if "CYCLE_ACTIVITY:STALLS_L1D_MISS" in part:
                                print(line,end='')
                            if "L1D_PEND_MISS:FB_FULL" in part:
                                print(line,end='')
                            if "OFFCORE_REQUESTS_BUFFER:SQ_FULL" in part:
                                print(line,end='')
                            if "CYCLE_ACTIVITY:STALLS_TOTAL" in part:
                                print(line)
                            