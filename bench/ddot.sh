#!/bin/bash -e
#SBATCH -N 1  # MPI nodes
#SBATCH -n 1  # MPI processes
#SBATCH --exclusive  # threads/MPI processe
#SBATCH -t 12:00:00  # timeout
#SBATCH -e ./ddot.log
./ddot 100   1000  10   10000000
./ddot 1100  10000 100  1000000
./ddot 11000 50000 1000 100000
