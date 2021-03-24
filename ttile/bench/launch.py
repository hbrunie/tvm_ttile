import os

os.system("python3 bench_1_core_avx2/launch_execution.py")
os.system("python3 bench_1_core_avx512/launch_execution.py")
os.system("python3 bench_1_core_avx2/launch_ga.py")
os.system("python3 bench_1_core_avx512/launch_ga.py")
