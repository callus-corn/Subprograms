#!/bin/bash -e
#SBATCH -N 1  # MPI nodes
#SBATCH -n 1  # MPI processes
#SBATCH --exclusive  # threads/MPI processe
#SBATCH -t 12:00:00  # timeout
#SBATCH -e ./dgemm.log
./dgemm 1000 5000 100 1 n n
