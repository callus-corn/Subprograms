#!/bin/bash -e
#SBATCH -N 1  # MPI nodes
#SBATCH -n 1  # MPI processes
#SBATCH --exclusive  # threads/MPI processe
#SBATCH -t 12:00:00  # timeout
#SBATCH -e ./dgemv.log
./dgemv 100  1000 10  10000  n
./dgemv 1100 5000 100 1000 n
