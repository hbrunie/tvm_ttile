import os
import input_conv
name_folder = "XeonGold6130"
SIZE_VECTOR = 16
f = 2.1 * 10**9

### AUTOTVM

results_autotvm = os.listdir("result_autotvm")
try:
    results_autotvm.remove(".DS_Store")
except:
    pass
autotvm = {
    1: {},
    2: {},
    4: {},
    8: {},
    16: {},
    32: {}
}
for result_autotvm in results_autotvm:
    _, NUM_THREADS, archi, cpu = result_autotvm.split(".")[0].split("_")
    if name_folder == cpu:

        file_ = open("result_autotvm/" + result_autotvm, "r")
        for line in file_:
            name_conv, time, std = line.split(";")
            autotvm[int(NUM_THREADS)][name_conv] = time
        file_.close()

###TVM TTILE



subfolder = os.listdir(name_folder)
try:
    subfolder.remove(".DS_Store")
except:
    pass


file_ = open("result_all.csv", "w")

file_.write("NAME_CONV,NUM_THREADS,TimeTVM+TTILE(ms),%PeakPerfTVM+TTILE,TimeAUTOTVM,%PeakPerfAUTOTVM,NbMicroKernel,AxeFuse,SizeAxeFuse,Schema\n")

for sub in range(len(subfolder)):
    lconv = os.listdir(name_folder + "/" + subfolder[sub] + "/results")
    try:
        lconv.remove(".DS_Store")
    except:
        pass
    for c in range(len(lconv)):
        result = open(name_folder + "/" + subfolder[sub] + "/results/" + lconv[c], "r")
        mini = 99999999.0
        bestline = ""
        for line in result:
            if "IdRun" in line:
                pass
            else:
                l = line.split(";")
                if float(l[2]) < mini:
                    mini = float(l[2])
                    # print(maxi)
                    bestline = line.split(";")
        result.close()

        if bestline != "":
            res = [bestline[1], subfolder[sub], bestline[2], bestline[4], bestline[5], bestline[6], bestline[7]]
            input_c = input_conv.input_conv
            K, C, H, W, R, S, Stride, _ = input_c[bestline[1]]
            peak_perf = K * C * (H / Stride) * (W / Stride) * R * S
            peak_perf = peak_perf / (2 * SIZE_VECTOR)
            peak_perf = peak_perf / float(subfolder[sub])
            peak_perf = peak_perf / f * 1000
            try:
                time_autotvm = autotvm[int(subfolder[sub])][bestline[1]]
                peak_perf_autotvm = str(peak_perf/float(time_autotvm) * 100)
            except:
                time_autotvm = ""
                peak_perf_autotvm = ""
            file_.write(bestline[1] + "," + subfolder[sub] + "," + bestline[2] + "," + str(peak_perf/float(bestline[2]) * 100)  + "," + time_autotvm + "," + peak_perf_autotvm + "," + bestline[4].replace(",", ";")  + "," + bestline[5].replace(",", ";")  + "," + bestline[6].replace(",", ";")  + "," + bestline[7].replace(",", ";") + "\n")


file_.close()
