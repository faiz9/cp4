# vmmul instructional test harness

This directory contains a benchmark harness for testing different implementations of
vector-matrix multiply (VMM) for varying problem sizes.

The main code is benchmark.cpp, which sets up the problem, iterates over problem
sizes, sets up the vector and matrix, executes the vmmul call, and tests the
result for accuracy by comparing your result against a reference implementation (CBLAS).

Note that cmake needs to be able to find the CBLAS package. For CSC 746/656 Fall 2022,
this condition is true on Perlmutter@NERSC and on the class VM. It is also true for some
other platforms, but you are on your own if using a platform other than Perlmutter@NERSC
or the class VM.

Credits To Dr. E Wes Bethel 

<br></br>

# Running Instructions:

1 - ssh into CORI using terminal
2 - Git clone <repo link>
3 - cd <repo>
4 - mkdir build
5 - cd build
6 - cmake ../
7 - make
8 - module load PrgEnv-intel
9 - salloc --nodes=1 --qos=interactive --time=01:00:00 --constraint=knl --account=m3930
   
   `srun ./benchmark-basic`  
   or  
   `srun ./benchmark-vectorized`  
   or  
   `srun ./benchmark-blas`

For the OpenMP parallel code, note that you specify concurrency at runtime using
the OMP_NUM_THREADS environment variable. While it is possible to set the number of
concurrent OpenMP threads at compile time, it is generally considered better practice to
specify the number of OpenMP threads via the OMP_NUM_THREADS environment variable.

<br></br>

# Running the codes

There is a sample job script provided for running the OpenMP code at 3 levels of concurrency: 1, 4, 8 threads. You may launch that script either as a batch job using the sbatch command, or you may run it as a shell script from an interactive node (preferred).

For the other codes -- benchmark-blas, benchmark-basic, and benchmark-vectorized -- it is easiest to run these from the command line from an interactive node by typing:

   `srun ./benchmark-basic`  
   or  
   `srun ./benchmark-vectorized`  
   or  
   `srun ./benchmark-blas`

#eof
