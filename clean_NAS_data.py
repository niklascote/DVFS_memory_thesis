import os,re,csv
import pandas as pd

#benchmarks = ["./a.out 0 ", "./a.out 10","./a.out 20","./a.out 23","./a.out 25","./a.out 30","./a.out 35", "./a.out 40","./a.out 45", "./a.out 50","./a.out 55" ,"./a.out 60", "./a.out 70"]
benchmarks = ["./ep.A.x","./ep.B.x","./ep.C.x","./ep.W.x","./mg.A.x","./mg.B.x","./mg.C.x","./mg.W.x","./ft.A.x","./ft.B.x","./ft.C.x","./ft.W.x","./lu.A.x","./lu.B.x","./lu.C.x","./lu.W.x","./is.A.x","./is.B.x","./is.C.x","./is.W.x" ,"./cg.A.x","./cg.B.x","./cg.C.x","./cg.W.x","./ua.A.x","./ua.B.x","./ua.C.x","./ua.W.x"]

threads= ["1","2","4"]
frequencies = [800000,2600000,4400000]
instructions = "cycles,RESOURCE_STALLS:SB,CYCLE_ACTIVITY:STALLS_L1D_MISS,CYCLE_ACTIVITY:STALLS_L3_MISS,CYCLE_ACTIVITY:STALLS_TOTAL"#"cycles,instructions,RESOURCE_STALLS:SB,CYCLE_ACTIVITY:STALLS_L1D_MISS,CYCLE_ACTIVITY:STALLS_L3_MISS,CYCLE_ACTIVITY:STALLS_TOTAL"

cycles=0
l3misses=0
membound=0
i = 0
if(os.path.exists("NAS_results.txt")):
    os.remove("NAS_results.txt")
output=open("NAS_results.txt","w+")
for b in benchmarks:
    for t in threads:
        with open("results_"+b[2]+b[3]+b[5]+"_"+t+"Thread") as openfile:
            output.write(""+b[2]+b[3]+b[5]+"\n")
            print(""+b[2]+b[3]+b[5])
            membound=0
            cycles=0
            l3misses=0
            for line in openfile:
                for part in line.split():
                    if "cycles" in part:
                        cycles=float(""+line.replace("cycles",""))
                        #print(""+line,end='')
                    if "CYCLE_ACTIVITY:STALLS_L3_MISS" in part:
                        l3misses=float(""+line.replace("CYCLE_ACTIVITY:STALLS_L3_MISS",""))
                        membound= str(l3misses/cycles)
                        #membound=membound.replace('.',',')
                        output.write(membound+"\n")
                        print(membound)
output.close()

fieldnames=[]
columns = []
with open ("NAS_results.txt","r") as infile, open("output_NAS.csv","w",newline='') as outfile:
    for b in benchmarks:
        fieldnames.append(""+b[2]+b[3]+b[5])
        columns.append(""+b[2]+b[3]+b[5])
    thewriter=csv.DictWriter(outfile, fieldnames=fieldnames)
    thewriter.writeheader()
    memlist = []
    for row in infile:
        if row.strip() in columns:
            memlist.append(next(infile).strip())
            memlist.append(next(infile).strip())
            memlist.append(next(infile).strip())
    for i in range(0,9):
        thewriter.writerow({""+columns[0] : ""+memlist[i],""+columns[1] : ""+memlist[i+9] , ""+columns[2] : ""+memlist[i+18], ""+columns[3] : ""+memlist[i+27], ""+columns[4] : ""+memlist[i+36], ""+columns[5] : ""+memlist[i+45], ""+columns[6] : ""+memlist[i+6*9],""+columns[7] : ""+memlist[i+7*9] , ""+columns[8] : ""+memlist[i+8*9], ""+columns[9] : ""+memlist[i+9*9], ""+columns[10] : ""+memlist[i+10*9], ""+columns[11] : ""+memlist[i+11*9],""+columns[12] : ""+memlist[i+12*9],""+columns[13] : ""+memlist[i+13*9] , ""+columns[14] : ""+memlist[i+14*9], ""+columns[15] : ""+memlist[i+15*9], ""+columns[16] : ""+memlist[i+16*9], ""+columns[17] : ""+memlist[i+17*9],""+columns[18] : ""+memlist[18*9],""+columns[19] : ""+memlist[i+19*9] , ""+columns[20] : ""+memlist[i+20*9], ""+columns[21] : ""+memlist[i+21*9], ""+columns[22] : ""+memlist[i+22*9], ""+columns[23] : ""+memlist[i+23*9],""+columns[24] : ""+memlist[i+24*9],""+columns[25] : ""+memlist[i+25*9] , ""+columns[26] : ""+memlist[i+26*9], ""+columns[27] : ""+memlist[i+27*9]})